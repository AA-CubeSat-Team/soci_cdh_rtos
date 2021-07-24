#include "img_wrap.h"
#include "imag_task.h"
#include "semc_sdram.h"

static uint8_t recv_buffer[5]; // Receive 5 bytes
//TODO: tell Lachlan to extern the recv_buff in wrapper.
//TODO:
//interact with the sdram, when we getPicture from IMG, store it in sdram, and retrieve the image from sdram to send to the MCC

TaskHandle_t TaskHandler_img;
extern uint8_t IMG_command; //TODO: what does img command look like?
extern uint8_t IMG_param; //TODO: what does img command look like?

/*UART 4
  Ring buffer for data input and output, input data are saved
  to ring buffer in IRQ handler. The main function polls the ring buffer status,
  if there is new data, then send them out.
  Ring buffer full: (((rxIndex + 1) % DEMO_RING_BUFFER_SIZE) == txIndex)
  Ring buffer empty: (rxIndex == txIndex)
*/
uint8_t UART4RingBuffer[UART4_RING_BUFFER_SIZE];
volatile uint16_t txIndex_4; /* Index of the data to send out. */
volatile uint16_t rxIndex_4; /* Index of the memory to save new arrived data. */
uint8_t UART_4[] =
    "UART 4 initialized \r\n";

void UART4_IRQHandler(void)
{
    uint8_t data;
    uint16_t tmprxIndex = rxIndex_4;
    uint16_t tmptxIndex = txIndex_4;

    /* If new data arrived. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART_4))
    {
        data = LPUART_ReadByte(LPUART_4);

        /* If ring buffer is not full, add data to ring buffer. */
        if (((tmprxIndex + 1) % UART4_RING_BUFFER_SIZE) != tmptxIndex)
        {
        	UART4RingBuffer[rxIndex_4] = data;
            rxIndex_4++;
            rxIndex_4 %= UART4_RING_BUFFER_SIZE;
        }
    }
    SDK_ISR_EXIT_BARRIER;
}

//TODO: need to go over the operation of IMG and the wrappers to lay out the functions in this task
void imag_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time


	/*initiate UART 4*/
    lpuart_config_t config;
    uint16_t tmprxIndex = rxIndex_4;
    uint16_t tmptxIndex = txIndex_4;

    LPUART_GetDefaultConfig(&config);
    config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
    config.enableTx     = true;
    config.enableRx     = true;

    LPUART_Init(LPUART_4, &config, LPUART4_CLK_FREQ);

    /* Send g_tipString out. */
    if(kStatus_Success == LPUART_WriteBlocking(LPUART_4, UART_4, sizeof(UART_4) / sizeof(UART_4[0]))) {
    	PRINTF("UART4 succeed write blocking\r\n");
	} else {
		PRINTF("UART4 failed write blocking\r\n");
	}

    /* Enable RX interrupt. */
    LPUART_EnableInterrupts(LPUART_4, kLPUART_RxDataRegFullInterruptEnable);
    EnableIRQ(UART4_IRQn);

    /*UART 4 initialisation done */

    /* sdram example */
    memset(sdram_writeBuffer, 0, sizeof(sdram_writeBuffer));
    memset(sdram_readBuffer, 0, sizeof(sdram_readBuffer));
    SEMC_SDRAM_Read(0, 10, 1);
    memset(sdram_writeBuffer, 1, sizeof(sdram_writeBuffer));
    SEMC_SDRAM_Write(0, 10, 1);
    SEMC_SDRAM_Read(0, 10, 1);
	for (int i = 0; i < 10; i++) {
		//read into the readBuffer to access later
		PRINTF("reading 0x%2x from sdram at %ith byte", sdram_readBuffer[i], i);
	}
#if IMAG_ENABLE
	PRINTF("\ninitialize imag.\r\n");
//	imag_init();
#endif
	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
#if IMAG_ENABLE
		PRINTF("\nimag work\r\n");
		/* sending commands to IMG */
		//use the commands from the MCC (retrieve from a queue of commands)
		//determine what functions we want to call,
		//send the commands and params to the function
		switch (IMG_command) {
			case CHECK_STATUS:
				checkStatus(IMG_param);
				break;
			case TAKE_PICTURE:
				takePicture(IMG_param);
				break;
			case GET_THUMBNAIL_SIZE:
				getThumbnailSize(IMG_param);
				break;
			case GET_PICTURE_SIZE:
				getPictureSize(IMG_param);
				break;
			case GET_THUMBNAIL:
				getThumbnail(IMG_param);
				break;
			case GET_PICTURE:
				getPicture(IMG_param);
				break;
			case SET_CONTRAST:
				setContrast(IMG_param);
				break;
			case SET_BRIGHTNESS:
				setBrightness(IMG_param);
				break;
			case SET_EXPOSURE:
				setExposure(IMG_param);
				break;
			case SET_SLEEP_TIME:
				setSleepTime(IMG_param);
				break;
			default:
				PRINTF("IMG sendCommand UNKNOWN\r\n");
				break;
		}
		vTaskSuspend( NULL );
	}
#else
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#endif
}
