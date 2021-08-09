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
#include "semc_sdram.h"
#include "idle_task.h"
#include "imag_task.h"
#include "gnc_task.h"
#include "com_task.h"

#include "eps_wrap.h"
#include "act_wrap.h"
#include "sen_wrap.h"
#include "imag_wrap.h"
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

// Queue handlers declared in queue folder
extern QueueHandle_t QueueHandler_IndexSDRAM;
extern QueueHandle_t QueueHandler_ImageInfo;
extern QueueHandle_t QueueHandler_CommandIMG; 

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

uint8_t sdram_writeBuffer_copy[SEMC_EXAMPLE_DATALEN];
uint8_t sdram_readBuffer_copy[SEMC_EXAMPLE_DATALEN];
uint8_t *sdram_copy  = (uint8_t *)EXAMPLE_SEMC_START_ADDRESS; //SD ram



int main(void)
{
    /* System Power Buses ON: Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    BOARD_InitPeripherals();

    if (BOARD_InitSEMC() != kStatus_Success)
	{
		PRINTF("\r\n SEMC SDRAM Init Failed\r\n");
	}
    PRINTF("write \"hello world\" to sdram \r\n");
    char message[] = "hello world";
    PRINTF("Expected:\r\n");
    for (uint8_t i = 0; i < strlen(message); i++) {
    	sdram_writeBuffer_copy[i] = message[i];
    	PRINTF("%c", sdram_writeBuffer_copy[i]);
    }
    //TODO: maybe we need to reset the whole ram when powering up
//    SEMC_SDRAM_Write(100, strlen(message), 1); //write chars of the size of message starting at 10th byte
//    for (int i = 0; i < 10000000; i++) {
//    	PRINTF("");
//    }
    PRINTF("\r\nREAD:\r\n");
    SEMC_SDRAM_Read(102, strlen(message), 1); //read the four uint8_t into readbuffer
    for (uint8_t i = 0; i< strlen(message); i++) {
		PRINTF("%c", sdram_readBuffer_copy[i]);
	}

	// Queue Folder
	QueueHandle_t QueueHandler_IndexSDRAM = xQueueCreate(1, sizeof(uint8_t)); 	// Tracks available index in SDRAM for IMG & GNC
	QueueHandle_t QueueHandler_ImageInfo = xQueueCreate(2, sizeof(uint8_t)); 	// Holds size & location of images written to SDRAM by IMG for COM/MCC
	QueueHandle_t QueueHandler_CommandIMG = xQueueCreate(10, sizeof(uint8_t)); 	// Holds up to 5 command/param pairs for systems to command IMG

//    /* 32Bit data read and write. */
//	SEMC_SDRAMReadWrite32Bit();
//	/* 16Bit data read and write. */
//	SEMC_SDRAMReadWrite16Bit();
//	/* 8Bit data read and write. */
//	SEMC_SDRAMReadWrite8Bit();

    if (xTaskCreate(idle_task, "idle_task", configMINIMAL_STACK_SIZE + 100, NULL, max_PRIORITY, &TaskHandler_idle) != //initialize priority to the highest +1
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





