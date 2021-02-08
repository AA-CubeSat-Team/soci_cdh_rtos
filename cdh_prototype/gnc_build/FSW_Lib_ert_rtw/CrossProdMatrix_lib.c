/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CrossProdMatrix_lib.c
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

#include <gnc_build/FSW_Lib_ert_rtw/CrossProdMatrix_lib.h>
#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>
#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_private.h>

/*
 * Output and update for atomic system:
 *    '<S23>/CrossProdMatrix_lib'
 *    '<S23>/CrossProdMatrix_lib1'
 */
void CrossProdMatrix_lib(real_T rtu_Vector, real_T rtu_Vector_p, real_T
  rtu_Vector_j, real_T rty_XProdMat[9])
{
  /* SignalConversion: '<S29>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S29>/Constant1'
   *  Reshape: '<S29>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[0] = 0.0;

  /* SignalConversion: '<S29>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Reshape: '<S29>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[1] = rtu_Vector;

  /* SignalConversion: '<S29>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Constant: '<S29>/Constant2'
   *  Reshape: '<S29>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[4] = 0.0;

  /* SignalConversion: '<S29>/ConcatBufferAtVector ConcatenateIn6' incorporates:
   *  Reshape: '<S29>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[5] = rtu_Vector_p;

  /* SignalConversion: '<S29>/ConcatBufferAtVector ConcatenateIn7' incorporates:
   *  Reshape: '<S29>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[6] = rtu_Vector_j;

  /* SignalConversion: '<S29>/ConcatBufferAtVector ConcatenateIn9' incorporates:
   *  Constant: '<S29>/Constant3'
   *  Reshape: '<S29>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[8] = 0.0;

  /* Gain: '<S29>/Gain' incorporates:
   *  Reshape: '<S29>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[2] = -rtu_Vector_j;

  /* Gain: '<S29>/Gain1' incorporates:
   *  Reshape: '<S29>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[7] = -rtu_Vector_p;

  /* Gain: '<S29>/Gain3' incorporates:
   *  Reshape: '<S29>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[3] = -rtu_Vector;
}

/*
 * Output and update for atomic system:
 *    '<S18>/CrossProdMatrix_lib'
 *    '<S18>/CrossProdMatrix_lib1'
 */
void CrossProdMatrix_lib_d(const real_T rtu_Vector[3], real_T rty_XProdMat[9])
{
  /* SignalConversion: '<S46>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S46>/Constant1'
   *  Reshape: '<S46>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[0] = 0.0;

  /* SignalConversion: '<S46>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Reshape: '<S46>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[1] = rtu_Vector[2];

  /* SignalConversion: '<S46>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Constant: '<S46>/Constant2'
   *  Reshape: '<S46>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[4] = 0.0;

  /* SignalConversion: '<S46>/ConcatBufferAtVector ConcatenateIn6' incorporates:
   *  Reshape: '<S46>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[5] = rtu_Vector[0];

  /* SignalConversion: '<S46>/ConcatBufferAtVector ConcatenateIn7' incorporates:
   *  Reshape: '<S46>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[6] = rtu_Vector[1];

  /* SignalConversion: '<S46>/ConcatBufferAtVector ConcatenateIn9' incorporates:
   *  Constant: '<S46>/Constant3'
   *  Reshape: '<S46>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[8] = 0.0;

  /* Gain: '<S46>/Gain' incorporates:
   *  Reshape: '<S46>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[2] = -rtu_Vector[1];

  /* Gain: '<S46>/Gain1' incorporates:
   *  Reshape: '<S46>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[7] = -rtu_Vector[0];

  /* Gain: '<S46>/Gain3' incorporates:
   *  Reshape: '<S46>/Reshape to Cross Product Matrix'
   */
  rty_XProdMat[3] = -rtu_Vector[2];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
