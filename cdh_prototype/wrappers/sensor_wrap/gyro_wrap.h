/*
 * gyro_wrap.h
 *
 *  Created on: Feb 17, 2021
 *      Author: Alex Zhen
 */

#ifndef GYRO_WRAP_H_
#define GYRO_WRAP_H_

#define ARDUINO_CODE            0

#if ARDUINO_CODE
#include <Wire.h>
#else
#include "fsl_lpi2c.h"
#include "fsl_lpi2c_freertos.h"
#endif

#define COUNT_TEMP_BIAS       0     // if the code count temperature influence on output
#define MULTI_GYROS         0   // if there are multiple gyroscopes(three)
#define DIFF_TEMP_BIAS_COE      0   // if the gyroscopes have different temperature bias and sensitivity coefficients.

#define GYRO_ODR_VALUE        12.5
#define GYRO_FSR_VALUE        250
/*!
 * @brief Structure contains information about one gyroscope
 *
 */
typedef struct _Gyro
{
  float gyroXYZ[3];           /* measured angular rates*/
  int8_t temperature;           /* measured temperature*/
#if ARDUINO_CODE
  TwoWire gyroWire;
#else
  lpi2c_rtos_handle_t * gyroHandle;   /* gyroscope i2c handle?*/
  lpi2c_master_transfer_t * gyroTransfer;   /* gyroscope i2c transfer structure pointer*/
#endif
  float gyroBias[3];            /* gyroscope zero-off set(bias)*/
  float gyroTempBiasCoe[3];       /* gyroscope temperature bias coefficients*/
  float gyroTempSensCoe[3];       /* gyroscope temperature sensitivity coefficients*/
} gyro_t;

extern gyro_t Gyro1;                /* gyroscope 1*/
/* lpi2c_rtos_handle_t * gyroHandle1 freertos handle of gyroscope 1?*/
/* lpi2c_master_transfer_t gyroTransfer1 gyroscope i2c transfer structure pointer*/

#if MULTI_GYROS
extern gyro_t Gyro2;
extern gyro_t Gyro3;
/* lpi2c_rtos_handle_t * gyroHandle1 freertos handle of gyroscope 2?*/
/* lpi2c_rtos_handle_t * gyroHandle1 freertos handle of gyroscope 3?*/
/* lpi2c_master_transfer_t gyroTransfer2 gyroscope i2c transfer structure pointer*/
/* lpi2c_master_transfer_t gyroTransfer3 gyroscope i2c transfer structure pointer*/
#endif


/*!
 * @brief read the value of registers of a gyroscope.
 *
 *
 * @param reg The register want to be read.
 * @param value The variable to hold the value of the register.
 * @param valueSize The size of the value of the register.
 * @param Gyro The gyroscope want to be read.
 * @return void
 *
 */
void readRegs(uint8_t reg, uint8_t *value, uint8_t valueSize, gyro_t * Gyro);

/*!
 * @brief write a value to the registers of a gyroscope.
 *
 *
 * @param reg The register want to be written.
 * @param value The value want to assigned to the register.
 * @param valueSize The size of The value want to assigned to the register.
 * @param Gyro The gyroscope want to be written.
 * @return void
 *
 */
void writeReg(uint8_t reg, uint8_t value, gyro_t * Gyro);

/*!
 * @brief Turn on a gyroscope. Initialize all parameters of a gyroscope. Set the gyroscope to desired configurations. Start reading.
 *
 *
 * @param Gyro The gyroscope want to be read.
 * @param gyroHandle The freertos handle of the gyroscope.
 * @param gyroTransfer The transfer information of the gyroscope.
 * @return void
 *
 */
#if ARDUINO_CODE
void startGyro(gyro_t * Gyro);
#else
void startGyro(gyro_t * Gyro, lpi2c_rtos_handle_t *gyroHandle, lpi2c_master_transfer_t *transfer);
#endif

/*!
 * @brief Read the temperature of a gyroscope.
 *
 *
 * @param Gyro The gyroscope that its temperature want to be read.
 * @return void
 *
 */
void readTempData(gyro_t * Gyro);

/*!
 * @brief Read the angular rates of a gyroscope (x,y,z axes).
 *
 *
 * @param Gyro The gyroscope that its angular rates  want to be read.
 * @return void
 *
 */
void readGyroData(gyro_t * Gyro);

/*!
 * @brief Reset a gyroscope. The i2c connection won't be reset.
 *
 *
 * @param Gyro The gyroscope to be reset
 * @return void
 *
 */
void reset(gyro_t * Gyro);

#endif /* GYRO_WRAP_H_ */
