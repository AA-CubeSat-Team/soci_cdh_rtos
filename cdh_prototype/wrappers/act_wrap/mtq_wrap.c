
#include "mtq_wrap.h"

#define lowByte(w) ((uint8_t) ((w) & 0xff))


// initialize struct.
mtq_t mtq;

uint8_t readRegMtq(uint8_t reg, mtq_t * mtq) {
#if ARDUINO_CODE
    Wire.beginTransmission(PWM_ADDR);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(PWM_ADDR, 1);
    return Wire.read();
  #else
	uint8_t value;
    I2C_request(mtq->mtqHandle, PWM_ADDR, reg, &value, 1);
    return value;
  #endif
}

void writeRegMtq(uint8_t reg, uint8_t value, mtq_t * mtq) {
#if ARDUINO_CODE
  Wire.beginTransmission(PWM_ADDR);
  Wire.write((uint8_t)reg);
  Wire.write((uint8_t)value);
  Wire.endTransmission();
#else
  I2C_send(mtq->mtqHandle, PWM_ADDR, reg, &value, 1);
#endif
}

// write 4 bytes
void writeRegsMtq(uint8_t reg, uint8_t values[4], mtq_t * mtq) {
  #if ARDUINO_CODE
    Wire.beginTransmission(PWM_ADDR);
    Wire.write(reg);
    for (int i=0; i<4; i++) {
      Wire.write(values[i]);
    }
    Wire.endTransmission();
  #else
    I2C_send(mtq->mtqHandle, PWM_ADDR, reg, values, 4);
  #endif
}

void SetPWMFreq(float freq, mtq_t * mtq) {
  // Range output modulation frequency is dependant on oscillator
  if (freq < 1)
    freq = 1;
  if (freq > 3500)
    freq = 3500; // Datasheet limit is 3052=50MHz/(4*4096)

  float prescaleval = ((mtq->oscillatorFreq / (freq * 4096.0)) + 0.5) - 1;
  if (prescaleval < PCA9685_PRESCALE_MIN)
    prescaleval = PCA9685_PRESCALE_MIN;
  if (prescaleval > PCA9685_PRESCALE_MAX)
    prescaleval = PCA9685_PRESCALE_MAX;
  uint8_t prescale = (uint8_t)prescaleval;

  uint8_t oldmode = readRegMtq(PCA9685_MODE1, mtq);
  uint8_t newmode = (oldmode & ~MODE1_RESTART) | MODE1_SLEEP; // sleep
  writeRegMtq(PCA9685_MODE1, newmode, mtq);                             // go to sleep
  writeRegMtq(PCA9685_PRESCALE, prescale, mtq); // set the prescaler
  writeRegMtq(PCA9685_MODE1, oldmode, mtq);

  // This sets the MODE1 register to turn on auto increment.
  writeRegMtq(PCA9685_MODE1, oldmode | MODE1_RESTART | MODE1_AI, mtq);
}

// reset function for PWM chip
void resetPWM(mtq_t * mtq) {
  writeRegMtq(PCA9685_MODE1, MODE1_RESTART, mtq);
}

void SetOscillatorFrequency(uint32_t freq, mtq_t * mtq) {
  mtq->oscillatorFreq = freq;
}

#if ARDUINO_CODE
void initpwm(mtq_t * mtq)
#else
void initPWM(mtq_t * mtq, lpi2c_rtos_handle_t *mtqHandle)
#endif
{
  if (!mtq->mtqInitialized)
  {
	#if !ARDUINO_CODE
	    mtq->mtqHandle = mtqHandle;
	#else
    	Wire.begin();
	#endif

    mtq->maxMomentZ = 0.109;
    mtq->maxMomentXY = 0.218;

    resetPWM(mtq);
    // set a default frequency
    SetPWMFreq(1000, mtq);
    // set the default internal frequency
    SetOscillatorFrequency(FREQUENCY_OSCILLATOR, mtq);

    mtq->mtqInitialized = 1;
    mtq->errorFlag = 0;
  }
}

