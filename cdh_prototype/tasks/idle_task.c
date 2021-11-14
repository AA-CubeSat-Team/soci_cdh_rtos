#include <stdbool.h>
#include "idle_task.h"
#include "eps_wrap.h"
#include "sen_wrap.h"
#include <stdint.h>
#include "peripherals.h"
#include "semc_sdram.h"
#include "fsl_semc.h"
#include "img_wrap.h"
#include "act_wrap.h"
#include "lpm.h"
#include "power_mode_switch.h"
#include "specific.h"
#include "com_protocol_helper.h"

/*******************************************************************************
 * Flags
 ******************************************************************************/
//flags for checking if it's turned on or not
bool g_mtqActive;
bool g_rwaActive;
bool g_senActive;

//flags for checking if they're healthy
bool g_obcHealthy;
bool g_epsHealthy;
bool g_comHealthy;
bool g_senHealthy;
bool g_gncHealthy;
bool g_mtqHealthy;
bool g_rwaHealthy;
bool g_imgHealthy;
//uint8_t healthFlags; //bit flags: [img|rwa|mtq|gnc|sen|com|eps|obc]

/*******************************************************************************
 * Function declarations
 ******************************************************************************/

static bool obc_healthcheck();
static void obc_reset();
static void idle_phase1();
static void setMCUPowerMode();
static void UpdateFlags();
static void idle_phase2();
static void idle_phase3();


TaskHandle_t TaskHandler_idle;
extern TaskHandle_t TaskHandler_img;
extern TaskHandle_t TaskHandler_com;

uint8_t i2c1_tx_buff[32];
uint8_t i2c1_rx_buff[32];

//
double voltage;
//

int operatingMode;

#define PDM5_MTQ  1 << (0)
#define PDM6_RWA  1 << (1)
#define PDM7_IMG  1 << (2)
#define PDM8_COM  1 << (3)
#define PDM9_SEN  1 << (4)
#define PDM_OBC  1 << (6) //TODO: do we need this?

/* health check the OBC */
static bool obc_healthcheck() {
	// TODO: Check what hardware to health check
	PRINTF("checking peripherals of obc\r\n");
	return true;
}

/* reset the OBC */
static void obc_reset(){
	// TODO: Verify how to reset OBC. By turning PDM on/off? or by software reset?
	PRINTF("Hard resetting obc\r\n");
}

/* Reset the priority of the task */
void resetPriority(TaskHandle_t handler) {
	vTaskPrioritySet(handler, 0);
}

/* Check if the task is suspended or not, if not, suspend it. */
void suspendTask (TaskHandle_t handler) {
	if (eTaskGetState(handler) != eSuspended) {
		vTaskSuspend(handler);
	}
}

/* Check if the task is suspended or not, if so, resume it. */
void resumeTask (TaskHandle_t handler) {
	if (eTaskGetState(handler) == eSuspended) {
		//TODO: check if we actually need to check the current state of the tasks
		//Also, might need to add other edge cases (ex. eRunning, eReady, eBlocked...)
		vTaskResume(handler);
	}
}

/* Step 1. Commission Phase I Checks */
static void idle_phase1() {
	PRINTF("idle: Commission Phase 1 Checks\r\n");
	while (!g_epsHealthy || !g_obcHealthy){
		g_epsHealthy = true; //eps_healthcheck(); //TODO: replace with whatever function eps is using to healthcheck
		g_obcHealthy = obc_healthcheck();
		if (!g_epsHealthy){
			//i2c_eps_manualReset();
		}
		if (!g_obcHealthy){
			obc_reset();
		}
	}

}

//extern lpm_power_mode_t s_targetPowerMode;
//extern lpm_power_mode_t s_curRunMode = LPM_PowerModeOverRun;
//
//extern const char *s_modeNames[] = {"Over RUN",    "Full Run",       "Low Speed Run", "Low Power Run",
//                                    "System Idle", "Low Power Idle", "Suspend"};

