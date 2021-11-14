/*
 * act_feedback.h
 *
 *  Created on: Sep 23, 2021
 *      Author: joshperry
 */

#ifndef ACTUATOR_WRAP_ACT_FEEDBACK_H_
#define ACTUATOR_WRAP_ACT_FEEDBACK_H_

#include <stdio.h>
#include "fsl_lpi2c.h"
#include "fsl_lpi2c_freertos.h"
#include "peripherals.h"

#define FEED_ADDR 0x48

typedef struct _Feed {

	uint8_t sendBytes[28];
	union {
	  float f;
	  uint8_t bytes[4];
	} m1;
	union {
	  float f;
	  uint8_t bytes[4];
	} m2;
	union {
	  float f;
	  uint8_t bytes[4];
	} m3;
	union {
	  float f;
	  uint8_t bytes[4];
	} r1;
	union {
	  float f;
	  uint8_t bytes[4];
	} r2;
	union {
	  float f;
	  uint8_t bytes[4];
	} r3;
	union {
	  float f;
	  uint8_t bytes[4];
	} r4;
	union {
	  float f;
	  uint8_t bytes[4];
	} md;

	lpi2c_rtos_handle_t * feedHandle;
	int feedInitialized;
} feed_t;

extern feed_t Feed;


void initFeedback(feed_t * Feed, lpi2c_rtos_handle_t * feedHandle);

void setFeedback(float mtqFeed[3], float rwaFeed[4], float mode, feed_t * Feed);

void writeFeedback(feed_t * Feed);


#endif /* ACTUATOR_WRAP_ACT_FEEDBACK_H_ */
