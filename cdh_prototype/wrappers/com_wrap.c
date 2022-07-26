#include "fsl_gpio.h"
#include "fsl_lpuart.h"
#include "fsl_lpuart_freertos.h"
#include "fsl_debug_console.h"
#include "fsl_lpi2c_freertos.h"
#include "fsl_lpi2c.h"
#include "peripherals.h"
#include "com_protocol_helper.h"
#include "telemetry.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if HMAC_ENABLE
#include <openssl/evp.h>
#include <openssl/hmac.h>
#endif
#include <string.h>

#include "com_task.h"

#define I2C_COM_RX_SIZE 4
#define I2C_COM_ANTENNA_SLAVE_ADDRESS 0x33   //should this be 16bit?
#define CLOCKS_PER_SECOND 1000000 //i believe this should be different depending on each CPU


#define DEFAULT_RETRIES 5
#define DEFAULT_RETRY_DELAY 0.4
#define RADIO_FREQ_STEP_HZ 6250
#define RADIO_DEFAULT_BANDWIDTH 12500
#define SHA256_HASH_SIZE 32
#define PACKET_HEADER_SIZE 2


//Everything but buffer should be static?
uint8_t rcv_buffer[I2C_COM_RX_SIZE];  //error thrown here for some reason?
static bool i2c_com_antennaDeployed;
static uint8_t algorithmOne[] = {0x00, 0x00, 0x00, 0x1F};
static uint8_t algorithmTwo[] = {0x00, 0x00, 0x00, 0x2F};
static clock_t deploy_initiated;
static char START_OF_HEADER = 0x01;
static bool DEALER= false;

//Intialize all the commands we will use
static char set_dealer_mode_buf[] = {0x01, 0x44, 0x00, 0xBB};
static char set_current_power[] = {0x01, 0x71, 0x01, 0x8D};//set to 0.5W, Changed checksum, from 0x8E to 0x8D
static char get_current_power[] = {0x01, 0x72, 0x8E};
static char set_tx_freq[] = {0x01, 0x37, 0x03, 0x13, 0xF7, 0xB1, 0xC0}; //set to 335MHz @ channel 3
static char set_rx_freq[] = {0x01, 0x39, 0x03, 0x13, 0xF7, 0xB1, 0xC0}; //set to 335MHz @ channel 3
static char get_tx_freq[] = {0x01, 0x3B, 0x03, 0xC1};
static char get_rx_freq[] = {0x01, 0x3A, 0x03, 0xC2};
static char set_channel[] = {0x01, 0x03, 0xFC}; //set to channel 3 // Rithu edit: Should we change second argument to 2?
static char set_bandwidth[] = {0x01, 0x70, 0x04, 0x01, 0x8A}; //set to 12.5k
static char set_modulation[] = {0x01, 0x70, 0x49, 0x00, 0x00}; //last 2 should be replaced when setting is determined
static char program_buf[] = {0x01, 0x1E, 0xE1};
static char warm_reset[] = {0x01, 0x1D, 0x01, 0xE1};
static char set_led_rx[] = {0x70, 0x36, 0x00, 0x5A}; //checksum = 0xC9? Not sure since starting value is 0x70 
// need add channel

//Program the expected responses for each command
static char set_dealer_response[] = {0x01, 0xC4, 0x00, 0x3B}; 
static char set_power_response[] = {0x01, 0xF1, 0x00, 0x0E}; //Changed checksum from 0x0F to 0x0E
static char get_power_response[] = {0x01, 0xF2, 0x01, 0x0C}; //Changed checksum from 0x0D to 0x0C
static char set_tx_freq_response[] = {0x01, 0xB7, 0x00}; //TBD once we figure out what to value to set it to
static char set_rx_freq_response[] = {0x01, 0xB9, 0x00}; //TBD once we figure out what to value to set it to
static char set_channel_response[] = {0x01, 0x83, 0x00, 0x7C};
static char set_bandwidth_response[] = {0x01, 0xF0, 0x00, 0x0F}; //Changed checksum from 0x10 to 0x0F
static char set_modulation_response[] = {0x01, 0xAB}; //TBD
static char program_response[] = {0x01,0x9E, 0x00, 0x61}; //Changed checksum from 0x62 to 0x61
static char reset_response[] = {0x01, 0x9D, 0x00, 0x62};
static char set_led_rx_response[] = {0x01, 0x00, 0xFF, 0x00}; //Changed checksum from 0x01 to 0x00

const char *to_send               = "FreeRTOSFreeRTOS";
const char *send_ring_overrun     = "\r\nRing buffer overrun!FreeRTOS\r\n";
const char *send_hardware_overrun = "\r\nHardware buffer overrun!FreeRTOS\r\n";
uint8_t backgroundBuffer[500];

static char tx_buffer[7] = {};
static char rx_buffer[5] = {};
static char downlink_buffer[] = {};
static int rx_size = 0;

