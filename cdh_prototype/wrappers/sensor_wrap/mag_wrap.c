//
//  mag_wrap.c
//  wrapper test
//
//  Created by Josh Perry on 3/21/21.
//

#include "mag_wrap.h"
#include "com_protocol_helper.h"

// initialize struct.
#if MULTI_MAGS
mag_t Mag1, Mag2, Mag3;
#else
mag_t Mag1;
#endif

void readRegsMag(uint8_t reg, uint8_t * value, uint8_t valueSize, mag_t * Mag)
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
//    I2C_send(Mag->magHandle, &LPI2C1_masterTransfer, LSM303_ADDRESS_MAG, 0, &reg, 1); // ToDo: figure out which version is correct
    I2C_request(Mag->magHandle, &LPI2C1_masterTransfer, LSM303_ADDRESS_MAG, reg, value, valueSize);
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
    I2C_send(Mag->magHandle, &LPI2C1_masterTransfer, LSM303_ADDRESS_MAG, reg, &value, 1);
#endif
}

void readMagTemp(mag_t * Mag)
{
  uint8_t rawTempData;
  readRegsMag(LSM303_REGISTER_MAG_TEMP_OUT_X_H_M, &rawTempData, 1, Mag);
  Mag->temperature = (int8_t) rawTempData;
}

#if ARDUINO_CODE
void initMag(mag_t * Mag, uint8_t nMag)
#else
void initMag(mag_t * Mag, lpi2c_rtos_handle_t *magHandle, uint8_t nMag)
#endif
{
  if (!Mag->magInitialized)
  {
#if !ARDUINO_CODE
    Mag->magHandle = magHandle;
#endif
    Mag->magCalVec[0] = 0; Mag->magCalVec[1] = 0; Mag->magCalVec[2] = 0;
    Mag->magCalCoe[0] = 1; Mag->magCalCoe[1] = 1; Mag->magCalCoe[2] = 1;
#if !FLATSAT
    if (nMag == 1) {
    	Mag->magCalVec[0] = 22.7787; Mag->magCalVec[1] = -63.1638, Mag->magCalVec[2] = 29.3146;
    	Mag->magCalCoe[0] = 1.2192; Mag->magCalCoe[1] = 1.2693, Mag->magCalCoe[2] = 1.0121;
    }
    else if (nMag == 2) {
    	Mag->magCalVec[0] = -19.2956, Mag->magCalVec[1] = 9.0566, Mag->magCalVec[2] = 0.2989;
    	Mag->magCalCoe[0] = 1.2157, Mag->magCalCoe[1] = 1.15, Mag->magCalCoe[2] = 1.0039;
    }
    else if (nMag == 3) {
    	Mag->magCalVec[0] = -42.4006, Mag->magCalVec[1] = -35.6511, Mag->magCalVec[2] = 0.5457;
    	Mag->magCalCoe[0] = 1.2577, Mag->magCalCoe[1] = 1.1608, Mag->magCalCoe[2] = 1.0236;
    }
#endif
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
    if (reg1_a != 0x10) { printf ("ERROR Initializing Mag\r\n"); Mag->errorFlag = 1;}
    writeRegMag(LSM303_REGISTER_MAG_CRB_REG_M, LSM303_MAGGAIN_1_3, Mag);
  }
}

#if ARDUINO_CODE
void quickStartMag(mag_t * Mag, uint8_t nMag)
#else
void quickStartMag(mag_t * Mag, lpi2c_rtos_handle_t *magHandle, uint8_t nMag)
#endif
{
#if ARDUINO_CODE
  initMag(Mag, nMag);
#else
  initMag(Mag, magHandle, nMag);
#endif
  startMag(Mag);
}

void readMagData(mag_t * Mag)
{
    uint8_t reg_mg;
    readRegsMag(LSM303_REGISTER_MAG_SR_REG_Mg, &reg_mg, 1, Mag);
    if (!(reg_mg & 0x1)) {
    	printf("ERROR");
      Mag->errorFlag = 2;
    }

    // Read the magnetometer
    uint8_t raw[6];
    readRegsMag(LSM303_REGISTER_MAG_OUT_X_H_M, raw, sizeof(raw), Mag);

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
    
    if ((raw_x >= 2040) || (raw_x <= -2040) ||
        (raw_y >= 2040) || (raw_y <= -2040) ||
        (raw_z >= 2040) || (raw_z <= -2040) )  { printf ("ERROR\r\n"); Mag->errorFlag = 3; }

    Mag->magXYZ[0] = Mag->magCalCoe[0]*(((float)raw_x/_lsm303Mag_Gauss_LSB_XY*GAUSS_TO_MICROTESLA) - Mag->magCalVec[0]);
    Mag->magXYZ[1] = Mag->magCalCoe[1]*(((float)raw_y/_lsm303Mag_Gauss_LSB_XY*GAUSS_TO_MICROTESLA) - Mag->magCalVec[1]);
    Mag->magXYZ[2] = Mag->magCalCoe[2]*(((float)raw_z/_lsm303Mag_Gauss_LSB_Z*GAUSS_TO_MICROTESLA) - Mag->magCalVec[2]);

    //printf("reading mag data");
}

void rotateMagData(mag_t * Mag, uint8_t i)
{
	float x2, y2, z2;
	if (i == 1) {
		x2 = Mag->magXYZ[1];
		y2 = -1*Mag->magXYZ[0];
		z2 = Mag->magXYZ[2];
	}
	else if (i == 2) {
		float s2 = 0.70711;
		x2 = s2*Mag->magXYZ[0] + s2*Mag->magXYZ[1];
		y2 = -1*s2*Mag->magXYZ[0] + s2*Mag->magXYZ[1];
		z2 = Mag->magXYZ[2];
	}
	else if (i == 3) {
		x2 = Mag->magXYZ[0];
		y2 = Mag->magXYZ[1];
		z2 = Mag->magXYZ[2];
	}
	Mag->magXYZ[0] = x2;
	Mag->magXYZ[1] = y2;
	Mag->magXYZ[2] = z2;
}



