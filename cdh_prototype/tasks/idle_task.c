#include <stdbool.h>
#include "idle_task.h"
#include "eps_wrap.h"
#include <stdint.h>
#include "power_mode_switch.h"

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

extern lpm_power_mode_t s_targetPowerMode;
extern lpm_power_mode_t s_curRunMode;
extern const char *s_modeNames[];

/* Set the OBC run mode - clock frequency etc. */
static void setMCUPowerMode() {
	switch(operatingMode){
			case CRIT_LOW_POWER:
				s_targetPowerMode = LPM_PowerModeLowPowerRun;
				break;

			case LOW_POWER:
				s_targetPowerMode = LPM_PowerModeLowPowerRun;
				break;

			case NOMINAL_POWER:
				s_targetPowerMode = LPM_PowerModeOverRun;
				break;
			default:
				break;
		}
		if (s_targetPowerMode <= LPM_PowerModeEnd)
		{
			/* If could not set the target power mode, loop continue. */
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
							LPM_OverDriveRun();
							break;
						case LPM_PowerModeFullRun:
							LPM_FullSpeedRun();
							break;
						case LPM_PowerModeLowSpeedRun:
							LPM_LowSpeedRun();
							break;
						case LPM_PowerModeLowPowerRun:
							LPM_LowPowerRun();
							break;
						default:
							break;
					}
					APP_SetRunMode(s_targetPowerMode);
				}
			}
			LPM_SetPowerMode(s_curRunMode);
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
	double voltage = 8;//i2c_eps_getBatteryLevel();
	if (voltage <= 7.4) // CRITICALLY LOW POWER
	{
		operatingMode = CRIT_LOW_POWER;
//		i2c_eps_switchOnOffPdms(PDM_OBC);
		/*task control*/
		suspendTask(TaskHandler_com);
		suspendTask(TaskHandler_img);
		voltage = 7.8;
	}
	else if (voltage <= 7.9 && voltage > 7.4) // LOW POWER
	{
		operatingMode = LOW_POWER;
//		i2c_eps_switchOnOffPdms(PDM8_COM | PDM9_SEN | PDM_OBC); //not mentioned PDMs are automatically set 0 in the bits
		/*task control*/
		suspendTask(TaskHandler_img);
		resumeTask(TaskHandler_com);
		voltage = 8;
	}
	else // Normal Mode: 7.9 < voltage < 8.26
	{
		operatingMode = NOMINAL_POWER;
//		i2c_eps_switchOnOffPdms(PDM5_MTQ | PDM6_RWA | PDM7_IMG | PDM8_COM | PDM9_SEN | PDM_OBC);
		resumeTask(TaskHandler_com);
		resumeTask(TaskHandler_img);
		voltage = 5;
		//GNC task will always be active
	}
	UpdateFlags();
	setMCUPowerMode();
}

/* Health checks subsystems */
static void idle_phase3() {
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
	}
}

/* The main operation of the idle task: */
void idle_task(void *pvParameters) {
	//APP_ShowPowerMode(s_curRunMode);
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
	setMCUPowerMode();
	//i2c_eps_switchOnOffPdms(PDM_OBC); //ensures only OBC is turned on, the rest are off
	idle_phase1();
	PRINTF("enters critically low power operatingMode\r\n");
	//no subsystem healthcheck in CLPM
	vTaskSuspend(TaskHandler_com); //suspend inactive tasks in CLPM mode
	vTaskSuspend(TaskHandler_img);
	resetPriority(TaskHandler_idle); //resetting priority of idle task to 0, now GNC(3), COM(2-suspended), IMG(1-suspended), IDLE(0)
	vTaskDelayUntil(&xLastWakeTime, xDelayms);
	//at this point, GNC will take over and run init and do main task for once, come back to IDLE to run its main task (check voltages)
	for (;;) {
		xLastWakeTime = xTaskGetTickCount(); // gets the last wake time
		idle_phase1(); //Commission Phase I Checks
		idle_phase2(); //pdm decider
		idle_phase3(); //health checks subsystem
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#else
	vTaskDelayUntil(&xLastWakeTime, xDelayms);
#endif
}
