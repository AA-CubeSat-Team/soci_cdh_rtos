
/* FreeRTOS kernel includes. */
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
//#include "FSW_Lib_types.h"

void sens_task(void *pvParameters)
{
	// Question: Can we read all sensors, calculate the response and deliver the response to actuators with the

	// TODO: Can we move structs sens_meas, act_meas etc. to sens_task.c? Does any other task use these values?
	extern bool g_sunSensActive, g_magSensActive, g_phdSensActive, g_mtqSensActive, g_rwaSensActive;
	// extern sens_meas; necessary?
	// variables to use with sens task

	// variable to store ticks equivalent to 500 ms
	const TickType_t xDelayms = pdMS_TO_TICKS( 10 );
	PRINTF("initialize sens.\r\n");


	for (;;) {

		TickType_t xLastWakeTime = xTaskGetTickCount();
		PRINTF("sens work.\r\n");

		if(g_sunSensActive == true){
			//sens_meas.sun_meas_ss_deg = svfds;
		}
		else{

		}

		if(g_magSensActive == true){

		}
		else{

		}

		if(g_phdSensActive == true){

		}
		else{

		}

		// TODO: enable rt_OneStep(); after include


		if(g_mtqSensActive == true){
			//uart_send(fsw_out...);
		}
		else{
		}

		if(g_rwaSensActive == true){

		}
		else{

		}

		vTaskDelayUntil(&xLastWakeTime, xDelayms);

	}
}
