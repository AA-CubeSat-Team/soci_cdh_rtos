/* This is a source file for testing the I2C commands required for the flight computer to
 * communicate with the EPS board and the battery
 *
 * As of 6/23/2020, everything in this file is being written without any access to hardware, and is completely untested.
 * It should not be assumed to be functional.
 *
 * Jerrold Erickson, 6/23/2020
 */

#include <eps_wrap.h>
#include "fsl_lpi2c.h"
#include "fsl_lpi2c_freertos.h"

uint8_t g_slave_buff[I2C_DATA_LENGTH];
uint8_t g_master_buff[I2C_DATA_LENGTH];

//uint32_t master_rtos_handle = 0; // fake variable for RTOS stuff
//status_t status = 0; // fake variable for RTOS stuff
//uint8_t kLPI2C_Write = 1; // not sure where this is defined, but I think it differentiates between read/write commands
//uint8_t kLPI2C_Read = 0; // not sure where this is defined, but I think it differentiates between read/write commands
//
///* the I2C_read_write_lp function is designed to write to registers within the i2c slave device, so writing i2c data looks like this:
// * [device address -> register address -> data]
// * The EPS/battery do not use registers like this, and instead just follow a format like:
// * [device address -> command -> parameters]
// * So, this register address is just temporary. A more complete i2c library is needed.
// */
//uint8_t I2C_EPS_REG_ADDR = 1;
//size_t datasize = 1U;
//
//
//
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
//    printf("%s \n", eps_powerModuleStatus);
//    printf("%s \n", eps_batteryModuleStatus);
//    printf("%s \n", eps_FDIRflag);
//    printf("%s \n", eps_idRegister);
//
//    while (1)
//    {
//    }
//}
//
//uint32_t i2c_read_write_helper(gmb_0, gmb_1, gmb_2, gmb_3, d) {
//	printf("Master will send data :");
//	print_i2c_data(g_master_buff);
//
//	// i2c write
//
//	 LPI2C_RTOS_Transfer(lpi2c_rtos_handle_t *handle, lpi2c_master_transfer_t *transfer);
//
//
//I2C_read_write_lp(&master_rtos_handle, &status, I2C_EPS_ADDR, kLPI2C_Write, I2C_EPS_REG_ADDR, gmb_0, datasize);
//	I2C_read_write_lp(&master_rtos_handle, &status, I2C_EPS_ADDR, kLPI2C_Write, I2C_EPS_REG_ADDR, gmb_1, datasize);
//	I2C_read_write_lp(&master_rtos_handle, &status, I2C_EPS_ADDR, kLPI2C_Write, I2C_EPS_REG_ADDR, gmb_2, datasize);
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
//	printf("Master received data from slave: ");
//	print_i2c_data(g_slave_buff);
//
//	uint32_t adc_count = 0;
//	/* get the ADC count returned using bitwise operations
//	 * adc_count will be a 32-bit int of the form:
//	 * {0x00     0x00     g_slave_buff[1]     g_slave_buff[0]}
//	 * I don't know if this calculation is correct
//	 */
//	adc_count = (g_slave_buff[1] << 8) | g_slave_buff[0]);
//
//	return adc_count;
//}
//
//// added 11/24/20
////__________________________________________________________________________________________________________________
//
//char i2c_eps_powerModuleStatus()
//{
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_POWER_MODULE_STATUS; // i2c command = get EPS telemetry
//
//    // send and read
//    // returns 2 bytes <- remember to adjust so it can return multiple different selection of bytes
//    // delay is unknown?
//    // thought: regardless if all bytes are moved, it should still return the same adc_count
//    //          which can still be checked, so it would be best to adjust so all bytes are moved
//    i2c_read_write_helper(g_master_buff[0], g_master_buff[1], g_master_buff[2], g_master_buff[3], 5000);
//
//    char string[1000];
//    if (adc_count & (1<<0))
//    {
//        strcpy(string, "3V3 output error\n");
//    }
//    if (adc_count & (1<<1))
//    {
//        strcpy(string, "5V output error\n");
//    }
//    if (adc_count & (1<<2))
//    {
//        strcpy(string, "12V output error\n");
//    }
//    if (adc_count & (1<<8))
//    {
//        strcpy(string, "PDM1 error\n");
//    }
//    if (adc_count & (1<<9))
//    {
//        strcpy(string, "PDM2 error\n");
//    }
//    if (adc_count & (1<<10))
//    {
//        strcpy(string, "PDM3 error\n");
//    }
//    if (adc_count & (1<<11))
//    {
//        strcpy(string, "PDM4 error\n");
//    }
//    if (adc_count & (1<<12))
//    {
//        strcpy(string, "PDM5 error\n");
//    }
//    if (adc_count & (1<<13))
//    {
//        strcpy(string, "PDM6 error\n");
//    }
//
//    return string;
//}
//
//char i2c_eps_batteryModuleStatus()
//{
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_BATTERY_MODULE_STATUS; // i2c command = get EPS telemetry
//
//    // send and read
//    // returns 2 bytes <- remember to adjust so it can return multiple different selection of bytes
//    i2c_read_write_helper(g_master_buff[0], g_master_buff[1], g_master_buff[2], g_master_buff[3], 5000);
//
//    char string[1000];
//    if (adc_count & (1<<0))
//    {
//        strcpy(string, "CC, Charge Control Flag. Set if battery charge is disabled.\n");
//    }
//    if (adc_count & (1<<1))
//    {
//        strcpy(string, "DC, Discharge Control Flag. Set if battery discharge is disabled.\n");
//    }
//    if (adc_count & (1<<2))
//    {
//        strcpy(string, " CHGTF, Charge-Termination Flag. Set if battery is fully charged.\n");
//    }
//    if (adc_count & (1<<4))
//    {
//        strcpy(string, "SEF, Standby-Empty Flag. Set if capacity is below 10%%, unset if above 15 %%.\n");
//    }
//    if (adc_count & (1<<8))
//    {
//        strcpy(string, "Set if heater is active.\n");
//    }
//    if (adc_count & (1<<12))
//    {
//        strcpy(string, "Set if battery balancing is happening from top cell to bottom cell.\n");
//    }
//    if (adc_count & (1<<13))
//    {
//        strcpy(string, "Set if battery balancing is happening from bottom cell to top cell.\n");
//    }
//
//    return string;
//}
//
//char i2c_eps_FDIRflag()
//{
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_FDIR; // i2c command = get EPS telemetry
//
//    // send and read
//    // returns 1 bytes <- remember to adjust so it can return multiple different selection of bytes
//    i2c_read_write_helper(g_master_buff[0], g_master_buff[1], g_master_buff[2], g_master_buff[3], 5000);
//
//    char string[1000];
//    if (adc_count & (1<<0))
//    {
//        strcpy(string, "0 Set if last was command unknown\n");
//    }
//    if (adc_count & (1<<1))
//    {
//        strcpy(string, "Set if last command parameter was invalid.\n");
//    }
//    if (adc_count & (1<<2))
//    {
//        strcpy(string, "Set if watchdog was triggered.\n");
//    }
//    if (adc_count & (1<<3))
//    {
//        strcpy(string, "Set if BOR was triggered.\n");
//    }
//    if (adc_count & (1<<5))
//    {
//        strcpy(string, "Set if battery manager is unavailable.\n");
//    }
//    if (adc_count & (1<<6))
//    {
//        strcpy(string, "Set if VBAT1_ADC is out of range.\n");
//    }
//    if (adc_count & (1<<7))
//    {
//        strcpy(string, "Set if VBAT2_ADC is out of range.\n");
//    }
//    if (adc_count & (1<<8))
//    {
//        strcpy(string, "Set if IBAT_BM is out of range.\n");
//    }
//    if (adc_count & (1<<9))
//    {
//        strcpy(string, "Set if TEMP_BM is out of range.\n");
//    }
//    if (adc_count & (1<<10))
//    {
//        strcpy(string, "Set if TEMP_MB is out of range.\n");
//    }
//    if (adc_count & (1<<11))
//    {
//        strcpy(string, "Set if TEMP_DB1 is out of range.\n");
//    }
//
//    return string;
//}
//
//bool i2c_eps_idRegister()
//{
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_ID; // i2c command = get EPS telemetry
//
//    // send and read
//    // returns 1 bytes <- remember to adjust so it can return multiple different selection of bytes
//    i2c_read_write_helper(g_master_buff[0], g_master_buff[1], g_master_buff[2], g_master_buff[3], 5000);
//
//    bool verified_com;
//   verified_com = adc_count && 0x67D6;
//   char string[100];
//   if (verified_com) {
//        strcpy(string, "Communication is verified with module \n");
//   } else {
//        strcpy(string, "Communication is NOT verified with module \n");
//   }
//   return string;
//}
//
//// for watchdog, userinput period
//// only accepts 1, 2, 4 for each period in minutes
//void i2c_eps_watchdogPeriod(period)
//{
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_SET_WATCHDOG_PERIOD; // i2c command = get EPS telemetry
//    g_master_buff[2] = 0x0000 | period;
//    //g_master_buff[3] = period;
//
//    // this one only needs to read
//    printf("Master will send data :");
//    print_i2c_data(g_master_buff);
//
//    // i2c write
//    I2C_read_write_lp(&master_rtos_handle, &status, I2C_EPS_ADDR, kLPI2C_Write, I2C_EPS_REG_ADDR, g_master_buff[0], datasize);
//    I2C_read_write_lp(&master_rtos_handle, &status, I2C_EPS_ADDR, kLPI2C_Write, I2C_EPS_REG_ADDR, g_master_buff[1], datasize);
//    I2C_read_write_lp(&master_rtos_handle, &status, I2C_EPS_ADDR, kLPI2C_Write, I2C_EPS_REG_ADDR, g_master_buff[2], datasize);
//
//    delay(5000);
//
//    // dont need to read bc no data returned
//}
//
//// Set PDM initial state has input for initial state
//// pdm_state = set bit: 00******
//// bit 0 effects PDM1 state, bit 1 effects PDM2 state, and so on...
//void i2c_eps_setPdmsInitialState(pdm_state)
//{
//    uint32_t intial_pdms = 0x00 | pdm_state; // bit 6 and 7 are reserved
//                                             // should become 0x00(6 bit pdm)
//
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_SET_PDMS_INTIAL_STATE; // i2c command = get EPS telemetry
//    g_master_buff[2] = 0x00;
//    g_master_buff[3] = intial_pdms;
//
//    // this one only needs to read
//    printf("Master will send data :");
//    print_i2c_data(g_master_buff);
//
//    // i2c write
//	i2c_read_write_helper(g_master_buff[0], g_master_buff[1], g_master_buff[2], g_master_buff[3], 5000);
//
//
//    delay(5000);
//
//    // dont need to read bc no data returned
//}
//
//void i2c_eps_resetPdm()
//{
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_RESET_PDMS; // i2c command = get EPS telemetry
//    g_master_buff[2] = 0x00;
//    g_master_buff[3] = 0xFF;
//
//    // this one only needs to read
//    printf("Master will send data :");
//    print_i2c_data(g_master_buff);
//
//    // i2c write
//	i2c_read_write_helper(g_master_buff[0], g_master_buff[1], g_master_buff[2], g_master_buff[3], 5000);
//
//
//    delay(5000);
//
//    // dont need to read bc no data returned
//}
//
// added 12/6/20
// will skip on doing telemtry for now until answers on how it outputs is provided
//
// for this newPdmState will turn on specific pdm 1-6 which is assigned from bit 0-5 in that order
//void i2c_eps_switchOnOffPdms(newPdmState)
//{
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_SWITCH_ON_OFF_PDMS; // i2c command = get EPS telemetry
//    g_master_buff[2] = 0x00
//    g_master_buff[3] = newPdmState;
//
//    // this one only needs to read
//    printf("Master will send data :");
//    print_i2c_data(g_master_buff);
//
//    // i2c write
//	i2c_read_write_helper(g_master_buff[0], g_master_buff[1], g_master_buff[2], g_master_buff[3], 5000);
//
//
//    delay(5000);
//
//    // dont need to read bc no data returned
//}
//
//// period can be 1 min 2 min or 4 min
//void i2c_eps_setHousekeepingPeriod(period)
//{
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_SET_HOUSEKEEPING_PERIOD; // i2c command = get EPS telemetry
//    g_master_buff[2] = 0x00
//    g_master_buff[3] = period;
//
//    // this one only needs to read
//    printf("Master will send data :");
//    print_i2c_data(g_master_buff);
//
//    // i2c write
//	i2c_read_write_helper(g_master_buff[0], g_master_buff[1], g_master_buff[2], g_master_buff[3], 5000);
//
//
//    delay(5000);
//
//    // dont need to read bc no data returned
//}
//
//// QUESTION: how is the i2c write structured
//// is it 7 bit address -> command -> param [1] -> param [0] (each a byte)
//// IF SO -> then what for PDM initial state why is it Byte 0 and not Param[0] (typo? as nothing is returned)
//
//void i2c_eps_setSafetyHazardEnvironment()
//{
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_SET_SAFETY_HAZARD_ENVIRONMENT; // i2c command = get EPS telemetry
//    g_master_buff[2] = 0x00;
//    g_master_buff[3] = 0xFF;
//
//    // this one only needs to read
//    printf("Master will send data :");
//    print_i2c_data(g_master_buff);
//
//    // i2c write
//	i2c_read_write_helper(g_master_buff[0], g_master_buff[1], g_master_buff[2], g_master_buff[3], 5000);
//
//
//    delay(5000);
//
//    // dont need to read bc no data returned
//}
//
//// some ideas about telemetry
//// for telemetry, need clarification
//
//// for bus Reset
//// ALSO ASSUMPTION: when asking for byte i am assuming its talking about only one byte of parameter
//// otherwise when it uses the term parameter, I am assuming there are 2 bytes of parameter
//// bit 1 and 0 = 1 then 3v3
//// bit 3 and 2 = 1 then 5v
//// bit 5 and 4 = 1 then 12v
//// bit 7 and 6 = 1 then Vbat
//void i2c_eps_fixedPowerBusReset(busReset)
//{
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_FIXED_POWER_BUS_RESET; // i2c command = get EPS telemetry
//    g_master_buff[2] = 0x00 | busReset;
//
//    // this one only needs to read
//    printf("Master will send data :");
//    print_i2c_data(g_master_buff);
//
//    // i2c write
//	i2c_read_write_helper(g_master_buff[0], g_master_buff[1], g_master_buff[2], g_master_buff[3], 5000);
//
//
//    delay(5000);
//
//    // dont need to read bc no data returned
//}
//
//void i2c_eps_manualReset()
//{
//    /* Set up i2c master to send data to slave */
//    g_master_buff[0] = I2C_EPS_ADDR; // i2c slave address = EPS motherboard
//    g_master_buff[1] = I2C_EPS_CMD_MANUAL_RESET; // i2c command = get EPS telemetry
//    g_master_buff[2] = 0xFF;
//
//    // this one only needs to read
//    printf("Master will send data :");
//    print_i2c_data(g_master_buff);
//
//    // i2c write
//	i2c_read_write_helper(g_master_buff[0], g_master_buff[1], g_master_buff[2], g_master_buff[3], 5000);
//
//
//    delay(5000);
//
//    // dont need to read bc no data returned
//}
