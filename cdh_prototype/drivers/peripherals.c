
/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include <peripherals.h>

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"

#include "fsl_lpuart.h"
#include "fsl_lpspi.h"
#include "fsl_lpi2c.h"

//#define uart_task_PRIORITY (configMAX_PRIORITIES - 1)

/*
 *
 * UART 1
 *
 */

// TODO: Implement queues for each peripheral (for UART only?) !
// Timer -> check all peripherals and update corresponding queues (

lpuart_rtos_handle_t uart1_handle;
struct _lpuart_handle t_handle1;
uint8_t background_buffer1[32];
uint8_t recv_buffer1[4];

lpuart_rtos_config_t lpuart1_config = { // TODO: should we make these const?
    .baudrate    = 115200,
    .parity      = kLPUART_ParityDisabled,
    .stopbits    = kLPUART_OneStopBit,
    .buffer      = background_buffer1,
    .buffer_size = sizeof(background_buffer1),
	.base        = LPUART1,
};


static void LPUART1_init(void) {
	//NVIC_SetPriority(LPUART1_IRQn, 5);
	lpuart1_config.srcclk = BOARD_DebugConsoleSrcFreq();
	if (kStatus_Success != LPUART_RTOS_Init(&uart1_handle, &t_handle1, &lpuart1_config))
	{
		PRINTF("UART1 initialization failed! \r\n");
	}
}

/*
 * if we want to implement queues for reading from uart
 *
 * static QueueHandle_t uartRxQueue;
 *
 * uartRxQueue = xQueueCreate(QUEUE_LEN, sizeof(char));
 * configASSERT(uartRxQueue);
 *
 * error = LPUART_RTOS_Receive(&handle3, recv_buffer3, sizeof(recv_buffer3), &n);
 *
 * xQueueSendToBack(uartRxQueue, recv_buffer3, xBlockTime)
 *
 *
 * whereever we want to read from uart,
 *
 * xQueueReceive(uartRxQueue, &in, xBlockTime);
 *
 * instead of
 *
 * LPUART_RTOS_Receive(&uart3_handle, recv_buffer, sizeof(recv_buffer), &n);
 *
 *
 *
 * this portion should be protected : disableInterrupts (not sure if this prevents task switch) or something else to pause scheduler
 */



/*
 *
 * UART 3
 *
 */

lpuart_rtos_handle_t uart3_handle;
struct _lpuart_handle t_handle3;
uint8_t background_buffer3[32];
uint8_t recv_buffer3[4];

lpuart_rtos_config_t lpuart3_config = {
    .baudrate    = 115200,
    .parity      = kLPUART_ParityDisabled,
    .stopbits    = kLPUART_OneStopBit,
    .buffer      = background_buffer3,
    .buffer_size = sizeof(background_buffer3),
	.base        = LPUART3,
};


static void LPUART3_init(void) {
	lpuart3_config.srcclk = BOARD_DebugConsoleSrcFreq();
	if (kStatus_Success != LPUART_RTOS_Init(&uart3_handle, &t_handle3, &lpuart3_config))
	{
		PRINTF("UART3 initialization failed! \r\n");
	}
}

/*
 *
 * UART 4
 *
 */

lpuart_rtos_handle_t uart4_handle;
struct _lpuart_handle t_handle4;
uint8_t background_buffer4[32];
uint8_t recv_buffer4[4];

lpuart_rtos_config_t lpuart4_config = {
    .baudrate    = 115200,
    .parity      = kLPUART_ParityDisabled,
    .stopbits    = kLPUART_OneStopBit,
    .buffer      = background_buffer4,
    .buffer_size = sizeof(background_buffer4),
	.base        = LPUART4,
};



static void LPUART4_init(void) {
	lpuart4_config.srcclk = BOARD_DebugConsoleSrcFreq();
	if (kStatus_Success != LPUART_RTOS_Init(&uart4_handle, &t_handle4, &lpuart4_config))
	{
		PRINTF("UART4 initialization failed! \r\n");
	}
}


