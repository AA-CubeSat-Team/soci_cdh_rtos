///* This is a source file for testing the UART1 commands required for the flight computer to
// * communicate with COM
// *
// */
//

// MCU Pin #105 | GPIO_AD_B0_06 | UART1_TX
// MCU Pin #101 | GPIO_AD_B0_07 | UART1_RX

#include <stdbool.h>

void com_radio_init();
bool com_healthcheck();
void com_getCommands();
void com_sendPayloads();
void com_sendImages();
void com_sendBeacons();