// GENERAL COMMAND LIST
uint8_t REQUEST_PAYLOAD = 1;
// maybe try uint8_t for buffers

void com_deployAntenna_algorithmTwo();
static bool enterCommandMode();
static bool sendConfigCommand();
static bool checkConfigCommand();
static void configRadio();
static bool getPower();
static bool setLEDRx();
static bool setPower();
static bool setProgramming();
static bool setModulation();
static bool setBandwidth();
static bool setRxFreq();
static bool setTxFreq();
static bool setChannel();
static void exitCommandMode();

static bool i2c_com_antennaDeployed;
uint8_t receive_buffer[4];

// TODO: Why isn't uart1 working?
// commands data: what type? how big?
// payload data: what type? how big?
// image data: what type? how big?
// beacons: what type? how big?

/*
 * Rithu edit: Program wasn't recognizing delay so copied
   this function from internet:
 */
//xTaskHandle COM_RTOS_UART_HANDLE = NULL;

void delay(int seconds)
{
    long pause;
    clock_t now,then;


    pause = (seconds)*(CLOCKS_PER_SEC);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

// set radio to command mode with dealer mode off
// returns true if properly set to command mode & dealer off
static bool enterCommandMode()
 {
	PRINTF("Setting to Command Mode\n");
	delay(4); // More than 100 milliseconds silence

	//clear buffer TODO: Check is 0 is best default val for clearing
	memset(tx_buffer, 0, sizeof(tx_buffer));

	tx_buffer[0] = '+';
	tx_buffer[1] = '+';
	tx_buffer[2] = '+';

	// Some testing lines
	//PRINTF("%s\nWhat's sending for enterCommandMode() test:", tx_buffer);
	//PRINTF("%d\n", strlen(rx_buffer));

	//size_t n = 0;
	int returnVal =  LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)tx_buffer, 3); //LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)tx_buffer, 3);
    PRINTF("message sent\n");

	//Another delay of 100 msec so radio can go into command mode
	delay(10);

	// Checking that sending of '+++' is successful
	if (returnVal == kStatus_Success){
		return 1;
	}
	else {
		return 0;
	}

}

void testSending(){
	memset(tx_buffer, 0, sizeof(tx_buffer));

	tx_buffer[0] = 'a';
	tx_buffer[1] = 'b';

	delay(10);
	LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)tx_buffer, 1);
	PRINTF("WRITE SUCCESS\n");
	delay(5);
}


//Sends a command to the radia via UART, retries several times if there is a failure.
static bool sendConfigCommand(uint8_t data[], uint8_t expectedResponse[], int sizeofTx, int sizeExpectedResponse) {
    int try = 0;

	//clear buffers here
	memset(rx_buffer, 0, sizeof(rx_buffer));
	memset(tx_buffer, 0, sizeof(tx_buffer));

    // Sends data to radio via UART, if the response is not correct it retries sending the command
    int size_t = 0;
    while (try < DEFAULT_RETRIES) {
    	PRINTF("Trying to send ...\n");
    	PRINTF("Should be sending the following ...\n");
        for (int i = 0; i < sizeofTx; i++) {
        	tx_buffer[i] = data[i];
        	PRINTF("tx_buffer[i]: %d\n", tx_buffer[i]);
        }
    	int sendReturnVal = LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)tx_buffer, sizeofTx); //LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, tx_buffer, sizeofTx); // Rithu: changing to sizeOfTx
    	if (sendReturnVal == kStatus_Success){
    		PRINTF("SUCCESS SENDING\n");
    	}
    	else {
    		PRINTF("ERROR SENDING\n");
    	}

        PRINTF("Trying to receive ...\n");
        int recReturnVal = LPUART_RTOS_Receive(&COM_RTOS_UART_HANDLE, rx_buffer, sizeExpectedResponse, size_t); // TODO: Fix Warning
    	if (recReturnVal == kStatus_Success){
    		PRINTF("SUCCESS RECEIVING\n");
    	}
    	else {
    		PRINTF("ERROR RECEIVING\n");
    	}
    	PRINTF("Value of rx_buffer: \n");
        for (int i = 0; i < sizeExpectedResponse; i++) {
        	PRINTF("rx_buffer: %d\n", rx_buffer[i]);
        }
        bool sentCommand = checkConfigCommand(*rx_buffer, *expectedResponse, sizeExpectedResponse);
        memset(rx_buffer, 0, sizeof(rx_buffer));
        if (sentCommand) {
        	PRINTF("Radio response to command is correct! \n");
        	try = 5;
        	//clear buffers here
        	memset(rx_buffer, 0, sizeof(rx_buffer));
        	memset(tx_buffer, 0, sizeof(tx_buffer));
            return true;

        }
        try++;
        delay(0.05);
    }
    PRINTF("unexpected response\n");
	//clear buffers here
    memset(rx_buffer, 0, sizeof(rx_buffer));
	memset(tx_buffer, 0, sizeof(tx_buffer));
    return false;
}

