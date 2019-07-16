/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
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
static void debugGNC_task(void *pvParameters);
static void debugCOM_task(void *pvParameters);
static void debugEPS_task(void *pvParameters);
static void updateGNC_task(void *pvParameters);
static void updateCOM_task(void *pvParameters);
static void updateEPS_task(void *pvParameters);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
double voltage = 0; // the voltage value that we get from the EPS
char mode = 'I'; // I: Idle, S: Safe, N: Normal
TaskHandle_t determineMode_TaskHandler;
TaskHandle_t idleMode_TaskHandler;
TaskHandle_t safeMode_TaskHandler;
TaskHandle_t normalMode_TaskHandler;
TaskHandle_t updateGNC_TaskHandle;
TaskHandle_t updateCOM_TaskHandle;
TaskHandle_t updateEPS_TaskHandle;
TaskHandle_t debugGNC_TaskHandle;
TaskHandle_t debugCOM_TaskHandle;
TaskHandle_t debugEPS_TaskHandle;


/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */

int main(void)
{
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    // Creating a task to determine mode of the system
    if (xTaskCreate(determineMode_task, "determineMode_task", configMINIMAL_STACK_SIZE + 166, NULL, 2, &determineMode_TaskHandler) != pdPASS) {
        PRINTF("determineMode_task creation failed!.\r\n");
        while (1);
    }
    vTaskStartScheduler();
    // The system should never reach here.
    for (;;);
}

/*******************************************************************************
 * Application functions
 ******************************************************************************/
/*!
 * @brief determineMode_task function
 *
 *  this task is periodic and happens every 50 ms.
 */
static void determineMode_task(void *pvParameters) {
    const TickType_t xDelay50ms = pdMS_TO_TICKS( 50 );
    TickType_t xLastWakeTime = xTaskGetTickCount();
    for (;;) {
        PRINTF("entered determineMode_task.\r\n");
        // TODO: Create a task to get the voltage from EPS system through I2C Communication


        // Idle Mode:
        if (voltage <= 3) {
            if (xTaskCreate(idleMode_task, "idleMode_task", configMINIMAL_STACK_SIZE + 166, NULL, 2, &idleMode_TaskHandler) != pdPASS) {
                PRINTF("idleMode_task creation failed!.\r\n");
                while (1);
            }
        // Safe Mode:
        } else if (volatge <= 5) {
            if (xTaskCreate(safeMode_task, "safeMode_task", configMINIMAL_STACK_SIZE + 166, NULL, 2, &safeMode_TaskHandler) != pdPASS) {
                PRINTF("safeMode_task creation failed!.\r\n");
                while (1);
            }
        // Normal Mode:
        } else {
            if (xTaskCreate(normalMode_task, "normalMode_task", configMINIMAL_STACK_SIZE + 166, NULL, 2, &normalMode_TaskHandler) != pdPASS) {
                PRINTF("normalMode_task creation failed!.\r\n");
                while (1);
            }
        }
        vTaskDelayUntil(&xLastWakeTime, xDelay50ms);
    }
}

/*!
 * @brief idleMode_task function
 */
