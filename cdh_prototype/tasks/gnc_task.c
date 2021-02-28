
/* FreeRTOS kernel includes. */
//#include "FSW_Lib_types.h"


#include <gnc_task.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "clock_config.h"

//#include "FSW_Lib_types.h"
#include "act_wrap.h"
#include "sen_wrap.h"

//#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_types.h>
//#include <wrappers/FSW_Lib_types.h>
//#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>

//temporary struct until we receive an functional GNC build folder
//typedef struct {
//  real_T solar_panel_power_W[6];
//  real_T photodiodes_A[6];
//  real_T mag_body_T[9];
//  boolean_T mag_meas_valid[3];
//  real_T sun_meas_ss_deg[2];
//  boolean_T sun_meas_valid;
//  real_T gyro_body_radps[9];
//  boolean_T gyro_meas_valid[3];
//} sensor_bus;
//
//typedef struct {
//  boolean_T mtq_valid[5];
//  boolean_T rwa_valid[4];
//  real_T rwa_power;
//  real_T mtq_power;
//  real_T rwa_rpm[4];
//} actuator_meas;
//
//typedef struct {
//  real_T rwa_cmd_rpm[4];
//  real_T mtq_cmd_Am2[5];
//  real_T gnc_telemetry[6];
//} fsw_out;


void gnc_task(void *pvParameters)
{
	// Question: Can we read all sensors, calculate the response and deliver the response to actuators with the

	// TODO: Can we move structs sens_meas, act_meas etc. to sens_task.c? Does any other task use these values?
	extern bool g_sunSensActive, g_magSensActive, g_phdSensActive, g_mtqSensActive, g_rwaSensActive;
	// extern sens_meas; necessary?
	// variables to use with sens task


	//temp struct variables
//	struct sensor_bus sens_var;
//	struct actuator_meas actu_var;
//	struct fsw_out fsw_var;

	// variable to store ticks equivalent to 500 ms
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //was 10
	PRINTF("\ninitialize gnc.\r\n");

	/* gnc, sens, act initialization */
//	 FSW_Lib_initialize(); //GNC board initialization



	for (;;) {

		TickType_t xLastWakeTime = xTaskGetTickCount();
		PRINTF("\nsens START.\r\n");

//		int c = 0;
//		while (c < 100000) {
//			PRINTF("");
//			c++;
//		}
//		vTaskDelayUntil(&xLastWakeTime, xDelayms);
//		xLastWakeTime = xTaskGetTickCount();
//		PRINTF("sens END.\r\n");

		/* read sensors and actuator measurements to sensor_bus */

//		if(g_sunSensActive == true){
//			sens_readSun();
//		}
//		else{
//			PRINTF("sun sensor not active\r\n");
//		}
//
//		if(g_magSensActive == true){
//			sens_readMag();
//		}
//		else{
//			PRINTF("magnetometer not active\r\n");
//		}
//
//		if(g_phdSensActive == true){
//			sens_readPhd();
//		}
//		else{
//			PRINTF("photodiode not active\r\n");
//		}
		sens_readSun();
		sens_readMag();
		sens_readPhd();
		sens_readGyr();
		readActMeas();

		/* call GNC rt_OneStep() */

		// TODO: enable rt_OneStep(); after include
		// rt_OneStep();

		/* send to actuators */
//		typedef struct {
//		  real_T solar_panel_power_W[6];
//		  real_T photodiodes_A[6];
//		  real_T mag_body_T[9];
//		  boolean_T mag_meas_valid[3];
//		  real_T sun_meas_ss_deg[2];
//		  boolean_T sun_meas_valid;
//		  real_T gyro_body_radps[9];
//		  boolean_T gyro_meas_valid[3];
//		} sensor_bus;
//
//		typedef struct {
//		  boolean_T mtq_valid[5];
//		  boolean_T rwa_valid[4];
//		  real_T rwa_power;
//		  real_T mtq_power;
//		  real_T rwa_rpm[4];
//		} actuator_meas;
//
//		typedef struct {
//		  real_T rwa_cmd_rpm[4];
//		  real_T mtq_cmd_Am2[5];
//		  real_T gnc_telemetry[6];
//		} fsw_out;

		gnc_sendCommand();

		/* printing to check if we have written everything correctly */
//		PRINTF("photodiodes_A=%d,\n mag_body_T=%d,\n sun_meas_ss_deg=%d,\n, gyro_body_radps=%d,\n, mtq_power=%d,\n, rwa_rpm=%d,\n rwa_cmd_rpm=%d\n",
//				sens_var.photodiodes_A[0], sens_var.mag_body_T[0], sens_var.sun_meas_ss_deg[0], sens_var.gyro_body_radps[0], actu_var.mtq_power[0], actu_var.rwa_rpm[0], fsw_var.rwa_cmd_rpm[0]);

		//These two magnetorquer and reaction wheel are not sensors
//		if(g_mtqSensActive == true){
//			//uart_send(fsw_out...);
//		}
//		else{
//		}
//
//		if(g_rwaSensActive == true){
//
//		}
//		else{
//
//		}

		vTaskDelayUntil(&xLastWakeTime, xDelayms);

	}
}
