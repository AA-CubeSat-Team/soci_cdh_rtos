
#ifndef mtq_wrap_h
#define mtq_wrap_h

#define ARDUINO_CODE            0

#if ARDUINO_CODE
// #include <Wire.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include "fsl_lpi2c.h"
#include "fsl_lpi2c_freertos.h"
#include "peripherals.h"
#endif

#define PCA9685_MODE1     0x00
#define MODE1_RESTART     0x80
#define MODE1_SLEEP       0x10
#define MODE1_EXTCLK      0x40
#define PCA9685_PRESCALE  0xFE
#define MODE1_AI          0x20

#define PCA9685_PRESCALE_MIN 3
#define PCA9685_PRESCALE_MAX 255
#define FREQUENCY_OSCILLATOR 25000000

#define PWM_ADDR       0x47
#define X1_POS_ADDR    0x6
#define X1_NEG_ADDR    0xA
#define X2_POS_ADDR    0xE
#define X2_NEG_ADDR    0x12
#define Y1_POS_ADDR    0x16
#define Y1_NEG_ADDR    0x1A
#define Y2_POS_ADDR    0x1E
#define Y2_NEG_ADDR    0x22
#define Z_POS_ADDR     0x26
#define Z_NEG_ADDR     0x2A

typedef struct _mtq
{
#if !ARDUINO_CODE
  lpi2c_rtos_handle_t * mtqHandle;        /* i2c handle?*/
#endif
  char mtqInitialized;
  int errorFlag;

  float requestedMoment[3];
  uint16_t val_XYZ[3];
  float maxMomentZ;
  float maxMomentXY;
  uint32_t oscillatorFreq;

} mtq_t;

extern mtq_t mtq;

uint8_t readRegMtq(uint8_t reg, mtq_t * mtq);
void writeRegMtq(uint8_t reg, uint8_t value, mtq_t * mtq);
void writeRegsMtq(uint8_t reg, uint8_t values[4], mtq_t * mtq);

void SetPWMFreq(float freq, mtq_t * mtq);
void resetPWM(mtq_t * mtq);
void SetOscillatorFrequency(uint32_t freq, mtq_t * mtq);
void initPWM(mtq_t * mtq, lpi2c_rtos_handle_t *mtqHandle);

void setMoments(float rqt_x, float rqt_y, float rqt_z, mtq_t * mtq);


#endif /* mtq_wrap_h */

