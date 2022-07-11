/* This is a source file for testing the I2C commands required for the flight computer to
 * communicate with the EPS board and the battery
 *
 * As of 6/23/2020, everything in this file is being written without any access to hardware, and is completely untested.
 * It should not be assumed to be functional.
 *
 * Jerrold Erickson, 6/23/2020
 * Ryan Park, 2/27/2021
 *
MCU Pinouts:
EPS:
75	GPIO_AD_B1_14	I2C1_SCL	EPS, MAG1, GYRO1
74	GPIO_AD_B1_15	I2C1_SDA	EPS, MAG1, GYRO1
 */


#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include <stdbool.h>
#include "eps_wrap.h"
#include "fsl_lpi2c.h" //need these here? already in peripherals
#include "fsl_lpi2c_freertos.h"
#include "peripherals.h"

#include "fsl_debug_console.h"

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
#define I2C_EPS_CMD_GET_TELEMETRY_GROUP 0x0B
#define I2C_EPS_CMD_FIXED_POWER_BUS_RESET 0xFE
#define I2C_EPS_CMD_MANUAL_RESET 0xFF

#define I2C_EPS_TELE_BCRS 0x00
#define I2C_EPS_TELE_SOLAR_PANEL_SENSORS 0x01
#define I2C_EPS_TELE_POWER_BUSES 0x02
#define I2C_EPS_TELE_SWITCHABLE_POWER_BUSES 0x03
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

#define BYTE16CAST 0xFF
#define VERIFIED_COM_MASK 0x67D6
#define VOLTAGE_MASK 0xFF0000000000000000
#define NO_RETURN 9999


#define EPS_SLAVE_ADDR 0x51
#define I2C_DATA_LENGTH 4

bool eps_healthy;

uint8_t buffer[I2C_DATA_LENGTH];
static uint32_t adc_count;

bool eps_healthcheck() {
	PRINTF("checking the health of eps!\r\n");
	//	TickType_t xLastWakeTime = xTaskGetTickCount();
	//	vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS( 10 ));
	i2c_eps_idRegister();
	i2c_eps_powerModuleStatus();
	i2c_eps_batteryModuleStatus();
	i2c_eps_FDIRflag();
	PRINTF("Finish delay\r\n");
	return eps_healthy;
}

/* the I2C_read_write_lp function is designed to write to registers within the i2c slave device, so writing i2c data looks like this:
 * [device address -> register address -> data]
 * The EPS/battery do not use registers like this, and instead just follow a format like:
 * [device address -> command -> parameters]
 * So, this register address is just temporary. A more complete i2c library is needed.
 */

static void i2c_read_write_helper(uint8_t* i2c_send_buffer, size_t tx_size, uint8_t * i2c_recv_buffer, size_t rx_size, time_t d) {
	I2C_send(&LPI2C1_masterHandle, EPS_SLAVE_ADDR, 0, i2c_send_buffer, tx_size);
	if (d != NO_RETURN) {
		I2C_request(&LPI2C1_masterHandle, EPS_SLAVE_ADDR, 0, i2c_recv_buffer, rx_size);
	}
	adc_count = 0;

}


// added 11/24/20
//__________________________________________________________________________________________________________________

double i2c_eps_getBatteryLevel()
{
	memset(buffer, 0, 2);
	buffer[0] = 0x0B;
	buffer[1] = 0x02;

	uint8_t recv_buffer[24];

	i2c_read_write_helper(buffer, sizeof(buffer), recv_buffer, sizeof(recv_buffer), 5000);

	// select bits of buffer for vbat
	uint16_t voltage_buff = 0;
	voltage_buff = (recv_buffer[17] << 8) | recv_buffer[16];

	// apply correction for voltage
	double correction = 0.0030945;
	double voltage = voltage_buff * correction;
	return voltage;
}

