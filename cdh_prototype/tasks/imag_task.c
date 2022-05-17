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

#if IMAG_ENABLE
//	imag_init();
#endif
	for (;;) {
		PRINTF("IMG task loop\r\n");

#if QUEUE_DEMO_ENABLE // Demo receives CMD from COM task and executes it
		// TO-DO: how to handle an IMAGE
		if(queue_IMG != NULL) {
			if( xQueueReceive( queue_IMG, &(IMG_cmdID), ( TickType_t ) 0 ) == pdPASS ) {
				// execute IMG cmd
				PRINTF("IMG task received %d cmd\r\n", IMG_cmdID);
				switch (IMG_cmdID) {
					case checkStatus:
						break;
					case takePicture:
						break;
					case getPictureSize:
						break;
					case getPicture:
						// sets telemetry
						tel_COM.cmdID = imgReady;
						memset(tel_COM.data, 0, 8*sizeof(uint8_t));

						/* preps image */

						/* circular buffer */
//						uint8_t temp_image[IMG_SIZE];
//						memset(temp_image, 1, IMG_SIZE*sizeof(uint8_t));
//						cb_push_back(&IMG_PAYLOAD, &temp_image);

						/* brute force */
						memset(image_CIA, 1, IMG_SIZE*sizeof(uint8_t));

						// sends telemetry to COM once image is prepped
						xQueueSend( queue_COM, ( void * ) &(tel_COM), ( TickType_t ) 0 );
						break;
					case setContrast:
						break;
					case setBrightness:
						break;
					case setExposure:
						break;
					default:
						break;
				}
			}
		}
		vTaskDelay(xDelayms);
#endif

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
		vTaskDelay(xDelayms);
	}
#endif
}
