/*
 * rtwdog_handler.c
 *
 *  Created on: Sep 22, 2022
 *      Author: andyl, Illya Kuzmych
 */
#include <stdbool.h>
#include <stdint.h>
#include "RTWDOG_PROTO.h"
#include "peripherals.h"

TaskHandle_t TaskHandle_rtwdog_handler;
extern uint8_t gnc_flag;
extern uint8_t idle_flag;
extern uint8_t img_flag;

uint16_t counterValueRTWDOGPre;
// uint16_t counterValueRTWDOGPost;

void handler_task(void *pvParameters) {
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 );
	if (gnc_flag | idle_flag | img_flag){                // Add com_flag (Illya's question)
		counterValueRTWDOGPre = RTWDOG_GetCounterValue(RTWDOG);
		//PRINTF("Current RTWDOG counter value before refresh: %u\r\n", counterValueRTWDOGPre); // value before refresh
		RTWDOG_Refresh(RTWDOG); // should refresh the rtwdog and let the task continue running as expected
		PRINTF("refresh\r\n");

		if(counterValueRTWDOGPre >= 300){
			PRINTF("RESET IMMINENT");
		}

//		counterValueRTWDOGPost = RTWDOG_GetCounterValue(RTWDOG);
//		PRINTF("Current RTWDOG counter value after refresh: %u\r\n", counterValueRTWDOGPost);


		// Reset the task_success flags
		gnc_flag = 0;
		idle_flag = 0;
		img_flag = 0;
	}

	vTaskDelay(xDelayms);

}
