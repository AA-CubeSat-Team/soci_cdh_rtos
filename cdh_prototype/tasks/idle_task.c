

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

extern bool g_imagActive;
extern bool g_commActive;
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
extern bool g_rxwHealthy;
extern bool g_imgHealthy;

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
	voltage = i2c_eps_getBatteryLevel(); //TODO: PRINTF THROWS ERROR WHEN THIS CALLED
	//PRINTF("Obtained the battery = %f", voltage);
	int mode = CRIT_LOW_POWER; // to ensure the system bootup from Critically Low Power Mode
	// variable to store ticks equivalent to 500 ms
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 );

	//
//	char X = i2c_eps_powerModuleStatus();
//	PRINTF("idle: Health check EPS\r\n");

	// power up the module

	for (;;) {

		// gets the last wake time
		TickType_t xLastWakeTime = xTaskGetTickCount();

		PRINTF("idle: Get Voltage from EPS\r\n");

		//voltage
		// TODO: Create a task to get the voltage from EPS system through I2C Communication
		voltage = i2c_eps_getBatteryLevel();

		PRINTF("idle: Power up modules based on voltage\r\n");


		// voltage will be between 6.144 and 8.26

		if (voltage <= 7.4 ) { // CRITICALLY LOW POWER
			mode = CRIT_LOW_POWER;
			PRINTF("enters critically low power mode");
			//MCU_LowPowerMode();
//			i2c_eps_switchOnOffPdms(RXW, OFF); //THESE SHOULD DO NOTHING IF ALREADY ON!
//			i2c_eps_switchOnOffPdms(MTQ, OFF);
//			i2c_eps_switchOnOffPdms(IMG, OFF);
//			i2c_eps_switchOnOffPdms(COM, OFF);
//			i2c_eps_switchOnOffPdms(SEN, OFF);
			g_epsHealthy = eps_healthcheck();

		} else if (voltage <= 7.9 && voltage > 7.4) { // LOW POWER

			mode = LOW_POWER;
			//MCU_LowPowerMode();
//			i2c_eps_switchOnOffPdms(RXW, OFF);
//			i2c_eps_switchOnOffPdms(MTQ, OFF);
//			i2c_eps_switchOnOffPdms(IMG, OFF);
//			i2c_eps_switchOnOffPdms(COM, ON);
//			i2c_eps_switchOnOffPdms(SEN, ON);
			while (!g_epsHealthy){
				g_epsHealthy = eps_healthcheck();
			}
			while (!g_comHealthy) {
				g_comHealthy = com_healthcheck();
			}
			while (!g_senHealthy) {
				g_senHealthy = sens_healthcheck();
			}
//			while (!g_gncHealthy) {
//				g_gncHealthy = gnc_healthcheck();
//			}
			com_sendBeacons();

		// Normal Mode: 7.9 < voltage < 8.26
		} else { // NOMINAL POWER

			mode = NOMINAL_POWER;
			//MCU_OverdriveMode();
//			i2c_eps_switchOnOffPdms(RXW, ON);
//			i2c_eps_switchOnOffPdms(MTQ, ON);
//			i2c_eps_switchOnOffPdms(IMG, ON);
//			i2c_eps_switchOnOffPdms(COM, ON);
//			i2c_eps_switchOnOffPdms(SEN, ON);
			while (!g_epsHealthy){
				g_epsHealthy = eps_healthcheck();
			}
			while (!g_comHealthy) {
				g_comHealthy = com_healthcheck();
			}
			while (!g_senHealthy) {
				g_senHealthy = sens_healthcheck();
			}
//			while (!g_gncHealthy) {
//				g_gncHealthy = gnc_healthcheck();
//			}
			while (!g_rxwHealthy) {
				g_rxwHealthy = rwa_healthcheck();
			}
			while (!g_mtqHealthy) {
				g_mtqHealthy = mtq_healthcheck();
			}
			while (!g_imgHealthy) {
				g_imgHealthy = img_healthcheck();
			}
			com_sendBeacons();
		}

		UpdateFlags(mode); //uses g_operatingMode and mode
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
}
