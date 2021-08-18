//TODO: tell Lachlan to extern the recv_buff in wrapper.
//TODO:
//interact with the sdram, when we getPicture from IMG, store it in sdram, and retrieve the image from sdram to send to the MCC

#include <imag_wrap.h>
#include "imag_task.h"
#include "semc_sdram.h"
#include <stdbool.h>

TaskHandle_t TaskHandler_img;

extern uint8_t IMG_command = 0; //hard coded test command
extern uint8_t IMG_param = 2; //hard coded test param
IMG_system_response responseStatus;

//uint8_t UART4RingBuffer[UART4_RING_BUFFER_SIZE];
lpuart_handle_t lpuart4Handle;

// UART send buffer
volatile bool newCommandFlag = 1; // default should be 0, set to 1 for testing purpose

void UART4_IRQHandler(void)
{
	getResponse();
    SDK_ISR_EXIT_BARRIER;
}

//TODO: need to go over the operation of IMG and the wrappers to lay out the functions in this task
void imag_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time


	/*initiate UART 4*/
    lpuart_config_t config;

    LPUART_GetDefaultConfig(&config);
    //config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
    config.baudRate_Bps = 57600;
    config.enableTx     = true;
    config.enableRx     = true;

    LPUART_Init(LPUART_4, &config, LPUART4_CLK_FREQ);

    /* Enable RX interrupt. */
	LPUART_EnableInterrupts(LPUART_4, kLPUART_RxDataRegFullInterruptEnable);
	EnableIRQ(UART4_IRQn);
    /*UART 4 initialisation done */

    // sdram example
   /* memset(sdram_writeBuffer, 0, sizeof(sdram_writeBuffer));
    memset(sdram_readBuffer, 0, sizeof(sdram_readBuffer));
    SEMC_SDRAM_Read(0, 10, 1);
    memset(sdram_writeBuffer, 1, sizeof(sdram_writeBuffer));
    SEMC_SDRAM_Write(0, 10, 1);
    SEMC_SDRAM_Read(0, 10, 1);
	for (int i = 0; i < 10; i++) {
		//read into the readBuffer to access later
		PRINTF("reading 0x%2x from sdram at %ith byte", sdram_readBuffer[i], i);
	}*/
#if IMAG_ENABLE
	PRINTF("\ninitialize imag.\r\n");
//	imag_init();
#endif
	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
#if IMAG_ENABLE
		/* sending commands to IMG */
		//use the commands from the MCC (retrieve from a queue of commands)
		//determine what functions we want to call,
		//send the commands and params to the function

		// TODO: figure out how to issue new command and set the flag
		//if (...)newCommandFlag = 1; send command


		if (newCommandFlag) {
		 	PRINTF("Sending command\r\n");
			sendCommand(IMG_command, IMG_param);
			PRINTF("Waiting for response\r\n");
			switch (IMG_command) {
				case CHECK_STATUS:
					responseStatus = checkStatus(IMG_param);
					break;
				case TAKE_PICTURE:
					responseStatus = takePicture(IMG_param);
					break;
				case GET_PICTURE_SIZE:
					responseStatus = getPictureSize(IMG_param);
					break;
				case GET_PICTURE:
					responseStatus = getPicture(IMG_param);
					break;
				case SET_CONTRAST:
					responseStatus = setContrast(IMG_param);
					break;
				case SET_BRIGHTNESS:
					responseStatus = setBrightness(IMG_param);
					break;
				case SET_EXPOSURE:
					responseStatus = setExposure(IMG_param);
					break;
				case SET_SLEEP_TIME:
					responseStatus = setSleepTime(IMG_param);
					break;
				default:
					PRINTF("Invalid command\r\n");
					break;
			}
			PRINTF("Response from IMG system: %d\r\n", responseStatus);
			newCommandFlag = 0;
		}

		vTaskSuspend( NULL );
	}
#else
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#endif
}