uint32_t i2c_eps_powerModuleStatus()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_POWER_MODULE_STATUS;

	uint8_t recv_buffer[2];
	i2c_read_write_helper(buffer, 1, recv_buffer, 2, 5000);

	adc_count = 0;
	for(int i=1; i>=0; i--)
	{
		adc_count <<= 8;
		adc_count |= recv_buffer[i];
	}

	if (adc_count & (1 << 0))
	{
		PRINTF("3V3 output error\n");
		i2c_eps_fixedPowerBusReset(0x03);
	}
	if (adc_count & (1 << 1))
	{
		PRINTF("5V output error\n");
		i2c_eps_fixedPowerBusReset(0x0C);
	}
	if (adc_count & (1 << 2))
	{
		PRINTF("12V output error\n");
		i2c_eps_fixedPowerBusReset(0x30);
	}
	if (adc_count & (1 << 8))
	{
		PRINTF("PDM1 error\n");
		i2c_eps_resetPdm();
	}
	if (adc_count & (1 << 9))
	{
		PRINTF("PDM2 error\n");
		i2c_eps_resetPdm();
	}
	if (adc_count & (1 << 10))
	{
		PRINTF("PDM3 error\n");
		i2c_eps_resetPdm();
	}
	if (adc_count & (1 << 11))
	{
		PRINTF("PDM4 error\n");
		i2c_eps_resetPdm();
	}
	if (adc_count & (1 << 12))
	{
		PRINTF("PDM5 error\n");
		i2c_eps_resetPdm();
	}
	if (adc_count & (1 << 13))
	{
		PRINTF("PDM6 error\n");
		i2c_eps_resetPdm();
	}
	if (adc_count != 0) {
		eps_healthy = false;
	} else {
		eps_healthy = true;
	}
	return adc_count;
}

uint32_t i2c_eps_batteryModuleStatus()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_BATTERY_MODULE_STATUS;

	uint8_t recv_buffer[2];
	i2c_read_write_helper(buffer, 1, recv_buffer, 2, 5000);

	adc_count = 0;
	for(int i=1; i>=0; i--)
	{
		adc_count <<= 8;
		adc_count |= recv_buffer[i];
	}

	if (adc_count & (1 << 0))
	{
		PRINTF("CC, Charge Control Flag. Set if battery charge is disabled.\n");
		eps_healthy = false;
	}
	if (adc_count & (1 << 1))
	{
		PRINTF("DC, Discharge Control Flag. Set if battery discharge is disabled.\n");
		eps_healthy = false;
	}
	if (adc_count & (1 << 2))
	{
		PRINTF(" CHGTF, Charge-Termination Flag. Set if battery is fully charged.\n");
		eps_healthy = true;
	}
	if (adc_count & (1 << 4))
	{
		PRINTF("SEF, Standby-Empty Flag. Set if capacity is below 10%%, unset if above 15 %%.\n");
		eps_healthy = true;
	}
	if (adc_count & (1 << 8))
	{
		PRINTF("Set if heater is active.\n");
		eps_healthy = true;
	}
	if (adc_count & (1 << 12))
	{
		PRINTF("Set if battery balancing is happening from top cell to bottom cell.\n");
		eps_healthy = true;
	}
	if (adc_count & (1 << 13))
	{
		PRINTF("Set if battery balancing is happening from bottom cell to top cell.\n");
		eps_healthy = true;
	}
	if (adc_count == 0) {
		eps_healthy = true;
	}
	return adc_count;
}

void i2c_eps_FDIRflag()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_FDIR;

	uint8_t recv_buffer[2];
	i2c_read_write_helper(buffer, 1, recv_buffer, 2, 5000);

	adc_count = 0;
	for(int i=1; i>=0; i--) //converts byte array into 32 bit adc_count
	{
		adc_count <<= 8;
		adc_count |= recv_buffer[i];
	}

	if (adc_count & (1 << 0))
	{
		PRINTF("0 Set if last was command unknown\n");
		eps_healthy = true;
	}
	if (adc_count & (1 << 1))
	{
		PRINTF("Set if last command parameter was invalid.\n");
		eps_healthy = true;
	}
	if (adc_count & (1 << 2))
	{
		PRINTF("Set if watchdog was triggered.\n");
		eps_healthy = true;
	}
	if (adc_count & (1 << 3))
	{
		PRINTF("Set if BOR was triggered.\n");
		eps_healthy = true;
	}
	if (adc_count & (1 << 5))
	{
		PRINTF("Set if battery manager is unavailable.\n");
		eps_healthy = true;
	}
	if (adc_count & (1 << 6))
	{
		PRINTF("Set if VBAT1_ADC is out of range.\n");
		eps_healthy = false;
	}
	if (adc_count & (1 << 7))
	{
		PRINTF("Set if VBAT2_ADC is out of range.\n");
		eps_healthy = false;
	}
	if (adc_count & (1 << 8))
	{
		PRINTF("Set if IBAT_BM is out of range.\n");
		eps_healthy = false;
	}
	if (adc_count & (1 << 9))
	{
		PRINTF("Set if TEMP_BM is out of range.\n");
		eps_healthy = false;
	}
	if (adc_count & (1 << 10))
	{
		PRINTF("Set if TEMP_MB is out of range.\n");
		eps_healthy = false;
	}
	if (adc_count & (1 << 11))
	{
		PRINTF("Set if TEMP_DB1 is out of range.\n");
		eps_healthy = false;
	}
	if (adc_count == 0) {
		eps_healthy = true;
	}
	return;
}

