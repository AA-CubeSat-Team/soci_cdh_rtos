
/* FreeRTOS kernel includes. */
//#include "FSW_Lib_types.h"


#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "sens_task.h"
#include "clock_config.h"
//#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_types.h>
//#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>

void sens_task(void *pvParameters)
{
	// Question: Can we read all sensors, calculate the response and deliver the response to actuators with the

	// TODO: Can we move structs sens_meas, act_meas etc. to sens_task.c? Does any other task use these values?
	extern bool g_sunSensActive, g_magSensActive, g_phdSensActive, g_mtqSensActive, g_rwaSensActive;
	// extern sens_meas; necessary?
	// variables to use with sens task

	// variable to store ticks equivalent to 500 ms
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //was 10
	PRINTF("\ninitialize sens.\r\n");


	for (;;) {

		TickType_t xLastWakeTime = xTaskGetTickCount();
		PRINTF("\nsens work.\r\n");

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

		// TODO: enable rt_OneStep(); after include
		// rt_OneStep();



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
