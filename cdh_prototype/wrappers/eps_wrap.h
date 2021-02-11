/*
 *
 * GPIO_AD_B1_14	I2C1_SCL
 * GPIO_AD_B1_15	I2C1_SDA
 *
 *
 *
 * */


#pragma once
#include <stdint.h>
#include <stdbool.h>


//#include "soci_cdh_drivers\cdh_i2c_driver\drivers\fsl_common.h"
//#include "soci_cdh_drivers\cdh_i2c_driver\board\board.h"

/******************** I2C definitions taken from soci_cdh_drivers\cdh_i2c_driver\source\freertos_lpi2c.c ********************/

#define EXAMPLE_I2C_MASTER_BASE (LPI2C1_BASE)
#define EXAMPLE_I2C_MASTER_IRQN (LPI2C1_IRQn)
#define EXAMPLE_I2C_SLAVE_BASE (LPI2C3_BASE)
#define EXAMPLE_I2C_SLAVE_IRQN (LPI2C3_IRQn)

/* Select USB1 PLL (480 MHz) as master lpi2c clock source */
#define LPI2C_CLOCK_SOURCE_SELECT (0U)
/* Clock divider for master lpi2c clock source */
#define LPI2C_CLOCK_SOURCE_DIVIDER (5U)
/* Get frequency of lpi2c clock */
#define LPI2C_CLOCK_FREQUENCY ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (LPI2C_CLOCK_SOURCE_DIVIDER + 1U))

/* clang-format off */
/*
The example support single board communication(one instance works as master, another
instance works as slave) or board to board communication. Default is single board mode.
*/
#define SINGLE_BOARD 0
#define BOARD_TO_BOARD 1
#ifndef EXAMPLE_CONNECT_I2C
#define EXAMPLE_CONNECT_I2C SINGLE_BOARD
#endif /* EXAMPLE_CONNECT_I2C */
#if (EXAMPLE_CONNECT_I2C == BOARD_TO_BOARD)
#define isMASTER 0
#define isSLAVE 1
#ifndef I2C_MASTER_SLAVE
#define I2C_MASTER_SLAVE isMASTER
#endif /* I2C_MASTER_SLAVE */
#endif /* EXAMPLE_CONNECT_I2C */

#define EXAMPLE_I2C_MASTER   ((LPI2C_Type *)EXAMPLE_I2C_MASTER_BASE)
#define EXAMPLE_I2C_SLAVE   ((LPI2C_Type *)EXAMPLE_I2C_SLAVE_BASE)

#define I2C_MASTER_SLAVE_ADDR_7BIT (0x7EU)
#define I2C_BAUDRATE (100000) /* 100K */
#define I2C_DATA_LENGTH (6) /* MAX is 256 */


/******************** EPS definitions ********************/

// added 11/3/20 (new eps check later)
//__________________________________________________________
// commands pg 9
#define I2C_EPS_CMD_POWER_MODULE_STATUS 0x01
#define I2C_EPS_CMD_BATTERY_MODULE_STATUS 0x02
#define I2C_EPS_CMD_FDIR 0x03
#define I2C_EPS_CMD_ID 0x04
#define I2C_EPS_CMD_SET_WATCHDOG_PERIOD 0x05
#define I2C_EPS_CMD_SET_PDMS_INTIAL_STATE 0x06
#define I2C_EPS_CMD_RESET_PDMS 0x07
#define I2C_EPS_CMD_SWITCH_ON_OFF_PDMS 0x08
#define I2C_EPS_CMD_SET_HOUSEKEEPING_PERIOD 0x09
#define I2C_EPS_CMD_SET_SAFETY_HAZARD_ENVIRONMENT 0x0A
// put telemetry
#define I2C_EPS_CMD_FIXED_POWER_BUS_RESET 0xFE
#define I2C_EPS_CMD_MANUAL_RESET 0xFF

// telemetry pg 14
// check if thinking about correctly
// for param[1] (where in I2C is parameter?)
// also how do you read the byte and bit
#define I2C_EPS_TELE_BCRS 0x00
#define I2C_EPS_TELE_SOLAR_PANEL_SENSORS 0x01
#define I2C_EPS_TELE_POWER_BUSES 0x02
#define I2C_EPS_TELE_SWITCHABLE_POWER_BUSEs 0x03
#define I2C_EPS_TELE_BATTERY_MODULE 0x04
#define I2C_EPS_TELE_SYSTEM_DATA 0x05

#define I2C_EPS_BYTE_0 0x00
#define I2C_EPS_BYTE_2 0x02
#define I2C_EPS_BYTE_4 0x04
#define I2C_EPS_BYTE_6 0x06
#define I2C_EPS_BYTE_8 0x08
#define I2C_EPS_BYTE_10 0x10
#define I2C_EPS_BYTE_12 0x12
#define I2C_EPS_BYTE_14 0x14
#define I2C_EPS_BYTE_16 0x16
#define I2C_EPS_BYTE_18 0x18
#define I2C_EPS_BYTE_20 0x20
#define I2C_EPS_BYTE_22 0x22


char i2c_eps_batteryModuleStatus();
char i2c_eps_powerModuleStatus();
bool i2c_eps_idRegister();
char i2c_eps_FDIRflag();

bool eps_healthcheck();
double i2c_eps_getBatteryLevel();














