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

 // telemetry pg 14
 // check if thinking about correctly
 // for param[1] (where in I2C is parameter?)
 // also how do you read the byte and bit
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
#define NO_RETURN 9999


#define EPS_SLAVE_ADDR 0 //change
#define I2C_DATA_LENGTH 4 //?

uint8_t buffer[I2C_DATA_LENGTH];
static uint32_t adc_count;

bool eps_healthcheck() {
	PRINTF("checking the health of eps!\r\n");
	//	TickType_t xLastWakeTime = xTaskGetTickCount();
	//	vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS( 10 ));
	//	PRINTF("Finish delay\r\n");
	return true;
}


//uint8_t kLPI2C_Write = 1; // not sure where this is defined, but I think it differentiates between read/write commands
//uint8_t kLPI2C_Read = 0; // not sure where this is defined, but I think it differentiates between read/write commands

/* the I2C_read_write_lp function is designed to write to registers within the i2c slave device, so writing i2c data looks like this:
 * [device address -> register address -> data]
 * The EPS/battery do not use registers like this, and instead just follow a format like:
 * [device address -> command -> parameters]
 * So, this register address is just temporary. A more complete i2c library is needed.
 */

uint8_t I2C_EPS_REG_ADDR = 1;
size_t datasize = 1U;

//int main(void)
//{
//    uint32_t i = 0;
//
//    /* Init board hardware. */
//    BOARD_ConfigMPU();
//    BOARD_InitPins();
//    BOARD_BootClockRUN();
//    BOARD_InitDebugConsole();
//
//    /*Clock setting for LPI2C*/
//    CLOCK_SetMux(kCLOCK_Lpi2cMux, LPI2C_CLOCK_SOURCE_SELECT);
//    CLOCK_SetDiv(kCLOCK_Lpi2cDiv, LPI2C_CLOCK_SOURCE_DIVIDER);
//
//
//    //EPS telemetry
//    char eps_powerModuleStatus[1000];
//    char eps_batteryModuleStatus[1000];
//    char eps_FDIRflag[1000];
//    char eps_idRegister[1000];
//
//    eps_powerModuleStatus = i2c_eps_powerModuleStatus();
//    eps_batteryModuleStatus = i2c_eps_batteryModuleStatus();
//    eps_FDIRflag = i2c_eps_FDIRflag();
//    eps_idRegister = i2c_eps_idRegister();
//    //enter telemetry here;
//
//    PRINTF("%s \n", eps_powerModuleStatus);
//    PRINTF("%s \n", eps_batteryModuleStatus);
//    PRINTF("%s \n", eps_FDIRflag);
//    PRINTF("%s \n", eps_idRegister);
//
//    while (1)
//    {
//    }
//}
//
static void i2c_read_write_helper(uint8_t* i2c_send_buffer, size_t data_size, uint32_t * i2c_recv_buffer, time_t d) {

	// send gmb0, gmb1, gmb2, gmb3 in order
	size_t n;
	// TODO: send the delay as well
	LPI2C1_send_receive(EPS_SLAVE_ADDR, i2c_send_buffer, data_size, &adc_count, &n); //n necessary?

	if (d != NO_RETURN) {
		//delay(d);
	}

	adc_count = 0;
	//LPI2C1_receive(...)
//
//
//	//OBC: getStatus() in idle_task -> helper -> FreeRTOS_send gmb
//	//EPS: gets a message via I2C -> I need to send back the status -> I2C send(status)
//	//OBC: received status -> read g_slave_buff -> use that to do the next operation
//
//
//	delay(d);
//
//	//i2c read
//	I2C_read_write_lp(&master_rtos_handle, &status, I2C_EPS_ADDR, kLPI2C_Read, I2C_EPS_REG_ADDR, g_slave_buff, datasize);
//
//	delay(d);
//
//	PRINTF("Master received data from slave: ");
//	print_i2c_data(g_slave_buff);
//
//	uint32_t adc_count = 0;
//	/* get the ADC count returned using bitwise operations
//	 * adc_count will be a 32-bit int of the form:
//	 * {0x00     0x00     g_slave_buff[1]     g_slave_buff[0]}
//	 * I don't know if this calculation is correct
//	 */

//	adc_count = (g_slave_buff[1] << 8) | g_slave_buff[0]);

}

