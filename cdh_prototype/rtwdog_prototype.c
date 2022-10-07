/**
 * @file    rtwdog_prototype.c
 * @brief   Application entry point.
 */

#include "RTWDOG_PROTO.h"
static rtwdog_config_t config;

void initializeRTWDOG(void) {

	uint16_t temp;
	/* When system is boot up, WDOG32 is disabled. We must wait for at least 2.5
     * periods of wdog32 clock to reconfigure wodg32. So Delay a while to wait for
     * the previous configuration taking effect. */
	/* DELAY_TIME = 0x140 ~ 2.5 seconds */
    for (temp = 0; temp < DELAY_TIME; temp++)
    {
        __NOP();
    }
    /**
     * config->enableRtwdog         = true;
     * config->clockSource          = kRTWDOG_ClockSource1;
     * config->prescaler            = kRTWDOG_ClockPrescalerDivide1;
     * config->workMode.enableWait  = true;
     * config->workMode.enableStop  = false;
     * config->workMode.enableDebug = false;
     * config->testMode             = kRTWDOG_TestModeDisabled;
     * config->enableUpdate         = true;
     * config->enableInterrupt      = false;
     * config->enableWindowMode     = false;
     * config->windowValue          = 0U;
     * config->timeoutValue         = 0xFFFFU;
    */
    /* get the default configuration for the rtwdog as listed above */
    RTWDOG_GetDefaultConfig(&config); // get the default configuration of rtwdog

    /*
     * Change the timeout value to 3 secs.
     * Use the prescaler to divide the 32.768 kHz clock by 256
     * turn off wait and stop, and enable debug to run the debugger.
     * When flashing to the board debug must be flagged false
     */
    config.timeoutValue = 0x0180U;     // set the timeout value to 3 secs for prescaled 32kHz clock1
    config.prescaler    = kRTWDOG_ClockPrescalerDivide256; // prescaler to increase the timeout value ((32.768 * 10^3) / 256)
    config.workMode.enableWait  = false;
    config.workMode.enableDebug = false;
    config.workMode.enableStop = false;
    config.enableUpdate = true;
    config.enableInterrupt = true;

    /* initialize the rtwdog timer.
     *  To be called in main()
     */
    RTWDOG_Init(RTWDOG, &config);
}
