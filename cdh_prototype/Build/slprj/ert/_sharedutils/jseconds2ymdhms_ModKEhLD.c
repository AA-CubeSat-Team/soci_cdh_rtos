/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: jseconds2ymdhms_ModKEhLD.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Oct 25 17:45:01 2021
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "jseconds2ymdhms_ModKEhLD.h"

/* Function for MATLAB Function: '<S292>/MATLAB Function3' */
void jseconds2ymdhms_ModKEhLD(real_T time_s_J2000, real_T *Year, real_T *Month,
  real_T *Day, real_T *Hour, real_T *Min, real_T *Sec, real_T *JC_J2000, real_T *
  JD)
{
  int8_T LMonth[12];
  real_T T_1900;
  real_T sum;
  static const int8_T b[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  int32_T i;
  for (i = 0; i < 12; i++) {
    LMonth[i] = b[i];
  }

  *JD = time_s_J2000 / 86400.0 + 2.451545E+6;
  *JC_J2000 = (*JD - 2.451545E+6) / 36525.0;
  sum = floor((*JD - 2.4150195E+6) / 365.25);
  *Year = 1900.0 + sum;
  T_1900 = (*JD - 2.4150195E+6) - (floor((((1900.0 + sum) - 1900.0) - 1.0) *
    0.25) + ((1900.0 + sum) - 1900.0) * 365.0);
  if (T_1900 < 1.0) {
    *Year = (1900.0 + sum) - 1.0;
    T_1900 = (*JD - 2.4150195E+6) - (floor(((((1900.0 + sum) - 1.0) - 1900.0) -
      1.0) * 0.25) + (((1900.0 + sum) - 1.0) - 1900.0) * 365.0);
  }

  if ((!rtIsInf(*Year)) && (!rtIsNaN(*Year))) {
    if (*Year == 0.0) {
      sum = 0.0;
    } else {
      sum = fmod(*Year, 4.0);
      if (sum == 0.0) {
        sum = 0.0;
      } else {
        if (*Year < 0.0) {
          sum += 4.0;
        }
      }
    }
  } else {
    sum = (rtNaN);
  }

  if (sum == 0.0) {
    LMonth[1] = 29;
  }

  *Day = floor(T_1900);
  sum = 0.0;
  *Month = 0.0;
  while (sum < *Day) {
    (*Month)++;
    sum += (real_T)LMonth[(int32_T)*Month - 1];
  }

  T_1900 = (T_1900 - *Day) * 24.0;
  *Hour = floor(T_1900);
  T_1900 -= *Hour;
  *Min = floor(T_1900 * 60.0);
  *Sec = (T_1900 - *Min / 60.0) * 3600.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
