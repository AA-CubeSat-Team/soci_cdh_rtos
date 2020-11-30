
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

#include "pin_mux.h"
#include "clock_config.h"

lpuart_rtos_handle_t handle3;
struct _lpuart_handle t_handle3;

#define QUEUE_LEN 100

static SemaphoreHandle_t xMutex;
static SemaphoreHandle_t count_semaphore_rx;
static SemaphoreHandle_t count_semaphore_tx;

static QueueHandle_t uartRxQueue;
static QueueHandle_t uartTxQueue;

const char *to_send3               = "LPUART3 woke up!\r\n";

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

void init_tasks(){


//	NVIC_SetPriority(LPUART3_IRQn, 5);
//	NVIC_SetPriority(LPUART6_IRQn, 5);
//	NVIC_SetPriority(LPUART8_IRQn, 5);
	uartRxQueue = xQueueCreate(QUEUE_LEN, sizeof(char));
	if(uartRxQueue == NULL)
	{
		PRINTF("Queue rx creation failed!.\r\n");
		while (1)
			;
	}

	uartTxQueue = xQueueCreate(QUEUE_LEN, sizeof(char));
	if(uartTxQueue == NULL)
	{
		PRINTF("Queue tx creation failed!.\r\n");
		while (1)
			;
	}

    xMutex = xSemaphoreCreateMutex();
    if(xMutex == NULL){
    	PRINTF("mutex creation failed!.\r\n");
		while (1)
			;
    }

    count_semaphore_rx = xSemaphoreCreateCounting(20,0); //max, initial
    if(count_semaphore_rx == NULL){
		PRINTF("semaphore creation failed!.\r\n");
		while (1)
			;
	}

    count_semaphore_tx = xSemaphoreCreateCounting(20,0); //max, initial
	if(count_semaphore_tx == NULL){
		PRINTF("semaphore creation failed!.\r\n");
		while (1)
			;
	}

	if (xTaskCreate(uart3_rx_task, "Uart3_Rx_task", configMINIMAL_STACK_SIZE + 100, NULL, 4 , NULL) != pdPASS)
	{
		PRINTF("uart3_rx_task creation failed!.\r\n");
		while (1)
			;
	}

	if (xTaskCreate(uart3_tx_task, "Uart3_Tx_task", configMINIMAL_STACK_SIZE + 100, NULL, 5 , NULL) != pdPASS)
	{
		PRINTF("uart3_tx_task creation failed!.\r\n");
		while (1)
			;
	}

	if (xTaskCreate(process_task, "Process_task", configMINIMAL_STACK_SIZE + 100, NULL, 5 , NULL) != pdPASS)
	{
		PRINTF("process_task creation failed!.\r\n");
		while (1)
			;
	}
}

void uart3_rx_task(void *pvParameters)
{

    int error;
    size_t n = 0;
	const TickType_t xBlockTime = pdMS_TO_TICKS(200);

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
			PRINTF("kStatus_LPUART_RxHardwareOverrun!.\r\n");
		}
		if (error == kStatus_LPUART_RxRingBufferOverrun)
		{
			PRINTF("kStatus_LPUART_RxRingBufferOverrun!.\r\n");
		}
		if (n > 0)
		{
			//put in queue
			for(size_t i=0; i<n; i++){
				if((xQueueSendToBack(uartRxQueue, recv_buffer3, xBlockTime)) == pdPASS ){
					xSemaphoreGive(count_semaphore_rx);
				}
			}

		}

	}

}

void uart3_tx_task(void *pvParameters)
{

    int error;
    size_t n = 0;
	const TickType_t xBlockTime = pdMS_TO_TICKS(200);
	char in;

	while(1){
		xSemaphoreTake(count_semaphore_tx, xBlockTime);
		xQueueReceive(uartTxQueue, &in, xBlockTime);
		LPUART_RTOS_Send(&handle3, &in, 1);
	}

}

void process_task(void *pvParameters)
{

    int error;
    size_t n = 0;
	const TickType_t xBlockTime = pdMS_TO_TICKS(200);
	char in;

	while(1){
		xSemaphoreTake(count_semaphore_rx, xBlockTime);
		xQueueReceive(uartRxQueue, &in, xBlockTime);
		//do the processing

		//
		if((xQueueSendToBack(uartTxQueue, &in, xBlockTime)) == pdPASS ){
			xSemaphoreGive(count_semaphore_tx);
		}

	}

}
