/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CrossProdMatrix_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:43:08 2021
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
 *    '<S30>/CrossProdMatrix_lib'
 *    '<S30>/CrossProdMatrix_lib1'
 */
void CrossProdMatrix_lib(real_T rtu_vector, real_T rtu_vector_p, real_T
  rtu_vector_j, real_T rty_skew_mat[9])
{
  /* SignalConversion: '<S38>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S36>/null'
   *  Reshape: '<S38>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[0] = 0.0;

  /* SignalConversion: '<S38>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Reshape: '<S38>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[1] = rtu_vector;

  /* SignalConversion: '<S38>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Constant: '<S36>/null'
   *  Reshape: '<S38>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[4] = 0.0;

  /* SignalConversion: '<S38>/ConcatBufferAtVector ConcatenateIn6' incorporates:
   *  Reshape: '<S38>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[5] = rtu_vector_p;

  /* SignalConversion: '<S38>/ConcatBufferAtVector ConcatenateIn7' incorporates:
   *  Reshape: '<S38>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[6] = rtu_vector_j;

  /* SignalConversion: '<S38>/ConcatBufferAtVector ConcatenateIn9' incorporates:
   *  Constant: '<S36>/null'
   *  Reshape: '<S38>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[8] = 0.0;

  /* Gain: '<S36>/Gain' incorporates:
   *  Reshape: '<S38>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[2] = -rtu_vector_j;

  /* Gain: '<S36>/Gain3' incorporates:
   *  Reshape: '<S38>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[3] = -rtu_vector;

  /* Gain: '<S36>/Gain1' incorporates:
   *  Reshape: '<S38>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[7] = -rtu_vector_p;
}

/*
 * Output and update for atomic system:
 *    '<S22>/CrossProdMatrix_lib'
 *    '<S22>/CrossProdMatrix_lib1'
 */
void CrossProdMatrix_lib_d(const real_T rtu_vector[3], real_T rty_skew_mat[9])
{
  /* SignalConversion: '<S63>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S56>/null'
   *  Reshape: '<S63>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[0] = 0.0;

  /* SignalConversion: '<S63>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Reshape: '<S63>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[1] = rtu_vector[2];

  /* SignalConversion: '<S63>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Constant: '<S56>/null'
   *  Reshape: '<S63>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[4] = 0.0;

  /* SignalConversion: '<S63>/ConcatBufferAtVector ConcatenateIn6' incorporates:
   *  Reshape: '<S63>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[5] = rtu_vector[0];

  /* SignalConversion: '<S63>/ConcatBufferAtVector ConcatenateIn7' incorporates:
   *  Reshape: '<S63>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[6] = rtu_vector[1];

  /* SignalConversion: '<S63>/ConcatBufferAtVector ConcatenateIn9' incorporates:
   *  Constant: '<S56>/null'
   *  Reshape: '<S63>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[8] = 0.0;

  /* Gain: '<S56>/Gain' incorporates:
   *  Reshape: '<S63>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[2] = -rtu_vector[1];

  /* Gain: '<S56>/Gain3' incorporates:
   *  Reshape: '<S63>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[3] = -rtu_vector[2];

  /* Gain: '<S56>/Gain1' incorporates:
   *  Reshape: '<S63>/Reshape (9) to [3x3] column-major'
   */
  rty_skew_mat[7] = -rtu_vector[0];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
