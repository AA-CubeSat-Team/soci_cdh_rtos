//
//  mag_wrap.c
//  wrapper test
//
//  Created by Josh Perry on 3/21/21.
//

#include "mag_wrap.h"

// initialize struct.
#if MULTI_MAGS
mag_t Mag1, Mag2, Mag3;
#else
mag_t Mag1;
#endif

void readRegsMag(uint8_t reg, uint8_t *value, uint8_t valueSize, mag_t * Mag)
{
#if ARDUINO_CODE
    Wire.beginTransmission(LSM303_ADDRESS_MAG);
    Wire.write(reg);
    Wire.endTransmission(false);
    Wire.requestFrom(LSM303_ADDRESS_MAG, valueSize);
    int i = 0;
    while (Wire.available()) {
      *(value+i) = Wire.read();
      i++;
    }
#else
  I2C_request(Mag->magHandle, LSM303_ADDRESS_MAG, reg, value, valueSize);
#endif
}

void writeRegMag(uint8_t reg, uint8_t value, mag_t * Mag)
{
#if ARDUINO_CODE
    Wire.beginTransmission(LSM303_ADDRESS_MAG);
    Wire.write((uint8_t)reg);
    Wire.write((uint8_t)value);
    Wire.endTransmission();
#else
  I2C_send(Mag->magHandle, LSM303_ADDRESS_MAG, reg, &value, 1);
#endif
}

void readMagTemp(mag_t * Mag)
{
  uint8_t rawTempData;
  readRegsMag(LSM303_REGISTER_MAG_TEMP_OUT_X_H_M, &rawTempData, 1, Mag);
  Mag->temperature = (int8_t) rawTempData;
}

#if ARDUINO_CODE
void initMag(mag_t * Mag)
#else
void initMag(mag_t * Mag, lpi2c_rtos_handle_t *magHandle)
#endif
{
  if (!Mag->magInitialized)
  {
#if !ARDUINO_CODE
    Mag->magHandle = magHandle;
#endif
    static const float magCalVecValue[3] = {0, 0, 0};
    static const float magCalCoeValue[3] = {1, 1, 1};
    memcpy(Mag->magCalVec,magCalVecValue, 12);
    memcpy(Mag->magCalCoe,magCalCoeValue, 12);
#if ARDUINO_CODE
    Wire.begin();
#endif
    Mag->errorFlag = 0;
    Mag->magInitialized = 1;
  }
}

void startMag(mag_t * Mag)
{
  if (Mag->magInitialized){
    writeRegMag(LSM303_REGISTER_MAG_MR_REG_M, 0x00, Mag);
    
    // LSM303DLHC has no WHOAMI register so read CRA_REG_M to check
    // the default value (0b00010000/0x10)
    uint8_t reg1_a;
    readRegsMag(LSM303_REGISTER_MAG_CRA_REG_M, &reg1_a, 1, Mag);
    if (reg1_a != 0x10) { Mag->errorFlag = 1;}
    writeRegMag(LSM303_REGISTER_MAG_CRB_REG_M, LSM303_MAGGAIN_1_3, Mag);
  }
}

#if ARDUINO_CODE
void quickStartMag(mag_t * Mag)
#else
void quickStartMag(mag_t * Mag, lpi2c_rtos_handle_t *magHandle)
#endif
{
#if ARDUINO_CODE
  initMag(Mag);
#else
  initMag(Mag, magHandle);
#endif
  startMag(Mag);
}

void readMagData(mag_t * Mag)
{
    uint8_t reg_mg;
    readRegsMag(LSM303_REGISTER_MAG_SR_REG_Mg, &reg_mg, 1, Mag);
    if (!(reg_mg & 0x1)) {
      Mag->errorFlag = 2;
    }

    // Read the magnetometer
    uint8_t raw[6];
   readRegsMag(LSM303_REGISTER_MAG_OUT_X_H_M, raw, (uint8_t)6, Mag);

    // Note high before low (different than accel)
    uint8_t xhi = raw[0];
    uint8_t xlo = raw[1];
    uint8_t zhi = raw[2];
    uint8_t zlo = raw[3];
    uint8_t yhi = raw[4];
    uint8_t ylo = raw[5];

    // Shift values to create properly formed integer (low uint8_t first)
    int16_t raw_x = (int16_t)((int16_t)xlo | ((int16_t)xhi << 8));
    int16_t raw_y = (int16_t)((int16_t)ylo | ((int16_t)yhi << 8));
    int16_t raw_z = (int16_t)((int16_t)zlo | ((int16_t)zhi << 8));
    
    if ((raw_x >= 2040) | (raw_x <= -2040) |
        (raw_y >= 2040) | (raw_y <= -2040) |
        (raw_z >= 2040) | (raw_z <= -2040) )  {Mag->errorFlag = 4; }

    Mag->magXYZ[0] = Mag->magCalCoe[0]*(((float)raw_x/_lsm303Mag_Gauss_LSB_XY*GAUSS_TO_MICROTESLA) - Mag->magCalVec[0]);
    Mag->magXYZ[1] = Mag->magCalCoe[1]*(((float)raw_y/_lsm303Mag_Gauss_LSB_XY*GAUSS_TO_MICROTESLA) - Mag->magCalVec[1]);
    Mag->magXYZ[2] = Mag->magCalCoe[2]*(((float)raw_z/_lsm303Mag_Gauss_LSB_Z*GAUSS_TO_MICROTESLA) - Mag->magCalVec[2]);
}
