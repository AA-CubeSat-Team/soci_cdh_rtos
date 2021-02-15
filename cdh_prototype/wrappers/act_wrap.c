/*
 * Pin #80	GPIO_AD_B1_10	UART4_TX
 * Pin #79	GPIO_AD_B1_11	UART4_RX
 *
 * Pin #96	GPIO_AD_B0_12	SPI1_MOSI	RXN Wheels
 * Pin #95	GPIO_AD_B0_13	SPI1_MISO	RXN Wheels
 * Pin #98	GPIO_AD_B0_10	SPI1_SCK	RXN Wheels
 */

#include <act_wrap.h>
#include "fsl_lpspi_freertos.h"
#include "fsl_lpspi.h"
#include "fsl_debug_console.h"
#include <stdbool.h>

bool rxw_healthcheck(){
	PRINTF("checking reaction wheel health");
	return true;
}

bool mtq_healthcheck(){
	PRINTF("checking magnetorquer health");
	return true;
}
