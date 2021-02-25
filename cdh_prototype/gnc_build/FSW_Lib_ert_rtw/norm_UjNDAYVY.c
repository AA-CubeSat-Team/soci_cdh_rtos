/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: norm_UjNDAYVY.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:19:10 2021
 */

#include "rtwtypes.h"
#include <math.h>
#include "norm_UjNDAYVY.h"

/* Function for MATLAB Function: '<S317>/SOLVE' */
real_T norm_UjNDAYVY(const real_T x[99])
{
  real_T y;
  int32_T k;
  y = 0.0;
  for (k = 0; k < 99; k++) {
    y += fabs(x[k]);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
