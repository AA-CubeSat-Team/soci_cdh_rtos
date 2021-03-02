
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


void resetPriority();
void idle_task(void *pvParameters);
bool obc_healthcheck();
void obc_reset();
