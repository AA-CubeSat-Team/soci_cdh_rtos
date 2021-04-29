#include <stdbool.h>
#include "idle_task.h"
#include "eps_wrap.h"

/*******************************************************************************
 * Flags
 ******************************************************************************/
//flags for checking if it's turned on or not
bool g_sunSensActive;
bool g_rwaSensActive;
bool g_magSensActive;
bool g_mtqSensActive;
bool g_phdSensActive;
//flags for checking if they're healthy
bool g_epsHealthy;
bool g_obcHealthy;
bool g_comHealthy;
bool g_senHealthy;
bool g_gncHealthy;
bool g_mtqHealthy;
bool g_rwaHealthy;
bool g_imgHealthy;


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


/* Step 1. Commission Phase I Checks */
static void idle_phase1() {
	PRINTF("idle: Commission Phase 1 Checks\r\n");
	while (!g_epsHealthy || !g_obcHealthy){
//		g_epsHealthy = eps_healthcheck(); //TODO: replace with whatever function eps is using to healthcheck
		g_obcHealthy = obc_healthcheck();
		if (!g_epsHealthy){
			//i2c_eps_manualReset();
		}
		if (!g_obcHealthy){
			//obc_reset();
		}
	}

}

/* Set the OBC run mode - clock frequency etc. */
static void setMCUPowerMode() {
	switch(operatingMode){
		case CRIT_LOW_POWER:
			LPM_LowPowerRun();
			break;

		case LOW_POWER:
			LPM_LowPowerRun();
			break;

		case NOMINAL_POWER:
			LPM_OverDriveRun();
			break;
		default:
			break;
	}
}

/* Update the flags for the peripherals in GNC */
static void UpdateFlags() {
	switch(operatingMode){
		case CRIT_LOW_POWER:
			g_sunSensActive = false;
			g_rwaSensActive = false;
			g_mtqSensActive = false;
			g_magSensActive = false;
			g_phdSensActive = false;
			break;

		case LOW_POWER:
			g_sunSensActive = true;
			g_rwaSensActive = true;
			g_mtqSensActive = true;
			g_magSensActive = true;
			g_phdSensActive = true;
			break;

		case NOMINAL_POWER:
			g_sunSensActive = true;
			g_rwaSensActive = true;
			g_mtqSensActive = true;
			g_magSensActive = true;
			g_phdSensActive = true;
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
	double voltage = i2c_eps_getBatteryLevel();
	if (voltage <= 7.4 ) // CRITICALLY LOW POWER
	{
		operatingMode = CRIT_LOW_POWER;
		PRINTF("enters critically low power operatingMode\r\n");
		setMCUPowerMode();
		i2c_eps_switchOnOffPdms(PDM_OBC);
		/*task control*/
		suspendTask(TaskHandler_com);
		suspendTask(TaskHandler_img);
	}
	else if (voltage <= 7.9 && voltage > 7.4) // LOW POWER
	{
		operatingMode = LOW_POWER;
		setMCUPowerMode();
		i2c_eps_switchOnOffPdms(PDM8_COM | PDM9_SEN | PDM_OBC); //not mentioned PDMs are automatically set 0 in the bits
		/*task control*/
		suspendTask(TaskHandler_img);
		resumeTask(TaskHandler_com);
	}
	else // Normal Mode: 7.9 < voltage < 8.26
	{
		operatingMode = NOMINAL_POWER;
		setMCUPowerMode();
		i2c_eps_switchOnOffPdms(PDM5_MTQ | PDM6_RWA | PDM7_IMG | PDM8_COM | PDM9_SEN | PDM_OBC);
		resumeTask(TaskHandler_com);
		resumeTask(TaskHandler_img);
		//GNC task will always be active
	}
	UpdateFlags();
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
	i2c_eps_switchOnOffPdms(PDM_OBC); //ensures only OBC is turned on, the rest are off
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
