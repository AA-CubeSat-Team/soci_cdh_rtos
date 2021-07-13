/*
 * MCU Pinouts:

COM:

105	GPIO_AD_B0_06	UART1_TX	COM Board
101	GPIO_AD_B0_07	UART1_RX	COM Board
 */

#include <stdbool.h>

// TODO: Modify code to include interrupt-based receiving/sending functions as Harshal talked about

/* TODO: We are using this method of communication called EOT (end of transmit) where we
 * just transmit packets for a while and then have a small pause/silence. I'm not completely
 * sure if I have the timing right (what I was talking about above yesterday). In the manual
 * there should be instructions for EOT @9600bps and I think you can check there if we have
 * that correct/ if anything needs to be added.
*/

// TODO: (NOT SURE) Figure out if way to test uplinking/downlinking functions (After fixing) w/o radios

void com_radio_init(); // Tested, TODO: Need to double check its working after error (7/1/21)
void com_init(); // Tested. False Error w/ entering command mode b/c bool not returned
void com_set_burn_wire1(); // TODO: (NOT SURE) What pins do the GPIO commands correspond to that we can check?
void com_set_burn_wire2(); // TODO: (NOT SURE) What pins do the GPIO commands correspond to that we can check?
bool com_healthcheck(); // TODO: Need to test (7/1/21)
void com_getCommands(); /// Uplinking? TODO: Need to double check and fix errors
void com_sendPayloads(); // Downlinking? TODO: Need to double check and fix errors
void com_sendImages(); // Downlinking? TODO: Need to double check and fix errors
void com_sendBeacons(); // Downlinking? TODO: Need to double check and fix errors
bool com_i2c_checkDeploy(); /* TODO: Test by replacing I2C request with pre-programmed buffer or can
                               program slave Arduino via I2C to send fake antenna response (7/1/21)*/

// Rithu edit: adding this to  check if sendConfigCommand works
void com_exitCommandMode();
void com_enterCommandMode();

void com_deployAntenna_algorithmOne(); // TODO: (NOT SURE) How will we test (do I need to test) ?
void com_deployAntenna_algorithmTwo(); // TODO: (NOT SURE) How will we test (do I need to test) ?

/* TODO: There might be a few other methods in the XDL manual u might want to decide if we
 * should implement. Id say take a look through, and see if we would want to implement
 * (i think there's one about picking the satellite mode, diff power levels to set to) and
 * suggest if those might want to be implemented (more for v2, not as much a priority))
*/



