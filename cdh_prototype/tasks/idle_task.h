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
//flags for checking if it's turned on or not
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

extern int operatingMode;
extern TaskHandle_t TaskHandler_idle;



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

