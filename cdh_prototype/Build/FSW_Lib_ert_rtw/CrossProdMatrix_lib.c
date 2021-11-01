/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CrossProdMatrix_lib.c
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

#include "CrossProdMatrix_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for atomic system:
 *    '<S132>/CrossProdMatrix_lib'
 *    '<S132>/CrossProdMatrix_lib1'
 */
void CrossProdMatrix_lib(real_T rtu_vector, real_T rtu_vector_h, real_T
  rtu_vector_o, real_T rty_skew_mat[9])
{
  /* SignalConversion: '<S140>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S138>/null'
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[0] = 0.0;

  /* SignalConversion: '<S140>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[1] = rtu_vector;

  /* SignalConversion: '<S140>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Constant: '<S138>/null'
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[4] = 0.0;

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
  rty_skew_mat[8] = 0.0;

  /* Gain: '<S138>/Gain' incorporates:
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[2] = -rtu_vector_o;

  /* Gain: '<S138>/Gain3' incorporates:
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[3] = -rtu_vector;

  /* Gain: '<S138>/Gain1' incorporates:
   *  Reshape: '<S140>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[7] = -rtu_vector_h;
}

/*
 * Output and update for atomic system:
 *    '<S124>/CrossProdMatrix_lib'
 *    '<S124>/CrossProdMatrix_lib1'
 */
void CrossProdMatrix_lib_m(const real_T rtu_vector[3], real_T rty_skew_mat[9])
{
  /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S161>/null'
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[0] = 0.0;

  /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[1] = rtu_vector[2];

  /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Constant: '<S161>/null'
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[4] = 0.0;

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
  rty_skew_mat[8] = 0.0;

  /* Gain: '<S161>/Gain' incorporates:
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[2] = -rtu_vector[1];

  /* Gain: '<S161>/Gain3' incorporates:
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[3] = -rtu_vector[2];

  /* Gain: '<S161>/Gain1' incorporates:
   *  Reshape: '<S168>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[7] = -rtu_vector[0];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
