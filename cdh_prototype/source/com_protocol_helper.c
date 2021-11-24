/*
 * com_protocol_helper.c
 *
 *  Created on: Nov 11, 2021
 *      Author: Issac
 */
#include "com_protocol_helper.h"

/*!
 * brief Perform UART send
 *
 * Wrapper for UART send function, checks that status of the send
 *
 * param handle pointer to RTOS handle for uart 1,3, and 4. Use following
 *		&LPUART1_rtos_handle
 *		&LPUART2_rtos_handle
 *		&LPUART3_rtos_handle
 * param buffer pointer to the buffer array
 * param length number of bytes to send, default should be size of the buffer.
 * return false if send was not successful.
 */
bool UART_send(lpuart_rtos_handle_t *handle, uint8_t *buffer, uint32_t length) {
	return  (kStatus_Success == LPUART_RTOS_Send(handle, buffer, length));
}


/*!
 * brief Perform UART receive
 *
 * Wrapper for UART receive function, checks that status of the receive
 *
 * param handle pointer to RTOS handle for uart 1,3, and 4. Use following
 *		&LPUART1_rtos_handle
 *		&LPUART2_rtos_handle
 *		&LPUART3_rtos_handle
 * param *buffer pointer to the buffer array
 * param length number of bytes to send, default should be size of the buffer.
 * Param received number of bytes received, passed by reference, method will modify this value.
 * return false if receive was not successful.
 */
bool UART_receive(lpuart_rtos_handle_t *handle, uint8_t *buffer, uint32_t length, size_t *received) {
	status_t error = LPUART_RTOS_Receive(handle, buffer, length, received);
    if (error == kStatus_LPUART_RxHardwareOverrun)
    {
        /* Notify about hardware buffer overrun */
    	PRINTF("UART hardware buffer overrun\n\r");
    }
    if (error == kStatus_LPUART_RxRingBufferOverrun)
    {
        /* Notify about ring buffer overrun */
    	PRINTF("UART ring buffer overrun\n\r");
    }
    return error == kStatus_Success;
}


/*!
 * brief Performs I2C send.
 *
 * Wrapper function for RTOS I2C send function, checks the
 *
 * param handle The RTOS LPI2C handle. Use following
 * 		&LPI2C1_masterHandle
 * 		&LPI2C2_masterHandle
 * 		&LPI2C3_masterHandle
 * param transfer Structure specifying the transfer parameters. Use following
 * 		&LPI2C1_masterTransfer
 * 		&LPI2C2_masterTransfer
 * 		&LPI2C3_masterTransfer
 * param slaveAddress 15bit slave addr
 * param subAddress 8bit slave sub addr
 * param masterSendBuffer pointer to the buffer arr
 * param tx_size number of btyes to send
 * return operation successful or not.
 */
bool I2C_send(lpi2c_rtos_handle_t * handle, lpi2c_master_transfer_t* transfer, uint16_t slaveAddress, uint8_t subAddress, uint8_t * masterSendBuffer, size_t tx_size) {

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

	/* Make modifications on lpi2c_master_transfer_t  */
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
	if (status != kStatus_Success)
	{
		PRINTF("I2C master transfer completed with error: %d!\r\n", status);
		return false;
	}
	return true;
}


/*!
 * brief Performs I2C request/receive.
 *
 * Wrapper function for RTOS I2C request/receive function, checks the
 *
 * param handle The RTOS LPI2C handle. Use following
 * 		&LPI2C1_masterHandle
 * 		&LPI2C2_masterHandle
 * 		&LPI2C3_masterHandle
 * param transfer Structure specifying the transfer parameters. Use following
 * 		&LPI2C1_masterTransfer
 * 		&LPI2C2_masterTransfer
 * 		&LPI2C3_masterTransfer
 * param slaveAddress 15bit slave addr
 * param subAddress 8bit slave sub addr
 * param rx_buffer pointer to the buffer arr
 * param rx_size number of btyes to receive
 * return operation successful or not.
 */
