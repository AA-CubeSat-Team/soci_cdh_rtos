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
#include "fsl_lpuart.h"
#include "fsl_clock.h"
#include "fsl_lpspi.h"
#include "fsl_lpi2c.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* Definition of peripheral ID */
#define LPUART8_PERIPHERAL LPUART8
/* Definition of the clock source frequency */
#define LPUART8_CLOCK_SOURCE 80000000UL
/* BOARD_InitPeripherals defines for LPSPI3 */
/* Definition of peripheral ID */
#define LPSPI3_PERIPHERAL LPSPI3
/* Definition of clock source */
#define LPSPI3_CLOCK_FREQ 105600000UL
/* LPSPI3 interrupt vector ID (number). */
#define LPSPI3_IRQN LPSPI3_IRQn
/* LPSPI3 interrupt handler identifier. */
#define LPSPI3_IRQHANDLER LPSPI3_IRQHandler
/* BOARD_InitPeripherals defines for LPI2C1 */
/* Definition of peripheral ID */
#define LPI2C1_PERIPHERAL LPI2C1
/* Definition of clock source */
#define LPI2C1_CLOCK_FREQ 60000000UL
/* Transfer buffer size */
#define LPI2C1_MASTER_BUFFER_SIZE 1
/* Definition of peripheral ID */
#define LPUART3_PERIPHERAL LPUART3
/* Definition of the clock source frequency */
#define LPUART3_CLOCK_SOURCE 80000000UL
/* BOARD_InitPeripherals defines for LPI2C3 */
/* Definition of peripheral ID */
#define LPI2C3_PERIPHERAL LPI2C3
/* Definition of clock source */
#define LPI2C3_CLOCK_FREQ 60000000UL
/* Transfer buffer size */
#define LPI2C3_MASTER_BUFFER_SIZE 1
/* Definition of peripheral ID */
#define LPUART2_PERIPHERAL LPUART2
/* Definition of the clock source frequency */
#define LPUART2_CLOCK_SOURCE 80000000UL
/* BOARD_InitPeripherals defines for LPI2C2 */
/* Definition of peripheral ID */
#define LPI2C2_PERIPHERAL LPI2C2
/* Definition of clock source */
#define LPI2C2_CLOCK_FREQ 60000000UL
/* Transfer buffer size */
#define LPI2C2_MASTER_BUFFER_SIZE 1
/* Definition of peripheral ID */
#define LPUART1_PERIPHERAL LPUART1
/* Definition of the clock source frequency */
#define LPUART1_CLOCK_SOURCE 80000000UL

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern const lpuart_config_t LPUART8_config;
extern const lpspi_master_config_t LPSPI3_config;
extern const lpi2c_master_config_t LPI2C1_masterConfig;
extern lpi2c_master_transfer_t LPI2C1_masterTransfer;
extern uint8_t LPI2C1_masterBuffer[LPI2C1_MASTER_BUFFER_SIZE];
extern lpi2c_master_handle_t LPI2C1_masterHandle;
extern const lpuart_config_t LPUART3_config;
extern const lpi2c_master_config_t LPI2C3_masterConfig;
extern lpi2c_master_transfer_t LPI2C3_masterTransfer;
extern uint8_t LPI2C3_masterBuffer[LPI2C3_MASTER_BUFFER_SIZE];
extern lpi2c_master_handle_t LPI2C3_masterHandle;
extern const lpuart_config_t LPUART2_config;
extern const lpi2c_master_config_t LPI2C2_masterConfig;
extern lpi2c_master_transfer_t LPI2C2_masterTransfer;
extern uint8_t LPI2C2_masterBuffer[LPI2C2_MASTER_BUFFER_SIZE];
extern lpi2c_master_handle_t LPI2C2_masterHandle;
extern const lpuart_config_t LPUART1_config;

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
