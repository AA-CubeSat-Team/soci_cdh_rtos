//TODO: tell Lachlan to extern the recv_buff in wrapper.
//TODO:
//interact with the sdram, when we getPicture from IMG, store it in sdram, and retrieve the image from sdram to send to the MCC

#include <imag_wrap.h>
#include "imag_task.h"
#include "semc_sdram.h"
#include <stdbool.h>

TaskHandle_t TaskHandler_img;

uint8_t IMG_command = 5; //hard coded test command
uint8_t IMG_param = 0; //hard coded test param
IMG_system_response responseStatus;

//uint8_t UART4RingBuffer[UART4_RING_BUFFER_SIZE];
lpuart_handle_t lpuart4Handle;

// UART send buffer
volatile bool newCommandFlag = 1; // default should be 0, set to 1 for testing purpose

extern volatile bool responseReceivedFlag = 0;

void UART4_IRQHandler(void)
{
	getResponse();
	responseReceivedFlag = 1;
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
		 	// Note: to get an image, system need to get its size first
		 	//IMG_command = IMG_command == GET_PICTURE ? GET_PICTURE_SIZE : IMG_command;
			sendCommand(IMG_command == GET_PICTURE ? GET_PICTURE_SIZE : IMG_command, IMG_param);
			PRINTF("Waiting for response\r\n");
			while(responseReceivedFlag == false) {
				delay(1); // TODO: figure out why doesn't work without delay
			}
			responseReceivedFlag = true;
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
