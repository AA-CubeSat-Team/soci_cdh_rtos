/* FreeRTOS kernel includes. */
#include "lpuart.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#include "peripherals.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

static void determineMode_task(void *pvParameters);

static void idleMode_task(void *pvParameters);
static void safeMode_task(void *pvParameters);
static void normalMode_task(void *pvParameters);

static void checkGNC_task(void *pvParameters);
static void checkCOM_task(void *pvParameters);
static void checkEPS_task(void *pvParameters);
static void checkOBC_task(void *pvParameters);
static void checkSEN_task(void *pvParameters);
static void checkIMG_task(void *pvParameters);

static void debugGNC_task(void *pvParameters);
static void debugCOM_task(void *pvParameters);
static void debugEPS_task(void *pvParameters);
static void debugOBC_task(void *pvParameters);
static void debugSEN_task(void *pvParameters);
static void debugIMG_task(void *pvParameters);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

// to be store in packets

unsigned int mode = 0; // 0: Critically Low Power Mode, 1: Low Power Mode, 2: Normal

TaskHandle_t determineMode_TaskHandle;

TaskHandle_t idleMode_TaskHandle;
TaskHandle_t safeMode_TaskHandle;
TaskHandle_t normalMode_TaskHandle;

TaskHandle_t checkGNC_TaskHandle;
TaskHandle_t checkCOM_TaskHandle;
TaskHandle_t checkEPS_TaskHandle;
TaskHandle_t checkOBC_TaskHandle;
TaskHandle_t checkSEN_TaskHandle;
TaskHandle_t checkIMG_TaskHandle;

TaskHandle_t debugGNC_TaskHandle;
TaskHandle_t debugCOM_TaskHandle;
TaskHandle_t debugEPS_TaskHandle;
TaskHandle_t debugOBC_TaskHandle;
TaskHandle_t debugSEN_TaskHandle;
TaskHandle_t debugIMG_TaskHandle;



/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */

int main(void)
{
    BOARD_ConfigMPU();
    //BOARD_InitPins(); //ERROR!
    BOARD_InitBootPeripherals();
    BOARD_InitBootPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole(); //this uses UART1 to print stuff back

    init_tasks();


    vTaskStartScheduler();


    // The system should never reach here.

    // (thought:)send the EPS system signal to restart the OBC? since it encountered an error

    for (;;);
}

/*******************************************************************************
 * Application functions
 ******************************************************************************/
/*!
 * @brief determineMode_task function
 *	this task determines the mode of the OBC according to the voltage from the EPS
 *  this task is periodic and happens every 500 ms.
 */
