/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "clock_config.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "lpm.h"

#define IDLE_ENABLE	1

/*******************************************************************************
 * Variable Declarations
 ******************************************************************************/
////flags for checking if it's turned on or not
//bool g_sunSensActive;
//bool g_rwaSensActive;
//bool g_magSensActive;
//bool g_mtqSensActive;
//bool g_phdSensActive;
////flags for checking if they're healthy
//bool g_epsHealthy;
//bool g_obcHealthy;
//bool g_comHealthy;
//bool g_senHealthy;
//bool g_gncHealthy;
//bool g_mtqHealthy;
//bool g_rwaHealthy;
//bool g_imgHealthy;


enum PowerMode {
	CRIT_LOW_POWER = 0,
	LOW_POWER = 1,
	NOMINAL_POWER = 2
};

enum Modules {
	COM = 0,
	CIA = 1,
	SEN = 2
	//...
};

enum PLLCommand {
	OFF = 0,
	ON = 1
};

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
void idle_task(void *pvParameters);

