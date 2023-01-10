//
// Created by mikhail Mazukabzov on 1/9/23.
//

#ifndef UNTITLED2_RING_BUFF_WRAP_H
#define UNTITLED2_RING_BUFF_WRAP_H
#pragma once

#include <stdint.h>

#define stored_data int
#define Size 100

typedef struct Buffer {
    stored_data data[Size];
    long upper_bound;
    long read_index;
    long write_index;
    short full_flag;
} Buffer;

Buffer *initBuffer();

void insert(Buffer *buffer, stored_data given_data);

stored_data read(Buffer *buffer);

void refreshBuffer(Buffer *buffer);

//#include "ringbuff.c"
#endif //UNTITLED2_RING_BUFF_WRAP_H
