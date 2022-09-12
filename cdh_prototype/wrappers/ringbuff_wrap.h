typedef struct circular_buf_t circular_buf_t;

typedef circular_buf_t* cbuf_handle_t;

typedef stored_data stored_data;

#define amount size;

// The hidden definition of our circular buffer structure
struct circular_buf_t {
	stored_data buffer[size];
	uint head = 0;
	uint tail = 0;
	uint max_used = 0;
	uint max = size;
	char full = 0;
};