/*
 *
 * SPI 1
 *
 */


#define TRANSFER_SIZE     (512U)    /*! Transfer dataSize.*/
#define TRANSFER_BAUDRATE (500000U) /*! Transfer baudrate - 500k */
#define LPSPI_CLOCK_SOURCE_DIVIDER (7U)
#define LPSPI_CLOCK_FREQ (CLOCK_GetFreq(kCLOCK_Usb1PllPfd0Clk) / (LPSPI_CLOCK_SOURCE_DIVIDER + 1U))

#define LPSPI_MASTER_PCS_FOR_INIT     (kLPSPI_Pcs0)
#define LPSPI_MASTER_PCS_FOR_TRANSFER (kLPSPI_MasterPcs0)

uint8_t masterReceiveBuffer[TRANSFER_SIZE] = {0};
uint8_t masterSendBuffer[TRANSFER_SIZE]    = {0};

lpspi_rtos_handle_t spi_m_rwa1_handle;
lpspi_rtos_handle_t spi_m_rwa2_handle;
lpspi_rtos_handle_t spi_m_rwa3_handle;

lpspi_master_config_t spi_master_rwa1_config;
lpspi_master_config_t spi_master_rwa2_config;
lpspi_master_config_t spi_master_rwa3_config;

static void LPSPI1_RWA1_init(void) {

	LPSPI_MasterGetDefaultConfig(&spi_master_rwa1_config);

	spi_master_rwa1_config.baudRate                      = TRANSFER_BAUDRATE;
	spi_master_rwa1_config.bitsPerFrame                  = 8 * TRANSFER_SIZE;
	spi_master_rwa1_config.cpol                          = kLPSPI_ClockPolarityActiveHigh;
	spi_master_rwa1_config.cpha                          = kLPSPI_ClockPhaseFirstEdge;
	spi_master_rwa1_config.direction                     = kLPSPI_MsbFirst;
	spi_master_rwa1_config.pcsToSckDelayInNanoSec        = 1000000000 / spi_master_rwa1_config.baudRate;
	spi_master_rwa1_config.lastSckToPcsDelayInNanoSec    = 1000000000 / spi_master_rwa1_config.baudRate;
	spi_master_rwa1_config.betweenTransferDelayInNanoSec = 1000000000 / spi_master_rwa1_config.baudRate;
	spi_master_rwa1_config.whichPcs                      = 1; //TODO: Replace with RWA1 chip select!
	spi_master_rwa1_config.pcsActiveHighOrLow            = kLPSPI_PcsActiveLow;
	spi_master_rwa1_config.pinCfg                        = kLPSPI_SdiInSdoOut;
	spi_master_rwa1_config.dataOutConfig                 = kLpspiDataOutRetained;

	uint32_t sourceClock;

	sourceClock = LPSPI_CLOCK_FREQ;
	if(kStatus_Success != LPSPI_RTOS_Init(&spi_m_rwa1_handle, LPSPI1, &spi_master_rwa1_config, sourceClock)) {
		PRINTF("SPI Master initialization failed! \r\n");
	}
}

