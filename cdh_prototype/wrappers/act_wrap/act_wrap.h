/*
 * MCU Pinouts:

Magnetorquer:

75	GPIO_AD_B1_14	I2C1_SCL	EPS, MAG1, GYRO1
74	GPIO_AD_B1_15	I2C1_SDA	EPS, MAG1, GYRO1
82	GPIO_AD_B1_08	I2C2_SCL	MAG2, GYRO2, PhotodiodeADC
81	GPIO_AD_B1_09	I2C2_SDA	MAG2, GYRO2, PhotodiodeADC
100	GPIO_AD_B0_08	I2C3_SCL	MAG3, GYRO3
99	GPIO_AD_B0_09	I2C3_SDA	MAG3, GYRO3

------------------------------------------------------------------------

Reaction wheel:

96	GPIO_AD_B0_12	SPI1_MOSI	RXN Wheels
95	GPIO_AD_B0_13	SPI1_MISO	RXN Wheels
98	GPIO_AD_B0_10	SPI1_SCK	RXN Wheels
97	GPIO_AD_B0_11	SPI1_PCS0	Chip Select - RXN Wheel 1
88	GPIO_AD_B1_04	SPI1_PCS1	Chip Select - RXN Wheel 2
87	GPIO_AD_B1_05	SPI1_PCS2	Chip Select - RXN Wheel 3
84	GPIO_AD_B1_06	SPI1_PCS3	Chip Select - RXN Wheel 4
92	GPIO_AD_B1_00	SPI1_EN0	Enable - RXN Wheel 1
91	GPIO_AD_B1_01	SPI1_EN1	Enable - RXN Wheel 2
90	GPIO_AD_B1_02	SPI1_EN2	Enable - RXN Wheel 3
89	GPIO_AD_B1_03	SPI1_EN3	Enable - RXN Wheel 4
 */

#include <stdbool.h>

bool rwa_healthcheck();
bool mtq_healthcheck();
void readActMeas();
void gnc_sendCommand();
void rt_OneStep(void);
