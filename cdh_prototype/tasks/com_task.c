
/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include <stdbool.h>
#include <time.h>

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "com_wrap.h"
#include "com_task.h"
#include "clock_config.h"

#define CLOCKS_PER_SECOND 1000000


//flags to check if there's data to send
//cdh receives these data and sends the data to radio which to
bool command_request = false;
bool payload_check = false;
bool image_check = false;
bool beacon_check = false;
bool com_wrap_debug = true;

extern TaskHandle_t TaskHandler_img;
extern bool g_comActive;
extern bool g_imgActive;

void com_task(void *pvParameters)
{
   /* Questions: What do I pass in to these commands,
      Do I need to change main.c ? Is it fine to include
      com_wrap.c in this class?
    */

	if(com_wrap_debug){
		// Delay to test "soft-break" into command mode via com_init function
		delay(10);
		//PRINTF("Testing com_init() function:\n");
		//com_init();
		//PRINTF("\n");
		PRINTF("Testing com_healthcheck() function:\n");
		com_healthcheck(); // exits command mode afterwards
		PRINTF("\n");

		//PRINTF("Testing com_set_burn_wire1()\n");
		//com_set_burn_wire1();
		//PRINTF("\n");
		//PRINTF("Testing com_set_burn_wire2()\n");
		//com_set_burn_wire2();
		//PRINTF("\n");

		// Probably not needed since com_init showed us sendConfigCommand works
		// PRINTF("Testing exitCommandMode function:\n");;
		// com_exitCommandMode();
		// PRINTF("\n");
	}
	else {
		const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
		PRINTF("\ninitialize comm.\r\n");
		com_init();
		com_set_burn_wire1();
		com_set_burn_wire2();
		int count = 0;
		for (;;) {
			TickType_t xLastWakeTime = xTaskGetTickCount();
			PRINTF("\ncomm work.\r\n");
			if(g_comActive == true){
	//			com_getCommands();
			}
			count++;
			PRINTF("count = %d\n", count);
			if (count >= 5){ //later: receive a command to take a pic
				vTaskResume(TaskHandler_img);
				count = 0;
				PRINTF("resuming img task\r\n");
			}

	//		if(g_comActive == true){
	//			//checking if getting a command request
	//			if (command_request){
	//				//sending data based on priority
	//				if (payload_check) {
	//					com_sendPayloads();
	//				} else if (image_check && g_imgActive) {
	//					com_sendImages();
	//				} else if(xTaskGetTickCount() - xLastWakeTime >= 60*1000){ //check if 60 secs have passed
	//					com_sendBeacons();
	//				}
	//			}
	//
	//		}
	//		else{
	//
	//		}

			vTaskDelayUntil(&xLastWakeTime, xDelayms);

		}
	}
}


