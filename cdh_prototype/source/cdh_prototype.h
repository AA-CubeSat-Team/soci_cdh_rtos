/*
 * cdh_prototype.h
 *
 *  Created on: May 16, 2022
 *      Author: jaeye
 */

#ifndef CDH_PROTOTYPE_H_
#define CDH_PROTOTYPE_H_

#define OBC 0			// Pin Layout | 0: Dev Board, 1: OBC

/* Serial Communication Definition */
#if OBC
#define COM_RTOS_UART_HANDLE LPUART1_rtos_handle
#else // DEV BOARD
#define COM_RTOS_UART_HANDLE LPUART3_rtos_handle
#endif


/* COM */
#define COM_ENABLE	1 	// ENABLES COM for testing
#define COSMOS_TEST 0	// ENABLES COSMOS Test
#define COM_WRAP_DEBUG 0
#define HMAC_ENABLE 1 // Enables HMAC

// TODO: Change to OBC GPIO Pin
#if OBC
#define ANTENNA_WIRE_1 23 // For OBC Board
#define ANTENNA_WIRE_2 28
#else // DEV BOARD
#define ANTENNA_WIRE_1 19 // For DEV Board
#define ANTENNA_WIRE_2 18
#endif
/*****************************************/


#endif /* CDH_PROTOTYPE_H_ */
