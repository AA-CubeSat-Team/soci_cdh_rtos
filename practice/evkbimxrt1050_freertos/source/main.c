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

static void updateTempVoltage_task(void *pvParameters);
static void updateGNC_task(void *pvParameters);
static void updateCOM_task(void *pvParameters);
static void updateEPS_task(void *pvParameters);

TaskHandle_t TaskHandle_1;
TaskHandle_t TaskHandle_2;
TaskHandle_t TaskHandle_3;
TaskHandle_t TaskHandle_4;

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

    if (xTaskCreate(updateTempVoltage_task,
            "updateTempVoltage_task",
            configMINIMAL_STACK_SIZE + 166,
            NULL,
            2,
            &TaskHandle_1) != pdPASS)
    {
        PRINTF("updateTempVoltage_task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(updateGNC_task, "updateGNC_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &TaskHandle_2) !=
        pdPASS)
    {
        PRINTF("updateGNC_task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(updateCOM_task, "updateCOM_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &TaskHandle_3) !=
        pdPASS)
    {
        PRINTF("updateCOM_task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(updateEPS_task, "updateEPS_task", configMINIMAL_STACK_SIZE + 166, NULL, 1, &TaskHandle_4) !=
        pdPASS)
    {
        PRINTF("updateEPS_task creation failed!.\r\n");
        while (1)
            ;
    }
    vTaskStartScheduler();
    for (;;)
        ;
}

/*******************************************************************************
 * Application functions
 ******************************************************************************/
/*!
 * @brief updateTempVoltage_task function
 */
static void updateTempVoltage_task(void *pvParameters) {
    const TickType_t xDelay50ms = pdMS_TO_TICKS( 50 );
    TickType_t xLastWakeTime = xTaskGetTickCount();
    for (;;)
    {
        PRINTF("entered updateTempVoltage_task.\r\n");
        //vTaskSuspend(NULL);
        vTaskResume(TaskHandle_2);
        vTaskResume(TaskHandle_3);
        vTaskResume(TaskHandle_4);
        vTaskDelayUntil(&xLastWakeTime, xDelay50ms);
    }
}

/*!
 * @brief updateGNC_task function
 */
static void updateGNC_task(void *pvParameters) {
    for (;;)
    {
        PRINTF("entered updateGNC_task.\r\n");
        vTaskSuspend(TaskHandle_2);
    }
}

/*!
 * @brief updateCOM_task function
 */
static void updateCOM_task(void *pvParameters) {
    for (;;)
    {
        PRINTF("entered updateCOM_task.\r\n");
        vTaskSuspend(TaskHandle_3);
    }
}

/*!
 * @brief updateEPS_task function
 */
static void updateEPS_task(void *pvParameters) {
    for (;;)
    {
        PRINTF("entered updateEPS_task.\r\n");
        vTaskSuspend(TaskHandle_4);
    }
}
