/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib_data.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 5.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May 24 14:44:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Debugging
 *    2. Execution efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/* Invariant block signals (default storage) */
const ConstB rtConstB = {
  1.0,                                 /* '<S89>/Switch' */

  { 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0,
    0.0, 0.0, 0.0, 2.9526E-5 },        /* '<S109>/Create Diagonal Matrix' */

  { -0.00011384640139575119, 0.00011384640139575162, -4.832493030858644E-5 },/* '<S109>/Matrix Multiply4' */

  { 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0,
    0.0, 0.0, 0.0, 2.9526E-5 },        /* '<S101>/Create Diagonal Matrix' */

  { -0.00011384640139575119, 0.00011384640139575162, -4.832493030858644E-5 },/* '<S101>/Matrix Multiply4' */

  /* Start of '<S1>/mode_select_lib' */
  {
    { 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5,
      0.0, 0.0, 0.0, 0.0, 2.9526E-5 }  /* '<S143>/Create Diagonal Matrix' */
  }
  ,

  /* End of '<S1>/mode_select_lib' */

  /* Start of '<S6>/rwa_allocation_lib' */
  {
    1                                  /* '<S91>/Logical Operator' */
  }
  /* End of '<S6>/rwa_allocation_lib' */
};

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Pooled Parameter (Expression: fswParams.allocator)
   * Referenced by:
   *   '<S133>/Constant'
   *   '<S137>/Constant1'
   */
  {
    { 0.92050485345244037, 0.0, 0.39073112848927377, 0.0, 0.92050485345244037,
      0.39073112848927377, -0.92050485345244037, 0.0, 0.39073112848927377, 0.0,
      -0.92050485345244037, 0.39073112848927377 },

    { 2.9526e-5, 2.9526e-5, 2.9526e-5, 2.9526e-5 },

    { 33868.4549210865, 33868.4549210865, 33868.4549210865, 33868.4549210865 },
    0.0032,
    6500.0,
    6U,

    { 0.0029991968249731822, -0.0030610359347664436, 0.0031228750445597051,
      -0.003184714154352967 },
    0.01,

    { 1.0, -1.0, 1.0, -1.0 },

    { 0.00294561553104781, 0.00214403277419873 },

    { 3U, 2U, 2U, 1U, 1U, 1U, 4U, 4U, 3U, 4U, 3U, 2U },

    { 1U, 1U, 1U, 2U, 2U, 3U, 2U, 3U, 4U, 3U, 4U, 4U },

    { 0.27159009435132403, 0.27159009435132403, 0.63982616631186306,
      0.54318018870264806, 0.0, -0.0, 0.27159009435132403, -0.27159009435132403,
      0.63982616631186306, 0.27159009435132403, -0.27159009435132403,
      -0.63982616631186306, 0.0, -0.54318018870264806, 0.0, -0.27159009435132403,
      -0.27159009435132403, 0.63982616631186306 },

    { -0.47020150830868962, 0.0, -0.47020150830868962, 0.47020150830868962, 0.0,
      -0.47020150830868962 },

    { 1.0238646233366748, 1.9325548097883873, 1.0238646233366748,
      1.0238646233366748, 1.9325548097883873, 1.0238646233366748 }
  },

  /* Pooled Parameter (Expression: -eye(3))
   * Referenced by:
   *   '<S77>/Bias1'
   *   '<S196>/Bias1'
   */
  { -1.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -1.0 },

  /* Expression: fswParams.controllers.asmc.C
   * Referenced by: '<S98>/Constant'
   */
  { -0.0041792285888789622, -0.00015263156770876305, 2.583106149731759E-6,
    -0.00015263156770876305, -0.0041140715087521276, 3.2852863977656267E-5,
    2.583106149731759E-6, 3.2852863977656267E-5, -0.0021335477849165076 },

  /* Pooled Parameter (Expression: fswParams.allocator.A_wheel2body)
   * Referenced by:
   *   '<S143>/A_wheel2body '
   *   '<S135>/Constant'
   *   '<S101>/A_wheel2body '
   *   '<S109>/A_wheel2body '
   */
  { 0.92050485345244037, 0.0, 0.39073112848927377, 0.0, 0.92050485345244037,
    0.39073112848927377, -0.92050485345244037, 0.0, 0.39073112848927377, 0.0,
    -0.92050485345244037, 0.39073112848927377 },

  /* Pooled Parameter (Expression: fswParams.scParams.J)
   * Referenced by:
   *   '<S143>/scParams.J '
   *   '<S101>/scParams.J '
   *   '<S109>/scParams.J '
   */
  { 0.0118206435013, 0.00043170726620000006, -7.3061275000000005E-6,
    0.00043170726620000006, 0.0116363514485, -9.29219316E-5,
    -7.3061275000000005E-6, -9.29219316E-5, 0.0060345844268 },

  /* Pooled Parameter (Expression: fswParams.desatcontrollerParams.gain)
   * Referenced by:
   *   '<S103>/Gain3'
   *   '<S111>/Gain3'
   */
  { 0.002, 0.0, 0.0, 0.0, 0.002, 0.0, 0.0, 0.0, 0.002 },

  /* Expression: fswParams.controllers.sunseek.Kd
   * Referenced by: '<S116>/Kd'
   */
  { 0.002127715830234, 7.7707307916000023E-5, -1.3151029500000002E-6,
    7.7707307916000023E-5, 0.0020945432607300004, -1.6725947688E-5,
    -1.3151029500000002E-6, -1.6725947688E-5, 0.0010862251968240001 },

  /* Expression: fswParams.controllers.sunseek.Kp
   * Referenced by: '<S116>/Kp'
   */
  { 0.00011820643501300003, 4.3170726620000016E-6, -7.3061275000000013E-8,
    4.3170726620000016E-6, 0.00011636351448500002, -9.2921931600000012E-7,
    -7.3061275000000013E-8, -9.2921931600000012E-7, 6.0345844268000013E-5 },

  /* Expression: pinv
   * Referenced by: '<S134>/Constant'
   */
  { 0.54318018870264806, 0.0, -0.54318018870264806, 0.0, 0.0,
    0.54318018870264806, 0.0, -0.54318018870264806, 0.639826166311863,
    0.639826166311863, 0.63982616631186306, 0.63982616631186306 },

  /* Expression: simParams.sensors.sun_sensor.ss2body
   * Referenced by: '<S152>/Constant1'
   */
  { -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S153>/Constant13'
   *   '<S153>/Constant20'
   *   '<S153>/Constant22'
   */
  { 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: fswParams.sensors.mag_rotate(:,:,1)
   * Referenced by: '<S154>/Constant13'
   */
  { 0.0, 1.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: fswParams.sensors.mag_rotate(:,:,2)
   * Referenced by: '<S154>/Constant20'
   */
  { 0.70710678118654757, 0.70710678118654757, 0.0, -0.70710678118654757,
    0.70710678118654757, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: fswParams.sensors.mag_rotate(:,:,3)
   * Referenced by: '<S154>/Constant22'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: [true;true;true;true]
   * Referenced by: '<S1>/Constant20'
   */
  { 1, 1, 1, 1 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
