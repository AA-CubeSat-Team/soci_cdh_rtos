/*
 * MCU Pinouts:

IMG:

80	GPIO_AD_B1_10	UART4_TX	CIA Board
79	GPIO_AD_B1_11	UART4_RX	CIA Board
 */

#include <stdbool.h>

bool img_healthcheck();
void img_sendCommand();
