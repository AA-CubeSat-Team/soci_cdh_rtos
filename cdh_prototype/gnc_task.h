#define GNC_ENABLE	0

// calculates values based on sensor values and output data for actuators
// run this function every 250 ms to make GNC build code real-time
void rt_OneStep(void);

void gnc_task(void *pvParameters);
