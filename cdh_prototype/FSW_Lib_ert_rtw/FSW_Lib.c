/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 5.10
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue May 24 14:44:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Debugging
 *    2. Execution efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

const soar_telemetry FSW_Lib_rtZsoar_telemetry = {
  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
  ,                                    /* opt_state */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
  ,                                    /* opt_ctrl_Nm */
  0.0,                                 /* final_time_s */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 }
  ,                                    /* exitcode */
  0U                                   /* soar_count */
} ;                                    /* soar_telemetry ground */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void jseconds2ymdhms(real_T time_s_J2000, real_T *Year, real_T *Month,
  real_T *Day, real_T *Hour, real_T *Min, real_T *Sec, real_T *JC_J2000, real_T *
  JD);
static real_T mod(real_T x);
static real_T norm_b(const real_T x[3]);
static void factorial(real_T *n);
static void merge(int32_T idx[6], real_T x[6], int32_T offset, int32_T np,
                  int32_T nq, int32_T iwork[6], real_T xwork[6]);
static void sort(real_T x[6], int32_T idx[6]);

/*
 * Output and update for action system:
 *    '<S89>/If Action Subsystem'
 *    '<S89>/If Action Subsystem3'
 */
void IfActionSubsystem(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S120>/Out1' incorporates:
   *  Constant: '<S120>/Constant'
   */
  *rty_Out1 = 1.0;
}

/*
 * Output and update for action system:
 *    '<S89>/If Action Subsystem1'
 *    '<S89>/If Action Subsystem4'
 */
void IfActionSubsystem1(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S121>/Out1' incorporates:
   *  Constant: '<S121>/Constant'
   */
  *rty_Out1 = 2.0;
}

/*
 * Output and update for action system:
 *    '<S89>/If Action Subsystem2'
 *    '<S89>/If Action Subsystem5'
 */
void IfActionSubsystem2(real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S122>/Out1' incorporates:
   *  Constant: '<S122>/Constant'
   */
  *rty_Out1 = 0.0;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function3' */
static void jseconds2ymdhms(real_T time_s_J2000, real_T *Year, real_T *Month,
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

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static real_T mod(real_T x)
{
  real_T q;
  real_T r;
  boolean_T rEQ0;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 6.2831853071795862);
    rEQ0 = (r == 0.0);
    if (!rEQ0) {
      q = fabs(x / 6.2831853071795862);
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = 0.0;
    } else {
      if (x < 0.0) {
        r += 6.2831853071795862;
      }
    }
  }

  return r;
}

