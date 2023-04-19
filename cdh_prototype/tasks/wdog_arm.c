/*
 * wdog_arm.c
 *
 *  Created on: Feb 19, 2023
 *      Author: Illya Kuzmych
 */

#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "fsl_wdog.h"

#define WDOG_BASE WDOG1

/**
 * WDOG_Refresh(WDOG_Type *base)      < refreshes the specified WDOG timer
 * WDOG_Init(WDOG_Type *base, const wdog_config_t *config)      < initialiazes the WDOG that is specified with the configuration given
 */

void configureWDOG(void) {
	wdog_config_t config;


	/*
	bool enableWdog;             < Enables or disables WDOG
    wdog_work_mode_t workMode;   < Configures WDOG work mode in debug stop and wait mode
    bool enableInterrupt;        < Enables or disables WDOG interrupt
    uint16_t timeoutValue;       < Timeout value
    uint16_t interruptTimeValue; < Interrupt count timeout value
    bool softwareResetExtension; < software reset extension
    bool enablePowerDown;        < power down enable bit
    bool enableTimeOutAssert;    < Enable WDOG_B timeout assertion.
	*/
	WDOG_GetDefaultConfig(&config);
	// enable the WDOG
	config.enableWdog = true;

	// configure the workmodes
	config.workMode.enableWait = false;
	config.workMode.enableStop = false;
	config.workMode.enableDebug = false; // have WDOG function while in debug mode

	// enable interrupts
	config.enableInterrupt = true;

	// configure timeout and interrupt values
	config.timeoutValue = 0xFFFFU; // Timeout value is (Total clock cycles / clock cycle frequency) = 65535 / 32768 ~ 2 seconds

	// activate the WDOG software reset (allow our WDOG to reset our MCU) and disable powerdown mode
	config.softwareResetExtension = true;
	config.enablePowerDown = false;

	// de-activate enableTimeOutAssert (we do not need it because we do not have anything external monitoring
	// WDOG behavior)
	config.enableTimeOutAssert = false;

	// apply our WDOG configurations to our WDOG base
	WDOG_Init(WDOG_BASE, &config);
	PRINTF("WDOG initialized");

	WDOG_Enable(WDOG_BASE);
	PRINTF("WDOG enabled");

}

// Test main function to test functionality of WDOG1

//int main(void) {
//    uint16_t resetFlag = 0U;
//    wdog_config_t config;
//    BOARD_ConfigMPU();
//    BOARD_InitBootPins();
//    BOARD_InitBootClocks();
//    BOARD_InitDebugConsole();
//
//	PRINTF("System boot up");
//
//	PRINTF("Refresh WDOG");
//	WDOG_Refresh(WDOG_BASE);
//
//	// run an infinite while loop to force
//	// system reset
//	while (1) {
//	}
//
//}