static void LPSPI1_RWA2_init(void) {

	LPSPI_MasterGetDefaultConfig(&spi_master_rwa2_config);

	spi_master_rwa2_config.baudRate                      = TRANSFER_BAUDRATE;
	spi_master_rwa2_config.bitsPerFrame                  = 8 * TRANSFER_SIZE;
	spi_master_rwa2_config.cpol                          = kLPSPI_ClockPolarityActiveHigh;
	spi_master_rwa2_config.cpha                          = kLPSPI_ClockPhaseFirstEdge;
	spi_master_rwa2_config.direction                     = kLPSPI_MsbFirst;
	spi_master_rwa2_config.pcsToSckDelayInNanoSec        = 1000000000 / spi_master_rwa2_config.baudRate;
	spi_master_rwa2_config.lastSckToPcsDelayInNanoSec    = 1000000000 / spi_master_rwa2_config.baudRate;
	spi_master_rwa2_config.betweenTransferDelayInNanoSec = 1000000000 / spi_master_rwa2_config.baudRate;
	spi_master_rwa2_config.whichPcs                      = 2; //TODO: Replace with RWA2 chip select!
	spi_master_rwa2_config.pcsActiveHighOrLow            = kLPSPI_PcsActiveLow;
	spi_master_rwa2_config.pinCfg                        = kLPSPI_SdiInSdoOut;
	spi_master_rwa2_config.dataOutConfig                 = kLpspiDataOutRetained;

	uint32_t sourceClock;

	sourceClock = LPSPI_CLOCK_FREQ;
	if(kStatus_Success != LPSPI_RTOS_Init(&spi_m_rwa2_handle, LPSPI1, &spi_master_rwa2_config, sourceClock)) {
		PRINTF("SPI Master initialization failed! \r\n");
	}
}

static void LPSPI1_RWA3_init(void) {

	LPSPI_MasterGetDefaultConfig(&spi_master_rwa3_config);

	spi_master_rwa3_config.baudRate                      = TRANSFER_BAUDRATE;
	spi_master_rwa3_config.bitsPerFrame                  = 8 * TRANSFER_SIZE;
	spi_master_rwa3_config.cpol                          = kLPSPI_ClockPolarityActiveHigh;
	spi_master_rwa3_config.cpha                          = kLPSPI_ClockPhaseFirstEdge;
	spi_master_rwa3_config.direction                     = kLPSPI_MsbFirst;
	spi_master_rwa3_config.pcsToSckDelayInNanoSec        = 1000000000 / spi_master_rwa3_config.baudRate;
	spi_master_rwa3_config.lastSckToPcsDelayInNanoSec    = 1000000000 / spi_master_rwa3_config.baudRate;
	spi_master_rwa3_config.betweenTransferDelayInNanoSec = 1000000000 / spi_master_rwa3_config.baudRate;
	spi_master_rwa3_config.whichPcs                      = 3; //TODO: Replace with RWA3 chip select!
	spi_master_rwa3_config.pcsActiveHighOrLow            = kLPSPI_PcsActiveLow;
	spi_master_rwa3_config.pinCfg                        = kLPSPI_SdiInSdoOut;
	spi_master_rwa3_config.dataOutConfig                 = kLpspiDataOutRetained;

	uint32_t sourceClock;

	sourceClock = LPSPI_CLOCK_FREQ;
	if(kStatus_Success != LPSPI_RTOS_Init(&spi_m_rwa3_handle, LPSPI1, &spi_master_rwa3_config, sourceClock)) {
		PRINTF("SPI Master initialization failed! \r\n");
	}
}

void SPI_transfer(lpspi_rtos_handle_t * handler, uint8_t * txBuffer, uint8_t * rxBuffer, size_t transferSize)
{
	lpspi_transfer_t masterXfer;
	status_t status;

	/*Start master transfer*/
	masterXfer.txData      = txBuffer;
	masterXfer.rxData      = rxBuffer;
	masterXfer.dataSize    = transferSize;
	masterXfer.configFlags = LPSPI_MASTER_PCS_FOR_TRANSFER | kLPSPI_MasterPcsContinuous | kLPSPI_SlaveByteSwap;

	status = LPSPI_RTOS_Transfer(handler, &masterXfer);
	if (status == kStatus_Success)
	{
		PRINTF("LPSPI master transfer completed successfully.\r\n");
	}
	else
	{
		PRINTF("LPSPI master transfer completed with error.\r\n");
	}
}

/*
 *
 * I2C 1
 *
 */

