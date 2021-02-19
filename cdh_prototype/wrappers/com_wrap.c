///* This is a source file for testing the I2C commands required for the flight computer to
// * communicate with IMG
// *
// * Pin #105	GPIO_AD_B0_06	UART1_TX
// * Pin #101	GPIO_AD_B0_07	UART1_RX
// */
//
#include "com_wrap.h"
#include "fsl_lpuart.h"
#include "fsl_lpuart_freertos.h"
#include "fsl_debug_console.h"
#include <stdbool.h>

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

bool com_healthcheck()
{
	PRINTF("checking COM health\r\n");
	return true;
}

void com_getCommands() //highest priority
{
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



