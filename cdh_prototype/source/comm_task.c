
/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "comm_task.h"
#include "clock_config.h"



void comm_task(void *pvParameters)
{
	extern bool g_commActive;
	// variables to use with imag task

	// variable to store ticks equivalent to 500 ms
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 );

	for (;;) {

		TickType_t xLastWakeTime = xTaskGetTickCount();
		if(g_commActive == true){


		}
//		else{
//
//		}
		vTaskDelayUntil(&xLastWakeTime, xDelayms);

	}
}
