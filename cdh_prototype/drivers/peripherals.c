
/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include <peripherals.h>

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_gpt.h"
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


void I2C_send(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t * masterSendBuffer, size_t tx_size) {
	lpi2c_master_transfer_t masterXfer;
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
		PRINTF("0x%2x  ", tx_buffer[i]);
	}
	PRINTF("\r\n\r\n");
#endif

	memset(&masterXfer, 0, sizeof(masterXfer));
	masterXfer.slaveAddress   = slaveAddress;
	masterXfer.direction      = kLPI2C_Write;
	masterXfer.subaddress     = 0;
	masterXfer.subaddressSize = 0;
	masterXfer.data           = masterSendBuffer;
	masterXfer.dataSize       = tx_size; //generally I2C_DATA_LENGTH used
	masterXfer.flags          = kLPI2C_TransferDefaultFlag;

	status = LPI2C_RTOS_Transfer(handle, &masterXfer);
	if (status == kStatus_Success)
	{
		PRINTF("I2C master transfer completed successfully.\r\n");
	}
	else
	{
		PRINTF("I2C master transfer completed with error!\r\n");
	}
}


void I2C_request(lpi2c_rtos_handle_t * handle, uint16_t slaveAddress, uint8_t * rx_buffer, size_t rx_size) {
	lpi2c_master_transfer_t masterXfer;
	status_t status;

	PRINTF("Master will request data\r\n");

	memset(&masterXfer, 0, sizeof(masterXfer));
	masterXfer.slaveAddress   = slaveAddress;
	masterXfer.direction      = kLPI2C_Read;
	masterXfer.subaddress     = 0;
	masterXfer.subaddressSize = 0;
	masterXfer.data           = rx_buffer;
	masterXfer.dataSize       = rx_size;
	masterXfer.flags          = kLPI2C_TransferDefaultFlag;

	status = LPI2C_RTOS_Transfer(handle, &masterXfer);
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
		PRINTF("Failed receive!\r\n");
	}
}
/***********************************************************************************************************************
 * GPT initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'GPT'
- type: 'gpt'
- mode: 'general'
- type_id: 'gpt_e92a0cbd07e389b82a1d19b05eb9fdda'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'GPT2'
- config_sets:
  - fsl_gpt:
    - gpt_config:
      - clockSource: 'kGPT_ClockSource_LowFreq'
      - clockSourceFreq: 'BOARD_BootClockRUN'
      - oscDivider: '1'
      - divider: '1'
      - enableFreeRun: 'false'
      - enableRunInWait: 'true'
      - enableRunInStop: 'true'
      - enableRunInDoze: 'true'
      - enableRunInDbg: 'false'
      - enableMode: 'true'
    - input_capture_channels: []
    - output_compare_channels: []
    - interrupt_requests: ''
    - isInterruptEnabled: 'false'
    - interrupt:
      - IRQn: 'GPT2_IRQn'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - EnableTimerInInit: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const gpt_config_t DEMO_GPT_config = {.clockSource     = kGPT_ClockSource_LowFreq,
                                      .divider         = 1,
                                      .enableFreeRun   = false,
                                      .enableRunInWait = true,
                                      .enableRunInStop = true,
                                      .enableRunInDoze = true,
                                      .enableRunInDbg  = false,
                                      .enableMode      = true};

void DEMO_GPT_init(void)
{
    /* GPT device and channels initialization */
    GPT_Init(DEMO_GPT_PERIPHERAL, &DEMO_GPT_config);
    GPT_SetOscClockDivider(DEMO_GPT_PERIPHERAL, 1);
    /* Enable GPT interrupt sources */
    GPT_EnableInterrupts(DEMO_GPT_PERIPHERAL, 0);
}


/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
	/*Set clock source for LPSPI*/
	CLOCK_SetMux(kCLOCK_LpspiMux, LPSPI_CLOCK_SOURCE_SELECT);
	CLOCK_SetDiv(kCLOCK_LpspiDiv, LPSPI_CLOCK_SOURCE_DIVIDER);

	NVIC_SetPriority(LPSPI1_IRQn, 3);

    /* Define the init structure for the output pin */
    gpio_pin_config_t pcs_config = {kGPIO_DigitalOutput, 1, kGPIO_NoIntmode};
    /* Init input switch GPIO. */
    GPIO_PinInit(GPIO1, RWA0, &pcs_config);
    GPIO_PinInit(GPIO1, RWA1, &pcs_config);
    GPIO_PinInit(GPIO1, RWA2, &pcs_config);
    GPIO_PinInit(GPIO1, RWA3, &pcs_config);

	/* Initialize components */
	LPUART1_init();
	LPUART3_init();
	LPUART4_init();

	LPSPI_RWA_init();

	LPI2C1_init();
	LPI2C2_init();
	LPI2C3_init();
	DEMO_GPT_init();
}

