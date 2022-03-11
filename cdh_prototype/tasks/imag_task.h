#define IMAG_ENABLE	1

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "clock_config.h"

/*UART includes*/
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_lpuart.h"

/* Variable Declarations
 ******************************************************************************/
extern TaskHandle_t TaskHandler_img;

/*******************************************************************************
 * Function declarations
 ******************************************************************************/
void imag_task(void *pvParameters);
