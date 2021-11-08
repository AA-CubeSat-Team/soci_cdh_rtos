/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "fsl_common.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_lpuart.h"
#include "specific.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "queue.h"
#include "timers.h"
#include <stdbool.h>
#include "idle_task.h"
#include "imag_task.h"
#include "gnc_task.h"
#include "com_task.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define CPU_NAME "iMXRT1021"

/* Task priorities. */
#define idle_task_PRIORITY	 			1
#define imag_task_PRIORITY 				2
#define com_task_PRIORITY				3
#define gnc_task_PRIORITY 				3
#define max_PRIORITY 	   				(configMAX_PRIORITIES - 1)


/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */

//mTask handlers declared in each task files in tasks folder.
extern TaskHandle_t TaskHandler_idle;
extern TaskHandle_t TaskHandler_com;
extern TaskHandle_t TaskHandler_img;

/*!
 * @brief main demo function.
 */
int main(void)
{

	/* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    BOARD_InitPeripherals();

    if (xTaskCreate(idle_task, "idle_task", configMINIMAL_STACK_SIZE + 100, NULL, max_PRIORITY , &TaskHandler_idle) != //initialize priority to the highest +1
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(imag_task, "imag_task", configMINIMAL_STACK_SIZE + 100, NULL, imag_task_PRIORITY, &TaskHandler_img) !=
		pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1)
			;
	}
    if (xTaskCreate(com_task, "com_task", configMINIMAL_STACK_SIZE + 100, NULL, com_task_PRIORITY, &TaskHandler_com) !=
		pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1)
			;
	}
    if (xTaskCreate(gnc_task, "gnc_task", configMINIMAL_STACK_SIZE + 100, NULL, gnc_task_PRIORITY, NULL) !=
		pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1)
			;
	}
    vTaskStartScheduler();
    for (;;)
        ;
}
