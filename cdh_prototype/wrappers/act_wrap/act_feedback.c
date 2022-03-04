/*
 * act_feedback.c
 *
 *  Created on: Sep 23, 2021
 *      Author: joshperry
 */

// to-do list: update the i2c function with the function from comm_helper inside the source folder

#include "act_feedback.h"


feed_t Feed;

void initFeedback(feed_t * Feed, lpi2c_rtos_handle_t * feedHandle) {
	if (!Feed->feedInitialized)
	{
		Feed->feedHandle = feedHandle;
    	Feed->feedInitialized = 1;
	}
}

void setFeedback(float mtqFeed[3], float rwaFeed[4], float mode, feed_t * Feed) {

	Feed->m1.f = mtqFeed[0];
	Feed->m2.f = mtqFeed[1];
	Feed->m3.f = mtqFeed[2];
	Feed->r1.f = rwaFeed[0];
	Feed->r2.f = rwaFeed[1];
	Feed->r3.f = rwaFeed[2];
	Feed->r4.f = rwaFeed[3];
	Feed->md.f = mode;

	for (uint8_t i = 0; i < 4; i++) {
		Feed->sendBytes[i] = Feed->m1.bytes[i];
		Feed->sendBytes[i+4] = Feed->m2.bytes[i];
		Feed->sendBytes[i+8] = Feed->m3.bytes[i];
		Feed->sendBytes[i+12] = Feed->r1.bytes[i];
		Feed->sendBytes[i+16] = Feed->r2.bytes[i];
		Feed->sendBytes[i+20] = Feed->r3.bytes[i];
		Feed->sendBytes[i+24] = Feed->r4.bytes[i];
		Feed->sendBytes[i+28] = Feed->md.bytes[i];
	}
}

void writeFeedback(feed_t * Feed) {
	I2C_send(Feed->feedHandle, FEED_ADDR, 0xF7, Feed->sendBytes, 28);

	uint8_t s2[4];
	for (uint8_t i = 0; i < 4; i++) {
		s2[i] = Feed->sendBytes[i+28];
	}
	I2C_send(Feed->feedHandle, FEED_ADDR, 0xF7, s2, 4);
}