//checks if radio response to command is correct
static bool checkConfigCommand(uint8_t actualResponse[], uint8_t expectedResponse[], int lengthOfResponse) {
	for (int j = 0; j < lengthOfResponse; j++) {
		if (actualResponse[j] != expectedResponse[j]) {
			return false;
		}
	}
	return true;
}

void com_enterCommandMode()
{
	bool success = enterCommandMode();
	//set transmit/receive rate to 19.2 kbps
	//choose trans FST mode
	//set RF power to 0.5W
	//Choose channel (center frequency) within our licensed band
	if(success){
		PRINTF("succesfully set to command mode\r\n");
	}
	else{
		PRINTF("error in setting to command mode\r\n");
	}

}

void com_radio_init()
{
	configRadio();
	//set transmit/receive rate to 19.2 kbps
	//choose trans FST mode
	//set RF power to 0.5W
	//Choose channel (center frequency) within our licensed band
	PRINTF("initializing COM radio\r\n");
}

void com_init()
{
	com_radio_init();
	gpio_pin_config_t gpioConfig = {
			kGPIO_DigitalOutput, 0, kGPIO_NoIntmode
	};
	// Setting burn wire pins to 0 I think
	GPIO_PinInit(GPIO1, ANTENNA_WIRE_1, &gpioConfig);
	GPIO_PinInit(GPIO1, ANTENNA_WIRE_2, &gpioConfig);
}

void com_set_burn_wire1()
{
	GPIO_PinWrite(GPIO1, ANTENNA_WIRE_1, 1);
}

void com_set_burn_wire2()
{
	GPIO_PinWrite(GPIO1, ANTENNA_WIRE_2, 1);
}

bool com_healthcheck() //checks power
{
	PRINTF("checking COM health\r\n");
	//getCurrentPower();
	bool setToCommand = enterCommandMode();
	bool powerOkay = getPower();
	if (setToCommand & powerOkay) {
		PRINTF("COM is operating properly\r\n");
		return true;
	}
	exitCommandMode();
	PRINTF("COM is not operating properly. Trying to reconfigure.\r\n");
	//configRadio();
	return false;
}

void com_getCommands() //highest priority
{
	size_t n;

	char * to_send = "com: give me commands";

	memset(rcv_buffer, 0, sizeof(*rcv_buffer)); //TODO: necessary?
	// void * memset ( void * ptr, int value, size_t num );

	// void * memcpy ( void * destination, const void * source, size_t num );

	if (kStatus_Success != LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)to_send, strlen(to_send)))//LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)to_send, strlen(to_send)))
	{
		PRINTF("could not send!!!\r\n\r\n");
		return;
	}

	status_t error = LPUART_RTOS_Receive(&COM_RTOS_UART_HANDLE, rcv_buffer, sizeof(rcv_buffer), &n);
	if (error == kStatus_LPUART_RxHardwareOverrun)
	{
		PRINTF("hardware overrun!!!\r\n\r\n");
		return;
	}
	if (error == kStatus_LPUART_RxRingBufferOverrun)
	{
		PRINTF("ring buffer overrun!!!\r\n\r\n");
		return;
	}
	if (n > 0)
	{
		/* send back the received data */
		if (kStatus_Success != LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)rcv_buffer, n))//LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)rcv_buffer, n))
		{
			vTaskSuspend(NULL);
		}
	}

	PRINTF("getting commands from the ground station\r\n");
}

#if HMAC_ENABLE
unsigned char *hmac_sha256(const void *key, 			/* pointer to authentication key */
						   int keylen,					/* length of authentication key  */
                           const unsigned char *data, 	/* pointer to data stream        */
						   int datalen,					/* length of data stream         */
                           unsigned char *result, 		/* caller digest to be filled in */
						   unsigned int *resultlen) 	/* length of result digest       */
{
    return HMAC(EVP_sha256(), key, keylen, data, datalen, result, resultlen);
}

void createHMAC()
{
	char *key = strdup("Start uplinking");
	int keylen = strlen(key);
	const unsigned char *data = (const unsigned char *)strdup("Security verify");
	int datalen = strlen((char *)data);
	unsigned char *result = NULL;
	unsigned int resultlen = -1;

	result = hmac_sha256((const void *)key, keylen, data, datalen, result, &resultlen);
}
#endif

//proper code below:

void com_deployAntenna()
{
	//using algorithm one as the default
    I2C_send(&LPI2C1_masterHandle, &LPI2C1_masterTransfer, I2C_COM_ANTENNA_SLAVE_ADDRESS, 0, algorithmOne, sizeof(algorithmOne));
	deploy_initiated = clock();
    delay(15); //longest time possible to deploy is 15 seconds
}

