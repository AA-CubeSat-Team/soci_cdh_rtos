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


#include <stdbool.h>


bool sens_healthcheck();
void sens_readSun();
void sens_readMag();
void sens_readPhd();
void sens_readGyr();

