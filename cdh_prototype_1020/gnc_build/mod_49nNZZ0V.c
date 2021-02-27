/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mod_49nNZZ0V.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.319
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Feb 17 22:19:10 2021
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "mod_49nNZZ0V.h"

/* Function for MATLAB Function: '<S169>/MATLAB Function' */
real_T mod_49nNZZ0V(real_T x)
{
  real_T r;
  boolean_T rEQ0;
  real_T q;
  if ((!rtIsInf(x)) && (!rtIsNaN(x))) {
    if (x == 0.0) {
      r = 0.0;
    } else {
      r = fmod(x, 6.2831853071795862);
      rEQ0 = (r == 0.0);
      if (!rEQ0) {
        q = fabs(x / 6.2831853071795862);
        rEQ0 = (fabs(q - floor(q + 0.5)) <= 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        r = 0.0;
      } else {
        if (x < 0.0) {
          r += 6.2831853071795862;
        }
      }
    }
  } else {
    r = (rtNaN);
  }

  return r;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
