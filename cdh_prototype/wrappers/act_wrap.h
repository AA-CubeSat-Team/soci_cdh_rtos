/*
 * Pin #80	GPIO_AD_B1_10	UART4_TX
 * Pin #79	GPIO_AD_B1_11	UART4_RX
 */
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include <stdbool.h>

bool rxw_healthcheck();
bool mtq_healthcheck();
