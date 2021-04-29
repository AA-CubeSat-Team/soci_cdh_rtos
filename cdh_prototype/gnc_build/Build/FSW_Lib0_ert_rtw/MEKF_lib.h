/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MEKF_lib.h
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MEKF_lib_h_
#define RTW_HEADER_MEKF_lib_h_
#include <math.h>
#include <string.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Child system includes */
#include "CrossProdMatrix_lib.h"
#include "TRIADActivation_lib.h"
#include "parallel_protection_lib.h"
#include "quat_rectify_lib.h"
#include "rt_sys_MEKF_lib_38.h"
#include "rt_sys_MEKF_lib_42.h"
#include "rt_sys_MEKF_lib_49.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<S1>/MEKF_lib' */
typedef struct {
  DW_IfWarningError IfWarningError_d;  /* '<S176>/If Warning//Error' */
  DW_TRIADActivation_lib TRIADActivation_lib_a;/* '<S3>/TRIADActivation_lib' */
  real_T Id_3[9];                      /* '<S150>/Id_3' */
  real_T Merge[4];                     /* '<S173>/Merge' */
  real_T UnitDelay_DSTATE[36];         /* '<S3>/Unit Delay' */
  real_T UnitDelay1_DSTATE[3];         /* '<S3>/Unit Delay1' */
  real_T UnitDelay3_DSTATE[4];         /* '<S3>/Unit Delay3' */
  real_T UnitDelay_DSTATE_p[4];        /* '<S113>/Unit Delay' */
} DW_MEKF_lib;

extern void MEKF_lib_Init(real_T rty_sc_quat[4], DW_MEKF_lib *localDW);
extern void MEKF_lib_Start(DW_MEKF_lib *localDW);
extern void MEKF_lib(const real_T rtu_sc2sun_eci_unit[3], const real_T
                     rtu_mag_eci_T[3], const real_T rtu_sun_meas_body_unit[3],
                     const real_T rtu_mag_meas_body_T[3], const real_T
                     rtu_gyro_meas_body_radps[3], boolean_T rtu_sunsensor_valid,
                     boolean_T rtu_mag_meas_valid, boolean_T rtu_gryo_meas_valid,
                     boolean_T rtu_triad_activate, real_T rty_sc_quat[4], real_T
                     rty_body_rates_radps[3], real_T rty_threeSigma_rad[6],
                     real_T rty_bias_radps[3], uint8_T *rty_mekf_telem,
                     DW_MEKF_lib *localDW);

#endif                                 /* RTW_HEADER_MEKF_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
