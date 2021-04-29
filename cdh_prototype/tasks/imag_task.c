#include "img_wrap.h"
#include "imag_task.h"


/*******************************************************************************
 * Variable Declarations
 ******************************************************************************/
TaskHandle_t TaskHandler_img;

//TODO: need to go over the operation of IMG and the wrappers to lay out the functions in this task
void imag_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time
#if IMAG_ENABLE
	PRINTF("\ninitialize imag.\r\n");


	for (;;) {
		PRINTF("\nimag work\r\n");

		vTaskSuspend( NULL );
	}
#else
	vTaskDelayUntil(&xLastWakeTime, xDelayms);
#endif
}
