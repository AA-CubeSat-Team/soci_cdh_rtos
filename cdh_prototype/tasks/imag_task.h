#define IMAG_ENABLE	0

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
 * Definitions for UART 4
 ******************************************************************************/
#define LPUART_4           	LPUART4
#define LPUART4_CLK_FREQ   	BOARD_DebugConsoleSrcFreq()
#define UART4_IRQn       	LPUART4_IRQn
#define UART4_IRQHandler 	LPUART4_IRQHandler

/*! @brief Ring buffer size for UART 4 (Unit: Byte). */
#define UART4_RING_BUFFER_SIZE 16

/*******************************************************************************
 * Variable Declarations
 ******************************************************************************/
extern TaskHandle_t TaskHandler_img;

/*******************************************************************************
 * Function declarations
 ******************************************************************************/
void UART4_IRQHandler(void);
void imag_task(void *pvParameters);
