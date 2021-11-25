/*
 * MCU Pinouts:

COM:

105	GPIO_AD_B0_06	UART1_TX	COM Board
101	GPIO_AD_B0_07	UART1_RX	COM Board
 */

#include <stdbool.h>

// TODO: Modify code to include interrupt-based receiving/sending functions as Harshal talked about

// TODO: (NOT SURE) Figure out if way to test uplinking/downlinking functions (After fixing) w/o radios

void com_radio_init(); // TODO: Ensure correct response is received from radio, lower priority
void com_init(); //
void com_set_burn_wire1(); // TODO: (NOT SURE) What pins do the GPIO commands correspond to that we can check?
void com_set_burn_wire2(); // TODO: (NOT SURE) What pins do the GPIO commands correspond to that we can check?
bool com_healthcheck(); // TODO: Ensure correct response is received from radio, sendConfigCommand
void com_getCommands(); /// Uplinking?
void com_sendPayloads(); // Downlinking?
void com_sendImages(); // Downlinking?
void com_sendBeacons(); // Downlinking?
bool com_i2c_checkDeploy(); /* TODO: Test by replacing I2C request with pre-programmed buffer or can
                               program slave Arduino via I2C to send fake antenna response, possibly
                               w/ COM_A as well*/

// Rithu: adding these for possible additional checks to see if sendConfigCommand works
void com_exitCommandMode();
void com_enterCommandMode();
void testSending();

void com_deployAntenna_algorithmOne(); // TODO: Test w/ COM_A once programmed
void com_deployAntenna_algorithmTwo(); // TODO: Test w/ COM_A once programmed

/* TODO: There might be a few other methods in the XDL manual u might want to decide if we
 * should implement. Id say take a look through, and see if we would want to implement
 * (i think there's one about picking the satellite mode, diff power levels to set to) and
 * suggest if those might want to be implemented (more for v2, not as much a priority))
*/