void i2c_eps_idRegister() ///make bool?
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_ID;

	uint8_t recv_buffer;
	i2c_read_write_helper(buffer, 1, &recv_buffer, 1, 5000);

	bool verified_com;
	verified_com = recv_buffer && VERIFIED_COM_MASK;
	if (verified_com) {
		PRINTF("Communication is verified with module \n");
		eps_healthy = true;
	}
	else {
		PRINTF("Communication is NOT verified with module \n");
		eps_healthy = false;
	}
	return;
}

// for watchdog, userinput period
// only accepts 1, 2, 4 for each period in minutes
void i2c_eps_watchdogPeriod(uint8_t period)
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_SET_WATCHDOG_PERIOD;
	buffer[1] = 0x0000 | period;
	i2c_read_write_helper(buffer, 2, 0, 0, NO_RETURN);

	return;
}


// Set PDM initial state has input for initial state
// pdm_state = set bit: 00******
// bit 0 effects PDM1 state, bit 1 effects PDM2 state, and so on...
void i2c_eps_setPdmsInitialState(uint8_t pdm_state)
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_SET_PDMS_INTIAL_STATE;
	buffer[1] = 0x00 | pdm_state;

	i2c_read_write_helper(buffer, 2, 0, 0, NO_RETURN);
	return;
}

void i2c_eps_resetPdm()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_RESET_PDMS;
	buffer[1] = 0xFF;

	i2c_read_write_helper(buffer, 2, 0, 0, NO_RETURN);
	return;
}

// added 12/6/20
// will skip on doing telemtry for now until answers on how it outputs is provided
//
// for this newPdmState will turn on specific pdm 1-6 which is assigned from bit 0-5 in that order
void i2c_eps_switchOnOffPdms(uint8_t newPdmState)
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_SWITCH_ON_OFF_PDMS;
	buffer[1] = 0x00 | newPdmState;

	i2c_read_write_helper(buffer, 2, 0, 0, NO_RETURN);

	return;
}

// period can be 1 min 2 min or 4 min
void i2c_eps_setHousekeepingPeriod(uint8_t period)
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_SET_HOUSEKEEPING_PERIOD;
	buffer[1] = 0x00 | period;

	i2c_read_write_helper(buffer, 2, 0, 0, NO_RETURN);

	return;
}

// QUESTION: how is the i2c write structured
// is it 7 bit address -> command -> param [1] -> param [0] (each a byte)
// IF SO -> then what for PDM initial state why is it Byte 0 and not Param[0] (typo? as nothing is returned)

void i2c_eps_setSafetyHazardEnvironment()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_SET_SAFETY_HAZARD_ENVIRONMENT;
	buffer[1] = 0x00;
	buffer[2] = 0xFF;

	i2c_read_write_helper(buffer, 3, 0, 0, NO_RETURN);

	return;
}


//// TELEMETRY____________________________________________________________________________________________________________
//// Would like a check from CDH
//// added 2/20/21
//// for telemetry the buffer needed for the complete family is different
//// may want to add a user input line instead of families input
//

// twos compliment times 0.5 which is needed to convert the temperatures below
static int twosComp(uint16_t x)
{
	return (1 + ~(unsigned)x) & BYTE16CAST; //TODO: Check this!
}

// telemetry helper function declarations
void telemetry_bcrs(uint8_t * data);
void telemetry_solarPanelSensors(uint8_t * data);
void telemetry_powerBuses(uint8_t * data);
void telemetry_switchablePowerBuses(uint8_t * data);
void telemetry_batteryModule(uint8_t * data);
void telemetry_systemData(uint8_t * data);

