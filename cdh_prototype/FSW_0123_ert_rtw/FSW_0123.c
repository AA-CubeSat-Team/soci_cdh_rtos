/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_0123.c
 *
 * Code generated for Simulink model 'FSW_0123'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Jan 23 23:50:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "FSW_0123.h"
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/*=========*
 * Asserts *
 *=========*/
#ifndef utAssert
# if defined(DOASSERTS)
#  if !defined(PRINT_ASSERTS)
#    include <assert.h>
#    define utAssert(exp)              assert(exp)
#  else
#    include <stdio.h>

static void _assert(char *statement, char *file, int line)
{
  printf("%s in %s on line %d\n", statement, file, line);
}

#   define utAssert(_EX)               ((_EX) ? (void)0 : _assert(#_EX, __FILE__, __LINE__))
#  endif

# else
#  define utAssert(exp)                                          /* do nothing */
# endif
#endif

extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/* Model step function */
void FSW_0123_step(void)
{
  real_T rtb_Product2_b;
  real_T rtb_Product1_b;
  real_T rtb_Sum_b;
  real_T rtb_MatrixConcatenate2[9];
  real_T rtb_MatrixMultiply1[9];
  int32_T i;
  int32_T i_0;
  real_T rtb_Switch_b0_idx_3;
  real_T rtb_MathFunction_idx_1;
  real_T rtb_Switch_b0_idx_2;
  real_T rtb_MathFunction_idx_0;
  real_T rtb_Switch_b0_idx_1;
  real_T rtb_Switch_b0_idx_0;
  real_T rtb_VariableSelector_idx_2;
  real_T rtb_VariableSelector_idx_1;
  int32_T rtb_MatrixMultiply1_tmp;
  int32_T rtb_MatrixMultiply1_tmp_0;

  /* Sum: '<S6>/Sum of Elements' incorporates:
   *  Inport: '<Root>/mag'
   *  Math: '<S6>/Math Function'
   *  S-Function (sdspperm2): '<Root>/Variable Selector'
   */
  rtb_Product2_b = (rtU.mag[0] * rtU.mag[0] + rtU.mag[1] * rtU.mag[1]) +
    rtU.mag[2] * rtU.mag[2];

  /* Math: '<S6>/Math Function1'
   *
   * About '<S6>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product2_b < 0.0) {
    rtb_Product2_b = -sqrt(fabs(rtb_Product2_b));
  } else {
    rtb_Product2_b = sqrt(rtb_Product2_b);
  }

  /* End of Math: '<S6>/Math Function1' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/mag'
   *  Product: '<S6>/Product'
   *  S-Function (sdspperm2): '<Root>/Variable Selector'
   */
  if (rtb_Product2_b > 0.01) {
    rtb_Switch_b0_idx_0 = rtU.mag[0];
    rtb_Switch_b0_idx_1 = rtU.mag[1];
    rtb_Switch_b0_idx_2 = rtU.mag[2];
    rtb_Switch_b0_idx_3 = rtb_Product2_b;
  } else {
    rtb_Switch_b0_idx_0 = rtU.mag[0] * 0.0;
    rtb_Switch_b0_idx_1 = rtU.mag[1] * 0.0;
    rtb_Switch_b0_idx_2 = rtU.mag[2] * 0.0;
    rtb_Switch_b0_idx_3 = 1.0;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/sun'
   */
  rtb_Product2_b = 57.295779513082323 * rtU.sun[0];

  /* Gain: '<Root>/Gain1' incorporates:
   *  Inport: '<Root>/sun'
   */
  rtb_Product1_b = 57.295779513082323 * rtU.sun[1];

  /* Trigonometry: '<Root>/Cos1' */
  rtb_Sum_b = cos(rtb_Product1_b);

  /* Product: '<Root>/Multiply2' incorporates:
   *  Trigonometry: '<Root>/Sin'
   */
  rtb_MathFunction_idx_0 = sin(rtb_Product2_b) * rtb_Sum_b;

  /* Trigonometry: '<Root>/Cos' */
  rtb_Product2_b = cos(rtb_Product2_b);

  /* Product: '<Root>/Multiply' */
  rtb_MathFunction_idx_1 = rtb_Product2_b * rtb_Sum_b;

  /* Product: '<Root>/Multiply1' incorporates:
   *  Trigonometry: '<Root>/Sin1'
   */
  rtb_Product2_b *= sin(rtb_Product1_b);

  /* Product: '<S6>/Divide' */
  rtb_Product1_b = rtb_Switch_b0_idx_0 / rtb_Switch_b0_idx_3;
  rtb_VariableSelector_idx_1 = rtb_Switch_b0_idx_1 / rtb_Switch_b0_idx_3;
  rtb_VariableSelector_idx_2 = rtb_Switch_b0_idx_2 / rtb_Switch_b0_idx_3;

  /* Sum: '<S7>/Sum of Elements' incorporates:
   *  Math: '<S7>/Math Function'
   */
  rtb_Sum_b = (rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0 +
               rtb_MathFunction_idx_1 * rtb_MathFunction_idx_1) + rtb_Product2_b
    * rtb_Product2_b;

  /* Math: '<S7>/Math Function1'
   *
   * About '<S7>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Sum_b < 0.0) {
    rtb_Sum_b = -sqrt(fabs(rtb_Sum_b));
  } else {
    rtb_Sum_b = sqrt(rtb_Sum_b);
  }

  /* End of Math: '<S7>/Math Function1' */

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Product: '<S7>/Product'
   */
  if (rtb_Sum_b > 0.01) {
    rtb_Switch_b0_idx_0 = rtb_MathFunction_idx_0;
    rtb_Switch_b0_idx_1 = rtb_MathFunction_idx_1;
    rtb_Switch_b0_idx_2 = rtb_Product2_b;
    rtb_Switch_b0_idx_3 = rtb_Sum_b;
  } else {
    rtb_Switch_b0_idx_0 = rtb_MathFunction_idx_0 * 0.0;
    rtb_Switch_b0_idx_1 = rtb_MathFunction_idx_1 * 0.0;
    rtb_Switch_b0_idx_2 = rtb_Product2_b * 0.0;
    rtb_Switch_b0_idx_3 = 1.0;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Product: '<S7>/Divide' */
  rtb_MathFunction_idx_0 = rtb_Switch_b0_idx_0 / rtb_Switch_b0_idx_3;
  rtb_MathFunction_idx_1 = rtb_Switch_b0_idx_1 / rtb_Switch_b0_idx_3;
  rtb_Product2_b = rtb_Switch_b0_idx_2 / rtb_Switch_b0_idx_3;

  /* Product: '<S1>/Element product' */
  rtb_Switch_b0_idx_3 = rtb_VariableSelector_idx_2 * rtb_MathFunction_idx_0;
  rtb_Switch_b0_idx_2 = rtb_Product1_b * rtb_MathFunction_idx_1;
  rtb_Switch_b0_idx_1 = rtb_VariableSelector_idx_1 * rtb_MathFunction_idx_0;

  /* Sum: '<S1>/Add3' incorporates:
   *  Product: '<S1>/Element product'
   */
  rtb_MathFunction_idx_0 = rtb_VariableSelector_idx_1 * rtb_Product2_b -
    rtb_VariableSelector_idx_2 * rtb_MathFunction_idx_1;
  rtb_MathFunction_idx_1 = rtb_Switch_b0_idx_3 - rtb_Product1_b * rtb_Product2_b;
  rtb_Product2_b = rtb_Switch_b0_idx_2 - rtb_Switch_b0_idx_1;

  /* S-Function (sdsp2norm2): '<Root>/Normalization6' */
  rtb_Sum_b = 1.0 / (sqrt((rtb_MathFunction_idx_0 * rtb_MathFunction_idx_0 +
    rtb_MathFunction_idx_1 * rtb_MathFunction_idx_1) + rtb_Product2_b *
    rtb_Product2_b) + 1.0E-10);
  rtb_MathFunction_idx_0 *= rtb_Sum_b;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix Concatenate2In1' */
  rtb_MatrixConcatenate2[0] = rtb_Product1_b;

  /* S-Function (sdsp2norm2): '<Root>/Normalization6' */
  rtb_MathFunction_idx_1 *= rtb_Sum_b;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix Concatenate2In1' */
  rtb_MatrixConcatenate2[1] = rtb_VariableSelector_idx_1;

  /* S-Function (sdsp2norm2): '<Root>/Normalization6' */
  rtb_Product2_b *= rtb_Sum_b;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix Concatenate2In1' */
  rtb_MatrixConcatenate2[2] = rtb_VariableSelector_idx_2;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix Concatenate2In2' */
  rtb_MatrixConcatenate2[3] = rtb_MathFunction_idx_0;

  /* Sum: '<S2>/Add3' incorporates:
   *  Product: '<S2>/Element product'
   */
  rtb_MatrixConcatenate2[6] = rtb_VariableSelector_idx_1 * rtb_Product2_b -
    rtb_VariableSelector_idx_2 * rtb_MathFunction_idx_1;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix Concatenate2In2' */
  rtb_MatrixConcatenate2[4] = rtb_MathFunction_idx_1;

  /* Sum: '<S2>/Add3' incorporates:
   *  Product: '<S2>/Element product'
   */
  rtb_MatrixConcatenate2[7] = rtb_VariableSelector_idx_2 *
    rtb_MathFunction_idx_0 - rtb_Product1_b * rtb_Product2_b;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix Concatenate2In2' */
  rtb_MatrixConcatenate2[5] = rtb_Product2_b;

  /* Sum: '<S2>/Add3' incorporates:
   *  Product: '<S2>/Element product'
   */
  rtb_MatrixConcatenate2[8] = rtb_Product1_b * rtb_MathFunction_idx_1 -
    rtb_VariableSelector_idx_1 * rtb_MathFunction_idx_0;

  /* Product: '<Root>/Matrix Multiply1' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      rtb_MatrixMultiply1_tmp = i + 3 * i_0;
      rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] = 0.0;
      rtb_MatrixMultiply1_tmp_0 = 3 * i_0 + i;
      rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] =
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0] + rtConstB.MathFunction1
        [3 * i_0] * rtb_MatrixConcatenate2[i];
      rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] = rtConstB.MathFunction1[3 *
        i_0 + 1] * rtb_MatrixConcatenate2[i + 3] +
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0];
      rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp] = rtConstB.MathFunction1[3 *
        i_0 + 2] * rtb_MatrixConcatenate2[i + 6] +
        rtb_MatrixMultiply1[rtb_MatrixMultiply1_tmp_0];
    }
  }

  /* End of Product: '<Root>/Matrix Multiply1' */

  /* Sum: '<S13>/Add' */
  rtb_MathFunction_idx_0 = (rtb_MatrixMultiply1[0] + rtb_MatrixMultiply1[4]) +
    rtb_MatrixMultiply1[8];

  /* If: '<S5>/If' incorporates:
   *  If: '<S10>/Find Maximum Diagonal Value'
   */
  if (rtb_MathFunction_idx_0 > 0.0) {
    /* Outputs for IfAction SubSystem: '<S5>/Positive Trace' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* Sqrt: '<S11>/sqrt' incorporates:
     *  Constant: '<S11>/Constant'
     *  Sum: '<S11>/Sum'
     */
    rtb_Sum_b = sqrt(rtb_MathFunction_idx_0 + 1.0);

    /* Gain: '<S11>/Gain' */
    rtDW.Merge[0] = 0.5 * rtb_Sum_b;

    /* Gain: '<S11>/Gain1' */
    rtb_Sum_b *= 2.0;

    /* Product: '<S11>/Product' incorporates:
     *  Sum: '<S33>/Add'
     *  Sum: '<S34>/Add'
     *  Sum: '<S35>/Add'
     */
    rtDW.Merge[1] = (rtb_MatrixMultiply1[7] - rtb_MatrixMultiply1[5]) /
      rtb_Sum_b;
    rtDW.Merge[2] = (rtb_MatrixMultiply1[2] - rtb_MatrixMultiply1[6]) /
      rtb_Sum_b;
    rtDW.Merge[3] = (rtb_MatrixMultiply1[3] - rtb_MatrixMultiply1[1]) /
      rtb_Sum_b;

    /* End of Outputs for SubSystem: '<S5>/Positive Trace' */
  } else {
    /* Outputs for IfAction SubSystem: '<S5>/Negative Trace' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    if ((rtb_MatrixMultiply1[4] > rtb_MatrixMultiply1[0]) &&
        (rtb_MatrixMultiply1[4] > rtb_MatrixMultiply1[8])) {
      /* Outputs for IfAction SubSystem: '<S10>/Maximum Value at DCM(2,2)' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* If: '<S10>/Find Maximum Diagonal Value' incorporates:
       *  Constant: '<S26>/Constant1'
       *  Constant: '<S27>/Constant'
       *  Gain: '<S15>/Gain'
       *  Gain: '<S15>/Gain1'
       *  Gain: '<S15>/Gain3'
       *  Gain: '<S15>/Gain4'
       *  Product: '<S15>/Product'
       *  Product: '<S26>/Product'
       *  Sqrt: '<S15>/sqrt'
       *  Sum: '<S23>/Add'
       *  Sum: '<S24>/Add'
       *  Sum: '<S25>/Add'
       *  Sum: '<S27>/Add'
       *  Switch: '<S26>/Switch'
       */
      rtb_Sum_b = sqrt(((rtb_MatrixMultiply1[4] - rtb_MatrixMultiply1[0]) -
                        rtb_MatrixMultiply1[8]) + 1.0);
      if (rtb_Sum_b != 0.0) {
        rtb_Switch_b0_idx_3 = 0.5;
        rtb_Switch_b0_idx_2 = rtb_Sum_b;
      } else {
        rtb_Switch_b0_idx_3 = 0.0;
        rtb_Switch_b0_idx_2 = 1.0;
      }

      rtb_MathFunction_idx_0 = rtb_Switch_b0_idx_3 / rtb_Switch_b0_idx_2;
      rtDW.Merge[1] = (rtb_MatrixMultiply1[1] + rtb_MatrixMultiply1[3]) *
        rtb_MathFunction_idx_0;
      rtDW.Merge[3] = (rtb_MatrixMultiply1[5] + rtb_MatrixMultiply1[7]) *
        rtb_MathFunction_idx_0;
      rtDW.Merge[0] = (rtb_MatrixMultiply1[2] - rtb_MatrixMultiply1[6]) *
        rtb_MathFunction_idx_0;
      rtDW.Merge[2] = 0.5 * rtb_Sum_b;

      /* End of Outputs for SubSystem: '<S10>/Maximum Value at DCM(2,2)' */
    } else if (rtb_MatrixMultiply1[8] > rtb_MatrixMultiply1[0]) {
      /* Outputs for IfAction SubSystem: '<S10>/Maximum Value at DCM(3,3)' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      /* If: '<S10>/Find Maximum Diagonal Value' incorporates:
       *  Constant: '<S31>/Constant1'
       *  Constant: '<S32>/Constant'
       *  Gain: '<S16>/Gain'
       *  Gain: '<S16>/Gain1'
       *  Gain: '<S16>/Gain2'
       *  Gain: '<S16>/Gain3'
       *  Product: '<S16>/Product'
       *  Product: '<S31>/Product'
       *  Sqrt: '<S16>/sqrt'
       *  Sum: '<S28>/Add'
       *  Sum: '<S29>/Add'
       *  Sum: '<S30>/Add'
       *  Sum: '<S32>/Add'
       *  Switch: '<S31>/Switch'
       */
      rtb_Sum_b = sqrt(((rtb_MatrixMultiply1[8] - rtb_MatrixMultiply1[0]) -
                        rtb_MatrixMultiply1[4]) + 1.0);
      if (rtb_Sum_b != 0.0) {
        rtb_Switch_b0_idx_3 = 0.5;
        rtb_Switch_b0_idx_2 = rtb_Sum_b;
      } else {
        rtb_Switch_b0_idx_3 = 0.0;
        rtb_Switch_b0_idx_2 = 1.0;
      }

      rtb_MathFunction_idx_0 = rtb_Switch_b0_idx_3 / rtb_Switch_b0_idx_2;
      rtDW.Merge[1] = (rtb_MatrixMultiply1[2] + rtb_MatrixMultiply1[6]) *
        rtb_MathFunction_idx_0;
      rtDW.Merge[2] = (rtb_MatrixMultiply1[5] + rtb_MatrixMultiply1[7]) *
        rtb_MathFunction_idx_0;
      rtDW.Merge[0] = (rtb_MatrixMultiply1[3] - rtb_MatrixMultiply1[1]) *
        rtb_MathFunction_idx_0;
      rtDW.Merge[3] = 0.5 * rtb_Sum_b;

      /* End of Outputs for SubSystem: '<S10>/Maximum Value at DCM(3,3)' */
    } else {
      /* Outputs for IfAction SubSystem: '<S10>/Maximum Value at DCM(1,1)' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* If: '<S10>/Find Maximum Diagonal Value' incorporates:
       *  Constant: '<S21>/Constant1'
       *  Constant: '<S22>/Constant'
       *  Gain: '<S14>/Gain'
       *  Gain: '<S14>/Gain1'
       *  Gain: '<S14>/Gain2'
       *  Gain: '<S14>/Gain3'
       *  Product: '<S14>/Product'
       *  Product: '<S21>/Product'
       *  Sqrt: '<S14>/sqrt'
       *  Sum: '<S18>/Add'
       *  Sum: '<S19>/Add'
       *  Sum: '<S20>/Add'
       *  Sum: '<S22>/Add'
       *  Switch: '<S21>/Switch'
       */
      rtb_Sum_b = sqrt(((rtb_MatrixMultiply1[0] - rtb_MatrixMultiply1[4]) -
                        rtb_MatrixMultiply1[8]) + 1.0);
      if (rtb_Sum_b != 0.0) {
        rtb_Switch_b0_idx_3 = 0.5;
        rtb_Switch_b0_idx_2 = rtb_Sum_b;
      } else {
        rtb_Switch_b0_idx_3 = 0.0;
        rtb_Switch_b0_idx_2 = 1.0;
      }

      rtb_MathFunction_idx_0 = rtb_Switch_b0_idx_3 / rtb_Switch_b0_idx_2;
      rtDW.Merge[2] = (rtb_MatrixMultiply1[1] + rtb_MatrixMultiply1[3]) *
        rtb_MathFunction_idx_0;
      rtDW.Merge[3] = (rtb_MatrixMultiply1[2] + rtb_MatrixMultiply1[6]) *
        rtb_MathFunction_idx_0;
      rtDW.Merge[0] = (rtb_MatrixMultiply1[7] - rtb_MatrixMultiply1[5]) *
        rtb_MathFunction_idx_0;
      rtDW.Merge[1] = 0.5 * rtb_Sum_b;

      /* End of Outputs for SubSystem: '<S10>/Maximum Value at DCM(1,1)' */
    }

    /* End of Outputs for SubSystem: '<S5>/Negative Trace' */
  }

  /* End of If: '<S5>/If' */

  /* Signum: '<Root>/Sign' */
  if (rtDW.Merge[0] < 0.0) {
    rtb_Sum_b = -1.0;
  } else if (rtDW.Merge[0] > 0.0) {
    rtb_Sum_b = 1.0;
  } else if (rtDW.Merge[0] == 0.0) {
    rtb_Sum_b = 0.0;
  } else {
    rtb_Sum_b = (rtNaN);
  }

  /* End of Signum: '<Root>/Sign' */

  /* Product: '<Root>/Multiply3' */
  rtb_Switch_b0_idx_0 = rtb_Sum_b * rtDW.Merge[0];
  rtb_Switch_b0_idx_1 = rtb_Sum_b * rtDW.Merge[1];
  rtb_Switch_b0_idx_2 = rtb_Sum_b * rtDW.Merge[2];
  rtb_Switch_b0_idx_3 = rtb_Sum_b * rtDW.Merge[3];

  /* Product: '<S48>/Product2' incorporates:
   *  Product: '<S49>/Product2'
   *  Sum: '<S49>/Sum'
   *  UnaryMinus: '<S8>/Unary Minus1'
   */
  rtb_Sum_b = -rtb_Switch_b0_idx_2 * 0.0;

  /* Product: '<S48>/Product3' incorporates:
   *  Product: '<S49>/Product3'
   *  Product: '<S50>/Product3'
   *  Sum: '<S49>/Sum'
   *  Sum: '<S50>/Sum'
   *  UnaryMinus: '<S8>/Unary Minus2'
   */
  rtb_MathFunction_idx_1 = -rtb_Switch_b0_idx_3 * 0.0;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Product: '<S48>/Product'
   *  Product: '<S48>/Product1'
   *  Product: '<S48>/Product2'
   *  Product: '<S48>/Product3'
   *  Sum: '<S48>/Sum'
   *  UnaryMinus: '<S8>/Unary Minus'
   */
  if (((rtb_Switch_b0_idx_0 - -rtb_Switch_b0_idx_1 * 0.0) - rtb_Sum_b) -
      rtb_MathFunction_idx_1 >= 0.0) {
    rtb_MathFunction_idx_0 = 1.0;
  } else {
    rtb_MathFunction_idx_0 = -1.0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* UnaryMinus: '<S8>/Unary Minus' */
  rtb_Product2_b = rtb_Switch_b0_idx_1;

  /* UnaryMinus: '<S8>/Unary Minus1' */
  rtb_Product1_b = rtb_Switch_b0_idx_2;

  /* Product: '<Root>/Multiply4' incorporates:
   *  Product: '<S49>/Product'
   *  Product: '<S50>/Product'
   *  Product: '<S50>/Product1'
   *  Product: '<S51>/Product'
   *  Product: '<S51>/Product1'
   *  Product: '<S51>/Product2'
   *  Sum: '<S49>/Sum'
   *  Sum: '<S50>/Sum'
   *  Sum: '<S51>/Sum'
   *  UnaryMinus: '<S8>/Unary Minus'
   *  UnaryMinus: '<S8>/Unary Minus1'
   *  UnaryMinus: '<S8>/Unary Minus2'
   */
  rtb_Switch_b0_idx_1 = (((rtb_Switch_b0_idx_0 * 0.0 + -rtb_Switch_b0_idx_1) +
    rtb_Sum_b) - rtb_MathFunction_idx_1) * rtb_MathFunction_idx_0;
  rtb_Switch_b0_idx_2 = (((rtb_Switch_b0_idx_0 * 0.0 - -rtb_Product2_b * 0.0) +
    -rtb_Switch_b0_idx_2) + rtb_MathFunction_idx_1) * rtb_MathFunction_idx_0;
  rtb_Switch_b0_idx_3 = (((rtb_Switch_b0_idx_0 * 0.0 + -rtb_Product2_b * 0.0) -
    -rtb_Product1_b * 0.0) + -rtb_Switch_b0_idx_3) * rtb_MathFunction_idx_0;

  /* Gain: '<Root>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Product: '<Root>/Product'
   */
  rtb_Switch_b0_idx_0 = 33868.0 * rtDW.DiscreteTimeIntegrator_DSTATE[0] *
    9.5492965855137211;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Switch_b0_idx_0 > 6000.0) {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[0] = 6000.0;
  } else if (rtb_Switch_b0_idx_0 < -6000.0) {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[0] = -6000.0;
  } else {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[0] = rtb_Switch_b0_idx_0;
  }

  /* Gain: '<Root>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Product: '<Root>/Product'
   */
  rtb_Switch_b0_idx_0 = 33968.0 * rtDW.DiscreteTimeIntegrator_DSTATE[1] *
    9.5492965855137211;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Switch_b0_idx_0 > 6000.0) {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[1] = 6000.0;
  } else if (rtb_Switch_b0_idx_0 < -6000.0) {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[1] = -6000.0;
  } else {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[1] = rtb_Switch_b0_idx_0;
  }

  /* Gain: '<Root>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Product: '<Root>/Product'
   */
  rtb_Switch_b0_idx_0 = 33868.0 * rtDW.DiscreteTimeIntegrator_DSTATE[2] *
    9.5492965855137211;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Switch_b0_idx_0 > 6000.0) {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[2] = 6000.0;
  } else if (rtb_Switch_b0_idx_0 < -6000.0) {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[2] = -6000.0;
  } else {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[2] = rtb_Switch_b0_idx_0;
  }

  /* Gain: '<Root>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Product: '<Root>/Product'
   */
  rtb_Switch_b0_idx_0 = 33868.0 * rtDW.DiscreteTimeIntegrator_DSTATE[3] *
    9.5492965855137211;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Switch_b0_idx_0 > 6000.0) {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[3] = 6000.0;
  } else if (rtb_Switch_b0_idx_0 < -6000.0) {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[3] = -6000.0;
  } else {
    /* Outport: '<Root>/rpm' */
    rtY.rpm[3] = rtb_Switch_b0_idx_0;
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Kp'
   *  Gain: '<Root>/kd'
   *  Inport: '<Root>/gyro'
   *  S-Function (sdspperm2): '<Root>/Variable Selector1'
   */
  rtb_Switch_b0_idx_1 = 0.0023 * rtb_Switch_b0_idx_1 - 0.017453292519943295 *
    rtU.gyro[0] * 0.0104;
  rtb_Switch_b0_idx_2 = 0.0022 * rtb_Switch_b0_idx_2 - 0.017453292519943295 *
    rtU.gyro[1] * 0.0102;
  rtb_Switch_b0_idx_3 = 0.0012 * rtb_Switch_b0_idx_3 - 0.017453292519943295 *
    rtU.gyro[2] * 0.0053;
  for (i_0 = 0; i_0 < 4; i_0++) {
    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
     *  Constant: '<Root>/body2wheel'
     *  Product: '<Root>/Matrix Multiply'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE[i_0] += 0.25 *
      (rtConstP.body2wheel_Value[i_0 + 8] * rtb_Switch_b0_idx_3 +
       (rtConstP.body2wheel_Value[i_0 + 4] * rtb_Switch_b0_idx_2 +
        rtConstP.body2wheel_Value[i_0] * rtb_Switch_b0_idx_1));
  }
}

/* Model initialize function */
void FSW_0123_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[0] = 0.0031;

  /* SystemInitialize for Merge: '<S5>/Merge' */
  rtDW.Merge[0] = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[1] = -0.0031;

  /* SystemInitialize for Merge: '<S5>/Merge' */
  rtDW.Merge[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[2] = 0.0031;

  /* SystemInitialize for Merge: '<S5>/Merge' */
  rtDW.Merge[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[3] = -0.0031;

  /* SystemInitialize for Merge: '<S5>/Merge' */
  rtDW.Merge[3] = 0.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
