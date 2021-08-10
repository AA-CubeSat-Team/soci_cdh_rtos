#include "imag_wrap.h"
#include "imag_task.h"
#include <stdint.h>
#include <stdbool.h>
#include "peripherals.h"
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include "semc_sdram.h"
#include "projdefs.h"

TaskHandle_t TaskHandler_img;
QueueHandle_t QueueHandler_CommandIMG; 
uint8_t IMG_command; 
uint8_t IMG_param; 

void imag_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); // delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time
#if IMAG_ENABLE
	PRINTF("\n Initialize imag.\r\n");
    imag_init(); 
	for (;;) {
		PRINTF("\n Imaging work \r\n");

		//Assumption: Command and param are sent to queue in order: command then param
		scanCommands(); // Retrieve command and param from commandIMG queue 
		switch (IMG_command) {
			case CHECK_STATUS:
				checkStatus(IMG_param);
				break;
			case TAKE_PICTURE:
				takePicture(IMG_param);
				break;
			case GET_PICTURE_SIZE:
				getPictureSize(IMG_param);
				break;
			case GET_PICTURE:
				getPicture(IMG_param);
				//getPicture will store the image in sdram and then send the images index and size to ImageInfo queue
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
#endif
}

// Retrieve the command and param from CommandIMG queue 
void scanCommands(){
	PRINTF("Fetching command from commandIMG queue...\r\n");
	if(xQueueReceive(QueueHandler_CommandIMG, &IMG_command, 500) != pdTRUE){ // TODO: How long to wait for queue? 500 ticks is arbitrary 
		PRINTF("Fetching command failed. \r\n");
	}
	PRINTF("Fetching param from commandIMG queue...\r\n");

	if(xQueueReceive(QueueHandler_CommandIMG, &IMG_param, 500) != pdTRUE){ // TODO: How long to wait for queue? 500 ticks is arbitrary 
		PRINTF("Fetching param failed. \r\n");
	}
}	

// Correct Version