void com_deployAntenna_algorithmTwo()
{
	//TODO: Uncomment this! Comment below statement if testing i2c
	I2C_send(&LPI2C1_masterHandle, &LPI2C1_masterTransfer, I2C_COM_ANTENNA_SLAVE_ADDRESS, 0, algorithmTwo, sizeof(algorithmTwo));
	delay(30); //longest time possible to deploy is 30 seconds
}

//The structure?code for each of these downlink functions are from the CDH uart driver code
void com_sendPayloads() //high priority
{
//	 if (kStatus_Success != LPUART_RTOS_Init(&handle, &t_handle, &lpuart_config))
//	    {
//	        vTaskSuspend(NULL);
//	    }

	    /* Send introduction message. */
	    if (kStatus_Success != LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)to_send, strlen(to_send))){
	    	vTaskSuspend( NULL );
	    }
	    PRINTF("message sent\n");

	    /* Receive user input and send it back to terminal. */
	    int n = 0;
	    status_t error = LPUART_RTOS_Receive(&COM_RTOS_UART_HANDLE, receive_buffer, 8, &n);
	    do
	    {
	    	error = LPUART_RTOS_Receive(&COM_RTOS_UART_HANDLE, receive_buffer, 8, &n);

	        PRINTF("n = %d\n", n);
	        if (error == kStatus_LPUART_RxHardwareOverrun)
	        {
	            /* Notify about hardware buffer overrun */
	            if (kStatus_Success !=
					LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)send_hardware_overrun, strlen(send_hardware_overrun)))
	            {
	                vTaskSuspend(NULL);
	            }
	        }
	        if (error == kStatus_LPUART_RxRingBufferOverrun)
	        {
	            /* Notify about ring buffer overrun */
	            if (kStatus_Success != LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)send_ring_overrun, strlen(send_ring_overrun)))
	            {
	                vTaskSuspend(NULL);
	            }
	        }
	        if (n > 0)
	        {
	            /* send back the received data */
	            if (kStatus_Success != LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)receive_buffer, 8))
	            {
	                vTaskSuspend(NULL);
	            }
	        }
	//        vTaskDelay(1000);
	    } while (kStatus_Success == error);

	    //LPUART_RTOS_Deinit(&handle);
}

void com_sendImages() //medium priority
{
//	 if (kStatus_Success != LPUART_RTOS_Init(&handle, &t_handle, &lpuart_config))
//	    {
//	        vTaskSuspend(NULL);
//	    }

	    /* Send introduction message. */
	    if (kStatus_Success != LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)to_send, strlen(to_send))){
	    	vTaskSuspend( NULL );
	    }
	    PRINTF("message sent\n");

	    /* Receive user input and send it back to terminal. */
	    size_t n = 0;
	    status_t error = LPUART_RTOS_Receive(&COM_RTOS_UART_HANDLE, receive_buffer, 8, &n);
	    do
	    {
	    	n = 0;
	        error = LPUART_RTOS_Receive(&COM_RTOS_UART_HANDLE, receive_buffer, 8, &n);

	        PRINTF("n = %d\n", n);
	        if (error == kStatus_LPUART_RxHardwareOverrun)
	        {
	            /* Notify about hardware buffer overrun */
	            if (kStatus_Success !=
					LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)send_hardware_overrun, strlen(send_hardware_overrun)))
	            {
	                vTaskSuspend(NULL);
	            }
	        }
	        if (error == kStatus_LPUART_RxRingBufferOverrun)
	        {
	            /* Notify about ring buffer overrun */
	            if (kStatus_Success != LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)send_ring_overrun, strlen(send_ring_overrun)))
	            {
	                vTaskSuspend(NULL);
	            }
	        }
	        if (n > 0)
	        {
	            /* send back the received data */
	            if (kStatus_Success != LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)receive_buffer, 8))
	            {
	                vTaskSuspend(NULL);
	            }
	        }
	//        vTaskDelay(1000);
	    } while (kStatus_Success == error);

	    //LPUART_RTOS_Deinit(&handle);
}

