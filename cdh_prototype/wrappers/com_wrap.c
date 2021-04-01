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
#include "peripherals.h"
#include "fsl_lpi2c_freertos.h"
#include "fsl_lpi2c.h"

#define I2C_COM_DOOR1_STATUS 0;  //0 is door closed, 1 is door open-- do i need these 4, think i only need to know if all 4 are deployed
#define I2C_COM_DOOR2_STATUS 0;
#define I2C_COM_DOOR3_STATUS 0;
#define I2C_COM_DOOR4_STATUS 0;
#define I2C_COM_ALL_DOORS_DEPLOYED 0;

#define I2C_COM_OPERATION_MODE 0; //0 is normal mode, 1 is test mode
#define I2C_COM_DEPLOY_ALGORITHM 0; //01 is algorithm 1, 10 is algorithm 2


uint8_t recv_buffer[rx_size];


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


void com_deployAntenna()
{

    //command format passed in is 00 s1 s0 ant4 ant3 ant2 ant1 where s1 and s0 are which algorithm to use
    // and ant1-4 are which door/antenna rod to be deployed
    if (rx_buffer[2] == 1) //replace w/ actual name instead of constant
    {
        com_i2c_algorithmTwo();
    } else if (rx_buffer[2] == 0 && rx_buffer[3] == 1) //if 3rd bit in command is a 1 execute command 1
    {
       i2c_com_algorithmOne();
    }
}

void com_all_doors_deployed() //this is probably not necessary
{
    if (I2C_COM_DOOR1_STATUS && I2C_COM_DOOR2_STATUS && I2C_COM_DOOR3_STATUS && I2C_COM_DOOR4_STATUS) {
        I2C_COM_ALL_DOORS_DEPLOYED = 1;
    }
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


void com_i2c_algorithmOne() //algorithm detailed in user manual
{
    if (!I2C_COM_ALL_DOORS_DEPLOYED) {
            com_set_burn_wire1();
            //wait 5 seconds
            if (I2C_COM_ALL_DOORS_DEPLOYED == 0){
                com_set_burn_wire2();
                I2C_COM_ALL_DOORS_DEPLOYED = 1;
            }
    }
}


void com_i2c_algorithmTwo()
{
    com_set_burn_wire1();
    com_set_burn_wire2();
    //wait 20 seconds
    I2C_COM_ALL_DOORS_DEPLOYED = 1;
}


bool com_i2c_checkDeploy() //returns a true if doors are deployed
{
    return (com_all_doors_deployed == 1);
}