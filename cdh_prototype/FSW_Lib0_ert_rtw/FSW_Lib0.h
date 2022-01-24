/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib0.h
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jan 14 15:17:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FSW_Lib0_h_
#define RTW_HEADER_FSW_Lib0_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Child system includes */
#include "MEKF_lib.h"
#include "PD_Controller_Lib.h"
#include "asmController_lib.h"
#include "maggyroProcessing_lib.h"
#include "mode_select_lib.h"
#include "null_control_lib.h"
#include "quat_err_lib.h"
#include "rwa_allocation_lib.h"
#include "sunSeek_lib.h"
#include "target_generation_lib.h"
#include "target_groundpass_lib.h"
#include "twonorm.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define FSW_Lib0_M                     (rtM)

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_IfWarningError IfWarningError_d;  /* '<S399>/If Warning//Error' */
  DW_mode_select_lib mode_select_lib_k;/* '<S1>/mode_select_lib' */
  DW_target_groundpass_lib target_groundpass_lib1;/* '<S288>/target_groundpass_lib1' */
  DW_target_groundpass_lib target_groundpass_lib_f;/* '<S288>/target_groundpass_lib' */
  DW_rwa_allocation_lib rwa_allocation_lib_h;/* '<S5>/rwa_allocation_lib' */
  DW_sunSeek_lib sunSeek_lib_j;        /* '<S238>/sunSeek_lib' */
  DW_MEKF_lib MEKF_lib_k;              /* '<S1>/MEKF_lib' */
  DW_maggyroProcessing_lib maggyroProcessing_lib1;/* '<S2>/maggyroProcessing_lib1' */
  DW_maggyroProcessing_lib maggyroProcessing_lib_j;/* '<S2>/maggyroProcessing_lib' */
  soar_telemetry soar_telemetry_n;     /* '<S1>/Rate Transition4' */
  soar_telemetry RateTransition4_19_Buffer0;/* '<S1>/Rate Transition4' */
  real_T orbit_tle[9];                 /* '<S1>/Rate Transition' */
  real_T RateTransition2[2];           /* '<S2>/Rate Transition2' */
  real_T RateTransition3[9];           /* '<S2>/Rate Transition3' */
  real_T RateTransition4[9];           /* '<S2>/Rate Transition4' */
  real_T RateTransition1[4];           /* '<S4>/Rate Transition1' */
  real_T telecom[6];                   /* '<S1>/Rate Transition' */
  real_T target_latlonalt[3];          /* '<S1>/Rate Transition' */
  real_T quat_soar_cmd[4];             /* '<S1>/Rate Transition' */
  real_T RateTransition1_l[5];         /* '<S2>/Rate Transition1' */
  real_T Merge1[3];                    /* '<S228>/Merge1' */
  real_T Merge[3];                     /* '<S228>/Merge' */
  real_T sc_quat[4];                   /* '<S1>/Rate Transition4' */
  real_T sc_body_rates_radps[3];       /* '<S1>/Rate Transition4' */
  real_T cmd_quat[4];                  /* '<S1>/Rate Transition4' */
  real_T cmd_body_rates_radps[3];      /* '<S1>/Rate Transition4' */
  real_T mekf_3sigma_rad[6];           /* '<S1>/Rate Transition4' */
  real_T mekf_bias_radps[3];           /* '<S1>/Rate Transition4' */
  real_T r_eci_m[3];                   /* '<S1>/Rate Transition4' */
  real_T Merge_n[4];                   /* '<S390>/Merge' */
  real_T RateTransition6[4];           /* '<S10>/Rate Transition6' */
  real_T X_l[100];                     /* '<S438>/SOLVE' */
  real_T U[30];                        /* '<S438>/SOLVE' */
  real_T exitcode[17];                 /* '<S438>/SOLVE' */
  real_T q_p_merge[4];                 /* '<S3>/q_p_merge' */
  real_T UnitDelay_DSTATE[3];          /* '<S11>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE[4];/* '<S233>/Discrete-Time Integrator' */
  real_T ResettableDelay_DSTATE[10];   /* '<S437>/Resettable Delay' */
  real_T RateTransition4_2_Buffer0[4]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_3_Buffer0[3]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_4_Buffer0[4]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_5_Buffer0[3]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_6_Buffer0[6]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_7_Buffer0[3]; /* '<S1>/Rate Transition4' */
  real_T RateTransition4_9_Buffer0[3]; /* '<S1>/Rate Transition4' */
  real_T rtb_TmpSignalConversionAtAprO_m[1278];
  real_T rtb_TmpSignalConversionAtGprO_c[834];
  real_T rtb_TmpSignalConversionAthOut_k[474];
  real_T sfun_ecos[333];               /* '<S443>/sfun_ecos' */
  real_T rtb_TmpSignalConversionAtcOut_c[332];
  real_T rtb_TmpSignalConversionAtbOut_b[117];
  real_T EH[10000];
  real_T BE[3000];
  real_T G[157368];
  real_T A[38844];
  real_T Apr[1278];
  real_T Gpr[834];
  real_T Hw[9960];
  real_T Hu[9960];
  real_T Hv[33200];
  real_T Hev[33200];
  real_T Gquad_[30544];
  real_T Gquad__[50464];
  real_T Hv_tmp[10000];
  real_T dv0[900];
  real_T dv1[3000];
  real_T MI[1328];
  real_T h[474];
  real_T y[333];
  real_T c[332];
  real_T P0[190];
  real_T k1[190];
  real_T k2[190];
  real_T k3[190];
  real_T k4[190];
  real_T P0_m[190];
  real_T b[117];
  real_T ES[100];
  real_T AR[100];
  real_T Ad[100];
  real_T EH_tmp[100];
  real_T P0_c[100];
  real_T A_k[100];
  real_T X_c[100];
  real_T s_b[100];
  real_T A_p[100];
  real_T qb[40];
  real_T Bdp_dot[30];
  real_T Bdm_dot[30];
  real_T exitcode_c[17];
  real_T Mi[16];
  real_T De[16];
  real_T Di[16];
  real_T ME[16];                       /* '<S438>/INITIALIZE' */
  real_T MI_f[16];                     /* '<S438>/INITIALIZE' */
  real_T d_y[16];
  real_T Mi_g[16];
  real_T dfq_dhb[12];
  real_T b_y_tmp[12];
  real_T k1_g[10];
  real_T k2_m[10];
  real_T k3_n[10];
  real_T k4_p[10];
  real_T xi[10];
  real_T x_opt_t[10];                  /* '<S437>/soar_INTERP' */
  real_T rtb_x_opt_t_l[10];
  real_T tspan[10];
  real_T Ad_j[10];
  real_T Sd_dot[10];
  real_T Zd_dot[10];
  real_T f[10];
  real_T A_d[10];
  real_T C_cmd[9];                     /* '<S10>/target_gen' */
  real_T J[9];                         /* '<S438>/INITIALIZE' */
  real_T dv2[9];
  real_T dv3[9];
  real_T rtu_sc2sun_eci_unit[9];
  real_T b_b[9];
  real_T b_A[9];
  real_T dv4[9];
  real_T dv5[9];
  real_T dv6[9];
  real_T b_A_g[9];
  real_T xf[7];
  real_T u[6];
  real_T Switch_o[4];                  /* '<S396>/Switch' */
  real_T Reshape[4];                   /* '<S10>/Reshape' */
  real_T q[4];
  real_T Product1[3];                  /* '<S391>/Product1' */
  real_T Gain[3];                      /* '<S10>/Gain' */
  real_T MathFunction[3];              /* '<S392>/Math Function' */
  real_T rtu_sc2sun_eci_unit_l[3];
  real_T e[3];
  real_T rtb_Gain_dh[3];
  real_T u_tau[3];
  real_T w[3];
  real_T hquad__[152];
  real_T hquad_[92];
  real_T MI_d[40];
  real_T u_max[30];
  real_T b_w_max[30];
  real_T dv7[30];
  real_T dv8[9];
  real_T b_x[9];
  real_T b_A_l[100];
  real_T b_A_o[100];
  real_T varargin_2[30];
  real_T dv9[12];
  real_T b_x_b[10];
  real_T dv10[9];
  real_T b_A_n[9];
  real_T q_b[4];
  real_T u_t[3];
  real_T u_t_l[3];
  real_T J_h[3];
  real_T Body1[9];
  real_T Inertial1[9];
  real_T Ytb[3];
  real_T Ztb[3];
  real_T Yti[3];
  real_T Zti[3];
  real_T work[4];
  real_T tau[3];
  real_T v[3];
  real_T b_v[3];
  real_T work_b[4];
  real_T P_m[196];
  real_T CreateDiagonalMatrix_i[16];   /* '<S242>/Create Diagonal Matrix' */
  real_T sp[13];
  real_T cp[13];
  real_T NED2ECEF[9];                  /* '<S289>/Transpose' */
  real_T MathFunction1_e[9];           /* '<S293>/Math Function1' */
  real_T MathFunction_o[9];            /* '<S293>/Math Function' */
  real_T Transpose[9];                 /* '<S288>/Transpose' */
  real_T rtb_Gain_d_tmp[9];
  real_T dv0_c[9];
  real_T dv1_k[9];
  real_T rtb_Gain_d_c[9];
  real_T dv2_b[9];
  real_T rtb_Gain_d_p[9];
  real_T rtb_Gain_d_cv[9];
  real_T rtb_Gain_d_tmp_f[9];
  real_T TmpSignalConversionAtSFunct[6];/* '<S14>/MATLAB Function' */
  real_T YMDHMS_UTC[6];                /* '<S292>/MATLAB Function3' */
  real_T xwork[6];
  real_T Switch_g[4];                  /* '<S376>/Switch' */
  real_T RPM2Radps[4];                 /* '<S5>/RPM2Radps' */
  real_T Switch_mo[4];                 /* '<S241>/Switch' */
  real_T x4[4];
  real_T Gain_d[3];                    /* '<S290>/Gain' */
  real_T AU2KM[3];                     /* '<S291>/AU2KM' */
  real_T Subtract_a[3];                /* '<S291>/Subtract' */
  real_T MathFunction_i[3];            /* '<S376>/Math Function' */
  real_T Divide_a[3];                  /* '<S376>/Divide' */
  real_T TmpSignalConversionAtProduc[3];
  real_T nT2T[3];                      /* '<S289>/nT2T' */
  real_T ss_2_body[3];                 /* '<S107>/ss_2_body' */
  real_T bias_merge[3];                /* '<S3>/bias_merge' */
  real_T pos_teme_km[3];               /* '<S290>/MATLAB Function' */
  real_T tod_to_mod_tmp[3];
  real_T deg2rad[9];                   /* '<S2>/deg2rad' */
  real_T MET_utc_s;                    /* '<S1>/Rate Transition' */
  real_T MET_soar_utc_s;               /* '<S1>/Rate Transition' */
  real_T ace_err;                      /* '<S1>/Rate Transition4' */
  real_T elev_gs_rad;                  /* '<S1>/Rate Transition4' */
  real_T elev_targ_rad;                /* '<S1>/Rate Transition4' */
  real_T s;                            /* '<S438>/SOLVE' */
  real_T UnitDelay_DSTATE_p;           /* '<S437>/Unit Delay' */
  real_T RateTransition4_10_Buffer0;   /* '<S1>/Rate Transition4' */
  real_T RateTransition4_16_Buffer0;   /* '<S1>/Rate Transition4' */
  real_T RateTransition4_17_Buffer0;   /* '<S1>/Rate Transition4' */
  real_T Memory_PreviousInput;         /* '<S372>/Memory' */
  real_T Divide_DWORK4;                /* '<S252>/Divide' */
  real_T Divide_DWORK4_g;              /* '<S244>/Divide' */
  real_T coff;
  real_T xtmp;
  real_T t;
  real_T diff;
  real_T Sum;                          /* '<S394>/Sum' */
  real_T Add;                          /* '<S400>/Add' */
  real_T h_d;
  real_T a;
  real_T lam_km;
  real_T lam_kp;
  real_T scale;
  real_T absxk;
  real_T t_e;
  real_T maxval;
  real_T dfq_dhb_tmp;
  real_T dfq_dhb_tmp_b;
  real_T maxval_j;
  real_T a21;
  real_T y_tmp;
  real_T y_tmp_f;
  real_T y_tmp_a;
  real_T y_tmp_j;
  real_T d0;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  real_T temp;
  real_T smax;
  real_T s_j;
  real_T temp_o;
  real_T mag;
  real_T scale_n;
  real_T absxk_i;
  real_T b_t;
  real_T maxval_o;
  real_T a21_n;
  real_T Body1_m;
  real_T Body2;
  real_T Ytb_c;
  real_T Inertial1_m;
  real_T Inertial2;
  real_T Yti_m;
  real_T scale_j;
  real_T absxk_h;
  real_T tst;
  real_T htmp1;
  real_T ab;
  real_T ba;
  real_T aa;
  real_T h12;
  real_T cs;
  real_T sn;
  real_T tst_tmp;
  real_T tst_tmp_tmp;
  real_T temp_c;
  real_T p;
  real_T bcmax;
  real_T bcmis;
  real_T scale_c;
  real_T z;
  real_T a_p;
  real_T alpha1;
  real_T xnorm;
  real_T temp_p;
  real_T xnorm_tmp;
  real_T c_a;
  real_T xnorm_e;
  real_T scale_a;
  real_T absxk_a;
  real_T t_i;
  real_T X_lt;
  real_T X_o;
  real_T temp_o2;
  real_T temp_i;
  real_T scale_f;
  real_T K_tmp;
  real_T K_tmp_i;
  real_T temp_f;
  real_T delta1;
  real_T epsb_1980;
  real_T M_moon;
  real_T M_sun;
  real_T u_moon;
  real_T D_sun;
  real_T O_moon;
  real_T dpsi_1980;
  real_T deps_1980;
  real_T api;
  real_T QOMS4;
  real_T w_o;
  real_T M_o;
  real_T n_o;
  real_T tsince_JD;
  real_T tsince;
  real_T d_1;
  real_T a_o_pp;
  real_T xi_g;
  real_T b_o;
  real_T eta;
  real_T C_5;
  real_T D_2;
  real_T D_3;
  real_T D_4;
  real_T IL3;
  real_T IL4;
  real_T IL5;
  real_T M_DF;
  real_T d_w;
  real_T d_M;
  real_T eps;
  real_T Sum1_m;                       /* '<S369>/Sum1' */
  real_T Sqrt_g;                       /* '<S245>/Sqrt' */
  real_T Sum_o;                        /* '<S292>/Sum' */
  real_T d_1_tmp;
  real_T C_1_tmp;
  real_T C_1_tmp_g;
  real_T M_DF_tmp;
  real_T M_DF_tmp_m;
  real_T M_DF_tmp_tmp;
  real_T d_1_tmp_n;
  real_T C_1_tmp_tmp;
  real_T C_1_tmp_p;
  real_T d0_l;
  real_T d1;
  real_T T_1900;
  real_T sum;
  real_T scale_jw;
  real_T absxk_d;
  real_T t_g;
  real_T d2;
  real_T d3;
  real_T q_l;
  real_T q_d;
  int32_T rtb_TmpSignalConversionAtAirO_p[1278];
  int32_T rtb_TmpSignalConversionAtGirO_c[834];
  int32_T rtb_TmpSignalConversionAtGjcO_f[333];
  int32_T rtb_TmpSignalConversionAtAjcO_g[333];
  int32_T rtb_TmpSignalConversionAtqOut_g[21];
  int32_T Air[1278];
  int32_T Gir[834];
  int32_T Ajc[333];
  int32_T Gjc[333];
  int32_T d[21];
  int32_T ipiv[10];
  int32_T ipiv_g[10];
  int32_T iidx[6];
  int32_T iwork[6];
  int32_T n;
  int32_T i;
  int32_T rtu_sc2sun_eci_unit_tmp;
  int32_T rtb_MI_tmp;
  int32_T rtb_MI_tmp_c;
  int32_T k;
  int32_T k_;
  int32_T i0;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T BE_tmp;
  int32_T BE_tmp_o;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T s_tmp;
  int32_T i8;
  int32_T i9;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  int32_T dfq_dhb_tmp_l;
  int32_T dfq_dhb_tmp_m;
  int32_T dfq_dhb_tmp_mj;
  int32_T dfq_dhb_tmp_c;
  int32_T dfq_dhb_tmp_f;
  int32_T dfq_dhb_tmp_p;
  int32_T dfq_dhb_tmp_e;
  int32_T dfq_dhb_tmp_o;
  int32_T r1_h;
  int32_T r2_l;
  int32_T r3_h;
  int32_T rtemp_m;
  int32_T y_tmp_m;
  int32_T i_h;
  int32_T i10;
  int32_T A_tmp;
  int32_T MI_tmp;
  int32_T ip;
  int32_T info;
  int32_T xj;
  int32_T kAcol;
  int32_T i_c;
  int32_T i11;
  int32_T j;
  int32_T c_k;
  int32_T ix;
  int32_T k_p;
  int32_T info_p;
  int32_T kAcol_p;
  int32_T i_a;
  int32_T offset;
  int32_T c_k_j;
  int32_T n_e;
  int32_T itau;
  int32_T i_o;
  int32_T L;
  int32_T k_b;
  int32_T m;
  int32_T nr;
  int32_T hoffset;
  int32_T its;
  int32_T j_a;
  int32_T ia0;
  int32_T knt;
  int32_T rowleft;
  int32_T ia;
  int32_T iy;
  int32_T g;
  int32_T b_ia;
  int32_T jy;
  int32_T b_ix;
  int32_T lastv;
  int32_T lastc;
  int32_T tst_tmp_g;
  int32_T col;
  int32_T b_n;
  int32_T col_e;
  int32_T b_n_f;
  int32_T iter;
  int32_T i_d;
  int32_T rtb_Gain_d_tmp_l;
  int32_T rtb_Gain_d_tmp_o;
  int32_T P_tmp;
  int32_T P_tmp_b;
  int32_T P_tmp_n;
  int32_T deps_1980_tmp;
  int32_T nNaNs;
  int32_T m_b;
  int32_T i1_l;
  int32_T i2_h;
  int32_T i3_b;
  int32_T i4_d;
  int32_T i_e;
  int32_T n_b;
  int32_T q_j;
  int32_T iout;
  int32_T n_tmp;
  int32_T i0_f;
  int32_T u0;
  int32_T u1;
  uint32_T Counter_Count;              /* '<S394>/Counter' */
  uint32_T Counter_ClkEphState;        /* '<S394>/Counter' */
  int8_T Bp_tmp[30];
  int8_T Hk[3320];
  int8_T idx4[4];
  int8_T perm[4];
  int8_T LMonth[12];
  int8_T s366_iter;
  uint8_T gnc_mode;                    /* '<S1>/Rate Transition4' */
  uint8_T mekf_telem;                  /* '<S1>/Rate Transition4' */
  uint8_T sgp4_flag;                   /* '<S1>/Rate Transition4' */
  uint8_T target_gen_flag;             /* '<S1>/Rate Transition4' */
  uint8_T ss_valid;                    /* '<S1>/Rate Transition4' */
  uint8_T Output_DSTATE;               /* '<S19>/Output' */
  uint8_T RateTransition4_1_Buffer0;   /* '<S1>/Rate Transition4' */
  uint8_T RateTransition4_8_Buffer0;   /* '<S1>/Rate Transition4' */
  uint8_T RateTransition4_12_Buffer0;  /* '<S1>/Rate Transition4' */
  uint8_T RateTransition4_15_Buffer0;  /* '<S1>/Rate Transition4' */
  uint8_T RateTransition4_18_Buffer0;  /* '<S1>/Rate Transition4' */
  uint8_T icLoad;                      /* '<S437>/Resettable Delay' */
  uint8_T Output;                      /* '<S19>/Output' */
  uint8_T gnc_mode_a;                  /* '<S9>/mode_select' */
  uint8_T Merge_b;                     /* '<S108>/Merge' */
  uint8_T Merge_n_j;                   /* '<S118>/Merge' */
  uint8_T flag_b1;                     /* '<S290>/MATLAB Function' */
  uint8_T Switch3;                     /* '<S396>/Switch3' */
  boolean_T RateTransition6_l[3];      /* '<S2>/Rate Transition6' */
  boolean_T RateTransition7[3];        /* '<S2>/Rate Transition7' */
  boolean_T RateTransition2_p[4];      /* '<S4>/Rate Transition2' */
  boolean_T Relay_Mode[2];             /* '<S111>/Relay' */
  boolean_T RateTransition5;           /* '<S2>/Rate Transition5' */
  boolean_T triad_override;            /* '<S1>/Rate Transition' */
  boolean_T eclipse;                   /* '<S1>/Rate Transition4' */
  boolean_T sc_above_gs;               /* '<S1>/Rate Transition4' */
  boolean_T sc_above_targ;             /* '<S1>/Rate Transition4' */
  boolean_T Merge1_g;                  /* '<S13>/Merge1' */
  boolean_T Merge1_g2;                 /* '<S12>/Merge1' */
  boolean_T DelayInput1_DSTATE;        /* '<S436>/Delay Input1' */
  boolean_T RateTransition4_11_Buffer0;/* '<S1>/Rate Transition4' */
  boolean_T RateTransition4_13_Buffer0;/* '<S1>/Rate Transition4' */
  boolean_T RateTransition4_14_Buffer0;/* '<S1>/Rate Transition4' */
  boolean_T lowAlt;
  boolean_T light;
  boolean_T Compare_mg;                /* '<S336>/Compare' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ResettableDelay_Reset_ZCE;/* '<S437>/Resettable Delay' */
  ZCSigState soar_lib_Trig_ZCE;        /* '<S394>/soar_lib' */
} PrevZCX;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T IdentityMatrix[9];      /* '<S251>/Identity Matrix' */
  const real_T IdentityMatrix_e[9];    /* '<S243>/Identity Matrix' */
} ConstB;

