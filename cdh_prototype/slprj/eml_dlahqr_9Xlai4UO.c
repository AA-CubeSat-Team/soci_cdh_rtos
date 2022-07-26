/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: eml_dlahqr_9Xlai4UO.c
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun May  8 21:05:29 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "xdlanv2_7VfWHvfb.h"
#include "xrot_GqxWzXOv.h"
#include "xrot_MOZ0Ssgv.h"
#include "xrot_w5C6g5Fw.h"
#include "xzlarfg_OnHd8y0N.h"
#include "eml_dlahqr_9Xlai4UO.h"

/* Function for MATLAB Function: '<S210>/INITIALIZE' */
int32_T eml_dlahqr_9Xlai4UO(real_T h[16], real_T z[16])
{
  real_T b_v[3];
  real_T v[3];
  real_T aa;
  real_T ab;
  real_T ba;
  real_T cs;
  real_T h12;
  real_T htmp2;
  real_T htmp2_tmp;
  real_T htmp2_tmp_tmp;
  real_T sn;
  real_T tst;
  int32_T L;
  int32_T b_k;
  int32_T h12_tmp;
  int32_T h12_tmp_0;
  int32_T hoffset;
  int32_T i;
  int32_T info;
  int32_T its;
  int32_T j;
  int32_T k;
  int32_T m;
  int32_T nr;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T goto150;
  info = 0;
  v[0] = 0.0;
  v[1] = 0.0;
  v[2] = 0.0;
  h[2] = 0.0;
  h[3] = 0.0;
  h[7] = 0.0;
  i = 3;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    L = 1;
    goto150 = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      k = i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > L)) {
        nr = ((k - 1) << 2) + k;
        htmp2 = fabs(h[nr]);
        if (htmp2 <= 4.0083367200179456E-292) {
          exitg3 = true;
        } else {
          m = (k << 2) + k;
          tst = fabs(h[nr - 1]) + fabs(h[m]);
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = fabs(h[(((k - 2) << 2) + k) - 1]);
            }

            if (k + 2 <= 4) {
              tst += fabs(h[((k << 2) + k) + 1]);
            }
          }

          if (htmp2 <= 2.2204460492503131E-16 * tst) {
            tst = fabs(h[nr]);
            htmp2 = fabs(h[m - 1]);
            if (tst > htmp2) {
              ab = tst;
              ba = htmp2;
            } else {
              ab = htmp2;
              ba = tst;
            }

            htmp2 = h[m];
            tst = fabs(htmp2);
            htmp2 = fabs(h[nr - 1] - htmp2);
            if (tst > htmp2) {
              aa = tst;
              tst = htmp2;
            } else {
              aa = htmp2;
            }

            htmp2 = aa + ab;
            tst = aa / htmp2 * tst * 2.2204460492503131E-16;
            if ((4.0083367200179456E-292 > tst) || rtIsNaN(tst)) {
              tst = 4.0083367200179456E-292;
            }

            if (ab / htmp2 * ba <= tst) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }

      L = k + 1;
      if (k + 1 > 1) {
        h[k + ((k - 1) << 2)] = 0.0;
      }

      if (k + 1 >= i) {
        goto150 = true;
        exitg2 = true;
      } else {
        switch (its) {
         case 10:
          nr = (k << 2) + k;
          htmp2 = fabs(h[(((k + 1) << 2) + k) + 2]) + fabs(h[nr + 1]);
          ba = h[nr] + 0.75 * htmp2;
          h12 = -0.4375 * htmp2;
          aa = htmp2;
          tst = ba;
          break;

         case 20:
          htmp2 = fabs(h[(((i - 2) << 2) + i) - 1]) + fabs(h[((i - 1) << 2) + i]);
          ba = h[(i << 2) + i] + 0.75 * htmp2;
          h12 = -0.4375 * htmp2;
          aa = htmp2;
          tst = ba;
          break;

         default:
          ba = h[(((i - 1) << 2) + i) - 1];
          aa = h[((i - 1) << 2) + i];
          h12 = h[((i << 2) + i) - 1];
          tst = h[(i << 2) + i];
          break;
        }

        htmp2 = ((fabs(ba) + fabs(h12)) + fabs(aa)) + fabs(tst);
        if (htmp2 == 0.0) {
          ba = 0.0;
          tst = 0.0;
          ab = 0.0;
          aa = 0.0;
        } else {
          ba /= htmp2;
          aa /= htmp2;
          h12 /= htmp2;
          tst /= htmp2;
          ab = (ba + tst) / 2.0;
          ba = (ba - ab) * (tst - ab) - h12 * aa;
          aa = sqrt(fabs(ba));
          if (ba >= 0.0) {
            ba = ab * htmp2;
            ab = ba;
            tst = aa * htmp2;
            aa = -tst;
          } else {
            ba = ab + aa;
            ab -= aa;
            if (fabs(ba - tst) <= fabs(ab - tst)) {
              ba *= htmp2;
              ab = ba;
            } else {
              ab *= htmp2;
              ba = ab;
            }

            tst = 0.0;
            aa = 0.0;
          }
        }

        m = i - 1;
        exitg3 = false;
        while ((!exitg3) && (m >= k + 1)) {
          nr = ((m - 1) << 2) + m;
          h12 = h[nr];
          htmp2_tmp_tmp = h[nr - 1];
          htmp2_tmp = htmp2_tmp_tmp - ab;
          htmp2 = (fabs(htmp2_tmp) + fabs(aa)) + fabs(h12);
          h12 /= htmp2;
          nr = (m << 2) + m;
          v[0] = (htmp2_tmp / htmp2 * (htmp2_tmp_tmp - ba) + h[nr - 1] * h12) -
            aa / htmp2 * tst;
          htmp2_tmp = h[nr];
          v[1] = (((htmp2_tmp_tmp + htmp2_tmp) - ba) - ab) * h12;
          v[2] = h[nr + 1] * h12;
          htmp2 = (fabs(v[0]) + fabs(v[1])) + fabs(v[2]);
          v[0] /= htmp2;
          v[1] /= htmp2;
          v[2] /= htmp2;
          if (k + 1 == m) {
            exitg3 = true;
          } else {
            hoffset = ((m - 2) << 2) + m;
            if (fabs(h[hoffset - 1]) * (fabs(v[1]) + fabs(v[2])) <= ((fabs
                  (h[hoffset - 2]) + fabs(htmp2_tmp_tmp)) + fabs(htmp2_tmp)) *
                (2.2204460492503131E-16 * fabs(v[0]))) {
              exitg3 = true;
            } else {
              m--;
            }
          }
        }

        for (b_k = m; b_k <= i; b_k++) {
          nr = (i - b_k) + 2;
          if (3 < nr) {
            nr = 3;
          }

          if (b_k > m) {
            hoffset = ((b_k - 2) << 2) + b_k;
            for (j = 0; j < nr; j++) {
              v[j] = h[(j + hoffset) - 1];
            }
          }

          tst = v[0];
          b_v[0] = v[0];
          b_v[1] = v[1];
          b_v[2] = v[2];
          htmp2 = xzlarfg_OnHd8y0N(nr, &tst, b_v);
          v[1] = b_v[1];
          v[2] = b_v[2];
          v[0] = tst;
          if (b_k > m) {
            h[(b_k + ((b_k - 2) << 2)) - 1] = tst;
            h[b_k + ((b_k - 2) << 2)] = 0.0;
            if (b_k < i) {
              h[(b_k + ((b_k - 2) << 2)) + 1] = 0.0;
            }
          } else {
            if (m > k + 1) {
              hoffset = (((b_k - 2) << 2) + b_k) - 1;
              h[hoffset] *= 1.0 - htmp2;
            }
          }

          tst = b_v[1];
          ab = htmp2 * b_v[1];
          switch (nr) {
           case 3:
            ba = b_v[2];
            aa = htmp2 * b_v[2];
            for (nr = b_k - 1; nr + 1 < 5; nr++) {
              h12_tmp = (nr << 2) + b_k;
              h12 = (h[h12_tmp - 1] + h[h12_tmp] * tst) + h[h12_tmp + 1] * ba;
              h[h12_tmp - 1] -= h12 * htmp2;
              h[h12_tmp] -= h12 * ab;
              h[h12_tmp + 1] -= h12 * aa;
            }

            if (b_k + 3 < i + 1) {
              nr = b_k + 3;
            } else {
              nr = i + 1;
            }

            for (hoffset = 0; hoffset < nr; hoffset++) {
              h12_tmp = ((b_k - 1) << 2) + hoffset;
              j = (b_k << 2) + hoffset;
              h12_tmp_0 = ((b_k + 1) << 2) + hoffset;
              h12 = (h[h12_tmp] + h[j] * tst) + h[h12_tmp_0] * ba;
              h[h12_tmp] -= h12 * htmp2;
              h[j] -= h12 * ab;
              h[h12_tmp_0] -= h12 * aa;
            }

            for (nr = 0; nr < 4; nr++) {
              h12_tmp = ((b_k - 1) << 2) + nr;
              j = (b_k << 2) + nr;
              h12_tmp_0 = ((b_k + 1) << 2) + nr;
              h12 = (z[h12_tmp] + z[j] * tst) + z[h12_tmp_0] * ba;
              z[h12_tmp] -= h12 * htmp2;
              z[j] -= h12 * ab;
              z[h12_tmp_0] -= h12 * aa;
            }
            break;

           case 2:
            for (nr = b_k - 1; nr + 1 < 5; nr++) {
              h12_tmp = (nr << 2) + b_k;
              ba = h[h12_tmp - 1];
              h12 = ba + h[h12_tmp] * tst;
              h[h12_tmp - 1] = ba - h12 * htmp2;
              h[h12_tmp] -= h12 * ab;
            }

            for (nr = 0; nr <= i; nr++) {
              h12_tmp = ((b_k - 1) << 2) + nr;
              j = (b_k << 2) + nr;
              h12 = h[h12_tmp] + h[j] * tst;
              h[h12_tmp] -= h12 * htmp2;
              h[j] -= h12 * ab;
            }

            for (nr = 0; nr < 4; nr++) {
              h12_tmp = (b_k - 1) << 2;
              j = b_k << 2;
              h12 = z[h12_tmp + nr] + z[j + nr] * tst;
              hoffset = h12_tmp + nr;
              z[hoffset] -= h12 * htmp2;
              hoffset = j + nr;
              z[hoffset] -= h12 * ab;
            }
            break;
          }
        }

        its++;
      }
    }

    if (!goto150) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((i + 1 != L) && (L == i)) {
        nr = ((i - 1) << 2) + i;
        htmp2 = h[nr - 1];
        m = (i << 2) + i;
        tst = h[m - 1];
        ab = h[nr];
        ba = h[m];
        xdlanv2_7VfWHvfb(&htmp2, &tst, &ab, &ba, &aa, &h12, &htmp2_tmp_tmp,
                         &htmp2_tmp, &cs, &sn);
        h[nr - 1] = htmp2;
        h[m - 1] = tst;
        h[nr] = ab;
        h[m] = ba;
        if (4 > i + 1) {
          xrot_GqxWzXOv(3 - i, h, i + ((i + 1) << 2), (i + ((i + 1) << 2)) + 1,
                        cs, sn);
        }

        xrot_w5C6g5Fw(i - 1, h, ((i - 1) << 2) + 1, (i << 2) + 1, cs, sn);
        xrot_MOZ0Ssgv(z, ((i - 1) << 2) + 1, (i << 2) + 1, cs, sn);
      }

      i = L - 2;
    }
  }

  return info;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
