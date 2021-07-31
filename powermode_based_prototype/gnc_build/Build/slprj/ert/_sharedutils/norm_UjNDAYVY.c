/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: norm_UjNDAYVY.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
 */

#include "rtwtypes.h"
#include <math.h>
#include "norm_UjNDAYVY.h"

/* Function for MATLAB Function: '<S412>/SOLVE' */
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
