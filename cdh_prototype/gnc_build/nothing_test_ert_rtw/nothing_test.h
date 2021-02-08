/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: nothing_test.h
 *
 * Code generated for Simulink model 'nothing_test'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun May 10 16:06:22 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_nothing_test_h_
#define RTW_HEADER_nothing_test_h_

#ifndef nothing_test_COMMON_INCLUDES_
# define nothing_test_COMMON_INCLUDES_
#include <gnc_build/nothing_test_ert_rtw/rtwtypes.h>
#endif                                 /* nothing_test_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Model entry point functions */
extern void nothing_test_initialize(void);
extern void nothing_test_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Digital Clock' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<Root>/Product' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'nothing_test'
 */
#endif                                 /* RTW_HEADER_nothing_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
