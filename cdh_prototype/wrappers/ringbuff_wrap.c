typedef struct circular_buf_t circular_buf_t;

typedef circular_buf_t* cbuf_handle_t;

typedef stored_data stored_data;

// The hidden definition of our circular buffer structure
struct circular_buf_t {
	uint8_t * buffer;
	size_t head;
	size_t size_of_data;
	size_t tail;
	size_t max; //of the buffer
	bool full;
};


cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size)
{
	assert(buffer && size);

	cbuf_handle_t cbuf = malloc(sizeof(circular_buf_t));
	assert(me);

	cbuf->buffer = buffer;
	cbuf->size_of_data = sizeof(stored_data);
	cbuf->max = size;
	cbuf->size_of_data = malloc(stored_data);
	circular_buf_reset(cbuf);

	assert(circular_buf_empty(cbuf));

	return cbuf;
}

void circular_buf_reset(cbuf_handle_t me)
{
    assert(me);

    me->head = 0;
    me->tail = 0;
    me->full = false;
}

void circular_buf_free(cbuf_handle_t me)
{
	assert(me);
	free(me);
}

bool circular_buf_full(cbuf_handle_t me)
{
	assert(me);

	return me->full;
}

size_t circular_buf_capacity(cbuf_handle_t me)
{
	assert(me);

	return me->max;
}

static void advance_pointer(cbuf_handle_t me)
{
	assert(me);

	if(me->full)
   	{
		if (++(me->tail) == me->max)
		{
			me->tail = 0;
		}
	}

	if (++(me->head) == me->max)
	{
		me->head = 0;
	}
	me->full = (me->head == me->tail);
}

static void retreat_pointer(cbuf_handle_t me)
{
	assert(me);

	me->full = false;
	if (++(me->tail) == me->max)
	{
		me->tail = 0;
	}
}

void circular_buf_put(cbuf_handle_t me, uint8_t data)
{
	assert(me && me->buffer);

    me->buffer[me->head] = data;

    advance_pointer(me);
}

int circular_buf_get(cbuf_handle_t me, uint8_t * data)
{
    assert(me && data && me->buffer);

    int r = -1;

    if(!circular_buf_empty(me))
    {
        *data = me->buffer[me->tail];
        retreat_pointer(me);

        r = 0;
    }

    return r;
}
