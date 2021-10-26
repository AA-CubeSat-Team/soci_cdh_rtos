/*
 * com_protocol_helper.h
 *
 *  Created on: Oct 25, 2021
 *      Author: Issac
 */
#include "peripherals.h"

#ifndef COM_PROTOCOL_HELPER_H_
#define COM_PROTOCOL_HELPER_H_

void I2C_send(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t subAddress, uint8_t * masterSendBuffer, size_t tx_size) {

	status_t status;

#if 1
	PRINTF("I2C - master will send data :");
	int i=0;
	for (i = 0; i < tx_size; i++)
	{
		if (i % 8 == 0)
		{
			PRINTF("\r\n");
		}
		PRINTF("0x%2x  ", masterSendBuffer[i]);
	}
	PRINTF("\r\n\r\n");
#endif

	/* Make modifications on send buffer */

	LPI2C1_masterTransfer.slaveAddress = slaveAddress;
	LPI2C1_masterTransfer.data = masterSendBuffer;
	if (subAddress != 0) {
		LPI2C1_masterTransfer.subaddress = subAddress;
		LPI2C1_masterTransfer.subaddressSize = 8;
	} else {
		LPI2C1_masterTransfer.subaddress = 0;
		LPI2C1_masterTransfer.subaddressSize = 0;
	}
	LPI2C1_masterTransfer.dataSize = tx_size;
	LPI2C1_masterTransfer.direction = kLPI2C_Write;

	/* Monitor status through transfer */

	status = LPI2C_RTOS_Transfer(handle, &LPI2C1_masterTransfer);
	if (status == kStatus_Success)
	{
		PRINTF("I2C master transfer completed successfully.\r\n");
	}
	else
	{
		PRINTF("I2C master transfer completed with error: %d!\r\n", status);
		if (status == 903) {
			I2C_send(handle, slaveAddress, subAddress, masterSendBuffer, tx_size);
		}
	}
}


void I2C_request(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t subAddress, uint8_t * rx_buffer, size_t rx_size) {

	status_t status;

	PRINTF("Master will request data.\r\n");

	/* Make modifications on send buffer */

	LPI2C1_masterTransfer.slaveAddress = slaveAddress;
	if (subAddress != 0) {
		LPI2C1_masterTransfer.subaddress = subAddress;
		LPI2C1_masterTransfer.subaddressSize = 8;
	} else {
		LPI2C1_masterTransfer.subaddress = 0;
		LPI2C1_masterTransfer.subaddressSize = 0;
	}
	LPI2C1_masterTransfer.data = rx_buffer;
	LPI2C1_masterTransfer.dataSize = rx_size;
	LPI2C1_masterTransfer.direction = kLPI2C_Read;

	/* Monitor status through transfer */

	status = LPI2C_RTOS_Transfer(handle, &LPI2C1_masterTransfer);
	if (status == kStatus_Success)
	{
		PRINTF("Received data :\r\n");
		int i;
		for (i = 0; i < rx_size; i++)
		{
			if (i % 8 == 0)
			{
				PRINTF("\r\n");
			}
			PRINTF("0x%2x  ", rx_buffer[i]);
		}
		PRINTF("\r\n\r\n");
	}
	else {
		PRINTF("Failed receive: %d!\r\n", status);
	}
}

#endif /* COM_PROTOCOL_HELPER_H_ */