void setMoments(float rqt_x, float rqt_y, float rqt_z, mtq_t * mtq)
{
	if (fabs(rqt_x) > mtq->maxMomentXY || fabs(rqt_y) > mtq->maxMomentXY || fabs(rqt_z) > mtq->maxMomentZ) {
		mtq->errorFlag = 1;
		return;
	}

	mtq->requestedMoment[0] = rqt_x;
	mtq->requestedMoment[1] = rqt_y;
	mtq->requestedMoment[2] = rqt_z;

	mtq->val_XYZ[0] = 4095*(1 - fabs(rqt_x)/(mtq->maxMomentXY));
	mtq->val_XYZ[1] = 4095*(1 - fabs(rqt_y)/(mtq->maxMomentXY));
	mtq->val_XYZ[2] = 4095*(1 - fabs(rqt_z)/(mtq->maxMomentZ));

	uint8_t Xdata[4] = {lowByte(mtq->val_XYZ[0]), (mtq->val_XYZ[0] >> 8), 0x0, 0x0};
	uint8_t Ydata[4] = {lowByte(mtq->val_XYZ[1]), (mtq->val_XYZ[1] >> 8), 0x0, 0x0};
	uint8_t Zdata[4] = {lowByte(mtq->val_XYZ[2]), (mtq->val_XYZ[2] >> 8), 0x0, 0x0};
	uint8_t offData[4] = {0x0, 0x0, 0x0, 0x10};

	if (rqt_x > 0) {
		writeRegsMtq(X1_POS_ADDR, Xdata, mtq);
	    writeRegsMtq(X1_NEG_ADDR, offData, mtq);
	    writeRegsMtq(X2_POS_ADDR, offData, mtq);
	    writeRegsMtq(X2_NEG_ADDR, Xdata, mtq);
	}
	else if (rqt_x < 0) {
	    writeRegsMtq(X1_POS_ADDR, offData, mtq);
	    writeRegsMtq(X1_NEG_ADDR, Xdata, mtq);
	    writeRegsMtq(X2_POS_ADDR, Xdata, mtq);
	    writeRegsMtq(X2_NEG_ADDR, offData, mtq);
	}
	else {
	    writeRegsMtq(X1_POS_ADDR, offData, mtq);
	    writeRegsMtq(X1_NEG_ADDR, offData, mtq);
	    writeRegsMtq(X2_POS_ADDR, offData, mtq);
	    writeRegsMtq(X2_NEG_ADDR, offData, mtq);
	}

	if (rqt_y > 0) {
	    writeRegsMtq(Y1_POS_ADDR, Ydata, mtq);
	    writeRegsMtq(Y1_NEG_ADDR, offData, mtq);
	    writeRegsMtq(Y2_POS_ADDR, offData, mtq);
	    writeRegsMtq(Y2_NEG_ADDR, Ydata, mtq);
	}
	else if (rqt_y < 0) {
	    writeRegsMtq(Y1_POS_ADDR, offData, mtq);
	    writeRegsMtq(Y1_NEG_ADDR, Ydata, mtq);
	    writeRegsMtq(Y2_POS_ADDR, Ydata, mtq);
	    writeRegsMtq(Y2_NEG_ADDR, offData, mtq);
	}
	else {
	    writeRegsMtq(Y1_POS_ADDR, offData, mtq);
	    writeRegsMtq(Y1_NEG_ADDR, offData, mtq);
	    writeRegsMtq(Y2_POS_ADDR, offData, mtq);
	    writeRegsMtq(Y2_NEG_ADDR, offData, mtq);
	}

	if (rqt_z > 0) {
	    writeRegsMtq(Z_POS_ADDR, Zdata, mtq);
	    writeRegsMtq(Z_NEG_ADDR, offData, mtq);
	}
	else if (rqt_z < 0) {
	    writeRegsMtq(Z_POS_ADDR, offData, mtq);
	    writeRegsMtq(Z_NEG_ADDR, Zdata, mtq);
	}
	else {
		writeRegsMtq(Z_POS_ADDR, offData, mtq);
	    writeRegsMtq(Z_NEG_ADDR, offData, mtq);
	}
}

//void writeFeedbackMtq(mtq_t * mtq, mtqFeed_t * mtqFeed) {
//
//  // Create union of shared memory space
//  union {
//    float fData;
//    uint8_t tempArr[4];
//  } u1;
//  union {
//    float fData;
//    uint8_t tempArr[4];
//  } u2;
//  union {
//    float fData;
//    uint8_t tempArr[4];
//  } u3;
//
//  // Overite bytes of union with float variable
//  u1.fData = mtq->requestedMoment[0];
//  u2.fData = mtq->requestedMoment[1];
//  u3.fData = mtq->requestedMoment[2];
//
//  uint8_t sendBytes[12];
//  for (uint8_t i = 0; i < 4; i++) {
//	  sendBytes[i] = u1.tempArr[i];
//	  sendBytes[i+4] = u2.tempArr[i];
//	  sendBytes[i+8] = u3.tempArr[i];
//  }
//
//  I2C_send(mtqFeed->mtqFeedHandle, FEED_ADDR, 0xF7, sendBytes, 12);
//}