void com_sendBeacons() //low priority, happens every 60 secs
{
//	 if (kStatus_Success != LPUART_RTOS_Init(&handle, &t_handle, &lpuart_config))
//	    {
//	        vTaskSuspend(NULL);
//	    }

	    /* Send introduction message. */
	    if (kStatus_Success != LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)to_send, strlen(to_send))){
	    	vTaskSuspend( NULL );
	    }
	    PRINTF("message sent\n");

	    /* Receive user input and send it back to terminal. */
	    size_t n = 0;
	    status_t error = LPUART_RTOS_Receive(&COM_RTOS_UART_HANDLE, receive_buffer, 8, &n);
	    do
	    {
	    	n = 0;
	        error = LPUART_RTOS_Receive(&COM_RTOS_UART_HANDLE, receive_buffer, 8, &n);

	        PRINTF("n = %d\n", n);
	        if (error == kStatus_LPUART_RxHardwareOverrun)
	        {
	            /* Notify about hardware buffer overrun */
	            if (kStatus_Success !=
					LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)send_hardware_overrun, strlen(send_hardware_overrun)))
	            {
	                vTaskSuspend(NULL);
	            }
	        }
	        if (error == kStatus_LPUART_RxRingBufferOverrun)
	        {
	            /* Notify about ring buffer overrun */
	            if (kStatus_Success != LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)send_ring_overrun, strlen(send_ring_overrun)))
	            {
	                vTaskSuspend(NULL);
	            }
	        }
	        if (n > 0)
	        {
	            /* send back the received data */
	            if (kStatus_Success != LPUART_RTOS_Send(&COM_RTOS_UART_HANDLE, (uint8_t *)receive_buffer, 8))
	            {
	                vTaskSuspend(NULL);
	            }
	        }
	//        vTaskDelay(1000);
	    } while (kStatus_Success == error);

	    //LPUART_RTOS_Deinit(&handle);
}


//void I2C_send(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t * masterSendBuffer, size_t tx_size);
//void I2C_request(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t * rx_buffer, size_t rx_size);


bool com_i2c_checkDeploy() //returns a true if doors are deployed
{
	clock_t current_time = clock();
	//TODO: Uncomment this! Comment below if statement if testing w/o antenna setup
	if ((current_time-deploy_initiated)/CLOCKS_PER_SECOND < 900) {
		PRINTF("Not enough time has elapsed for the antenna to deploy\r\n");
		return false;
	}
	memset(rcv_buffer, 0, sizeof(*rcv_buffer));
    //TODO: Uncomment this! Comment below if statement if testing I2C
	I2C_request(&LPI2C1_masterHandle, &LPI2C1_masterTransfer, I2C_COM_ANTENNA_SLAVE_ADDRESS, 0, rcv_buffer, sizeof(rcv_buffer));
	//Receive 4 bytes back with status of antenna
	//First byte of rx_buffer is:
	//MSB LSB D4 D3 D2 D1 0 M S2 S1
	// Testing correct rcv_buffer
    //	for (int i = 0; i < 4; i++){
    //		rcv_buffer[i] = 0xFF;
    //	}
	uint8_t rcv_byteZero = rcv_buffer[0];

	//iterate through first four bits of first byte to find if all rods are deployed
	int what_bit_i_am_testing = 0;
	bool allDeployed = true;

	while (what_bit_i_am_testing < 8) {
		if(what_bit_i_am_testing > 3) {
			if (rcv_byteZero & 0x01) {
				PRINTF("bit %d is 1\n", what_bit_i_am_testing);
	        }
	        else {
	        	printf("bit %d is 0\n", what_bit_i_am_testing);
	        	allDeployed = false;
	        }
		}

	what_bit_i_am_testing++;
	rcv_byteZero = rcv_byteZero >> 1;
	}

    if (allDeployed) {
    	i2c_com_antennaDeployed = true;
        PRINTF("Antenna deployed\r\n");
    } else {
    	i2c_com_antennaDeployed = false;
        PRINTF("Antenna not deployed, trying again.\r\n");
        com_deployAntenna_algorithmTwo();
    }
    return i2c_com_antennaDeployed;
}

// Rithu edit: adding this to check if sendConfigCommand works
void com_exitCommandMode(){
	exitCommandMode();
}

static void exitCommandMode() {
	int sizeOfTx = sizeof(warm_reset) / sizeof(warm_reset[0]);
	int sizeExpectedResponse = sizeof(reset_response) / sizeof(reset_response[0]);
	bool exitedCommandMode = sendConfigCommand(warm_reset, reset_response, sizeOfTx, sizeExpectedResponse);
	if (exitedCommandMode) {
		PRINTF("Radio reset to data mode.\n");
		return true;
	}
	PRINTF("Unable to reset radio to data mode.\n");
	return false;
}


//Set to a modulation of
static bool setDealerMode() {
	int sizeOfTx = sizeof(set_dealer_mode_buf) / sizeof(set_dealer_mode_buf[0]);
	int sizeExpectedResponse = sizeof(set_dealer_response) / sizeof(set_dealer_response[0]);
    bool successDealer = sendConfigCommand(set_dealer_mode_buf, set_dealer_response, sizeOfTx, sizeExpectedResponse);
    if (successDealer) {
        PRINTF("Dealer allows user access\n");
        return true;
    }
     PRINTF("Failure to change dealer mode\n");
     return false;
}


