//
// Created by mikhail Mazukabzov on 1/9/23.
// Header for the ring buffer

#ifndef UNTITLED2_RING_BUFF_WRAP_H
#define UNTITLED2_RING_BUFF_WRAP_H
#pragma once

#include <stdint.h>
//change this
#define stored_data int // defines the datatype
#define Size 100 // defines the number of buckets for the data
//change this


typedef struct Buffer {
    stored_data data[Size];
    long upper_bound;
    long read_index;
    long write_index;
    short full_flag;
} Buffer;

Buffer *initRIngBuffer();

void insertRingBuffer(Buffer *buffer, stored_data given_data);

stored_data readRingBuffer(Buffer *buffer);

void refreshRingBuffer(Buffer *buffer);

//#include "ringbuff.c"
#endif //UNTITLED2_RING_BUFF_WRAP_H
