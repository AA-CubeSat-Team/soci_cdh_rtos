// photodiode wrapper

/* issues:
* albedo from Earth may mess up 3*maxV health check
*/

#include "phd_wrap.h"

// Initialize register values to be used in ADC initialization:
uint8_t advance_config_value = 0b00000001;
uint8_t test;
uint8_t conv_rate_value = 0b00000001;
uint8_t disable_value = 0b11100000;
uint8_t interrupt_mask_value = 0b00011111;
uint8_t in_high_val = 0b101; // change this (just a test for now)
uint8_t in_low_val = 0;
uint8_t config_default_value = 0b00001000;
uint8_t start_value = 0b00001001;
uint8_t int_clear_val = 0b00000001;

// diode struct
diodes_t Diodes;

// reads 'counts' number of values from registration 'reg' and stores the values in 'dest[]'
void readRegsPhd(uint8_t reg, uint8_t *value, uint8_t valueSize, diodes_t * Diodes)
{
#if ARDUINO_CODE
  Wire.beginTransmission(ADC_SER_ADDRESS);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(ADC_SER_ADDRESS, valueSize);
  int i = 0;
  while (Wire.available()) {
    *(value+i) = Wire.read();
    i++;
  }
#else
  I2C_request(Diodes->diodesHandle, ADC_SER_ADDRESS, reg, value, valueSize);
#endif
}


// writes registration 'reg' with value 'value'
void writeRegPhd(uint8_t reg, uint8_t value, diodes_t * Diodes)
{
  #if ARDUINO_CODE
  Wire.beginTransmission(ADC_SER_ADDRESS);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
  #else
  I2C_send(Diodes->diodesHandle, ADC_SER_ADDRESS, reg, &value, 1);
  #endif
}

