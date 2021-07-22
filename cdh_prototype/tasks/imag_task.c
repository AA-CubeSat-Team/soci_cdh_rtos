#include "imag_wrap.h"
#include "imag_task.h"
#include <stdint.h>
#include <stdbool.h>
#include "peripherals.h"
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include "semc_sdram.h"

static uint8_t recv_buffer[5]; // Buffer for receiving commands 	TODO: is 5 bytes enough/too much? 
//interact with the sdram, when we getPicture from IMG, store it in sdram, and retrieve the image from sdram to send to the MCC

TaskHandle_t TaskHandler_img;
extern uint8_t IMG_command; //TODO: what does img command look like?
extern uint8_t IMG_param; //TODO: what does img command look like?

//TODO: need to go over the operation of IMG and the wrappers to lay out the functions in this task
void imag_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time
#if IMAG_ENABLE
	PRINTF("\n Initialize imag.\r\n");
    imag_init(); //  Where is this defined? Does this initialize the imaging boards?
	for (;;) {
		PRINTF("\nImaging work\r\n");
		/* sending commands to IMG */
		//use the commands from the MCC (retrieve from a queue of commands)
		//determine what functions we want to call,
		//send the commands and params to the function

		//Assumption: Command and param are sent to queue as {command, param}
		scanCommands(); // Retrieve commands from MCC and store in recv_buffer 
		IMG_command = recv_buffer[0];
		IMG_param = recv_buffer[1];
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
				//getPicture will store the image in sdram and then read it to the readbuffer
				if(getPicture == ACK){
					PRINTF("sending sdram read buffer to queue");
					xQueueSend(/*Handle of image transfer queue*/, &sdram_readBuffer_copy, 100);
				} else {
					PRINTF("getPicture failed.\r\n");
				}
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

// Retrieve the command(s) from MCC/GNC from a global queue 
void scanCommands(){
	PRINTF("Fetching command from queue...\r\n");
	// Reset buffer memory before receiving
	memset(recv_buffer, 0, sizeof(recv_buffer));
	if(xQueueReceive(/*Handle of command queue*/, &recv_buffer, 100)){ // 100 ticks is arbitrary TODO: How long to wait for queue?
		PRINTF("Fetching command succeeded! \r\n");
	} else {
		PRINTF("Failed to fetch command from queue.\r\n");
	}
}	

// Correct Version