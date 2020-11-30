#ifndef LPUARTH
#define LPUARTH

#include <stdint.h>

void uart3_rx_task(void *pvParameters);
void uart3_tx_task(void *pvParameters);
void process_task(void *pvParameters);

void init_tasks();

#endif
