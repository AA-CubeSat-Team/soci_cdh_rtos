/*
 * MCU Pinouts:

COM:

105	GPIO_AD_B0_06	UART1_TX	COM Board
101	GPIO_AD_B0_07	UART1_RX	COM Board
83	GPIO_AD_B1_07	ANT_BURN_WIRE1	Antenna Burn Wire 1
78	GPIO_AD_B1_12	ANT_BURN_WIRE2	Antenna Burn Wire 2
 */
#include "fsl_gpio.h"
#include "com_wrap.h"
#include "fsl_lpuart.h"
#include "fsl_lpuart_freertos.h"
#include "fsl_debug_console.h"
#include <stdbool.h>
#include <time.h>
#include "peripherals.h"
#include "fsl_lpi2c_freertos.h"
#include "fsl_lpi2c.h"

#define I2C_COM_RX_SIZE 4
#define I2C_COM_ANTENNA_SLAVE_ADDRESS 0x33   //should this be 16bit?
#define CLOCKS_PER_SECOND 1000000 //i believe this should be different depending on each CPU


#define DEFAULT_RETRIES 5
#define DEFAULT_RETRY_DELAY 0.4
#define RADIO_FREQ_STEP_HZ 6250
#define RADIO_DEFAULT_BANDWIDTH 12500


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
static char set_current_power[] = {0x01, 0x71, 0x01, 0x8E};
static char get_current_power[] = {0x01, 0x72, 0x8E};
static char set_tx_freq[] = {0x01, 0x37, 0x01, 0x19, 0xF5, 0xF7, 0x30, 0x92};
static char set_rx_freq[] = {0x01, 0x39, 0x01, 0x19, 0xF5, 0xF7, 0x30, 0x90};
static char get_tx_freq[] = {0x01, 0x38, 0x01, 0xC6};
static char get_rx_freq[] = {0x01, 0x3a, 0x01, 0xC4};
static char set_channel[] = {0x01, 0x03, 0x03, 0x83, 0x77}; //set to channel 3
static char set_bandwidth[] = {0x01, 0x70, 0x04, 0x01, 0x8A};
static char set_modulation[] = {0x01, 0x70, 0x49, 0x00, 0x00}; //last 2 should be replaced when setting is determined
static char program_buf[] = {0x01, 0x1E, 0xE1};
static char warm_reset[] = {0x01, 0x1D, 0x01, 0xE1};
static char set_led_rx[] = {0x70, 0x36, 0x00, 0x5A};

//Program the expected responses for each command
static char set_dealer_response[] = {0x01, 0xC4, 0x00, 0x3B};
static char set_power_response[] = {0x01, 0xF1, 0x00, 0x0F};
static char get_power_response[] = {0x01, 0xF2, 0x01, 0x0D}; //done
static char set_tx_freq_response[] = {0x01, 0xB7}; //should be updated to actual freq.
static char set_rx_freq_response[] = {0x01, 0xB9}; //should be updated
static char set_channel_response[] = {0x01, 0x83, 0x03, 0x00, 0x7A};
static char set_bandwidth_response[] = {0x01, 0xF0, 0x00, 0x10};
static char set_modulation_response[] = {0x01, 0xAB}; //TBD
static char program_response[] = {0x01,0x9E, 0x00, 0x62};
static char reset_response[] = {0x01, 0x9D, 0x00, 0x63};
static char set_led_rx_response[] = {0x01, 0x00, 0xFF, 0x01};



static char tx_buffer[] = {};
static char rx_buffer[] = {};
static char downlink_buffer[] = {};
static int rx_size = 0;

static void com_deployAntenna_algorithmTwo();
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


// commands data: what type? how big?
// payload data: what type? how big?
// image data: what type? how big?
// beacons: what type? how big?



//set radio ito command mode with dealer mode off
//returns true if properly set to command mode & dealer off
static bool enterCommandMode()
 {
	PRINTF("Setting to Command Mode");
	delay(0.1);
	//clear buffer here
	//memset();
	rx_buffer[0] = "+++";
	LPUART_RTOS_Send(&uart3_handle, *rx_buffer, sizeof(rx_buffer));
	//send +++ over uart

	delay(0.1);

}


