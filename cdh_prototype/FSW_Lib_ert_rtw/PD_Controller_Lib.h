/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PD_Controller_Lib.h
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 5.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May 24 14:44:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Debugging
 *    2. Execution efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PD_Controller_Lib_h_
#define RTW_HEADER_PD_Controller_Lib_h_
#ifndef FSW_Lib_COMMON_INCLUDES_
#define FSW_Lib_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FSW_Lib_COMMON_INCLUDES_ */

#include "FSW_Lib_types.h"

extern void PD_Controller_Lib(const real_T rtu_quat_err[4], const real_T
  rtu_w_err_radps[3], real_T rty_cmd_Nm[3]);

#endif                                 /* RTW_HEADER_PD_Controller_Lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