static void idleMode_task(void *pvParameters) {
    for (;;)
    {
        PRINTF("entered idleMode_task.\r\n");
        mode = 'I';
        // updating each subsystem
        if (xTaskCreate(updateGNC_task, "updateGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &updateGNC_TaskHandle) != pdPASS) {
            PRINTF("idlemode_updateGNC_task creation failed!.\r\n");
            while (1);
        }
        if (xTaskCreate(updateCOM_task, "updateCOM_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &updateCOM_TaskHandle) != pdPASS) {
            PRINTF("idlemode_updateCOM_task creation failed!.\r\n");
            while (1);
        }
        if (xTaskCreate(updateEPS_task, "updateEPS_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &updateEPS_TaskHandle) != pdPASS) {
            PRINTF("idlemode_updateEPS_task creation failed!.\r\n");
            while (1);
        }
        vTaskResume(updateGNC_TaskHandle);
        vTaskResume(updateCOM_TaskHandle);
        vTaskResume(updateEPS_TaskHandle);
        vTaskSuspend(idleMode_TaskHandle);
    }
}

/*!
 * @brief safeMode_task function
 */
static void safeMode_task(void *pvParameters) {
    for (;;)
    {
        PRINTF("entered safeMode_task.\r\n");
        mode = 'S';
        // updating each subsystem
        if (xTaskCreate(updateGNC_task, "updateGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &updateGNC_TaskHandle) != pdPASS) {
            PRINTF("safemode_updateGNC_task creation failed!.\r\n");
            while (1);
        }
        if (xTaskCreate(updateCOM_task, "updateCOM_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &updateCOM_TaskHandle) != pdPASS) {
            PRINTF("safemode_updateCOM_task creation failed!.\r\n");
            while (1);
        }
        if (xTaskCreate(updateEPS_task, "updateEPS_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &updateEPS_TaskHandle) != pdPASS) {
            PRINTF("safemode_updateEPS_task creation failed!.\r\n");
            while (1);
        }
        vTaskResume(updateGNC_TaskHandle);
        vTaskResume(updateCOM_TaskHandle);
        vTaskResume(updateEPS_TaskHandle);
        vTaskSuspend(safeMode_TaskHandle);
    }
}

/*!
 * @brief normalMode_task function
 */
static void normalMode_task(void *pvParameters) {
    for (;;)
    {
        PRINTF("entered normalMode_task.\r\n");
        mode = 'N';
        // updating each subsystem
        if (xTaskCreate(updateGNC_task, "updateGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &updateGNC_TaskHandle) != pdPASS) {
            PRINTF("normalmode_updateGNC_task creation failed!.\r\n");
            while (1);
        }
        if (xTaskCreate(updateCOM_task, "updateCOM_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &updateCOM_TaskHandle) != pdPASS) {
            PRINTF("normalmode_updateCOM_task creation failed!.\r\n");
            while (1);
        }
        if (xTaskCreate(updateEPS_task, "updateEPS_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &updateEPS_TaskHandle) != pdPASS) {
            PRINTF("normalmode_updateEPS_task creation failed!.\r\n");
            while (1);
        }

        // check if each subsystem is working fine
        if (xTaskCreate(checkGNC_task, "checkGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &checkGNC_TaskHandle) != pdPASS) {
            PRINTF("checkGNC_task creation failed!.\r\n");
            while (1);
        }
        if (xTaskCreate(checkCOM_task, "checkCOM_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &checkCOM_TaskHandle) != pdPASS) {
            PRINTF("checkCOM_task creation failed!.\r\n");
            while (1);
        }
        if (xTaskCreate(checkEPS_task, "checkEPS_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &checkEPS_TaskHandle) != pdPASS) {
            PRINTF("checkEPS_task creation failed!.\r\n");
            while (1);
        }

        // TODO: after all the peripherals are checked, do the main stuff

        vTaskResume(updateGNC_TaskHandle);
        vTaskResume(updateCOM_TaskHandle);
        vTaskResume(updateEPS_TaskHandle);
        vTaskResume(checkGNC_TaskHandle);
        vTaskResume(checkCOM_TaskHandle);
        vTaskResume(checkEPS_TaskHandle);
        vTaskSuspend(normalMode_TaskHandle);
    }
}

/*!
 * @brief checkGNC_task function
 */
static void checkGNC_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered checkGNC_task.\r\n");
        int statusGNC; // 0 for OK, 1 for not OK
        // TODO: ask the GNC subsystem for its status


        // if GNC is not OK then start a debug of GNC with a greater priority
        if (statusGNC == 1) {
            if (xTaskCreate(debugGNC_task, "debugGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 2, &debugGNC_TaskHandle) != pdPASS) {
                PRINTF("debugGNC_task creation failed!.\r\n");
                while (1);
            }
        }
        vTaskResume(debugGNC_TaskHandle);
        vTaskSuspend(checkGNC_TaskHandle);
    }
}

/*!
 * @brief checkGNC_task function
 */
static void checkCOM_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered checkCOM_task.\r\n");
        int statusCOM; // 0 for OK, 1 for not OK
        // TODO: ask the GNC subsystem for its status


        // if GNC is not OK then start a debug of GNC with a greater priority
        if (statusCOM == 1) {
            if (xTaskCreate(debugCOM_task, "debugCOM_task", configMINIMAL_STACK_SIZE + 166, NULL, 2, &debugCOM_TaskHandle) != pdPASS) {
                PRINTF("debugCOM_task creation failed!.\r\n");
                while (1);
            }
        }
        vTaskResume(debugCOM_TaskHandle);
        vTaskSuspend(checkCOM_TaskHandle);
    }
}

/*!
 * @brief checkGNC_task function
 */
static void checkEPS_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered checkEPS_task.\r\n");
        int statusEPS; // 0 for OK, 1 for not OK
        // TODO: ask the GNC subsystem for its status


        // if GNC is not OK then start a debug of GNC with a greater priority
        if (statusEPS == 1) {
            if (xTaskCreate(debugEPS_task, "debugEPS_task", configMINIMAL_STACK_SIZE + 166, NULL, 2, &debugEPS_TaskHandle) != pdPASS) {
                PRINTF("debugEPS_task creation failed!.\r\n");
                while (1);
            }
        }
        vTaskResume(debugEPS_TaskHandle);
        vTaskSuspend(checkEPS_TaskHandle);
    }
}

/*!
 * @brief debugGNC_task function
 */
static void debugGNC_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered debugGNC_task.\r\n");
        // TODO: ask the GNC subsystem to debug itself


        vTaskSuspend(debugGNC_TaskHandle);
    }
}

/*!
 * @brief debugCOM_task function
 */
static void debugCOM_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered debugGNC_task.\r\n");
        // TODO: ask the COM subsystem to debug itself


        vTaskSuspend(debugCOM_TaskHandle);
    }
}

/*!
 * @brief debugEPS_task function
 */
static void debugEPS_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered debugEPS_task.\r\n");
        // TODO: ask the EPS subsystem to debug itself


        vTaskSuspend(debugEPS_TaskHandle);
    }
}

/*!
 * @brief updateGNC_task function
 */
static void updateGNC_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered updateGNC_task.\r\n");
        if (mode == 'I') {
            // TODO: Tell GNC to go on Idle mode

        } else if (mode == "S") {
            // TODO: Tell GNC to go on Safe mode

        } else if (mode == "N") {
            // TODO: Tell GNC to go on Normal mode

        }
        vTaskSuspend(updateGNC_TaskHandle);
    }
}

/*!
 * @brief updateCOM_task function
 */
static void updateCOM_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered updateCOM_task.\r\n");
        if (mode == 'I') {
            // TODO: Tell COM to go on Idle mode

        } else if (mode == "S") {
            // TODO: Tell COM to go on Safe mode

        } else if (mode == "N") {
            // TODO: Tell COM to go on Normal mode

        }
        vTaskSuspend(updateCOM_TaskHandle);
    }
}

/*!
 * @brief updateEPS_task function
 */
static void updateEPS_task(void *pvParameters) {
    for (;;) {
        PRINTF("entered updateEPS_task.\r\n");
        if (mode == 'I') {
            // TODO: Tell EPS to go on Idle mode

        } else if (mode == "S") {
            // TODO: Tell EPS to go on Safe mode

        } else if (mode == "N") {
            // TODO: Tell EPS to go on Normal mode

        }
        vTaskSuspend(updateEPS_TaskHandle);
    }
}