//Set to a default channel of 1
static bool setChannel() {
	int sizeOfTx = sizeof(set_channel) / sizeof(set_channel[0]);
	int sizeExpectedResponse = sizeof(set_channel_response) / sizeof(set_channel_response[0]);
    bool successChannel = sendConfigCommand(set_channel, set_channel_response, sizeOfTx, sizeExpectedResponse);
    if (successChannel) {
    	// Rithu: Why does this say set to channel 1 when it's set to channel 3?
        PRINTF("Channel successfully set to 1\n");
        return true;
    }
     PRINTF("Failure to set channel\n");
     return false;
}

//Set to a tx freq of
static bool setTxFreq() {
	int sizeOfTx = sizeof(set_tx_freq) / sizeof(set_tx_freq[0]);
	int sizeExpectedResponse = sizeof(set_tx_freq_response) / sizeof(set_tx_freq_response[0]);
    bool successTX = sendConfigCommand(set_tx_freq, set_tx_freq_response, sizeOfTx, sizeExpectedResponse);
    if (successTX) {
        PRINTF("Tx frequency set to ____\n");
        return true;
    }
     PRINTF("Failure to set tx frequency\n");
     return false;
}

//Set to a rx freq of
static bool setRxFreq() {
	int sizeOfTx = sizeof(set_rx_freq) / sizeof(set_rx_freq[0]);
	int sizeExpectedResponse = sizeof(set_rx_freq_response) / sizeof(set_rx_freq_response[0]);
    bool successRX = sendConfigCommand(set_rx_freq, set_rx_freq_response, sizeOfTx, sizeExpectedResponse);
    if (successRX) {
        PRINTF("Rx frequency set to ____\n");
        return true;
    }
     PRINTF("Failure to set Rx frequency\n");
     return false;
}

//Set to a bandwidth
static bool setBandwidth() {
	int sizeOfTx = sizeof(set_bandwidth) / sizeof(set_bandwidth[0]);
	int sizeExpectedResponse = sizeof(set_bandwidth_response) / sizeof(set_bandwidth_response[0]);
    bool successBandwidth = sendConfigCommand(set_bandwidth, set_bandwidth_response, sizeOfTx, sizeExpectedResponse);
    if (successBandwidth) {
        PRINTF("Bandwidth set to ____\n");
        return true;
    }
     PRINTF("Failure to set Bandwidth\n");
     return false;
}


//Set to a modulation of
static bool setModulation() {
	int sizeOfTx = sizeof(set_modulation) / sizeof(set_modulation[0]);
	int sizeExpectedResponse = sizeof(set_modulation_response) / sizeof(set_modulation_response[0]);
    bool successModulation = sendConfigCommand(set_modulation, set_modulation_response, sizeOfTx, sizeExpectedResponse);
    if (successModulation) {
        PRINTF("Modulation set to 4-Level GSK\n");
        return true;
    }
     PRINTF("Failure to setModulation\n");
     return false;
}


static bool setProgramming() {
	int sizeOfTx = sizeof(program_buf) / sizeof(program_buf[0]);
	int sizeExpectedResponse = sizeof(program_response) / sizeof(program_response[0]);
    bool successProgramming = sendConfigCommand(program_buf, program_response, sizeOfTx, sizeExpectedResponse);
    if (successProgramming) {
        PRINTF("Set to non volatile memory\n");
        return true;
    }
     PRINTF("Failure to program to memory\n");
     return false;
}



static bool setPower() {
	int sizeOfTx = sizeof(set_current_power) / sizeof(set_current_power[0]);
	int sizeExpectedResponse = sizeof(set_current_power) / sizeof(set_current_power[0]);
	bool successPower = sendConfigCommand(set_current_power, set_power_response, sizeOfTx, sizeExpectedResponse);

	if(successPower) {
		PRINTF("0.5W power set properly.\n");
		return true;
	}
	PRINTF("Failure to set to power to 0.5W.\n");
	return false;
}

//This should be used for testing on flatsat, will not be used in the flight module.
static bool setLEDRx() {
	int sizeOfTx = sizeof(set_led_rx) / sizeof(set_led_rx[0]);
	int sizeExpectedResponse = sizeof(set_led_rx_response) / sizeof(set_led_rx_response[0]);
	bool checkLED = sendConfigCommand(set_led_rx, set_led_rx_response, sizeOfTx, sizeExpectedResponse);
	if (checkLED) {
		PRINTF("LED for Rx is turned on.\n");
	}
	PRINTF("LED is not set properly.\n");
	return false;
}

static bool getPower() {
	int sizeOfTx = sizeof(get_current_power) / sizeof(get_current_power[0]);
	int sizeExpectedResponse = sizeof(get_power_response) / sizeof(get_power_response[0]);
	bool checkPower = sendConfigCommand(get_current_power, get_power_response, sizeOfTx, sizeExpectedResponse);

	if(checkPower) {
		PRINTF("0.5W power set properly.\n");
		return true;
	}
	PRINTF("Power is not set correct.\n");
	return false;
}