/* Function for MATLAB Function: '<S35>/MATLAB Function' */
static real_T norm_b(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else {
      if ((u0 < 0.0) != (u1 < 0.0)) {
        y += u1;
      }
    }
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T u1_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = fabs(u0 / u1);
      if (!(fabs(u1_0 - floor(u1_0 + 0.5)) > DBL_EPSILON * u1_0)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S20>/MATLAB Function' */
static void factorial(real_T *n)
{
  static const real_T b[170] = { 1.0, 2.0, 6.0, 24.0, 120.0, 720.0, 5040.0,
    40320.0, 362880.0, 3.6288E+6, 3.99168E+7, 4.790016E+8, 6.2270208E+9,
    8.71782912E+10, 1.307674368E+12, 2.0922789888E+13, 3.55687428096E+14,
    6.402373705728E+15, 1.21645100408832E+17, 2.43290200817664E+18,
    5.109094217170944E+19, 1.1240007277776077E+21, 2.5852016738884978E+22,
    6.2044840173323941E+23, 1.5511210043330986E+25, 4.0329146112660565E+26,
    1.0888869450418352E+28, 3.0488834461171384E+29, 8.8417619937397008E+30,
    2.6525285981219103E+32, 8.2228386541779224E+33, 2.6313083693369352E+35,
    8.6833176188118859E+36, 2.9523279903960412E+38, 1.0333147966386144E+40,
    3.7199332678990118E+41, 1.3763753091226343E+43, 5.23022617466601E+44,
    2.0397882081197442E+46, 8.1591528324789768E+47, 3.3452526613163803E+49,
    1.4050061177528798E+51, 6.0415263063373834E+52, 2.6582715747884485E+54,
    1.1962222086548019E+56, 5.5026221598120885E+57, 2.5862324151116818E+59,
    1.2413915592536073E+61, 6.0828186403426752E+62, 3.0414093201713376E+64,
    1.5511187532873822E+66, 8.0658175170943877E+67, 4.2748832840600255E+69,
    2.3084369733924138E+71, 1.2696403353658276E+73, 7.1099858780486348E+74,
    4.0526919504877221E+76, 2.3505613312828789E+78, 1.3868311854568986E+80,
    8.3209871127413916E+81, 5.0758021387722484E+83, 3.1469973260387939E+85,
    1.98260831540444E+87, 1.2688693218588417E+89, 8.2476505920824715E+90,
    5.4434493907744307E+92, 3.6471110918188683E+94, 2.4800355424368305E+96,
    1.711224524281413E+98, 1.197857166996989E+100, 8.5047858856786218E+101,
    6.1234458376886077E+103, 4.4701154615126834E+105, 3.3078854415193856E+107,
    2.4809140811395391E+109, 1.8854947016660498E+111, 1.4518309202828584E+113,
    1.1324281178206295E+115, 8.9461821307829729E+116, 7.1569457046263779E+118,
    5.7971260207473655E+120, 4.75364333701284E+122, 3.9455239697206569E+124,
    3.314240134565352E+126, 2.8171041143805494E+128, 2.4227095383672724E+130,
    2.1077572983795269E+132, 1.8548264225739836E+134, 1.6507955160908452E+136,
    1.4857159644817607E+138, 1.3520015276784023E+140, 1.24384140546413E+142,
    1.1567725070816409E+144, 1.0873661566567424E+146, 1.0329978488239052E+148,
    9.916779348709491E+149, 9.6192759682482062E+151, 9.426890448883242E+153,
    9.33262154439441E+155, 9.33262154439441E+157, 9.4259477598383536E+159,
    9.6144667150351211E+161, 9.9029007164861754E+163, 1.0299016745145622E+166,
    1.0813967582402903E+168, 1.1462805637347078E+170, 1.2265202031961373E+172,
    1.3246418194518284E+174, 1.4438595832024928E+176, 1.5882455415227421E+178,
    1.7629525510902437E+180, 1.9745068572210728E+182, 2.2311927486598123E+184,
    2.5435597334721862E+186, 2.9250936934930141E+188, 3.3931086844518965E+190,
    3.969937160808719E+192, 4.6845258497542883E+194, 5.5745857612076033E+196,
    6.6895029134491239E+198, 8.09429852527344E+200, 9.8750442008335976E+202,
    1.2146304367025325E+205, 1.5061417415111404E+207, 1.8826771768889254E+209,
    2.3721732428800459E+211, 3.0126600184576582E+213, 3.8562048236258025E+215,
    4.9745042224772855E+217, 6.4668554892204716E+219, 8.4715806908788174E+221,
    1.1182486511960039E+224, 1.4872707060906852E+226, 1.9929427461615181E+228,
    2.6904727073180495E+230, 3.6590428819525472E+232, 5.01288874827499E+234,
    6.9177864726194859E+236, 9.6157231969410859E+238, 1.346201247571752E+241,
    1.89814375907617E+243, 2.6953641378881614E+245, 3.8543707171800706E+247,
    5.5502938327393013E+249, 8.0479260574719866E+251, 1.17499720439091E+254,
    1.7272458904546376E+256, 2.5563239178728637E+258, 3.8089226376305671E+260,
    5.7133839564458505E+262, 8.6272097742332346E+264, 1.3113358856834518E+267,
    2.0063439050956811E+269, 3.0897696138473489E+271, 4.7891429014633912E+273,
    7.47106292628289E+275, 1.1729568794264138E+278, 1.8532718694937338E+280,
    2.9467022724950369E+282, 4.714723635992059E+284, 7.5907050539472148E+286,
    1.2296942187394488E+289, 2.0044015765453015E+291, 3.2872185855342945E+293,
    5.423910666131586E+295, 9.0036917057784329E+297, 1.5036165148649983E+300,
    2.5260757449731969E+302, 4.2690680090047027E+304, 7.257415615307994E+306 };

  if (*n < 0.0) {
    *n = (rtNaN);
  } else if (floor(*n) != *n) {
    *n = (rtNaN);
  } else if (rtIsInf(*n) || rtIsNaN(*n)) {
    *n = (rtNaN);
  } else if (*n > 170.0) {
    *n = (rtInf);
  } else if (*n < 1.0) {
    *n = 1.0;
  } else {
    *n = b[(int32_T)*n - 1];
  }
}

/* Function for MATLAB Function: '<S151>/MATLAB Function' */
static void merge(int32_T idx[6], real_T x[6], int32_T offset, int32_T np,
                  int32_T nq, int32_T iwork[6], real_T xwork[6])
{
  int32_T exitg1;
  int32_T iout;
  int32_T n;
  int32_T n_tmp;
  int32_T q;
  if ((np != 0) && (nq != 0)) {
    n_tmp = np + nq;
    for (q = 0; q < n_tmp; q++) {
      iout = offset + q;
      iwork[q] = idx[iout];
      xwork[q] = x[iout];
    }

    n = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[n] <= xwork[q]) {
        idx[iout] = iwork[n];
        x[iout] = xwork[n];
        if (n + 1 < np) {
          n++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - n;
          while (n + 1 <= np) {
            iout = (q + n) + 1;
            idx[iout] = iwork[n];
            x[iout] = xwork[n];
            n++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* Function for MATLAB Function: '<S151>/MATLAB Function' */
static void sort(real_T x[6], int32_T idx[6])
{
  real_T xwork[6];
  real_T x4[4];
  real_T tmp;
  real_T tmp_0;
  int32_T iwork[6];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T ib;
  int32_T nNaNs;
  int8_T idx4[4];
  int8_T perm[4];
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  for (i = 0; i < 6; i++) {
    idx[i] = 0;
    xwork[i] = 0.0;
  }

  nNaNs = 0;
  ib = -1;
  for (i = 0; i < 6; i++) {
    if (rtIsNaN(x[i])) {
      idx[5 - nNaNs] = i + 1;
      xwork[5 - nNaNs] = x[i];
      nNaNs++;
    } else {
      ib++;
      idx4[ib] = (int8_T)(i + 1);
      x4[ib] = x[i];
      if (ib + 1 == 4) {
        ib = i - nNaNs;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        tmp = x4[i1 - 1];
        tmp_0 = x4[i3 - 1];
        if (tmp <= tmp_0) {
          tmp = x4[i2 - 1];
          if (tmp <= tmp_0) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i2;
            perm[2] = (int8_T)i3;
            perm[3] = (int8_T)i4;
          } else if (tmp <= x4[i4 - 1]) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        } else {
          tmp_0 = x4[i4 - 1];
          if (tmp <= tmp_0) {
            if (x4[i2 - 1] <= tmp_0) {
              perm[0] = (int8_T)i3;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i2;
              perm[3] = (int8_T)i4;
            } else {
              perm[0] = (int8_T)i3;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i4;
              perm[3] = (int8_T)i2;
            }
          } else {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)i4;
            perm[2] = (int8_T)i1;
            perm[3] = (int8_T)i2;
          }
        }

        idx[ib - 3] = idx4[perm[0] - 1];
        idx[ib - 2] = idx4[perm[1] - 1];
        idx[ib - 1] = idx4[perm[2] - 1];
        idx[ib] = idx4[perm[3] - 1];
        x[ib - 3] = x4[perm[0] - 1];
        x[ib - 2] = x4[perm[1] - 1];
        x[ib - 1] = x4[perm[2] - 1];
        x[ib] = x4[perm[3] - 1];
        ib = -1;
      }
    }
  }

  if (ib + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    switch (ib + 1) {
     case 1:
      perm[0] = 1;
      break;

     case 2:
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
      break;

     default:
      if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      break;
    }

    for (i = 0; i <= ib; i++) {
      i1 = perm[i] - 1;
      i2 = ((i - nNaNs) - ib) + 5;
      idx[i2] = idx4[i1];
      x[i2] = x4[i1];
    }
  }

  i = (nNaNs >> 1) + 6;
  for (ib = 6; ib - 6 <= i - 7; ib++) {
    i2 = ib - nNaNs;
    i1 = idx[i2];
    idx[i2] = idx[11 - ib];
    idx[11 - ib] = i1;
    x[i2] = xwork[11 - ib];
    x[11 - ib] = xwork[i2];
  }

  if ((nNaNs & 1U) != 0U) {
    i -= nNaNs;
    x[i] = xwork[i];
  }

  if (6 - nNaNs > 1) {
    for (i = 0; i < 6; i++) {
      iwork[i] = 0;
    }

    ib = (6 - nNaNs) >> 2;
    i = 4;
    while (ib > 1) {
      if ((ib & 1U) != 0U) {
        ib--;
        i1 = i * ib;
        i2 = 6 - (nNaNs + i1);
        if (i2 > i) {
          merge(idx, x, i1, i, i2 - i, iwork, xwork);
        }
      }

      i1 = i << 1;
      ib >>= 1;
      for (i2 = 0; i2 < ib; i2++) {
        merge(idx, x, i2 * i1, i, i, iwork, xwork);
      }

      i = i1;
    }

    if (6 - nNaNs > i) {
      merge(idx, x, 0, i, 6 - (nNaNs + i), iwork, xwork);
    }
  }
}

/* Model step function */
void FSW_Lib_step(void)
{
  static const real_T nc[300] = { 1.0, 9.0, 31.0, 2.0, 10.0, 32.0, 11.0, 33.0,
    34.0, 12.0, 35.0, 13.0, 36.0, 38.0, 37.0, 40.0, 39.0, 41.0, 14.0, 3.0, 42.0,
    45.0, 43.0, 44.0, 46.0, 15.0, 47.0, 16.0, 18.0, 48.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, -1.0, 1.0, 0.0, -1.0, -1.0, 1.0, 2.0,
    -2.0, 0.0, 2.0, 2.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0, 0.0,
    0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0, 2.0, 2.0, 0.0, 0.0, 2.0, 0.0, 2.0, 0.0,
    2.0, 2.0, 2.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0, 0.0,
    0.0, 0.0, -2.0, 0.0, 0.0, -2.0, -2.0, -2.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0,
    -2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0, -2.0, 0.0, 0.0, -2.0, 2.0, 1.0, 2.0,
    2.0, 2.0, 0.0, 0.0, 2.0, 1.0, 2.0, 2.0, 0.0, 1.0, 2.0, 1.0, 0.0, 2.0, 1.0,
    1.0, 0.0, 1.0, 2.0, 2.0, 0.0, 2.0, 0.0, 0.0, 1.0, 0.0, 2.0, 1.0, -171996.0,
    -13187.0, -2274.0, 2062.0, 1426.0, 712.0, -517.0, -386.0, -301.0, 217.0,
    -158.0, 129.0, 123.0, 63.0, 63.0, -59.0, -58.0, -51.0, 48.0, 46.0, -38.0,
    -31.0, 29.0, 29.0, 26.0, -22.0, 21.0, 17.0, -16.0, 16.0, -174.2, -1.6, -0.2,
    0.2, -3.4, 0.1, 1.2, -0.4, 0.0, -0.5, 0.0, 0.1, 0.0, 0.1, 0.0, 0.0, -0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.1, 0.1, 0.0, 92025.0,
    5736.0, 977.0, -895.0, 54.0, -7.0, 224.0, 200.0, 129.0, -95.0, -1.0, -70.0,
    -53.0, -33.0, -2.0, 26.0, 32.0, 27.0, 1.0, -24.0, 16.0, 13.0, -1.0, -12.0,
    -1.0, 0.0, -10.0, 0.0, 7.0, -8.0, 8.9, -3.1, -0.5, 0.5, -0.1, 0.0, -0.6, 0.0,
    -0.1, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T dg[156] = { 7.0, -11.0, 2.4, -0.8, -0.3, -0.8, -0.3, -0.1,
    -0.1, 0.0, 0.0, 0.0, 9.0, -6.2, -5.7, -0.9, 0.6, -0.5, -0.2, 0.2, -0.1, 0.0,
    0.0, 0.0, 0.0, 0.3, 2.0, -6.5, -0.8, -0.1, -0.3, -0.2, 0.0, -0.1, 0.0, 0.0,
    0.0, 0.0, -11.0, 5.2, 0.1, 1.6, 0.9, 0.5, 0.4, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0,
    -4.0, 1.2, -1.6, 0.1, -0.1, -0.4, -0.1, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 1.4,
    0.0, -0.6, 0.4, 0.0, -0.2, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2, -0.9,
    0.4, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.7, -0.1, 0.0, -0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 0.0, -0.2, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.3, -0.1, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -0.1 };

  static const real_T dh[156] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -30.2, -29.6, 6.5, -0.4, 0.2, 0.3, 0.6, -0.4, -0.3, 0.0, 0.0,
    0.0, 0.0, -17.3, -0.8, 5.8, 2.3, -1.5, 0.5, 0.6, 0.1, 0.1, 0.1, 0.0, 0.0,
    0.0, -2.0, 3.8, 0.0, -1.2, -0.8, -0.1, -0.4, -0.2, 0.0, -0.1, 0.0, 0.0, 0.0,
    -3.5, 3.3, 0.4, -0.2, 0.6, 0.3, 0.1, 0.1, 0.1, 0.0, 0.0, 0.0, 0.0, -0.6, 0.2,
    -1.1, -0.2, 0.1, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.3, 0.1, -0.5,
    0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.5, -0.1, 0.0, 0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.5, -0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.2, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.1 };

  static const real_T g[156] = { -29438.2, -2444.5, 1351.8, 907.5, -232.9, 69.4,
    81.7, 24.2, 5.5, -2.0, 3.0, -2.0, -1493.5, 3014.7, -2351.6, 814.8, 360.1,
    67.7, -75.9, 8.9, 8.8, -6.1, -1.4, -0.1, 0.0, 1679.0, 1223.6, 117.8, 191.7,
    72.3, -7.1, -16.9, 3.0, 0.2, -2.3, 0.5, 0.0, 0.0, 582.3, -335.6, -141.3,
    -129.1, 52.2, -3.1, -3.2, 0.6, 2.1, 1.2, 0.0, 0.0, 0.0, 69.7, -157.2, -28.4,
    15.0, -20.7, 0.6, -0.5, -0.8, -0.9, 0.0, 0.0, 0.0, 0.0, 7.7, 13.6, 9.1, 13.3,
    -13.2, 1.8, 0.6, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, -70.3, -3.0, 11.6, -0.1, -0.7,
    -0.7, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.9, -16.3, 8.7, 2.2, 0.1, 0.6, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -2.1, -9.1, 2.4, 1.7, -0.4, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -10.4, -1.8, -0.2, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -3.6, 0.4, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 3.5, -0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T h[156] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 4796.3, -2842.4, -113.7, 283.3, 46.9, -20.1, -54.3, 10.1,
    -21.8, 3.3, 0.0, -1.0, 0.0, -638.8, 246.5, -188.6, 196.5, 32.8, -19.5, -18.3,
    10.7, -0.4, 2.1, 0.3, 0.0, 0.0, -537.4, 180.7, -119.9, 59.1, 6.0, 13.3, 11.8,
    4.6, -0.6, 1.8, 0.0, 0.0, 0.0, -330.0, 16.0, -67.1, 24.5, -14.5, -6.8, 4.4,
    -1.1, -2.2, 0.0, 0.0, 0.0, 0.0, 100.6, 8.1, 3.5, 16.2, -6.9, -7.9, 0.7, 0.3,
    0.0, 0.0, 0.0, 0.0, 0.0, 61.9, -27.7, 6.0, 7.9, -0.6, -0.2, 0.7, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -2.9, -9.2, 1.0, -4.2, -2.1, -0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 2.4, -3.9, -2.9, -1.5, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 8.5, -1.1, -2.6, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -8.8,
    -2.0, -0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -2.3, -0.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.8 };

  static const int8_T normals[18] = { 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0,
    1, 0, 0, -1 };

  real_T P_0[196];
  real_T cp[13];
  real_T sp[13];
  real_T rtb_Gain2_0[9];
  real_T rtb_MathFunction1[9];
  real_T rtb_MatrixConcatenate2[9];
  real_T rtb_VectorConcatenate_d[9];
  real_T rtb_mod_to_gcrf[9];
  real_T theta_0[9];
  real_T rtb_YMDHMS_UTC[6];
  real_T rtb_DiscreteTimeIntegrator[4];
  real_T rtb_Multiply_i[4];
  real_T rtb_RPM2Radps[4];
  real_T rtb_Switch_g[4];
  real_T rtb_AU2KM[3];
  real_T rtb_Gain2[3];
  real_T rtb_Gain_a[3];
  real_T rtb_LLA2ECEF[3];
  real_T rtb_Median[3];
  real_T rtb_Multiply2[3];
  real_T rtb_Product2_tmp[3];
  real_T rtb_Switch[3];
  real_T rtb_pos_teme_km[3];
  real_T rtb_ss_2_body[3];
  real_T C_5;
  real_T D_2;
  real_T D_2_tmp;
  real_T D_3;
  real_T D_4;
  real_T D_sun;
  real_T IL3;
  real_T IL4;
  real_T IL5;
  real_T M_DF;
  real_T M_moon;
  real_T M_o;
  real_T M_p;
  real_T M_sun;
  real_T O_moon;
  real_T a_1;
  real_T api;
  real_T b_o;
  real_T d_1;
  real_T d_1_tmp_tmp_tmp;
  real_T d_M;
  real_T d_M_tmp;
  real_T d_o;
  real_T d_w;
  real_T d_w_tmp;
  real_T d_w_tmp_0;
  real_T deps_1980;
  real_T dpsi_1980;
  real_T dpsi_1980_tmp;
  real_T dpsi_1980_tmp_0;
  real_T dpsi_1980_tmp_1;
  real_T eps;
  real_T epsb_1980;
  real_T eta;
  real_T n_o;
  real_T rtb_Sqrt_c;
  real_T theta;
  real_T tsince;
  real_T tsince_JD;
  real_T u_moon;
  real_T w_DF_tmp_tmp;
  real_T xi;
  real_T z;
  real_T zeta;
  int32_T iidx[6];
  int32_T P_tmp;
  int32_T P_tmp_0;
  int32_T i;
  int32_T idxStart;
  int32_T iter;
  int32_T zeta_tmp;
  uint32_T i0;
  uint32_T i1;
  uint8_T rtb_Merge;
  boolean_T lowAlt;

  /* MATLAB Function: '<S4>/MATLAB Function3' incorporates:
   *  Inport: '<Root>/MET_utc_s'
   */
  jseconds2ymdhms(rtU.MET_utc_s, &rtb_YMDHMS_UTC[0], &rtb_YMDHMS_UTC[1],
                  &rtb_YMDHMS_UTC[2], &rtb_YMDHMS_UTC[3], &rtb_YMDHMS_UTC[4],
                  &rtb_YMDHMS_UTC[5], &D_sun, &tsince_JD);
  jseconds2ymdhms(rtU.MET_utc_s + -0.0361535, &M_moon, &M_sun, &u_moon, &D_sun,
                  &deps_1980, &api, &eps, &z);
  jseconds2ymdhms((rtU.MET_utc_s + 37.0) + 32.184, &M_moon, &M_sun, &u_moon,
                  &D_sun, &deps_1980, &api, &z, &epsb_1980);

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S4>/MATLAB Function3'
   */
  tsince = rt_powd_snf(z, 3.0);
  n_o = z * z;
  epsb_1980 = (((23.439291 - 0.0130042 * z) - n_o * 1.64E-7) + 5.04E-7 * tsince)
    * 0.017453292519943295;
  M_moon = (((477198.8673981 * z + 134.96298139) + n_o * 0.0086972) + 1.78E-5 *
            tsince) * 0.017453292519943295;
  M_sun = (((35999.05034 * z + 357.52772333) - n_o * 0.0001603) - 3.3E-6 *
           tsince) * 0.017453292519943295;
  u_moon = (((483202.0175381 * z + 93.27191028) - n_o * 0.0036825) + 3.1E-6 *
            tsince) * 0.017453292519943295;
  D_sun = (((445267.11148 * z + 297.85036306) - n_o * 0.0019142) + 5.3E-6 *
           tsince) * 0.017453292519943295;
  O_moon = (((125.04452222 - 1934.1362608 * z) + n_o * 0.0020708) + 2.2E-6 *
            tsince) * 0.017453292519943295;
  dpsi_1980 = 0.0;
  deps_1980 = 0.0;
  for (iter = 0; iter < 30; iter++) {
    api = (((nc[iter + 30] * M_moon + nc[iter + 60] * M_sun) + nc[iter + 90] *
            u_moon) + nc[iter + 120] * D_sun) + nc[iter + 150] * O_moon;
    dpsi_1980 += (nc[iter + 210] * z + nc[iter + 180]) * 0.0001 * sin(api);
    deps_1980 += (nc[iter + 270] * z + nc[iter + 240]) * 0.0001 * cos(api);
  }

  api = 4.84813681109536E-6 * deps_1980 + epsb_1980;
  M_o = 4.84813681109536E-6 * dpsi_1980;
  M_moon = sin(-epsb_1980);
  M_sun = cos(-epsb_1980);
  u_moon = sin(M_o);
  D_sun = cos(M_o);
  deps_1980 = sin(api);
  api = cos(api);
  zeta = ((n_o * 0.30188 + 2306.2181 * z) + 0.017998 * tsince) *
    4.84813681109536E-6;
  theta = ((2004.3109 * z - n_o * 0.42665) - 0.041833 * tsince) *
    4.84813681109536E-6;
  z = ((n_o * 1.09468 + 2306.2181 * z) + 0.018203 * tsince) *
    4.84813681109536E-6;
  tsince = sin(zeta);
  zeta = cos(zeta);
  M_o = sin(-theta);
  theta = cos(-theta);
  n_o = sin(z);
  z = cos(z);
  rtb_mod_to_gcrf[0] = zeta;
  rtb_mod_to_gcrf[3] = tsince;
  rtb_mod_to_gcrf[6] = 0.0;
  rtb_mod_to_gcrf[1] = -tsince;
  rtb_mod_to_gcrf[4] = zeta;
  rtb_mod_to_gcrf[7] = 0.0;
  theta_0[0] = theta;
  theta_0[3] = 0.0;
  theta_0[6] = -M_o;
  rtb_Gain2[0] = 1.0;
  rtb_mod_to_gcrf[2] = 0.0;
  theta_0[1] = 0.0;
  rtb_ss_2_body[0] = 0.0;
  rtb_Gain2[1] = 0.0;
  rtb_mod_to_gcrf[5] = 0.0;
  theta_0[4] = 1.0;
  rtb_ss_2_body[1] = 0.0;
  rtb_Gain2[2] = 0.0;
  rtb_mod_to_gcrf[8] = 1.0;
  theta_0[7] = 0.0;
  rtb_ss_2_body[2] = 1.0;
  theta_0[2] = M_o;
  theta_0[5] = 0.0;
  theta_0[8] = theta;
  rtb_VectorConcatenate_d[0] = z;
  rtb_VectorConcatenate_d[3] = n_o;
  rtb_VectorConcatenate_d[6] = 0.0;
  rtb_VectorConcatenate_d[1] = -n_o;
  rtb_VectorConcatenate_d[4] = z;
  rtb_VectorConcatenate_d[7] = 0.0;
  for (i = 0; i < 3; i++) {
    for (iter = 0; iter < 3; iter++) {
      zeta_tmp = i + 3 * iter;
      rtb_MatrixConcatenate2[zeta_tmp] = 0.0;
      rtb_MatrixConcatenate2[zeta_tmp] += theta_0[3 * iter] * rtb_mod_to_gcrf[i];
      rtb_MatrixConcatenate2[zeta_tmp] += theta_0[3 * iter + 1] *
        rtb_mod_to_gcrf[i + 3];
      rtb_MatrixConcatenate2[zeta_tmp] += theta_0[3 * iter + 2] *
        rtb_mod_to_gcrf[i + 6];
    }

    rtb_VectorConcatenate_d[3 * i + 2] = rtb_ss_2_body[i];
  }

  for (i = 0; i < 3; i++) {
    for (iter = 0; iter < 3; iter++) {
      zeta_tmp = iter + 3 * i;
      rtb_mod_to_gcrf[zeta_tmp] = 0.0;
      rtb_mod_to_gcrf[zeta_tmp] += rtb_VectorConcatenate_d[3 * i] *
        rtb_MatrixConcatenate2[iter];
      rtb_mod_to_gcrf[zeta_tmp] += rtb_VectorConcatenate_d[3 * i + 1] *
        rtb_MatrixConcatenate2[iter + 3];
      rtb_mod_to_gcrf[zeta_tmp] += rtb_VectorConcatenate_d[3 * i + 2] *
        rtb_MatrixConcatenate2[iter + 6];
    }
  }

  epsb_1980 = ((dpsi_1980 * cos(epsb_1980) + 0.00264 * sin(O_moon)) + sin(2.0 *
    O_moon) * 6.3E-5) * 4.84813681109536E-6;
  O_moon = ((3.1644001848128662E+9 * eps + 67310.54841) + eps * eps * 0.093104)
    - 6.2E-6 * rt_powd_snf(eps, 3.0);
  if (O_moon < 0.0) {
    z = -1.0;
  } else if (O_moon > 0.0) {
    z = 1.0;
  } else if (O_moon == 0.0) {
    z = 0.0;
  } else {
    z = (rtNaN);
  }

  z *= 86400.0;
  tsince = O_moon;
  if (z == 0.0) {
    if (O_moon == 0.0) {
      tsince = z;
    }
  } else if (rtIsNaN(O_moon)) {
    tsince = (rtNaN);
  } else if (rtIsNaN(z)) {
    tsince = (rtNaN);
  } else if (rtIsInf(O_moon)) {
    tsince = (rtNaN);
  } else if (O_moon == 0.0) {
    tsince = 0.0 / z;
  } else {
    tsince = fmod(O_moon, z);
    if (tsince == 0.0) {
      tsince = z * 0.0;
    } else {
      if ((O_moon < 0.0) != (z < 0.0)) {
        tsince += z;
      }
    }
  }

  O_moon = tsince / 240.0;
  if (rtIsNaN(O_moon)) {
    z = (rtNaN);
  } else if (rtIsInf(O_moon)) {
    z = (rtNaN);
  } else if (O_moon == 0.0) {
    z = 0.0;
  } else {
    z = fmod(O_moon, 360.0);
    if (z == 0.0) {
      z = 0.0;
    } else {
      if (O_moon < 0.0) {
        z += 360.0;
      }
    }
  }

  z = -(0.017453292519943295 * z + epsb_1980);

  /* MATLAB Function: '<S4>/MATLAB Function1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Inport: '<Root>/orbit_tle'
   *  MATLAB Function: '<S4>/MATLAB Function3'
   *  Sum: '<S4>/Subtract'
   */
  theta = 1.88027916E-9;
  dpsi_1980 = 1.01222928;
  O_moon = rtU.orbit_tle[3] * 0.0174532925;
  zeta = rtU.orbit_tle[6] * 0.0174532925;
  M_o = rtU.orbit_tle[7] * 0.0174532925;
  n_o = rtU.orbit_tle[8] * 2.0 * 3.1415926535897931 / 1440.0;
  if ((rtU.orbit_tle[5] >= 1.0) || (rtU.orbit_tle[5] <= 0.0)) {
    rtb_pos_teme_km[0] = 6378.137;
    rtb_pos_teme_km[1] = 6378.137;
    rtb_pos_teme_km[2] = 6878.137;
  } else if (n_o == 0.0) {
    rtb_pos_teme_km[0] = 6378.137;
    rtb_pos_teme_km[1] = 6378.137;
    rtb_pos_teme_km[2] = 6878.137;
  } else {
    tsince_JD = (tsince_JD - 2.451545E+6) - rtU.orbit_tle[1];
    if (fabs(tsince_JD) < 1.0E-8) {
      tsince_JD = 0.0;
    } else {
      if (tsince_JD < 0.0) {
        tsince_JD = 0.0;
      }
    }

    tsince = 1440.0 * tsince_JD;
    a_1 = rt_powd_snf(0.0743669161 / n_o, 0.66666666666666663);
    tsince_JD = cos(O_moon);
    M_p = 1.0 - rtU.orbit_tle[5] * rtU.orbit_tle[5];
    d_w = tsince_JD * tsince_JD;
    d_1_tmp_tmp_tmp = d_w * 3.0;
    d_M = (d_1_tmp_tmp_tmp - 1.0) / rt_powd_snf(M_p, 1.5);
    d_1 = d_M * (0.000541308 / (a_1 * a_1) * 1.5);
    a_1 *= ((1.0 - 0.33333333333333331 * d_1) - d_1 * d_1) - 1.654320987654321 *
      rt_powd_snf(d_1, 3.0);
    d_o = d_M * (0.000541308 / (a_1 * a_1) * 1.5);
    n_o /= d_o + 1.0;
    d_o = a_1 / (1.0 - d_o);
    d_1 = (1.0 - rtU.orbit_tle[5]) * d_o;
    a_1 = (d_1 - 1.0) * 6378.137;
    lowAlt = (d_1 < 1.0344928307435228);
    if ((a_1 >= 98.0) && (a_1 <= 156.0)) {
      dpsi_1980 = (d_1 - 1.01222928) + 1.0;
      theta = rt_powd_snf(1.0188142770258546 - ((d_1 - 1.01222928) + 1.0), 4.0);
    } else {
      if (a_1 < 98.0) {
        theta = 6.0426196528035638E-8;
        dpsi_1980 = 1.0031357118857749;
      }
    }

    xi = 1.0 / (d_o - dpsi_1980);
    b_o = sqrt(M_p);
    eta = d_o * rtU.orbit_tle[5] * xi;
    if (eta == 1.0) {
      rtb_pos_teme_km[0] = 6378.137;
      rtb_pos_teme_km[1] = 6378.137;
      rtb_pos_teme_km[2] = 6878.137;
    } else {
      M_p = rt_powd_snf(xi, 4.0);
      d_w_tmp = eta * eta;
      d_w_tmp_0 = rt_powd_snf(1.0 - d_w_tmp, -3.5);
      d_M_tmp = rt_powd_snf(eta, 3.0);
      d_M = d_w_tmp * 1.5;
      d_1 = ((((d_M + 1.0) + 4.0 * rtU.orbit_tle[5] * eta) + rtU.orbit_tle[5] *
              d_M_tmp) * d_o + (d_w * 1.5 + -0.5) * (0.00081196200000000006 * xi)
             * ((d_w_tmp * 24.0 + 8.0) + 3.0 * rt_powd_snf(eta, 4.0)) / (1.0 -
              eta * eta)) * (theta * M_p * n_o * d_w_tmp_0) * rtU.orbit_tle[2];
      C_5 = 0.0;
      D_2 = 0.0;
      D_3 = 0.0;
      D_4 = 0.0;
      IL3 = 0.0;
      IL4 = 0.0;
      IL5 = 0.0;
      if (!lowAlt) {
        C_5 = 2.0 * theta * M_p * d_o * (b_o * b_o) * d_w_tmp_0 * ((2.75 * eta *
          (eta + rtU.orbit_tle[5]) + 1.0) + rtU.orbit_tle[5] * rt_powd_snf(eta,
          3.0));
        D_2_tmp = d_1 * d_1;
        D_2 = 4.0 * d_o * xi * D_2_tmp;
        IL4 = rt_powd_snf(d_1, 3.0);
        D_3 = 1.3333333333333333 * d_o * (xi * xi) * (17.0 * d_o + dpsi_1980) *
          IL4;
        a_1 = rt_powd_snf(d_1, 4.0);
        D_4 = 0.66666666666666663 * d_o * rt_powd_snf(xi, 3.0) * (221.0 * d_o +
          31.0 * dpsi_1980) * a_1;
        IL3 = D_2_tmp * 2.0 + D_2;
        IL4 = ((12.0 * d_1 * D_2 + 3.0 * D_3) + 10.0 * IL4) * 0.25;
        IL5 = ((((12.0 * d_1 * D_3 + 3.0 * D_4) + D_2 * D_2 * 6.0) + D_2_tmp *
                30.0 * D_2) + 15.0 * a_1) * 0.2;
      }

      a_1 = rt_powd_snf(tsince_JD, 4.0);
      dpsi_1980_tmp = rt_powd_snf(d_o, 4.0);
      dpsi_1980 = d_o * d_o;
      D_2_tmp = dpsi_1980 * 2.0 * rt_powd_snf(b_o, 3.0);
      M_DF = (((d_1_tmp_tmp_tmp - 1.0) * 0.0016239240000000001 / D_2_tmp + 1.0)
              + ((13.0 - d_w * 78.0) + 137.0 * a_1) * 8.7904305259200008E-7 /
              (16.0 * dpsi_1980_tmp * rt_powd_snf(b_o, 7.0))) * n_o * tsince +
        M_o;
      w_DF_tmp_tmp = rt_powd_snf(b_o, 8.0);
      a_1 = ((((7.0 - d_w * 114.0) + 395.0 * a_1) * 8.7904305259200008E-7 /
              (16.0 * rt_powd_snf(d_o, 4.0) * w_DF_tmp_tmp) + (1.0 - d_w * 5.0) *
              -0.0016239240000000001 / D_2_tmp) + ((3.0 - d_w * 36.0) + 49.0 *
              a_1) * 3.1049437500000002E-6 / (4.0 * dpsi_1980_tmp * w_DF_tmp_tmp))
        * n_o * tsince + zeta;
      dpsi_1980_tmp_0 = b_o * b_o;
      dpsi_1980_tmp_1 = tsince * tsince;
      D_2_tmp = d_w * 7.0;
      dpsi_1980 = ((((4.0 * tsince_JD - 19.0 * rt_powd_snf(tsince_JD, 3.0)) *
                     8.7904305259200008E-7 / (2.0 * dpsi_1980_tmp * w_DF_tmp_tmp)
                     + -0.0016239240000000001 * tsince_JD / (dpsi_1980 *
        rt_powd_snf(b_o, 4.0))) + (3.0 - D_2_tmp) * (3.1049437500000002E-6 *
        tsince_JD) / (2.0 * dpsi_1980_tmp * w_DF_tmp_tmp)) * n_o * tsince +
                   rtU.orbit_tle[4] * 0.0174532925) - n_o * 0.000541308 *
        tsince_JD / (dpsi_1980 * dpsi_1980_tmp_0) * 10.5 * d_1 * dpsi_1980_tmp_1;
      if (!lowAlt) {
        d_w = theta * rt_powd_snf(xi, 5.0) * 2.538815E-6 * n_o * sin(O_moon) /
          (0.000541308 * rtU.orbit_tle[5]) * rtU.orbit_tle[2] * cos(zeta) *
          tsince;
        d_M = -0.66666666666666663 * theta * rtU.orbit_tle[2] * M_p * (1.0 /
          (rtU.orbit_tle[5] * eta)) * (rt_powd_snf(eta * cos(M_DF) + 1.0, 3.0) -
          rt_powd_snf(eta * cos(M_o) + 1.0, 3.0));
        M_p = (M_DF + d_w) + d_M;
        a_1 = (a_1 - d_w) - d_M;
        theta = (rtU.orbit_tle[5] - ((((rtU.orbit_tle[5] * eta + 1.0) * (2.0 *
          eta) + 0.5 * rtU.orbit_tle[5]) + 0.5 * d_M_tmp) - ((((1.0 - eta * eta *
          1.5) - 2.0 * rtU.orbit_tle[5] * eta) - 0.5 * rtU.orbit_tle[5] *
                    d_M_tmp) * ((1.0 - tsince_JD * tsince_JD * 3.0) * 3.0) +
                   ((eta * eta * 2.0 - rtU.orbit_tle[5] * eta) - rtU.orbit_tle[5]
                    * rt_powd_snf(eta, 3.0)) * ((1.0 - tsince_JD * tsince_JD) *
                    0.75) * cos(2.0 * zeta)) * (0.001082616 * xi / ((1.0 - eta *
          eta) * d_o))) * (2.0 * n_o * theta * rt_powd_snf(xi, 4.0) * d_o * (b_o
                   * b_o) * d_w_tmp_0) * rtU.orbit_tle[2] * tsince) -
          rtU.orbit_tle[2] * C_5 * (sin(M_p) - sin(M_o));
        zeta = rt_powd_snf(tsince, 3.0);
        xi = rt_powd_snf(tsince, 4.0);
        d_w = tsince * tsince;
        M_o = (((1.0 - d_1 * tsince) - d_w * D_2) - D_3 * zeta) - D_4 * xi;
        M_o = M_o * M_o * d_o;
        d_1 = (((1.5 * d_1 * d_w + IL3 * zeta) + IL4 * xi) + IL5 * rt_powd_snf
               (tsince, 5.0)) * n_o + ((M_p + a_1) + dpsi_1980);
      } else {
        M_o = 1.0 - d_1 * tsince;
        M_o = M_o * M_o * d_o;
        D_3 = rtU.orbit_tle[5] * eta;
        theta = rtU.orbit_tle[5] - ((((D_3 + 1.0) * (2.0 * eta) + 0.5 *
          rtU.orbit_tle[5]) + 0.5 * d_M_tmp) - ((((1.0 - d_M) - 2.0 *
          rtU.orbit_tle[5] * eta) - 0.5 * rtU.orbit_tle[5] * d_M_tmp) * ((1.0 -
          d_1_tmp_tmp_tmp) * 3.0) + ((d_w_tmp * 2.0 - D_3) - rtU.orbit_tle[5] *
          rt_powd_snf(eta, 3.0)) * ((1.0 - d_w) * 0.75) * cos(2.0 * zeta)) *
          (0.001082616 * xi / ((1.0 - eta * eta) * d_o))) * (2.0 * n_o * theta *
          M_p * d_o * dpsi_1980_tmp_0 * d_w_tmp_0) * rtU.orbit_tle[2] * tsince;
        d_1 = 1.5 * d_1 * n_o * dpsi_1980_tmp_1 + ((M_DF + a_1) + dpsi_1980);
      }

      if ((M_o == 0.0) || (theta >= 1.0)) {
        rtb_pos_teme_km[0] = 6378.137;
        rtb_pos_teme_km[1] = 6378.137;
        rtb_pos_teme_km[2] = 6878.137;
      } else {
        tsince = sqrt(1.0 - theta * theta);
        IL3 = cos(a_1);
        n_o = theta * IL3;
        zeta = sin(O_moon);
        M_p = tsince * tsince;
        d_o = 2.538815E-6 * zeta / (0.002165232 * M_o * M_p) + theta * sin(a_1);
        theta = mod((2.538815E-6 * sin(O_moon) / (0.004330464 * M_o * M_p) *
                     theta * IL3 * ((5.0 * tsince_JD + 3.0) / (tsince_JD + 1.0))
                     + d_1) - dpsi_1980);
        a_1 = theta;
        tsince = 0.0;
        iter = 0;
        while ((fabs(a_1 - tsince) > 1.0E-8) && (iter < 10)) {
          a_1 = tsince;
          d_1 = sin(tsince);
          xi = cos(tsince);
          tsince += (((theta - d_o * xi) + n_o * d_1) - tsince) / ((-d_o * d_1 -
            n_o * xi) + 1.0);
          iter++;
        }

        d_1 = sin(tsince);
        IL3 = cos(tsince);
        IL4 = n_o * d_1 - d_o * IL3;
        D_2 = sqrt(n_o * n_o + d_o * d_o);
        D_3 = 1.0 - D_2 * D_2;
        theta = D_3 * M_o;
        tsince = (1.0 - (n_o * cos(tsince) + d_o * d_1)) * M_o;
        if ((tsince == 0.0) || (theta == 0.0)) {
          rtb_pos_teme_km[0] = 6378.137;
          rtb_pos_teme_km[1] = 6378.137;
          rtb_pos_teme_km[2] = 6878.137;
        } else {
          a_1 = sqrt(D_3);
          d_w = M_o / tsince;
          M_o = rt_atan2d_snf(((d_1 - d_o) - n_o * IL4 / (a_1 + 1.0)) * d_w,
                              (d_o * IL4 / (sqrt(1.0 - D_2 * D_2) + 1.0) + (IL3
            - n_o)) * d_w);
          n_o = cos(2.0 * M_o);
          d_1 = theta * theta;
          tsince = (1.0 - (d_1_tmp_tmp_tmp - 1.0) * (0.00081196200000000006 *
                     a_1) / d_1) * tsince + 0.000541308 / (2.0 * theta) * (1.0 -
            tsince_JD * tsince_JD) * n_o;
          d_o = sin(2.0 * M_o);
          M_o += -(0.000541308 / (d_1 * 4.0)) * (D_2_tmp - 1.0) * d_o;
          dpsi_1980_tmp = 0.0016239240000000001 * tsince_JD / (d_1 * 2.0);
          dpsi_1980 += dpsi_1980_tmp * d_o;
          O_moon += dpsi_1980_tmp * zeta * n_o;
          tsince_JD = sin(M_o);
          theta = cos(M_o);
          zeta = cos(O_moon);
          M_o = cos(dpsi_1980);
          dpsi_1980 = sin(dpsi_1980);
          rtb_pos_teme_km[0] = (-dpsi_1980 * zeta * tsince_JD + M_o * theta) *
            tsince * 6378.137;
          rtb_pos_teme_km[1] = (M_o * zeta * tsince_JD + dpsi_1980 * theta) *
            tsince * 6378.137;
          rtb_pos_teme_km[2] = (sin(O_moon) * tsince_JD + 0.0 * theta) * tsince *
            6378.137;
        }
      }
    }
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function1' */

  /* MATLAB Function: '<S4>/MATLAB Function' */
  O_moon = sin(-epsb_1980);
  epsb_1980 = cos(-epsb_1980);
  rtb_VectorConcatenate_d[1] = 0.0;
  rtb_VectorConcatenate_d[4] = M_sun;
  rtb_VectorConcatenate_d[7] = M_moon;
  rtb_VectorConcatenate_d[2] = 0.0;
  rtb_VectorConcatenate_d[5] = -M_moon;
  rtb_VectorConcatenate_d[8] = M_sun;
  rtb_MatrixConcatenate2[0] = D_sun;
  rtb_MatrixConcatenate2[3] = u_moon;
  rtb_MatrixConcatenate2[6] = 0.0;
  rtb_MatrixConcatenate2[1] = -u_moon;
  rtb_MatrixConcatenate2[4] = D_sun;
  rtb_MatrixConcatenate2[7] = 0.0;
  rtb_VectorConcatenate_d[0] = 1.0;
  rtb_MatrixConcatenate2[2] = 0.0;
  rtb_VectorConcatenate_d[3] = 0.0;
  rtb_MatrixConcatenate2[5] = 0.0;
  rtb_VectorConcatenate_d[6] = 0.0;
  rtb_MatrixConcatenate2[8] = 1.0;
  for (i = 0; i < 3; i++) {
    for (iter = 0; iter < 3; iter++) {
      zeta_tmp = i + 3 * iter;
      theta_0[zeta_tmp] = 0.0;
      theta_0[zeta_tmp] += rtb_MatrixConcatenate2[3 * iter] *
        rtb_VectorConcatenate_d[i];
      theta_0[zeta_tmp] += rtb_MatrixConcatenate2[3 * iter + 1] *
        rtb_VectorConcatenate_d[i + 3];
      theta_0[zeta_tmp] += rtb_MatrixConcatenate2[3 * iter + 2] *
        rtb_VectorConcatenate_d[i + 6];
    }

    rtb_Gain2_0[3 * i] = rtb_Gain2[i];
  }

  rtb_Gain2_0[1] = 0.0;
  rtb_Gain2_0[4] = api;
  rtb_Gain2_0[7] = deps_1980;
  rtb_Gain2_0[2] = 0.0;
  rtb_Gain2_0[5] = -deps_1980;
  rtb_Gain2_0[8] = api;
  for (i = 0; i < 3; i++) {
    for (iter = 0; iter < 3; iter++) {
      zeta_tmp = iter + 3 * i;
      rtb_VectorConcatenate_d[zeta_tmp] = 0.0;
      rtb_VectorConcatenate_d[zeta_tmp] += rtb_Gain2_0[3 * i] * theta_0[iter];
      rtb_VectorConcatenate_d[zeta_tmp] += rtb_Gain2_0[3 * i + 1] * theta_0[iter
        + 3];
      rtb_VectorConcatenate_d[zeta_tmp] += rtb_Gain2_0[3 * i + 2] * theta_0[iter
        + 6];
    }
  }

  theta_0[0] = epsb_1980;
  theta_0[3] = O_moon;
  theta_0[6] = 0.0;
  theta_0[1] = -O_moon;
  theta_0[4] = epsb_1980;
  theta_0[7] = 0.0;
  for (i = 0; i < 3; i++) {
    for (iter = 0; iter < 3; iter++) {
      zeta_tmp = i + 3 * iter;
      rtb_MatrixConcatenate2[zeta_tmp] = 0.0;
      rtb_MatrixConcatenate2[zeta_tmp] += rtb_VectorConcatenate_d[3 * iter] *
        rtb_mod_to_gcrf[i];
      rtb_MatrixConcatenate2[zeta_tmp] += rtb_VectorConcatenate_d[3 * iter + 1] *
        rtb_mod_to_gcrf[i + 3];
      rtb_MatrixConcatenate2[zeta_tmp] += rtb_VectorConcatenate_d[3 * iter + 2] *
        rtb_mod_to_gcrf[i + 6];
    }

    theta_0[3 * i + 2] = rtb_ss_2_body[i];
  }

  for (i = 0; i < 3; i++) {
    /* Product: '<S4>/Product1' */
    rtb_Multiply2[i] = 0.0;
    for (iter = 0; iter < 3; iter++) {
      zeta_tmp = i + 3 * iter;
      rtb_VectorConcatenate_d[zeta_tmp] = 0.0;
      rtb_VectorConcatenate_d[zeta_tmp] += theta_0[3 * iter] *
        rtb_MatrixConcatenate2[i];
      rtb_VectorConcatenate_d[zeta_tmp] += theta_0[3 * iter + 1] *
        rtb_MatrixConcatenate2[i + 3];
      rtb_VectorConcatenate_d[zeta_tmp] += theta_0[3 * iter + 2] *
        rtb_MatrixConcatenate2[i + 6];
      rtb_Multiply2[i] += rtb_VectorConcatenate_d[zeta_tmp] *
        rtb_pos_teme_km[iter];
    }

    /* End of Product: '<S4>/Product1' */

    /* Gain: '<S4>/Gain2' */
    rtb_Gain2[i] = 1000.0 * rtb_Multiply2[i];
  }

  /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S4>/MATLAB Function3'
   */
  M_sun = mod((35999.05034 * eps + 357.5277233) * 0.017453292519943295);
  M_moon = (mod((36000.77 * eps + 280.46) * 0.017453292519943295) +
            0.033417233996490527 * sin(M_sun)) + sin(2.0 * M_sun) *
    0.00034897235311083654;
  eps = (23.439291 - 0.0130042 * eps) * 0.017453292519943295;
  tsince = (1.000140612 - 0.016708617 * cos(M_sun)) - cos(2.0 * M_sun) *
    0.000139589;
  M_sun = sin(M_moon);
  M_moon = tsince * cos(M_moon);
  u_moon = cos(eps) * M_sun * tsince;
  epsb_1980 = sin(eps) * M_sun * tsince;

  /* MATLAB Function: '<S35>/MATLAB Function' */
  api = 0.0;
  M_sun = 0.0;
  for (iter = 0; iter < 3; iter++) {
    /* Gain: '<S4>/M2KM' */
    D_sun = 0.001 * rtb_Gain2[iter];

    /* Gain: '<S16>/Gain' */
    O_moon = 1.002 * D_sun;

    /* Gain: '<S16>/AU2KM' incorporates:
     *  Product: '<S16>/Product'
     */
    eps = 1.49598073E+8 * (rtb_mod_to_gcrf[iter + 6] * epsb_1980 +
      (rtb_mod_to_gcrf[iter + 3] * u_moon + rtb_mod_to_gcrf[iter] * M_moon));

    /* MATLAB Function: '<S35>/MATLAB Function' */
    tsince_JD = eps * 1.49598073E+8;
    tsince = O_moon * tsince_JD;
    api += tsince;
    M_sun += tsince;

    /* Gain: '<S4>/M2KM' */
    rtb_pos_teme_km[iter] = D_sun;

    /* Gain: '<S16>/Gain' */
    rtb_Gain_a[iter] = O_moon;

    /* Gain: '<S16>/AU2KM' */
    rtb_AU2KM[iter] = eps;

    /* MATLAB Function: '<S35>/MATLAB Function' */
    rtb_Switch[iter] = tsince_JD;
  }

  /* MATLAB Function: '<S35>/MATLAB Function' */
  eps = norm_b(rtb_Gain_a);
  M_moon = norm_b(rtb_Switch);
  eps *= eps;
  M_moon = (eps - api) / ((eps + M_moon * M_moon) - 2.0 * M_sun);
  lowAlt = ((!(((rtb_Gain_a[0] * rtb_Switch[0] + rtb_Gain_a[1] * rtb_Switch[1])
                + rtb_Gain_a[2] * rtb_Switch[2]) * M_moon + (1.0 - M_moon) * eps
               >= 4.0680631590768993E+7)) && ((!(M_moon < 0.0)) && (!(M_moon >
    1.0))));

  /* If: '<S155>/If' incorporates:
   *  Inport: '<Root>/sun_meas_valid'
   */
  if (rtU.sun_meas_valid) {
    /* Outputs for IfAction SubSystem: '<S155>/sunSensorIsValid' incorporates:
     *  ActionPort: '<S159>/Action Port'
     */
    /* Abs: '<S159>/Abs' incorporates:
     *  Inport: '<Root>/sun_meas_ss_deg'
     */
    api = fabs(rtU.sun_meas_ss_deg[0]);

    /* Relay: '<S159>/Relay' */
    if (api >= 60.0) {
      rtDW.Relay_Mode[0] = true;
    } else {
      if (api <= 10.0) {
        rtDW.Relay_Mode[0] = false;
      }
    }

    /* Abs: '<S159>/Abs' incorporates:
     *  Inport: '<Root>/sun_meas_ss_deg'
     */
    api = fabs(rtU.sun_meas_ss_deg[1]);

    /* Relay: '<S159>/Relay' */
    if (api >= 60.0) {
      rtDW.Relay_Mode[1] = true;
    } else {
      if (api <= 10.0) {
        rtDW.Relay_Mode[1] = false;
      }
    }

    /* Sum: '<S159>/Sum' incorporates:
     *  Constant: '<S160>/Lower Limit'
     *  Constant: '<S160>/Upper Limit'
     *  Constant: '<S161>/Lower Limit'
     *  Constant: '<S161>/Upper Limit'
     *  Inport: '<Root>/sun_meas_ss_deg'
     *  Logic: '<S159>/AND'
     *  Logic: '<S159>/AND1'
     *  Logic: '<S160>/AND'
     *  Logic: '<S161>/AND'
     *  RelationalOperator: '<S160>/Lower Test'
     *  RelationalOperator: '<S160>/Upper Test'
     *  RelationalOperator: '<S161>/Lower Test'
     *  RelationalOperator: '<S161>/Upper Test'
     *  Relay: '<S159>/Relay'
     */
    rtb_Merge = (uint8_T)((uint32_T)((-60.0 <= rtU.sun_meas_ss_deg[0]) &&
      (rtU.sun_meas_ss_deg[0] <= 60.0) && ((-60.0 <= rtU.sun_meas_ss_deg[1]) &&
      (rtU.sun_meas_ss_deg[1] <= 60.0))) + ((!rtDW.Relay_Mode[0]) &&
      (!rtDW.Relay_Mode[1])));

    /* End of Outputs for SubSystem: '<S155>/sunSensorIsValid' */
  } else {
    /* Outputs for IfAction SubSystem: '<S155>/sunSensorIsNotValid' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    /* SignalConversion generated from: '<S158>/ss_valid_false' incorporates:
     *  Constant: '<S158>/Constant'
     */
    rtb_Merge = 0U;

    /* End of Outputs for SubSystem: '<S155>/sunSensorIsNotValid' */
  }

  /* End of If: '<S155>/If' */

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Product: '<S15>/Matrix Multiply'
   *  Product: '<S4>/Product3'
   */
  eps = sin(z);
  M_moon = cos(z);
  rtb_VectorConcatenate_d[0] = M_moon;
  rtb_VectorConcatenate_d[3] = eps;
  rtb_VectorConcatenate_d[6] = 0.0;
  rtb_VectorConcatenate_d[1] = -eps;
  rtb_VectorConcatenate_d[4] = M_moon;
  rtb_VectorConcatenate_d[7] = 0.0;
  for (i = 0; i < 3; i++) {
    idxStart = 3 * i + 2;
    rtb_VectorConcatenate_d[idxStart] = rtb_ss_2_body[i];

    /* Product: '<S4>/Product3' incorporates:
     *  Product: '<S15>/MatrixMultiply'
     */
    rtb_ss_2_body[i] = 0.0;
    for (iter = 0; iter < 3; iter++) {
      /* Math: '<S4>/Transpose' incorporates:
       *  Product: '<S15>/Matrix Multiply'
       *  Product: '<S4>/Product3'
       */
      zeta_tmp = i + 3 * iter;
      rtb_mod_to_gcrf[zeta_tmp] = 0.0;
      rtb_mod_to_gcrf[zeta_tmp] += rtb_VectorConcatenate_d[3 * i] *
        rtb_MatrixConcatenate2[iter];
      rtb_mod_to_gcrf[zeta_tmp] += rtb_VectorConcatenate_d[3 * i + 1] *
        rtb_MatrixConcatenate2[iter + 3];
      rtb_mod_to_gcrf[zeta_tmp] += rtb_VectorConcatenate_d[idxStart] *
        rtb_MatrixConcatenate2[iter + 6];
      rtb_ss_2_body[i] += rtb_mod_to_gcrf[zeta_tmp] * rtb_Gain2[iter];
    }
  }

  /* LLA2ECEF: '<S4>/LLA2ECEF' incorporates:
   *  Inport: '<Root>/target_latlonalt'
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  eps = rtU.target_latlonalt[0] * 3.1415926535897931 / 180.0;
  M_sun = fabs(eps);
  M_moon = rtU.target_latlonalt[1] * 3.1415926535897931 / 180.0;
  if (M_sun > 3.1415926535897931) {
    eps = rt_modd_snf(eps + 3.1415926535897931, 6.2831853071795862) -
      3.1415926535897931;
    M_sun = fabs(eps);
  }

  if (M_sun > 1.5707963267948966) {
    M_moon += 3.1415926535897931;
    if (eps < 0.0) {
      eps = -1.0;
    } else if (eps > 0.0) {
      eps = 1.0;
    } else if (eps == 0.0) {
      eps = 0.0;
    } else {
      eps = (rtNaN);
    }

    eps *= 1.5707963267948966 - (M_sun - 1.5707963267948966);
  }

  if (fabs(M_moon) > 3.1415926535897931) {
    u_moon = rt_remd_snf(M_moon, 6.2831853071795862);
    api = u_moon / 3.1415926535897931;
    if (api < 0.0) {
      api = ceil(api);
    } else {
      api = floor(api);
    }

    M_moon = u_moon - 6.2831853071795862 * api;
  }

  M_sun = sin(eps);
  rtb_LLA2ECEF[0] = (6.378137E+6 / sqrt(1.0 - M_sun * M_sun *
    0.0066943799901413165) + rtU.target_latlonalt[2]) * cos(eps) * cos(M_moon);
  rtb_LLA2ECEF[1] = (6.378137E+6 / sqrt(1.0 - sin(eps) * sin(eps) *
    0.0066943799901413165) + rtU.target_latlonalt[2]) * cos(eps) * sin(M_moon);
  rtb_LLA2ECEF[2] = (6.378137E+6 / sqrt(1.0 - sin(eps) * sin(eps) *
    0.0066943799901413165) * 0.99330562000985867 + rtU.target_latlonalt[2]) *
    M_sun;

  /* End of LLA2ECEF: '<S4>/LLA2ECEF' */

  /* Outputs for Atomic SubSystem: '<S4>/target_groundpass_lib1' */
  /* Product: '<S4>/Product3' incorporates:
   *  Inport: '<Root>/target_latlonalt'
   *  Outport: '<Root>/sc_above_targ'
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  target_groundpass_lib(rtb_ss_2_body, rtb_LLA2ECEF, rtU.target_latlonalt[0],
                        rtU.target_latlonalt[1], &rtY.sc_above_targ, &eps,
                        rtb_Gain_a);

  /* End of Outputs for SubSystem: '<S4>/target_groundpass_lib1' */

  /* Gain: '<S10>/deg2rad' incorporates:
   *  Concatenate: '<S5>/Matrix Concatenate2'
   *  Inport: '<Root>/gyro_gyro_radps'
   */
  for (i = 0; i < 9; i++) {
    rtb_MatrixConcatenate2[i] = 0.017453292519943295 * rtU.gyro_gyro_radps[i];
  }

  /* End of Gain: '<S10>/deg2rad' */

  /* S-Function (sdspperm2): '<S153>/Variable Selector' incorporates:
   *  Concatenate: '<S5>/Matrix Concatenate2'
   *  Product: '<S89>/Multiply2'
   */
  rtb_Multiply2[0] = rtb_MatrixConcatenate2[0];
  rtb_Multiply2[1] = rtb_MatrixConcatenate2[1];
  rtb_Multiply2[2] = rtb_MatrixConcatenate2[2];

  /* Product: '<S153>/Matrix Multiply3' incorporates:
   *  Constant: '<S153>/Constant13'
   *  Product: '<S89>/Multiply2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtConstP.pooled25[i + 6] * rtb_Multiply2[2] +
      (rtConstP.pooled25[i + 3] * rtb_Multiply2[1] + rtConstP.pooled25[i] *
       rtb_Multiply2[0]);
  }

  /* End of Product: '<S153>/Matrix Multiply3' */

  /* S-Function (sdspperm2): '<S153>/Variable Selector1' incorporates:
   *  Concatenate: '<S5>/Matrix Concatenate2'
   *  Product: '<S89>/Multiply2'
   */
  rtb_Multiply2[0] = rtb_MatrixConcatenate2[3];
  rtb_Multiply2[1] = rtb_MatrixConcatenate2[4];
  rtb_Multiply2[2] = rtb_MatrixConcatenate2[5];

  /* Product: '<S153>/Matrix Multiply1' incorporates:
   *  Constant: '<S153>/Constant20'
   *  Product: '<S89>/Multiply2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i + 3] = rtConstP.pooled25[i + 6] * rtb_Multiply2[2]
      + (rtConstP.pooled25[i + 3] * rtb_Multiply2[1] + rtConstP.pooled25[i] *
         rtb_Multiply2[0]);
  }

  /* End of Product: '<S153>/Matrix Multiply1' */

  /* S-Function (sdspperm2): '<S153>/Variable Selector2' incorporates:
   *  Concatenate: '<S5>/Matrix Concatenate2'
   *  Product: '<S89>/Multiply2'
   */
  rtb_Multiply2[0] = rtb_MatrixConcatenate2[6];
  rtb_Multiply2[1] = rtb_MatrixConcatenate2[7];
  rtb_Multiply2[2] = rtb_MatrixConcatenate2[8];

  /* Product: '<S153>/Matrix Multiply2' incorporates:
   *  Constant: '<S153>/Constant22'
   *  Product: '<S89>/Multiply2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i + 6] = rtConstP.pooled25[i + 6] * rtb_Multiply2[2]
      + (rtConstP.pooled25[i + 3] * rtb_Multiply2[1] + rtConstP.pooled25[i] *
         rtb_Multiply2[0]);
  }

  /* End of Product: '<S153>/Matrix Multiply2' */

  /* S-Function (sdspmdn2): '<S153>/Median' incorporates:
   *  Concatenate: '<S154>/Vector Concatenate'
   */
  zeta_tmp = 0;
  for (i = 0; i < 3; i++) {
    i0 = rtDW.Median_Index[0];
    eps = rtb_VectorConcatenate_d[rtDW.Median_Index[0] + i];
    i1 = rtDW.Median_Index[1U];
    M_moon = rtb_VectorConcatenate_d[rtDW.Median_Index[1U] + i];
    if (eps > M_moon) {
      rtDW.Median_Index[1U] = rtDW.Median_Index[0];
      rtDW.Median_Index[0U] = i1;
    } else {
      eps = M_moon;
      i0 = rtDW.Median_Index[1U];
    }

    i1 = rtDW.Median_Index[2U];
    M_moon = rtb_VectorConcatenate_d[rtDW.Median_Index[2U] + i];
    if (eps > M_moon) {
      rtDW.Median_Index[2U] = i0;
      iter = 2;
      if (rtb_VectorConcatenate_d[rtDW.Median_Index[0U] + i] > M_moon) {
        rtDW.Median_Index[1U] = rtDW.Median_Index[0U];
        iter = 1;
      } else {
        /* set loop index to break loop */
      }

      rtDW.Median_Index[iter - 1U] = i1;
    }

    rtb_Median[zeta_tmp] = rtb_VectorConcatenate_d[rtDW.Median_Index[1] + i];
    zeta_tmp++;
  }

  /* End of S-Function (sdspmdn2): '<S153>/Median' */

  /* Outputs for Atomic SubSystem: '<S1>/mode_select_lib' */
  /* Inport: '<Root>/telecom' incorporates:
   *  Inport: '<Root>/MET_soar_utc_s'
   *  Inport: '<Root>/MET_utc_s'
   *  Inport: '<Root>/rwa_rpm'
   *  Outport: '<Root>/gnc_mode'
   *  Outport: '<Root>/sc_above_targ'
   */
  mode_select_lib(rtU.telecom, lowAlt, rtb_Merge, rtb_Median, rtU.MET_utc_s,
                  rtU.MET_soar_utc_s, rtU.rwa_rpm, &rtY.gnc_mode,
                  &rtConstB.mode_select_lib_p, &rtDW.mode_select_lib_p);

  /* End of Outputs for SubSystem: '<S1>/mode_select_lib' */

  /* Sum: '<S16>/Subtract' */
  eps = rtb_AU2KM[0] - rtb_pos_teme_km[0];

  /* Math: '<S34>/Math Function' */
  rtb_LLA2ECEF[0] = eps * eps;

  /* Sum: '<S16>/Subtract' */
  rtb_AU2KM[0] = eps;
  eps = rtb_AU2KM[1] - rtb_pos_teme_km[1];

  /* Math: '<S34>/Math Function' */
  rtb_LLA2ECEF[1] = eps * eps;

  /* Sum: '<S16>/Subtract' */
  rtb_AU2KM[1] = eps;
  eps = rtb_AU2KM[2] - rtb_pos_teme_km[2];

  /* Sum: '<S34>/Sum of Elements' incorporates:
   *  Math: '<S34>/Math Function'
   */
  D_sun = (rtb_LLA2ECEF[0] + rtb_LLA2ECEF[1]) + eps * eps;

  /* Math: '<S34>/Math Function1'
   *
   * About '<S34>/Math Function1':
   *  Operator: sqrt
   */
  if (D_sun < 0.0) {
    D_sun = -sqrt(fabs(D_sun));
  } else {
    D_sun = sqrt(D_sun);
  }

  /* End of Math: '<S34>/Math Function1' */

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S34>/Constant'
   *  Product: '<S34>/Product'
   */
  if (D_sun > 0.0) {
    rtb_DiscreteTimeIntegrator[0] = rtb_AU2KM[0];
    rtb_DiscreteTimeIntegrator[1] = rtb_AU2KM[1];
    rtb_DiscreteTimeIntegrator[2] = eps;
    rtb_DiscreteTimeIntegrator[3] = D_sun;
  } else {
    rtb_DiscreteTimeIntegrator[0] = rtb_AU2KM[0] * 0.0;
    rtb_DiscreteTimeIntegrator[1] = rtb_AU2KM[1] * 0.0;
    rtb_DiscreteTimeIntegrator[2] = eps * 0.0;
    rtb_DiscreteTimeIntegrator[3] = 1.0;
  }

  /* End of Switch: '<S34>/Switch' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S34>/Divide' */
    rtb_AU2KM[i] = rtb_DiscreteTimeIntegrator[i] / rtb_DiscreteTimeIntegrator[3];

    /* Math: '<S4>/Transpose1' incorporates:
     *  Math: '<S15>/Transpose1'
     *  Product: '<S15>/Matrix Multiply'
     */
    rtb_VectorConcatenate_d[3 * i] = rtb_mod_to_gcrf[i];
    rtb_VectorConcatenate_d[3 * i + 1] = rtb_mod_to_gcrf[i + 3];
    rtb_VectorConcatenate_d[3 * i + 2] = rtb_mod_to_gcrf[i + 6];
  }

  /* Product: '<S4>/Product2' incorporates:
   *  Math: '<S4>/Transpose1'
   */
  for (i = 0; i < 3; i++) {
    rtb_LLA2ECEF[i] = rtb_VectorConcatenate_d[i + 6] * rtb_Gain_a[2] +
      (rtb_VectorConcatenate_d[i + 3] * rtb_Gain_a[1] +
       rtb_VectorConcatenate_d[i] * rtb_Gain_a[0]);
  }

  /* End of Product: '<S4>/Product2' */

  /* Outputs for Atomic SubSystem: '<S1>/target_generation_lib' */
  /* Outport: '<Root>/gnc_mode' incorporates:
   *  Inport: '<Root>/MET_soar_utc_s'
   *  Inport: '<Root>/MET_utc_s'
   *  Inport: '<Root>/quat_soar_cmd'
   *  Inport: '<Root>/telecom'
   *  Outport: '<Root>/sc_above_targ'
   *  RateTransition generated from: '<S1>/Rate Transition4'
   */
  target_generation_lib(rtY.gnc_mode, rtb_AU2KM, rtb_LLA2ECEF, rtb_Gain2,
                        rtU.quat_soar_cmd, rtU.MET_soar_utc_s, rtU.MET_utc_s,
                        rtY.sc_above_targ, rtU.telecom[4]);

  /* End of Outputs for SubSystem: '<S1>/target_generation_lib' */

  /* ECEF2LLA: '<S15>/ECEF Position to LLA' incorporates:
   *  Product: '<S15>/MatrixMultiply'
   */
  D_sun = sqrt(rtb_ss_2_body[0] * rtb_ss_2_body[0] + rtb_ss_2_body[1] *
               rtb_ss_2_body[1]);
  eps = rt_atan2d_snf(rtb_ss_2_body[2], 0.99664718933525254 * D_sun);
  M_moon = sin(eps);
  M_sun = cos(eps);
  M_moon = rt_atan2d_snf(42841.311513313573 * M_moon * M_moon * M_moon +
    rtb_ss_2_body[2], D_sun - 42697.672707179969 * M_sun * M_sun * M_sun);
  M_sun = rt_atan2d_snf(0.99664718933525254 * sin(M_moon), cos(M_moon));
  iter = 0;
  while ((eps != M_sun) && (iter < 5)) {
    eps = M_sun;
    M_moon = sin(M_sun);
    M_sun = cos(M_sun);
    M_moon = rt_atan2d_snf(42841.311513313573 * M_moon * M_moon * M_moon +
      rtb_ss_2_body[2], D_sun - 42697.672707179969 * M_sun * M_sun * M_sun);
    M_sun = rt_atan2d_snf(0.99664718933525254 * sin(M_moon), cos(M_moon));
    iter++;
  }

  M_sun = fabs(M_moon);
  eps = M_moon;
  u_moon = rt_atan2d_snf(rtb_ss_2_body[1], rtb_ss_2_body[0]);
  if (M_sun > 3.1415926535897931) {
    eps = rt_modd_snf(M_moon + 3.1415926535897931, 6.2831853071795862) -
      3.1415926535897931;
    M_sun = fabs(eps);
  }

  if (M_sun > 1.5707963267948966) {
    u_moon += 3.1415926535897931;
    if (eps < 0.0) {
      eps = -1.0;
    } else if (eps > 0.0) {
      eps = 1.0;
    } else if (eps == 0.0) {
      eps = 0.0;
    } else {
      eps = (rtNaN);
    }

    eps *= 1.5707963267948966 - (M_sun - 1.5707963267948966);
  }

  if (fabs(u_moon) > 3.1415926535897931) {
    u_moon = rt_remd_snf(u_moon, 6.2831853071795862);
    api = u_moon / 3.1415926535897931;
    if (api < 0.0) {
      api = ceil(api);
    } else {
      api = floor(api);
    }

    u_moon -= 6.2831853071795862 * api;
  }

  api = eps * 180.0 / 3.1415926535897931;
  eps = sin(M_moon);
  M_moon = ((6.378137E+6 / sqrt(1.0 - eps * eps * 0.0066943799901413165) *
             0.0066943799901413165 * eps + rtb_ss_2_body[2]) * eps + D_sun * cos
            (M_moon)) - 6.378137E+6 / sqrt(1.0 - sin(M_moon) * sin(M_moon) *
    0.0066943799901413165);

  /* UnitConversion: '<S30>/Unit Conversion' incorporates:
   *  MATLAB Function: '<S20>/MATLAB Function'
   */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  deps_1980 = 0.017453292519943295 * api;

  /* Trigonometry: '<S18>/sincos' incorporates:
   *  UnitConversion: '<S30>/Unit Conversion'
   */
  M_sun = cos(deps_1980);

  /* UnitConversion: '<S30>/Unit Conversion' incorporates:
   *  ECEF2LLA: '<S15>/ECEF Position to LLA'
   *  MATLAB Function: '<S20>/MATLAB Function'
   *  Trigonometry: '<S18>/sincos'
   */
  eps = sin(deps_1980);
  z = 0.017453292519943295 * (u_moon * 180.0 / 3.1415926535897931);

  /* Trigonometry: '<S18>/sincos' incorporates:
   *  UnitConversion: '<S30>/Unit Conversion'
   */
  u_moon = cos(z);
  api = sin(z);

  /* UnaryMinus: '<S21>/Unary Minus' incorporates:
   *  Product: '<S21>/u(1)*u(4)'
   */
  rtb_mod_to_gcrf[0] = -(eps * u_moon);

  /* UnaryMinus: '<S24>/Unary Minus' */
  rtb_mod_to_gcrf[1] = -api;

  /* UnaryMinus: '<S27>/Unary Minus' incorporates:
   *  Product: '<S27>/u(3)*u(4)'
   */
  rtb_mod_to_gcrf[2] = -(M_sun * u_moon);

  /* UnaryMinus: '<S22>/Unary Minus' incorporates:
   *  Product: '<S22>/u(1)*u(2)'
   */
  rtb_mod_to_gcrf[3] = -(eps * api);

  /* SignalConversion generated from: '<S31>/Vector Concatenate' */
  rtb_mod_to_gcrf[4] = u_moon;

  /* UnaryMinus: '<S28>/Unary Minus' incorporates:
   *  Product: '<S28>/u(2)*u(3)'
   */
  rtb_mod_to_gcrf[5] = -(api * M_sun);

  /* SignalConversion generated from: '<S31>/Vector Concatenate' */
  rtb_mod_to_gcrf[6] = M_sun;

  /* SignalConversion generated from: '<S31>/Vector Concatenate' incorporates:
   *  Constant: '<S26>/Constant'
   */
  rtb_mod_to_gcrf[7] = 0.0;

  /* UnaryMinus: '<S29>/Unary Minus' */
  rtb_mod_to_gcrf[8] = -eps;

  /* Math: '<S15>/Transpose' incorporates:
   *  Concatenate: '<S31>/Vector Concatenate'
   *  Concatenate: '<S5>/Matrix Concatenate2'
   */
  for (i = 0; i < 3; i++) {
    rtb_MatrixConcatenate2[3 * i] = rtb_mod_to_gcrf[i];
    rtb_MatrixConcatenate2[3 * i + 1] = rtb_mod_to_gcrf[i + 3];
    rtb_MatrixConcatenate2[3 * i + 2] = rtb_mod_to_gcrf[i + 6];
  }

  /* End of Math: '<S15>/Transpose' */

  /* MATLAB Function: '<S15>/MATLAB Function' */
  if (rtIsNaN(rtb_YMDHMS_UTC[0])) {
    tsince = (rtNaN);
  } else if (rtIsInf(rtb_YMDHMS_UTC[0])) {
    tsince = (rtNaN);
  } else if (rtb_YMDHMS_UTC[0] == 0.0) {
    tsince = 0.0;
  } else {
    tsince = fmod(rtb_YMDHMS_UTC[0], 4.0);
    if (tsince == 0.0) {
      tsince = 0.0;
    } else {
      if (rtb_YMDHMS_UTC[0] < 0.0) {
        tsince += 4.0;
      }
    }
  }

  if (tsince == 0.0) {
    D_sun = 366.0;
    iter = 29;
  } else {
    D_sun = 365.25;
    iter = 28;
  }

  if (rtb_YMDHMS_UTC[1] == 1.0) {
    api = rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 2.0) {
    api = rtb_YMDHMS_UTC[2] + 31.0;
  } else if (rtb_YMDHMS_UTC[1] == 3.0) {
    api = ((real_T)iter + 31.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 4.0) {
    api = (((real_T)iter + 31.0) + 31.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 5.0) {
    api = ((((real_T)iter + 31.0) + 31.0) + 30.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 6.0) {
    api = (((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 7.0) {
    api = ((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) +
      rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 8.0) {
    api = (((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0) +
      rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 9.0) {
    api = ((((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0) +
           31.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 10.0) {
    api = (((((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0) +
            31.0) + 30.0) + rtb_YMDHMS_UTC[2];
  } else if (rtb_YMDHMS_UTC[1] == 11.0) {
    api = ((((((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0)
             + 31.0) + 30.0) + 31.0) + rtb_YMDHMS_UTC[2];
  } else {
    api = (((((((((((real_T)iter + 31.0) + 31.0) + 30.0) + 31.0) + 30.0) + 31.0)
              + 31.0) + 30.0) + 31.0) + 30.0) + rtb_YMDHMS_UTC[2];
  }

  eps = (((rtb_YMDHMS_UTC[3] / 24.0 + api) + rtb_YMDHMS_UTC[4] / 1440.0) +
         rtb_YMDHMS_UTC[5] / 86400.0) / D_sun + rtb_YMDHMS_UTC[0];

  /* End of MATLAB Function: '<S15>/MATLAB Function' */

  /* MATLAB Function: '<S20>/MATLAB Function' */
  api = sin(deps_1980);
  memset(&sp[0], 0, 13U * sizeof(real_T));
  memset(&cp[0], 0, 13U * sizeof(real_T));
  sp[1] = sin(z);
  cp[0] = 1.0;
  cp[1] = cos(z);
  iter = 3;
  for (i = 0; i < 11; i++) {
    iter = i + 3;
    z = cp[i + 1];
    sp[i + 2] = z * sp[1] + sp[i + 1] * cp[1];
    cp[i + 2] = z * cp[1] - sp[i + 1] * sp[1];
  }

  u_moon = 6.378137E+6 / sqrt(1.0 - api * api * 0.0066943799901413165);
  M_sun = (u_moon + M_moon) * cos(deps_1980);
  z = (u_moon * 0.99330562000985867 + M_moon) * api;
  tsince = sqrt(M_sun * M_sun + z * z);
  M_moon = asin(z / tsince);
  api = sin(M_moon);
  M_sun = 6.3712E+6 / tsince;
  u_moon = M_sun * M_sun;
  memset(&P_0[0], 0, 196U * sizeof(real_T));
  z = sqrt(1.0 - api * api);
  D_sun = tan(M_moon);
  M_o = 1.0 / cos(M_moon);
  P_0[0] = 1.0;
  P_0[1] = api;
  P_0[15] = -z;
  i = 2;
  for (zeta_tmp = 0; zeta_tmp < 12; zeta_tmp++) {
    i = zeta_tmp + 2;
    P_0[zeta_tmp + 2] = ((((real_T)zeta_tmp + 2.0) * 2.0 - 1.0) * api *
                         P_0[zeta_tmp + 1] - (((real_T)zeta_tmp + 2.0) - 1.0) *
                         P_0[zeta_tmp]) * (1.0 / ((real_T)zeta_tmp + 2.0));
    iter = 1;
    for (idxStart = 0; idxStart <= zeta_tmp + 1; idxStart++) {
      iter = idxStart + 1;
      P_tmp = 14 * idxStart + zeta_tmp;
      P_tmp_0 = zeta_tmp - idxStart;
      tsince = zeta_tmp + idxStart;
      P_0[(zeta_tmp + 14 * (idxStart + 1)) + 2] = ((((real_T)P_tmp_0 + 1.0) +
        1.0) * api * P_0[P_tmp + 2] - ((tsince + 3.0) - 1.0) * P_0[P_tmp + 1]) *
        (1.0 / z);
      if ((idxStart + 1 > 1) && (P_tmp_0 + 1 > 0)) {
        epsb_1980 = ((real_T)(zeta_tmp - idxStart) - 1.0) + 1.0;
        factorial(&epsb_1980);
        theta = (tsince + 1.0) - 1.0;
        factorial(&theta);
        P_0[P_tmp] *= rt_powd_snf(-1.0, ((real_T)idxStart + 1.0) - 1.0) * sqrt
          (2.0 * epsb_1980 / theta);
      }

      if ((idxStart + 1 > 1) && (zeta_tmp + 2 == 13)) {
        O_moon = (real_T)(zeta_tmp - idxStart) + 1.0;
        factorial(&O_moon);
        tsince_JD = (tsince + 2.0) - 1.0;
        factorial(&tsince_JD);
        epsb_1980 = rt_powd_snf(-1.0, ((real_T)idxStart + 1.0) - 1.0);
        P_0[P_tmp + 1] *= sqrt(2.0 * O_moon / tsince_JD) * epsb_1980;
        O_moon = ((real_T)(zeta_tmp - idxStart) + 1.0) + 1.0;
        factorial(&O_moon);
        tsince_JD = ((real_T)(zeta_tmp + idxStart) + 3.0) - 1.0;
        factorial(&tsince_JD);
        P_0[P_tmp + 2] *= sqrt(2.0 * O_moon / tsince_JD) * epsb_1980;
      }
    }
  }

  tsince = i - iter;
  factorial(&tsince);
  api = i + iter;
  factorial(&api);
  P_tmp = 14 * iter + i;
  P_0[P_tmp] *= sqrt(2.0 * tsince / api) * rt_powd_snf(-1.0, (real_T)iter);
  api = 0.0;
  z = 0.0;
  epsb_1980 = 0.0;
  for (iter = 0; iter < 12; iter++) {
    u_moon *= M_sun;
    for (i = 0; i <= iter + 1; i++) {
      zeta_tmp = 12 * i + iter;
      O_moon = dg[zeta_tmp] * (eps - 2015.0) + g[zeta_tmp];
      tsince_JD = dh[zeta_tmp] * (eps - 2015.0) + h[zeta_tmp];
      zeta_tmp = 14 * i + iter;
      tsince = P_0[zeta_tmp + 1];
      api -= ((((real_T)iter + 1.0) + 1.0) * D_sun * tsince - sqrt((iter + 2) *
               (iter + 2) - i * i) * M_o * P_0[zeta_tmp + 2]) * ((O_moon * cp[i]
        + tsince_JD * sp[i]) * u_moon);
      z += (O_moon * sp[i] - tsince_JD * cp[i]) * (u_moon * (real_T)i) * tsince;
      epsb_1980 -= (((real_T)iter + 1.0) + 1.0) * u_moon * (O_moon * cp[i] +
        tsince_JD * sp[i]) * tsince;
    }
  }

  M_moon -= deps_1980;
  eps = sin(M_moon);
  D_sun = cos(M_moon);
  rtb_ss_2_body[0] = api * D_sun - epsb_1980 * eps;
  rtb_ss_2_body[1] = M_o * z;
  rtb_ss_2_body[2] = api * eps + epsb_1980 * D_sun;
  for (i = 0; i < 3; i++) {
    /* Product: '<S15>/Matrix Multiply1' */
    rtb_Product2_tmp[i] = 0.0;
    for (iter = 0; iter < 3; iter++) {
      /* Product: '<S15>/Matrix Multiply' incorporates:
       *  Concatenate: '<S5>/Matrix Concatenate2'
       *  Math: '<S15>/Transpose1'
       *  Product: '<S15>/Matrix Multiply1'
       */
      zeta_tmp = i + 3 * iter;
      rtb_mod_to_gcrf[zeta_tmp] = 0.0;
      rtb_mod_to_gcrf[zeta_tmp] += rtb_MatrixConcatenate2[3 * iter] *
        rtb_VectorConcatenate_d[i];
      rtb_mod_to_gcrf[zeta_tmp] += rtb_MatrixConcatenate2[3 * iter + 1] *
        rtb_VectorConcatenate_d[i + 3];
      rtb_mod_to_gcrf[zeta_tmp] += rtb_MatrixConcatenate2[3 * iter + 2] *
        rtb_VectorConcatenate_d[i + 6];

      /* Product: '<S15>/Matrix Multiply1' */
      rtb_Product2_tmp[i] += rtb_mod_to_gcrf[zeta_tmp] * rtb_ss_2_body[iter];
    }

    /* Gain: '<S15>/nT2T' */
    rtb_LLA2ECEF[i] = 1.0E-9 * rtb_Product2_tmp[i];
  }

  /* Trigonometry: '<S152>/Tan1' incorporates:
   *  Gain: '<S152>/deg2rad'
   *  Inport: '<Root>/sun_meas_ss_deg'
   */
  D_sun = tan(0.017453292519943295 * rtU.sun_meas_ss_deg[0]);

  /* Trigonometry: '<S152>/Tan' incorporates:
   *  Gain: '<S152>/deg2rad'
   *  Inport: '<Root>/sun_meas_ss_deg'
   */
  M_moon = tan(0.017453292519943295 * rtU.sun_meas_ss_deg[1]);

  /* Math: '<S157>/Math Function' incorporates:
   *  Constant: '<S157>/Constant'
   *  Math: '<S157>/Square'
   *  Math: '<S157>/Square1'
   *  Sqrt: '<S157>/Sqrt'
   *  Sum: '<S157>/Sum'
   *
   * About '<S157>/Math Function':
   *  Operator: reciprocal
   */
  eps = 1.0 / sqrt((D_sun * D_sun + 1.0) + M_moon * M_moon);

  /* SignalConversion generated from: '<S152>/ss_2_body' incorporates:
   *  Product: '<S152>/Matrix Multiply'
   *  Product: '<S152>/Matrix Multiply1'
   */
  rtb_Multiply2[0] = D_sun * eps;
  rtb_Multiply2[1] = eps * M_moon;

  /* Product: '<S152>/ss_2_body' incorporates:
   *  Constant: '<S152>/Constant1'
   *  SignalConversion generated from: '<S152>/ss_2_body'
   */
  for (i = 0; i < 3; i++) {
    rtb_ss_2_body[i] = rtConstP.Constant1_Value[i + 6] * eps +
      (rtConstP.Constant1_Value[i + 3] * rtb_Multiply2[1] +
       rtConstP.Constant1_Value[i] * rtb_Multiply2[0]);
  }

  /* End of Product: '<S152>/ss_2_body' */
  for (i = 0; i < 5; i++) {
    /* SignalConversion generated from: '<S156>/ SFunction ' incorporates:
     *  Inport: '<Root>/photodiodes_uA'
     *  MATLAB Function: '<S151>/MATLAB Function'
     */
    rtb_YMDHMS_UTC[i] = rtU.photodiodes_uA[i];
  }

  /* SignalConversion generated from: '<S156>/ SFunction ' incorporates:
   *  Constant: '<S151>/Constant13'
   *  MATLAB Function: '<S151>/MATLAB Function'
   */
  rtb_YMDHMS_UTC[5] = 0.0;

  /* MATLAB Function: '<S151>/MATLAB Function' */
  rtb_Gain_a[0] = 0.0;
  rtb_Gain_a[1] = 0.0;
  rtb_Gain_a[2] = 0.0;
  for (zeta_tmp = 0; zeta_tmp < 6; zeta_tmp++) {
    if (rtb_YMDHMS_UTC[zeta_tmp] > 99.760095101689075) {
      rtb_Gain_a[0] += (real_T)normals[3 * zeta_tmp];
      rtb_Gain_a[1] += (real_T)normals[3 * zeta_tmp + 1];
      rtb_Gain_a[2] += (real_T)normals[3 * zeta_tmp + 2];
    }
  }

  rtb_Product2_tmp[0] = rtb_Gain_a[0];
  rtb_Product2_tmp[1] = rtb_Gain_a[1] - -1.0;
  rtb_Product2_tmp[2] = rtb_Gain_a[2];
  if (norm_b(rtb_Product2_tmp) < 1.0E-8) {
    sort(rtb_YMDHMS_UTC, iidx);
    i = (iidx[4] - 1) * 3;
    rtb_Gain_a[0] += (real_T)normals[i];
    rtb_Gain_a[1] += (real_T)normals[i + 1];
    rtb_Gain_a[2] += (real_T)normals[i + 2];
  }

  D_sun = norm_b(rtb_Gain_a);
  if (D_sun < 1.0) {
    rtb_Gain_a[0] = 0.0;
    rtb_Gain_a[1] = 0.0;
    rtb_Gain_a[2] = -1.0;
  } else {
    rtb_Gain_a[0] /= D_sun;
    rtb_Gain_a[1] /= D_sun;
    rtb_Gain_a[2] /= D_sun;
  }

  /* Switch: '<S1>/Switch' */
  if (rtb_Merge > 0) {
    rtb_Switch[0] = rtb_ss_2_body[0];
    rtb_Switch[1] = rtb_ss_2_body[1];
    rtb_Switch[2] = rtb_ss_2_body[2];
  } else {
    rtb_Switch[0] = rtb_Gain_a[0];
    rtb_Switch[1] = rtb_Gain_a[1];
    rtb_Switch[2] = rtb_Gain_a[2];
  }

  /* End of Switch: '<S1>/Switch' */

  /* S-Function (sdspperm2): '<S154>/Variable Selector' incorporates:
   *  Inport: '<Root>/mag_mag_uT'
   *  Product: '<S89>/Multiply2'
   */
  rtb_Multiply2[0] = rtU.mag_mag_uT[0];
  rtb_Multiply2[1] = rtU.mag_mag_uT[1];
  rtb_Multiply2[2] = rtU.mag_mag_uT[2];

  /* Product: '<S154>/Matrix Multiply3' incorporates:
   *  Constant: '<S154>/Constant13'
   *  Product: '<S89>/Multiply2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtConstP.Constant13_Value[i + 6] *
      rtb_Multiply2[2] + (rtConstP.Constant13_Value[i + 3] * rtb_Multiply2[1] +
                          rtConstP.Constant13_Value[i] * rtb_Multiply2[0]);
  }

  /* End of Product: '<S154>/Matrix Multiply3' */

  /* S-Function (sdspperm2): '<S154>/Variable Selector1' incorporates:
   *  Inport: '<Root>/mag_mag_uT'
   *  Product: '<S89>/Multiply2'
   */
  rtb_Multiply2[0] = rtU.mag_mag_uT[3];
  rtb_Multiply2[1] = rtU.mag_mag_uT[4];
  rtb_Multiply2[2] = rtU.mag_mag_uT[5];

  /* Product: '<S154>/Matrix Multiply1' incorporates:
   *  Constant: '<S154>/Constant20'
   *  Product: '<S89>/Multiply2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i + 3] = rtConstP.Constant20_Value[i + 6] *
      rtb_Multiply2[2] + (rtConstP.Constant20_Value[i + 3] * rtb_Multiply2[1] +
                          rtConstP.Constant20_Value[i] * rtb_Multiply2[0]);
  }

  /* End of Product: '<S154>/Matrix Multiply1' */

  /* S-Function (sdspperm2): '<S154>/Variable Selector2' incorporates:
   *  Inport: '<Root>/mag_mag_uT'
   *  Product: '<S89>/Multiply2'
   */
  rtb_Multiply2[0] = rtU.mag_mag_uT[6];
  rtb_Multiply2[1] = rtU.mag_mag_uT[7];
  rtb_Multiply2[2] = rtU.mag_mag_uT[8];

  /* Product: '<S154>/Matrix Multiply2' incorporates:
   *  Constant: '<S154>/Constant22'
   *  Product: '<S89>/Multiply2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i + 6] = rtConstP.Constant22_Value[i + 6] *
      rtb_Multiply2[2] + (rtConstP.Constant22_Value[i + 3] * rtb_Multiply2[1] +
                          rtConstP.Constant22_Value[i] * rtb_Multiply2[0]);
  }

  /* End of Product: '<S154>/Matrix Multiply2' */

  /* S-Function (sdspmdn2): '<S154>/Median' incorporates:
   *  Concatenate: '<S154>/Vector Concatenate'
   *  Product: '<S89>/Multiply2'
   */
  zeta_tmp = 0;
  for (i = 0; i < 3; i++) {
    i0 = rtDW.Median_Index_e[0];
    eps = rtb_VectorConcatenate_d[rtDW.Median_Index_e[0] + i];
    i1 = rtDW.Median_Index_e[1U];
    M_moon = rtb_VectorConcatenate_d[rtDW.Median_Index_e[1U] + i];
    if (eps > M_moon) {
      rtDW.Median_Index_e[1U] = rtDW.Median_Index_e[0];
      rtDW.Median_Index_e[0U] = i1;
    } else {
      eps = M_moon;
      i0 = rtDW.Median_Index_e[1U];
    }

    i1 = rtDW.Median_Index_e[2U];
    M_moon = rtb_VectorConcatenate_d[rtDW.Median_Index_e[2U] + i];
    if (eps > M_moon) {
      rtDW.Median_Index_e[2U] = i0;
      iter = 2;
      if (rtb_VectorConcatenate_d[rtDW.Median_Index_e[0U] + i] > M_moon) {
        rtDW.Median_Index_e[1U] = rtDW.Median_Index_e[0U];
        iter = 1;
      } else {
        /* set loop index to break loop */
      }

      rtDW.Median_Index_e[iter - 1U] = i1;
    }

    rtb_Multiply2[zeta_tmp] = rtb_VectorConcatenate_d[rtDW.Median_Index_e[1] + i];
    zeta_tmp++;
  }

  /* End of S-Function (sdspmdn2): '<S154>/Median' */

  /* Outputs for Atomic SubSystem: '<S1>/TriadAlgorithm' */
  /* SignalConversion generated from: '<S5>/Matrix Concatenate2' */
  rtb_MatrixConcatenate2[0] = rtb_Switch[0];

  /* End of Outputs for SubSystem: '<S1>/TriadAlgorithm' */

  /* Gain: '<S154>/Gain' incorporates:
   *  Product: '<S89>/Multiply2'
   */
  rtb_Multiply2[0] *= 1.0E-6;

  /* Outputs for Atomic SubSystem: '<S1>/TriadAlgorithm' */
  /* SignalConversion generated from: '<S5>/Matrix Concatenate2' */
  rtb_MatrixConcatenate2[1] = rtb_Switch[1];

  /* End of Outputs for SubSystem: '<S1>/TriadAlgorithm' */

  /* Gain: '<S154>/Gain' incorporates:
   *  Product: '<S89>/Multiply2'
   */
  rtb_Multiply2[1] *= 1.0E-6;
  M_moon = 1.0E-6 * rtb_Multiply2[2];

  /* Outputs for Atomic SubSystem: '<S1>/TriadAlgorithm' */
  /* SignalConversion generated from: '<S5>/Matrix Concatenate2' */
  rtb_MatrixConcatenate2[2] = rtb_Switch[2];

  /* Product: '<S43>/Element product' incorporates:
   *  Product: '<S46>/Element product'
   */
  rtb_YMDHMS_UTC[1] = rtb_Switch[2] * rtb_Multiply2[0];
  rtb_YMDHMS_UTC[2] = rtb_Switch[0] * rtb_Multiply2[1];
  rtb_YMDHMS_UTC[5] = rtb_Switch[1] * rtb_Multiply2[0];

  /* Sum: '<S43>/Add3' incorporates:
   *  Product: '<S43>/Element product'
   */
  rtb_Multiply2[0] = rtb_Switch[1] * M_moon - rtb_Switch[2] * rtb_Multiply2[1];
  rtb_Multiply2[1] = rtb_YMDHMS_UTC[1] - rtb_Switch[0] * M_moon;
  rtb_Multiply2[2] = rtb_YMDHMS_UTC[2] - rtb_YMDHMS_UTC[5];

  /* S-Function (sdsp2norm2): '<S5>/Normalization6' */
  D_sun = 1.0 / (sqrt((rtb_Multiply2[0] * rtb_Multiply2[0] + rtb_Multiply2[1] *
                       rtb_Multiply2[1]) + rtb_Multiply2[2] * rtb_Multiply2[2])
                 + 1.0E-10);
  rtb_Multiply2[0] *= D_sun;
  rtb_Multiply2[1] *= D_sun;
  rtb_Multiply2[2] *= D_sun;

  /* SignalConversion generated from: '<S5>/Matrix Concatenate2' */
  rtb_MatrixConcatenate2[3] = rtb_Multiply2[0];

  /* SignalConversion generated from: '<S5>/Matrix Concatenate3' */
  rtb_MathFunction1[0] = rtb_AU2KM[0];

  /* Sum: '<S45>/Add3' incorporates:
   *  Product: '<S45>/Element product'
   */
  rtb_pos_teme_km[0] = rtb_AU2KM[1] * rtb_LLA2ECEF[2] - rtb_AU2KM[2] *
    rtb_LLA2ECEF[1];

  /* SignalConversion generated from: '<S5>/Matrix Concatenate2' */
  rtb_MatrixConcatenate2[4] = rtb_Multiply2[1];

  /* SignalConversion generated from: '<S5>/Matrix Concatenate3' */
  rtb_MathFunction1[1] = rtb_AU2KM[1];

  /* Sum: '<S45>/Add3' incorporates:
   *  Product: '<S45>/Element product'
   */
  rtb_pos_teme_km[1] = rtb_AU2KM[2] * rtb_LLA2ECEF[0] - rtb_AU2KM[0] *
    rtb_LLA2ECEF[2];

  /* SignalConversion generated from: '<S5>/Matrix Concatenate2' */
  rtb_MatrixConcatenate2[5] = rtb_Multiply2[2];

  /* SignalConversion generated from: '<S5>/Matrix Concatenate3' */
  rtb_MathFunction1[2] = rtb_AU2KM[2];

  /* Sum: '<S45>/Add3' incorporates:
   *  Product: '<S45>/Element product'
   */
  rtb_pos_teme_km[2] = rtb_AU2KM[0] * rtb_LLA2ECEF[1] - rtb_AU2KM[1] *
    rtb_LLA2ECEF[0];

  /* S-Function (sdsp2norm2): '<S5>/Normalization7' */
  D_sun = 1.0 / (sqrt((rtb_pos_teme_km[0] * rtb_pos_teme_km[0] +
                       rtb_pos_teme_km[1] * rtb_pos_teme_km[1]) +
                      rtb_pos_teme_km[2] * rtb_pos_teme_km[2]) + 1.0E-10);
  rtb_pos_teme_km[0] *= D_sun;
  rtb_pos_teme_km[1] *= D_sun;
  rtb_pos_teme_km[2] *= D_sun;

  /* SignalConversion generated from: '<S5>/Matrix Concatenate3' */
  rtb_MathFunction1[3] = rtb_pos_teme_km[0];

  /* Sum: '<S44>/Add3' incorporates:
   *  Product: '<S44>/Element product'
   */
  rtb_MatrixConcatenate2[6] = rtb_Switch[1] * rtb_Multiply2[2] - rtb_Switch[2] *
    rtb_Multiply2[1];

  /* SignalConversion generated from: '<S5>/Matrix Concatenate3' */
  rtb_MathFunction1[4] = rtb_pos_teme_km[1];

  /* Sum: '<S44>/Add3' incorporates:
   *  Product: '<S44>/Element product'
   */
  rtb_MatrixConcatenate2[7] = rtb_Switch[2] * rtb_Multiply2[0] - rtb_Switch[0] *
    rtb_Multiply2[2];

  /* SignalConversion generated from: '<S5>/Matrix Concatenate3' */
  rtb_MathFunction1[5] = rtb_pos_teme_km[2];

  /* Sum: '<S44>/Add3' incorporates:
   *  Product: '<S44>/Element product'
   */
  rtb_MatrixConcatenate2[8] = rtb_Switch[0] * rtb_Multiply2[1] - rtb_Switch[1] *
    rtb_Multiply2[0];

  /* Sum: '<S46>/Add3' incorporates:
   *  Product: '<S46>/Element product'
   */
  rtb_MathFunction1[6] = rtb_AU2KM[1] * rtb_pos_teme_km[2] - rtb_AU2KM[2] *
    rtb_pos_teme_km[1];
  rtb_MathFunction1[7] = rtb_AU2KM[2] * rtb_pos_teme_km[0] - rtb_AU2KM[0] *
    rtb_pos_teme_km[2];
  rtb_MathFunction1[8] = rtb_AU2KM[0] * rtb_pos_teme_km[1] - rtb_AU2KM[1] *
    rtb_pos_teme_km[0];

  /* Math: '<S5>/Math Function1' */
  for (i = 0; i < 3; i++) {
    rtb_mod_to_gcrf[3 * i] = rtb_MathFunction1[i];
    rtb_mod_to_gcrf[3 * i + 1] = rtb_MathFunction1[i + 3];
    rtb_mod_to_gcrf[3 * i + 2] = rtb_MathFunction1[i + 6];
  }

  memcpy(&rtb_MathFunction1[0], &rtb_mod_to_gcrf[0], 9U * sizeof(real_T));

  /* End of Math: '<S5>/Math Function1' */

  /* Product: '<S5>/Matrix Multiply1' incorporates:
   *  Concatenate: '<S5>/Matrix Concatenate2'
   *  Math: '<S5>/Math Function1'
   */
  for (i = 0; i < 3; i++) {
    for (iter = 0; iter < 3; iter++) {
      zeta_tmp = iter + 3 * i;
      rtb_mod_to_gcrf[zeta_tmp] = 0.0;
      rtb_mod_to_gcrf[zeta_tmp] += rtb_MathFunction1[3 * i] *
        rtb_MatrixConcatenate2[iter];
      rtb_mod_to_gcrf[zeta_tmp] += rtb_MathFunction1[3 * i + 1] *
        rtb_MatrixConcatenate2[iter + 3];
      rtb_mod_to_gcrf[zeta_tmp] += rtb_MathFunction1[3 * i + 2] *
        rtb_MatrixConcatenate2[iter + 6];
    }
  }

  /* End of Product: '<S5>/Matrix Multiply1' */

  /* Sum: '<S51>/Add' */
  M_moon = (rtb_mod_to_gcrf[0] + rtb_mod_to_gcrf[4]) + rtb_mod_to_gcrf[8];

  /* If: '<S47>/If' */
  if (M_moon > 0.0) {
    /* Outputs for IfAction SubSystem: '<S47>/Positive Trace' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    PositiveTrace(M_moon, rtb_mod_to_gcrf, &rtDW.Merge_l[0], &rtDW.Merge_l[1]);

    /* End of Outputs for SubSystem: '<S47>/Positive Trace' */
  } else {
    /* Outputs for IfAction SubSystem: '<S47>/Negative Trace' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    NegativeTrace(rtb_mod_to_gcrf, rtDW.Merge_l);

    /* End of Outputs for SubSystem: '<S47>/Negative Trace' */
  }

  /* End of If: '<S47>/If' */

  /* Signum: '<S5>/Sign' */
  if (rtDW.Merge_l[0] < 0.0) {
    eps = -1.0;
  } else if (rtDW.Merge_l[0] > 0.0) {
    eps = 1.0;
  } else if (rtDW.Merge_l[0] == 0.0) {
    eps = 0.0;
  } else {
    eps = (rtNaN);
  }

  /* End of Signum: '<S5>/Sign' */

  /* Product: '<S5>/Multiply' */
  rtb_DiscreteTimeIntegrator[0] = eps * rtDW.Merge_l[0];
  rtb_DiscreteTimeIntegrator[1] = eps * rtDW.Merge_l[1];
  rtb_DiscreteTimeIntegrator[2] = eps * rtDW.Merge_l[2];
  rtb_DiscreteTimeIntegrator[3] = eps * rtDW.Merge_l[3];

  /* End of Outputs for SubSystem: '<S1>/TriadAlgorithm' */

  /* Sum: '<S6>/Sum1' incorporates:
   *  S-Function (sdspmdn2): '<S153>/Median'
   */
  rtb_pos_teme_km[0] = 0.0 - rtb_Median[0];
  rtb_pos_teme_km[1] = 0.0 - rtb_Median[1];
  rtb_pos_teme_km[2] = 0.0 - rtb_Median[2];

  /* Outputs for Atomic SubSystem: '<S6>/quat_err_lib' */
  /* Outport: '<Root>/cmd_quat' */
  quat_err_lib(rtY.cmd_quat, rtb_DiscreteTimeIntegrator, rtb_Multiply_i);

  /* End of Outputs for SubSystem: '<S6>/quat_err_lib' */

  /* Gain: '<S6>/RPM2Radps' incorporates:
   *  Inport: '<Root>/rwa_rpm'
   *  RateTransition generated from: '<S1>/Rate Transition3'
   */
  rtb_RPM2Radps[0] = 0.10471975511965977 * rtU.rwa_rpm[0];
  rtb_RPM2Radps[1] = 0.10471975511965977 * rtU.rwa_rpm[1];
  rtb_RPM2Radps[2] = 0.10471975511965977 * rtU.rwa_rpm[2];
  rtb_RPM2Radps[3] = 0.10471975511965977 * rtU.rwa_rpm[3];

  /* SwitchCase: '<S87>/Switch Case' incorporates:
   *  Outport: '<Root>/gnc_mode'
   */
  switch (rtY.gnc_mode) {
   case 0:
   case 1:
   case 2:
   case 4:
    /* Outputs for IfAction SubSystem: '<S87>/case_null_control' incorporates:
     *  ActionPort: '<S95>/Action Port'
     */
    /* Merge: '<S87>/Merge1' incorporates:
     *  SignalConversion generated from: '<S95>/null_MTQ_cmd_Am2'
     */
    rtDW.Merge1[0] = 0.0;

    /* Merge: '<S87>/Merge' incorporates:
     *  SignalConversion generated from: '<S95>/null_RWA_cmd_Nm'
     */
    rtDW.Merge[0] = 0.0;

    /* Merge: '<S87>/Merge1' incorporates:
     *  SignalConversion generated from: '<S95>/null_MTQ_cmd_Am2'
     */
    rtDW.Merge1[1] = 0.0;

    /* Merge: '<S87>/Merge' incorporates:
     *  SignalConversion generated from: '<S95>/null_RWA_cmd_Nm'
     */
    rtDW.Merge[1] = 0.0;

    /* Merge: '<S87>/Merge1' incorporates:
     *  SignalConversion generated from: '<S95>/null_MTQ_cmd_Am2'
     */
    rtDW.Merge1[2] = 0.0;

    /* Merge: '<S87>/Merge' incorporates:
     *  SignalConversion generated from: '<S95>/null_RWA_cmd_Nm'
     */
    rtDW.Merge[2] = 0.0;

    /* End of Outputs for SubSystem: '<S87>/case_null_control' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S87>/case_asm' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S93>/asmController_lib' */
    asmController_lib(rtb_pos_teme_km, rtDW.Merge);

    /* End of Outputs for SubSystem: '<S93>/asmController_lib' */

    /* Sum: '<S100>/Sum of Elements' incorporates:
     *  Math: '<S100>/Math Function'
     */
    rtb_Sqrt_c = rtb_LLA2ECEF[0] * rtb_LLA2ECEF[0];
    rtb_Sqrt_c += rtb_LLA2ECEF[1] * rtb_LLA2ECEF[1];
    rtb_Sqrt_c += rtb_LLA2ECEF[2] * rtb_LLA2ECEF[2];

    /* Math: '<S100>/Math Function1'
     *
     * About '<S100>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Sqrt_c < 0.0) {
      rtb_Sqrt_c = -sqrt(fabs(rtb_Sqrt_c));
    } else {
      rtb_Sqrt_c = sqrt(rtb_Sqrt_c);
    }

    /* End of Math: '<S100>/Math Function1' */

    /* Switch: '<S100>/Switch' incorporates:
     *  Constant: '<S100>/Constant'
     *  Product: '<S100>/Product'
     */
    if (rtb_Sqrt_c > 0.0) {
      rtb_Switch_g[0] = rtb_LLA2ECEF[0];
      rtb_Switch_g[1] = rtb_LLA2ECEF[1];
      rtb_Switch_g[2] = rtb_LLA2ECEF[2];
      rtb_Switch_g[3] = rtb_Sqrt_c;
    } else {
      rtb_Switch_g[0] = rtb_LLA2ECEF[0] * 0.0;
      rtb_Switch_g[1] = rtb_LLA2ECEF[1] * 0.0;
      rtb_Switch_g[2] = rtb_LLA2ECEF[2] * 0.0;
      rtb_Switch_g[3] = 1.0;
    }

    /* End of Switch: '<S100>/Switch' */

    /* Product: '<S100>/Divide' */
    rtb_pos_teme_km[0] = rtb_Switch_g[0] / rtb_Switch_g[3];
    rtb_pos_teme_km[1] = rtb_Switch_g[1] / rtb_Switch_g[3];
    rtb_pos_teme_km[2] = rtb_Switch_g[2] / rtb_Switch_g[3];

    /* Product: '<S101>/Matrix Multiply1' incorporates:
     *  Constant: '<S101>/A_wheel2body '
     *  S-Function (sdspdiag2): '<S101>/Create Diagonal Matrix'
     */
    for (i = 0; i < 4; i++) {
      M_moon = rtConstB.CreateDiagonalMatrix_e[i + 12] * rtb_RPM2Radps[3] +
        (rtConstB.CreateDiagonalMatrix_e[i + 8] * rtb_RPM2Radps[2] +
         (rtConstB.CreateDiagonalMatrix_e[i + 4] * rtb_RPM2Radps[1] +
          rtConstB.CreateDiagonalMatrix_e[i] * rtb_RPM2Radps[0]));
      rtb_Switch_g[i] = M_moon;
    }

    for (i = 0; i < 3; i++) {
      M_moon = rtConstP.pooled13[i + 9] * rtb_Switch_g[3] + (rtConstP.pooled13[i
        + 6] * rtb_Switch_g[2] + (rtConstP.pooled13[i + 3] * rtb_Switch_g[1] +
        rtConstP.pooled13[i] * rtb_Switch_g[0]));

      /* Sum: '<S101>/Subtract1' incorporates:
       *  Constant: '<S101>/A_wheel2body '
       *  Constant: '<S101>/scParams.J '
       *  Product: '<S101>/Matrix Multiply'
       *  S-Function (sdspmdn2): '<S153>/Median'
       *  Sum: '<S105>/Add3'
       */
      rtb_Multiply2[i] = (rtConstB.h_w_nom_body_Nms_m[i] - M_moon) -
        ((rtConstP.pooled16[i + 3] * rtb_Median[1] + rtConstP.pooled16[i] *
          rtb_Median[0]) + rtConstP.pooled16[i + 6] * rtb_Median[2]);
    }

    /* End of Product: '<S101>/Matrix Multiply1' */

    /* Outputs for Atomic SubSystem: '<S99>/twonorm' */
    rtb_Sqrt_c = twonorm_m(rtb_LLA2ECEF);

    /* End of Outputs for SubSystem: '<S99>/twonorm' */

    /* Sum: '<S105>/Add3' incorporates:
     *  Product: '<S105>/Element product'
     */
    M_moon = rtb_Multiply2[1] * rtb_pos_teme_km[2] - rtb_Multiply2[2] *
      rtb_pos_teme_km[1];
    api = rtb_Multiply2[2] * rtb_pos_teme_km[0] - rtb_Multiply2[0] *
      rtb_pos_teme_km[2];
    z = rtb_Multiply2[0] * rtb_pos_teme_km[1] - rtb_Multiply2[1] *
      rtb_pos_teme_km[0];
    for (i = 0; i < 3; i++) {
      /* Merge: '<S87>/Merge1' incorporates:
       *  Gain: '<S103>/Gain'
       *  Gain: '<S103>/Gain3'
       *  Product: '<S103>/Divide'
       */
      rtDW.Merge1[i] = -(rtConstP.pooled17[i + 6] * z + (rtConstP.pooled17[i + 3]
        * api + rtConstP.pooled17[i] * M_moon)) / rtb_Sqrt_c;
    }

    /* End of Outputs for SubSystem: '<S87>/case_asm' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S87>/case_sunseek' incorporates:
     *  ActionPort: '<S97>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S97>/sunSeek_lib' */
    sunSeek_lib(rtb_Merge, rtb_Gain_a, rtb_ss_2_body, rtb_pos_teme_km,
                rtDW.Merge);

    /* End of Outputs for SubSystem: '<S97>/sunSeek_lib' */

    /* Merge: '<S87>/Merge1' incorporates:
     *  SignalConversion generated from: '<S97>/sunseek_MTQ_cmd_Am2'
     */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* End of Outputs for SubSystem: '<S87>/case_sunseek' */
    break;

   case 6:
   case 7:
   case 8:
    /* Outputs for IfAction SubSystem: '<S87>/case_desaturation' incorporates:
     *  ActionPort: '<S94>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S94>/PD_Controller_Lib' */
    PD_Controller_Lib(rtb_Multiply_i, rtb_pos_teme_km, rtDW.Merge);

    /* End of Outputs for SubSystem: '<S94>/PD_Controller_Lib' */

    /* Sum: '<S108>/Sum of Elements' incorporates:
     *  Math: '<S108>/Math Function'
     */
    rtb_Sqrt_c = rtb_LLA2ECEF[0] * rtb_LLA2ECEF[0];
    rtb_Sqrt_c += rtb_LLA2ECEF[1] * rtb_LLA2ECEF[1];
    rtb_Sqrt_c += rtb_LLA2ECEF[2] * rtb_LLA2ECEF[2];

    /* Math: '<S108>/Math Function1'
     *
     * About '<S108>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Sqrt_c < 0.0) {
      rtb_Sqrt_c = -sqrt(fabs(rtb_Sqrt_c));
    } else {
      rtb_Sqrt_c = sqrt(rtb_Sqrt_c);
    }

    /* End of Math: '<S108>/Math Function1' */

    /* Switch: '<S108>/Switch' incorporates:
     *  Constant: '<S108>/Constant'
     *  Product: '<S108>/Product'
     */
    if (rtb_Sqrt_c > 0.0) {
      rtb_Switch_g[0] = rtb_LLA2ECEF[0];
      rtb_Switch_g[1] = rtb_LLA2ECEF[1];
      rtb_Switch_g[2] = rtb_LLA2ECEF[2];
      rtb_Switch_g[3] = rtb_Sqrt_c;
    } else {
      rtb_Switch_g[0] = rtb_LLA2ECEF[0] * 0.0;
      rtb_Switch_g[1] = rtb_LLA2ECEF[1] * 0.0;
      rtb_Switch_g[2] = rtb_LLA2ECEF[2] * 0.0;
      rtb_Switch_g[3] = 1.0;
    }

    /* End of Switch: '<S108>/Switch' */

    /* Product: '<S108>/Divide' */
    rtb_pos_teme_km[0] = rtb_Switch_g[0] / rtb_Switch_g[3];
    rtb_pos_teme_km[1] = rtb_Switch_g[1] / rtb_Switch_g[3];
    rtb_pos_teme_km[2] = rtb_Switch_g[2] / rtb_Switch_g[3];

    /* Product: '<S109>/Matrix Multiply1' incorporates:
     *  Constant: '<S109>/A_wheel2body '
     *  S-Function (sdspdiag2): '<S109>/Create Diagonal Matrix'
     */
    for (i = 0; i < 4; i++) {
      M_moon = rtConstB.CreateDiagonalMatrix[i + 12] * rtb_RPM2Radps[3] +
        (rtConstB.CreateDiagonalMatrix[i + 8] * rtb_RPM2Radps[2] +
         (rtConstB.CreateDiagonalMatrix[i + 4] * rtb_RPM2Radps[1] +
          rtConstB.CreateDiagonalMatrix[i] * rtb_RPM2Radps[0]));
      rtb_Switch_g[i] = M_moon;
    }

    for (i = 0; i < 3; i++) {
      M_moon = rtConstP.pooled13[i + 9] * rtb_Switch_g[3] + (rtConstP.pooled13[i
        + 6] * rtb_Switch_g[2] + (rtConstP.pooled13[i + 3] * rtb_Switch_g[1] +
        rtConstP.pooled13[i] * rtb_Switch_g[0]));

      /* Sum: '<S109>/Subtract1' incorporates:
       *  Constant: '<S109>/A_wheel2body '
       *  Constant: '<S109>/scParams.J '
       *  Product: '<S109>/Matrix Multiply'
       *  S-Function (sdspmdn2): '<S153>/Median'
       *  Sum: '<S113>/Add3'
       */
      rtb_Multiply2[i] = (rtConstB.h_w_nom_body_Nms[i] - M_moon) -
        ((rtConstP.pooled16[i + 3] * rtb_Median[1] + rtConstP.pooled16[i] *
          rtb_Median[0]) + rtConstP.pooled16[i + 6] * rtb_Median[2]);
    }

    /* End of Product: '<S109>/Matrix Multiply1' */

    /* Outputs for Atomic SubSystem: '<S107>/twonorm' */
    rtb_Sqrt_c = twonorm_m(rtb_LLA2ECEF);

    /* End of Outputs for SubSystem: '<S107>/twonorm' */

    /* Sum: '<S113>/Add3' incorporates:
     *  Product: '<S113>/Element product'
     */
    M_moon = rtb_Multiply2[1] * rtb_pos_teme_km[2] - rtb_Multiply2[2] *
      rtb_pos_teme_km[1];
    api = rtb_Multiply2[2] * rtb_pos_teme_km[0] - rtb_Multiply2[0] *
      rtb_pos_teme_km[2];
    z = rtb_Multiply2[0] * rtb_pos_teme_km[1] - rtb_Multiply2[1] *
      rtb_pos_teme_km[0];
    for (i = 0; i < 3; i++) {
      /* Merge: '<S87>/Merge1' incorporates:
       *  Gain: '<S111>/Gain'
       *  Gain: '<S111>/Gain3'
       *  Product: '<S111>/Divide'
       */
      rtDW.Merge1[i] = -(rtConstP.pooled17[i + 6] * z + (rtConstP.pooled17[i + 3]
        * api + rtConstP.pooled17[i] * M_moon)) / rtb_Sqrt_c;
    }

    /* End of Outputs for SubSystem: '<S87>/case_desaturation' */
    break;

   case 9:
    /* Outputs for IfAction SubSystem: '<S87>/case_reorientation' incorporates:
     *  ActionPort: '<S96>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S96>/PD_Controller_Lib' */
    PD_Controller_Lib(rtb_Multiply_i, rtb_pos_teme_km, rtDW.Merge);

    /* End of Outputs for SubSystem: '<S96>/PD_Controller_Lib' */

    /* Merge: '<S87>/Merge1' incorporates:
     *  SignalConversion generated from: '<S96>/tracking_MTQ_cmd_Am2'
     */
    rtDW.Merge1[0] = 0.0;
    rtDW.Merge1[1] = 0.0;
    rtDW.Merge1[2] = 0.0;

    /* End of Outputs for SubSystem: '<S87>/case_reorientation' */
    break;
  }

  /* End of SwitchCase: '<S87>/Switch Case' */

  /* Outputs for IfAction SubSystem: '<S89>/If Action Subsystem' incorporates:
   *  ActionPort: '<S120>/Action Port'
   */
  /* If: '<S89>/If' */
  IfActionSubsystem(&eps);

  /* End of Outputs for SubSystem: '<S89>/If Action Subsystem' */

  /* Outputs for IfAction SubSystem: '<S89>/If Action Subsystem3' incorporates:
   *  ActionPort: '<S123>/Action Port'
   */
  /* If: '<S89>/If1' */
  IfActionSubsystem(&M_moon);

  /* End of Outputs for SubSystem: '<S89>/If Action Subsystem3' */

  /* Sum: '<S6>/Sum' incorporates:
   *  Merge: '<S87>/Merge'
   */
  rtb_LLA2ECEF[0] = rtDW.Merge[0];
  rtb_LLA2ECEF[1] = rtDW.Merge[1];
  rtb_LLA2ECEF[2] = rtDW.Merge[2];

  /* Outputs for Atomic SubSystem: '<S6>/rwa_allocation_lib' */
  /* Constant: '<S1>/Constant20' */
  rwa_allocation_lib(rtb_LLA2ECEF, rtb_RPM2Radps, rtConstP.Constant20_Value_b,
                     rtb_Switch_g, &rtConstB.rwa_allocation_lib_m,
                     &rtDW.rwa_allocation_lib_m);

  /* End of Outputs for SubSystem: '<S6>/rwa_allocation_lib' */

  /* Gain: '<S92>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S92>/Discrete-Time Integrator'
   *  Product: '<S92>/Product'
   */
  api = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[0] *
    9.5492965855137211;

  /* Saturate: '<S92>/Saturation' */
  if (api > 6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[0] = 6500.0;
  } else if (api < -6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[0] = -6500.0;
  } else {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[0] = api;
  }

  /* Gain: '<S92>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S92>/Discrete-Time Integrator'
   *  Product: '<S92>/Product'
   */
  api = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[1] *
    9.5492965855137211;

  /* Saturate: '<S92>/Saturation' */
  if (api > 6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[1] = 6500.0;
  } else if (api < -6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[1] = -6500.0;
  } else {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[1] = api;
  }

  /* Gain: '<S92>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S92>/Discrete-Time Integrator'
   *  Product: '<S92>/Product'
   */
  api = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[2] *
    9.5492965855137211;

  /* Saturate: '<S92>/Saturation' */
  if (api > 6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[2] = 6500.0;
  } else if (api < -6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[2] = -6500.0;
  } else {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[2] = api;
  }

  /* Gain: '<S92>/radps_2_rpm' incorporates:
   *  DiscreteIntegrator: '<S92>/Discrete-Time Integrator'
   *  Product: '<S92>/Product'
   */
  api = 33868.4549210865 * rtDW.DiscreteTimeIntegrator_DSTATE[3] *
    9.5492965855137211;

  /* Saturate: '<S92>/Saturation' */
  if (api > 6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[3] = 6500.0;
  } else if (api < -6500.0) {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[3] = -6500.0;
  } else {
    /* Outport: '<Root>/rwa_cmd_rpm' */
    rtY.rwa_cmd_rpm[3] = api;
  }

  /* Product: '<S89>/Multiply2' */
  rtb_Multiply2[0] = rtDW.Merge1[0] * eps;
  rtb_Multiply2[1] = rtDW.Merge1[1] * M_moon;

  /* Outport: '<Root>/mtq_cmd_Am2' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Product: '<S89>/Multiply'
   *  Product: '<S89>/Multiply2'
   */
  rtY.mtq_cmd_Am2[0] = -(rtb_Multiply2[0] * 0.5);
  rtY.mtq_cmd_Am2[1] = -(rtb_Multiply2[0] * -0.5);
  rtY.mtq_cmd_Am2[3] = -(rtb_Multiply2[1] * -0.5);
  rtY.mtq_cmd_Am2[2] = -(rtb_Multiply2[1] * 0.5);
  rtY.mtq_cmd_Am2[4] = -(rtDW.Merge1[2] * rtConstB.Switch);

  /* Outport: '<Root>/sc_quat' */
  rtY.sc_quat[0] = rtb_DiscreteTimeIntegrator[0];
  rtY.sc_quat[1] = rtb_DiscreteTimeIntegrator[1];
  rtY.sc_quat[2] = rtb_DiscreteTimeIntegrator[2];
  rtY.sc_quat[3] = rtb_DiscreteTimeIntegrator[3];

  /* Outport: '<Root>/sc_body_rates_radps' */
  rtY.sc_body_rates_radps[0] = rtb_Median[0];

  /* Outport: '<Root>/cmd_body_rates_radps' */
  rtY.cmd_body_rates_radps[0] = 0.0;

  /* Outport: '<Root>/sc_body_rates_radps' */
  rtY.sc_body_rates_radps[1] = rtb_Median[1];

  /* Outport: '<Root>/cmd_body_rates_radps' */
  rtY.cmd_body_rates_radps[1] = 0.0;

  /* Outport: '<Root>/sc_body_rates_radps' */
  rtY.sc_body_rates_radps[2] = rtb_Median[2];

  /* Outport: '<Root>/cmd_body_rates_radps' */
  rtY.cmd_body_rates_radps[2] = 0.0;

  /* Outport: '<Root>/mekf_3sigma_rad' */
  for (i = 0; i < 6; i++) {
    rtY.mekf_3sigma_rad[i] = 0.0;
  }

  /* End of Outport: '<Root>/mekf_3sigma_rad' */

  /* Outport: '<Root>/mekf_telem' incorporates:
   *  Constant: '<S1>/Constant15'
   */
  rtY.mekf_telem = 0U;

  /* Outport: '<Root>/mekf_bias_radps' */
  rtY.mekf_bias_radps[0] = 0.0;

  /* Outport: '<Root>/r_eci_m' */
  rtY.r_eci_m[0] = rtb_Gain2[0];

  /* Outport: '<Root>/mekf_bias_radps' */
  rtY.mekf_bias_radps[1] = 0.0;

  /* Outport: '<Root>/r_eci_m' */
  rtY.r_eci_m[1] = rtb_Gain2[1];

  /* Outport: '<Root>/mekf_bias_radps' */
  rtY.mekf_bias_radps[2] = 0.0;

  /* Outport: '<Root>/r_eci_m' */
  rtY.r_eci_m[2] = rtb_Gain2[2];

  /* Saturate: '<S88>/Saturation' */
  if (rtb_Multiply_i[0] > 1.0) {
    M_moon = 1.0;
  } else if (rtb_Multiply_i[0] < -1.0) {
    M_moon = -1.0;
  } else {
    M_moon = rtb_Multiply_i[0];
  }

  /* End of Saturate: '<S88>/Saturation' */

  /* Outport: '<Root>/ace_err' incorporates:
   *  Abs: '<S88>/Abs'
   *  Gain: '<S88>/Gain'
   *  Gain: '<S88>/RAD2DEG'
   *  Trigonometry: '<S88>/Acos'
   */
  rtY.ace_err = fabs(2.0 * acos(M_moon) * 57.295779513082323);

  /* Outport: '<Root>/eclipse' */
  rtY.eclipse = lowAlt;

  /* Outport: '<Root>/sgp4_flag' incorporates:
   *  Constant: '<S1>/Constant6'
   */
  rtY.sgp4_flag = 0U;

  /* Outport: '<Root>/sc_above_gs' incorporates:
   *  Constant: '<S1>/Constant8'
   */
  rtY.sc_above_gs = false;

  /* Outport: '<Root>/target_gen_flag' incorporates:
   *  Constant: '<S1>/Constant10'
   */
  rtY.target_gen_flag = 0U;

  /* Outport: '<Root>/elev_gs_rad' incorporates:
   *  Constant: '<S1>/Constant11'
   */
  rtY.elev_gs_rad = 0.0;

  /* Outport: '<Root>/elev_targ_rad' incorporates:
   *  Constant: '<S1>/Constant12'
   */
  rtY.elev_targ_rad = 0.0;

  /* Outport: '<Root>/ss_valid' */
  rtY.ss_valid = rtb_Merge;

  /* Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[0] += 0.25 * rtb_Switch_g[0];
  rtDW.DiscreteTimeIntegrator_DSTATE[1] += 0.25 * rtb_Switch_g[1];
  rtDW.DiscreteTimeIntegrator_DSTATE[2] += 0.25 * rtb_Switch_g[2];
  rtDW.DiscreteTimeIntegrator_DSTATE[3] += 0.25 * rtb_Switch_g[3];
}

/* Model initialize function */
void FSW_Lib_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for S-Function (sdspmdn2): '<S153>/Median' */
  rtDW.Median_Index[0] = 0U;
  rtDW.Median_Index[1] = 3U;
  rtDW.Median_Index[2] = 6U;

  /* InitializeConditions for S-Function (sdspmdn2): '<S154>/Median' */
  rtDW.Median_Index_e[0] = 0U;
  rtDW.Median_Index_e[1] = 3U;
  rtDW.Median_Index_e[2] = 6U;

  /* InitializeConditions for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE[0] = 0.0030919554896630744;
  rtDW.DiscreteTimeIntegrator_DSTATE[1] = -0.0030919554896630744;
  rtDW.DiscreteTimeIntegrator_DSTATE[2] = 0.0030919554896630744;
  rtDW.DiscreteTimeIntegrator_DSTATE[3] = -0.0030919554896630744;

  /* SystemInitialize for Atomic SubSystem: '<S1>/target_generation_lib' */
  target_generation_lib_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/target_generation_lib' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/TriadAlgorithm' */
  /* SystemInitialize for Merge: '<S47>/Merge' */
  rtDW.Merge_l[0] = 1.0;
  rtDW.Merge_l[1] = 0.0;
  rtDW.Merge_l[2] = 0.0;
  rtDW.Merge_l[3] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S1>/TriadAlgorithm' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