//Sends a command to the radia via UART, retries several times if there is a failure.
static bool sendConfigCommand(char * data, char * expectedResponse) {
    int try = 0;
    int sizeofTx = sizeof(expectedResponse);
    for (int i = 0; i < sizeofTx; i++) {
    	tx_buffer[i] = data[i];
    }
    // Sends data to radio via UART, if the response is not correct it retries sending the command
    while (try < DEFAULT_RETRIES) {
        LPUART_RTOS_Send(&uart3_handle, tx_buffer, sizeof(tx_buffer));
        LPUART_RTOS_Receive(&uart3_handle, rx_buffer, sizeof(rx_buffer));
        bool sentCommand = checkConfigCommand(*rx_buffer, *expectedResponse);
        if (sentCommand) {
        	try = 5;
            return true;

        }
        try++;
        delay(0.1);
    }
    PRINTF("unexpected response");
    return false;
}


//checks if radio response to command is correct
static bool checkConfigCommand(char * actualResponse, char * expectedResponse) {
	int lengthOfResponse = sizeof(expectedResponse);
	for (int j = 0; j < lengthOfResponse; j++) {
		if (actualResponse[j] != expectedResponse[j]) {
			return false;
		}
	}
	return true;
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
	GPIO_PinInit(GPIO1, 23, &gpioConfig); //GPIO_AD_B1_07
	GPIO_PinInit(GPIO1, 28, &gpioConfig); //GPIO_AD_B1_12
}

void com_set_burn_wire1()
{
	GPIO_PinWrite(GPIO1, 23, 1); //GPIO_AD_B1_07, J19-1
}

void com_set_burn_wire2()
{
	GPIO_PinWrite(GPIO1, 28, 1); //GPIO_AD_B1_12, J18-3, GND->J20-6
}


bool com_healthcheck() //checks power
{
	PRINTF("checking COM health\r\n");
	//getCurrentPower();
	bool setToCommand = entercommandMode();
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

	memset(rcv_buffer, 0, sizeof(*rcv_buffer)); //necessary?
	// void * memset ( void * ptr, int value, size_t num );

	// void * memcpy ( void * destination, const void * source, size_t num );

	if (kStatus_Success != LPUART_RTOS_Send(&uart3_handle, (uint8_t *)to_send, strlen(to_send)))
	{
		PRINTF("could not send!!!\r\n\r\n");
		return;
	}

	status_t error = LPUART_RTOS_Receive(&uart3_handle, rcv_buffer, sizeof(rcv_buffer), &n);
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
		if (kStatus_Success != LPUART_RTOS_Send(&uart3_handle, (uint8_t *)rcv_buffer, n))
		{
			vTaskSuspend(NULL);
		}
	}

	PRINTF("getting commands from the ground station\r\n");
}



//proper code below:

void com_deployAntenna()
{
	//using algorithm one as the default
    I2C_send(&i2c1_m_rtos_handle, I2C_COM_ANTENNA_SLAVE_ADDRESS, algorithmOne, sizeof(algorithmOne));
	deploy_initiated = clock();
    delay(15); //longest time possible to deploy is 15 seconds
}

static void com_deployAntenna_algorithmTwo()
{
	I2C_send(&i2c1_m_rtos_handle, I2C_COM_ANTENNA_SLAVE_ADDRESS, algorithmTwo, sizeof(algorithmTwo));
	delay(30); //longest time possible to deploy is 30 seconds
}


void com_sendPayloads() //high priority
{
	if (kStatus_Success != LPUART_RTOS_Send(&uart3_handle, downlink_buffer, sizeof(downlink_buffer))) {
		PRINTF("could not send payload\r\n\r\n");
		return;
	}
	PRINTF("sending payloads\r\n");
}

void com_sendImages() //medium priority
{
	if (kStatus_Success != LPUART_RTOS_Send(&uart3_handle, downlink_buffer, sizeof(downlink_buffer))) {
			PRINTF("could not send Images\r\n\r\n");
			return;
		}
		PRINTF("sending images\r\n");
}

void com_sendBeacons() //low priority, happens every 60 secs
{
	if (kStatus_Success != LPUART_RTOS_Send(&uart3_handle, downlink_buffer, sizeof(downlink_buffer))) {
			PRINTF("could not send beacon\r\n\r\n");
			return;
		}
		PRINTF("sending beacon\r\n");
}


//void I2C_send(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t * masterSendBuffer, size_t tx_size)
//void I2C_request(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t * rx_buffer, size_t rx_size)


