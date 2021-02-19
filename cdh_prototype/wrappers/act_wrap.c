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
#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_types.h>
#include <stdbool.h>

// structs we would need for the input and output to communicate with GNC
//typedef struct {
//  boolean_T mtq_valid[5];
//  boolean_T rwa_valid[4];
//  real_T rwa_power;
//  real_T mtq_power;
//  real_T rwa_rpm[4];
//} actuator_meas;
//
//typedef struct {
//  real_T A[12];
//  real_T max_norm_ellipsoid_R[3];
//  uint8_T num_facet;
//  real_T h_targ_wheel_Nms[4];
//  real_T feedback_gain;
//  uint8_T id_facet[12];
//  uint8_T id_facet_complement[12];
//  real_T w_facet[18];
//  real_T g_facet[6];
//  real_T inrm2[6];
//} RWA;
//
//typedef struct {
//  real_T rwa_cmd_rpm[4];
//  real_T mtq_cmd_Am2[5];
//  real_T gnc_telemetry[6];
//} fsw_out;

bool rwa_healthcheck()
{
	PRINTF("checking reaction wheel health\r\n");
	return true;
}

bool mtq_healthcheck()
{
	PRINTF("checking magnetorquer health\r\n");
	return true;
}

double readActMeas()
{
	PRINTF("Read RWA and MTQ measurements\r\n");
	return 0.0;
}

void gnc_sendCommand() //we will have something like rwa_writeDeg() to use
{
	PRINTF("Sending command to GNC\r\n");
}
