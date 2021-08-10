#include "wrappers/gyro_wrapper/gyro_wrap.h"
#include "gnc_task.h"
//#include "FSW_Lib_types.h"
#include "act_wrap.h"
#include "sen_wrap.h"
#include "idle_task.h"
#include "peripherals.h"

//#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_types.h>
//#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>

extern bool g_senActive, g_rwaActive, g_mtqActive;

/*UART 3
  Ring buffer for data input and output, input data are saved
  to ring buffer in IRQ handler. The main function polls the ring buffer status,
  if there is new data, then send them out.
  Ring buffer full: (((rxIndex + 1) % DEMO_RING_BUFFER_SIZE) == txIndex)
  Ring buffer empty: (rxIndex == txIndex)
*/
uint8_t UART3RingBuffer[UART3_RING_BUFFER_SIZE];
volatile uint16_t txIndex_3; /* Index of the data to send out. */
volatile uint16_t rxIndex_3; /* Index of the memory to save new arrived data. */
uint8_t UART_3[] =
    "UART 3 initialized \r\n";

void UART3_IRQHandler(void)
{
    uint8_t data;
    uint16_t tmprxIndex = rxIndex_3;
    uint16_t tmptxIndex = txIndex_3;

    /* If new data arrived. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART_3))
    {
        data = LPUART_ReadByte(LPUART_3);

        /* If ring buffer is not full, add data to ring buffer. */
        if (((tmprxIndex + 1) % UART3_RING_BUFFER_SIZE) != tmptxIndex)
        {
        	UART3RingBuffer[rxIndex_3] = data;
            rxIndex_3++;
            rxIndex_3 %= UART3_RING_BUFFER_SIZE;
        }
    }
    SDK_ISR_EXIT_BARRIER;
}

//TODO: need to go over the operation of GNC and the wrappers to lay out the functions in this task
void gnc_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount();

	/*initiate UART 3*/
	lpuart_config_t config;
	uint16_t tmprxIndex = rxIndex_3;
	uint16_t tmptxIndex = txIndex_3;

	LPUART_GetDefaultConfig(&config);
	config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
	config.enableTx     = true;
	config.enableRx     = true;

	LPUART_Init(LPUART_3, &config, LPUART3_CLK_FREQ);

	/* Send g_tipString out. */
	if(kStatus_Success == LPUART_WriteBlocking(LPUART_3, UART_3, sizeof(UART_3) / sizeof(UART_3[0]))) {
		PRINTF("UART3 succeed write blocking\r\n");
	} else {
		PRINTF("UART3 failed write blocking\r\n");
	}

	/* Enable RX interrupt. */
	LPUART_EnableInterrupts(LPUART_3, kLPUART_RxDataRegFullInterruptEnable);
	EnableIRQ(UART3_IRQn);

    /*UART 3 initialization done */

#if SPI_TEST
		/* Initialize data in transfer buffers */
		for (int i = 0; i < 16; i++)
		{
			masterSendBuffer[i]    = i;

			slaveSendBuffer[i] = masterSendBuffer[i];//checks match with slave response
		}
		SPI_transfer(masterSendBuffer, masterReceiveBuffer, 16, RWA0);
		SPI_transfer(masterSendBuffer, masterReceiveBuffer, 16, RWA1);
		SPI_transfer(masterSendBuffer, masterReceiveBuffer, 16, RWA2);
		SPI_transfer(masterSendBuffer, masterReceiveBuffer, 16, RWA3);
#endif

#if GNC_ENABLE
	PRINTF("\ninitialize gnc.\r\n");
	/* gnc, sens, act initialization */
//	sens_init();
//  act_init();
//	FSW_Lib_initialize(); //GNC initialization
#endif
	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
#if GNC_ENABLE
//		xLastWakeTime = xTaskGetTickCount();
		PRINTF("\nGNC TASK START.\r\n");

		/* read sensors and actuator measurements to sensor_bus */
		if (g_senActive) {
//			sens_readSun();
//			sens_readMag();
//			sens_readPhd();
//			sens_readGyr();
		}
		if (g_rwaActive) {
//			readRWA();
		}
		if (g_mtqActive) {
//			readMTQ();
		}

		/* call GNC rt_OneStep() */
//		 rt_OneStep(); // TODO: enable rt_OneStep() after include
		/* write to actuators */
		if (g_rwaActive) {
//			writeRWA();
		}
		if (g_mtqActive) {
//			writeMTQ();
		}
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#else
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#endif
}
