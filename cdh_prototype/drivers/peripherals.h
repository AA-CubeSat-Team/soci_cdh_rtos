/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_common.h"
#include "fsl_gpt.h"
#include "fsl_clock.h"
#include "fsl_lpi2c.h"
#include "fsl_lpi2c_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_lpuart_freertos.h"
#include "fsl_lpspi.h"
#include "fsl_lpspi_freertos.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* Definition of peripheral ID */
#define GPT_PERIPHERAL GPT2
/* Definition of the clock source frequency */
#define GPT_CLOCK_SOURCE 32768UL
/* NVIC interrupt vector ID (number). */
#define INT_0_IRQN LPI2C1_IRQn
/* NVIC interrupt vector priority. */
#define INT_0_IRQ_PRIORITY 3
/* NVIC interrupt handler identifier. */
#define INT_0_IRQHANDLER LPI2C1_IRQHandler
/* NVIC interrupt vector ID (number). */
#define INT_1_IRQN LPI2C2_IRQn
/* NVIC interrupt vector priority. */
#define INT_1_IRQ_PRIORITY 3
/* NVIC interrupt handler identifier. */
#define INT_1_IRQHANDLER LPI2C2_IRQHandler
/* BOARD_InitPeripherals defines for LPI2C1 */
/* Definition of peripheral ID */
#define LPI2C1_PERIPHERAL LPI2C1
/* Definition of clock source */
#define LPI2C1_CLOCK_FREQ 60000000UL
/* Transfer buffer size */
#define LPI2C1_MASTER_BUFFER_SIZE 32
/* Definition of slave address */
#define LPI2C1_MASTER_SLAVE_ADDRESS 0
/* BOARD_InitPeripherals defines for LPI2C2 */
/* Definition of peripheral ID */
#define LPI2C2_PERIPHERAL LPI2C2
/* Definition of clock source */
#define LPI2C2_CLOCK_FREQ 60000000UL
/* Transfer buffer size */
#define LPI2C2_MASTER_BUFFER_SIZE 32
/* Definition of slave address */
#define LPI2C2_MASTER_SLAVE_ADDRESS 126
/* Definition of peripheral ID */
#define LPUART3_PERIPHERAL LPUART3
/* Definition of the backround buffer size */
#define LPUART3_BACKGROUND_BUFFER_SIZE 64
/* LPUART3 interrupt vector ID (number). */
#define LPUART3_IRQN LPUART3_IRQn
/* LPUART3 interrupt vector priority. */
#define LPUART3_IRQ_PRIORITY 5
/* Definition of peripheral ID */
#define LPUART4_PERIPHERAL LPUART4
/* Definition of the backround buffer size */
#define LPUART4_BACKGROUND_BUFFER_SIZE 64
/* LPUART4 interrupt vector ID (number). */
#define LPUART4_IRQN LPUART4_IRQn
/* LPUART4 interrupt vector priority. */
#define LPUART4_IRQ_PRIORITY 5
/* BOARD_InitPeripherals defines for LPI2C3 */
/* Definition of peripheral ID */
#define LPI2C3_PERIPHERAL LPI2C3
/* Definition of clock source */
#define LPI2C3_CLOCK_FREQ 60000000UL
/* Transfer buffer size */
#define LPI2C3_MASTER_BUFFER_SIZE 32
/* Definition of slave address */
#define LPI2C3_MASTER_SLAVE_ADDRESS 0
/* BOARD_InitPeripherals defines for LPSPI1 */
/* Definition of peripheral ID */
#define LPSPI1_PERIPHERAL LPSPI1
/* Definition of clock source */
#define LPSPI1_CLOCK_FREQ 78545454UL
/* LPSPI1 interrupt vector ID (number). */
#define LPSPI1_IRQN LPSPI1_IRQn
/* LPSPI1 interrupt vector priority. */
#define LPSPI1_IRQ_PRIORITY 5
/* Transfer buffer size */
#define LPSPI1_BUFFER_SIZE 96
/* Definition of peripheral ID */
#define LPUART1_PERIPHERAL LPUART1
/* Definition of the backround buffer size */
#define LPUART1_BACKGROUND_BUFFER_SIZE 64
/* LPUART1 interrupt vector ID (number). */
#define LPUART1_IRQN LPUART1_IRQn
/* LPUART1 interrupt vector priority. */
#define LPUART1_IRQ_PRIORITY 5

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern const gpt_config_t GPT_config;
extern const lpi2c_master_config_t LPI2C1_masterConfig;
extern lpi2c_master_transfer_t LPI2C1_masterTransfer;
extern uint8_t LPI2C1_masterBuffer[LPI2C1_MASTER_BUFFER_SIZE];
extern lpi2c_rtos_handle_t LPI2C1_masterHandle;
extern const lpi2c_master_config_t LPI2C2_masterConfig;
extern lpi2c_master_transfer_t LPI2C2_masterTransfer;
extern uint8_t LPI2C2_masterBuffer[LPI2C2_MASTER_BUFFER_SIZE];
extern lpi2c_rtos_handle_t LPI2C2_masterHandle;
extern lpuart_rtos_handle_t LPUART3_rtos_handle;
extern lpuart_handle_t LPUART3_lpuart_handle;
extern lpuart_rtos_config_t LPUART3_rtos_config;
extern lpuart_rtos_handle_t LPUART4_rtos_handle;
extern lpuart_handle_t LPUART4_lpuart_handle;
extern lpuart_rtos_config_t LPUART4_rtos_config;
extern const lpi2c_master_config_t LPI2C3_masterConfig;
extern lpi2c_master_transfer_t LPI2C3_masterTransfer;
extern uint8_t LPI2C3_masterBuffer[LPI2C3_MASTER_BUFFER_SIZE];
extern lpi2c_rtos_handle_t LPI2C3_masterHandle;
extern const lpspi_master_config_t LPSPI1_config;
extern lpspi_transfer_t LPSPI1_transfer;
extern lpspi_rtos_handle_t LPSPI1_handle;
extern uint8_t LPSPI1_txBuffer[LPSPI1_BUFFER_SIZE];
extern uint8_t LPSPI1_rxBuffer[LPSPI1_BUFFER_SIZE];
extern lpuart_rtos_handle_t LPUART1_rtos_handle;
extern lpuart_handle_t LPUART1_lpuart_handle;
extern lpuart_rtos_config_t LPUART1_rtos_config;

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/

void BOARD_InitPeripherals(void);

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */
