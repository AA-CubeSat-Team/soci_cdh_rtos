#define COM_ENABLE	0
#define COM_WRAP_DEBUG 1

//flags to check if there's data to send
//cdh receives these data and sends the data to radio which to
extern bool command_request;
extern bool payload_check;
extern bool image_check;
extern bool beacon_check;

extern TaskHandle_t TaskHandler_com;
void com_task(void *pvParameters);


