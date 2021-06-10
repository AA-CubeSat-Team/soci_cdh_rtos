/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


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
#include "peripherals.h"
#include "lpm.h"

#include "idle_task.h"
#include "imag_task.h"
#include "gnc_task.h"
#include "com_task.h"

#include "eps_wrap.h"
#include "act_wrap.h"
#include "sen_wrap.h"
#include "img_wrap.h"
#include "com_wrap.h"

// TODO: add includes for uart, spi, i2c, sdram, etc.

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Task priorities. */
#define idle_task_PRIORITY	 			0
#define imag_task_PRIORITY 				1
#define com_task_PRIORITY				2
#define gnc_task_PRIORITY 				3
#define max_PRIORITY 	   				(configMAX_PRIORITIES - 1)


/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */

// Task handlers declared in each task files in tasks folder.
extern TaskHandle_t TaskHandler_idle;
extern TaskHandle_t TaskHandler_com;
extern TaskHandle_t TaskHandler_img;

/* Reset the priority of the task */
void resetPriority(TaskHandle_t handler) {
	vTaskPrioritySet(handler, 0);
}

/* Check if the task is suspended or not, if not, suspend it. */
void suspendTask (TaskHandle_t handler) {
	if (eTaskGetState(handler) != eSuspended) {
		vTaskSuspend(handler);
	}
}

/* Check if the task is suspended or not, if so, resume it. */
void resumeTask (TaskHandle_t handler) {
	if (eTaskGetState(handler) == eSuspended) {
		//TODO: check if we actually need to check the current state of the tasks
		//Also, might need to add other edge cases (ex. eRunning, eReady, eBlocked...)
		vTaskResume(handler);
	}
}

int main(void)
{
    /* System Power Buses ON: Init board hardware. */
`    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    BOARD_InitPeripherals();

    // Not sure why is this deleted
    CLOCK_SetMux(kCLOCK_Lpi2cMux, BOARD_ACCEL_I2C_CLOCK_SOURCE_SELECT);
    CLOCK_SetDiv(kCLOCK_Lpi2cDiv, BOARD_ACCEL_I2C_CLOCK_SOURCE_DIVIDER);
    /* Set IRQ priority for freertos_lpi2c */
    NVIC_SetPriority(LPI2C1_IRQn, 3);

//    if (xTaskCreate(idle_task, "idle_task", configMINIMAL_STACK_SIZE + 100, NULL, max_PRIORITY, &TaskHandler_idle) != //initialize priority to the highest +1
//        pdPASS)
//    {
//        PRINTF("Task creation failed!.\r\n");
//        while (1)
//            ;
//    }
//    if (xTaskCreate(imag_task, "imag_task", configMINIMAL_STACK_SIZE + 100, NULL, imag_task_PRIORITY, &TaskHandler_img) !=
//		pdPASS)
//	{
//		PRINTF("Task creation failed!.\r\n");
//		while (1)
//			;
//	}
//    if (xTaskCreate(com_task, "com_task", configMINIMAL_STACK_SIZE + 100, NULL, com_task_PRIORITY, &TaskHandler_com) !=
//		pdPASS)
//	{
//		PRINTF("Task creation failed!.\r\n");
//		while (1)
//			;
//	}
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





