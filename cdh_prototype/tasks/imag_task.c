//interact with the sdram, when we getPicture from IMG, store it in sdram, and retrieve the image from sdram to send to the MCC
#include "telemetry.h"
#include "img_wrap.h"
#include "imag_task.h"
#include "com_protocol_helper.h"

//static uint8_t recv_buffer[5]; // Receive 5 bytes

TaskHandle_t TaskHandler_img;
extern uint8_t IMG_command; //TODO: what does img command look like?
extern uint8_t IMG_param; //TODO: what does img command look like?
uint8_t image_CIA[IMG_SIZE];
//TODO: need to go over the operation of IMG and the wrappers to lay out the functions in this task
void imag_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	//TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time
	PRINTF("\ninitialize imag.\r\n");


#if QUEUE_DEMO_ENABLE
	struct tel tel_COM;
	uint8_t IMG_cmdID;

	/* Create IMG Ring Buffer */
	//cb_init(&IMG_PAYLOAD, 5, IMG_SIZE);

	vTaskDelay(xDelayms);

#endif
	for (;;) {
		PRINTF("IMG task loop\r\n");
#if IMAG_ENABLE
		/* sending commands to IMG */
		//use the commands from the MCC (retrieve from a queue of commands)
		//determine what functions we want to call,
		//send the commands and params to the function

		// TODO: figure out how to issue new command and set the flag
		//if (...)newCommandFlag = 1; send command

		if( xQueueReceive( cmd_queue_IMG, &(IMG_command), ( TickType_t ) 5 ) == pdPASS ) {
			PRINTF("Sending command\r\n");
			xQueueReceive( cmd_queue_IMG, &(IMG_param), ( TickType_t ) 5 );
			// Note: to get an image, system need to get its size first
			//IMG_command = IMG_command == GET_PICTURE ? GET_PICTURE_SIZE : IMG_command;
			sendCommand(IMG_command == GET_PICTURE ? GET_PICTURE_SIZE : IMG_command, IMG_param);
			PRINTF("Waiting for response\r\n");
			uint8_t try = 0;
			switch (IMG_command) {
				case CHECK_STATUS:
					responseStatus = checkStatus(IMG_param);
					/*
					 * 0: success
					 * 1: sd card error
					 * 2: camera error
					 */
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
				xQueueSend( tlm_queue_COM, &(1), 5);
			`	xQueueSend( tlm_queue_COM, &(IMG_command), 5);
				xQueueSend( tlm_queue_COM, &(responseStatus), 5);
			}
			PRINTF("Response from IMG system: %d\r\n", responseStatus);
			newCommandFlag = 0;
		}

		vTaskSuspend( NULL );
	}
#else
		vTaskDelay(xDelayms);
	}
#endif
}
