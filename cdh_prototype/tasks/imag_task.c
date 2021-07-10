#include "imag_wrap.h"
#include "imag_task.h"
#include <stdint.h>
#include <stdbool.h>
#include "peripherals.h"
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"

static uint8_t recv_buffer[5]; // Buffer for receiving commands TODO: is 5 bytes enough? 
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
	PRINTF("\ninitialize imag.\r\n");
    imag_init(); //  Where is this defined? Does this initialize the imaging boards?
	scanCommands(); // Retrieve commands from MCC and store in recv_buffer 
	for (;;) {
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
			case GET_PICTURE_SIZE:
				getPictureSize(IMG_param);
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
#endif
}

// Retrieve the command(s) from MCC from a global queue 
void scanCommands(){
	// Reset buffer memory before receiving
	memset(recv_buffer, 0, sizeof(recv_buffer));
	if(xQueueReceive(/*Handle of command queue*/, &recv_buffer, 100)){ // 100 ticks is arbitrary TODO: How long to wait for queue?
		PRINTF("Fetching commands succeeded! \r\n");
	} else {
		PRINTF("Failed to fetch commands from queue.\r\n");
	}
}	