#define LPI2C_CLOCK_SOURCE_SELECT (0U)
/* Clock divider for master lpi2c clock source */
#define LPI2C_CLOCK_SOURCE_DIVIDER (5U)
/* Get frequency of lpi2c clock */
#define LPI2C_CLOCK_FREQUENCY ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (LPI2C_CLOCK_SOURCE_DIVIDER + 1U))
//#define I2C_MASTER_SLAVE_ADDR_7BIT (0x7EU)
#define I2C_BAUDRATE (100000) /* 100K */
#define I2C_DATA_LENGTH (32) /* MAX is 256 */

uint8_t i2c1_master_buff[I2C_DATA_LENGTH];

lpi2c_master_config_t i2c1_master_config;
lpi2c_rtos_handle_t i2c1_m_rtos_handle;


static void LPI2C1_init(void) {

	/*
	 * masterConfig.debugEnable = false;
	 * masterConfig.ignoreAck = false;
	 * masterConfig.pinConfig = kLPI2C_2PinOpenDrain;
	 * masterConfig.baudRate_Hz = 100000U;
	 * masterConfig.busIdleTimeout_ns = 0;
	 * masterConfig.pinLowTimeout_ns = 0;
	 * masterConfig.sdaGlitchFilterWidth_ns = 0;
	 * masterConfig.sclGlitchFilterWidth_ns = 0;
	 */
	LPI2C_MasterGetDefaultConfig(&i2c1_master_config); //defined in fsl_lpi2c.c
	i2c1_master_config.baudRate_Hz = I2C_BAUDRATE;
	if(kStatus_Success != LPI2C_RTOS_Init(&i2c1_m_rtos_handle, (LPI2C_Type *)LPI2C1_BASE, &i2c1_master_config, LPI2C_CLOCK_FREQUENCY))
    {
		PRINTF("I2C1 Master initialization failed! \r\n");
    }
	//return status?
}

/*
 *
 * I2C 2
 *
 */

uint8_t i2c2_master_buff[I2C_DATA_LENGTH];

lpi2c_master_config_t i2c2_master_config;
lpi2c_rtos_handle_t i2c2_m_rtos_handle;


static void LPI2C2_init(void) {

	/*
	 * masterConfig.debugEnable = false;
	 * masterConfig.ignoreAck = false;
	 * masterConfig.pinConfig = kLPI2C_2PinOpenDrain;
	 * masterConfig.baudRate_Hz = 100000U;
	 * masterConfig.busIdleTimeout_ns = 0;
	 * masterConfig.pinLowTimeout_ns = 0;
	 * masterConfig.sdaGlitchFilterWidth_ns = 0;
	 * masterConfig.sclGlitchFilterWidth_ns = 0;
	 */
	LPI2C_MasterGetDefaultConfig(&i2c2_master_config); //defined in fsl_lpi2c.c
	i2c2_master_config.baudRate_Hz = I2C_BAUDRATE;
	if(kStatus_Success != LPI2C_RTOS_Init(&i2c2_m_rtos_handle, (LPI2C_Type *)LPI2C2_BASE, &i2c2_master_config, LPI2C_CLOCK_FREQUENCY))
    {
		PRINTF("I2C1 Master initialization failed! \r\n");
    }
}


/*
 *
 * I2C 3
 *
 */

uint8_t i2c3_master_buff[I2C_DATA_LENGTH];

lpi2c_master_config_t i2c3_master_config;
lpi2c_rtos_handle_t i2c3_m_rtos_handle;