// VERSION 2 OF TELEMETRY - SAVES RUNTIME AND SPACE____________________________________
// I feel like for convenience we can have user type the family they want and it will be
// the input for families which can set the buffer
void i2c_eps_getTelemetryGroup(uint16_t families)
{
	/* Set up i2c master to send data to slave */
	buffer[0] = I2C_EPS_CMD_GET_TELEMETRY_GROUP; // i2c command = get EPS telemetry

	// possible families
	// 0x00 BCRs
	// 0x01 Solar Panel Sensors
	// 0x02 Power Buses
	// 0x03 Switchable Power Buses
	// 0x04 Battery Module
	// 0x05 System Data

	// add user input here
	buffer[1] = families; //TODO: this is 16 bits being written into 8 bits!

	uint8_t recv_buffer[24]; //holds array of 24 bytes

	i2c_read_write_helper(buffer, 2, recv_buffer, 24, 5000);

	/* get the ADC count returned using bitwise operations
	 * adc_count will be a 32-bit int of the form:
	 * {0x00     0x00     g_slave_buff[1]     g_slave_buff[0]}
	 * I don't know if this calculation is correct
	 */


	 // Depending on family, there is a limit to which branch can be selected
	 // 24 bytes		BCRs
	 // 10 bytes		Solar Panel Temperature
	 // 24 bytes		Power Module
	 // 24 bytes		Switchable Power Buses
	 // 16 bytes		Battery Module Telemetry
	 // 12 bytes		System Data

	// for calculations on which family
	if (families == 0x00)
	{
		telemetry_bcrs(recv_buffer);
	}
	else if (families == 0x01)
	{
		telemetry_solarPanelSensors(recv_buffer);
	}
	else if (families == 0x02)
	{
		telemetry_powerBuses(recv_buffer);
	}
	else if (families == 0x03)
	{
		telemetry_switchablePowerBuses(recv_buffer);
	}
	else if (families == 0x04)
	{
		telemetry_batteryModule(recv_buffer);
	}
	else if (families == 0x05)
	{
		telemetry_systemData(recv_buffer);
	}

	return;
}


// TELEMETRY HELPER FUNCTIONS

void telemetry_bcrs(uint8_t * data)
{
	PRINTF ("\r\n");
	PRINTF ("BCRs Telemetry\r\n");
	PRINTF ("------------------\r\n");

	double tm1 = ((data[1] << 8) | data[0]) * 0.008;
	double tm2 = ((data[3] << 8) | data[2]) * 2;
	double tm3 = ((data[5] << 8) | data[4]) * 0.008;
	double tm4 = ((data[7] << 8) | data[6]) * 2;
	double tm5 = ((data[9] << 8) | data[8]) * 0.008;
	double tm6 = ((data[11] << 8) | data[10]) * 2;
	double tm7 = ((data[13] << 8) | data[12]) * 0.008;
	double tm8 = ((data[15] << 8) | data[14]) * 2;
	double tm9 = ((data[17] << 8) | data[16]) * 0.008;
	double tm10 = ((data[19] << 8) | data[18]) * 5;
	double tm11 = ((data[21] << 8) | data[20]) * 0.008;
	double tm12 = ((data[23] << 8) | data[22]) * 2;

	PRINTF("BCR8W_1 Input Voltage = %.4f V \n", tm1);
	PRINTF("BCR8W_1 Input Current = %.4f mA \n", tm2);
	PRINTF("BCR8W_1 Output Voltage = %.4f V \n", tm3);
	PRINTF("BCR8W_1 Output Current = %.4f mA \n", tm4);
	PRINTF("BCR8W_2 Input Voltage = %.4f V \n", tm5);
	PRINTF("BCR8W_2 Input Current = %.4f mA \n", tm6);
	PRINTF("BCR8W_2 Output Voltage = %.4f V \n", tm7);
	PRINTF("BCR8W_2 Output Current = %.4f mA \n", tm8);
	PRINTF("BCR3W Input Voltage = %.4f V \n", tm9);
	PRINTF("BCR3W Input Current = %.4f mA \n", tm10);
	PRINTF("BCR3W Output Voltage = %.4f V \n", tm11);
	PRINTF("BCR3W Output Current = %.4f mA \n", tm12);

	return;
}

