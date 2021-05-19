/*
 * gyro_wrap.c
 *
 *  Created on: Feb 17, 2021
 *      Author: Alex Zhen
 */


#include "gyro_wrap.h"

// gyroscope struct.
#if MULTI_GYROS
gyro_t Gyro1, Gyro2, Gyro3;
#else
gyro_t Gyro1;
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
void readRegsGyro(uint8_t reg, uint8_t *value, uint8_t valueSize, gyro_t * Gyro)
{
#if ARDUINO_CODE
    Wire.beginTransmission(GYRO_ADDRESS);
    Wire.write(reg);
    Wire.endTransmission(false);
    Wire.requestFrom(GYRO_ADDRESS, valueSize);
    int i = 0;
    while (Wire.available()) {
      *(value+i) = Wire.read();
      i++;
    }
#else
    I2C_request(Gyro->gyroHandle, GYRO_ADDRESS, reg, value, valueSize);
#endif
}

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
void writeRegGyro(uint8_t reg, uint8_t value, gyro_t * Gyro)
{
#if ARDUINO_CODE
  Wire.beginTransmission(GYRO_ADDRESS);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
#else
  I2C_send(Gyro->gyroHandle, GYRO_ADDRESS, reg, &value, 1);
#endif
}

#if ARDUINO_CODE
/*!
 * @brief Turn on a gyroscope. Initialize all parameters of a gyroscope.
 *
 *
 * @param Gyro The gyroscope wants to be initialized
 * @return void
 *
 */
void initGyro(gyro_t * Gyro)
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
void initGyro(gyro_t * Gyro, lpi2c_rtos_handle_t *gyroHandle)
#endif
{
  if (!Gyro->gyroInitialized)
  {
#if !ARDUINO_CODE
    Gyro->gyroHandle = gyroHandle;
#endif

#if DIFF_TEMP_BIAS_COE
    switch (base_Gyro){
      case LPI2C1:
        static const float gyroBiasValue = {-0.565375, 0.6173333, -0.0121667};
        static const float gyroTempBiasCoeValue = {0.02, 0.02, 0.01};
        static const float gyroTempSensCoeValue = {0.0008, 0.0008, 0.0001};
        Gyro->gyroBias = gyroBiasValue;
        Gyro->gyroTempBiasCoe = gyroTempBiasCoeValue;
        Gyro->gyroTempSensCoe = gyroTempSensCoeValue;
        break;
      case LPI2C2:
        static const float gyroBiasValue = {0, 0, 0};
        static const float gyroTempBiasCoeValue = {0, 0, 0};
        static const float gyroTempSensCoeValue = {0, 0, 0};
        Gyro->gyroBias = gyroBiasValue;
        Gyro->gyroTempBiasCoe = gyroTempBiasCoeValue;
        Gyro->gyroTempSensCoe = gyroTempSensCoeValue;
        break;
      case LPI2C3:
        static const float gyroBiasValue = {0, 0, 0};
        static const float gyroTempBiasCoeValue = {0, 0, 0};
        static const float gyroTempSensCoeValue = {0, 0, 0};
        Gyro->gyroBias = gyroBiasValue;
        Gyro->gyroTempBiasCoe = gyroTempBiasCoeValue;
        Gyro->gyroTempSensCoe = gyroTempSensCoeValue;
        break;
    }
#else

#if COUNT_ZERO_OFFSET
    static const float gyroBiasValue[3] = {-0.565375, 0.6173333, -0.0121667};
    static const float gyroTempBiasCoeValue[3] = {0.02, 0.02, 0.01};
    static const float gyroTempSensCoeValue[3] = {0.0008, 0.0008, 0.0001};
#else
    static const float gyroBiasValue[3] = {.0, .0, .0};
    static const float gyroTempBiasCoeValue[3] = {.0, .0, .0};
    static const float gyroTempSensCoeValue[3] = {.0, .0, .0};
#endif
    memcpy(Gyro->gyroBias,gyroBiasValue, 12);
    memcpy(Gyro->gyroTempBiasCoe,gyroTempBiasCoeValue, 12);
    memcpy(Gyro->gyroTempSensCoe,gyroTempSensCoeValue, 12);
#endif

#if ARDUINO_CODE
    Wire.begin();
#endif
    Gyro->gyroInitialized = 1;
  }
}

/*!
 * @brief Set the gyroscope to desired configurations. Start reading.
 *
 *
 * @param Gyro The gyroscope wants to be set.
 * @return void
 *
 */
void startGyro(gyro_t * Gyro)
{
  if (Gyro->gyroInitialized){
  writeRegGyro(GYRO_CTRL_REG0, GYRO_FSR_NUM, Gyro);
  writeRegGyro(GYRO_CTRL_REG1, (GYRO_ODR_NUM<<2 | 0b10), Gyro);
  }
}

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
void quickStartGyro(gyro_t * Gyro)
#else
void quickStartGyro(gyro_t * Gyro, lpi2c_rtos_handle_t *gyroHandle)
#endif
{
#if ARDUINO_CODE
  initGyro(Gyro);
#else
  initGyro(Gyro, gyroHandle);
#endif
  startGyro(Gyro);
}

/*!
 * @brief Read the temperature of a gyroscope.
 *
 *
 * @param Gyro The gyroscope that its temperature want to be read.
 * @return void
 *
 */
void readTempData(gyro_t * Gyro)
{
  uint8_t rawTempData;
  readRegsGyro(GYRO_TEMP, &rawTempData, 1, Gyro);
  Gyro->temperature = (int8_t) rawTempData;
}

/*!
 * @brief Read the angular rates of a gyroscope (x,y,z axes).
 *
 *
 * @param Gyro The gyroscope that its angular rates  want to be read.
 * @return void
 *
 */
void readGyroData(gyro_t * Gyro)
{
  readTempData(Gyro);
  unsigned char rawData[6];  // x/y/z gyro register data stored here
  readRegsGyro(GYRO_OUT_X_MSB,rawData, 6, Gyro);  // Read the six raw data registers into data array


#if COUNT_TEMP_BIAS
  int8_t tempDelta = Gyro->temperature - GYRO_TEMP_0;
#endif
  for (int i = 0; i<3; i++){
    short tempValue = ((short)(((unsigned short)rawData[2*i]) << 8 | ((unsigned short) rawData[2*i + 1])));
#if COUNT_TEMP_BIAS
    Gyro->gyroXYZ[i] = tempValue*GYRO_SENSITIVITY*(1 + (Gyro->gyroTempSensCoe[i])*(int16_t) tempDelta) - (Gyro->gyroBias[i]) - Gyro->gyroTempBiasCoe[i]*(int16_t) tempDelta;
#else
    Gyro->gyroXYZ[i] = ((float) tempValue)*GYRO_SENSITIVITY  - (Gyro->gyroBias[i]);
#endif
  }
}

/*!
 * @brief Reset a gyroscope. The i2c connection won't be reset.
 *
 *
 * @param Gyro The gyroscope to be reset
 * @return void
 *
 */
void resetGyro(gyro_t * Gyro){
  writeRegGyro(GYRO_CTRL_REG1, 0b1000000, Gyro); // set reset bit to 1 to assert software reset to zero at end of boot process

  uint8_t flag;
  readRegsGyro(GYRO_INT_SRC_FLAG, &flag, 1, Gyro);
  while(!(flag & 0x08))  { // wait for boot end flag to be set
      readRegsGyro(GYRO_INT_SRC_FLAG, &flag, 1, Gyro);
  }
}