// added 11/24/20
//__________________________________________________________________________________________________________________

double i2c_eps_getBatteryLevel()
{
	PRINTF("get the battery value!\r\n");
	return 0.0;
}

uint32_t i2c_eps_powerModuleStatus()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_POWER_MODULE_STATUS;

	// send and read
	// returns 2 bytes <- remember to adjust so it can return multiple different selection of bytes
	// delay is unknown?
	// thought: regardless if all bytes are moved, it should still return the same adc_count
	//          which can still be checked, so it would be best to adjust so all bytes are moved
	i2c_read_write_helper(buffer, 4, &adc_count, 5000);


	if (adc_count & (1 << 0))
	{
		PRINTF("3V3 output error\n");
	}
	if (adc_count & (1 << 1))
	{
		PRINTF("5V output error\n");
	}
	if (adc_count & (1 << 2))
	{
		PRINTF("12V output error\n");
	}
	if (adc_count & (1 << 8))
	{
		PRINTF("PDM1 error\n");
	}
	if (adc_count & (1 << 9))
	{
		PRINTF("PDM2 error\n");
	}
	if (adc_count & (1 << 10))
	{
		PRINTF("PDM3 error\n");
	}
	if (adc_count & (1 << 11))
	{
		PRINTF("PDM4 error\n");
	}
	if (adc_count & (1 << 12))
	{
		PRINTF("PDM5 error\n");
	}
	if (adc_count & (1 << 13))
	{
		PRINTF("PDM6 error\n");
	}
	return adc_count;
}

uint32_t i2c_eps_batteryModuleStatus()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_BATTERY_MODULE_STATUS;

	// send and read
	//  returns 2 bytes <- remember to adjust so it can return multiple different selection of bytes
	// delay is unknown?
	// thought: regardless if all bytes are moved, it should still return the same adc_count
	//          which can still be checked, so it would be best to adjust so all bytes are moved
	i2c_read_write_helper(buffer, 4, &adc_count, 5000);

	if (adc_count & (1 << 0))
	{
		PRINTF("CC, Charge Control Flag. Set if battery charge is disabled.\n");
	}
	if (adc_count & (1 << 1))
	{
		PRINTF("DC, Discharge Control Flag. Set if battery discharge is disabled.\n");
	}
	if (adc_count & (1 << 2))
	{
		PRINTF(" CHGTF, Charge-Termination Flag. Set if battery is fully charged.\n");
	}
	if (adc_count & (1 << 4))
	{
		PRINTF("SEF, Standby-Empty Flag. Set if capacity is below 10%%, unset if above 15 %%.\n");
	}
	if (adc_count & (1 << 8))
	{
		PRINTF("Set if heater is active.\n");
	}
	if (adc_count & (1 << 12))
	{
		PRINTF("Set if battery balancing is happening from top cell to bottom cell.\n");
	}
	if (adc_count & (1 << 13))
	{
		PRINTF("Set if battery balancing is happening from bottom cell to top cell.\n");
	}
	return adc_count;
}