/* Set the OBC run mode - clock frequency etc. */
static void setMCUPowerMode() {
	switch(operatingMode){
		case CRIT_LOW_POWER:
			s_targetPowerMode = LPM_PowerModeLowPowerRun;
			break;

		case LOW_POWER:
			s_targetPowerMode = LPM_PowerModeLowSpeedRun;
			break;

		case NOMINAL_POWER:
			s_targetPowerMode = LPM_PowerModeOverRun;
			break;
		default:
			break;
	}
	if (s_targetPowerMode <= LPM_PowerModeEnd)
	{
		//If could not set the target power mode, loop continue.
		if (!APP_CheckPowerMode(s_curRunMode, s_targetPowerMode))
		{
			PRINTF("cannot set power mode %s \r\n", s_modeNames[s_targetPowerMode]);
		}

		if (!LPM_SetPowerMode(s_targetPowerMode))
		{
			PRINTF("Some task doesn't allow to enter mode %s\r\n", s_modeNames[s_targetPowerMode]);
		}
		else
		{
			if (s_targetPowerMode <= LPM_PowerModeRunEnd)
			{
				switch (s_targetPowerMode)
				{
					case LPM_PowerModeOverRun:
						PRINTF("Entering PowerModeOverRun MODE \n");
						LPM_OverDriveRun();
						break;
					case LPM_PowerModeFullRun:
						LPM_FullSpeedRun();
						break;
					case LPM_PowerModeLowSpeedRun:
						PRINTF("Entering PowerModeLowSpeedRun MODE \n");
						LPM_LowSpeedRun();
						break;
					case LPM_PowerModeLowPowerRun:
						PRINTF("Entering PowerModeLowPowerRun MODE \n");
						LPM_LowPowerRun();
						break;
					default:
						break;
				}
				APP_SetRunMode(s_targetPowerMode);
			}
		}
	}
}

/* Update the flags for the peripherals in GNC */
static void UpdateFlags() {
	switch(operatingMode){
		case CRIT_LOW_POWER:
			g_mtqActive = false;
			g_rwaActive = false;
			g_senActive = false;
			break;

		case LOW_POWER:
			g_mtqActive = false;
			g_rwaActive = true;
			g_senActive = true;
			break;

		case NOMINAL_POWER:
			g_mtqActive = true;
			g_rwaActive = true;
			g_senActive = true;
			break;
		default:
			break;
	}
}

/* Step 2. Get the battery voltage and decides the appropriate pdm */
static void idle_phase2() {
	/* Battery Voltage Check */
	PRINTF("idle: Get Voltage from EPS\r\n");
	// TODO: Create a task to get the voltage from EPS system through I2C Communication
	//double voltage = i2c_eps_getBatteryLevel();
	if (voltage <= 7.4 ) // CRITICALLY LOW POWER
	{
		operatingMode = CRIT_LOW_POWER;
//		i2c_eps_switchOnOffPdms(PDM_OBC);
		/*task control*/
//		suspendTask(TaskHandler_com);
//		suspendTask(TaskHandler_img);
		voltage = 8.0;
	}
	else if (voltage <= 7.9 && voltage > 7.4) // LOW POWER
	{
		operatingMode = LOW_POWER;
		//i2c_eps_switchOnOffPdms(PDM8_COM | PDM9_SEN | PDM_OBC); //not mentioned PDMs are automatically set 0 in the bits
		/*task control*/
//		suspendTask(TaskHandler_img);
//		resumeTask(TaskHandler_com);
		voltage = 8.0;
	}
	else // Normal Mode: 7.9 < voltage < 8.26
	{
		operatingMode = NOMINAL_POWER;
		//i2c_eps_switchOnOffPdms(PDM5_MTQ | PDM6_RWA | PDM7_IMG | PDM8_COM | PDM9_SEN | PDM_OBC);
//		resumeTask(TaskHandler_com);
//		resumeTask(TaskHandler_img);
		voltage = 8.0;
		//GNC task will always be active
	}
	setMCUPowerMode();
	APP_PrintRunFrequency(0);
	UpdateFlags();
}