/* External inputs (root inport signals with default storage) */
typedef struct {
  sensor_bus sensor_meas;              /* '<Root>/sensor_meas' */
  cdh_data telecommands;               /* '<Root>/telecommands' */
  actuator_meas actuator_meas_p;       /* '<Root>/act_meas' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  fsw_out fsw_out_l;                   /* '<Root>/fsw_out' */
  fsw_telemetry fsw_telem;             /* '<Root>/fsw_telem' */
} ExtY;

/* Parameters for system: '<S230>/If Action Subsystem' */
struct P_IfActionSubsystem_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S261>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_ {
  struct_Fxs15VniWr6vzefGObgabH fswParams;/* Variable: fswParams
                                           * Referenced by:
                                           *   '<S2>/maggyroProcessing_lib'
                                           *   '<S2>/maggyroProcessing_lib1'
                                           *   '<S2>/deg2rad'
                                           *   '<S3>/Unit Delay'
                                           *   '<S3>/Unit Delay1'
                                           *   '<S3>/Unit Delay3'
                                           *   '<S5>/RPM2Radps'
                                           *   '<S6>/M2KM'
                                           *   '<S9>/Relay'
                                           *   '<S9>/Unit Delay'
                                           *   '<S10>/ss_offset_rad'
                                           *   '<S115>/parallel_protection_lib'
                                           *   '<S119>/Constant'
                                           *   '<S119>/Saturation'
                                           *   '<S120>/Constant'
                                           *   '<S121>/Constant'
                                           *   '<S124>/Constant'
                                           *   '<S124>/Constant13'
                                           *   '<S125>/parallel_protection_lib'
                                           *   '<S125>/parallel_protection_lib1'
                                           *   '<S125>/Unit Delay'
                                           *   '<S229>/RAD2DEG'
                                           *   '<S288>/Constant'
                                           *   '<S288>/Constant1'
                                           *   '<S288>/Constant2'
                                           *   '<S290>/JD_J2000'
                                           *   '<S291>/AU2KM'
                                           *   '<S292>/Constant1'
                                           *   '<S382>/A_wheel2body '
                                           *   '<S382>/J_w_wheel_kgm2'
                                           *   '<S382>/scParams.J '
                                           *   '<S382>/rpm2radps'
                                           *   '<S382>/Relay3'
                                           *   '<S391>/A_wheel2body'
                                           *   '<S391>/wheel_inertia'
                                           *   '<S107>/deg2rad'
                                           *   '<S126>/DEG2RAD'
                                           *   '<S179>/DEG2RAD'
                                           *   '<S180>/DEG2RAD'
                                           *   '<S233>/Constant'
                                           *   '<S233>/radps_2_rpm'
                                           *   '<S233>/Saturation'
                                           *   '<S274>/Constant'
                                           *   '<S275>/feedback_gain'
                                           *   '<S275>/wheel_inertia_kgm2'
                                           *   '<S276>/Constant'
                                           *   '<S294>/deg2rad1'
                                           *   '<S294>/deg2rad2'
                                           *   '<S295>/deg2rad1'
                                           *   '<S295>/deg2rad2'
                                           *   '<S111>/Relay'
                                           *   '<S239>/Constant'
                                           *   '<S247>/Kp'
                                           *   '<S247>/kd'
                                           *   '<S256>/Kp'
                                           *   '<S256>/kd'
                                           *   '<S257>/Kd'
                                           *   '<S257>/Kp'
                                           *   '<S278>/Constant'
                                           *   '<S279>/Constant'
                                           *   '<S280>/Constant1'
                                           *   '<S336>/Constant'
                                           *   '<S342>/Constant'
                                           *   '<S112>/Lower Limit'
                                           *   '<S112>/Upper Limit'
                                           *   '<S113>/Lower Limit'
                                           *   '<S113>/Upper Limit'
                                           *   '<S242>/A_wheel2body '
                                           *   '<S242>/J_w_wheel_kgm2'
                                           *   '<S242>/h_targ_wheel_Nms'
                                           *   '<S242>/scParams.J '
                                           *   '<S243>/Gain'
                                           *   '<S244>/Gain3'
                                           *   '<S250>/A_wheel2body '
                                           *   '<S250>/J_w_wheel_kgm2'
                                           *   '<S250>/h_targ_wheel_Nms'
                                           *   '<S250>/scParams.J '
                                           *   '<S251>/Gain'
                                           *   '<S252>/Gain3'
                                           *   '<S258>/sunsensor_boresight_unit'
                                           */
  struct_8XGv1kQV9vs4SVMcdRefJC simParams;/* Variable: simParams
                                           * Referenced by:
                                           *   '<S289>/nT2T'
                                           *   '<S107>/Constant1'
                                           *   '<S233>/Discrete-Time Integrator'
                                           */
  real_T GeodetictoGeocentricLatitude_F;/* Mask Parameter: GeodetictoGeocentricLatitude_F
                                         * Referenced by:
                                         *   '<S298>/Constant'
                                         *   '<S327>/f'
                                         */
  real_T RadiusatGeocentricLatitude_F; /* Mask Parameter: RadiusatGeocentricLatitude_F
                                        * Referenced by: '<S300>/f'
                                        */
  real_T maggyroProcessing_lib1_Gain;  /* Mask Parameter: maggyroProcessing_lib1_Gain
                                        * Referenced by: '<S2>/maggyroProcessing_lib1'
                                        */
  real_T GeodetictoGeocentricLatitude_R;/* Mask Parameter: GeodetictoGeocentricLatitude_R
                                         * Referenced by: '<S327>/Re'
                                         */
  real_T RadiusatGeocentricLatitude_R; /* Mask Parameter: RadiusatGeocentricLatitude_R
                                        * Referenced by: '<S300>/Re'
                                        */
  real_T DirectionCosineMatrixtoQuaterni;/* Mask Parameter: DirectionCosineMatrixtoQuaterni
                                          * Referenced by:
                                          *   '<S399>/If Warning//Error'
                                          *   '<S399>/Constant'
                                          */
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S445>/Constant'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S333>/Constant'
                                        */
  real_T CompareToConstant_const_o;    /* Mask Parameter: CompareToConstant_const_o
                                        * Referenced by: '<S331>/Constant'
                                        */
  real_T CompareToConstant_const_f;    /* Mask Parameter: CompareToConstant_const_f
                                        * Referenced by: '<S334>/Constant'
                                        */
  real_T target_groundpass_lib1_id;    /* Mask Parameter: target_groundpass_lib1_id
                                        * Referenced by: '<S288>/target_groundpass_lib1'
                                        */
  real_T target_groundpass_lib_id;     /* Mask Parameter: target_groundpass_lib_id
                                        * Referenced by: '<S288>/target_groundpass_lib'
                                        */
  real_T NormalizeVector_maxzero;      /* Mask Parameter: NormalizeVector_maxzero
                                        * Referenced by: '<S241>/Switch'
                                        */
  real_T NormalizeVector_maxzero_c;    /* Mask Parameter: NormalizeVector_maxzero_c
                                        * Referenced by: '<S249>/Switch'
                                        */
  real_T NormalizeVector1_maxzero;     /* Mask Parameter: NormalizeVector1_maxzero
                                        * Referenced by: '<S392>/Switch'
                                        */
  real_T NormalizeVector_maxzero_g;    /* Mask Parameter: NormalizeVector_maxzero_g
                                        * Referenced by: '<S376>/Switch'
                                        */
  real_T DirectionCosineMatrixtoQuater_g;/* Mask Parameter: DirectionCosineMatrixtoQuater_g
                                          * Referenced by: '<S399>/If Warning//Error'
                                          */
  uint32_T Counter_InitialCount;       /* Mask Parameter: Counter_InitialCount
                                        * Referenced by: '<S394>/Counter'
                                        */
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S436>/Delay Input1'
                                        */
  uint8_T CompareToConstant_const_f2;  /* Mask Parameter: CompareToConstant_const_f2
                                        * Referenced by: '<S435>/Constant'
                                        */
  uint8_T CompareToConstant_const_a;   /* Mask Parameter: CompareToConstant_const_a
                                        * Referenced by: '<S444>/Constant'
                                        */
  uint8_T CompareToConstant1_const_c;  /* Mask Parameter: CompareToConstant1_const_c
                                        * Referenced by: '<S18>/Constant'
                                        */
  uint8_T CompareToConstant_const_p;   /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S17>/Constant'
                                        */
  uint8_T CounterLimited_uplimit;      /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S21>/FixPt Switch'
                                        */
  soar_telemetry RateTransition4_19_InitialCondi;/* Computed Parameter: RateTransition4_19_InitialCondi
                                                  * Referenced by: '<S1>/Rate Transition4'
                                                  */
  real_T mtq_off_cmd_Value[5];         /* Expression: zeros(5,1)
                                        * Referenced by: '<S227>/mtq_off_cmd'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S230>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S230>/Constant1'
                                        */
  real_T Constant_Value[5];            /* Expression: [0.5;-0.5;0.5;-0.5;1]
                                        * Referenced by: '<S230>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S241>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S244>/Gain'
                                        */
  real_T DutyCycleAdjustment_Gain;     /* Expression: 11/5
                                        * Referenced by: '<S240>/DutyCycleAdjustment'
                                        */
  real_T Constant_Value_l[3];          /* Expression: zeros(3,1)
                                        * Referenced by: '<S238>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S249>/Constant'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S252>/Gain'
                                        */
  real_T DutyCycleAdjustment_Gain_f;   /* Expression: 11/5
                                        * Referenced by: '<S248>/DutyCycleAdjustment'
                                        */
  real_T Constant_Value_e[3];          /* Expression: zeros(3,1)
                                        * Referenced by: '<S237>/Constant'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S299>/Constant1'
                                        */
  real_T Constant_Value_ea;            /* Expression: 180
                                        * Referenced by: '<S299>/Constant'
                                        */
  real_T Bias_Bias;                    /* Expression: -90
                                        * Referenced by: '<S329>/Bias'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S329>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: +90
                                        * Referenced by: '<S329>/Bias1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 360
                                        * Referenced by: '<S332>/Constant2'
                                        */
  real_T Bias_Bias_g;                  /* Expression: 180
                                        * Referenced by: '<S332>/Bias'
                                        */
  real_T Bias1_Bias_c;                 /* Expression: -180
                                        * Referenced by: '<S332>/Bias1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 360
                                        * Referenced by: '<S330>/Constant2'
                                        */
  real_T Bias_Bias_b;                  /* Expression: 180
                                        * Referenced by: '<S330>/Bias'
                                        */
  real_T Bias1_Bias_e;                 /* Expression: -180
                                        * Referenced by: '<S330>/Bias1'
                                        */
  real_T phi_Y0;                       /* Expression: 0
                                        * Referenced by: '<S366>/phi'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S372>/Memory'
                                        */
  real_T Constant1_Value_j;            /* Expression: R
                                        * Referenced by: '<S370>/Constant1'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S376>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S392>/Constant'
                                        */
  real_T opt_state_Y0;                 /* Computed Parameter: opt_state_Y0
                                        * Referenced by: '<S438>/opt_state'
                                        */
  real_T opt_ctrl_Nm_Y0;               /* Computed Parameter: opt_ctrl_Nm_Y0
                                        * Referenced by: '<S438>/opt_ctrl_Nm'
                                        */
  real_T final_time_s_Y0;              /* Computed Parameter: final_time_s_Y0
                                        * Referenced by: '<S438>/final_time_s'
                                        */
  real_T exitcode_Y0;                  /* Computed Parameter: exitcode_Y0
                                        * Referenced by: '<S438>/exitcode'
                                        */
  real_T Constant_Value_j[3];          /* Expression: [0;0;0]
                                        * Referenced by: '<S396>/Constant'
                                        */
  real_T Constant1_Value_m[3];         /* Expression: [0;0;0]
                                        * Referenced by: '<S396>/Constant1'
                                        */
  real_T Constant_Value_e3[3];         /* Expression: [0; 0; 0]
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -1
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Merge_InitialOutput[4];       /* Expression: [1 0 0 0]
                                        * Referenced by: '<S390>/Merge'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S437>/Unit Delay'
                                        */
  real_T Gain_Gain_ac;                 /* Expression: 1000
                                        * Referenced by: '<S290>/Gain'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S368>/Constant'
                                        */
  real_T Constant1_Value_j5;           /* Expression: F
                                        * Referenced by: '<S368>/Constant1'
                                        */
  real_T Constant_Value_b;             /* Expression: R
                                        * Referenced by: '<S349>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S369>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S367>/Constant'
                                        */
  real_T Constant_Value_nr;            /* Expression: 0
                                        * Referenced by: '<S357>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: R
                                        * Referenced by: '<S365>/Constant1'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S365>/f'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S109>/Constant'
                                        */
  real_T UnitDelay_InitialCondition_p[3];/* Expression: [0;0;1]
                                          * Referenced by: '<S11>/Unit Delay'
                                          */
  real_T Constant2_Value_nc;           /* Expression: 0
                                        * Referenced by: '<S293>/Constant2'
                                        */
  real_T Constant_Value_jh;            /* Expression: 1
                                        * Referenced by: '<S327>/Constant'
                                        */
  real_T f_Value_m;                    /* Expression: 1
                                        * Referenced by: '<S298>/f'
                                        */
  real_T Constant_Value_ez;            /* Expression: 0
                                        * Referenced by: '<S317>/Constant'
                                        */
  real_T Constant_Value_ey;            /* Expression: 0
                                        * Referenced by: '<S293>/Constant'
                                        */
  real_T Constant_Value_nu;            /* Expression: 1
                                        * Referenced by: '<S300>/Constant'
                                        */
  real_T Constant_Value_jk;            /* Expression: 0
                                        * Referenced by: '<S306>/Constant'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S293>/Constant1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 1.002
                                        * Referenced by: '<S291>/Gain'
                                        */
  real_T Constant_Value_en;            /* Expression: 0
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Merge1_InitialOutput;         /* Computed Parameter: Merge1_InitialOutput
                                        * Referenced by: '<S228>/Merge1'
                                        */
  real_T Merge_InitialOutput_f;        /* Computed Parameter: Merge_InitialOutput_f
                                        * Referenced by: '<S228>/Merge'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S233>/Discrete-Time Integrator'
                                         */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S229>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S229>/Saturation'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 2
                                        * Referenced by: '<S229>/Gain'
                                        */
  real_T RateTransition4_2_InitialCondit;/* Expression: 0
                                          * Referenced by: '<S1>/Rate Transition4'
                                          */
  real_T RateTransition4_3_InitialCondit;/* Expression: 0
                                          * Referenced by: '<S1>/Rate Transition4'
                                          */
  real_T RateTransition4_4_InitialCondit;/* Expression: 0
                                          * Referenced by: '<S1>/Rate Transition4'
                                          */
  real_T RateTransition4_5_InitialCondit;/* Expression: 0
                                          * Referenced by: '<S1>/Rate Transition4'
                                          */
  real_T RateTransition4_6_InitialCondit;/* Expression: 0
                                          * Referenced by: '<S1>/Rate Transition4'
                                          */
  real_T RateTransition4_7_InitialCondit;/* Expression: 0
                                          * Referenced by: '<S1>/Rate Transition4'
                                          */
  real_T RateTransition4_9_InitialCondit;/* Expression: 0
                                          * Referenced by: '<S1>/Rate Transition4'
                                          */
  real_T RateTransition4_10_InitialCondi;/* Expression: 0
                                          * Referenced by: '<S1>/Rate Transition4'
                                          */
  real_T RateTransition4_16_InitialCondi;/* Expression: 0
                                          * Referenced by: '<S1>/Rate Transition4'
                                          */
  real_T RateTransition4_17_InitialCondi;/* Expression: 0
                                          * Referenced by: '<S1>/Rate Transition4'
                                          */
  uint32_T ResettableDelay_DelayLength;/* Computed Parameter: ResettableDelay_DelayLength
                                        * Referenced by: '<S437>/Resettable Delay'
                                        */
  boolean_T Relay_YOn;                 /* Expression: false
                                        * Referenced by: '<S111>/Relay'
                                        */
  boolean_T Relay_YOff;                /* Expression: true
                                        * Referenced by: '<S111>/Relay'
                                        */
  boolean_T Constant_Value_h4;         /* Computed Parameter: Constant_Value_h4
                                        * Referenced by: '<S439>/Constant'
                                        */
  boolean_T Constant_Value_mj[5];      /* Expression: [true;true;true;true;true]
                                        * Referenced by: '<S5>/Constant'
                                        */
  boolean_T RateTransition4_11_InitialCondi;/* Computed Parameter: RateTransition4_11_InitialCondi
                                             * Referenced by: '<S1>/Rate Transition4'
                                             */
  boolean_T RateTransition4_13_InitialCondi;/* Computed Parameter: RateTransition4_13_InitialCondi
                                             * Referenced by: '<S1>/Rate Transition4'
                                             */
  boolean_T RateTransition4_14_InitialCondi;/* Computed Parameter: RateTransition4_14_InitialCondi
                                             * Referenced by: '<S1>/Rate Transition4'
                                             */
  int8_T Switch_Threshold;             /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S372>/Switch'
                                        */
  uint8_T Constant_Value_js;           /* Computed Parameter: Constant_Value_js
                                        * Referenced by: '<S21>/Constant'
                                        */
  uint8_T Constant_Value_gq;           /* Computed Parameter: Constant_Value_gq
                                        * Referenced by: '<S110>/Constant'
                                        */
  uint8_T Constant2_Value_o;           /* Computed Parameter: Constant2_Value_o
                                        * Referenced by: '<S396>/Constant2'
                                        */
  uint8_T Output_InitialCondition;     /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S19>/Output'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S20>/FixPt Constant'
                                        */
  uint8_T RateTransition4_1_InitialCondit;/* Computed Parameter: RateTransition4_1_InitialCondit
                                           * Referenced by: '<S1>/Rate Transition4'
                                           */
  uint8_T RateTransition4_8_InitialCondit;/* Computed Parameter: RateTransition4_8_InitialCondit
                                           * Referenced by: '<S1>/Rate Transition4'
                                           */
  uint8_T RateTransition4_12_InitialCondi;/* Computed Parameter: RateTransition4_12_InitialCondi
                                           * Referenced by: '<S1>/Rate Transition4'
                                           */
  uint8_T RateTransition4_15_InitialCondi;/* Computed Parameter: RateTransition4_15_InitialCondi
                                           * Referenced by: '<S1>/Rate Transition4'
                                           */
  uint8_T RateTransition4_18_InitialCondi;/* Computed Parameter: RateTransition4_18_InitialCondi
                                           * Referenced by: '<S1>/Rate Transition4'
                                           */
  P_quat_rectify_lib quat_rectify_lib_l;/* '<S10>/quat_rectify_lib' */
  P_IfWarningError IfWarningError_d;   /* '<S399>/If Warning//Error' */
  P_NegativeTrace NegativeTrace_l;     /* '<S390>/Negative Trace' */
  P_PositiveTrace PositiveTrace_p;     /* '<S390>/Positive Trace' */
  P_mode_select_lib mode_select_lib_k; /* '<S1>/mode_select_lib' */
  P_target_groundpass_lib target_groundpass_lib1;/* '<S288>/target_groundpass_lib1' */
  P_target_groundpass_lib target_groundpass_lib_f;/* '<S288>/target_groundpass_lib' */
  P_rwa_allocation_lib rwa_allocation_lib_h;/* '<S5>/rwa_allocation_lib' */
  P_quat_err_lib quat_err_lib_e;       /* '<S5>/quat_err_lib' */
  P_IfActionSubsystem IfActionSubsystem5;/* '<S230>/If Action Subsystem5' */
  P_IfActionSubsystem IfActionSubsystem4;/* '<S230>/If Action Subsystem4' */
  P_IfActionSubsystem IfActionSubsystem3;/* '<S230>/If Action Subsystem3' */
  P_IfActionSubsystem IfActionSubsystem2_p;/* '<S230>/If Action Subsystem2' */
  P_IfActionSubsystem IfActionSubsystem1;/* '<S230>/If Action Subsystem1' */
  P_IfActionSubsystem IfActionSubsystem_f;/* '<S230>/If Action Subsystem' */
  P_sunSeek_lib sunSeek_lib_j;         /* '<S238>/sunSeek_lib' */
  P_null_control_lib null_control_lib1;/* '<S236>/null_control_lib1' */
  P_MEKF_lib MEKF_lib_k;               /* '<S1>/MEKF_lib' */
  P_maggyroProcessing_lib maggyroProcessing_lib1;/* '<S2>/maggyroProcessing_lib1' */
  P_maggyroProcessing_lib maggyroProcessing_lib_j;/* '<S2>/maggyroProcessing_lib' */
};

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P rtP;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX rtPrevZCX;
extern const ConstB rtConstB;          /* constant block i/o */

