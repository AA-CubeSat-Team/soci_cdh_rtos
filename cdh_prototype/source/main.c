/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


/* FreeRTOS kernel includes. */
#include <com_task.h>
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

#include "idle_task.h"
#include "imag_task.h"
#include "sens_task.h"
#include "eps_wrap.h"


// TODO: add includes for uart, spi, i2c, sdram, etc.

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Task priorities. */
#define idle_task_PRIORITY 0
#define imag_task_PRIORITY 1
#define com_task_PRIORITY 2
#define sens_task_PRIORITY 3


/*******************************************************************************
 * Flags
 ******************************************************************************/
//flags for checking if it's turned on or not
bool g_imgActive;
bool g_comActive;
bool g_sunSensActive;
bool g_rwaSensActive;
bool g_magSensActive;
bool g_mtqSensActive;
bool g_phdSensActive;
//flags for checking if they're healthy
bool g_epsHealthy;
bool g_obcHealthy;
bool g_comHealthy;
bool g_senHealthy;
bool g_gncHealthy;
bool g_mtqHealthy;
bool g_rwaHealthy;
bool g_imgHealthy;

int g_operatingMode;



//struct sens_meas{
//	// TODO: to be filled in
//};
//
//struct telecommands{
//
//};
//
//struct act_meas{
//
//};
//
//struct fsw_out{
//	//rwa_cmd_rpm
//};
//
//struct fsw_telem{
//
//};

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */
bool obc_healthcheck(){
	PRINTF("checking peripherals of obc");
	return true;
}
void obc_reset(){
	PRINTF("Hard resetting obc");
}

int main(void)
{
    /* System Power Buses ON: Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    BOARD_InitPeripherals();

    if (xTaskCreate(idle_task, "idle_task", configMINIMAL_STACK_SIZE + 100, NULL, idle_task_PRIORITY, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(imag_task, "imag_task", configMINIMAL_STACK_SIZE + 100, NULL, imag_task_PRIORITY, NULL) !=
		pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1)
			;
	}
    if (xTaskCreate(com_task, "com_task", configMINIMAL_STACK_SIZE + 100, NULL, com_task_PRIORITY, NULL) !=
		pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1)
			;
	}
    if (xTaskCreate(sens_task, "sens_task", configMINIMAL_STACK_SIZE + 100, NULL, sens_task_PRIORITY, NULL) !=
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

