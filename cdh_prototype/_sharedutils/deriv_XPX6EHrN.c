/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: deriv_XPX6EHrN.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Mar 29 09:22:04 2022
 */

#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>
#include "bsearch_qRItHZGW.h"
#include "mldivide_NEqYeqp4.h"
#include "deriv_XPX6EHrN.h"

/* Function for MATLAB Function: '<S385>/soar_INTERP' */
void deriv_XPX6EHrN(real_T t, const real_T x[10], const real_T u[30], const
                    real_T ut[10], const real_T J[9], real_T dx[10])
{
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T varargin_2[30];
  real_T tmp_0[12];
  real_T b_x[10];
  real_T tmp[9];
  real_T q[4];
  real_T J_0[3];
  real_T u_t[3];
  real_T u_t_0[3];
  real_T absxk;
  real_T b_t;
  real_T mag;
  real_T scale;
  int32_T c_k;
  int32_T exitg1;
  int32_T mag_tmp;
  int32_T n;
  int32_T offset;
  int32_T varargin_2_tmp;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    mag = 1.0;
    scale = absxk;
  } else {
    b_t = absxk / 3.3121686421112381E-170;
    mag = b_t * b_t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    b_t = scale / absxk;
    mag = mag * b_t * b_t + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    mag += b_t * b_t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    b_t = scale / absxk;
    mag = mag * b_t * b_t + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    mag += b_t * b_t;
  }

  absxk = fabs(x[3]);
  if (absxk > scale) {
    b_t = scale / absxk;
    mag = mag * b_t * b_t + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    mag += b_t * b_t;
  }

  mag = scale * sqrt(mag);
  if (mag < 1.0E-5) {
    memset(&dx[0], 0, 10U * sizeof(real_T));
  } else {
    q[0] = x[0] / mag;
    q[1] = x[1] / mag;
    q[2] = x[2] / mag;
    q[3] = x[3] / mag;
    if (t > ut[9]) {
      u_t[0] = 0.0;
      u_t[1] = 0.0;
      u_t[2] = 0.0;
    } else if (t < ut[0]) {
      u_t[0] = 0.0;
      u_t[1] = 0.0;
      u_t[2] = 0.0;
    } else {
      for (n = 0; n < 3; n++) {
        for (offset = 0; offset < 10; offset++) {
          varargin_2[offset + 10 * n] = u[3 * offset + n];
        }
      }

      memcpy(&b_x[0], &ut[0], 10U * sizeof(real_T));
      u_t[0] = (rtNaN);
      u_t[1] = (rtNaN);
      u_t[2] = (rtNaN);
      n = 0;
      do {
        exitg1 = 0;
        if (n < 10) {
          if (rtIsNaN(ut[n])) {
            exitg1 = 1;
          } else {
            n++;
          }
        } else {
          if (ut[1] < ut[0]) {
            for (n = 0; n < 5; n++) {
              mag = b_x[n];
              b_x[n] = b_x[9 - n];
              b_x[9 - n] = mag;
            }

            for (n = 0; n < 3; n++) {
              offset = n * 10;
              for (c_k = 0; c_k < 5; c_k++) {
                mag_tmp = offset + c_k;
                mag = varargin_2[mag_tmp];
                varargin_2_tmp = (offset - c_k) + 9;
                varargin_2[mag_tmp] = varargin_2[varargin_2_tmp];
                varargin_2[varargin_2_tmp] = mag;
              }
            }
          }

          if (rtIsNaN(t)) {
            u_t[0] = (rtNaN);
            u_t[1] = (rtNaN);
            u_t[2] = (rtNaN);
          } else {
            if ((!(t > b_x[9])) && (!(t < b_x[0]))) {
              n = bsearch_qRItHZGW(b_x, t);
              scale = b_x[n - 1];
              mag = (t - scale) / (b_x[n] - scale);
              if (mag == 0.0) {
                u_t[0] = varargin_2[n - 1];
                u_t[1] = varargin_2[n + 9];
                u_t[2] = varargin_2[n + 19];
              } else if (mag == 1.0) {
                u_t[0] = varargin_2[n];
                u_t[1] = varargin_2[n + 10];
                u_t[2] = varargin_2[n + 20];
              } else {
                scale = varargin_2[n - 1];
                absxk = varargin_2[n];
                if (scale == absxk) {
                  u_t[0] = scale;
                } else {
                  u_t[0] = (1.0 - mag) * scale + mag * absxk;
                }

                scale = varargin_2[n + 9];
                absxk = varargin_2[n + 10];
                if (scale == absxk) {
                  u_t[1] = scale;
                } else {
                  u_t[1] = (1.0 - mag) * scale + mag * absxk;
                }

                scale = varargin_2[n + 19];
                absxk = varargin_2[n + 20];
                if (scale == absxk) {
                  u_t[2] = scale;
                } else {
                  u_t[2] = (1.0 - mag) * scale + mag * absxk;
                }
              }
            }
          }

          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    tmp[0] = 0.0;
    tmp[3] = -x[6];
    tmp[6] = x[5];
    tmp[1] = x[6];
    tmp[4] = 0.0;
    tmp[7] = -x[4];
    tmp[2] = -x[5];
    tmp[5] = x[4];
    tmp[8] = 0.0;
    for (n = 0; n < 3; n++) {
      J_0[n] = ((J[n + 3] * x[5] + J[n] * x[4]) + J[n + 6] * x[6]) + x[n + 7];
    }

    for (n = 0; n < 3; n++) {
      u_t_0[n] = -u_t[n] - ((tmp[n + 3] * J_0[1] + tmp[n] * J_0[0]) + tmp[n + 6]
                            * J_0[2]);
    }

    mldivide_NEqYeqp4(J, u_t_0, J_0);
    scale = q[0];
    tmp[0] = 0.0;
    tmp[3] = -q[3];
    tmp[6] = q[2];
    tmp[1] = q[3];
    tmp[4] = 0.0;
    tmp[7] = -q[1];
    tmp[2] = -q[2];
    tmp[5] = q[1];
    tmp[8] = 0.0;
    for (n = 0; n < 3; n++) {
      offset = n << 2;
      tmp_0[offset] = -q[n + 1] * 0.5;
      tmp_0[offset + 1] = ((real_T)b[3 * n] * scale + tmp[3 * n]) * 0.5;
      c_k = 3 * n + 1;
      tmp_0[offset + 2] = ((real_T)b[c_k] * scale + tmp[c_k]) * 0.5;
      c_k = 3 * n + 2;
      tmp_0[offset + 3] = ((real_T)b[c_k] * scale + tmp[c_k]) * 0.5;
    }

    for (n = 0; n < 4; n++) {
      dx[n] = tmp_0[n + 8] * x[6] + (tmp_0[n + 4] * x[5] + tmp_0[n] * x[4]);
    }

    dx[4] = J_0[0];
    dx[7] = u_t[0];
    dx[5] = J_0[1];
    dx[8] = u_t[1];
    dx[6] = J_0[2];
    dx[9] = u_t[2];
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
