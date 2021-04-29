/*
 * MCU Pinouts:

EPS:

75	GPIO_AD_B1_14	I2C1_SCL	EPS, MAG1, GYRO1
74	GPIO_AD_B1_15	I2C1_SDA	EPS, MAG1, GYRO1
 */


#pragma once
#include <stdint.h>
#include <stdbool.h>


bool eps_healthcheck();

double i2c_eps_getBatteryLevel();

uint8_t i2c_eps_powerModuleStatus();

uint8_t i2c_eps_batteryModuleStatus();

void i2c_eps_FDIRflag();

void i2c_eps_idRegister();

void i2c_eps_watchdogPeriod(uint8_t period);

void i2c_eps_setPdmsInitialState(uint8_t pdm_state);

void i2c_eps_resetPdm();

void i2c_eps_switchOnOffPdms(uint8_t newPdmState);

void i2c_eps_getTelemetryGroup(uint16_t families);

void i2c_eps_setHousekeepingPeriod(uint8_t period);

void i2c_eps_setSafetyHazardEnvironment();

void i2c_eps_fixedPowerBusReset(uint8_t busReset);

void i2c_eps_manualReset();














