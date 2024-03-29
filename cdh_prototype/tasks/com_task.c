#include "com_task.h"
#include "com_protocol_helper.h"
#include "RTWDOG_PROTO.h"

//flags to check if there's data to send
//cdh receives these data and sends the data to radio which to
bool command_request = false;
bool payload_check = false;
bool image_check = false;
bool beacon_check = false;

/* Global Variables */
uint8_t uplink_recv_buffer[UPLINK_SIZE];

struct u_primary_tel u_primary_tel1;
struct u_ack_tel u_ack_tel1;
struct u_tel u_tel1[MAX_TEL_SIZE];

struct d_primary_tel d_primary_tel1;
struct d_ack_tel d_ack_tel1;
struct u_tel d_cmd_tel1[MAX_CMD_SIZE];

TaskHandle_t TaskHandler_com;
extern TaskHandle_t TaskHandler_img;
extern bool i2c_com_antennaDeployed;

enum COM_States COM_State;

void com_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms

	/* COM Setup */
	COM_State = INIT;
    bool img_ready = false;
    bool com_ready = false;
    bool gnc_ready = false;
    bool eps_ready = false;

    /* UPLINKING */
    size_t n = 0;
    uint32_t cmd_packet_size = 0;

#if  QUEUE_DEMO_ENABLE
	bool downlink_ready = true;
    bool commandReceived = true;
#endif

	for (;;) {

		switch (COM_State) { // Transitions
			case INIT:
#if COM_ENABLE
				com_init();
				/* deploy antenna */
				// TODO: do we need wait for deployment for antenna
				// TODO: whwere do we slot the 15 min wait                  <--- timer test
				int tel_IMG_cmdID = 0; // used temporarily as a count local variable
				com_deployAntenna_alorithmOne();
				while (!i2c_com_antennaDeployed) { // did antenna deployed
					switch(tel_IMG_cmdID) {
						case 0:
							com_deployAntenna_algorithmTwo();
							break;
						case 1:
							com_set_burn_wire1();
							break;
						case 2:
							com_set_burn_wire2();
							break;
					}
					tel_IMG_cmdID++;
				}
				// Waiting to detumble

				// vTaskDelay maximum input number is 2^16.
				// TODO: Must use a loop here (Illya's request)
				vTaskDelay(pdMS_TO_TICKS( 15*60*1000 )); // TODO wait for detumble, 15min
#endif

				// Detumble time limit hit

				/* Initialize PIT Timer */
				// PIT_TIMER_INTIALIZE

				/* Initialize HMAC Algorithm */
				// HMAC Algorithm Initialize

				COM_State = NORMAL;
				vTaskDelay(xDelayms);
				break;

			case NORMAL:
				/* receive all uplink data */
				uplink_handshake(&cmd_packet_size);

				if(COM_State == UPLINKING) {
					break;
				} else { // prepare data for passing
					/* send health beacon */
					// health beacon message

					/* algorithm to get all the data */
					if(!(img_ready & gnc_ready &eps_ready & com_ready)) { // downlink ready?
						prep_payload(&img_ready, &com_ready, &gnc_ready, &eps_ready); // preps payload
					}
					vTaskDelay(xDelayms);
				}
				break;
			case UPLINKING:
				/* Implement HMAC */
				/*
				//check CRC bytes
				if(error) {
					// downlink/send NACK
					COM_State = Normal;
					break;
			    else {
			    	// send CMDs to different tasks
			    }
				 */

				/* execute any uplink command */
				COM_State = DOWNLINKING;
				break;

			case DOWNLINKING:
				break;
				//TODO: Send Beacon
				//TODO: Listen for response | how to respond to commands from MCC
				if(!(img_ready & gnc_ready & eps_ready & com_ready)) { // downlink ready?
					prep_payload(&img_ready, &com_ready, &gnc_ready, &eps_ready); // preps payload
				} else {
					send_payload();
					COM_State = NORMAL;
					vTaskDelay(xDelayms);
				}
				//TODO: add tick measure to make sure PASSING is over
			default:
				COM_State = INIT;
				break;
		}
	}
}