void telemetry_solarPanelSensors(uint8_t * data)
{
	PRINTF ("\r\n");
	PRINTF ("Solar Panel Sensors Telemetry\r\n");
	PRINTF ("---------------------------------\r\n");

	double tm1 = twosComp((data[1] << 8) | data[0]) * 0.5;
	double tm2 = twosComp((data[3] << 8) | data[2]) * 0.5;
	double tm3 = twosComp((data[5] << 8) | data[4]) * 0.5;
	double tm4 = twosComp((data[7] << 8) | data[6]) * 0.5;
	double tm5 = twosComp((data[9] << 8) | data[8]) * 0.5;

	PRINTF("M_SP Temperature X+ = %.4f C \n", tm1);
	PRINTF("M_SP Temperature X- = %.4f C \n", tm2);
	PRINTF("M_SP Temperature Y+ = %.4f C \n", tm3);
	PRINTF("M_SP Temperature Y- = %.4f C \n", tm4);
	PRINTF("M_SP Temperature Z+ = %.4f C \n", tm5);

	return;
}

void telemetry_powerBuses(uint8_t * data)
{
	PRINTF ("\r\n");
	PRINTF ("Power Buses Telemetry\r\n");
	PRINTF ("-------------------------\r\n");

	double tm1 = ((data[1] << 8) | data[0]) * 0.0030945;
	double tm2 = ((data[3] << 8) | data[2]) * 0.0020676;
	double tm3 = ((data[5] << 8) | data[4]) * 0.0030945;
	double tm4 = ((data[7] << 8) | data[6]) * 0.0020676;
	double tm5 = ((data[9] << 8) | data[8]) * 0.0030945;
	double tm6 = ((data[11] << 8) | data[10]) * 0.0020676;
	double tm7 = ((data[13] << 8) | data[12]) * 0.0030945;
	double tm8 = ((data[15] << 8) | data[14]) * 0.0020676;
	double tm9 = ((data[17] << 8) | data[16]) * 0.0030945;
	double tm10 = ((data[19] << 8) | data[18]) * 0.0020676;
	double tm11 = ((data[21] << 8) | data[20]) * 0.0030945;
	double tm12 = ((data[23] << 8) | data[22]) * 0.0020676;

	PRINTF("BCR Output Voltage = %.4f V \n", tm1);
	PRINTF("BCR Output Current = %.4f A \n", tm2);
	PRINTF("PCM Input Voltage = %.4f V \n", tm3);
	PRINTF("PCM Input Current = %.4f A \n", tm4);
	PRINTF("3V3 Power Bus Voltage = %.4f V \n", tm5);
	PRINTF("3V3 Power Bus Current = %.4f A \n", tm6);
	PRINTF("5V Power Bus Voltage = %.4f V \n", tm7);
	PRINTF("5V Power Bus Current = %.4f A \n", tm8);
	PRINTF("Vbat Power Bus Voltage = %.4f V \n", tm9);
	PRINTF("Vbat Power Bus Current = %.4f A \n", tm10);
	PRINTF("12V Power Bus Voltage = %.4f V \n", tm11);
	PRINTF("12V Power Bus Current = %.4f A \n", tm12);

	return;
}

void telemetry_switchablePowerBuses(uint8_t * data)
{
	PRINTF ("\r\n");
	PRINTF ("Switchable Power Buses Telemetry\r\n");
	PRINTF ("------------------------------------\r\n");

	double tm1 = ((data[1] << 8) | data[0]) * 0.0030945;
	double tm2 = ((data[3] << 8) | data[2]) * 0.0008336 - 0.010;
	double tm3 = ((data[5] << 8) | data[4]) * 0.0030945;
	double tm4 = ((data[7] << 8) | data[6]) * 0.0008336 - 0.010;
	double tm5 = ((data[9] << 8) | data[8]) * 0.0030945;
	double tm6 = ((data[11] << 8) | data[10]) * 0.0008336 - 0.010;
	double tm7 = ((data[13] << 8) | data[12]) * 0.0030945;
	double tm8 = ((data[15] << 8) | data[14]) * 0.0008336 - 0.010;
	double tm9 = ((data[17] << 8) | data[16]) * 0.0030945;
	double tm10 = ((data[19] << 8) | data[18]) * 0.0008336 - 0.010;
	double tm11 = ((data[21] << 8) | data[20]) * 0.0030945;
	double tm12 = ((data[23] << 8) | data[22]) * 0.0008336 - 0.010;

	PRINTF("SW1_V = %.4f V \n", tm1);
	PRINTF("SW1_C = %.4f A \n", tm2);
	PRINTF("SW2_V = %.4f V \n", tm3);
	PRINTF("SW2_C = %.4f A \n", tm4);
	PRINTF("SW3_V = %.4f V \n", tm5);
	PRINTF("SW3_C = %.4f A \n", tm6);
	PRINTF("SW4_V = %.4f V \n", tm7);
	PRINTF("SW4_C = %.4f A \n", tm8);
	PRINTF("SW5_V = %.4f V \n", tm9);
	PRINTF("SW5_C = %.4f A \n", tm10);
	PRINTF("SW6_V = %.4f V \n", tm11);
	PRINTF("SW6_C = %.4f A \n", tm12);

	return;
}