// Initialize ADC
#if ARDUINO_CODE
void initADC(diodes_t * Diodes){
#else
void initADC(diodes_t * Diodes, lpi2c_rtos_handle_t * diodesHandle){
#endif

#if ARDUINO_CODE
  // Enable pullup resistors
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  Wire.begin();
#endif
  
  // STEP 1&2: wait until busy status register is read not busy
  uint8_t c = 1;
  while (c) {
    readRegsPhd(BUSY_STATUS_REG, &c, 1, Diodes);
  }
    
  // STEP 3: choosing internal VREF and mode of operation
  writeRegPhd(ADVANCE_CONFIG_REG,advance_config_value,Diodes);
  readRegsPhd(ADVANCE_CONFIG_REG,&advance_config_value, 1, Diodes);
  
  // STEP 4: enabling Conversion Rate Register
  writeRegPhd(CONV_RATE_REG,conv_rate_value,Diodes);
  readRegsPhd(CONV_RATE_REG,&conv_rate_value, 1, Diodes);
  
  //STEP 5: disabling unused inputs
  writeRegPhd(CONFIG_REG,config_default_value,Diodes); // Disabling pins in shutdown mode
  readRegsPhd(CONFIG_REG,&test, 1, Diodes);
  writeRegPhd(DISABLE_REG,disable_value,Diodes);
  readRegsPhd(DISABLE_REG,&disable_value, 1, Diodes);
  
  //STEP 6: enabling interrupt mask (won't go to INT pin)
  writeRegPhd(CONFIG_REG,0b00000001,Diodes); // Powering ADC back on
  writeRegPhd(INTERRUPT_MASK_REG,interrupt_mask_value,Diodes);
  readRegsPhd(INTERRUPT_MASK_REG,&interrupt_mask_value, 1, Diodes);
  
  //STEP7: sending Limits for only enable input
  writeRegPhd(IN_HIGH_REG1,in_high_val,Diodes);
  writeRegPhd(IN_LOW_REG1,in_low_val,Diodes);
  readRegsPhd(IN_HIGH_REG1,&in_high_val, 1, Diodes);
  readRegsPhd(IN_LOW_REG1,&in_low_val, 1, Diodes);
  
  in_high_val = 0b101;
  in_low_val = 0;
  writeRegPhd(IN_HIGH_REG2,in_high_val,Diodes);
  writeRegPhd(IN_LOW_REG2,in_low_val,Diodes);
  readRegsPhd(IN_HIGH_REG2,&in_high_val, 1, Diodes);
  readRegsPhd(IN_LOW_REG2,&in_low_val, 1, Diodes);
  
  in_high_val = 0b101;
  in_low_val = 0;
  writeRegPhd(IN_HIGH_REG3,in_high_val,Diodes);
  writeRegPhd(IN_LOW_REG3,in_low_val,Diodes);
  readRegsPhd(IN_HIGH_REG3,&in_high_val, 1, Diodes);
  readRegsPhd(IN_LOW_REG3,&in_low_val, 1, Diodes);
  
  in_high_val = 0b101;
  in_low_val = 0;
  writeRegPhd(IN_HIGH_REG4,in_high_val,Diodes);
  writeRegPhd(IN_LOW_REG4,in_low_val,Diodes);
  readRegsPhd(IN_HIGH_REG4,&in_high_val, 1, Diodes);
  readRegsPhd(IN_LOW_REG4,&in_low_val, 1, Diodes);
  
  in_high_val = 0b101;
  in_low_val = 0;
  writeRegPhd(IN_HIGH_REG5,in_high_val,Diodes);
  writeRegPhd(IN_LOW_REG5,in_low_val,Diodes);
  readRegsPhd(IN_HIGH_REG5,&in_high_val, 1, Diodes);
  readRegsPhd(IN_LOW_REG5,&in_low_val, 1, Diodes);
    
  //STEP 8: setting Start bit to 1   
  writeRegPhd(CONFIG_REG, start_value,Diodes);
  readRegsPhd(CONFIG_REG,&c, 1, Diodes);
  
  //STEP 9: setting interrupt to zero
  writeRegPhd(CONFIG_REG,int_clear_val,Diodes);
  readRegsPhd(CONFIG_REG,&int_clear_val, 1, Diodes);
}


// health check: if any channel exceeds the maxV or all 5 channels exceed 3*maxV (only three side of satellite can face sun) when summed: 
// 1) resets registers to default values and puts ADC into shutdown mode. 
// 2) reinitializes ADC to proper configuration (same as quickstart procedure).
#if ARDUINO_CODE
void health(diodes_t * Diodes){
#else
void health(diodes_t * Diodes, lpi2c_rtos_handle_t * diodesHandle){
#endif
if((Diodes->current[0] > MAX_CURRENT || Diodes->current[1] > MAX_CURRENT ||
  Diodes->current[2] > MAX_CURRENT || Diodes->current[3] > MAX_CURRENT || 
  Diodes->current[4] > MAX_CURRENT) || Diodes->current[0] + Diodes->current[1] +
  Diodes->current[2] + Diodes->current[3] + Diodes->current[4] > 3*MAX_CURRENT){
  writeRegPhd(CONFIG_REG, 0b01001000,Diodes);
#if ARDUINO_CODE
  initADC(Diodes);
#else
  initADC(Diodes, diodesHandle);
#endif
}
}


// reads voltages from ADC
void getVoltage(diodes_t * Diodes){
  // recieve data from ADC
//    j = 0;
//    for(i=0; i<sizeof(PD_REG_ARRAY); i++){ 
//      Wire.beginTransmission(ADC_SER_ADDRESS);            
//      Wire.write(PD_REG_ARRAY[i]);     // write register address
//      Wire.endTransmission(false);
//      
//      Wire.requestFrom(ADC_SER_ADDRESS,uint8_t(2));
//      while(Wire.available()){
//        PDVol[j] = Wire.read();     // data byte 1
//        PDVol[j+1] = Wire.read();     // data byte 2
//      }
//      j = j+2;
//    }
//    
//    // process data and hold current 5 values in 'current' buffer
//    j = 0;
//    for(i=0;i<5;i++){
//      D_out[i] = PDVol[j]<<8 | PDVol[j+1];
//      j = j+2;
//    }

//    Diodes->current_pos_x = uint16_t((((D_out[0]/4096)*V_REF)/R)*1000); // current calculated in uA (micro Amps)
//    Diodes->current_neg_x = uint16_t((((D_out[3]/4096)*V_REF)/R)*1000);
//    Diodes->current_pos_y = uint16_t((((D_out[1]/4096)*V_REF)/R)*1000);
//    Diodes->current_neg_y = uint16_t((((D_out[2]/4096)*V_REF)/R)*1000);
//    Diodes->current_pos_z = uint16_t((((D_out[4]/4096)*V_REF)/R)*1000);

  uint8_t PDVol[10];
  uint16_t D_out[5];
  readRegsPhd(PD1_REG, PDVol, 10, Diodes);

  for (int i = 0; i < 5; i++) {
    D_out[i] = ((uint16_t)PDVol[2*i]<<8 | (uint16_t)PDVol[2*i + 1]);
    Diodes->current[i] = (((D_out[i]/4096)*V_REF)/R)*1000;
  }
}