static void determineMode_task(void *pvParameters) {
    for (;;) {
    	// variable to store ticks equivalent to 500 ms
    	const TickType_t xDelayms = pdMS_TO_TICKS( 500 );

    	// gets the last wake time
    	TickType_t xLastWakeTime = xTaskGetTickCount();

        PRINTF("entered determineMode_task.\r\n");

        // TODO: Create a task to get the voltage from EPS system through I2C Communication
        // voltage will be between 6.144 and 8.26
        double voltage = 7.5; // the voltage value that we get from the EPS

        // Idle Mode: 6.144 < voltage <= 7.9
        if (voltage <= 7.4 ) { // what if we dont get a voltage value

        	mode = 0;

        	// no more health check ups needed
        	// start idle mode
        	if (xTaskCreate(idleMode_task, "idleMode_task", configMINIMAL_STACK_SIZE + 166, NULL, 4, &idleMode_TaskHandle) != pdPASS) {
        		PRINTF("idleMode_task creation failed!.\r\n");
        	    while (1);
        	}

        // Safe Mode: 7.4 < voltage <= 7.9
        } else if (voltage <= 7.9 && voltage > 7.4) {

        	mode = 1;

        	// do COM health check up
        	if (xTaskCreate(checkCOM_task, "checkCOM_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkCOM_TaskHandle) != pdPASS) {
        		PRINTF("checkCOM_task creation failed!.\r\n");
        	    while (1);
        	}

        	// do GNC health check up
        	if (xTaskCreate(checkGNC_task, "checkGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkGNC_TaskHandle) != pdPASS) {
        	    PRINTF("checkGNC_task creation failed!.\r\n");
        		while (1);
        	}

        	// do SEN health check up
        	if (xTaskCreate(checkSEN_task, "checkSEN_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkSEN_TaskHandle) != pdPASS) {
        	    PRINTF("checkSEN_task creation failed!.\r\n");
        	    while (1);
        	}

        	// start safe mode
        	if (xTaskCreate(safeMode_task, "safeMode_task", configMINIMAL_STACK_SIZE + 166, NULL, 3, &safeMode_TaskHandle) != pdPASS) {
        	    PRINTF("safeMode_task creation failed!.\r\n");
        	    while (1);
        	}

        // Normal Mode: 7.9 < voltage < 8.26
        } else {

        	mode = 2;

        	// do COM health check up
        	if (xTaskCreate(checkCOM_task, "checkCOM_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkCOM_TaskHandle) != pdPASS) {
        		PRINTF("checkCOM_task creation failed!.\r\n");
        		while (1);
        	}

        	// do GNC health check up
        	if (xTaskCreate(checkGNC_task, "checkGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkGNC_TaskHandle) != pdPASS) {
        	   	PRINTF("checkGNC_task creation failed!.\r\n");
        	  	while (1);
        	}

        	// do SEN health check up
        	if (xTaskCreate(checkSEN_task, "checkSEN_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkSEN_TaskHandle) != pdPASS) {
        	   	PRINTF("checkSEN_task creation failed!.\r\n");
        	   	while (1);
        	}

        	// do IMG health check up
        	if (xTaskCreate(checkIMG_task, "checkIMG_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &checkIMG_TaskHandle) != pdPASS) {
        		PRINTF("checkIMG_task creation failed!.\r\n");
        	   	while (1);
        	}

        	// start nominal mode
        	if (xTaskCreate(normalMode_task, "normalMode_task", configMINIMAL_STACK_SIZE + 166, NULL, 2, &normalMode_TaskHandle) != pdPASS) {
        	    PRINTF("normalMode_task creation failed!.\r\n");
        	    while (1);
        	}
        }

        vTaskDelayUntil(&xLastWakeTime, xDelayms);
    }
}

/*!
 * @brief idleMode_task function
 */
static void idleMode_task(void *pvParameters) {
    for (;;)
    {
        PRINTF("entered idleMode_task.\r\n");

        // TODO: update each subsystem to idle mode
        // turn off all the PDMs except OBC
        // 
        vTaskDelete(idleMode_TaskHandle);
    }
}

/*!
 * @brief safeMode_task function
 */
static void safeMode_task(void *pvParameters) {
    for (;;)
    {
        PRINTF("entered safeMode_task.\r\n");

        // TODO: update each subsystem to safe mode


        vTaskDelete(safeMode_TaskHandle);
    }
}

/*!
 * @brief normalMode_task function
 */
static void normalMode_task(void *pvParameters) {
    for (;;)
    {
        PRINTF("entered normalMode_task.\r\n");

        // TODO: after all the peripherals are checked, do the main stuff

        vTaskDelete(normalMode_TaskHandle);
    }
}

/*!
 * @brief checkSEN_task function
 */
static void checkSEN_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered checkSEN_task.\r\n");
        int statusSEN = 0; // 0 for OK, 1 for not OK
        // TODO: ask the SEN subsystem for its status


        // if SEN is not OK then start a debug of SEN
        if (statusSEN == 1) {
            if (xTaskCreate(debugSEN_task, "debugSEN_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &debugSEN_TaskHandle) != pdPASS) {
                PRINTF("debugSEN_task creation failed!.\r\n");
                while (1);
            }
        }
        vTaskDelete(checkSEN_TaskHandle);
    }
}

/*!
 * @brief checkIMG_task function
 */
static void checkIMG_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered checkIMG_task.\r\n");
        int statusIMG = 0; // 0 for OK, 1 for not OK
        // TODO: ask the IMG subsystem for its status


        // if IMG is not OK then start a debug of IMG
        if (statusIMG == 1) {
            if (xTaskCreate(debugIMG_task, "debugIMG_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &debugIMG_TaskHandle) != pdPASS) {
                PRINTF("debugIMG_task creation failed!.\r\n");
                while (1);
            }
        }
        vTaskDelete(checkIMG_TaskHandle);
    }
}
/*!
 * @brief checkGNC_task function
 */
static void checkGNC_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered checkGNC_task.\r\n");
        int statusGNC = 0; // 0 for OK, 1 for not OK
        // TODO: ask the GNC subsystem for its status


        // if GNC is not OK then start a debug of GNC
        if (statusGNC == 1) {
            if (xTaskCreate(debugGNC_task, "debugGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &debugGNC_TaskHandle) != pdPASS) {
                PRINTF("debugGNC_task creation failed!.\r\n");
                while (1);
            }
        }
        vTaskDelete(checkGNC_TaskHandle);
    }
}

/*!
 * @brief checkGNC_task function
 */
static void checkCOM_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered checkCOM_task.\r\n");
        int statusCOM = 0; // 0 for OK, 1 for not OK
        // TODO: ask the COM subsystem for its status


        // if COM is not OK then start a debug of COM
        if (statusCOM == 1) {
            if (xTaskCreate(debugCOM_task, "debugCOM_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &debugCOM_TaskHandle) != pdPASS) {
                PRINTF("debugCOM_task creation failed!.\r\n");
                while (1);
            }
        }
        vTaskDelete(checkCOM_TaskHandle);
    }
}

/*!
 * @brief checkGNC_task function
 */
static void checkEPS_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered checkEPS_task.\r\n");
        int statusEPS = 0; // 0 for OK, 1 for not OK
        // TODO: ask the EPS subsystem for its status


        // if EPS is not OK then start a debug of EPS
        if (statusEPS == 1) {
            if (xTaskCreate(debugEPS_task, "debugEPS_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &debugEPS_TaskHandle) != pdPASS) {
                PRINTF("debugEPS_task creation failed!.\r\n");
                while (1);
            }

        }
        vTaskDelete(checkEPS_TaskHandle);
    }
}

static void checkOBC_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered checkOBC_task.\r\n");
        int statusOBC = 0; // 0 for OK, 1 for not OK
        // TODO: ask the OBC subsystem for its status


        // if OBC is not OK then start a debug of OBC
        if (statusOBC == 1) {
            if (xTaskCreate(debugOBC_task, "debugOBC_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &debugOBC_TaskHandle) != pdPASS) {
                PRINTF("debugOBC_task creation failed!.\r\n");
                while (1);
            }
        }
        vTaskDelete(checkOBC_TaskHandle);
    }
}


/*!
 * @brief debugGNC_task function
 */
static void debugGNC_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered debugGNC_task.\r\n");
        // TODO: ask the GNC subsystem to debug itself


        /*
        // do a health check up again
        if (xTaskCreate(debugGNC_task, "debugGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 5, &debugGNC_TaskHandle) != pdPASS) {
            PRINTF("debugGNC_task creation failed!.\r\n");
        	while (1);
        }
        vTaskResume(debugGNC_TaskHandle);
        */

        vTaskDelete(debugGNC_TaskHandle);
    }
}

/*!
 * @brief debugCOM_task function
 */
static void debugCOM_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered debugGNC_task.\r\n");
        // TODO: ask the COM subsystem to debug itself


        vTaskDelete(debugCOM_TaskHandle);
    }
}

/*!
 * @brief debugEPS_task function
 */
static void debugEPS_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered debugEPS_task.\r\n");
        // TODO: ask the EPS subsystem to debug itself


        vTaskDelete(debugEPS_TaskHandle);
    }
}

/*!
 * @brief debugOBC_task function
 */
static void debugOBC_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered debugOBC_task.\r\n");
        // TODO: ask the OBC subsystem to debug itself


        vTaskDelete(debugOBC_TaskHandle);
    }
}

/*!
 * @brief debugSEN_task function
 */
static void debugSEN_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered debugSEN_task.\r\n");
        // TODO: ask the SEN subsystem to debug itself

        //call check sensor
        vTaskDelete(debugSEN_TaskHandle);
    }
}

/*!
 * @brief debugIMG_task function
 */
static void debugIMG_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered debugIMG_task.\r\n");
        // TODO: ask the IMG subsystem to debug itself


        vTaskDelete(debugIMG_TaskHandle);
    }
}