/* Health checks subsystems */
static void idle_phase3() {
	/*
	if (operatingMode == NOMINAL_POWER)
	{
		g_comHealthy = com_healthcheck();
		g_senHealthy = sens_healthcheck();
		//g_gncHealthy = gnc_healthcheck();
		g_rwaHealthy = rwa_healthcheck();
		g_mtqHealthy = mtq_healthcheck();
		g_imgHealthy = img_healthcheck();
	}
	else if (operatingMode == LOW_POWER)
	{
		g_comHealthy = com_healthcheck();
		g_senHealthy = sens_healthcheck();
//		g_gncHealthy = gnc_healthcheck(); //what does this check?
	}
	else { //operatingMode == CRIT_LOW_POWER
		g_comHealthy = com_healthcheck();
	}*/
}
void print_buff(uint8_t* arr, int size);
/* The main operation of the idle task: */
void idle_task(void *pvParameters) {
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time
#if IDLE_ENABLE
	//TODO: (1) when booting up, only turn on PDM of GNC (i.e. CLPM mode, no subsystem should be init already).
	//			(1-1) do health checks in CLPM mode, init GNC and run GNC once.
	//		(2) in the next cycle, we go to check the voltage and determine what mode we should be in. Turn on PDMs of active subsystems
	//		(3) go into the subsystem, init them and run once?
	//			(3-1) for COM, init takes time, so just init and go do other tasks. For the rest, they can run right after init
	//		(4) normal operation

	/*initial boot-up operations, IDLE remains the highest priority*/
	operatingMode = CRIT_LOW_POWER;
    LPM_Init(s_curRunMode);
	//i2c_eps_switchOnOffPdms(PDM_OBC); //ensures only OBC is turned on, the rest are off
	idle_phase1();
	//no subsystem healthcheck in CLPM
//	vTaskSuspend(TaskHandler_com); //suspend inactive tasks in CLPM mode
//	vTaskSuspend(TaskHandler_img);
	resetPriority(TaskHandler_idle); //resetting priority of idle task to 0, now GNC(3), COM(2-suspended), IMG(1-suspended), IDLE(0)
	vTaskDelayUntil(&xLastWakeTime, xDelayms);
	voltage = 8;

	uint32_t i = 0;

	/* Set up i2c master to send data to slave */
	for (i = 0; i < 32; i++)
	{
		i2c1_tx_buff[i] = i;
	}

	//at this point, GNC will take over and run init and do main task for once, come back to IDLE to run its main task (check voltages)
	for (;;) {
		xLastWakeTime = xTaskGetTickCount(); // gets the last wake time
		idle_phase1(); //Commission Phase I Checks
		idle_phase2(); //pdm decider
		idle_phase3(); //health checks subsystem
		PRINTF ("Send I2C Data\r\n");

		/*Test code for I2C1*/

//		I2C_send(&LPI2C1_masterHandle, 0x7E, 0, i2c1_tx_buff, (32));
//		I2C_request(&LPI2C1_masterHandle, 0x7E, 0, i2c1_rx_buff, (32));

		/*Test code for I2C2*/

		I2C_send(&LPI2C2_masterHandle, &LPI2C2_masterTransfer, 0x7E, 0, i2c1_tx_buff, (32));
		I2C_request(&LPI2C2_masterHandle, &LPI2C2_masterTransfer, 0x7E, 0, i2c1_rx_buff, (32));

		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#elif IDLE_UART

	char *to_send               = "FreeRTOS LPUART driver example!\r\n";
	char *send_ring_overrun     = "\r\nRing buffer overrun!\r\n";
	char *send_hardware_overrun = "\r\nHardware buffer overrun!\r\n";
	uint8_t background_buffer[32];
	uint8_t recv_buffer[4];

    uint8_t rxbuff[4] = {0x00, 0x00, 0x00, 0x00};
    uint8_t txbuff[4] = {0xDE, 0xAD, 0xBE, 0xEF};

    //LPUART_WriteBlocking(uart3_handle, txbuff, sizeof(txbuff));

//	for (;;) {
//
//		PRINTF("Sending UART3\r\n");
//
//        LPUART_ReadBlocking(uart3_handle, rxbuff, sizeof(rxbuff));
//        PRINTF("%X, %X, %X, %X\n", rxbuff[0], rxbuff[1], rxbuff[2], rxbuff[3]);
//        LPUART_WriteBlocking(uart3_handle, txbuff, sizeof(txbuff));
//
//		LPUART_RTOS_Send(lpuart_rtos_handle_t *handle, uint8_t *buffer, uint32_t length);
//
//		vTaskDelayUntil(&xLastWakeTime, xDelayms);
//	}
//
    /* Send introduction message. */
    if (kStatus_Success != LPUART_RTOS_Send(&LPUART3_rtos_handle, (uint8_t *)to_send, strlen(to_send)))
    {
        vTaskSuspend(NULL);
    }

    int error;
    size_t n = 0;

    do
    {
        error = LPUART_RTOS_Receive(&LPUART3_rtos_handle, recv_buffer, sizeof(recv_buffer), &n);
        if (error == kStatus_LPUART_RxHardwareOverrun)
        {
            /* Notify about hardware buffer overrun */
            if (kStatus_Success !=
                LPUART_RTOS_Send(&LPUART3_rtos_handle, (uint8_t *)send_hardware_overrun, strlen(send_hardware_overrun)))
            {
                vTaskSuspend(NULL);
            }
        }
        if (error == kStatus_LPUART_RxRingBufferOverrun)
        {
            /* Notify about ring buffer overrun */
            if (kStatus_Success != LPUART_RTOS_Send(&LPUART3_rtos_handle, (uint8_t *)send_ring_overrun, strlen(send_ring_overrun)))
            {
                vTaskSuspend(NULL);
            }
        }
        if (n > 0)
        {
            /* send back the received data */
            if (kStatus_Success != LPUART_RTOS_Send(&LPUART3_rtos_handle, recv_buffer, n))
            {
                vTaskSuspend(NULL);
            }
        }
        vTaskDelayUntil(&xLastWakeTime, xDelayms);
    } while (kStatus_Success == error);


#elif IDLE_ALL
    SPI_GPIO_init();
	uint8_t spi_tx[32];
	uint8_t spi_rx[32] = {0};
    uint8_t rxbuff3[4] = {0xDE, 0xAD, 0xBE, 0xEF};
    uint8_t rxbuff4[4] = {0xDE, 0xAD, 0xBE, 0xEF};
    uint8_t txbuff[4] = {0xDE, 0xAD, 0xBE, 0xEF};
    size_t n = 4;
	uint32_t i = 0;

	/* Set up i2c master to send data to slave */
	for (i = 0; i < 32; i++)
	{
		i2c1_tx_buff[i] = i;
		spi_tx[i] = i;
	}

	//at this point, GNC will take over and run init and do main task for once, come back to IDLE to run its main task (check voltages)
	for (;;) {
		xLastWakeTime = xTaskGetTickCount(); // gets the last wake time

//		PRINTF("UART3 send and receive\n\r");
//		LPUART_RTOS_Send(&LPUART3_rtos_handle, (uint8_t *)rxbuff3, n);
//		LPUART_RTOS_Receive(&LPUART3_rtos_handle, (uint8_t *)rxbuff3, sizeof(rxbuff3), &n);


//		PRINTF("UART4 send and receive\n\r");
//		LPUART_RTOS_Send(&LPUART4_rtos_handle, (uint8_t *)rxbuff4, n);
//		LPUART_RTOS_Receive(&LPUART4_rtos_handle, rxbuff4, 4, &n);


		PRINTF("I2C1 send receive\n\r");
		I2C_send(&LPI2C1_masterHandle, &LPI2C1_masterTransfer, 0x7E, 0, i2c1_tx_buff, (32));
		I2C_request(&LPI2C1_masterHandle, &LPI2C1_masterTransfer, 0x7E, 0, i2c1_rx_buff, (32));

		PRINTF("I2C2 send receive\n\r");
		I2C_request(&LPI2C2_masterHandle, &LPI2C2_masterTransfer, 0x7E, 0, i2c1_rx_buff, (32));
		I2C_send(&LPI2C2_masterHandle, &LPI2C2_masterTransfer, 0x7E, 0, i2c1_tx_buff, (32));

		PRINTF("SPI SENDING\n\r");
		print_buff(spi_rx, 32);
		SPI_transfer(spi_tx, spi_rx, 32, RWA0);
		print_buff(spi_rx, 32);
//		SPI_transfer(spi_tx, spi_rx, 32, RWA1);
//		print_buff(spi_rx, 32);
//		SPI_transfer(spi_tx, spi_rx, 32, RWA2);
//		print_buff(spi_rx, 32);
//		SPI_transfer(spi_tx, spi_rx, 32, RWA3);
//		print_buff(spi_rx, 32);

		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}

#else
	vTaskDelayUntil(&xLastWakeTime, xDelayms);
#endif
}

void print_buff(uint8_t* arr, int size) {
	for (int i = 0; i < size; i++) {
		PRINTF("%x ", arr[i]);
	}
	PRINTF("\r\n");
}
