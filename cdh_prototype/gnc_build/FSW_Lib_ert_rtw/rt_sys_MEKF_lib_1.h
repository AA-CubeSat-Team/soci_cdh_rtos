/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_sys_MEKF_lib_1.h
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

#ifndef RTW_HEADER_rt_sys_MEKF_lib_1_h_
#define RTW_HEADER_rt_sys_MEKF_lib_1_h_
#include <math.h>
#ifndef FSW_Lib_COMMON_INCLUDES_
# define FSW_Lib_COMMON_INCLUDES_
#include <gnc_build/FSW_Lib_ert_rtw/rtwtypes.h>
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* FSW_Lib_COMMON_INCLUDES_ */

#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_types.h>

extern void PositiveTrace(real_T rtu_traceDCM, const real_T rtu_DCM[9], real_T
  *rty_qwqxqyqz, real_T rty_qwqxqyqz_e[3]);

#endif                                 /* RTW_HEADER_rt_sys_MEKF_lib_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
