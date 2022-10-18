//TODO: tell Lachlan to extern the recv_buff in wrapper.
//TODO:
//interact with the sdram, when we getPicture from IMG, store it in sdram, and retrieve the image from sdram to send to the MCC
#include "FreeRTOS.h"
#include "task.h"
#include "img_wrap.h"
#include "imag_task.h"
#include "fsl_common.h"
#include "semc_sdram.h"
#include "com_protocol_helper.h"

//static uint8_t recv_buffer[5]; // Receive 5 bytes

TaskHandle_t TaskHandler_img;
extern uint8_t IMG_command; //TODO: what does img command look like?
extern uint8_t IMG_param; //TODO: what does img command look like?
uint8_t img_flag;

//TODO: need to go over the operation of IMG and the wrappers to lay out the functions in this task
void imag_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	//TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time
	PRINTF("\ninitialize imag.\r\n");
	img_flag = 0;
    // sdram example
//    memset(sdram_writeBuffer, 0, sizeof(sdram_writeBuffer));
//    memset(sdram_readBuffer, 0, sizeof(sdram_readBuffer));
//    SEMC_SDRAM_Read(0, 10, 1);
//    memset(sdram_writeBuffer, 1, sizeof(sdram_writeBuffer));
//    SEMC_SDRAM_Write(0, 10, 1);
//    SEMC_SDRAM_Read(0, 10, 1);
//	for (int i = 0; i < 10; i++) {
//		//read into the readBuffer to access later
//		PRINTF("reading 0x%2x from sdram at %ith byte", sdram_readBuffer[i], i);
//	}
#if IMAG_ENABLE
//	imag_init();
#endif
	img_flag = 1;
	for (;;) {
		PRINTF("imag task loop\r\n");
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
		img_flag = 1;
	}
#else
		vTaskDelay(xDelayms);
	}
#endif
}