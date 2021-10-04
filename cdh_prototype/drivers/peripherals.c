
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
#include "semc_sdram.h"

/*
 *
 * UART 2
 *
 */


uint8_t background_buffer[32];

lpuart_rtos_handle_t uart2_handle;
struct _lpuart_handle uart2_t_handle;

lpuart_rtos_config_t lpuart2_config = {
    .baudrate    = 115200,
    .parity      = kLPUART_ParityDisabled,
    .stopbits    = kLPUART_OneStopBit,
    .buffer      = background_buffer,
    .buffer_size = sizeof(background_buffer),
};


static void LPUART2_init(void) {
    NVIC_SetPriority(LPUART2_IRQn, 3);
    lpuart2_config.srcclk = BOARD_DebugConsoleSrcFreq();
	lpuart2_config.base   = LPUART2;
    if (kStatus_Success != LPUART_RTOS_Init(&uart2_handle, &uart2_t_handle, &lpuart2_config))
    {
        PRINTF("LPUART2 Init Failed");
    }
}

/*
 *
 * SPI 1
 *
 */


#define TRANSFER_SIZE     (512U)    /*! Transfer dataSize.*/
#define TRANSFER_BAUDRATE (500000UL) /*! Transfer baudrate - 500k */
#define LPSPI_CLOCK_SOURCE_SELECT (1U)
#define LPSPI_CLOCK_SOURCE_DIVIDER (7U)
#define LPSPI_CLOCK_FREQ (CLOCK_GetFreq(kCLOCK_Usb1PllPfd0Clk) / (LPSPI_CLOCK_SOURCE_DIVIDER + 1U))

//#define LPSPI_MASTER_PCS_FOR_INIT     (kLPSPI_Pcs3)
//#define LPSPI_MASTER_PCS_FOR_TRANSFER (kLPSPI_MasterPcs3)

uint8_t masterReceiveBuffer[TRANSFER_SIZE] = {0};
uint8_t masterSendBuffer[TRANSFER_SIZE]    = {0};
uint8_t slaveSendBuffer[TRANSFER_SIZE] = {0};

lpspi_rtos_handle_t spi_m_rwa_handle;
lpspi_master_config_t spi_master_rwa_config;

static void LPSPI_RWA_init(void) {

	LPSPI_MasterGetDefaultConfig(&spi_master_rwa_config);

	spi_master_rwa_config.baudRate                      = TRANSFER_BAUDRATE;
	spi_master_rwa_config.bitsPerFrame                  = 8U;
	spi_master_rwa_config.cpol                          = kLPSPI_ClockPolarityActiveHigh;
	spi_master_rwa_config.cpha                          = kLPSPI_ClockPhaseFirstEdge;
	spi_master_rwa_config.direction                     = kLPSPI_MsbFirst;
	spi_master_rwa_config.pcsToSckDelayInNanoSec        = 1000U;
	spi_master_rwa_config.lastSckToPcsDelayInNanoSec    = 1000U;
	spi_master_rwa_config.betweenTransferDelayInNanoSec = 1000U;
	spi_master_rwa_config.whichPcs                      = kLPSPI_Pcs3;
	spi_master_rwa_config.pcsActiveHighOrLow            = kLPSPI_PcsActiveLow;
	spi_master_rwa_config.pinCfg                        = kLPSPI_SdiInSdoOut;
	spi_master_rwa_config.dataOutConfig                 = kLpspiDataOutRetained;

	uint32_t sourceClock;

	sourceClock = LPSPI_CLOCK_FREQ;
	if(kStatus_Success != LPSPI_RTOS_Init(&spi_m_rwa_handle, LPSPI1, &spi_master_rwa_config, sourceClock)) {
		PRINTF("SPI Master initialization failed! \r\n");
	}
}

//SPI transfer lpspi_master_config_t config
void SPI_transfer(uint8_t * txBuffer, uint8_t * rxBuffer, size_t transferSize, uint32_t pcsPin)
{
	lpspi_transfer_t masterXfer;
	status_t status;

	//Start master transfer
	masterXfer.txData      = txBuffer;
	masterXfer.rxData      = rxBuffer;
	masterXfer.dataSize    = transferSize;

	GPIO_PortToggle(GPIO1, 1U << pcsPin);
	status = LPSPI_RTOS_Transfer(&spi_m_rwa_handle, &masterXfer);
	GPIO_PortToggle(GPIO1, 1U << pcsPin);

	if (status == kStatus_Success)
	{
		PRINTF("LPSPI master transfer completed successfully.\r\n");
	}
	else
	{
		PRINTF("LPSPI master transfer completed with error.\r\n");
	}
#if SPI_TEST
	Debug_SPI_function();
#endif
}

