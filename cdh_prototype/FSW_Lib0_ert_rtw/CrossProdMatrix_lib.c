/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CrossProdMatrix_lib.c
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

#include "CrossProdMatrix_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for atomic system:
 *    '<S132>/CrossProdMatrix_lib'
 *    '<S132>/CrossProdMatrix_lib1'
 */
void CrossProdMatrix_lib(real_T rtu_vector, real_T rtu_vector_h, real_T
  rtu_vector_o, real_T rty_skew_mat[9], P_CrossProdMatrix_lib *localP)
{
  /* SignalConversion: '<S140>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S138>/null'
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[0] = localP->null_Value;

  /* SignalConversion: '<S140>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[1] = rtu_vector;

  /* SignalConversion: '<S140>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Constant: '<S138>/null'
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[4] = localP->null_Value;

  /* SignalConversion: '<S140>/ConcatBufferAtVector ConcatenateIn6' incorporates:
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[5] = rtu_vector_h;

  /* SignalConversion: '<S140>/ConcatBufferAtVector ConcatenateIn7' incorporates:
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[6] = rtu_vector_o;

  /* SignalConversion: '<S140>/ConcatBufferAtVector ConcatenateIn9' incorporates:
   *  Constant: '<S138>/null'
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[8] = localP->null_Value;

  /* Gain: '<S138>/Gain' incorporates:
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[2] = localP->Gain_Gain * rtu_vector_o;

  /* Gain: '<S138>/Gain3' incorporates:
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[3] = localP->Gain3_Gain * rtu_vector;

  /* Gain: '<S138>/Gain1' incorporates:
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[7] = localP->Gain1_Gain * rtu_vector_h;
}

/*
 * Output and update for atomic system:
 *    '<S124>/CrossProdMatrix_lib'
 *    '<S124>/CrossProdMatrix_lib1'
 */
void CrossProdMatrix_lib_m(const real_T rtu_vector[3], real_T rty_skew_mat[9],
  P_CrossProdMatrix_lib_g *localP)
{
  /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S161>/null'
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[0] = localP->null_Value;

  /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[1] = rtu_vector[2];

  /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Constant: '<S161>/null'
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[4] = localP->null_Value;

  /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn6' incorporates:
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[5] = rtu_vector[0];

  /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn7' incorporates:
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[6] = rtu_vector[1];

  /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn9' incorporates:
   *  Constant: '<S161>/null'
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[8] = localP->null_Value;

  /* Gain: '<S161>/Gain' incorporates:
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[2] = localP->Gain_Gain * rtu_vector[1];

  /* Gain: '<S161>/Gain3' incorporates:
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[3] = localP->Gain3_Gain * rtu_vector[2];

  /* Gain: '<S161>/Gain1' incorporates:
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[7] = localP->Gain1_Gain * rtu_vector[0];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
