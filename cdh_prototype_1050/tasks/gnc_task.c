#include "dummy_type.h"
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
//#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>

//	temp struct variables
sensor_bus sens_var;
actuator_meas actu_var;
fsw_out fsw_var;

extern bool g_sunSensActive, g_magSensActive, g_phdSensActive, g_mtqSensActive, g_rwaSensActive;

void gnc_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	PRINTF("\ninitialize gnc.\r\n");
	/* gnc, sens, act initialization */
//	 FSW_Lib_initialize(); //GNC board initialization
	for (;;) {
		TickType_t xLastWakeTime = xTaskGetTickCount();
		PRINTF("\nGNC TASK START.\r\n");

		/* read sensors and actuator measurements to sensor_bus */
//		if(g_sunSensActive){
//			sens_readSun();
//		}
//		else{
//			PRINTF("sun sensor not active\r\n");
//		}
//
//		if(g_magSensActive){
//			sens_readMag();
//		}
//		else{
//			PRINTF("magnetometer not active\r\n");
//		}
//
//		if(g_phdSensActive){
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
		gnc_sendCommand();
		vTaskDelayUntil(&xLastWakeTime, xDelayms);

	}
}
