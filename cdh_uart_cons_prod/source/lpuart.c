
/*
 * Need to add fsl_lpuart_freertos files into drivers folder
 * 	       add serial_port_internal.h into serial manager folder
 * cannot find fsl_lpuart_freertos.h -> modify include directories if necessary:
 *
 * 	Project -> Properties -> C/C++ Build -> Settings -> Includes -> Add 	 e.g.	 ../drivers/freertos
 *
 */


/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include <lpuart.h>
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"

//#include "fsl_common.h" //probably redundant

#include "pin_mux.h"
#include "clock_config.h"

#define uart_task_PRIORITY (configMAX_PRIORITIES - 1)

#define QUEUE_LEN 100

static SemaphoreHandle_t xMutex;
static SemaphoreHandle_t count_semaphore_rx;
static SemaphoreHandle_t count_semaphore_tx;

static QueueHandle_t uartRxQueue;
static QueueHandle_t uartTxQueue;

const char *to_send3               = "LPUART3 woke up!\r\n";
const char *to_send3_2               = "TX task inited!\r\n";
const char *send_ring_overrun     = "\r\nRing buffer overrun!\r\n";
const char *send_hardware_overrun = "\r\nHardware buffer overrun!\r\n";

uint8_t background_buffer3[32];
uint8_t recv_buffer3[4];

uint8_t background_buffer6[32];
uint8_t recv_buffer6[4];

uint8_t background_buffer8[32];
uint8_t recv_buffer8[4];

lpuart_rtos_handle_t handle3;
struct _lpuart_handle t_handle3;

lpuart_rtos_config_t lpuart_config3 = {
    .baudrate    = 115200,
    .parity      = kLPUART_ParityDisabled,
    .stopbits    = kLPUART_OneStopBit,
    .buffer      = background_buffer3,
    .buffer_size = sizeof(background_buffer3),
	.base  		 = LPUART3,
};

void init_tasks(){


	NVIC_SetPriority(LPUART3_IRQn, 6); //if this is not done, it is stuck after lpuart send


	uartRxQueue = xQueueCreate(QUEUE_LEN, sizeof(char));
	configASSERT(uartRxQueue);

	uartTxQueue = xQueueCreate(QUEUE_LEN, sizeof(char));
	configASSERT(uartTxQueue);

    xMutex = xSemaphoreCreateMutex();
    configASSERT(xMutex);

    count_semaphore_rx = xSemaphoreCreateCounting(20,0); //max, initial
    configASSERT(count_semaphore_rx);

    xSemaphoreTake(count_semaphore_rx, 0);//pdMS_TO_TICKS(200));

    count_semaphore_tx = xSemaphoreCreateCounting(20,0); //max, initial
    configASSERT(count_semaphore_tx);

    xSemaphoreTake(count_semaphore_tx, 0);//pdMS_TO_TICKS(200));

    lpuart_config3.srcclk = BOARD_DebugConsoleSrcFreq();//DEMO_LPUART_CLK_FREQ;

	if (0 > LPUART_RTOS_Init(&handle3, &t_handle3, &lpuart_config3))
	{
		PRINTF("uart3 init failed!.\r\n");
		while (1)
			;
	}

	if (xTaskCreate(uart3_rx_task, "Uart3_Rx_task", configMINIMAL_STACK_SIZE + 100, NULL, uart_task_PRIORITY , NULL) != pdPASS)
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

    xSemaphoreTake(xMutex, portMAX_DELAY);

	/* Send introduction message. */
	error = LPUART_RTOS_Send(&handle3, (uint8_t *)to_send3, strlen(to_send3));
	if (error != kStatus_Success)
	{
			PRINTF("uart3 init failed!.\r\n");
			vTaskSuspend(NULL);
	}

	xSemaphoreGive(xMutex);


	PRINTF("rx inited!.\r\n");


	while(error == kStatus_Success){ // stops if uart fails
		PRINTF("rx while.\r\n");

		// this call blocks until data available
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
					PRINTF("gave rx semaphore!.\r\n");
				}
			}

		}
		else{
			PRINTF("RX: no new message!.\r\n");
		}

	}

    LPUART_RTOS_Deinit(&handle3);
    vTaskSuspend(NULL);

}

void uart3_tx_task(void *pvParameters)
{

    int error;
//  size_t n = 0;
	const TickType_t xBlockTime = pdMS_TO_TICKS(200);
	char in;

    xSemaphoreTake(xMutex, portMAX_DELAY);

	/* Send introduction message. */
	error = LPUART_RTOS_Send(&handle3, (uint8_t *)to_send3_2, strlen(to_send3_2));

	xSemaphoreGive(xMutex);


	while(1){
		if(xSemaphoreTake(count_semaphore_tx, xBlockTime)){
			xQueueReceive(uartTxQueue, &in, xBlockTime);
			LPUART_RTOS_Send(&handle3, (uint8_t *)&in, 1);
			PRINTF("TX: took semaphore!.\r\n");
		}
		else{
//			PRINTF("TX: semaphore unavailable!.\r\n");
		}
	}

}

void process_task(void *pvParameters)
{

	const TickType_t xBlockTime = pdMS_TO_TICKS(200);
	char in;

	while(1){
		//sprintf(buffer,"Count = %d\n",(int)uxSemaphoreGetCount( count_semaphore_rx ));
		//PRINTF("process event!.\r\n");
		//PRINTF("%d\n",(int)uxSemaphoreGetCount( count_semaphore_rx ));
		if(xSemaphoreTake(count_semaphore_rx, xBlockTime)){
			PRINTF("RX: took semaphore!.\r\n");

			xQueueReceive(uartRxQueue, &in, xBlockTime);
			//do the processing

			//
			if((xQueueSendToBack(uartTxQueue, &in, xBlockTime)) == pdPASS ){
				xSemaphoreGive(count_semaphore_tx);
			}
		}
		else{
			//PRINTF("RX: semaphore unavailable!.\r\n");
		}

	}

}
