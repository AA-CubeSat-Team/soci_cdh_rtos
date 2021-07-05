#define COM_ENABLE	0

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
 * Definitions for UART 1
 ******************************************************************************/
#define LPUART_1           	LPUART1
#define LPUART1_CLK_FREQ   	BOARD_DebugConsoleSrcFreq()
#define UART1_IRQn       	LPUART1_IRQn
#define UART1_IRQHandler 	LPUART1_IRQHandler

/*! @brief Ring buffer size for UART 1 (Unit: Byte). */
#define UART1_RING_BUFFER_SIZE 16



/*******************************************************************************
 * Variable Declarations
 ******************************************************************************/

//flags to check if there's data to send
//cdh receives these data and sends the data to radio which to
extern bool command_request;
extern bool payload_check;
extern bool image_check;
extern bool beacon_check;

extern TaskHandle_t TaskHandler_com;

/*******************************************************************************
 * Function declarations
 ******************************************************************************/
void UART1_IRQHandler(void);
void com_task(void *pvParameters);


