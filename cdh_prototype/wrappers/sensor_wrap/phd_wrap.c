// photodiode wrapper

/* issues:
* albedo from Earth may mess up 3*maxV health check
*/

#include "phd_wrap.h"
#include "com_protocol_helper.h"

#define PHD_ADC_SER_ADDRESS (uint8_t)0x1D // ADC address

// Define all registers:
#define PHD1_REG            0x20
#define ADVANCE_CONFIG_REG  0x0B
#define CONFIG_REG          0x00
#define CONV_RATE_REG       0x07
#define DISABLE_REG         0x08
#define BUSY_STATUS_REG     0x0C

// Define values for current calculations:
#define R           10      // Resistance in kilo Ohms
#define V_REF       3.3       // Voltage in V
#define MAX_CURRENT 170

// Initialize register values to be used in ADC initialization:
#define ADVANCE_CONFIG_VALUE  0b00000001
#define CONV_RATE_VALUE       0b00000001
#define DISABLE_VALUE         0b11100000
#define CONFIG_DEFAULT_VALUE  0b00001000
#define START_VALUE           0b00000001

// diode struct
phd_t Phd1;

// reads 'counts' number of values from registration 'reg' and stores the values in 'dest[]'
void readRegsPhd(uint8_t reg, uint8_t *value, uint8_t valueSize, phd_t * Phd)
{
#if ARDUINO_CODE
  Wire.beginTransmission(PHD_ADC_SER_ADDRESS);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(PHD_ADC_SER_ADDRESS, valueSize);
  int i = 0;
  while (Wire.available()) {
    *(value+i) = Wire.read();
    i++;
  }
#else
  I2C_request(Phd->PhdHandle, &LPI2C1_masterTransfer, PHD_ADC_SER_ADDRESS, reg, value, valueSize);
#endif
}

// writes registration 'reg' with value 'value'
void writeRegPhd(uint8_t reg, uint8_t value, phd_t * Phd)
{
  #if ARDUINO_CODE
  Wire.beginTransmission(PHD_ADC_SER_ADDRESS);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
  #else
  uint8_t send_buff[2];
  send_buff[0] = reg;
  send_buff[1] = value;
  I2C_send(Phd->PhdHandle, &LPI2C1_masterTransfer, PHD_ADC_SER_ADDRESS, 0, send_buff, 2);
  #endif
}

// Initialize ADC
#if ARDUINO_CODE
void quickStartPhd(phd_t * Phd){
#else
void quickStartPhd(phd_t * Phd, lpi2c_rtos_handle_t * PhdHandle){
#endif

#if ARDUINO_CODE
  Wire.begin();
#else
  Phd->PhdHandle = PhdHandle;
#endif
  // STEP 1&2: wait until busy status register is read not busy
  uint8_t busyFlag = 2;
  uint8_t iteration = 0;
  while (busyFlag>>1) {
    readRegsPhd(BUSY_STATUS_REG, &busyFlag, 1, Phd);
    iteration = iteration+1;
    printf("%d, \n", iteration);
    if (iteration > 100) {
    	Phd->errorFlag = 1;
    	break;
    }
  }
  writeRegPhd(CONFIG_REG,CONFIG_DEFAULT_VALUE,Phd); // Disabling pins in shutdown mode
  // STEP 3: choosing internal VREF and mode of operation
  writeRegPhd(ADVANCE_CONFIG_REG, ADVANCE_CONFIG_VALUE,Phd);
  // STEP 4: enabling Conversion Rate Register
  writeRegPhd(CONV_RATE_REG,CONV_RATE_VALUE,Phd);  
  //STEP 5: disabling unused inputs
  writeRegPhd(DISABLE_REG,DISABLE_VALUE,Phd);
  //STEP 6: enabling interrupt mask (won't go to INT pin, skip)
  //STEP7: sending Limits for only enable input (won't go to INT pin, skip)   
  //STEP 8: setting Start bit to 1
  writeRegPhd(CONFIG_REG,START_VALUE,Phd);
  //STEP 9: setting interrupt to zero (won't go to INT pin, skip)
  Phd->errorFlag = 0;
}

// health check: if any channel exceeds the maxV or all 5 channels exceed 3*maxV (only three side of satellite can face sun) when summed: 
// 1) resets registers to default values and puts ADC into shutdown mode. 
// 2) reinitializes ADC to proper configuration (same as quickstart procedure).
#if ARDUINO_CODE
void health(phd_t * Phd){
#else
void health(phd_t * Phd, lpi2c_rtos_handle_t * diodesHandle){
#endif
if((Phd->current[0] > MAX_CURRENT || Phd->current[1] > MAX_CURRENT ||
  Phd->current[2] > MAX_CURRENT || Phd->current[3] > MAX_CURRENT || 
  Phd->current[4] > MAX_CURRENT) || Phd->current[0] + Phd->current[1] +
  Phd->current[2] + Phd->current[3] + Phd->current[4] > 3*MAX_CURRENT){
  writeRegPhd(CONFIG_REG, 0b01001000,Phd);
  Phd->errorFlag = 2;
#if ARDUINO_CODE
  quickStartPhd(Phd);
#else
  quickStartPhd(Phd, diodesHandle);
#endif
}
else {
  Phd->errorFlag = 0;
}
}

// reads voltages from ADC
void readPhdData(phd_t * Phd, lpi2c_rtos_handle_t * Handle){
  uint8_t rawData8[2];
  uint16_t rawData16;
  health(Phd, Handle);
  
  for (int i = 0; i < 5; i++) {
    readRegsPhd(PHD1_REG + i, rawData8, 2, Phd);
    rawData16 = ((uint16_t)rawData8[0]<<8 | (uint16_t)rawData8[1])>>4;
    Phd->current[i] = (double)rawData16/4096*V_REF/R*1000;
  }

}
