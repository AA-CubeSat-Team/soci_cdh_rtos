#define GNC_ENABLE	1

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

/*******************************************************************************
 * Variable Declarations
 ******************************************************************************/
//extern bool g_sunSensActive, g_magSensActive, g_phdSensActive, g_mtqSensActive, g_rwaSensActive;

/*******************************************************************************
 * Function declarations
 ******************************************************************************/
void gnc_task(void *pvParameters);
