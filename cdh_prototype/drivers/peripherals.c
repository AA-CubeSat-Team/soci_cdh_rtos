
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

//#define uart_task_PRIORITY (configMAX_PRIORITIES - 1)

/*
 *
 * UART 1
 *
 */

lpuart_rtos_handle_t handle1;
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
	if (kStatus_Success != LPUART_RTOS_Init(&handle1, &t_handle1, &lpuart1_config))
	{
		PRINTF("UART1 initialization failed! \r\n");
	}
}


/*
 *
 * UART 3
 *
 */

lpuart_rtos_handle_t handle3;
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
	if (kStatus_Success != LPUART_RTOS_Init(&handle3, &t_handle3, &lpuart3_config))
	{
		PRINTF("UART3 initialization failed! \r\n");
	}
}

/*
 *
 * UART 4
 *
 */

lpuart_rtos_handle_t handle4;
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
	if (kStatus_Success != LPUART_RTOS_Init(&handle4, &t_handle4, &lpuart4_config))
	{
		PRINTF("UART4 initialization failed! \r\n");
	}
}




#define TRANSFER_SIZE     (512U)    /*! Transfer dataSize.*/
#define TRANSFER_BAUDRATE (500000U) /*! Transfer baudrate - 500k */
#define LPSPI_CLOCK_SOURCE_DIVIDER (7U)
#define LPSPI_CLOCK_FREQ (CLOCK_GetFreq(kCLOCK_Usb1PllPfd0Clk) / (LPSPI_CLOCK_SOURCE_DIVIDER + 1U))

#define LPSPI_MASTER_PCS_FOR_INIT     (kLPSPI_Pcs0)
#define LPSPI_MASTER_PCS_FOR_TRANSFER (kLPSPI_MasterPcs0)

uint8_t masterReceiveBuffer[TRANSFER_SIZE] = {0};
uint8_t masterSendBuffer[TRANSFER_SIZE]    = {0};

lpspi_rtos_handle_t master_rtos_handle;
lpspi_master_config_t masterConfig;

static void LPSPI1_init(void) {

	LPSPI_MasterGetDefaultConfig(&masterConfig);

	masterConfig.baudRate                      = TRANSFER_BAUDRATE;
	masterConfig.bitsPerFrame                  = 8 * TRANSFER_SIZE;
	masterConfig.cpol                          = kLPSPI_ClockPolarityActiveHigh;
	masterConfig.cpha                          = kLPSPI_ClockPhaseFirstEdge;
	masterConfig.direction                     = kLPSPI_MsbFirst;
	masterConfig.pcsToSckDelayInNanoSec        = 1000000000 / masterConfig.baudRate;
	masterConfig.lastSckToPcsDelayInNanoSec    = 1000000000 / masterConfig.baudRate;
	masterConfig.betweenTransferDelayInNanoSec = 1000000000 / masterConfig.baudRate;
	masterConfig.whichPcs                      = LPSPI_MASTER_PCS_FOR_INIT;
	masterConfig.pcsActiveHighOrLow            = kLPSPI_PcsActiveLow;
	masterConfig.pinCfg                        = kLPSPI_SdiInSdoOut;
	masterConfig.dataOutConfig                 = kLpspiDataOutRetained;

	uint32_t sourceClock;

	sourceClock = LPSPI_CLOCK_FREQ;
	if(kStatus_Success != LPSPI_RTOS_Init(&master_rtos_handle, LPSPI1, &masterConfig, sourceClock)) {
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

	status = LPSPI_RTOS_Transfer(&master_rtos_handle, &masterXfer);
	if (status == kStatus_Success)
	{
		PRINTF("LPSPI master transfer completed successfully.\r\n");
	}
	else
	{
		PRINTF("LPSPI master transfer completed with error.\r\n");
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

//  LPI2C1_init();
//  LPI2C2_init();
//  LPI2C3_init();
}

