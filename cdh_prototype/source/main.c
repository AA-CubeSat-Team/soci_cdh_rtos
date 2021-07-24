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
#include <stdbool.h>

#include "semc_sdram.h"
#include "power_mode_switch.h"

/*
 powermode includes
#include "lpm.h"
#include "power_mode_switch.h"
*/

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
#define idle_task_PRIORITY	 			3
#define imag_task_PRIORITY 				3
#define com_task_PRIORITY				3
#define gnc_task_PRIORITY 				3
#define max_PRIORITY 	   				3 //(configMAX_PRIORITIES - 1)


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

extern SemaphoreHandle_t s_wakeupSig;

int main(void)
{
    /* System Power Buses ON: Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    BOARD_InitPeripherals();

    /* When wakeup from suspend, peripheral's doze & stop requests won't be cleared, need to clear them manually */
   IOMUXC_GPR->GPR4  = 0x00000000;
   IOMUXC_GPR->GPR7  = 0x00000000;
   IOMUXC_GPR->GPR8  = 0x00000000;
   IOMUXC_GPR->GPR12 = 0x00000000;

    /*powermode init*/
    if (true != LPM_Init(s_curRunMode))
	{
		PRINTF("LPM Init Failed!\r\n");
	}
    s_wakeupSig = xSemaphoreCreateBinary();
	/* Make current resource count 0 for signal purpose */
	if (xSemaphoreTake(s_wakeupSig, 0) == pdTRUE)
	{
		assert(0);
	}
	/****/

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





