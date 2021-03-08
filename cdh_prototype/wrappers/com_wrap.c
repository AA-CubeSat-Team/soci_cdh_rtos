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

uint8_t recv_buffer[4];

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
	GPIO_PinInit (GPIO, uint32_t port, uint32_t pin, const gpio_pin_config_t *config)
}
void com_set_burn_wire()
{

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



