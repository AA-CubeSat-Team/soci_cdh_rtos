#include <stdint.h>
/*
 *
 * GPIO_AD_B1_10	UART4_TX
 * GPIO_AD_B1_11	UART4_RX
 *
 *
 * */


/* Commands that can be tested */
#define CHECK_STATUS     0x00
#define TAKE_PICTURE     0x01
// #define GET_THUMBNAIL_SIZE 0x02 IMG not using these commands anymore.
#define GET_PICTURE_SIZE 0x03
// #define GET_THUMBNAIL 0x04 IMG not using these commands anymore.
#define GET_PICTURE      0x05
#define SET_CONTRAST     0x06
#define SET_BRIGHTNESS   0x07
#define SET_EXPOSURE     0x08
#define SET_SLEEP_TIME   0x09
#define PADDING          0xAA
#define ACK                 1
#define NAK                 0

void testCheckStatus(char parameter);

void testTakePicture();

void testGetThumbnailSize();

void testGetPictureSize();

void testGetThumbnail();

void testGetPicture();

void testSetContrast();

void testSetBrightness();

void testSetExposure();

void testSetSleepTime();
