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
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "peripherals.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_LPUART          LPUART1
#define DEMO_LPUART_CLK_FREQ BOARD_DebugConsoleSrcFreq()
#define DEMO_LPUART_IRQn     LPUART1_IRQn
/* Task priorities. */
#define uart_task_PRIORITY (configMAX_PRIORITIES - 1)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void uart_task(void *pvParameters);

/*******************************************************************************
 * Code
 ******************************************************************************/
char *u1               = "hello world uart-1\r\n";
char *u3               = "hello world uart-3!\r\n";
char *u4               = "hello world uart-4!\r\n";
char *send_ring_overrun     = "\r\nRing buffer overrun!\r\n";
char *send_hardware_overrun = "\r\nHardware buffer overrun!\r\n";
uint8_t background_buffer[32];
uint8_t recv_u1[8];
uint8_t recv_u3[8];
uint8_t recv_u4[8];

lpuart_rtos_handle_t handle;
struct _lpuart_handle t_handle;

lpuart_rtos_config_t lpuart_config = {
    .baudrate    = 115200,
    .parity      = kLPUART_ParityDisabled,
    .stopbits    = kLPUART_OneStopBit,
    .buffer      = background_buffer,
    .buffer_size = sizeof(background_buffer),
};

/*!
 * @brief Application entry point.
 */
int main(void)
{
    /* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    //NVIC_SetPriority(LPUART1_IRQn, 5);

	if (kStatus_Success != LPUART_RTOS_Send(&LPUART1_rtos_handle, (uint8_t *)u1, strlen(u1)))
	{
		vTaskSuspend(NULL);
	}

	if (kStatus_Success != LPUART_RTOS_Send(&LPUART3_rtos_handle, (uint8_t *)u3, strlen(u3)))
	{
		vTaskSuspend(NULL);
	}

	if (kStatus_Success != LPUART_RTOS_Send(&LPUART4_rtos_handle, (uint8_t *)u4, strlen(u4)))
	{
		vTaskSuspend(NULL);
	}

    if (xTaskCreate(uart_task, "Uart_task", configMINIMAL_STACK_SIZE + 100, NULL, uart_task_PRIORITY, NULL) != pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    vTaskStartScheduler();
    for (;;)
        ;
}

/*!
 * @brief Task responsible for loopback.
 */
static void uart_task(void *pvParameters)
{
    int error;
    size_t n1;
    size_t n3;
    size_t n4;
//    LPUART1_rtos_handle
	/* Send introduction message. */
    while (1) {
    	n1 = 0;
    	n3 = 0;
    	n4 = 0;

    	error = LPUART_RTOS_Receive(&LPUART1_rtos_handle, recv_u1, sizeof(recv_u1), &n1);
    	if (kStatus_Success == error) {
			if (n1 > 0) {
						/* send back the received data */
				if (kStatus_Success != LPUART_RTOS_Send(&LPUART1_rtos_handle, recv_u1, n1)) {
					vTaskSuspend(NULL);
				}
			}
    	}


		error = LPUART_RTOS_Receive(&LPUART3_rtos_handle, recv_u3, sizeof(recv_u3), &n3);
    	if (kStatus_Success == error) {
			if (n3 > 0) {
						/* send back the received data */
				if (kStatus_Success != LPUART_RTOS_Send(&LPUART3_rtos_handle, recv_u3, n4)) {
					vTaskSuspend(NULL);
				}
			}
    	}

		error = LPUART_RTOS_Receive(&LPUART4_rtos_handle, recv_u4, sizeof(recv_u4), &n4);
    	if (kStatus_Success == error) {
			if (n4 > 0) {
						/* send back the received data */
				if (kStatus_Success != LPUART_RTOS_Send(&LPUART4_rtos_handle, recv_u4, n4)) {
					vTaskSuspend(NULL);
				}
			}
    	}

    	vTaskDelay(100);

    }


//    lpuart_config.srcclk = DEMO_LPUART_CLK_FREQ;
//    lpuart_config.base   = DEMO_LPUART;
//
//    if (kStatus_Success != LPUART_RTOS_Init(&handle, &t_handle, &lpuart_config))
//    {
//        vTaskSuspend(NULL);
//    }
//
//    /* Send introduction message. */
//    if (kStatus_Success != LPUART_RTOS_Send(&handle, (uint8_t *)to_send, strlen(to_send)))
//    {
//        vTaskSuspend(NULL);
//    }
//
//    /* Receive user input and send it back to terminal. */
//    do
//    {
//        error = LPUART_RTOS_Receive(&handle, recv_buffer, sizeof(recv_buffer), &n);
//        if (error == kStatus_LPUART_RxHardwareOverrun)
//        {
//            /* Notify about hardware buffer overrun */
//            if (kStatus_Success !=
//                LPUART_RTOS_Send(&handle, (uint8_t *)send_hardware_overrun, strlen(send_hardware_overrun)))
//            {
//                vTaskSuspend(NULL);
//            }
//        }
//        if (error == kStatus_LPUART_RxRingBufferOverrun)
//        {
//            /* Notify about ring buffer overrun */
//            if (kStatus_Success != LPUART_RTOS_Send(&handle, (uint8_t *)send_ring_overrun, strlen(send_ring_overrun)))
//            {
//                vTaskSuspend(NULL);
//            }
//        }
//        if (n > 0)
//        {
//            /* send back the received data */
//            if (kStatus_Success != LPUART_RTOS_Send(&handle, recv_buffer, n))
//            {
//                vTaskSuspend(NULL);
//            }
//        }
//    } while (kStatus_Success == error);

//    LPUART_RTOS_Deinit(&handle);
    vTaskSuspend(NULL);
}
