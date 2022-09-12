typedef struct circular_buf_t circular_buf_t;

typedef circular_buf_t* cbuf_handle_t;

typedef stored_data stored_data;

#define amount size;

// The hidden definition of our circular buffer structure
struct circular_buf_t {
	stored_data buffer[size];
	uint head = 0;
	uint tail = 0;
	uint max = size;
};


void
buf_put(circular_buf_t buffer_in,stored_data input){

	assert(sizeof(input) == sizeof(stored_data));

	if(buffer->head == buffer->size){
		buffer->head = 0;
	}

	buffer_in->buffer[buffer->head] = input;
}

stored_data
buf_return(circular_buf_t buffer_in){

	if(buffer->tail == buffer->size){
		buffer->tail = 0;
	}

	return(buffer_in->buffer[buffer->tail])

}
