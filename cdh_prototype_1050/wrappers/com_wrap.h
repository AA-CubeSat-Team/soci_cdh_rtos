/*
 * MCU Pinouts:

COM:

105	GPIO_AD_B0_06	UART1_TX	COM Board
101	GPIO_AD_B0_07	UART1_RX	COM Board
 */

#include <stdbool.h>

void com_radio_init();
bool com_healthcheck();
void com_getCommands();
void com_sendPayloads();
void com_sendImages();
void com_sendBeacons();
