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


#define I2C_COM_OPERATION_MODE 0; //0 is normal mode, 1 is test mode
#define I2C_COM_DEPLOY_ALGORITHM 0; //01 is algorithm 1, 10 is algorithm 2
#define ANTENNA_SLAVE_ADDRESS 0x33; //0x33 is slave address but convert to 16 bit somehow 
#define rx_size = 4; //receiving 4 bytes

uint8_t rx_buffer[rx_size];
bool i2c_com_antennaDeployed = False;
uint8_t algorithmOne[] = {0x00, 0x00, 0x00, 0x1F};
uint8_t algorithmTwo[] = {0x00, 0x00, 0x00, 0x2F};


void delay();


// commands data: what type? how big?
// payload data: what type? how big?
// image data: what type? how big?
// beacons: what type? how big?

void com_radio_init()
{
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


bool com_healthcheck()
{
	PRINTF("checking COM health\r\n");
	return true;
}

void com_getCommands() //highest priority
{
	size_t n;

	char * to_send = "com: give me commands";

	memset(recv_buffer, 0, sizeof(recv_buffer)); //necessary?
	// void * memset ( void * ptr, int value, size_t num );

	// void * memcpy ( void * destination, const void * source, size_t num );

	if (kStatus_Success != LPUART_RTOS_Send(&uart3_handle, (uint8_t *)to_send, strlen(to_send)))
	{
		PRINTF("could not send!!!\r\n\r\n");
		return;
	}


	status_t error = LPUART_RTOS_Receive(&uart3_handle, recv_buffer, sizeof(recv_buffer), &n);
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
		if (kStatus_Success != LPUART_RTOS_Send(&uart3_handle, (uint8_t *)recv_buffer, n))
		{
			vTaskSuspend(NULL);
		}
	}

	PRINTF("getting commands from the ground station\r\n");
}



//proper code below:

void com_deployAntenna_algorithmOne()
{		
    i2c_send(handle, ANTENNA_SLAVE_ADDRESS, (uint8_t *)algorithmOne, sizeof(algorithmOne));
    delay(15); //longest time possible to deploy is 15 seconds
}

void com_deployAntenna_algorithmTwo()
{
	I2C_send(handle, ANTENNA_SLAVE_ADDRESS, (uint8_t *)algorithmTwo, sizeof(algorithmTwo));
	delay(30); //longest time possible to deploy is 30 seconds
}


void com_sendPayloads() //high priority
{
	PRINTF("sending payloads\r\n");
}

void com_sendImages() //medium priority
{
	PRINTF("sending images\r\n");
}

void com_sendBeacons() //low priority, happens every 60 secs
{
	PRINTF("sending beacons\r\n");
}


//void I2C_send(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t * masterSendBuffer, size_t tx_size)
//void I2C_request(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t * rx_buffer, size_t rx_size)


bool com_i2c_checkDeploy() //returns a true if doors are deployed
{
	memset(rx_buffer, 0, sizeof(*rx_buffer));
	I2C_request(handle, ANTENNA_SLAVE_ADDRESS, rx_buffer, sizeof(rx_buffer));
	//Receive 4 bytes back with status of antenna
	//First byte of rx_buffer is: 
	//MSB LSB D4 D3 D2 D1 0 M S2 S1 
	uint8_t rx_byteZero = rx_buffer[0];
	//iterate through first byte to find if all rods are deployed
	bool allDeployed = true;
	for (int i = 0; i < 4; i++) {
		//not 100% sure if this is the right way to parse bit by bit
		unsigned checkBit = rx_byteZero << 1;
		if (!(checkBit & 1)) { //check if the bit is 0
			allDeployed = false;
		}
	}
	
    if (allDeployed) {
    	i2c_com_antennaDeployed = true;
        PRINTF("antenna deployed\r\n");
    } else {
    	i2c_com_antennaDeployed = false;
        PRINTF("antenna not deployed\r\n");
    }
    return i2c_com_all_doors_deployed;
}

//function from https://www.geeksforgeeks.org/time-delay-c/
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}