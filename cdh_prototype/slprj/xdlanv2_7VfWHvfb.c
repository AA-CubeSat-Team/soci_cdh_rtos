/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xdlanv2_7VfWHvfb.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun May  8 21:05:29 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_hypotd_snf.h"
#include "rt_nonfinite.h"
#include "xdlanv2_7VfWHvfb.h"

/* Function for MATLAB Function: '<S210>/INITIALIZE' */
void xdlanv2_7VfWHvfb(real_T *a, real_T *b, real_T *c, real_T *d, real_T *rt1r,
                      real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs,
                      real_T *sn)
{
  real_T bcmax;
  real_T bcmis;
  real_T p;
  real_T scale;
  real_T temp;
  real_T z;
  int32_T b_0;
  int32_T c_0;
  boolean_T tmp;
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    temp = *d;
    *d = *a;
    *a = temp;
    *b = -*c;
    *c = 0.0;
  } else {
    temp = *a - *d;
    if ((temp == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      p = 0.5 * temp;
      bcmis = fabs(*b);
      z = fabs(*c);
      tmp = rtIsNaN(z);
      if ((bcmis > z) || tmp) {
        bcmax = bcmis;
      } else {
        bcmax = z;
      }

      if ((bcmis < z) || tmp) {
        z = bcmis;
      }

      if (!(*b < 0.0)) {
        b_0 = 1;
      } else {
        b_0 = -1;
      }

      if (!(*c < 0.0)) {
        c_0 = 1;
      } else {
        c_0 = -1;
      }

      bcmis = z * (real_T)b_0 * (real_T)c_0;
      scale = fabs(p);
      if ((!(scale > bcmax)) && (!rtIsNaN(bcmax))) {
        scale = bcmax;
      }

      z = p / scale * p + bcmax / scale * bcmis;
      if (z >= 8.8817841970012523E-16) {
        if (!(p < 0.0)) {
          z = sqrt(scale) * sqrt(z);
        } else {
          z = -(sqrt(scale) * sqrt(z));
        }

        z += p;
        *a = *d + z;
        *d -= bcmax / z * bcmis;
        bcmax = rt_hypotd_snf(*c, z);
        *cs = z / bcmax;
        *sn = *c / bcmax;
        *b -= *c;
        *c = 0.0;
      } else {
        bcmis = *b + *c;
        bcmax = rt_hypotd_snf(bcmis, temp);
        *cs = sqrt((fabs(bcmis) / bcmax + 1.0) * 0.5);
        if (!(bcmis < 0.0)) {
          b_0 = 1;
        } else {
          b_0 = -1;
        }

        *sn = -(p / (bcmax * *cs)) * (real_T)b_0;
        temp = *a * *cs + *b * *sn;
        p = -*a * *sn + *b * *cs;
        bcmax = *c * *cs + *d * *sn;
        bcmis = -*c * *sn + *d * *cs;
        *b = p * *cs + bcmis * *sn;
        *c = -temp * *sn + bcmax * *cs;
        temp = ((temp * *cs + bcmax * *sn) + (-p * *sn + bcmis * *cs)) * 0.5;
        *a = temp;
        *d = temp;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              z = sqrt(fabs(*b));
              bcmis = sqrt(fabs(*c));
              p = z * bcmis;
              if (*c < 0.0) {
                p = -p;
              }

              bcmax = 1.0 / sqrt(fabs(*b + *c));
              *a = temp + p;
              *d = temp - p;
              *b -= *c;
              *c = 0.0;
              p = z * bcmax;
              bcmax *= bcmis;
              temp = *cs * p - *sn * bcmax;
              *sn = *cs * bcmax + *sn * p;
              *cs = temp;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            temp = *cs;
            *cs = -*sn;
            *sn = temp;
          }
        }
      }
    }
  }

  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = sqrt(fabs(*b)) * sqrt(fabs(*c));
    *rt2i = -*rt1i;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
