/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib_data.c
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

#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>
#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_private.h>

/* Invariant block signals (default storage) */
const ConstB rtConstB = {
  6.3567523142451793E+6,               /* '<S292>/Product1' */
  0.0067394967422764488,               /* '<S310>/Product2' */
  6.3567523142451793E+6,               /* '<S181>/Product1' */
  0.0067394967422764488,               /* '<S191>/Product2' */
  6.3567523142451793E+6,               /* '<S237>/Product1' */
  0.0067394967422764488                /* '<S244>/Product2' */
};

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Pooled Parameter (Expression: fswParams.allocator.rwa)
   * Referenced by:
   *   '<S166>/Constant'
   *   '<S167>/Constant'
   */
  {
    { 0.92050485345244037, 0.0, 0.39073112848927377, 0.0, 0.92050485345244037,
      0.39073112848927377, -0.92050485345244037, 0.0, 0.39073112848927377, 0.0,
      -0.92050485345244037, 0.39073112848927377 },

    { 28813.0, 28813.0, 79957.0 },
    6U,

    { 0.0030919554896630744, -0.0030919554896630744, 0.0030919554896630744,
      -0.0030919554896630744 },
    0.01,

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
   *   '<S363>/Bias1'
   *   '<S96>/Bias1'
   */
  { -1.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -1.0 },

  /* Expression: fswParams.estimation.Rchol
   * Referenced by: '<S16>/Constant'
   */
  { 0.0016794438557724239, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0016794438557724239,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0016794438557724239, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 4.0305E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.41E-7, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.7321E-7 },

  /* Expression: fswParams.estimation.ic.Pchol_init
   * Referenced by: '<S3>/Unit Delay'
   */
  { 3.1622776601683795E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.1622776601683795E-5,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.1622776601683795E-5, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 3.1622776601683795E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    3.1622776601683795E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.1622776601683795E-5 },

  /* Expression: fswParams.estimation.Qchol
   * Referenced by: '<S18>/Constant13'
   */
  { 1.0000099999500005E-6, 0.0, 0.0, 2.9999700004499927E-10, 0.0, 0.0, 0.0,
    1.0000099999500005E-6, 0.0, 0.0, 2.9999700004499927E-10, 0.0, 0.0, 0.0,
    1.0000099999500005E-6, 0.0, 0.0, 2.9999700004499927E-10, 0.0, 0.0, 0.0,
    7.7459085986086637E-8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.7459085986086637E-8,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.7459085986086637E-8 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S50>/Rate Transition'
   *   '<S121>/Memory1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: fswParams.controllers.reorientation.J
   * Referenced by: '<S124>/Constant'
   */
  { 0.0118206435013, 0.00043170726620000006, -7.3061275000000005E-6,
    0.00043170726620000006, 0.0116363514485, -9.29219316E-5,
    -7.3061275000000005E-6, -9.29219316E-5, 0.0060345844268 },

  /* Pooled Parameter (Expression: fswParams.controllers.reorientation.T)
   * Referenced by:
   *   '<S122>/Constant1'
   *   '<S138>/Constant1'
   */
  { 446.42857142857144, 0.0, 0.0, 0.0, 0.0, 446.42857142857144, 0.0, 0.0, 0.0,
    0.0, 446.42857142857144, 0.0, 0.0, 0.0, 0.0, 446.42857142857144 },

  /* Pooled Parameter (Expression: fswParams.controllers.reorientation.Phi)
   * Referenced by:
   *   '<S122>/Constant'
   *   '<S138>/Constant'
   */
  { 0.54318018870264806, 0.0, -0.54318018870264806, 0.0, 0.0,
    0.54318018870264806, 0.0, -0.54318018870264806, 0.639826166311863,
    0.639826166311863, 0.63982616631186306, 0.63982616631186306 },

  /* Expression: fswParams.controllers.reorientation.P
   * Referenced by: '<S120>/Constant1'
   */
  { 20.074791027802114, 0.74477237925517437, -0.00929401890684035,
    0.73316085991389812, 20.074791027802114, -0.11820464249365011,
    -0.012407867876977091, -0.1603069799864271, 7.6765073915837805 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S120>/Constant'
   *   '<S134>/kd'
   *   '<S137>/Constant'
   */
  { 0.0083584571777579244, 0.0003052631354175261, -5.166212299463518E-6,
    0.0003052631354175261, 0.0082281430175042553, -6.5705727955312534E-5,
    -5.166212299463518E-6, -6.5705727955312534E-5, 0.0042670955698330152 },

  /* Expression: fswParams.controllers.tracking.Kp1
   * Referenced by: '<S134>/Kp'
   */
  { 0.002955160875325, 0.00010792681655000002, -1.8265318750000001E-6,
    0.00010792681655000002, 0.002909087862125, -2.32304829E-5,
    -1.8265318750000001E-6, -2.32304829E-5, 0.0015086461067 },

  /* Expression: fswParams.controllers.desaturation.T
   * Referenced by: '<S147>/Constant1'
   */
  { 19.417475728155342, 0.0, 0.0, 0.0, 0.0, 0.0, 19.417475728155342, 0.0, 0.0,
    0.0, 0.0, 0.0, 19.417475728155342, 0.0, 0.0, 0.0, 0.0, 0.0,
    19.417475728155342, 0.0, 0.0, 0.0, 0.0, 0.0, 9.7087378640776709 },

  /* Pooled Parameter (Expression: fswParams.rwa.inertia)
   * Referenced by:
   *   '<S107>/Constant'
   *   '<S164>/wheel_inertia_kgm2'
   *   '<S145>/rwa_inertia_matrix'
   */
  { 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0,
    0.0, 0.0, 0.0, 2.9526E-5 },

  /* Pooled Parameter (Expression: fswParams.allocator.MTQ_B_inv)
   * Referenced by:
   *   '<S5>/Constant3'
   *   '<S147>/Constant'
   */
  { 0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0
  },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S107>/Constant1'
   *   '<S157>/Discrete-Time Integrator'
   *   '<S164>/h_wheel_targ_Nms'
   *   '<S145>/wheel_momentum_target'
   */
  { 0.0030919554896630744, -0.0030919554896630744, 0.0030919554896630744,
    -0.0030919554896630744 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S5>/Constant'
   *   '<S165>/Constant'
   */
  { 0.92050485345244037, 0.0, 0.39073112848927377, 0.0, 0.92050485345244037,
    0.39073112848927377, -0.92050485345244037, 0.0, 0.39073112848927377, 0.0,
    -0.92050485345244037, 0.39073112848927377 },

  /* Expression: fswParams.rwa.inv_inertia
   * Referenced by: '<S157>/Constant'
   */
  { 33868.4549210865, 0.0, 0.0, 0.0, 0.0, 33868.4549210865, 0.0, 0.0, 0.0, 0.0,
    33868.4549210865, 0.0, 0.0, 0.0, 0.0, 33868.4549210865 },

  /* Expression: fswParams.allocator.MTQ_B
   * Referenced by: '<S5>/Constant2'
   */
  { 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0
  },

  /* Expression: simParams.sensors.sun_sensor.ss2body
   * Referenced by: '<S11>/Constant1'
   */
  { -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
