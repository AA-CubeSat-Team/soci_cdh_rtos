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
#include "peripherals.h"
#endif

#define COUNT_ZERO_OFFSET     0
#define COUNT_TEMP_BIAS       0     // if the code count temperature influence on output
#define MULTI_GYROS         0   // if there are multiple gyroscopes(three)
#define DIFF_TEMP_BIAS_COE      0   // if the gyroscopes have different temperature bias and sensitivity coefficients.


// register addresses FXAS21002C_H_
#define GYRO_OUT_X_MSB        0x01
#define GYRO_CTRL_REG0        0x0D
#define GYRO_TEMP         0x12
#define GYRO_CTRL_REG1        0x13
#define GYRO_INT_SRC_FLAG     0x0B

// gyro parameters

#define GYRO_ODR_NUM        0b101
#define GYRO_FSR_NUM        0b11
#define GYRO_ODR_VALUE        25
#define GYRO_FSR_VALUE        250
#define GYRO_SENSITIVITY      7.8125e-3
#define GYRO_TEMP_0         23
#define GYRO_ADDRESS        (uint8_t)0x20
/*!
 * @brief Structure contains information about one gyroscope
 *
 */
typedef struct _Gyro
{
  float gyroXYZ[3];           /* measured angular rates*/
  int8_t temperature;           /* measured temperature*/
#if !ARDUINO_CODE
  lpi2c_rtos_handle_t * gyroHandle;   /* gyroscope i2c handle?*/
#endif
  float gyroBias[3];            /* gyroscope zero-off set(bias)*/
  float gyroTempBiasCoe[3];       /* gyroscope temperature bias coefficients*/
  float gyroTempSensCoe[3];       /* gyroscope temperature sensitivity coefficients*/
  char  gyroInitialized; /* gyroscope status */
} gyro_t;

extern gyro_t Gyro1;                /* gyroscope 1*/

#if MULTI_GYROS
extern gyro_t Gyro2;
extern gyro_t Gyro3;
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
void readRegsGyro(uint8_t reg, uint8_t *value, uint8_t valueSize, gyro_t * Gyro);

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
void writeRegGyro(uint8_t reg, uint8_t value, gyro_t * Gyro);


#if ARDUINO_CODE
/*!
 * @brief Turn on a gyroscope. Initialize all parameters of a gyroscope.
 *
 *
 * @param Gyro The gyroscope wants to be initialized
 * @return void
 *
 */
void initGyro(gyro_t * Gyro);
#else
/*!
 * @brief Turn on a gyroscope. Initialize all parameters of a gyroscope.
 *
 *
 * @param Gyro The gyroscope wants to be initialized.
 * @param gyroHandle The freertos handle of the gyroscope.
 * @param gyroTransfer The transfer information of the gyroscope.
 * @return void
 *
 */
void initGyro(gyro_t * Gyro, lpi2c_rtos_handle_t *gyroHandle);
#endif

/*!
 * @brief Set the gyroscope to desired configurations. Start reading.
 *
 *
 * @param Gyro The gyroscope wants to be set.
 * @return void
 *
 */
void startGyro(gyro_t * Gyro);

/*!
 * @brief initialize the gyroscope and start the gyroscope's reading
 *
 *
 * @param Gyro The gyroscope wants to be set.
 * @return void
 *
 */
/*!
 * @brief initialize the gyroscope and start the gyroscope's reading. This
 * is the function going to be used on the FSW for starting the gyroscope.
 *
 *
 * @param Gyro The gyroscope wants to be set.
 * @return void
 *
 */
#if ARDUINO_CODE
void quickStartGyro(gyro_t * Gyro);
#else
void quickStartGyro(gyro_t * Gyro, lpi2c_rtos_handle_t *gyroHandle);
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
void resetGyro(gyro_t * Gyro);

#endif /* GYRO_WRAP_H_ */
