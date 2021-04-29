

/* FreeRTOS kernel includes. */
#include "eps_wrap.h"
#include "act_wrap.h"
#include "com_wrap.h"
#include "img_wrap.h"
#include "sen_wrap.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"


#include "idle_task.h"
#include "clock_config.h"
#include <stdbool.h>

extern bool g_imgActive;
extern bool g_comActive;
extern bool g_sunSensActive;
extern bool g_rwaSensActive;
extern bool g_magSensActive;
extern bool g_mtqSensActive;
extern bool g_phdSensActive;

//flags for checking if they're healthy
extern bool g_epsHealthy;
extern bool g_obcHealthy;
extern bool g_comHealthy;
extern bool g_senHealthy;
extern bool g_gncHealthy;
extern bool g_mtqHealthy;
extern bool g_rwaHealthy;
extern bool g_imgHealthy;

int mode;

#define PDM_MTQ  1 << (0)
#define PDM_RWA  1 << (1)
#define PDM_IMG  1 << (2)
#define PDM_COM  1 << (3)
#define PDM_SEN  1 << (4)

/* reseting priority */
extern TaskHandle_t TaskHandler_idle;
void resetPriority()
{
	vTaskPrioritySet(TaskHandler_idle, 0);
}
/******/

void UpdateFlags(int mode)
{
	switch(mode){
		case CRIT_LOW_POWER:
			g_imgActive     = false;
			g_comActive     = false;
			g_sunSensActive = false;
			g_rwaSensActive = false;
			g_mtqSensActive = false;
			g_magSensActive = false;
			g_phdSensActive = false;
			break;

		case LOW_POWER:
			//TODO: fix flags for low power mode
			g_imgActive     = false;
			g_comActive     = true;
			g_sunSensActive = true;
			g_rwaSensActive = true;
			g_mtqSensActive = true;
			g_magSensActive = true;
			g_phdSensActive = true;
			break;

		case NOMINAL_POWER:
			g_imgActive     = true;
			g_comActive     = true;
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

bool obc_healthcheck(){
	PRINTF("checking peripherals of obc\r\n");
	return true;
}

void obc_reset(){
	PRINTF("Hard resetting obc\r\n");
}

/* Step 1. Commission Phase I Checks */
void idle_phase1() {
	PRINTF("\nidle: Commission Phase 1 Checks\r\n");
	while (!g_epsHealthy || !g_obcHealthy){
//		g_epsHealthy = eps_healthcheck();
		PRINTF("i HAVN'T SWITCHED");
		g_obcHealthy = obc_healthcheck();
		PRINTF("I SWITCHED!");
		if (!g_epsHealthy){
//			i2c_eps_manualReset();
		}
		if (!g_obcHealthy){
			//obc_reset();
		}
	}

}

/* get the battery voltage and decides the appropriate pdm */
void idle_phase2() {
	/* Battery Voltage Check */
	PRINTF("idle: Get Voltage from EPS\r\n");
	// TODO: Create a task to get the voltage from EPS system through I2C Communication
//	double voltage = i2c_eps_getBatteryLevel();
	PRINTF("idle: PDM Power up modules based on voltage\r\n");
	float voltage = 0;
	if (voltage <= 7.4 ) // CRITICALLY LOW POWER
	{
		mode = CRIT_LOW_POWER;
		PRINTF("enters critically low power mode\r\n");
		//MCU_LowPowerMode();
//		i2c_eps_switchOnOffPdms(0); //nothing should be on
	}
	else if (voltage <= 7.9 && voltage > 7.4) // LOW POWER
	{
		mode = LOW_POWER;
		//MCU_LowPowerMode();
//		i2c_eps_switchOnOffPdms(PDM_COM | PDM_SEN); //not mentioned PDMs are automatically set 0 in the bits

	}
	else // Normal Mode: 7.9 < voltage < 8.26
	{ // NOMINAL POWER
		mode = NOMINAL_POWER;
		//MCU_OverdriveMode();
//		i2c_eps_switchOnOffPdms(PDM_RWA | PDM_MTQ | PDM_IMG | PDM_COM | PDM_SEN);
	}
	UpdateFlags(mode); //uses g_operatingMode and mode
}

/* Health checks subsystems */
void idle_phase3() {
	if (mode == NOMINAL_POWER)
	{
		g_comHealthy = com_healthcheck();
		g_senHealthy = sens_healthcheck();
		//g_gncHealthy = gnc_healthcheck();
		g_rwaHealthy = rwa_healthcheck();
		g_mtqHealthy = mtq_healthcheck();
		g_imgHealthy = img_healthcheck();
	}
	else if (mode == LOW_POWER)
	{
		g_comHealthy = com_healthcheck();
		g_senHealthy = sens_healthcheck();
//		g_gncHealthy = gnc_healthcheck(); //what does this check?
	}
	else { //mode == CRIT_LOW_POWER
		//nothing here
	}
}
void idle_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	int mode = CRIT_LOW_POWER;
	UpdateFlags(mode); //initialize mode to be CRIT_LOW_POWER
	vTaskSuspendAll();
	idle_phase1(); //Commission Phase I Checks
	idle_phase2(); //pdm decider
	idle_phase3(); //health checks subsystem
	resetPriority(); //resetting priority of idle task to 0
	xTaskResumeAll();

	for (;;) {
		TickType_t xLastWakeTime = xTaskGetTickCount(); // gets the last wake time
		idle_phase1(); //Commission Phase I Checks
		idle_phase2(); //pdm decider
		idle_phase3(); //health checks subsystem
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
}
