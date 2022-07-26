/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: jseconds2ymdhms_eXoGXxIT.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun May  8 21:05:29 2022
 */

#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "jseconds2ymdhms_eXoGXxIT.h"

/* Function for MATLAB Function: '<S4>/MATLAB Function3' */
void jseconds2ymdhms_eXoGXxIT(real_T time_s_J2000, real_T *Year, real_T *Month,
  real_T *Day, real_T *Hour, real_T *Min, real_T *Sec, real_T *JC_J2000, real_T *
  JD)
{
  static const int8_T b[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  real_T Days;
  real_T sum;
  int32_T i;
  int8_T LMonth[12];
  for (i = 0; i < 12; i++) {
    LMonth[i] = b[i];
  }

  *JD = time_s_J2000 / 86400.0 + 2.451545E+6;
  *JC_J2000 = (*JD - 2.451545E+6) / 36525.0;
  sum = floor((*JD - 2.4150195E+6) / 365.25);
  *Year = sum + 1900.0;
  Days = (*JD - 2.4150195E+6) - (floor((((sum + 1900.0) - 1900.0) - 1.0) * 0.25)
    + ((sum + 1900.0) - 1900.0) * 365.0);
  if (Days < 1.0) {
    *Year = (sum + 1900.0) - 1.0;
    Days = (*JD - 2.4150195E+6) - (floor(((((sum + 1900.0) - 1.0) - 1900.0) -
      1.0) * 0.25) + (((sum + 1900.0) - 1.0) - 1900.0) * 365.0);
  }

  if (rtIsNaN(*Year)) {
    sum = (rtNaN);
  } else if (rtIsInf(*Year)) {
    sum = (rtNaN);
  } else if (*Year == 0.0) {
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

  if (sum == 0.0) {
    LMonth[1] = 29;
  }

  *Day = floor(Days);
  sum = 0.0;
  *Month = 0.0;
  while (sum < *Day) {
    (*Month)++;
    sum += (real_T)LMonth[(int32_T)*Month - 1];
  }

  Days = (Days - *Day) * 24.0;
  *Hour = floor(Days);
  Days -= *Hour;
  *Min = floor(Days * 60.0);
  *Sec = (Days - *Min / 60.0) * 3600.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
