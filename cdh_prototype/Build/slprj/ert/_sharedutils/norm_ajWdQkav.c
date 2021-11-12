/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: norm_ajWdQkav.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Oct 25 17:45:01 2021
 */

#include "rtwtypes.h"
#include <math.h>
#include "norm_ajWdQkav.h"

/* Function for MATLAB Function: '<S438>/SOLVE' */
real_T norm_ajWdQkav(const real_T x[100])
{
  real_T y;
  int32_T k;
  y = 0.0;
  for (k = 0; k < 100; k++) {
    y += fabs(x[k]);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */