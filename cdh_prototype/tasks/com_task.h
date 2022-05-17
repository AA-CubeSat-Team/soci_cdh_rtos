#define COM_WRAP_DEBUG 0

/*
 * TODO: Add health beacon that would signal every minute using non-interrupt based
 * TODO: Rethink how to grab all data from COM task loop
 * TODO: Increase UART Buffer Size
 */

#define CLOCKS_PER_SECOND 1000000

/* UPLINKING */
#define PRIMARY_HEADER_SIZE 50
#define ACK_SIZE			5
#define UPLINK_SIZE         100

// TODO: Change to OBC GPIO Pin
#if OBC
#define ANTENNA_WIRE_1 23 // For OBC Board
#define ANTENNA_WIRE_2 28
#else
#define ANTENNA_WIRE_1 19 // For DEV Board
#define ANTENNA_WIRE_2 18
#endif

//flags to check if there's data to send
//cdh receives these data and sends the data to radio which to
extern bool command_request;
extern bool payload_check;
extern bool image_check;
extern bool beacon_check;

/* telemetry */
extern struct u_primary_tel u_primary_tel1;
extern struct u_ack_tel u_ack_tel1;
extern struct u_tel u_tel1[MAX_TEL_SIZE];

extern uint8_t uplink_recv_buffer[UPLINK_SIZE];
extern enum COM_States COM_State;
extern TaskHandle_t TaskHandler_com;
void com_task(void *pvParameters);


