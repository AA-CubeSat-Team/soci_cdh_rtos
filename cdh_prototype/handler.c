/*
 * handler.c
 *
 *  Created on: Sep 22, 2022
 *      Author: andyl
 */
#include <stdbool.h>
#include "fsl_debug_console.h"
#include "idle_task.h"
#include "eps_wrap.h"
#include "sen_wrap.h"
#include <stdint.h>
#include "peripherals.h"
#include "semc_sdram.h"
#include "fsl_semc.h"
#include "img_wrap.h"
#include "act_wrap/act_wrap.h"
#include "lpm.h"
#include "power_mode_switch.h"
#include "specific.h"
#include "RTWDOG_PROTO.h"
#include "fsl_rtwdog.h"
TaskHandle_t handler;
extern uint8_t gnc_flag;
extern uint8_t idle_flag;
extern uint8_t img_flag;

void handler_task(void *pvParameters) {
	if (gnc_flag | idle_flag | img_flag){
		uint16_t counterValueRTWDOGPre = RTWDOG_GetCounterValue(RTWDOG);
		PRINTF("Current RTWDOG counter value before refresh: %u\r\n", counterValueRTWDOGPre); // value before refresh
		RTWDOG_Refresh(RTWDOG); // should refresh the rtwdog and let the task continue running as expected
		if(counterValueRTWDOGPre >= 300){
			PRINTF("RESET IMMINENT");
		}
		PRINTF("refresh\r\n");
		uint16_t counterValueRTWDOGPost = RTWDOG_GetCounterValue(RTWDOG);
		PRINTF("Current RTWDOG counter value after refresh: %u\r\n", counterValueRTWDOGPost);
		gnc_flag = 0;
		idle_flag = 0;
		img_flag = 0;
	}


}
