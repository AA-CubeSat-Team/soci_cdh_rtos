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

/*UART includes*/
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_lpuart.h"

/*******************************************************************************
 * Variable Declarations
 ******************************************************************************/

/*******************************************************************************
 * Definitions for UART 3
 ******************************************************************************/
#define LPUART_3           	LPUART3
#define LPUART3_CLK_FREQ   	BOARD_DebugConsoleSrcFreq()
#define UART3_IRQn       	LPUART3_IRQn
#define UART3_IRQHandler 	LPUART3_IRQHandler

/*! @brief Ring buffer size for UART 3 (Unit: Byte). */
#define UART3_RING_BUFFER_SIZE 16

/*******************************************************************************
 * Function declarations
 ******************************************************************************/
void UART3_IRQHandler(void);
void gnc_task(void *pvParameters);
