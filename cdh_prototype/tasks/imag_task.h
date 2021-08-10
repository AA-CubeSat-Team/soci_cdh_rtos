#define IMAG_ENABLE	1
#include <stdint.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "projdefs.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "clock_config.h"

/*******************************************************************************
 * Variable Declarations
 ******************************************************************************/
extern TaskHandle_t TaskHandler_img;
extern QueueHandle_t QueueHandler_CommandIMG; 

/*******************************************************************************
 * Function declarations
 ******************************************************************************/
void imag_task(void *pvParameters);