static void LPI2C3_init(void) {

	/*
	 * masterConfig.debugEnable = false;
	 * masterConfig.ignoreAck = false;
	 * masterConfig.pinConfig = kLPI2C_2PinOpenDrain;
	 * masterConfig.baudRate_Hz = 100000U;
	 * masterConfig.busIdleTimeout_ns = 0;
	 * masterConfig.pinLowTimeout_ns = 0;
	 * masterConfig.sdaGlitchFilterWidth_ns = 0;
	 * masterConfig.sclGlitchFilterWidth_ns = 0;
	 */
	LPI2C_MasterGetDefaultConfig(&i2c3_master_config); //defined in fsl_lpi2c.c
	i2c3_master_config.baudRate_Hz = I2C_BAUDRATE;
	if(kStatus_Success != LPI2C_RTOS_Init(&i2c3_m_rtos_handle, (LPI2C_Type *)LPI2C3_BASE, &i2c3_master_config, LPI2C_CLOCK_FREQUENCY))
    {
		PRINTF("I2C1 Master initialization failed! \r\n");
    }
}


#define DEBUG_I2C_a		0
#define DEBUG_I2C_b		0
void I2C_send(lpi2c_rtos_handle_t * handle, uint16_t slave_address, uint8_t subaddress, uint8_t * tx_buffer, size_t tx_size)
{
	lpi2c_master_transfer_t masterXfer;
	status_t status;

#if DEBUG_I2C_a
	PRINTF("Master will send data :");
	int i=0;
	for (i = 0; i < tx_size; i++)
	{
		if (i % 8 == 0)
		{
			PRINTF("\r\n");
		}
		PRINTF("0x%2x  ", tx_buffer[i]);
	}
	PRINTF("\r\n\r\n");
#endif

	memset(&masterXfer, 0, sizeof(masterXfer));
	masterXfer.slaveAddress   = slave_address;
	masterXfer.direction      = kLPI2C_Write;
	masterXfer.subaddress     = ((uint32_t)subaddress);
	masterXfer.subaddressSize = 1;
	masterXfer.data           = tx_buffer;
	masterXfer.dataSize       = tx_size;
	masterXfer.flags          = kLPI2C_TransferDefaultFlag;

	status = LPI2C_RTOS_Transfer(handle, &masterXfer);

	if (status == kStatus_Success)
	{
#if DEBUG_I2C_b
		PRINTF("I2C master transfer completed successfully.\r\n");
#endif
	}
	else
	{
		PRINTF("I2C master transfer completed with ERROR!:      %d\r\n", status);

	}
}


void I2C_request(lpi2c_rtos_handle_t * handle, uint16_t slave_address, uint8_t subaddress, uint8_t * rx_buffer, size_t rx_size)
{
	lpi2c_master_transfer_t masterXfer;
	status_t status;
#if DEBUG_I2C_a
	PRINTF("Master will request data\r\n");
#endif
	memset(&masterXfer, 0, sizeof(masterXfer));
	masterXfer.slaveAddress   = slave_address;
	masterXfer.direction      = kLPI2C_Read;
	masterXfer.subaddress     = ((uint32_t)subaddress);
	if (!subaddress) {
		masterXfer.subaddressSize = 0;
	} else {
		masterXfer.subaddressSize = 1;
	}
	masterXfer.data           = rx_buffer;
	masterXfer.dataSize       = rx_size;
	masterXfer.flags          = kLPI2C_TransferDefaultFlag;

	status = LPI2C_RTOS_Transfer(handle, &masterXfer);

	if (status == kStatus_Success)
	{
#if DEBUG_I2C_b
		PRINTF("Received data :\r\n");
		int i;
		for (i = 0; i < rx_size; i++)
		{
			if (i % 8 == 0)
			{
				PRINTF("\r\n");
			}
			PRINTF("0x%2x  ", (rx_buffer)[i]);
		}
		PRINTF("\r\n\r\n");
#endif
	}
	else {
		PRINTF("Failed receive!:      %d\r\n", status);
	}

}
/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  LPUART1_init();
  LPUART3_init();
  LPUART4_init();

  LPSPI1_RWA1_init();
  LPSPI1_RWA2_init();
  LPSPI1_RWA3_init();

  LPI2C1_init();
  LPI2C2_init();
  LPI2C3_init();
}

