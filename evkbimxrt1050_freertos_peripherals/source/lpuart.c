
/*
 * Need to add fsl_lpuart_freertos files into drivers folder
 * 	       add serial_port_internal.h into serial manager folder
 * cannot find fsl_lpuart_freertos.h -> modify include directories if necessary:
 *
 * 	Project -> Properties -> C/C++ Build -> Settings -> Includes -> Add 	 e.g.	 ../drivers/freertos
 *
 */


/* Freescale includes. */
#include <lpuart.h>
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"

#include "pin_mux.h"
#include "clock_config.h"

lpuart_rtos_handle_t handle3;
struct _lpuart_handle t_handle3;

lpuart_rtos_handle_t handle6;
struct _lpuart_handle t_handle6;

lpuart_rtos_handle_t handle8;
struct _lpuart_handle t_handle8;

SemaphoreHandle_t xMutex;

const char *to_send3               = "LPUART3 woke up!\r\n";
const char *to_send6               = "LPUART3 woke up!\r\n";
const char *to_send8               = "LPUART8 woke up!\r\n";

const char *send_ring_overrun     = "\r\nRing buffer overrun!\r\n";
const char *send_hardware_overrun = "\r\nHardware buffer overrun!\r\n";

uint8_t background_buffer3[32];
uint8_t recv_buffer3[4];

uint8_t background_buffer6[32];
uint8_t recv_buffer6[4];

uint8_t background_buffer8[32];
uint8_t recv_buffer8[4];


lpuart_rtos_config_t lpuart_config3 = {
    .baudrate    = 115200,
    .parity      = kLPUART_ParityDisabled,
    .stopbits    = kLPUART_OneStopBit,
    .buffer      = background_buffer3,
    .buffer_size = sizeof(background_buffer3),
	.base  		 = LPUART3,
};

lpuart_rtos_config_t lpuart_config6 = {
    .baudrate    = 115200,
    .parity      = kLPUART_ParityDisabled,
    .stopbits    = kLPUART_OneStopBit,
    .buffer      = background_buffer6,
    .buffer_size = sizeof(background_buffer6),
	.base  		 = LPUART6,
};

lpuart_rtos_config_t lpuart_config8 = {
    .baudrate    = 115200,
    .parity      = kLPUART_ParityDisabled,
    .stopbits    = kLPUART_OneStopBit,
    .buffer      = background_buffer8,
    .buffer_size = sizeof(background_buffer8),
	.base  		 = LPUART8,
};

//static?
void init_uart_tasks(){


	NVIC_SetPriority(LPUART3_IRQn, 5);
	NVIC_SetPriority(LPUART6_IRQn, 5);
	NVIC_SetPriority(LPUART8_IRQn, 5);
    xMutex = xSemaphoreCreateMutex();

	if (xTaskCreate(uart3_task, "Uart3_task", configMINIMAL_STACK_SIZE + 100, NULL, 5 , NULL) != pdPASS) //uart_task_PRIORITY
	{
		PRINTF("uart3_task creation failed!.\r\n");
		while (1)
			;
	}
	if (xTaskCreate(uart6_task, "Uart6_task", configMINIMAL_STACK_SIZE + 100, NULL, 5, NULL) != pdPASS)
	{
		PRINTF("uart6_task creation failed!.\r\n");
		while (1)
			;
	}
	if (xTaskCreate(uart8_task, "Uart8_task", configMINIMAL_STACK_SIZE + 100, NULL, 5, NULL) != pdPASS)
	{
		PRINTF("uart8_task creation failed!.\r\n");
		while (1)
			;
	}

}

void uart3_task(void *pvParameters)
{

    int error;
    size_t n = 0;

    lpuart_config3.srcclk = BOARD_DebugConsoleSrcFreq();//DEMO_LPUART_CLK_FREQ;
	LPUART_RTOS_Init(&handle3, &t_handle3, &lpuart_config3);

    xSemaphoreTake(xMutex, portMAX_DELAY);

	/* Send introduction message. */
	LPUART_RTOS_Send(&handle3, (uint8_t *)to_send3, strlen(to_send3));


	xSemaphoreGive(xMutex);

	while(1){

		error = LPUART_RTOS_Receive(&handle3, recv_buffer3, sizeof(recv_buffer3), &n);
		if (error == kStatus_LPUART_RxHardwareOverrun)
		{
			LPUART_RTOS_Send(&handle3, (uint8_t *)send_hardware_overrun, strlen(send_hardware_overrun));
		}
		if (error == kStatus_LPUART_RxRingBufferOverrun)
		{
			LPUART_RTOS_Send(&handle3, (uint8_t *)send_ring_overrun, strlen(send_ring_overrun));
		}
		if (n > 0)
		{
			LPUART_RTOS_Send(&handle3, (uint8_t *)recv_buffer3, n);
		}

	}

}

void uart6_task(void *pvParameters)
{

    int error;
    size_t n = 0;

    lpuart_config6.srcclk = BOARD_DebugConsoleSrcFreq();//DEMO_LPUART_CLK_FREQ;

	LPUART_RTOS_Init(&handle6, &t_handle6, &lpuart_config6);

    xSemaphoreTake(xMutex, portMAX_DELAY);

	/* Send introduction message. */
	LPUART_RTOS_Send(&handle6, (uint8_t *)to_send6, strlen(to_send6));

	xSemaphoreGive(xMutex);

	while(1){

		error = LPUART_RTOS_Receive(&handle6, recv_buffer6, sizeof(recv_buffer6), &n);
		if (error == kStatus_LPUART_RxHardwareOverrun)
		{
			LPUART_RTOS_Send(&handle6, (uint8_t *)send_hardware_overrun, strlen(send_hardware_overrun));
		}
		if (error == kStatus_LPUART_RxRingBufferOverrun)
		{
			LPUART_RTOS_Send(&handle6, (uint8_t *)send_ring_overrun, strlen(send_ring_overrun));
		}
		if (n > 0)
		{
			LPUART_RTOS_Send(&handle6, (uint8_t *)recv_buffer6, n);
		}

	}

}

void uart8_task(void *pvParameters)
{

	int error;
	    size_t n = 0;
	    lpuart_config8.srcclk = BOARD_DebugConsoleSrcFreq();//DEMO_LPUART_CLK_FREQ;

		LPUART_RTOS_Init(&handle8, &t_handle8, &lpuart_config8);

	    xSemaphoreTake(xMutex, portMAX_DELAY);

		/* Send introduction message. */
		LPUART_RTOS_Send(&handle8, (uint8_t *)to_send8, strlen(to_send8));


		xSemaphoreGive(xMutex);

		while(1){

			error = LPUART_RTOS_Receive(&handle8, recv_buffer8, sizeof(recv_buffer8), &n);
			if (error == kStatus_LPUART_RxHardwareOverrun)
			{
				LPUART_RTOS_Send(&handle8, (uint8_t *)send_hardware_overrun, strlen(send_hardware_overrun));
			}
			if (error == kStatus_LPUART_RxRingBufferOverrun)
			{
				LPUART_RTOS_Send(&handle8, (uint8_t *)send_ring_overrun, strlen(send_ring_overrun));
			}
			if (n > 0)
			{
				LPUART_RTOS_Send(&handle8, (uint8_t *)recv_buffer8, n);
			}

		}

}