void i2c_eps_FDIRflag()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_FDIR;

	// send and read
	// returns 1 bytes <- remember to adjust so it can return multiple different selection of bytes
	// delay is unknown?
	// thought: regardless if all bytes are moved, it should still return the same adc_count
	//          which can still be checked, so it would be best to adjust so all bytes are moved
	i2c_read_write_helper(buffer, 4, &adc_count, 5000);

	if (adc_count & (1 << 0))
	{
		PRINTF("0 Set if last was command unknown\n");
	}
	if (adc_count & (1 << 1))
	{
		PRINTF("Set if last command parameter was invalid.\n");
	}
	if (adc_count & (1 << 2))
	{
		PRINTF("Set if watchdog was triggered.\n");
	}
	if (adc_count & (1 << 3))
	{
		PRINTF("Set if BOR was triggered.\n");
	}
	if (adc_count & (1 << 5))
	{
		PRINTF("Set if battery manager is unavailable.\n");
	}
	if (adc_count & (1 << 6))
	{
		PRINTF("Set if VBAT1_ADC is out of range.\n");
	}
	if (adc_count & (1 << 7))
	{
		PRINTF("Set if VBAT2_ADC is out of range.\n");
	}
	if (adc_count & (1 << 8))
	{
		PRINTF("Set if IBAT_BM is out of range.\n");
	}
	if (adc_count & (1 << 9))
	{
		PRINTF("Set if TEMP_BM is out of range.\n");
	}
	if (adc_count & (1 << 10))
	{
		PRINTF("Set if TEMP_MB is out of range.\n");
	}
	if (adc_count & (1 << 11))
	{
		PRINTF("Set if TEMP_DB1 is out of range.\n");
	}
	return;
}

void i2c_eps_idRegister() ///make bool?
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_ID;

	// send and read
	// returns 1 bytes <- remember to adjust so it can return multiple different selection of bytes
	// delay is unknown?
	// thought: regardless if all bytes are moved, it should still return the same adc_count
	//          which can still be checked, so it would be best to adjust so all bytes are moved
	i2c_read_write_helper(buffer, 4, &adc_count, 5000);

	bool verified_com;
	verified_com = adc_count && VERIFIED_COM_MASK; // TODO: gorkem - are we checking only the first bit here? then the mask is unnecessary
	if (verified_com) {
		PRINTF("Communication is verified with module \n");
	}
	else {
		PRINTF("Communication is NOT verified with module \n");
	}
	return;
}
//
//// for watchdog, userinput period
//// only accepts 1, 2, 4 for each period in minutes
void i2c_eps_watchdogPeriod(uint8_t period)
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_ID;
	buffer[2] = 0x0000 | period;
	//buffer[3] = period;
	i2c_read_write_helper(buffer, 4, 0, NO_RETURN);
	(void)adc_count; //unused
	return;
}


// Set PDM initial state has input for initial state
// pdm_state = set bit: 00******
// bit 0 effects PDM1 state, bit 1 effects PDM2 state, and so on...
void i2c_eps_setPdmsInitialState(uint8_t pdm_state)
{
	uint32_t intial_pdms = 0x00 | pdm_state; // bit 6 and 7 are reserved
											// should become 0x00(6 bit pdm)
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_SET_PDMS_INTIAL_STATE;
	buffer[2] = 0x00;
	buffer[3] = intial_pdms;
	//buffer[3] = period;
	i2c_read_write_helper(buffer, 4, 0, NO_RETURN);
	(void)adc_count; //unused
	return;
}

void i2c_eps_resetPdm()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_RESET_PDMS;
	buffer[2] = 0x00;
	buffer[3] = 0xFF; //all ON?

	i2c_read_write_helper(buffer, 4, 0, NO_RETURN);
	(void)adc_count; //unused
	return;
}

// added 12/6/20
// will skip on doing telemtry for now until answers on how it outputs is provided
//
// for this newPdmState will turn on specific pdm 1-6 which is assigned from bit 0-5 in that order
void i2c_eps_switchOnOffPdms(uint8_t newPdmState)
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_SWITCH_ON_OFF_PDMS;
	buffer[2] = 0x00;
	buffer[3] = newPdmState;

	i2c_read_write_helper(buffer, 4, 0, NO_RETURN);
	(void)adc_count; //unused

	// TODO: do we want an acknowledgement?
	return;
}

// period can be 1 min 2 min or 4 min
void i2c_eps_setHousekeepingPeriod(uint8_t period)
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_SET_HOUSEKEEPING_PERIOD;
	buffer[2] = 0x00;
	buffer[3] = period;

	i2c_read_write_helper(buffer, 4, 0, NO_RETURN);
	(void)adc_count; //unused

	return;
}

// QUESTION: how is the i2c write structured
// is it 7 bit address -> command -> param [1] -> param [0] (each a byte)
// IF SO -> then what for PDM initial state why is it Byte 0 and not Param[0] (typo? as nothing is returned)

void i2c_eps_setSafetyHazardEnvironment()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_SET_SAFETY_HAZARD_ENVIRONMENT;
	buffer[2] = 0x00;
	buffer[3] = 0xFF;

	i2c_read_write_helper(buffer, 4, 0, NO_RETURN);
	(void)adc_count; //unused

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
	// turn into 2s compliment
	for (int i = 15; i >= 0; i--)
	{
		if (x[i] == '1')
		{
			x[i] = '0';
		}
		else
		{
			x[i] = '1';
		}
	}
	x = x + 1;

	return x;
}




// VERSION 2 OF TELEMETRY - SAVES RUNTIME AND SPACE____________________________________
// I feel like for convenience we can have user type the family they want and it will be
// the input for families which can set the buffer
void i2c_eps_getTelemetryGroup(uint16_t families)
{
	/* Set up i2c master to send data to slave */
	buffer[0] = EPS_SLAVE_ADDR; // i2c slave address = EPS motherboard
	buffer[1] = I2C_EPS_CMD_GET_TELEMETRY_GROUP; // i2c command = get EPS telemetry

	// possible families
	// 0x00 BCRs
	// 0x01 Solar Panel Sensors
	// 0x02 Power Buses
	// 0x03 Switchable Power Buses
	// 0x04 Battery Module
	// 0x05 System Data

	// add user input here
	buffer[2] = families;


	uint32_t returnArray[6]; //holds array of 24 bytes

	i2c_read_write_helper(buffer, 4, returnArray, 5000);

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
		telemetry_bcrs(returnArray);
	}
	else if (families == 0x01)
	{
		telemetry_solarPanelSensors(returnArray);
	}
	else if (families == 0x02)
	{
		telemetry_powerBuses(returnArray);
	}
	else if (families == 0x03)
	{
		telemetry_switchablePowerBuses(returnArray);
	}
	else if (families == 0x04)
	{
		telemetry_batteryModule(returnArray);
	}
	else if (families == 0x05)
	{
		telemetry_systemData(returnArray);
	}

	return;
}

char telemetry_bcrs(uint32_t * data)
{
	int tm1 = (data[0] & BYTE16CAST) * 0.008;
	int tm2 = ((data[0] >> 16) & BYTE16CAST) * 2;
	int tm3 = (data[1] & BYTE16CAST) * 0.008;
	int tm4 = ((data[1] >> 16) & BYTE16CAST) * 2;
	int tm5 = (data[2] & BYTE16CAST) * 0.008;
	int tm6 = ((data[2] >> 16) & BYTE16CAST) * 2;
	int tm7 = (data[3] & BYTE16CAST) * 0.008;
	int tm8 = ((data[3] >> 16) & BYTE16CAST) * 2;
	int tm9 = (data[4] & BYTE16CAST) * 0.008;
	int tm10 = ((data[4] >> 16) & BYTE16CAST) * 5;
	int tm11 = (data[5] & BYTE16CAST) * 0.008;
	int tm12 = ((data[5] >> 16) & BYTE16CAST) * 2;

	PRINTF("BCR8W_1 Input Voltage = %d V \n", tm1);
	PRINTF("BCR8W_1 Input Current = %d mA \n", tm2);
	PRINTF("BCR8W_1 Output Voltage = %d V \n", tm3);
	PRINTF("BCR8W_1 Output Current = %d mA \n", tm4);
	PRINTF("BCR8W_2 Input Voltage = %d V \n", tm5);
	PRINTF("BCR8W_2 Input Current = %d mA \n", tm6);
	PRINTF("BCR8W_2 Output Voltage = %d V \n", tm7);
	PRINTF("BCR8W_2 Output Current = %d mA \n", tm8);
	PRINTF("BCR3W Input Voltage = %d V \n", tm9);
	PRINTF("BCR3W Input Current = %d mA \n", tm10);
	PRINTF("BCR3W Output Voltage = %d V \n", tm11);
	PRINTF("BCR3W Output Current = %d mA \n", tm12);

}

char telemetry_solarPanelSensors(uint32_t * data)
{
	int tm1 = twosComp(data[0] & BYTE16CAST) * 0.5;
	int tm2 = twosComp((data[0] >> 16) & BYTE16CAST) * 0.5;
	int tm3 = twosComp(data[1] & BYTE16CAST) * 0.5;
	int tm4 = twosComp((data[1] >> 16) & BYTE16CAST) * 0.5;
	int tm5 = twosComp(data[2] & BYTE16CAST) * 0.5;

	PRINTF("M_SP Temperature X+ = %d C \n", tm1);
	PRINTF("M_SP Temperature X- = %d C \n", tm2);
	PRINTF("M_SP Temperature Y+ = %d C \n", tm3);
	PRINTF("M_SP Temperature Y- = %d C \n", tm4);
	PRINTF("M_SP Temperature Z+ = %d C \n", tm5);

}

char telemetry_powerBuses(uint32_t * data)
{
	int tm1 = (data[0] & BYTE16CAST) * 0.0030945;
	int tm2 = ((data[0] >> 16) & BYTE16CAST) * 0.0020676;
	int tm3 = (data[1] & BYTE16CAST) * 0.0030945;
	int tm4 = ((data[1] >> 16) & BYTE16CAST) * 0.0020676;
	int tm5 = (data[2] & BYTE16CAST) * 0.0030945;
	int tm6 = ((data[2] >> 16) & BYTE16CAST) * 0.0020676;
	int tm7 = (data[3] & BYTE16CAST) * 0.0030945;
	int tm8 = ((data[3] >> 16) & BYTE16CAST) * 0.0020676;
	int tm9 = (data[4] & BYTE16CAST) * 0.0030945;
	int tm10 = ((data[4] >> 16) & BYTE16CAST) * 0.0020676;
	int tm11 = (data[5] & BYTE16CAST) * 0.0030945;
	int tm12 = ((data[5] >> 16) & BYTE16CAST) * 0.0020676;

	PRINTF("BCR Output Voltage = %d V \n", tm1);
	PRINTF("BCR Output Current = %d A \n", tm2);
	PRINTF("PCM Input Voltage = %d V \n", tm3);
	PRINTF("PCM Input Current = %d A \n", tm4);
	PRINTF("3V3 Power Bus Voltage = %d V \n", tm5);
	PRINTF("3V3 Power Bus Current = %d A \n", tm6);
	PRINTF("5V Power Bus Voltage = %d V \n", tm7);
	PRINTF("5V Power Bus Current = %d A \n", tm8);
	PRINTF("Vbat Power Bus Voltage = %d V \n", tm9);
	PRINTF("Vbat Power Bus Current = %d A \n", tm10);
	PRINTF("12V Power Bus Voltage = %d V \n", tm11);
	PRINTF("12V Power Bus Current = %d A \n", tm12);

}

