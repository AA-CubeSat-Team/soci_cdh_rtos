/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TRIADActivation_lib.h
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Oct 26 16:29:45 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TRIADActivation_lib_h_
#define RTW_HEADER_TRIADActivation_lib_h_
#ifndef FSW_Lib_COMMON_INCLUDES_
# define FSW_Lib_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib_COMMON_INCLUDES_ */

#include "FSW_Lib_types.h"

/* Block signals and states (default storage) for system '<S3>/TRIADActivation_lib' */
typedef struct {
  boolean_T Delay_DSTATE[10];          /* '<S159>/Delay' */
} DW_TRIADActivation_lib;

extern void TRIADActivation_lib_Init(DW_TRIADActivation_lib *localDW);
extern boolean_T TRIADActivation_lib(boolean_T rtu_TriadGroundCmd, boolean_T
  rtu_gyro_valid, boolean_T rtu_sunsensor_valid, boolean_T rtu_mag_valid,
  DW_TRIADActivation_lib *localDW);

#endif                                 /* RTW_HEADER_TRIADActivation_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