void telemetry_batteryModule(uint8_t * data)
{
	PRINTF ("\r\n");
	PRINTF ("Battery Module Telemetry\r\n");
	PRINTF ("----------------------------\r\n");

	double tm1 = ((data[1] << 8) | data[0]) * 4.883;
	double tm2 = ((data[3] << 8) | data[2]) * 4.883;
//	PRINTF ("Before: %4x\r\n", (data[5] << 8) | data[4]);
//	PRINTF ("Complement: %u\r\n", ~(signed)((data[5] << 8) | data[4]));
//	PRINTF ("After: %4x \r\n", twosComp((signed)((data[5] << 8) | data[4])));
	double tm3 = twosComp((data[5] << 8) | data[4]) * 0.26;
	double tm4 = twosComp((data[7] << 8) | data[6]) * 0.1;
	double tm5 = twosComp((data[9] << 8) | data[8]) * 0.125;
	double tm6 = ((data[11] << 8) | data[10]) * 1.6;
	double tm7 = ((data[13] << 8) | data[12]);
	double tm8 = ((data[15] << 8) | data[14]) * 1.042;

	PRINTF("VBAT_1 = %.4f mV \n", tm1);
	PRINTF("VBAT_2 = %.4f mV \n", tm2);
	PRINTF("IBAT = %.4f mA \n", tm3);
	PRINTF("BAT_TEMP = %.4f C \n", tm4);
	PRINTF("PCB_TEMP = %.4f C \n", tm5);
	PRINTF("Available Capacity = %.4f mAh \n", tm6);
	PRINTF("Remaining Capacity = %.4f %% \n", tm7);
	PRINTF("Accumulated Battery Current = %.4f mAh \n", tm8);

	return;
}

void telemetry_systemData(uint8_t * data)
{
	PRINTF ("\r\n");
	PRINTF ("System Data Telemetry\r\n");
	PRINTF ("-------------------------\r\n");

	int tm1 = ((data[1] << 8) | data[0]);
	int tm2 = ((data[3] << 8) | data[2]);
	int tm3 = ((data[5] << 8) | data[4]);
	int tm4 = ((data[7] << 8) | data[6]);
	int tm5 = ((data[9] << 8) | data[8]);
	int tm6 = ((data[11] << 8) | data[10]);

	PRINTF("Watchdog period = %d \n", tm1);
	PRINTF("PDMs Initial State = %d \n", tm2);
	PRINTF("PDMs State = %d \n", tm3);
	PRINTF("Housekeeping period = %d \n", tm4);
	if (tm5 == 0) {
		PRINTF("Battery Heater Status = OFF \n\r");
	}
	else {
		PRINTF("Battery Heater Status = ON \n\r");

	}
	PRINTF("Safety hazard environment = %d \n\r", tm6);

	return;
}



// TELEMETRY ENDS HERE
//____________________________________________________________________________________________________________________________

// for bus Reset
// ALSO ASSUMPTION: when asking for byte i am assuming its talking about only one byte of parameter
// otherwise when it uses the term parameter, I am assuming there are 2 bytes of parameter
// bit 1 and 0 = 1 then 3v3
// bit 3 and 2 = 1 then 5v
// bit 5 and 4 = 1 then 12v
// bit 7 and 6 = 1 then Vbat
void i2c_eps_fixedPowerBusReset(uint8_t busReset)
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_FIXED_POWER_BUS_RESET;
	buffer[1] = 0x00 | busReset;

	i2c_read_write_helper(buffer, 2, 0, 0, NO_RETURN);
	//(void)adc_count; //unused
	return;
}

void i2c_eps_manualReset()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = I2C_EPS_CMD_MANUAL_RESET;
	buffer[1] = 0xFF;

	i2c_read_write_helper(buffer, 2, 0, 0, NO_RETURN);
	//(void)adc_count; //unused
	return;
}
