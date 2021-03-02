/*
 * dummy_type.h
 *
 *  Created on: Mar 1, 2021
 *      Author: USER
 */
#include <stdbool.h>

#ifndef DUMMY_TYPE_H_
#define DUMMY_TYPE_H_


typedef double real_T;
typedef bool boolean_T;

//temporary struct until we receive an functional GNC build folder
typedef struct {
  real_T solar_panel_power_W[6];
  real_T photodiodes_A[6];
  real_T mag_body_T[9];
  boolean_T mag_meas_valid[3];
  real_T sun_meas_ss_deg[2];
  boolean_T sun_meas_valid;
  real_T gyro_body_radps[9];
  boolean_T gyro_meas_valid[3];
} sensor_bus;

typedef struct {
  boolean_T mtq_valid[5];
  boolean_T rwa_valid[4];
  real_T rwa_power;
  real_T mtq_power;
  real_T rwa_rpm[4];
} actuator_meas;

typedef struct {
  real_T rwa_cmd_rpm[4];
  real_T mtq_cmd_Am2[5];
  real_T gnc_telemetry[6];
} fsw_out;

#endif /* DUMMY_TYPE_H_ */
