

/* FreeRTOS kernel includes. */
#include <eps_wrap.h>
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

extern bool g_imagActive;
extern bool g_commActive;
extern bool g_sunSensActive;
extern bool g_rwaSensActive;
extern bool g_magSensActive;
extern bool g_mtqSensActive;
extern bool g_phdSensActive;

void UpdateFlags(int mode)
{
	switch(mode){
		case CRIT_LOW_POWER:
			g_imagActive    = false;
			g_commActive    = false;
			g_sunSensActive = false;
			g_rwaSensActive = false;
			g_mtqSensActive = false;
			g_magSensActive = false;
			g_phdSensActive = false;
			break;

		case LOW_POWER:
			//TODO: fix flags for low power mode
			g_imagActive    = false;
			g_commActive    = true;
			g_sunSensActive = true;
			g_rwaSensActive = true;
			g_mtqSensActive = true;
			g_magSensActive = true;
			g_phdSensActive = true;
			break;

		case NOMINAL_POWER:
			g_imagActive    = true;
			g_commActive    = true;
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

void idle_task(void *pvParameters)
{

	double voltage;

	// variable to store ticks equivalent to 500 ms
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 );


	PRINTF("idle: Health check EPS\r\n");
//	HealthCheck_EPS();

	// power up the module

	for (;;) {

		// gets the last wake time
		TickType_t xLastWakeTime = xTaskGetTickCount();

		PRINTF("idle: Get Voltage from EPS\r\n");

		//voltage
		// TODO: Create a task to get the voltage from EPS system through I2C Communication


		PRINTF("idle: Power up modules based on voltage\r\n");


		// voltage will be between 6.144 and 8.26

		if (voltage <= 7.4 ) { // CRITICALLY LOW POWER
			mode = CRIT_LOW_POWER;
			//MCU_LowPowerMode();
//			i2c_eps_switchOnOffPdms(RXW, OFF); //THESE SHOULD DO NOTHING IF ALREADY ON!
//			i2c_eps_switchOnOffPdms(MTQ, OFF);
//			i2c_eps_switchOnOffPdms(IMG, OFF);
//			i2c_eps_switchOnOffPdms(COM, OFF);
//			i2c_eps_switchOnOffPdms(SEN, OFF);
//			HealthCheck_EPS();//?

		} else if (voltage <= 7.9 && voltage > 7.4) { // LOW POWER

			mode = LOW_POWER;
			//MCU_LowPowerMode();
//			i2c_eps_switchOnOffPdms(RXW, OFF);
//			i2c_eps_switchOnOffPdms(MTQ, OFF);
//			i2c_eps_switchOnOffPdms(IMG, OFF);
//			i2c_eps_switchOnOffPdms(COM, ON);
//			i2c_eps_switchOnOffPdms(SEN, ON);
//			HealthCheck_EPS();
//			HealthCheck_COM();
//			HealthCheck_SEN();

		// Normal Mode: 7.9 < voltage < 8.26
		} else { // NOMINAL POWER

			mode = NOMINAL_POWER;
			//MCU_OverdriveMode();
//			i2c_eps_switchOnOffPdms(RXW, ON);
//			i2c_eps_switchOnOffPdms(MTQ, ON);
//			i2c_eps_switchOnOffPdms(IMG, ON);
//			i2c_eps_switchOnOffPdms(COM, ON);
//			i2c_eps_switchOnOffPdms(SEN, ON);
//			HealthCheck_EPS();
//			HealthCheck_IMG();
//			HealthCheck_COM();
//			HealthCheck_SEN();
//			HealthCheck_RWX();
//			HealthCheck_MTQ();

		}

		UpdateFlags(mode) //uses g_operatingMode and mode
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
}
