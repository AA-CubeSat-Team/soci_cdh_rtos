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
#include "fsl_clock.h"

#include "fsl_lpuart.h"
#include "fsl_lpuart_freertos.h"

#include "fsl_lpi2c.h"
#include "fsl_lpi2c_freertos.h"

#include "fsl_lpspi.h"
#include "fsl_lpspi_freertos.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

///***********************************************************************************************************************
// * Definitions
// **********************************************************************************************************************/
///* Definitions for BOARD_InitPeripherals functional group */
///* Definition of peripheral ID */
//#define LPUART1_PERIPHERAL LPUART1
///* Definition of the clock source frequency */
//#define LPUART1_CLOCK_SOURCE 80000000UL
///* Definition of peripheral ID */
//#define LPUART3_PERIPHERAL LPUART3
///* Definition of the clock source frequency */
//#define LPUART3_CLOCK_SOURCE 80000000UL
///* Definition of peripheral ID */
//#define LPUART4_PERIPHERAL LPUART4
///* Definition of the clock source frequency */
//#define LPUART4_CLOCK_SOURCE 80000000UL
///* BOARD_InitPeripherals defines for LPI2C2 */
///* Definition of peripheral ID */
//#define LPI2C2_PERIPHERAL LPI2C2
///* Definition of clock source */
//#define LPI2C2_CLOCK_FREQ 60000000UL
///* Transfer buffer size */
//#define LPI2C2_MASTER_BUFFER_SIZE 1
///* BOARD_InitPeripherals defines for LPI2C1 */
///* Definition of peripheral ID */
//#define LPI2C1_PERIPHERAL LPI2C1
///* Definition of clock source */
//#define LPI2C1_CLOCK_FREQ 60000000UL
///* Transfer buffer size */
//#define LPI2C1_MASTER_BUFFER_SIZE 1
///* BOARD_InitPeripherals defines for LPSPI1 */
///* Definition of peripheral ID */
//#define LPSPI1_PERIPHERAL LPSPI1
///* Definition of clock source */
//#define LPSPI1_CLOCK_FREQ 105600000UL
///* BOARD_InitPeripherals defines for LPI2C3 */
///* Definition of peripheral ID */
//#define LPI2C3_PERIPHERAL LPI2C3
///* Definition of clock source */
//#define LPI2C3_CLOCK_FREQ 60000000UL
///* Transfer buffer size */
//#define LPI2C3_MASTER_BUFFER_SIZE 1

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern lpuart_rtos_config_t lpuart1_config;
extern lpuart_rtos_config_t lpuart3_config;
extern lpuart_rtos_config_t lpuart4_config;

extern lpspi_master_config_t spiMaster_config;

extern lpi2c_master_config_t i2c1Master_config;
extern lpi2c_master_config_t i2c2Master_config;
extern lpi2c_master_config_t i2c3Master_config;

//
//
//extern const lpi2c_master_config_t LPI2C2_masterConfig;
//extern lpi2c_master_transfer_t LPI2C2_masterTransfer;
//extern uint8_t LPI2C2_masterBuffer[LPI2C2_MASTER_BUFFER_SIZE];
//extern lpi2c_master_handle_t LPI2C2_masterHandle;
//extern const lpi2c_master_config_t LPI2C1_masterConfig;
//extern lpi2c_master_transfer_t LPI2C1_masterTransfer;
//extern uint8_t LPI2C1_masterBuffer[LPI2C1_MASTER_BUFFER_SIZE];
//extern lpi2c_master_handle_t LPI2C1_masterHandle;
//extern const lpspi_master_config_t LPSPI1_config;
//extern const lpi2c_master_config_t LPI2C3_masterConfig;
//extern lpi2c_master_transfer_t LPI2C3_masterTransfer;
//extern uint8_t LPI2C3_masterBuffer[LPI2C3_MASTER_BUFFER_SIZE];
//extern lpi2c_master_handle_t LPI2C3_masterHandle;


void LPSPI1_send(uint8_t* masterSendBuffer, uint8_t* masterReceiveBuffer);

void LPI2C1_send(uint8_t slaveAddress, uint8_t* masterSendBuffer);
void LPI2C2_send(uint8_t slaveAddress, uint8_t* masterSendBuffer);
void LPI2C3_send(uint8_t slaveAddress, uint8_t* masterSendBuffer);

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void);



#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */
