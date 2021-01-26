

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"


#include "idle_task.h"
#include "clock_config.h"


void idle_task(void *pvParameters)
{
	extern bool g_imagActive;
	extern bool g_commActive;
	extern bool g_sunSensActive;
	extern bool g_rwaSensActive;
	extern bool g_magSensActive;
	extern bool g_mtqSensActive;
	extern bool g_phdSensActive;

	g_imagActive = false;
	g_commActive = false;
	g_sunSensActive = false;
	g_rwaSensActive = false;
	g_magSensActive = false;
	g_mtqSensActive = false;
	g_phdSensActive = false;


	double voltage;
	int mode;


	// variable to store ticks equivalent to 500 ms
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 );


	for (;;) {

		// gets the last wake time
		TickType_t xLastWakeTime = xTaskGetTickCount();

		PRINTF("entered determineMode_task.\r\n");

		// TODO: Create a task to get the voltage from EPS system through I2C Communication
		// voltage will be between 6.144 and 8.26
		voltage = 7.5; // the voltage value that we get from the EPS

		// Idle Mode: 6.144 < voltage <= 7.9
		if (voltage <= 7.4 ) { // what if we dont get a voltage value

			mode = 0;

			// no more health check ups needed
			// start idle mode
			// set the corresponding flags

		// Safe Mode: 7.4 < voltage <= 7.9
		} else if (voltage <= 7.9 && voltage > 7.4) {

			mode = 1;

//			// do COM health check up
//			if (xTaskCreate(checkCOM_task, "checkCOM_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkCOM_TaskHandle) != pdPASS) {
//				PRINTF("checkCOM_task creation failed!.\r\n");
//				while (1);
//			}
//
//			// do GNC health check up
//			if (xTaskCreate(checkGNC_task, "checkGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkGNC_TaskHandle) != pdPASS) {
//				PRINTF("checkGNC_task creation failed!.\r\n");
//				while (1);
//			}
//
//			// do SEN health check up
//			if (xTaskCreate(checkSEN_task, "checkSEN_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkSEN_TaskHandle) != pdPASS) {
//				PRINTF("checkSEN_task creation failed!.\r\n");
//				while (1);
//			}
//
//			// start safe mode
//			if (xTaskCreate(safeMode_task, "safeMode_task", configMINIMAL_STACK_SIZE + 166, NULL, 3, &safeMode_TaskHandle) != pdPASS) {
//				PRINTF("safeMode_task creation failed!.\r\n");
//				while (1);
//			}

		// Normal Mode: 7.9 < voltage < 8.26
		} else {

			mode = 2;
//
//			// do COM health check up
//			if (xTaskCreate(checkCOM_task, "checkCOM_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkCOM_TaskHandle) != pdPASS) {
//				PRINTF("checkCOM_task creation failed!.\r\n");
//				while (1);
//			}
//
//			// do GNC health check up
//			if (xTaskCreate(checkGNC_task, "checkGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkGNC_TaskHandle) != pdPASS) {
//				PRINTF("checkGNC_task creation failed!.\r\n");
//				while (1);
//			}
//
//			// do SEN health check up
//			if (xTaskCreate(checkSEN_task, "checkSEN_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkSEN_TaskHandle) != pdPASS) {
//				PRINTF("checkSEN_task creation failed!.\r\n");
//				while (1);
//			}
//
//			// do IMG health check up
//			if (xTaskCreate(checkIMG_task, "checkIMG_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkIMG_TaskHandle) != pdPASS) {
//				PRINTF("checkIMG_task creation failed!.\r\n");
//				while (1);
//			}
//
//			// start nominal mode
//			if (xTaskCreate(normalMode_task, "normalMode_task", configMINIMAL_STACK_SIZE + 166, NULL, 2, &normalMode_TaskHandle) != pdPASS) {
//				PRINTF("normalMode_task creation failed!.\r\n");
//				while (1);
//			}
		}

		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
}
