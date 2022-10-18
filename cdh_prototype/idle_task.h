#ifndef IDLE_TASK_HEADER
#define IDLE_TASK_HEADER

#define IDLE_ENABLE	0

/*******************************************************************************
 * Variable Declarations
 ******************************************************************************/
//flags for checking if it's turned on or not
extern bool mtqActive;
extern bool rwaActive;
extern bool senActive;

//flags for checking if they're healthy
extern bool obcHealthy;
extern bool epsHealthy;
extern bool comHealthy;
extern bool senHealthy;
extern bool gncHealthy;
extern bool mtqHealthy;
extern bool rwaHealthy;
extern bool imgHealthy;

extern int operatingMode;
extern uint8_t idle_flag;

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


void idle_task(void *pvParameters);
#endif