static void configRadio(){
    bool checkMode = enterCommandMode();
    PRINTF("Entering command mode\n");
    bool checkDealerMode = setDealerMode();
    PRINTF("Setting Dealer Mode off\n");
    bool checkChannel = setChannel();
    PRINTF("Setting Channel\n");
    bool checkRxFreq = setRxFreq();
    PRINTF("Setting Rx Frequency\n");
    bool checkTxFreq = setTxFreq();
    PRINTF("Setting Tx Frequency\n");
    bool checkBandwidth = setBandwidth();
    PRINTF("Setting Bandwidth\n");
    bool checkPower = setPower();
    PRINTF("Setting Power.\n");
    bool checkModulation = setModulation();
    PRINTF("Setting Modulation\n");
    bool checkProgramming = setProgramming();
    PRINTF("Programming to memory\n");
    exitCommandMode();

    PRINTF("checkMode: %d\n", checkMode);
    PRINTF("checkDealerMode: %d\n", checkDealerMode);
    PRINTF("checkChannel: %d\n", checkChannel);
    PRINTF("checkRxFreq: %d\n", checkRxFreq);
    PRINTF("checkTxFreq: %d\n", checkTxFreq);
    PRINTF("checkBandwidth: %d\n", checkBandwidth);
    PRINTF("checkPower: %d\n", checkPower);
    PRINTF("checkModulation: %d\n", checkModulation);
    PRINTF("checkProgramming: %d\n", checkProgramming);

    if (checkMode && checkChannel && checkRxFreq && checkTxFreq && checkBandwidth
    && checkBandwidth && checkModulation && checkProgramming && exit) {
        PRINTF("Radio Properly Configured\n");
    } else {
        PRINTF("Error configuring radio\n");
    }

}

void prep_payload(bool* img_ready, bool* com_ready, bool* gnc_ready, bool* eps_ready) {
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
#if COSMOS_TEST
	/* downlink primary telemetry */
	d_primary_tel1.packetLength = 1;
	d_primary_tel1.packetID = 1;
	d_primary_tel1.messageLength = 1;
	d_primary_tel1.encryptionLayer = 1;
	d_primary_tel1.crc = 1;

	d_ack_tel1.packetLength = 1;
	d_ack_tel1.packetID = 1;
	d_ack_tel1.ackMessage = 1;
	d_ack_tel1.crc = 1;

	for(int i=0; i<d_primary_tel1.messageLength; i++) {
		d_cmd_tel1[i].packetLength = 1;
		d_cmd_tel1[i].packetID = 1;
		d_cmd_tel1[i].packetMessage = 1;
		d_cmd_tel1[i].crc = 1;
	}

#else
	if(!gnc_ready) { //get GNC payload
		xQueueSend(cmd_queue_GNC, &(REQUEST_PAYLOAD), ( TickType_t ) 0 );
	} else if (!eps_ready) { // get EPS payload
		xQueueSend(cmd_queue_GNC, &(REQUEST_PAYLOAD), ( TickType_t ) 0 );
	} else if(!com_ready) { // get COM payload
		//TODO: COM Payload
		// MCC Comand config radio -> config radio
		// Downlink: Radio config improperly
		// COM Healthcheck:
		// Downlink: COM is operating properly
		// MCC command: Option to shut down transmission.
	} else if(!img_ready) { // get IMG payload
		xQueueSend( cmd_queue_IMG, &(REQUEST_PAYLOAD), ( TickType_t ) 0 ); // get Picture
	}

	vTaskDelay(xDelayms);

	uint8_t packetLength = 0;
	uint8_t cmdID = 0;
	/* EXAMPLE OF HOW IT MIGHT SEND DOWN DATA */
	if ( xQueueReceive( tlm_queue_COM, &(packetLength), ( TickType_t ) 10 ) == pdPASS ) {
		xQueueReceive( tlm_queue_COM, &(cmdID), ( TickType_t ) 10 );
		// execute IMG cmd
		switch (cmdID) {
			case(EPS_READY):
				eps_ready = true;
				break;
			case(GNC_READY):
				gnc_ready = true;
				break;
			case(IMG_READY):
				img_ready = true;
				break;
			/* add more packetID */
			default:
				break;
		}
	}
#endif
}

void* get_payload(uint8_t* payload_buffer, uint8_t messageLength) {
	uint8_t payload = 0;
	for(int i = 0; i < messageLength - PACKET_HEADER_SIZE; i++) {
		//xQueueReceive( tlm_queue_COM, &(packetLength), ( TickType_t ) 10 ) == pdPASS
		//payloadBuffer[i] =
	}
}

