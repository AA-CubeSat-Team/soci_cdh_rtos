/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: null_control_lib.c
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

#include "null_control_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/* Output and update for atomic system: '<S236>/null_control_lib1' */
void null_control_lib(real_T rty_null_MTQ_cmd_Am2[3], P_null_control_lib *localP)
{
  /* Constant: '<S255>/null_control_input' */
  rty_null_MTQ_cmd_Am2[0] = localP->null_control_input_Value[0];
  rty_null_MTQ_cmd_Am2[1] = localP->null_control_input_Value[1];
  rty_null_MTQ_cmd_Am2[2] = localP->null_control_input_Value[2];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
