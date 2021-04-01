

/* FreeRTOS kernel includes. */
#include <img_wrap.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "imag_task.h"
#include "clock_config.h"

void imag_task(void *pvParameters)
{
#if IMAG_ENABLE
	PRINTF("\ninitialize imag.\r\n");

	// suspend ourselves here
	vTaskSuspend( NULL );

	for (;;) {
		PRINTF("\nimag work\r\n");
		vTaskSuspend( NULL );
	}
#endif
}