char telemetry_switchablePowerBuses(uint32_t * data)
{
	int tm1 = (data[0] & BYTE16CAST) * 0.0030945;
	int tm2 = ((data[0] >> 16) & BYTE16CAST) * 0.0008336 − 0.010;
	int tm3 = (data[1] & BYTE16CAST) * 0.0030945;
	int tm4 = ((data[1] >> 16) & BYTE16CAST) * 0.0008336 − 0.010;
	int tm5 = (data[2] & BYTE16CAST) * 0.0030945;
	int tm6 = ((data[2] >> 16) & BYTE16CAST) * 0.0008336 − 0.010;
	int tm7 = (data[3] & BYTE16CAST) * 0.0030945;
	int tm8 = ((data[3] >> 16) & BYTE16CAST) * 0.0008336 − 0.010;
	int tm9 = (data[4] & BYTE16CAST) * 0.0030945;
	int tm10 = ((data[4] >> 16) & BYTE16CAST) * 0.0008336 − 0.010;
	int tm11 = (data[5] & BYTE16CAST) * 0.0030945;
	int tm12 = ((data[5] >> 16) & BYTE16CAST) * 0.0008336 − 0.010;

	PRINTF("SW1_V = %d V \n", tm1);
	PRINTF("SW1_C = %d A \n", tm2);
	PRINTF("SW2_V = %d V \n", tm3);
	PRINTF("SW2_C = %d A \n", tm4);
	PRINTF("SW3_V = %d V \n", tm5);
	PRINTF("SW3_C = %d A \n", tm6);
	PRINTF("SW4_V = %d V \n", tm7);
	PRINTF("SW4_C = %d A \n", tm8);
	PRINTF("SW5_V = %d V \n", tm9);
	PRINTF("SW5_C = %d A \n", tm10);
	PRINTF("SW6_V = %d V \n", tm11);
	PRINTF("SW6_C = %d A \n", tm12);

}

char telemetry_batteryModule(uint32_t * data)
{
	int tm1 = (data[0] & BYTE16CAST) * 4.883;
	int tm2 = ((data[0] >> 16) & BYTE16CAST) * 4.883;
	int tm3 = twosComp(data[1] & BYTE16CAST) * 0.26;
	int tm4 = twosComp((data[1] >> 16) & BYTE16CAST) * 0.1;
	int tm5 = twosComp(data[2] & BYTE16CAST) * 0.125;
	int tm6 = ((data[2] >> 16) & BYTE16CAST) * 1.6;
	int tm7 = (data[3] & BYTE16CAST);
	int tm8 = ((data[3] >> 16) & BYTE16CAST) * 1.042;

	PRINTF("VBAT_1 = %d mV \n", tm1);
	PRINTF("VBAT_2 = %d mV \n", tm2);
	PRINTF("IBAT = %d mA \n", tm3);
	PRINTF("BAT_TEMP = %d C \n", tm4);
	PRINTF("PCB_TEMP = %d C \n", tm5);
	PRINTF("Available Capacity = %d mAh \n", tm6);
	PRINTF("Remaining Capacity = %d %% \n", tm7);
	PRINTF("Accumulated Battery Current = %d mAh \n", tm8);

}

char telemetry_systemData(uint32_t * data)
{
	int tm1 = (data[0] & BYTE16CAST);
	int tm2 = ((data[0] >> 16) & BYTE16CAST);
	int tm3 = (data[1] & BYTE16CAST);
	int tm4 = ((data[1] >> 16) & BYTE16CAST);
	int tm5 = (data[2] & BYTE16CAST);
	int tm6 = ((data[2] >> 16) & BYTE16CAST);

	PRINTF("Watchdog period = %d \n", tm1);
	PRINTF("PDMs Initial State = %d \n", tm2);
	PRINTF("PDMs State = %d \n", tm3);
	PRINTF("Housekeeping period = %d \n", tm4);
	if (tm5 == 0) {
		PRINTF("Battery Heater Status = OFF \n", tm5);
	}
	else {
		PRINTF("Battery Heater Status = ON \n", tm5);

	}
	PRINTF("Safety hazard environment = %d \n", tm6);
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
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_FIXED_POWER_BUS_RESET;
	buffer[2] = 0x00 | busReset;

	i2c_read_write_helper(buffer, 4, 0, NO_RETURN);
	(void)adc_count; //unused

	return;
}

void i2c_eps_manualReset()
{
	memset(buffer, 0, sizeof(*buffer)*I2C_DATA_LENGTH);
	buffer[0] = EPS_SLAVE_ADDR; // do we need to send this as part of data on i2c bus?
	buffer[1] = I2C_EPS_CMD_MANUAL_RESET;
	buffer[2] = 0xFF;

	i2c_read_write_helper(buffer, 4, 0, NO_RETURN);
	(void)adc_count; //unused

	return;
}
