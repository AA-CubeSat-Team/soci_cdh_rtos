/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MEKF_lib.h
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.232
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep  9 13:53:00 2020
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
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef FSW_Lib_COMMON_INCLUDES_
# define FSW_Lib_COMMON_INCLUDES_
#include <FSW_Lib_ert_rtw/rtwtypes.h>
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* FSW_Lib_COMMON_INCLUDES_ */

#include <FSW_Lib_ert_rtw/FSW_Lib_types.h>

/* Child system includes */
#include <FSW_Lib_ert_rtw/CrossProdMatrix_lib.h>
#include <FSW_Lib_ert_rtw/rt_sys_MEKF_lib_1.h>
#include <FSW_Lib_ert_rtw/rt_sys_MEKF_lib_12.h>
#include <FSW_Lib_ert_rtw/rt_sys_MEKF_lib_5.h>
#include <FSW_Lib_ert_rtw/rtGetNaN.h>
#include <FSW_Lib_ert_rtw/rt_nonfinite.h>

/* Block signals and states (default storage) for system '<S1>/MEKF_lib' */
typedef struct {
  DW_IfWarningError IfWarningError_d;  /* '<S69>/If Warning//Error' */
  real_T Merge1[4];                    /* '<S3>/Merge1' */
  real_T RateTransition[9];            /* '<S50>/Rate Transition' */
  real_T IdentityMatrix[9];            /* '<S50>/Identity Matrix' */
  real_T Merge[4];                     /* '<S66>/Merge' */
  real_T UnitDelay_DSTATE[36];         /* '<S3>/Unit Delay' */
  real_T UnitDelay1_DSTATE[3];         /* '<S3>/Unit Delay1' */
  real_T UnitDelay2_DSTATE[4];         /* '<S15>/Unit Delay2' */
  real_T UnitDelay_DSTATE_p[4];        /* '<S19>/Unit Delay' */
  real_T RateTransition_Buffer0[9];    /* '<S50>/Rate Transition' */
} DW_MEKF_lib;

extern void MATLABFunction(real_T rtu_u, real_T rtu_min_angle_deg, boolean_T
  *rty_y);
extern void MEKF_lib_Init(real_T rty_sc_quat[4], DW_MEKF_lib *localDW);
extern void MEKF_lib_Start(DW_MEKF_lib *localDW);
extern void MEKF_libTID0(RT_MODEL * const rtM, const real_T rtu_sc2sun_eci_unit
  [3], const real_T rtu_mag_eci_T[3], const real_T rtu_sun_meas_body_unit[3],
  const real_T rtu_mag_meas_body_T[3], const real_T rtu_gyro_meas_body_radps[3],
  boolean_T rtu_sunsensor_valid, boolean_T rtu_mag_meas_valid, boolean_T
  rtu_gryo_meas_valid, boolean_T rtu_Triad_Activate, real_T rty_sc_quat[4],
  real_T rty_sc_body_rates[3], real_T rty_uSig_deg[3], real_T rty_Bias_radps[3],
  DW_MEKF_lib *localDW);
extern void MEKF_libTID2(DW_MEKF_lib *localDW);

#endif                                 /* RTW_HEADER_MEKF_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
