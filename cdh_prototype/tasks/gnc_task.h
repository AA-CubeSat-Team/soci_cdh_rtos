#define GNC_ENABLE	0

//#include <wrappers/FSW_Lib_types.h>
//#ifndef STRUCTS
//#define STRUCTS
//struct {
//  real_T solar_panel_power_W[6];
//  real_T photodiodes_A[6];
//  real_T mag_body_T[9];
//  boolean_T mag_meas_valid[3];
//  real_T sun_meas_ss_deg[2];
//  boolean_T sun_meas_valid;
//  real_T gyro_body_radps[9];
//  boolean_T gyro_meas_valid[3];
//} sensor_bus;
//
//struct {
//  boolean_T mtq_valid[5];
//  boolean_T rwa_valid[4];
//  real_T rwa_power;
//  real_T mtq_power;
//  real_T rwa_rpm[4];
//} actuator_meas;
//
//struct {
//  real_T rwa_cmd_rpm[4];
//  real_T mtq_cmd_Am2[5];
//  real_T gnc_telemetry[6];
//} fsw_out;
//
//extern sensor_bus sens_var;
//extern actuator_meas actu_var;
//extern fsw_out fsw_var;
//#endif


void gnc_task(void *pvParameters);
