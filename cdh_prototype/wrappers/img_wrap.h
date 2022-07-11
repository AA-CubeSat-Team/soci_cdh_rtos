/*
 * MCU Pinouts:
IMG:
80	GPIO_AD_B1_10	UART4_TX	CIA Board
79	GPIO_AD_B1_11	UART4_RX	CIA Board
 */


#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include <stdbool.h>

/* uint8_ts per package */
#define EXTERNAL_PACKAGE_SIZE 32

/* Reset time for uCamIII in milliseconds */
static const unsigned int HARDWARE_RESET_TIME = 5;

/* Maximum number of images allowed */
//static const unsigned int IMAGES_COUNT = 5;
#define IMAGES_COUNT 5

/* Response length */
#define RESPONSE_LENGTH 5

/* Commands that can be tested */
/*static const uint8_t CHECK_STATUS       = 0x00;
static const uint8_t TAKE_PICTURE       = 0x01;
static const uint8_t GET_PICTURE_SIZE   = 0x02;
static const uint8_t GET_PICTURE        = 0x03;
static const uint8_t SET_CONTRAST       = 0x04;
static const uint8_t SET_BRIGHTNESS     = 0x05;
static const uint8_t SET_EXPOSURE       = 0x06;
static const uint8_t SET_SLEEP_TIME     = 0x07;*/

#define CHECK_STATUS 		0
#define TAKE_PICTURE 		1
#define GET_THUMBNAIL_SIZE  2 // not used/implemented
#define GET_PICTURE_SIZE 	3
#define GET_THUMBNAIL		4 // not used/implemented
#define GET_PICTURE 		5
#define SET_CONTRAST 		6
#define SET_BRIGHTNESS 		7
#define SET_EXPOSURE 		8
#define SET_SLEEP_TIME 		9

/* Possible responses */
static const uint8_t NAK = 0x00;
static const uint8_t ACK = 0x01;

/* Possible errors */
static const uint8_t uCamIII_CONNECTION = 0x00;
static const uint8_t SD_CONNECTION      = 0x01;
static const uint8_t INCOMPLETE_COMMAND = 0x02;
static const uint8_t INVALID_COMMAND    = 0x03;
static const uint8_t INVALID_SLOT       = 0x04;
static const uint8_t INVALID_INTEGER    = 0x05;
static const uint8_t FILE_NOT_EXIST     = 0x06;

/* Possible <Device>s */
static const uint8_t COMPONENT_ALL      = 0;
static const uint8_t COMPONENT_UCAMIII  = 1;
static const uint8_t COMPONENT_SD       = 2;

/* Files names for pictures and thumbnails */
static const char pictureNames[5][6]   = {"P0.jpg", "P1.jpg", "P2.jpg", "P3.jpg", "P4.jpg"};
extern uint8_t IMG_PICTURE[75000];

// UART function declaration
status_t sendCommand(uint8_t command, uint8_t param);

// IMG system function declaration
typedef enum {
	SUCCESS,
	HANDSHAKEFAILURE,
	CMDFAILURE,
	PARAMFAILURE,
} IMG_system_response;

IMG_system_response checkStatus(uint8_t IMG_param);
IMG_system_response takePicture(uint8_t IMG_param);
IMG_system_response getPictureSize(uint8_t IMG_param);
IMG_system_response getPicture(uint8_t IMG_param);
IMG_system_response setContrast(uint8_t IMG_param);
IMG_system_response setBrightness(uint8_t IMG_param);
IMG_system_response setExposure(uint8_t IMG_param);
IMG_system_response setSleepTime(uint8_t IMG_param);
