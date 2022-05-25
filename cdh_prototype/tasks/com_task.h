/*
 * TODO: Add health beacon that would signal every minute using non-interrupt based
 * TODO: Rethink how to grab all data from COM task loop
 * TODO: Increase UART Buffer Size
 */

#define CLOCKS_PER_SECOND 1000000
#include "telemetry.h"

//flags to check if there's data to send
//cdh receives these data and sends the data to radio which to
extern bool command_request;
extern bool payload_check;
extern bool image_check;
extern bool beacon_check;

/* uplink */
extern struct u_primary_tel u_primary_tel1;
extern struct u_ack_tel u_ack_tel1;
extern struct u_tel u_tel1[MAX_TEL_SIZE];

/* downlink */
extern struct d_primary_tel d_primary_tel1;
extern struct d_ack_tel d_ack_tel1;
extern struct u_tel u_cmd_tel1[MAX_CMD_SIZE];

extern uint8_t uplink_recv_buffer[UPLINK_SIZE];
extern enum COM_States COM_State;
extern TaskHandle_t TaskHandler_com;
void com_task(void *pvParameters);