bool com_i2c_checkDeploy() //returns a true if doors are deployed
{
	clock_t current_time = clock();
	if ((current_time-deploy_initiated)/CLOCKS_PER_SECOND < 900) {
		PRINTF("Not enough time has elapsed for the antenna to deploy\r\n");
		return false;
	}
	memset(rcv_buffer, 0, sizeof(*rcv_buffer));
	I2C_request(&i2c1_m_rtos_handle, I2C_COM_ANTENNA_SLAVE_ADDRESS, rcv_buffer, sizeof(rcv_buffer));
	//Receive 4 bytes back with status of antenna
	//First byte of rx_buffer is:
	//MSB LSB D4 D3 D2 D1 0 M S2 S1
	uint8_t rcv_byteZero = rcv_buffer[0];
	//iterate through first byte to find if all rods are deployed
	uint8_t byteZero = byteZero << 2;
	bool allDeployed = true;
	for (int i = 0; i < 4; i++) {
		unsigned checkBit = rcv_byteZero << 1;
		if (!(checkBit & 1)) { //check if the bit is 0
			allDeployed = false;
		}
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



static void exitCommandMode() {
	bool exitedCommandMode = sendConfigCommand(warm_reset, reset_response);
	if (exitedCommandMode) {
		PRINTF("Radio reset to data mode.");
		return true;
	}
	PRINTF("Unable to reset radio to data mode.");
	return false;
}


//Set to a default channel of 1
static bool setChannel() {
    bool successChannel = sendConfigCommand(set_channel, set_channel_response);
    if (successChannel) {
        PRINTF("Channel successfully set to 1");
        return true;
    }
     PRINTF("Failure to set channel");
     return false;
}

//Set to a tx freq of
static bool setTxFreq() {
    bool successTX = sendConfigCommand(set_tx_freq, set_tx_freq_response);
    if (successTX) {
        PRINTF("Tx frequency set to ____");
        return true;
    }
     PRINTF("Failure to set tx frequency");
     return false;
}

//Set to a rx freq of
static bool setRxFreq() {
    bool successRX = sendConfigCommand(set_rx_freq, set_rx_freq_response);
    if (successRX) {
        PRINTF("Rx frequency set to ____");
        return true;
    }
     PRINTF("Failure to set Rx frequency");
     return false;
}

//Set to a bandwidth
static bool setBandwidth() {
    bool successBandwidth = sendConfigCommand(set_bandwidth, set_bandwidth_response);
    if (successBandwidth) {
        PRINTF("Bandwidth set to ____");
        return true;
    }
     PRINTF("Failure to set Bandwidth");
     return false;
}


//Set to a modulation of
static bool setModulation() {
    bool successModulation = sendConfigCommand(set_modulation, set_modulation_response);
    if (successModulation) {
        PRINTF("Modulation set to 4-Level GSK");
        return true;
    }
     PRINTF("Failure to setModulation");
     return false;
}


static bool setProgramming() {
    bool successProgramming = sendConfigCommand(program_buf, program_response);
    if (successProgramming) {
        PRINTF("Set to non volatile memory");
        return true;
    }
     PRINTF("Failure to program to memory");
     return false;
}



static bool setPower() {
	bool successPower = sendConfigCommand(set_current_power, set_power_response);

	if(successPower) {
		PRINTF("0.5W power set properly.");
		return true;
	}
	PRINTF("Failure to set to power to 0.5W.");
	return false;
}

//This should be used for testing on flatsat, will not be used in the flight module.
static bool setLEDRx() {
	bool checkLED = sendConfigCommand(set_led_rx, set_led_rx_response);
	if (checkLED) {
		PRINTF("LED for Rx is turned on.");
	}
	PRINTF("LED is not set properly.");
	return false;
}

static bool getPower() {
	bool checkPower = sendConfigCommand(get_current_power, get_power_response);

	if(checkPower) {
		PRINTF("0.5W power set properly.");
		return true;
	}
	PRINTF("Power is not set correct.");
	return false;
}


static void configRadio(){
    bool checkMode = enterCommandMode();
    PRINTF("Entering command mode");
    bool checkChannel = setChannel();
    PRINTF("Setting Channel");
    bool checkRxFreq = setRxFreq();
    PRINTF("Setting Rx Frequency");
    bool checkTxFreq = setTxFreq();
    PRINTF("Setting Tx Frequency");
    bool checkBandwidth = setBandwidth();
    PRINTF("Setting Bandwidth");
    bool checkPower = setPower();
    PRINTF("Setting Power.");
    bool checkModulation = setModulation();
    PRINTF("Setting Modulation");
    bool checkProgramming = setProgramming();
    PRINTF("Programming to memory");
    exitCommandMode();

    if (checkMode && checkChannel && checkRxFreq && checkTxFreq && checkBandwidth
    && checkBandwidth && checkModulation && checkProgramming && exit) {
        PRINTF("Radio Properly Configured");
    } else {
        PRINTF("Error configuring radio");
    }

}
