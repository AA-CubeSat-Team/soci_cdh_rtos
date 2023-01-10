
#include "ring_buff_wrap.h"
#include <stdlib.h>
#include "FreeRTOS.h" 

//inititatiiats the buffer with the type and size specified in the header file
//returns a points for type Buffer* to the created buffer
//uses dynamic allocation
Buffer *initBuffer() {

    Buffer *buffer = malloc(sizeof(Buffer));

    *buffer = (Buffer) {
            .upper_bound = Size,
            .read_index = 0,
            .full_flag = 0};

    return buffer;
    // assert(buffer->lower_bound == 0);
    // sanity check to be implemeted ... later
}


// resets the buffer, non-destructively and sets the
//
void refreshBuffer(Buffer *buffer) {

    *buffer = (Buffer) {
            .upper_bound = Size,
            .read_index = 0,
            .full_flag = 0};

    // assert(buffer->lower_bound == 0);
    // sanity check to be implemeted ... later
}


// inserts the given data in the first avaliable bucket
// or in the bucket that was last written to
void insert(Buffer *buffer, stored_data given_data) {

    buffer->data[buffer->write_index] = given_data;

    if (buffer->write_index < buffer->upper_bound) {

        buffer->write_index += 1;

    } else {

        buffer->full_flag = 1;
        buffer->write_index = 0;
    }

}

//reads the first avaliable buffer bucket from the ring buffer given
//copies that data and returns the value of that data
stored_data read(Buffer *buffer) {

    stored_data output = (buffer->data)[buffer->read_index];

    if ((buffer->read_index < (buffer->upper_bound)) && (buffer->read_index < (buffer->write_index))) {
        buffer->read_index += 1;
    } else if (buffer->full_flag == 1) {
        buffer->read_index = 0;
    } else {
        buffer->read_index += 1;
    }

    return (output);
}
