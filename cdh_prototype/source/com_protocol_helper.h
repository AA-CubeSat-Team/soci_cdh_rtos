/*
 * com_protocol_helper.h
 *
 *  Created on: Oct 25, 2021
 *      Author: Issac
 */
#include "peripherals.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"

#ifndef COM_PROTOCOL_HELPER_H_
#define COM_PROTOCOL_HELPER_H_

#define RWA0 9U  //PcsPin0 AD_B0_09
#define RWA1 23U //PcsPin1 AD_B1_07
#define RWA2 28U //PcsPin2 AD_B1_12
#define RWA3 29U //PcsPin3 AD_B1_13

#define SHOW_DATA 0

bool UART_send(lpuart_rtos_handle_t *handle, uint8_t *buffer, uint32_t length);
bool UART_RECEIVE(lpuart_rtos_handle_t *handle, uint8_t *buffer, uint32_t length, size_t *received);
bool I2C_send(lpi2c_rtos_handle_t * handle, lpi2c_master_transfer_t* transfer, uint16_t slaveAddress, uint8_t subAddress, uint8_t * masterSendBuffer, size_t tx_size);
bool I2C_request(lpi2c_rtos_handle_t * handle, lpi2c_master_transfer_t* transfer, uint16_t slaveAddress, uint8_t subAddress, uint8_t * rx_buffer, size_t rx_size);
void SPI_GPIO_init();
bool SPI_transfer(uint8_t * txBuffer, uint8_t * rxBuffer, size_t transferSize, uint32_t pcsPin);

#endif /* COM_PROTOCOL_HELPER_H_ */