#if SPI_TEST
void Debug_SPI_function()
{
	uint32_t errorCount;
	uint32_t i;

	PRINTF("EXPECTED: \n");
	for (i = 0; i < 16; i++)
		{
			/* Print 16 numbers in a line */
			if ((i % 0x08U) == 0U)
			{
				PRINTF("\r\n");
			}
			PRINTF(" %02X", slaveSendBuffer[i]);
		}
		PRINTF("\r\n");

		PRINTF("RECEIVED: \n");

	for (i = 0; i < 16; i++)
	{
		/* Print 16 numbers in a line */
		if ((i % 0x08U) == 0U)
		{
			PRINTF("\r\n");
		}
		PRINTF(" %02X", masterReceiveBuffer[i]);
	}
	PRINTF("\r\n");

	errorCount = 0;
	for (i = 0; i < 15; i++)
	{
		if (slaveSendBuffer[i] != masterReceiveBuffer[i+1])
		{
			errorCount++;
		}
	}

	if (errorCount == 0)
	{
		PRINTF("LPSPI transfer all data matched !\r\n");
	}
	else
	{
		PRINTF("Error occurred in LPSPI transfer !\r\n");
	}
}
#endif

/* LPI2C shared variables */

#define LPI2C_CLOCK_SOURCE_SELECT (1U)
/* Clock divider for master lpi2c clock source */
#define LPI2C_CLOCK_SOURCE_DIVIDER (5U)
/* Get frequency of lpi2c clock */
#define LPI2C_CLOCK_FREQUENCY ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (LPI2C_CLOCK_SOURCE_DIVIDER + 1U))
//#define I2C_MASTER_SLAVE_ADDR_7BIT (0x7EU)
#define I2C_BAUDRATE (100000) /* 100K */
#define I2C_DATA_LENGTH (32) /* MAX is 256 */

/* LPI2C master transfer, initial values used as place holders */

lpi2c_master_transfer_t LPI2C_masterTransfer = {
  .flags = kLPI2C_TransferDefaultFlag,
  .slaveAddress = 0x7E,
  .direction = kLPI2C_Write,
  .subaddress = 0,
  .subaddressSize = 0,
  .data = 0,
  .dataSize = I2C_DATA_LENGTH
};

/*
 *
 * I2C 1
 *
 */

uint8_t i2c1_master_buff[I2C_DATA_LENGTH];
lpi2c_rtos_handle_t LPI2C1_masterHandle;

const lpi2c_master_config_t LPI2C1_masterConfig = {
  .enableMaster = true,
  .enableDoze = true,
  .debugEnable = false,
  .ignoreAck = false,
  .pinConfig = kLPI2C_2PinOpenDrain,
  .baudRate_Hz = 100000UL,
  .busIdleTimeout_ns = 0UL,
  .pinLowTimeout_ns = 0UL,
  .sdaGlitchFilterWidth_ns = 0U,
  .sclGlitchFilterWidth_ns = 0U,
  .hostRequest = {
    .enable = false,
    .source = kLPI2C_HostRequestExternalPin,
    .polarity = kLPI2C_HostRequestPinActiveHigh
  }
};

static void LPI2C1_init(void) {
	LPI2C_RTOS_Init(&LPI2C1_masterHandle, LPI2C1, &LPI2C1_masterConfig, LPI2C_CLOCK_FREQUENCY);
}

/*
 *
 * I2C 2
 *
 */

uint8_t i2c2_master_buff[I2C_DATA_LENGTH];
lpi2c_rtos_handle_t LPI2C2_masterHandle;

const lpi2c_master_config_t LPI2C2_masterConfig = {
  .enableMaster = true,
  .enableDoze = true,
  .debugEnable = false,
  .ignoreAck = false,
  .pinConfig = kLPI2C_2PinOpenDrain,
  .baudRate_Hz = 100000UL,
  .busIdleTimeout_ns = 0UL,
  .pinLowTimeout_ns = 0UL,
  .sdaGlitchFilterWidth_ns = 0U,
  .sclGlitchFilterWidth_ns = 0U,
  .hostRequest = {
    .enable = false,
    .source = kLPI2C_HostRequestExternalPin,
    .polarity = kLPI2C_HostRequestPinActiveHigh
  }
};

