/*
 * com_protocol_helper.c
 *
 *  Created on: Nov 11, 2021
 *      Author: Issac
 */
#include "com_protocol_helper.h"

void I2C_send(lpi2c_rtos_handle_t * handle, lpi2c_master_transfer_t* transfer, uint16_t slaveAddress, uint8_t subAddress, uint8_t * masterSendBuffer, size_t tx_size) {

	status_t status;

#if SHOW_DATA
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

	transfer->slaveAddress = slaveAddress;
	transfer->data = masterSendBuffer;
	if (subAddress != 0) {
		transfer->subaddress = subAddress;
		transfer->subaddressSize = 8;
	} else {
		transfer->subaddress = 0;
		transfer->subaddressSize = 0;
	}
	transfer->dataSize = tx_size;
	transfer->direction = kLPI2C_Write;

	/* Monitor status through transfer */

	status = LPI2C_RTOS_Transfer(handle, transfer);
	if (status == kStatus_Success)
	{
		PRINTF("I2C master transfer completed successfully.\r\n");
	}
	else
	{
		PRINTF("I2C master transfer completed with error: %d!\r\n", status);
		if (status == 903) {
			I2C_send(handle, transfer, slaveAddress, subAddress, masterSendBuffer, tx_size);
		}
	}
}


void I2C_request(lpi2c_rtos_handle_t * handle, lpi2c_master_transfer_t* transfer, uint16_t slaveAddress, uint8_t subAddress, uint8_t * rx_buffer, size_t rx_size) {

	status_t status;
#if SHOW_DATA
	PRINTF("Master will request data.\r\n");
#endif
	/* Make modifications on send buffer */

	transfer->slaveAddress = slaveAddress;
	if (subAddress != 0) {
		transfer->subaddress = subAddress;
		transfer->subaddressSize = 8;
	} else {
		transfer->subaddress = 0;
		transfer->subaddressSize = 0;
	}
	transfer->data = rx_buffer;
	transfer->dataSize = rx_size;
	transfer->direction = kLPI2C_Read;

	/* Monitor status through transfer */

	status = LPI2C_RTOS_Transfer(handle, transfer);


	if (status == kStatus_Success)
	{
		PRINTF("I2C receive successful.\r\n");
#if SHOW_DATA
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
#endif
	}
	else {
		PRINTF("Failed receive: %d!\r\n", status);
	}


}

void SPI_GPIO_init() {
    /* Define the init structure for the output pin */
    gpio_pin_config_t pcs_config = {kGPIO_DigitalOutput, 1, kGPIO_NoIntmode};

    /* Init input switch GPIO. */
    GPIO_PinInit(GPIO1, RWA0, &pcs_config);
    GPIO_PinInit(GPIO1, RWA1, &pcs_config);
    GPIO_PinInit(GPIO1, RWA2, &pcs_config);
    GPIO_PinInit(GPIO1, RWA3, &pcs_config);
}

//SPI transfer lpspi_master_config_t config
void SPI_transfer(uint8_t * txBuffer, uint8_t * rxBuffer, size_t transferSize, uint32_t pcsPin)
{
	lpspi_transfer_t LPSPI1_config;
	status_t status;

	//Start master transfer
	LPSPI1_config.txData      = txBuffer;
	LPSPI1_config.rxData      = rxBuffer;
	LPSPI1_config.dataSize    = transferSize;

	GPIO_PortToggle(GPIO1, 1U << pcsPin);
	status = LPSPI_RTOS_Transfer(&LPSPI1_handle, &LPSPI1_config);
	GPIO_PortToggle(GPIO1, 1U << pcsPin);

	if (status == kStatus_Success)
	{
		PRINTF("LPSPI master transfer completed successfully.\r\n");
	}
	else
	{
		PRINTF("LPSPI master transfer completed with error.\r\n");
	}
}