bool I2C_request(lpi2c_rtos_handle_t * handle, lpi2c_master_transfer_t* transfer, uint16_t slaveAddress, uint8_t subAddress, uint8_t * rx_buffer, size_t rx_size) {

	status_t status;
#if SHOW_DATA
	PRINTF("Master will request data.\r\n");
#endif

	/* Make modifications on lpi2c_master_transfer_t */
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
	if (status != kStatus_Success)
	{
		PRINTF("Failed receive: %d!\r\n", status);
		return false;
	}
	else {
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
	return true;
}


/*!
 * brief Initialize GPIO pins for SPI chip select
 */
void SPI_GPIO_init() {
    /* Define the init structure for the output pin */
    gpio_pin_config_t pcs_config = {kGPIO_DigitalOutput, 1, kGPIO_NoIntmode};

    /* Init input switch GPIO. */
    GPIO_PinInit(GPIO1, RWA0, &pcs_config);
    GPIO_PinInit(GPIO1, RWA1, &pcs_config);
    GPIO_PinInit(GPIO1, RWA2, &pcs_config);
    GPIO_PinInit(GPIO1, RWA3, &pcs_config);
}

/*!
 * brief SPI send and receive
 *
 * SPI transfer lpspi_master_config_t config
 *
 * param txBuffer pointer to tx buffer array.
 * param rxBuffer pointer to rx buffer array.
 * param transferSize number of bytes to send and receive
 * Param pcsPin chip select pin. Use following
 * 		RWA0
 * 		RWA1
 * 		RWA2
 * 		RWA3
 * return false if receive was not successful.
 */
bool SPI_transfer(uint8_t * txBuffer, uint8_t * rxBuffer, size_t transferSize, uint32_t pcsPin)
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

	if (status != kStatus_Success)
	{
		PRINTF("LPSPI master transfer completed with error.\r\n");
	}

	return (status == kStatus_Success);
}

bool UART_test(lpuart_rtos_handle_t LPUART_rtos_handle, int * messageSize)
{
	char *send_ring_overrun     = "\r\nRing buffer overrun!\r\n";
	char *send_hardware_overrun = "\r\nHardware buffer overrun!\r\n";
	uint8_t recv_buffer[*messageSize];

	char to_send[*messageSize];
	for(int i = 0; i < *messageSize; i++) {
		to_send[i] = i;
	}

	/* Send introduction message. */
	if (kStatus_Success != LPUART_RTOS_Send(&LPUART_rtos_handle, (uint8_t *)to_send, strlen(to_send)))
	{
		vTaskSuspend(NULL);
	}

	int error;
	size_t n = 0;

	error = LPUART_RTOS_Receive(&LPUART_rtos_handle, recv_buffer, sizeof(recv_buffer), &n);
	if (error == kStatus_LPUART_RxHardwareOverrun)
	{
		/* Notify about hardware buffer overrun */
		if (kStatus_Success !=
			LPUART_RTOS_Send(&LPUART_rtos_handle, (uint8_t *)send_hardware_overrun, strlen(send_hardware_overrun)))
		{
			vTaskSuspend(NULL);
		}
	}
	if (error == kStatus_LPUART_RxRingBufferOverrun)
	{
		/* Notify about ring buffer overrun */
		if (kStatus_Success != LPUART_RTOS_Send(&LPUART_rtos_handle, (uint8_t *)send_ring_overrun, strlen(send_ring_overrun)))
		{
			vTaskSuspend(NULL);
		}
	}
	if (n > 0)
	{
		/* send back the received data */
		if (kStatus_Success != LPUART_RTOS_Send(&LPUART_rtos_handle, recv_buffer, n))
		{
			vTaskSuspend(NULL);
		}
	}
	for(int i = 0; i < *messageSize; i++) {
		if(to_send[i] != recv_buffer[i]) {
			return false;
		}
	}
	return true;
}

bool I2C_test(int * handlerNum)
{
	uint8_t i2c_tx_buff[32];
	uint8_t i2c_rx_buff[32];

	for(int i = 0; i < 32; i++) {
		i2c_tx_buff[i] = i;
	}
	if(*handlerNum == 1) {
		I2C_send(&LPI2C1_masterHandle, &LPI2C1_masterTransfer, 0x7E, 0, i2c_tx_buff, (32));
		I2C_request(&LPI2C1_masterHandle, &LPI2C1_masterTransfer, 0x7E, 0, i2c_rx_buff, (32));
	} else if(*handlerNum == 2) {
		I2C_request(&LPI2C2_masterHandle, &LPI2C2_masterTransfer, 0x7E, 0, i2c_rx_buff, (32));
		I2C_send(&LPI2C2_masterHandle, &LPI2C2_masterTransfer, 0x7E, 0, i2c_tx_buff, (32));
	}
	for(int i = 0; i < 32; i++) {
		if(i2c_tx_buff[i] != i2c_tx_buff[i]) {
			return false;
		}
	}
	return true;
}

bool SPI_test(int * RWA_num) {
	uint8_t masterSendBuffer[32];
	uint8_t masterReceiveBuffer[32];
	if(*RWA_num == 1) {
		return SPI_transfer(masterSendBuffer, masterReceiveBuffer, 32, RWA0);
	} else if(*RWA_num == 2) {
		return SPI_transfer(masterSendBuffer, masterReceiveBuffer, 32, RWA1);
	} else if(*RWA_num == 3) {
		return SPI_transfer(masterSendBuffer, masterReceiveBuffer, 32, RWA2);
	} else if(*RWA_num == 4) {
		return SPI_transfer(masterSendBuffer, masterReceiveBuffer, 32, RWA3);
	}
	return false;
}