static void LPI2C2_init(void) {
	LPI2C_RTOS_Init(&LPI2C2_masterHandle, LPI2C2, &LPI2C2_masterConfig, LPI2C_CLOCK_FREQUENCY);
}


/*
 *
 * I2C 3
 *
 */

uint8_t i2c3_master_buff[I2C_DATA_LENGTH];
lpi2c_rtos_handle_t LPI2C3_masterHandle;

const lpi2c_master_config_t LPI2C3_masterConfig = {
  .enableMaster = true,
  .enableDoze = true,
  .debugEnable = false,
  .ignoreAck = false,
  .pinConfig = kLPI2C_2PinOpenDrain,
  .baudRate_Hz = 100000UL,
  .busIdleTimeout_ns = 0UL,
  .pinLowTimeout_ns = 0UL,
  .sdaGlitchFilterWidth_ns = 0U,
  .sclGlitchFilterWidth_ns = 0U,
  .hostRequest = {
    .enable = false,
    .source = kLPI2C_HostRequestExternalPin,
    .polarity = kLPI2C_HostRequestPinActiveHigh
  }
};

static void LPI2C3_init(void) {
	LPI2C_RTOS_Init(&LPI2C3_masterHandle, LPI2C3, &LPI2C3_masterConfig, LPI2C_CLOCK_FREQUENCY);
}

/*
 *
 * I2C Transfer helpers
 *
 */

#define DEBUG_MODE 1

void I2C_send(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t * masterSendBuffer, size_t tx_size) {

	status_t status;

#if DEBUG_MODE
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

	LPI2C_masterTransfer.slaveAddress = slaveAddress;
	LPI2C_masterTransfer.data = masterSendBuffer;
	LPI2C_masterTransfer.direction = kLPI2C_Write;

	/* Monitor status through transfer */

	status = LPI2C_RTOS_Transfer(handle, &LPI2C_masterTransfer);
	if (status == kStatus_Success)
	{
		PRINTF("I2C master transfer completed successfully.\r\n");
	}
	else
	{
		PRINTF("I2C master transfer completed with error: %d!\r\n", status);
	}
}


void I2C_request(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t * rx_buffer, size_t rx_size) {

	status_t status;

	PRINTF("Master will request data.\r\n");

	/* Make modifications on send buffer */

	LPI2C_masterTransfer.slaveAddress = slaveAddress;
	LPI2C_masterTransfer.data = rx_buffer;
	LPI2C_masterTransfer.direction = kLPI2C_Read;

	/* Monitor status through transfer */

	status = LPI2C_RTOS_Transfer(handle, &LPI2C_masterTransfer);
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

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/

static void BOARD_InitPeripherals_CommonPostInit(void)
{
	/* Enable interrupt LPI2C1_IRQn request in the NVIC. */
	EnableIRQ(DEMO_INT_0_IRQN);
}

void BOARD_InitPeripherals(void)
{
	NVIC_SetPriority(LPSPI1_IRQn, 3);
    NVIC_SetPriority(LPUART3_IRQn, 10);

    /* Define the init structure for the output pin */
    gpio_pin_config_t pcs_config = {kGPIO_DigitalOutput, 1, kGPIO_NoIntmode};

    /* Init input switch GPIO. */
    GPIO_PinInit(GPIO1, RWA0, &pcs_config);
    GPIO_PinInit(GPIO1, RWA1, &pcs_config);
    GPIO_PinInit(GPIO1, RWA2, &pcs_config);
    GPIO_PinInit(GPIO1, RWA3, &pcs_config);

	/* Initialize components */
    BOARD_InitSEMC(); //sdram
	LPUART2_init();
	LPSPI_RWA_init(); // all three SPI

	/*Clock setting for LPI2C*/
	CLOCK_SetMux(kCLOCK_Lpi2cMux, LPI2C_CLOCK_SOURCE_SELECT);
	CLOCK_SetDiv(kCLOCK_Lpi2cDiv, LPI2C_CLOCK_SOURCE_DIVIDER);

	// Set LPI2C interrupt priority
	NVIC_SetPriority(LPI2C1_IRQn, 3);

	/* Initialize LPI2C interfaces */
	LPI2C1_init();
	LPI2C2_init();
	LPI2C3_init();

	/* Common post-initialization */
	BOARD_InitPeripherals_CommonPostInit();
}
