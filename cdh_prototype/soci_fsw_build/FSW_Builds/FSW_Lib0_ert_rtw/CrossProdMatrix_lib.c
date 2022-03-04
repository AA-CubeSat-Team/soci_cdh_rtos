/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CrossProdMatrix_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.376
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jan 13 14:39:11 2022
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
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for atomic system:
 *    '<S131>/CrossProdMatrix_lib'
 *    '<S131>/CrossProdMatrix_lib1'
 */
void CrossProdMatrix_lib(real_T rtu_vector, real_T rtu_vector_a, real_T
  rtu_vector_f, real_T rty_skew_mat[9])
{
  /* SignalConversion: '<S139>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S137>/null'
   *  Reshape: '<S139>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[0] = 0.0;

  /* SignalConversion: '<S139>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Reshape: '<S139>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[1] = rtu_vector;

  /* SignalConversion: '<S139>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Constant: '<S137>/null'
   *  Reshape: '<S139>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[4] = 0.0;

  /* SignalConversion: '<S139>/ConcatBufferAtVector ConcatenateIn6' incorporates:
   *  Reshape: '<S139>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[5] = rtu_vector_a;

  /* SignalConversion: '<S139>/ConcatBufferAtVector ConcatenateIn7' incorporates:
   *  Reshape: '<S139>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[6] = rtu_vector_f;

  /* SignalConversion: '<S139>/ConcatBufferAtVector ConcatenateIn9' incorporates:
   *  Constant: '<S137>/null'
   *  Reshape: '<S139>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[8] = 0.0;

  /* Gain: '<S137>/Gain' incorporates:
   *  Reshape: '<S139>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[2] = -rtu_vector_f;

  /* Gain: '<S137>/Gain3' incorporates:
   *  Reshape: '<S139>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[3] = -rtu_vector;

  /* Gain: '<S137>/Gain1' incorporates:
   *  Reshape: '<S139>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[7] = -rtu_vector_a;
}

/*
 * Output and update for atomic system:
 *    '<S123>/CrossProdMatrix_lib'
 *    '<S123>/CrossProdMatrix_lib1'
 */
void CrossProdMatrix_lib_j(const real_T rtu_vector[3], real_T rty_skew_mat[9])
{
  /* SignalConversion: '<S167>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S160>/null'
   *  Reshape: '<S167>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[0] = 0.0;

  /* SignalConversion: '<S167>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Reshape: '<S167>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[1] = rtu_vector[2];

  /* SignalConversion: '<S167>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Constant: '<S160>/null'
   *  Reshape: '<S167>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[4] = 0.0;

  /* SignalConversion: '<S167>/ConcatBufferAtVector ConcatenateIn6' incorporates:
   *  Reshape: '<S167>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[5] = rtu_vector[0];

  /* SignalConversion: '<S167>/ConcatBufferAtVector ConcatenateIn7' incorporates:
   *  Reshape: '<S167>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[6] = rtu_vector[1];

  /* SignalConversion: '<S167>/ConcatBufferAtVector ConcatenateIn9' incorporates:
   *  Constant: '<S160>/null'
   *  Reshape: '<S167>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[8] = 0.0;

  /* Gain: '<S160>/Gain' incorporates:
   *  Reshape: '<S167>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[2] = -rtu_vector[1];

  /* Gain: '<S160>/Gain3' incorporates:
   *  Reshape: '<S167>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[3] = -rtu_vector[2];

  /* Gain: '<S160>/Gain1' incorporates:
   *  Reshape: '<S167>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[7] = -rtu_vector[0];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
