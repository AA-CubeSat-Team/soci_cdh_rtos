/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

extern TaskHandle_t TaskHandler_img;
void com_task(void *pvParameters);
