#ifndef PHD_WRAP_H_
#define PHD_WRAP_H_
  // photodiode wrapper

#define ARDUINO_CODE  0

#if ARDUINO_CODE
  #include <Arduino.h>
  #include <Wire.h>
#else
#include "fsl_lpi2c.h"
#include "fsl_lpi2c_freertos.h"
#include "peripherals.h"
#endif



  /*!
 * @brief Structure contains information about one gyroscope
 *
 */
typedef struct _Phd
{
  double current[5];   ////// Current reported to flight software in uA (micro Amps) ///////
    
  #if !ARDUINO_CODE
  	lpi2c_rtos_handle_t * PhdHandle;
  #endif

} phd_t;

extern phd_t Phd1;

void readRegsPhd(uint8_t reg, uint8_t *value, uint8_t valueSize, phd_t * Phd);
void writeRegPhd(uint8_t reg, uint8_t value, phd_t * Phd);

#if ARDUINO_CODE
void quickStartPhd(phd_t * Phd);
#else
void quickStartPhd(phd_t * Phd, lpi2c_rtos_handle_t * PhdHandle);
#endif

#if ARDUINO_CODE
void health(phd_t * Phd);
#else
void health(phd_t * Phd, lpi2c_rtos_handle_t * PhdHandle);
#endif

void readPhdData(phd_t * Phd);
#endif
