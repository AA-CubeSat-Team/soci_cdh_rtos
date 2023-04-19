//interact with the sdram, when we getPicture from IMG, store it in sdram, and retrieve the image from sdram to send to the MCC
#include "telemetry.h"
#include "img_wrap.h"
#include "imag_task.h"
#include "com_protocol_helper.h"
#include "RTWDOG_PROTO.h"

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
		/* pseudocode*/
		if( xQueueReceive( cmd_queue_IMG, &(IMG_cmdID), ( TickType_t ) 5 ) == pdPASS ) { // <- Instead of if(new command flag)
			// execute IMG cmd
			PRINTF("IMG task received %d cmd\r\n", IMG_cmdID);
			switch (IMG_cmdID) {
				/* goal is to set communication between com and img */
				/*
				 * cmd_queue_IMG = xQueueCreate( xQueue_len, sizeof(uint8_t));
                 * cmd_queue_GNC = xQueueCreate( xQueue_len, sizeof(uint8_t));
                 * cmd_queue_EPS = xQueueCreate( xQueue_len, sizeof(uint8_t));
                 * tlm_queue_COM = xQueueCreate( xQueue_len, sizeof(uint8_t));
				 */
				case getPicture:
					uint8_t cmdID;
					uint8_t data_length;
					uint8_t data;

					// sets telemetry
					image_CIA[IMG_SIZE] = set pictures;

					if(success) {
						cmdID = imgReady;
						data_length = 1;
						data = 1;
					} else {
						cmdID = imgReady;
						data_length = 1;
						data = 1;
					}

					//always send data in this format
					//data_length + packetID + data
					// 0 | getPicture
					// sends telemetry to COM once image is prepped
					xQueueSend( tlm_queue_COM, ( void * ) &(data_length), ( TickType_t ) 0 );
					xQueueSend( queue_COM, ( void * ) &(cmdID)), ( TickType_t ) 0 );
					xQueueSend( queue_COM, ( void * ) &(data)), ( TickType_t ) 0 );
					break;
				default:
					break;
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
		RTWDOG_Refresh(RTWDOG);
		PRINTF("img task refreshed \n");
		vTaskSuspend( NULL );
	}
#else
	RTWDOG_Refresh(RTWDOG);
	PRINTF("img task refreshed \n");
	vTaskDelay(xDelayms);
	}
#endif
}
