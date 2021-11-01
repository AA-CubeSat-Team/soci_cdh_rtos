/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib_data.c
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

#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/* Invariant block signals (default storage) */
const ConstB rtConstB = {
  1.0,                                 /* '<S230>/Switch' */

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },/* '<S251>/Identity Matrix' */

  { 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0,
    0.0, 0.0, 0.0, 2.9526E-5 },        /* '<S250>/Create Diagonal Matrix' */

  { -0.00011384640139575119, 0.00011384640139575162, -4.832493030858644E-5 },/* '<S250>/Matrix Multiply4' */

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },/* '<S243>/Identity Matrix' */

  { 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0,
    0.0, 0.0, 0.0, 2.9526E-5 },        /* '<S242>/Create Diagonal Matrix' */

  { -0.00011384640139575119, 0.00011384640139575162, -4.832493030858644E-5 },/* '<S242>/Matrix Multiply4' */

  /* Start of '<S1>/mode_select_lib' */
  {
    { 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5, 0.0, 0.0, 0.0, 0.0, 2.9526E-5,
      0.0, 0.0, 0.0, 0.0, 2.9526E-5 }  /* '<S382>/Create Diagonal Matrix' */
  }
  ,

  /* End of '<S1>/mode_select_lib' */

  /* Start of '<S288>/target_groundpass_lib' */
  {
    { -0.39497937598550986, 0.845231988038406, -0.35996413563401142,
      -0.624718338364105, -0.53439955688290364, -0.56933655364375457,
      -0.67358614167579844, 0.0, 0.73910872660408433 }/* '<S341>/Vector Concatenate' */
  }
  /* End of '<S288>/target_groundpass_lib' */
};

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Expression: fswParams.allocator
   * Referenced by: '<S278>/Constant'
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