void uplink_handshake(uint32_t* cmd_packet_size) {
	/*
	* For this portion of the code it should pull data from the background
	* buffer needed to execute the HMAC Algorithm
	*/

#if COM_ENABLE
	size_t n = 0;
	if(!(kLPUART_RxDataRegEmptyFlag & LPUART_GetStatusFlags(COM_RTOS_UART_HANDLE)) ) { //recv_buffer not empty
		/* receive Transmission Primary Header & ACKNOWLEDGEMENT */
		LPUART_RTOS_Receive(&COM_RTOS_UART_HANDLE, &uplink_recv_buffer, (uint32_t)(PRIMARY_HEADER_SIZE + ACK_SIZE), &n);
	}
#elif COSMOS_TEST
	// receive char
	u_primary_tel1.crc = 0;
	u_primary_tel1.packetLength 	=  (uint8_t)GETCHAR();
	u_primary_tel1.packetID 		=  (uint8_t)GETCHAR();
	u_primary_tel1.messageLength 	=  (uint8_t)GETCHAR();
	u_primary_tel1.packetVersion 	=  (uint8_t)GETCHAR();
	u_primary_tel1.packetType 		=  (uint8_t)GETCHAR();
	u_primary_tel1.crc 			    |= (uint8_t)GETCHAR();    	// first byte
	u_primary_tel1.crc 			    |= ((uint8_t)GETCHAR())<<8; // second byte

	u_ack_tel1.packetLength			=  (uint8_t)GETCHAR();
	u_ack_tel1.packetID 			=  (uint8_t)GETCHAR();
	u_ack_tel1.ackMessage			=  (uint8_t)GETCHAR();
	u_ack_tel1.crc 			   	    |= (uint8_t)GETCHAR();    	// first byte
	u_ack_tel1.crc 			        |= ((uint8_t)GETCHAR())<<8; // second byte

	for(int i = 0; i < u_primary_tel1.messageLength; i++) {
		u_tel1[i].packetLength 		=  (uint8_t)GETCHAR();
		u_tel1[i].packetID			=  (uint8_t)GETCHAR();
		u_tel1[i].packetMessage 	=  (uint8_t)GETCHAR();
		u_tel1[i].crc				|= (uint8_t)GETCHAR();		// first byte
		u_tel1[i].crc				|= ((uint8_t)GETCHAR())<<8; // second byte
	}
#endif

#if HMAC_ENABLE
	// the key to hash
	char *key = strdup("Start uplinking");
	int keylen = strlen(key);

	// the data that we're going to hash using HMAC
	const unsigned char *data = (const unsigned char *)strdup("Security verify");
	int datalen = strlen((char *)data);

	unsigned char *result = NULL;
	unsigned int resultlen = -1;

	// call sha256 hash engine function
	// hashed output = "538b4306b1b28db75d84797c620c2a3c81a1dfa8e626283fcc66b554bd38f350"
	result = hmac_sha256((const void *)key, keylen, data, datalen, result, &resultlen);

	// get the hash key (256 bits - 64 characters) from the header packet (the last 256 bits of the packet)
	// unsigned char *hashkey = (unsigned char*)

	static char res_hexstring[SHA256_HASH_SIZE * 2];

	int result_length = SHA256_HASH_SIZE;

	// convert the result to string with printf
	// SHA256 is 256 bits long which rendered as 64 characters
	// (be careful of the length of string with the choosen hash engine)
	for (int i = 0; i < result_length; i++) {
	    sprintf(&(res_hexstring[i * 2]), "%02x", result[i]);
	}

	// compare the string pointed to by HMAC from ground station to the string pointed to by expected result
	if (strcmp((char *) res_hexstring, (char *) hashkey) == 0) {
		PRINTF("Passed security verify, start uplinking.\n");
		noError = true; // receive all function successfully
	}

	// if strings not matched or if there's no HMAC from ground station
	PRINTF("Not from AACT ground station, waiting for the next response.\n");
	noError = false; // security verification fails

#else
	bool noError = true;
#endif

	/* Process Incoming Message */
	if(noError) { // successful uplink handshake
		COM_State = UPLINKING;
	}
	// based packet structure

	cmd_packet_size = 0; //set cmd packet size
}

void send_payload() {
	// primary
	char* primary_tx_buffer = (char *)&d_primary_tel1;
	for(int i=0; i<(D_PRIMARY_SIZE); i++) {
		PRINTF("%c", primary_tx_buffer[i]);
	}
	// ack
	char* ack_tx_buffer = (char *)&d_ack_tel1;
	for(int i=0; i<(D_ACK_SIZE); i++) {
		PRINTF("%c", ack_tx_buffer[i]);
	}
	// cmd
	for(int j=0; j<d_primary_tel1.messageLength; j++) {
		char* cmd_tx_buffer= (char *)&d_cmd_tel1[j];
		for(int i=0; i<(D_CMD_SIZE); i++) {
			PRINTF("%c", cmd_tx_buffer[i]);
		}
	}
}
