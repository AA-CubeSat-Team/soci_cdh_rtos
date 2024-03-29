/*
 * MCU Pinouts: Check the pin header in the google drive
 */

// TODO: Modify code to include interrupt-based receiving/sending functions as Harshal talked about

// TODO: (NOT SURE) Figure out if way to test uplinking/downlinking functions (After fixing) w/o radios

#if HMAC_ENABLE
#include <hmac_sha256/hmac_sha256.h> // See https://github.com/h5p9sl/hmac_sha256/blob/master/examples/hmac_c_example.c
#endif

#ifndef SHA256_HASH_SIZE
#define SHA256_HASH_SIZE 32
#endif

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

/*
 * prep_payload: prepares all the payload
 * xxx_ready | payload for respective task ready
 */
void prep_payload(bool* img_ready, bool* com_ready, bool* gnc_ready, bool* eps_ready);

/*
 * uplink_handshake: process the upcoming header packet;
 */
void uplink_handshake(uint32_t* cmd_packet_size);

/*
 * send_payload | sends all the telemetry
 */
void send_payload();

/* TODO: There might be a few other methods in the XDL manual u might want to decide if we
 * should implement. Id say take a look through, and see if we would want to implement
 * (i think there's one about picking the satellite mode, diff power levels to set to) and
 * suggest if those might want to be implemented (more for v2, not as much a priority))
*/



