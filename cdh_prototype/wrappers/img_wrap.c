/*
 * Pin #80	GPIO_AD_B1_10	UART4_TX
 * Pin #79	GPIO_AD_B1_11	UART4_RX
 */
#include <img_wrap.h>
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include <stdbool.h>

bool img_healthcheck(){
	PRINTF("checking IMG health");
	return true;
}

void img_sendCommand(){
	PRINTF("sending commands to IMG");
}
