/*
 * cdh_prototype.h
 *
 *  Created on: May 16, 2022
 *      Author: jaeye
 */

#ifndef CDH_PROTOTYPE_H_
#define CDH_PROTOTYPE_H_

#define OBC 0
#define COM_ENABLE	0
#define COSMOS_TEST 1

/* Serial Communication Definition */
#if OBC
#define COM_RTOS_UART_HANDLE LPUART1_rtos_handle
#else // DEV BOARD
#define COM_RTOS_UART_HANDLE LPUART3_rtos_handle
#endif



#endif /* CDH_PROTOTYPE_H_ */