/* External function called from main */
extern void FSW_Lib0_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void FSW_Lib0_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void FSW_Lib0_initialize(void);
extern void FSW_Lib0_step0(void);
extern void FSW_Lib0_step1(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S19>/Data Type Propagation' : Unused code path elimination
 * Block '<S20>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S112>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S113>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Rate Transition3' : Unused code path elimination
 * Block '<S288>/Product2' : Unused code path elimination
 * Block '<S290>/Gain3' : Unused code path elimination
 * Block '<S290>/Product1' : Unused code path elimination
 * Block '<S7>/Constant1' : Unused code path elimination
 * Block '<S7>/Constant7' : Unused code path elimination
 * Block '<S8>/Constant1' : Unused code path elimination
 * Block '<S8>/Constant10' : Unused code path elimination
 * Block '<S8>/Constant11' : Unused code path elimination
 * Block '<S8>/Constant12' : Unused code path elimination
 * Block '<S8>/Constant13' : Unused code path elimination
 * Block '<S8>/Constant14' : Unused code path elimination
 * Block '<S8>/Constant15' : Unused code path elimination
 * Block '<S8>/Constant16' : Unused code path elimination
 * Block '<S8>/Constant17' : Unused code path elimination
 * Block '<S8>/Constant18' : Unused code path elimination
 * Block '<S8>/Constant19' : Unused code path elimination
 * Block '<S8>/Constant2' : Unused code path elimination
 * Block '<S8>/Constant3' : Unused code path elimination
 * Block '<S8>/Constant4' : Unused code path elimination
 * Block '<S8>/Constant5' : Unused code path elimination
 * Block '<S8>/Constant6' : Unused code path elimination
 * Block '<S8>/Constant7' : Unused code path elimination
 * Block '<S8>/Constant8' : Unused code path elimination
 * Block '<S8>/Constant9' : Unused code path elimination
 * Block '<S12>/Reshape' : Reshape block reduction
 * Block '<S13>/Reshape' : Reshape block reduction
 * Block '<S137>/map_12x1_to_4x3' : Reshape block reduction
 * Block '<S188>/Reshape 3x3 -> 9' : Reshape block reduction
 * Block '<S218>/Reshape' : Reshape block reduction
 * Block '<S225>/Reshape' : Reshape block reduction
 * Block '<S243>/Reshape' : Reshape block reduction
 * Block '<S243>/Reshape1' : Reshape block reduction
 * Block '<S251>/Reshape' : Reshape block reduction
 * Block '<S251>/Reshape1' : Reshape block reduction
 * Block '<S287>/Reshape' : Reshape block reduction
 * Block '<S311>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S322>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S341>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S347>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S362>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S390>/Reshape 3x3 -> 9' : Reshape block reduction
 * Block '<S426>/Reshape' : Reshape block reduction
 * Block '<S433>/Reshape' : Reshape block reduction
 * Block '<S10>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition12' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S394>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S394>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S394>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<S394>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S394>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S394>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S394>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S394>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<S394>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S394>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<S394>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S437>/Reshape' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Main_Sim/FSW_Lib')    - opens subsystem Main_Sim/FSW_Lib
 * hilite_system('Main_Sim/FSW_Lib/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Main_Sim'
 * '<S1>'   : 'Main_Sim/FSW_Lib'
 * '<S2>'   : 'Main_Sim/FSW_Lib/Conversion_lib'
 * '<S3>'   : 'Main_Sim/FSW_Lib/MEKF_lib'
 * '<S4>'   : 'Main_Sim/FSW_Lib/actuator_processing_lib'
 * '<S5>'   : 'Main_Sim/FSW_Lib/control_command_generation_lib'
 * '<S6>'   : 'Main_Sim/FSW_Lib/environmentEstimation_lib'
 * '<S7>'   : 'Main_Sim/FSW_Lib/fsw_out_bus'
 * '<S8>'   : 'Main_Sim/FSW_Lib/fsw_telemetry_bus'
 * '<S9>'   : 'Main_Sim/FSW_Lib/mode_select_lib'
 * '<S10>'  : 'Main_Sim/FSW_Lib/target_generation_lib'
 * '<S11>'  : 'Main_Sim/FSW_Lib/Conversion_lib/MagMtqDutyCycling'
 * '<S12>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib'
 * '<S13>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1'
 * '<S14>'  : 'Main_Sim/FSW_Lib/Conversion_lib/pd_processing_lib'
 * '<S15>'  : 'Main_Sim/FSW_Lib/Conversion_lib/sunsensor_processing_lib'
 * '<S16>'  : 'Main_Sim/FSW_Lib/Conversion_lib/MagMtqDutyCycling/mag_mtq_duty_cycle_lib'
 * '<S17>'  : 'Main_Sim/FSW_Lib/Conversion_lib/MagMtqDutyCycling/mag_mtq_duty_cycle_lib/Compare To Constant'
 * '<S18>'  : 'Main_Sim/FSW_Lib/Conversion_lib/MagMtqDutyCycling/mag_mtq_duty_cycle_lib/Compare To Constant1'
 * '<S19>'  : 'Main_Sim/FSW_Lib/Conversion_lib/MagMtqDutyCycling/mag_mtq_duty_cycle_lib/Counter Limited'
 * '<S20>'  : 'Main_Sim/FSW_Lib/Conversion_lib/MagMtqDutyCycling/mag_mtq_duty_cycle_lib/Counter Limited/Increment Real World'
 * '<S21>'  : 'Main_Sim/FSW_Lib/Conversion_lib/MagMtqDutyCycling/mag_mtq_duty_cycle_lib/Counter Limited/Wrap To Zero'
 * '<S22>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/DataCalibration'
 * '<S23>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/NoneValid'
 * '<S24>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/OneValid'
 * '<S25>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck '
 * '<S26>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/ThreeValid_MVS'
 * '<S27>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid'
 * '<S28>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/OneValid/If Action Subsystem1'
 * '<S29>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/OneValid/If Action Subsystem14'
 * '<S30>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/OneValid/If Action Subsystem2'
 * '<S31>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/OneValid/If Action Subsystem6'
 * '<S32>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/OneValid/If Action Subsystem8'
 * '<S33>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/OneValid/If Action Subsystem9'
 * '<S34>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /Check  Static Range1'
 * '<S35>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /Check  Static Range2'
 * '<S36>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /Check  Static Range4'
 * '<S37>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /If Action Subsystem'
 * '<S38>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /If Action Subsystem1'
 * '<S39>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /If Action Subsystem14'
 * '<S40>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /If Action Subsystem2'
 * '<S41>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /If Action Subsystem3'
 * '<S42>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /If Action Subsystem4'
 * '<S43>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /twonorm1'
 * '<S44>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /twonorm2'
 * '<S45>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/StaticRangeCheck /twonorm3'
 * '<S46>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/ThreeValid_MVS/Compare To Constant'
 * '<S47>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/ThreeValid_MVS/Compare To Constant1'
 * '<S48>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/ThreeValid_MVS/Compare To Constant2'
 * '<S49>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/ThreeValid_MVS/twonorm'
 * '<S50>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/ThreeValid_MVS/twonorm1'
 * '<S51>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/ThreeValid_MVS/twonorm2'
 * '<S52>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem1'
 * '<S53>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem14'
 * '<S54>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem2'
 * '<S55>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem6'
 * '<S56>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem8'
 * '<S57>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem9'
 * '<S58>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem1/Compare To Constant'
 * '<S59>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem1/twonorm'
 * '<S60>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem14/Compare To Constant'
 * '<S61>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem14/twonorm'
 * '<S62>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem2/Compare To Constant'
 * '<S63>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib/TwoValid/If Action Subsystem2/twonorm'
 * '<S64>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/DataCalibration'
 * '<S65>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/NoneValid'
 * '<S66>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/OneValid'
 * '<S67>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck '
 * '<S68>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/ThreeValid_MVS'
 * '<S69>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid'
 * '<S70>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/OneValid/If Action Subsystem1'
 * '<S71>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/OneValid/If Action Subsystem14'
 * '<S72>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/OneValid/If Action Subsystem2'
 * '<S73>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/OneValid/If Action Subsystem6'
 * '<S74>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/OneValid/If Action Subsystem8'
 * '<S75>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/OneValid/If Action Subsystem9'
 * '<S76>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /Check  Static Range1'
 * '<S77>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /Check  Static Range2'
 * '<S78>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /Check  Static Range4'
 * '<S79>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /If Action Subsystem'
 * '<S80>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /If Action Subsystem1'
 * '<S81>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /If Action Subsystem14'
 * '<S82>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /If Action Subsystem2'
 * '<S83>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /If Action Subsystem3'
 * '<S84>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /If Action Subsystem4'
 * '<S85>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /twonorm1'
 * '<S86>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /twonorm2'
 * '<S87>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/StaticRangeCheck /twonorm3'
 * '<S88>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/ThreeValid_MVS/Compare To Constant'
 * '<S89>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/ThreeValid_MVS/Compare To Constant1'
 * '<S90>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/ThreeValid_MVS/Compare To Constant2'
 * '<S91>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/ThreeValid_MVS/twonorm'
 * '<S92>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/ThreeValid_MVS/twonorm1'
 * '<S93>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/ThreeValid_MVS/twonorm2'
 * '<S94>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem1'
 * '<S95>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem14'
 * '<S96>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem2'
 * '<S97>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem6'
 * '<S98>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem8'
 * '<S99>'  : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem9'
 * '<S100>' : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem1/Compare To Constant'
 * '<S101>' : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem1/twonorm'
 * '<S102>' : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem14/Compare To Constant'
 * '<S103>' : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem14/twonorm'
 * '<S104>' : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem2/Compare To Constant'
 * '<S105>' : 'Main_Sim/FSW_Lib/Conversion_lib/maggyroProcessing_lib1/TwoValid/If Action Subsystem2/twonorm'
 * '<S106>' : 'Main_Sim/FSW_Lib/Conversion_lib/pd_processing_lib/MATLAB Function'
 * '<S107>' : 'Main_Sim/FSW_Lib/Conversion_lib/sunsensor_processing_lib/angles_to_unit_vector'
 * '<S108>' : 'Main_Sim/FSW_Lib/Conversion_lib/sunsensor_processing_lib/sun_validity_logic'
 * '<S109>' : 'Main_Sim/FSW_Lib/Conversion_lib/sunsensor_processing_lib/angles_to_unit_vector/create_sz'
 * '<S110>' : 'Main_Sim/FSW_Lib/Conversion_lib/sunsensor_processing_lib/sun_validity_logic/sunSensorIsNotValid'
 * '<S111>' : 'Main_Sim/FSW_Lib/Conversion_lib/sunsensor_processing_lib/sun_validity_logic/sunSensorIsValid'
 * '<S112>' : 'Main_Sim/FSW_Lib/Conversion_lib/sunsensor_processing_lib/sun_validity_logic/sunSensorIsValid/Interval Test'
 * '<S113>' : 'Main_Sim/FSW_Lib/Conversion_lib/sunsensor_processing_lib/sun_validity_logic/sunSensorIsValid/Interval Test1'
 * '<S114>' : 'Main_Sim/FSW_Lib/MEKF_lib/BypassMeasUpdate'
 * '<S115>' : 'Main_Sim/FSW_Lib/MEKF_lib/ChooseMEKForPropagation'
 * '<S116>' : 'Main_Sim/FSW_Lib/MEKF_lib/ChooseQuaternionSource'
 * '<S117>' : 'Main_Sim/FSW_Lib/MEKF_lib/Compare To Constant'
 * '<S118>' : 'Main_Sim/FSW_Lib/MEKF_lib/MEKF_telemetry'
 * '<S119>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate'
 * '<S120>' : 'Main_Sim/FSW_Lib/MEKF_lib/Reset'
 * '<S121>' : 'Main_Sim/FSW_Lib/MEKF_lib/Reset1'
 * '<S122>' : 'Main_Sim/FSW_Lib/MEKF_lib/TRIADActivation_lib'
 * '<S123>' : 'Main_Sim/FSW_Lib/MEKF_lib/ThreeSigmaBounds'
 * '<S124>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation'
 * '<S125>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib'
 * '<S126>' : 'Main_Sim/FSW_Lib/MEKF_lib/ChooseMEKForPropagation/parallel_protection_lib'
 * '<S127>' : 'Main_Sim/FSW_Lib/MEKF_lib/ChooseQuaternionSource/If Action Subsystem'
 * '<S128>' : 'Main_Sim/FSW_Lib/MEKF_lib/MEKF_telemetry/Compare To Constant'
 * '<S129>' : 'Main_Sim/FSW_Lib/MEKF_lib/MEKF_telemetry/If Action Subsystem'
 * '<S130>' : 'Main_Sim/FSW_Lib/MEKF_lib/MEKF_telemetry/If Action Subsystem1'
 * '<S131>' : 'Main_Sim/FSW_Lib/MEKF_lib/MEKF_telemetry/If Action Subsystem2'
 * '<S132>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Creates Estimated  Measurements'
 * '<S133>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/QR_factorization'
 * '<S134>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Normalize'
 * '<S135>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation'
 * '<S136>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1'
 * '<S137>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/makes_Xi_q'
 * '<S138>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Creates Estimated  Measurements/CrossProdMatrix_lib'
 * '<S139>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Creates Estimated  Measurements/CrossProdMatrix_lib1'
 * '<S140>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Creates Estimated  Measurements/CrossProdMatrix_lib/Create 3x3 Matrix'
 * '<S141>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Creates Estimated  Measurements/CrossProdMatrix_lib1/Create 3x3 Matrix'
 * '<S142>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Normalize/Quaternion Modulus'
 * '<S143>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S144>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/Quaternion Normalize'
 * '<S145>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/V1'
 * '<S146>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/V2'
 * '<S147>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/V3'
 * '<S148>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus'
 * '<S149>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S150>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/Quaternion Normalize'
 * '<S151>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/V1'
 * '<S152>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/V2'
 * '<S153>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/V3'
 * '<S154>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus'
 * '<S155>' : 'Main_Sim/FSW_Lib/MEKF_lib/MeasurementUpdate/Quaternion Rotation1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S156>' : 'Main_Sim/FSW_Lib/MEKF_lib/Reset/Compare To Constant'
 * '<S157>' : 'Main_Sim/FSW_Lib/MEKF_lib/Reset/Detect Rise Positive'
 * '<S158>' : 'Main_Sim/FSW_Lib/MEKF_lib/Reset/Detect Rise Positive/Positive'
 * '<S159>' : 'Main_Sim/FSW_Lib/MEKF_lib/TRIADActivation_lib/NEdgeDetector_lib'
 * '<S160>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/CreateStateTransitionMatrix'
 * '<S161>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/CrossProdMatrix_lib'
 * '<S162>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/CrossProdMatrix_lib1'
 * '<S163>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/MATLAB Function'
 * '<S164>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/MakePsiVector'
 * '<S165>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/OMEGAMatrix'
 * '<S166>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/Quaternion Normalize'
 * '<S167>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/quat_rectify_lib'
 * '<S168>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/CrossProdMatrix_lib/Create 3x3 Matrix'
 * '<S169>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/CrossProdMatrix_lib1/Create 3x3 Matrix'
 * '<S170>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/MakePsiVector/If Action Subsystem'
 * '<S171>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/MakePsiVector/If Action Subsystem1'
 * '<S172>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/Quaternion Normalize/Quaternion Modulus'
 * '<S173>' : 'Main_Sim/FSW_Lib/MEKF_lib/TimePropagation/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S174>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/Normalize Vector'
 * '<S175>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/Normalize Vector1'
 * '<S176>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/Quaternion Normalize'
 * '<S177>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm'
 * '<S178>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadBypass'
 * '<S179>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/parallel_protection_lib'
 * '<S180>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/parallel_protection_lib1'
 * '<S181>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/quat_rectify_lib'
 * '<S182>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/Quaternion Normalize/Quaternion Modulus'
 * '<S183>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S184>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Cross Product4'
 * '<S185>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Cross Product5'
 * '<S186>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Cross Product6'
 * '<S187>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Cross Product7'
 * '<S188>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2'
 * '<S189>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace'
 * '<S190>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Positive Trace'
 * '<S191>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM'
 * '<S192>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/trace(DCM)'
 * '<S193>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S194>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S195>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S196>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/diag(DCM)'
 * '<S197>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S198>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S199>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S200>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S201>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S202>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S203>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S204>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S205>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S206>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S207>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S208>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S209>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S210>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S211>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S212>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S213>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S214>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S215>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error'
 * '<S216>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal'
 * '<S217>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper'
 * '<S218>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotOrthogonal'
 * '<S219>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper'
 * '<S220>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
 * '<S221>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
 * '<S222>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper/Error'
 * '<S223>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/If Not Proper/Warning'
 * '<S224>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
 * '<S225>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
 * '<S226>' : 'Main_Sim/FSW_Lib/MEKF_lib/TriadEstimator_lib/TriadAlgorithm/Direction Cosine Matrix  to Quaternions2/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
 * '<S227>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/command_converter_lib'
 * '<S228>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib'
 * '<S229>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/degree error'
 * '<S230>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/mtq_allocation_lib'
 * '<S231>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib'
 * '<S232>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib'
 * '<S233>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/command_converter_lib/torque-2-RPM'
 * '<S234>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm'
 * '<S235>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation'
 * '<S236>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_null_control'
 * '<S237>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_reorientation'
 * '<S238>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek'
 * '<S239>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/asmController_lib'
 * '<S240>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib'
 * '<S241>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/Normalize Vector'
 * '<S242>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/Subsystem'
 * '<S243>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/Subsystem1'
 * '<S244>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/Subsystem2'
 * '<S245>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/twonorm'
 * '<S246>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_asm/desat_controller_lib/Subsystem2/Cross Product1'
 * '<S247>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/PD_Controller_Lib'
 * '<S248>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib'
 * '<S249>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/Normalize Vector'
 * '<S250>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/Subsystem'
 * '<S251>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/Subsystem1'
 * '<S252>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/Subsystem2'
 * '<S253>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/twonorm'
 * '<S254>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_desaturation/desat_controller_lib/Subsystem2/Cross Product1'
 * '<S255>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_null_control/null_control_lib1'
 * '<S256>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_reorientation/PD_Controller_Lib'
 * '<S257>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek/sunSeek_lib'
 * '<S258>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek/sunSeek_lib/get_error_axis'
 * '<S259>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek/sunSeek_lib/get_error_axis/Cross Product'
 * '<S260>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/control_selection_lib/case_sunseek/sunSeek_lib/get_error_axis/Normalize Vector'
 * '<S261>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem'
 * '<S262>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem1'
 * '<S263>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem2'
 * '<S264>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem3'
 * '<S265>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem4'
 * '<S266>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/mtq_allocation_lib/If Action Subsystem5'
 * '<S267>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Conjugate'
 * '<S268>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication'
 * '<S269>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/quat_rectify_lib'
 * '<S270>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q0'
 * '<S271>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q1'
 * '<S272>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q2'
 * '<S273>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/quat_err_lib/Quaternion Multiplication/q3'
 * '<S274>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/DirPreservingSaturation'
 * '<S275>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem'
 * '<S276>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1'
 * '<S277>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/DirPreservingSaturation/MATLAB Function'
 * '<S278>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/L_inf_allocation_lib'
 * '<S279>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/L_inf_allocation_lib1'
 * '<S280>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/null_allocation_lib'
 * '<S281>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/L_inf_allocation_lib/MATLAB Function'
 * '<S282>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/L_inf_allocation_lib1/MATLAB Function'
 * '<S283>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem/null_allocation_lib/MATLAB Function'
 * '<S284>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/Invert  3x3 Matrix'
 * '<S285>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/MATLAB Function'
 * '<S286>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/MATLAB Function1'
 * '<S287>' : 'Main_Sim/FSW_Lib/control_command_generation_lib/rwa_allocation_lib/If Action Subsystem1/Invert  3x3 Matrix/Determinant of 3x3 Matrix'
 * '<S288>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib'
 * '<S289>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib'
 * '<S290>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sgp4_lib_fsw'
 * '<S291>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sunVectorEclipse_lib'
 * '<S292>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/time_coord_rotations_lib  '
 * '<S293>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position'
 * '<S294>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib'
 * '<S295>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1'
 * '<S296>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED'
 * '<S297>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1'
 * '<S298>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude'
 * '<S299>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap'
 * '<S300>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Radius at Geocentric Latitude'
 * '<S301>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A11'
 * '<S302>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A12'
 * '<S303>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A13'
 * '<S304>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A21'
 * '<S305>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A22'
 * '<S306>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A23'
 * '<S307>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A31'
 * '<S308>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A32'
 * '<S309>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/A33'
 * '<S310>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/Angle Conversion'
 * '<S311>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED/Create Transformation Matrix'
 * '<S312>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A11'
 * '<S313>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A12'
 * '<S314>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A13'
 * '<S315>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A21'
 * '<S316>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A22'
 * '<S317>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A23'
 * '<S318>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A31'
 * '<S319>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A32'
 * '<S320>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/A33'
 * '<S321>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/Angle Conversion'
 * '<S322>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Direction Cosine Matrix ECI to NED1/Create Transformation Matrix'
 * '<S323>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Conversion'
 * '<S324>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Conversion1'
 * '<S325>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Conversion2'
 * '<S326>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Latitude Wrap 90'
 * '<S327>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Radius at Geocentric Latitude'
 * '<S328>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Geodetic to  Geocentric Latitude/Radius at Geocentric Latitude/Conversion'
 * '<S329>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Latitude Wrap 90'
 * '<S330>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Wrap Longitude'
 * '<S331>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S332>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S333>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S334>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S335>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/LLA to ECEF Position/Radius at Geocentric Latitude/Conversion'
 * '<S336>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/Compare To Constant'
 * '<S337>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/Normalize Vector'
 * '<S338>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/Normalize Vector1'
 * '<S339>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/get_C_F2T'
 * '<S340>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/twonorm'
 * '<S341>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib/get_C_F2T/Create 3x3 Matrix'
 * '<S342>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/Compare To Constant'
 * '<S343>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/Normalize Vector'
 * '<S344>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/Normalize Vector1'
 * '<S345>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/get_C_F2T'
 * '<S346>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/twonorm'
 * '<S347>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/groundpass_predict_lib/target_groundpass_lib1/get_C_F2T/Create 3x3 Matrix'
 * '<S348>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1'
 * '<S349>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA'
 * '<S350>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/MATLAB Function'
 * '<S351>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/magField_custom_lib'
 * '<S352>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A11'
 * '<S353>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A12'
 * '<S354>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A13'
 * '<S355>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A21'
 * '<S356>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A22'
 * '<S357>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A23'
 * '<S358>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A31'
 * '<S359>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A32'
 * '<S360>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/A33'
 * '<S361>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/Angle Conversion'
 * '<S362>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/Direction Cosine Matrix ECEF to NED1/Create Transformation Matrix'
 * '<S363>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/Conversion'
 * '<S364>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/Subsystem2'
 * '<S365>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/Subsystem3'
 * '<S366>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/While Iterator Subsystem'
 * '<S367>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/e^1'
 * '<S368>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/e^2'
 * '<S369>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/e^3'
 * '<S370>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/While Iterator Subsystem/Subsystem2'
 * '<S371>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/While Iterator Subsystem/Subsystem3'
 * '<S372>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/ECEF Position to LLA/While Iterator Subsystem/Subsystem4'
 * '<S373>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/magField_lib/magField_custom_lib/MATLAB Function'
 * '<S374>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sgp4_lib_fsw/MATLAB Function'
 * '<S375>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sunVectorEclipse_lib/MATLAB Function'
 * '<S376>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sunVectorEclipse_lib/Normalize Vector'
 * '<S377>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sunVectorEclipse_lib/eclipseCheck_lib'
 * '<S378>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/sunVectorEclipse_lib/eclipseCheck_lib/MATLAB Function'
 * '<S379>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/time_coord_rotations_lib  /MATLAB Function3'
 * '<S380>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/time_coord_rotations_lib  /coord_rotations_lib'
 * '<S381>' : 'Main_Sim/FSW_Lib/environmentEstimation_lib/time_coord_rotations_lib  /coord_rotations_lib/MATLAB Function'
 * '<S382>' : 'Main_Sim/FSW_Lib/mode_select_lib/RPM_2_desat_check'
 * '<S383>' : 'Main_Sim/FSW_Lib/mode_select_lib/Subsystem'
 * '<S384>' : 'Main_Sim/FSW_Lib/mode_select_lib/mode_select'
 * '<S385>' : 'Main_Sim/FSW_Lib/mode_select_lib/twonorm'
 * '<S386>' : 'Main_Sim/FSW_Lib/mode_select_lib/RPM_2_desat_check/twonorm1'
 * '<S387>' : 'Main_Sim/FSW_Lib/mode_select_lib/Subsystem/Compare To Constant'
 * '<S388>' : 'Main_Sim/FSW_Lib/mode_select_lib/Subsystem/Compare To Constant1'
 * '<S389>' : 'Main_Sim/FSW_Lib/mode_select_lib/Subsystem/Compare To Constant2'
 * '<S390>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions'
 * '<S391>' : 'Main_Sim/FSW_Lib/target_generation_lib/Map to BodyFrame Momentum'
 * '<S392>' : 'Main_Sim/FSW_Lib/target_generation_lib/Normalize Vector1'
 * '<S393>' : 'Main_Sim/FSW_Lib/target_generation_lib/quat_rectify_lib'
 * '<S394>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib'
 * '<S395>' : 'Main_Sim/FSW_Lib/target_generation_lib/target_gen'
 * '<S396>' : 'Main_Sim/FSW_Lib/target_generation_lib/target_gen_logic_lib'
 * '<S397>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace'
 * '<S398>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace'
 * '<S399>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM'
 * '<S400>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/trace(DCM)'
 * '<S401>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S402>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S403>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S404>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/diag(DCM)'
 * '<S405>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S406>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S407>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S408>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S409>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S410>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S411>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S412>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S413>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S414>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S415>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S416>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S417>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S418>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S419>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S420>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S421>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S422>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S423>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error'
 * '<S424>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal'
 * '<S425>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper'
 * '<S426>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal'
 * '<S427>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper'
 * '<S428>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
 * '<S429>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
 * '<S430>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Error'
 * '<S431>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Warning'
 * '<S432>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
 * '<S433>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
 * '<S434>' : 'Main_Sim/FSW_Lib/target_generation_lib/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
 * '<S435>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/Compare To Constant'
 * '<S436>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/Detect Rise Positive'
 * '<S437>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_interp'
 * '<S438>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_lib'
 * '<S439>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/Detect Rise Positive/Positive'
 * '<S440>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_interp/soar_INTERP'
 * '<S441>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_lib/INITIALIZE'
 * '<S442>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_lib/SOLVE'
 * '<S443>' : 'Main_Sim/FSW_Lib/target_generation_lib/soar_interface_lib/soar_lib/call to ECOS SOCP solver (compiled C function)'
 * '<S444>' : 'Main_Sim/FSW_Lib/target_generation_lib/target_gen_logic_lib/Compare To Constant'
 * '<S445>' : 'Main_Sim/FSW_Lib/target_generation_lib/target_gen_logic_lib/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_FSW_Lib0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
