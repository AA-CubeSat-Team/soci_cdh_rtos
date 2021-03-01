/*
 * MCU Pinouts:

Gyroscope, Photodiodes:

75	GPIO_AD_B1_14	I2C1_SCL	EPS, MAG1, GYRO1
74	GPIO_AD_B1_15	I2C1_SDA	EPS, MAG1, GYRO1
82	GPIO_AD_B1_08	I2C2_SCL	MAG2, GYRO2, PhotodiodeADC
81	GPIO_AD_B1_09	I2C2_SDA	MAG2, GYRO2, PhotodiodeADC
100	GPIO_AD_B0_08	I2C3_SCL	MAG3, GYRO3
99	GPIO_AD_B0_09	I2C3_SDA	MAG3, GYRO3

----------------------------------------------------------

Sun Sensor:

94	GPIO_AD_B0_14	UART3_TX	Sun Sensor
93	GPIO_AD_B0_15	UART3_RX	Sun Sensor

 */
#include "dummy_type.h"
#include <sen_wrap.h>
#include "fsl_lpuart_freertos.h"
#include "fsl_lpuart.h"
#include "fsl_lpi2c_freertos.h"
#include "fsl_lpi2c.h"
#include "fsl_debug_console.h"
#include <stdbool.h>
#include "peripherals.h"

extern sensor_bus sens_var;

bool sens_healthcheck(){
	PRINTF("checking sensors health\r\n");
	return true;
}
//do each sensor separately
void sens_readSun(){
	PRINTF("reading sun sensors\r\n");
	sens_var.sun_meas_ss_deg[0] = 180;
}

void sens_readMag(){
	PRINTF("reading magnetometer sensors\r\n");
	sens_var.mag_body_T[0] = 111;
}

void sens_readPhd(){
	PRINTF("reading photodiode sensors\r\n");
	sens_var.photodiodes_A[0] = 222;
}

void sens_readGyr(){
	PRINTF("reading gyroscope sensors\r\n");
	sens_var.gyro_body_radps[0] = 333;
	//loop() in gyro.ino by Alex
}
