// Created by: Mikhail Mazukabzov 
// A simple implementiation of a ring buffer to be used for telemetery 
// Go to ring_buff.h to set the data types and the size of buffer

#include "ring_buff_wrap.h"
#include <stdlib.h>
#include "FreeRTOS.h" 



//innitiats the buffer with the type and size specified in the header file
//returns a points for type Buffer* to the created buffer
//uses dynamic allocation
//returns: pointer to type buffer
Buffer *initRingBuffer() {

    Buffer *buffer = malloc(sizeof(Buffer));

    *buffer = (Buffer) {
            .upper_bound = Size,
            .read_index = 0,
            .full_flag = 0};

    return buffer;
}


// resets the buffer, non-destructively 
// inputs: Pointer to type Buffer
// 
void refreshRingBuffer(Buffer *buffer) {

    *buffer = (Buffer) {
            .upper_bound = Size,
            .read_index = 0,
            .full_flag = 0};

}


// inserts the given data in the first avaliable empty bucket
// or in the bucket that was last written to 
// inputs: Pointer to type Buffer
void insertRingBuffer(Buffer *buffer, stored_data given_data) {

    buffer->data[buffer->write_index] = given_data;

    if (buffer->write_index < buffer->upper_bound) {

        buffer->write_index += 1;

    } else {

        buffer->full_flag = 1;
        buffer->write_index = 0;
    }

}

//reads the first avaliable buffer bucket from the  given pointer to the ring buffer
//copies that data and returns the value of that data
//inputs: Pointer to type Buffer
stored_data readRingBuffer(Buffer *buffer) {

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
