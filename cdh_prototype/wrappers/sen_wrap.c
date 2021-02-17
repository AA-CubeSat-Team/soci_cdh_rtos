/*
 * 94	GPIO_AD_B0_14	UART3_TX	Sun Sensor
 * 93	GPIO_AD_B0_15	UART3_RX	Sun Sensor
 * 75	GPIO_AD_B1_14	I2C1_SCL	EPS, MAG1, GYRO1
 * 74	GPIO_AD_B1_15	I2C1_SDA	EPS, MAG1, GYRO1
 * 82	GPIO_AD_B1_08	I2C2_SCL	MAG2, GYRO2, PhotodiodeADC
 * 81	GPIO_AD_B1_09	I2C2_SDA	MAG2, GYRO2, PhotodiodeADC
 * 100	GPIO_AD_B0_08	I2C3_SCL	MAG3, GYRO3
 * 99	GPIO_AD_B0_09	I2C3_SDA	MAG3, GYRO3
 *
 */
#include <sen_wrap.h>
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include <stdbool.h>


/*
 * solar_panel_power, phd, mag, sun_sensor, gyro
 *
 * struct {
  real_T solar_panel_power_W[6];
  real_T photodiodes_A[6];
  real_T mag_body_T[9];
  boolean_T mag_meas_valid[3];
  real_T sun_meas_ss_deg[2];
  boolean_T sun_meas_valid;
  real_T gyro_body_radps[9];
  boolean_T gyro_meas_valid[3];
} sensor_bus;
 */

bool sens_healthcheck(){
	PRINTF("checking sensors health");
	return true;
}
//do each sensor separately
void sens_readSun(){
	PRINTF("reading sun sensors");
}

void sens_readMag(){
	PRINTF("reading magnetometer sensors");
}

void sens_readPhd(){
	PRINTF("reading photodiode sensors");
}

void sens_readGyr(){
	PRINTF("reading gyroscope sensors");
	//loop() in gyro.ino by Alex
}
