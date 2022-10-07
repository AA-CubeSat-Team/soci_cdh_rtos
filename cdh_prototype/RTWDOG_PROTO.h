#ifndef RTWDOG_PROTO
#define RTWDOG_PROTO

#include "fsl_debug_console.h" // PRINTF statement
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_rtwdog.h"
#include "idle_task.h"


//#define RTWDOG_BASE RTWDOG
#define RTWDOG_ENABLE 1

/* Prototypes for functions made below */
void initializeRTWDOG(void);

#define DELAY_TIME 0x0140U // 2.5 seconds on a 32kHz/256 clock

#endif
