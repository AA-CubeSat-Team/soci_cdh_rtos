/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib0_data.c
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

#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/* Invariant block signals (default storage) */
const ConstB rtConstB = {
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },/* '<S250>/Identity Matrix' */

  { 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0,
    0.0, 0.0, 0.0, 2.9526E-5 },        /* '<S249>/Create Diagonal Matrix' */

  { -0.00011384640139575119, 0.00011384640139575162, -4.832493030858644E-5 },/* '<S249>/Matrix Multiply4' */

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },/* '<S242>/Identity Matrix' */

  { 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0,
    0.0, 0.0, 0.0, 2.9526E-5 },        /* '<S241>/Create Diagonal Matrix' */

  { -0.00011384640139575119, 0.00011384640139575162, -4.832493030858644E-5 },/* '<S241>/Matrix Multiply4' */

  /* Start of '<S1>/mode_select_lib' */
  {
    { 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5,
      0.0, 0.0, 0.0, 0.0, 2.9526E-5 }  /* '<S287>/Create Diagonal Matrix' */
  }
  ,

  /* End of '<S1>/mode_select_lib' */

  /* Start of '<S1>/MEKF_lib' */
  {
    { 0.5, 0.0, -0.70710678108654745, 0.5, 0.70710678108654745,
      0.35355339054327373, 0.5, -0.70710678108654745, 0.35355339054327373 },/* '<S176>/Math Function1' */

    /* Start of '<S124>/parallel_protection_lib1' */
    {
      0.57735026918962584              /* '<S179>/Abs' */
    }
    /* End of '<S124>/parallel_protection_lib1' */
  }
  /* End of '<S1>/MEKF_lib' */
};

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Expression: fswParams.allocator
   * Referenced by: '<S277>/Constant'
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
  }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
