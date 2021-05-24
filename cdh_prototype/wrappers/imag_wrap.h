/*
 *
 * GPIO_AD_B1_10	UART4_TX
 * GPIO_AD_B1_11	UART4_RX
 *
 *
 * */


/* Commands that can be tested */
static const uint8_t CHECK_STATUS       = 0x00;
static const uint8_t TAKE_PICTURE       = 0x01;
// static const uint8_t GET_THUMBNAIL_SIZE = 0x02; IMG not using these commands anymore.
static const uint8_t GET_PICTURE_SIZE   = 0x03;
// static const uint8_t GET_THUMBNAIL      = 0x04; IMG not using these commands anymore.
static const uint8_t GET_PICTURE        = 0x05;
static const uint8_t SET_CONTRAST       = 0x06;
static const uint8_t SET_BRIGHTNESS     = 0x07;
static const uint8_t SET_EXPOSURE       = 0x08;
static const uint8_t SET_SLEEP_TIME     = 0x09;
static const uint8_t PADDING            = 0xAA;

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