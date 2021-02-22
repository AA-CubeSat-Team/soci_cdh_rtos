
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

lpspi_rtos_handle_t spi_m_rtos_handle;
lpspi_master_config_t spi_master_config;

static void LPSPI1_init(void) {

	LPSPI_MasterGetDefaultConfig(&spi_master_config);

	spi_master_config.baudRate                      = TRANSFER_BAUDRATE;
	spi_master_config.bitsPerFrame                  = 8 * TRANSFER_SIZE;
	spi_master_config.cpol                          = kLPSPI_ClockPolarityActiveHigh;
	spi_master_config.cpha                          = kLPSPI_ClockPhaseFirstEdge;
	spi_master_config.direction                     = kLPSPI_MsbFirst;
	spi_master_config.pcsToSckDelayInNanoSec        = 1000000000 / spi_master_config.baudRate;
	spi_master_config.lastSckToPcsDelayInNanoSec    = 1000000000 / spi_master_config.baudRate;
	spi_master_config.betweenTransferDelayInNanoSec = 1000000000 / spi_master_config.baudRate;
	spi_master_config.whichPcs                      = LPSPI_MASTER_PCS_FOR_INIT;
	spi_master_config.pcsActiveHighOrLow            = kLPSPI_PcsActiveLow;
	spi_master_config.pinCfg                        = kLPSPI_SdiInSdoOut;
	spi_master_config.dataOutConfig                 = kLpspiDataOutRetained;

	uint32_t sourceClock;

	sourceClock = LPSPI_CLOCK_FREQ;
	if(kStatus_Success != LPSPI_RTOS_Init(&spi_m_rtos_handle, LPSPI1, &spi_master_config, sourceClock)) {
		PRINTF("SPI Master initialization failed! \r\n");
	}
}

void LPSPI1_send(uint8_t* masterSendBuffer, uint8_t* masterReceiveBuffer) {
	lpspi_transfer_t masterXfer;
	status_t status;

	/*Start master transfer*/
	masterXfer.txData      = masterSendBuffer;
	masterXfer.rxData      = masterReceiveBuffer;
	masterXfer.dataSize    = TRANSFER_SIZE; //do we need this as a parameter?
	masterXfer.configFlags = LPSPI_MASTER_PCS_FOR_TRANSFER | kLPSPI_MasterPcsContinuous | kLPSPI_SlaveByteSwap;

	status = LPSPI_RTOS_Transfer(&spi_m_rtos_handle, &masterXfer);
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
	if(kStatus_Success == LPI2C_RTOS_Init(&i2c1_m_rtos_handle, (LPI2C_Type *)LPI2C1_BASE, &i2c1_master_config, LPI2C_CLOCK_FREQUENCY))
    {
		PRINTF("I2C1 Master initialization failed! \r\n");
    }
}


void LPI2C1_send_receive(uint8_t slaveAddress, uint8_t* masterSendBuffer, size_t sendDataSize, uint32_t * masterRecvBuffer, size_t * recvDataSize) { //need to pass length as well?
	// might want to change uint32_t * masterRecvBuffer to uint8_t * masterRecvBuffer

	lpi2c_master_transfer_t masterXfer;
	status_t status;

	memset(&masterXfer, 0, sizeof(masterXfer));
	masterXfer.slaveAddress   = slaveAddress;
	masterXfer.direction      = kLPI2C_Write;
	masterXfer.subaddress     = 0;
	masterXfer.subaddressSize = 0;
	masterXfer.data           = masterSendBuffer;
	masterXfer.dataSize       = I2C_DATA_LENGTH;
	masterXfer.flags          = kLPI2C_TransferDefaultFlag;

	status = LPI2C_RTOS_Transfer(&i2c1_m_rtos_handle, &masterXfer);
	if (status == kStatus_Success)
	{
//#if (EXAMPLE_CONNECT_I2C == BOARD_TO_BOARD)
//		xSemaphoreGive(lpi2c_sem);
//#endif
		PRINTF("I2C master transfer completed successfully.\r\n");
	}
	else
	{
		PRINTF("I2C master transfer completed with error!\r\n");
	}
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
	if(kStatus_Success == LPI2C_RTOS_Init(&i2c2_m_rtos_handle, (LPI2C_Type *)LPI2C2_BASE, &i2c2_master_config, LPI2C_CLOCK_FREQUENCY))
    {
		PRINTF("I2C1 Master initialization failed! \r\n");
    }
}


void LPI2C2_send(uint8_t slaveAddress, uint8_t* masterSendBuffer, size_t dataSize) { //need to pass length as well?
	lpi2c_master_transfer_t masterXfer;
	status_t status;

	memset(&masterXfer, 0, sizeof(masterXfer));
	masterXfer.slaveAddress   = slaveAddress;
	masterXfer.direction      = kLPI2C_Write;
	masterXfer.subaddress     = 0;
	masterXfer.subaddressSize = 0;
	masterXfer.data           = masterSendBuffer;
	masterXfer.dataSize       = I2C_DATA_LENGTH; // use dataSize?
	masterXfer.flags          = kLPI2C_TransferDefaultFlag;

	status = LPI2C_RTOS_Transfer(&i2c2_m_rtos_handle, &masterXfer);
	if (status == kStatus_Success)
	{
//#if (EXAMPLE_CONNECT_I2C == BOARD_TO_BOARD)
//		xSemaphoreGive(lpi2c_sem);
//#endif
		PRINTF("I2C master transfer completed successfully.\r\n");
	}
	else
	{
		PRINTF("I2C master transfer completed with error!\r\n");
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
	if(kStatus_Success == LPI2C_RTOS_Init(&i2c1_m_rtos_handle, (LPI2C_Type *)LPI2C3_BASE, &i2c3_master_config, LPI2C_CLOCK_FREQUENCY))
    {
		PRINTF("I2C1 Master initialization failed! \r\n");
    }
}


void LPI2C3_send(uint8_t slaveAddress, uint8_t* masterSendBuffer, size_t dataSize) { //need to pass length as well?
	lpi2c_master_transfer_t masterXfer;
	status_t status;

	memset(&masterXfer, 0, sizeof(masterXfer));
	masterXfer.slaveAddress   = slaveAddress;
	masterXfer.direction      = kLPI2C_Write;
	masterXfer.subaddress     = 0;
	masterXfer.subaddressSize = 0;
	masterXfer.data           = masterSendBuffer;
	masterXfer.dataSize       = I2C_DATA_LENGTH;
	masterXfer.flags          = kLPI2C_TransferDefaultFlag;

	status = LPI2C_RTOS_Transfer(&i2c3_m_rtos_handle, &masterXfer);
	if (status == kStatus_Success)
	{
//#if (EXAMPLE_CONNECT_I2C == BOARD_TO_BOARD)
//		xSemaphoreGive(lpi2c_sem);
//#endif
		PRINTF("I2C master transfer completed successfully.\r\n");
	}
	else
	{
		PRINTF("I2C master transfer completed with error!\r\n");
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

  LPSPI1_init();

  LPI2C1_init();
  LPI2C2_init();
  LPI2C3_init();
}

