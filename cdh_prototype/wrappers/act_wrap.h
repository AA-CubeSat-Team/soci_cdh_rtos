/*
 * Pin #80	GPIO_AD_B1_10	UART4_TX
 * Pin #79	GPIO_AD_B1_11	UART4_RX
 */
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include <stdbool.h>
#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_types.h>

bool rwa_healthcheck();
bool mtq_healthcheck();
double readActMeas();
void gnc_sendCommand();
void rt_OneStep(void);
