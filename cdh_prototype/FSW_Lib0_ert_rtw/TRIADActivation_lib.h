/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TRIADActivation_lib.h
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jan 14 15:17:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TRIADActivation_lib_h_
#define RTW_HEADER_TRIADActivation_lib_h_
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Block signals and states (default storage) for system '<S3>/TRIADActivation_lib' */
typedef struct {
  boolean_T Delay_DSTATE[10];          /* '<S159>/Delay' */
} DW_TRIADActivation_lib;

/* Parameters for system: '<S3>/TRIADActivation_lib' */
struct P_TRIADActivation_lib_ {
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S159>/Delay'
                                        */
  boolean_T Delay_InitialCondition;    /* Computed Parameter: Delay_InitialCondition
                                        * Referenced by: '<S159>/Delay'
                                        */
};

extern void TRIADActivation_lib_Init(DW_TRIADActivation_lib *localDW,
  P_TRIADActivation_lib *localP);
extern boolean_T TRIADActivation_lib(boolean_T rtu_TriadGroundCmd, boolean_T
  rtu_gyro_valid, boolean_T rtu_sunsensor_valid, boolean_T rtu_mag_valid,
  DW_TRIADActivation_lib *localDW);

#endif                                 /* RTW_HEADER_TRIADActivation_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
