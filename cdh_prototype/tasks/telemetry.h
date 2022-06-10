/*
 * telemetry.h
 *
 *  Created on: Apr 6, 2022
 *      Author: jaeye
 */

#ifndef TELEMETRY_H_
#define TELEMETRY_H_

#define QUEUE_DEMO_ENABLE 0

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "fsl_common.h"

/* drivers and peripherals */
#include "semc_sdram.h"
#include "peripherals.h"

/* std libraries */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/* Command Name List */

// IMG Command ID
//#define CMD_NAME #

//IMG data
#define NUM_IMG 5
#define IMG_SIZE     600000

// EPS Command ID
#define CMD_PAYLOAD_EPS 1

// GNC Command ID
#define CMD_PAYLOAD_GNC 1

// COM Command ID
#define EPS_READY 1
#define GNC_READY 2
#define IMG_READY 3


//static circular_buffer IMG_PAYLOAD;
extern uint8_t image_CIA[IMG_SIZE]; // IMG size

/***************************/

// Queue
#define xQueue_len 		20

// Queue handlers
extern QueueHandle_t cmd_queue_IMG;
extern QueueHandle_t cmd_queue_GNC;
extern QueueHandle_t cmd_queue_EPS;
extern QueueHandle_t tlm_queue_COM;

/****************** UPLINK *********************/
#define PRIMARY_HEADER_SIZE 50
#define ACK_SIZE			5
#define UPLINK_SIZE         100

typedef struct __attribute__((__packed__)) u_primary_tel{
	uint8_t packetLength;
	uint8_t packetID;
	uint8_t messageLength;
	uint8_t packetVersion;
	uint8_t packetType;
	uint16_t crc;
};

typedef struct __attribute__((__packed__)) u_ack_tel{
	uint8_t packetLength;
	uint8_t packetID;
	uint8_t ackMessage;
	uint16_t crc;
};

#define MAX_TEL_SIZE 20U
typedef struct __attribute__((__packed__)) u_tel{
	uint8_t packetLength;
	uint8_t packetID;
	uint64_t packetMessage;
	uint16_t crc;
};
/**********************************************/

/*******************DOWNLINK*******************/
#define D_PRIMARY_SIZE 1+1+1+4+2
typedef struct __attribute__((__packed__)) d_primary_tel{
	uint8_t packetLength;
	uint8_t packetID;
	uint8_t messageLength;
	uint32_t encryptionLayer;
	uint16_t crc;
};

#define D_ACK_SIZE 1+1+1+2
typedef struct __attribute__((__packed__)) d_ack_tel{
	uint8_t packetLength;
	uint8_t packetID;
	uint8_t ackMessage;
	uint16_t crc;
};

#define D_CMD_SIZE 1+1+8+2
#define MAX_CMD_SIZE 20U
typedef struct __attribute__((__packed__)) d_cmd_tel{
	uint8_t packetLength;
	uint8_t packetID;
	uint64_t packetMessage;
	uint16_t crc;
};
/*********************************************/

/******************GNC PAYLOAD****************/
struct __attribute__((__packed__)) payload_GNC{
	uint8_t packetLength;
	uint8_t packetID;
	uint64_t tlm;
};
/*********************************************/

/******************EPS PAYLOAD****************/
struct __attribute__((__packed__)) payload_EPS{
	uint8_t packetLength;
	uint8_t packetID;
	uint64_t tlm;
};
/*********************************************/
#endif /* TELEMETRY_H_ */
