//
//  mag_wrap.h
//  wrapper test
//
//  Created by Josh Perry on 3/21/21.
//


#ifndef mag_wrap_h
#define mag_wrap_h

#define ARDUINO_CODE            0
#define MULTI_MAGS              1

#if ARDUINO_CODE
// #include <Wire.h>
#else
#include "fsl_lpi2c.h"
#include "fsl_lpi2c_freertos.h"
#include "peripherals.h"
#endif

// Gain multipliers
#define GAUSS_TO_MICROTESLA                       100
#define _lsm303Mag_Gauss_LSB_XY                   1100
#define _lsm303Mag_Gauss_LSB_Z                    980
// Address
#define LSM303_ADDRESS_MAG                  (uint8_t)(0x3C >> 1)   // 0011110x*/

// Registers
#define LSM303_REGISTER_MAG_CRA_REG_M             0x00
#define LSM303_REGISTER_MAG_CRB_REG_M             0x01
#define LSM303_REGISTER_MAG_MR_REG_M              0x02
#define LSM303_REGISTER_MAG_OUT_X_H_M             0x03
#define LSM303_REGISTER_MAG_SR_REG_Mg             0x09
#define LSM303_MAGGAIN_1_3                        0x20
#define LSM303_REGISTER_MAG_TEMP_OUT_X_H_M        0x31


/*!
 * @brief Structure contains information about one magnetometer
 */

typedef struct _Mag
{
  float magXYZ[3];            /* measured field strengths*/
  int8_t temperature;         /* measured temperature*/
#if !ARDUINO_CODE
  lpi2c_rtos_handle_t * magHandle;        /* i2c handle?*/
#endif
  float magCalVec[3];
  float magCalCoe[3];
  char magInitialized;
  int errorFlag;
} mag_t;

extern mag_t Mag1, Mag2, Mag3;

void readRegsMag(uint8_t reg, uint8_t * value, uint8_t valueSize, mag_t * Mag);
void writeRegMag(uint8_t reg, uint8_t value, mag_t * Mag);

#if ARDUINO_CODE
void initMag(mag_t * Mag, nMag);
#else
void initMag(mag_t * Mag, lpi2c_rtos_handle_t *magHandle, uint8_t nMag);
#endif

void startMag(mag_t * Mag);

#if ARDUINO_CODE
void quickStartMag(mag_t * Mag, nMag);
#else
void quickStartMag(mag_t * Mag, lpi2c_rtos_handle_t * magHandle, uint8_t nMag);
#endif

void readMagData(mag_t * Mag);
void readMagTemp(mag_t * Mag);
void rotateMagData(mag_t * Mag, uint8_t i);

#endif /* mag_wrap_h */
