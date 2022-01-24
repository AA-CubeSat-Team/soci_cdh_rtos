/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MEKF_lib.h
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

#ifndef RTW_HEADER_MEKF_lib_h_
#define RTW_HEADER_MEKF_lib_h_
#include <math.h>
#include <string.h>
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Child system includes */
#include "CrossProdMatrix_lib.h"
#include "TRIADActivation_lib.h"
#include "parallel_protection_lib.h"
#include "quat_rectify_lib.h"
#include "rt_sys_MEKF_lib_39.h"
#include "rt_sys_MEKF_lib_49.h"
#include "rt_sys_MEKF_lib_56.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* Block signals and states (default storage) for system '<S1>/MEKF_lib' */
typedef struct {
  DW_IfWarningError IfWarningError_o;  /* '<S191>/If Warning//Error' */
  DW_TRIADActivation_lib TRIADActivation_lib_f;/* '<S3>/TRIADActivation_lib' */
  dsp_private_SlidingWindowAverag gobj_0;/* '<S121>/Moving Average' */
  dsp_private_SlidingWindowAverag gobj_1;/* '<S121>/Moving Average' */
  dsp_simulink_MovingAverage obj;      /* '<S121>/Moving Average' */
  real_T Id_3[9];                      /* '<S165>/Id_3' */
  real_T Merge[4];                     /* '<S188>/Merge' */
  real_T UnitDelay_DSTATE[36];         /* '<S3>/Unit Delay' */
  real_T UnitDelay1_DSTATE[3];         /* '<S3>/Unit Delay1' */
  real_T UnitDelay3_DSTATE[4];         /* '<S3>/Unit Delay3' */
  real_T UnitDelay_DSTATE_g[4];        /* '<S125>/Unit Delay' */
  real_T unusedU2[144];
  real_T R[144];
  real_T dv0[144];
  real_T b_A[144];
  real_T C[72];
  real_T P_chol_p_merge[36];           /* '<S3>/P_chol_p_merge' */
  real_T Phi[36];                      /* '<S124>/CreateStateTransitionMatrix' */
  real_T rtb_P_chol_p_merge_m[36];
  real_T MatrixConcatenate2_i[16];     /* '<S165>/Matrix Concatenate2' */
  real_T VectorConcatenate_d[12];      /* '<S137>/Vector Concatenate' */
  real_T unusedExpr[12];
  real_T tau[12];
  real_T work[12];
  real_T work_c[12];
  real_T MatrixConcatenate3[9];        /* '<S177>/Matrix Concatenate3' */
  real_T MathFunction1_k[9];           /* '<S177>/Math Function1' */
  real_T MatrixMultiply1[9];           /* '<S177>/Matrix Multiply1' */
  real_T sigma[6];                     /* '<S123>/Sqrt' */
  real_T Elementproduct_g[6];          /* '<S184>/Element product' */
  real_T TmpSignalConversionAtquat_e[4];/* '<S125>/Quaternion Normalize' */
  real_T Merge_i[4];                   /* '<S116>/Merge' */
  real_T MathFunction_j[3];            /* '<S175>/Math Function' */
  real_T MathFunction_p[3];            /* '<S174>/Math Function' */
  real_T b_A_k[36];
  real_T work_cx[12];
  real_T Product3_j;                   /* '<S176>/Product3' */
  real_T Product2_da;                  /* '<S176>/Product2' */
  real_T Product1_f;                   /* '<S176>/Product1' */
  real_T Product8;                     /* '<S152>/Product8' */
  real_T Product1_k;                   /* '<S150>/Product1' */
  real_T Product3_pe;                  /* '<S143>/Product3' */
  real_T Product2_at;                  /* '<S143>/Product2' */
  real_T Product1_kn;                  /* '<S143>/Product1' */
  real_T sqrt_m;                       /* '<S142>/sqrt' */
  real_T Add_h;                        /* '<S192>/Add' */
  real_T rtb_Product5_b_b;
  real_T rtb_Product1_kn_tmp;
  real_T rtb_sqrt_m_tmp;
  real_T rtb_sqrt_m_tmp_p;
  real_T b_atmp;
  real_T xnorm;
  real_T temp;
  real_T smax;
  real_T s;
  real_T b_atmp_c;
  real_T xnorm_f;
  real_T c;
  real_T scale;
  int32_T idxStart;
  int32_T i;
  int32_T rtb_MatrixMultiply1_tmp;
  int32_T rtb_MatrixMultiply1_tmp_g;
  int32_T d_i;
  int32_T itau;
  int32_T iaii;
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T i_i;
  int32_T i_g;
  int32_T knt;
  int32_T lastv_m;
  int32_T lastc_n;
  int8_T Phi_22[9];
  int8_T b_I[9];
  int8_T ipiv[6];
  int8_T TRIAD_activation_ActiveSubsyste;/* '<S3>/TRIAD_activation' */
  boolean_T DelayInput1_DSTATE;        /* '<S157>/Delay Input1' */
  boolean_T objisempty;                /* '<S121>/Moving Average' */
} DW_MEKF_lib;

/* Parameters for system: '<S1>/MEKF_lib' */
struct P_MEKF_lib_ {
  real_T Normalization6_Bias;          /* Mask Parameter: Normalization6_Bias
                                        * Referenced by: '<S177>/Normalization6'
                                        */
  real_T Normalization7_Bias;          /* Mask Parameter: Normalization7_Bias
                                        * Referenced by: '<S177>/Normalization7'
                                        */
  real_T DirectionCosineMatrixtoQuaterni;/* Mask Parameter: DirectionCosineMatrixtoQuaterni
                                          * Referenced by:
                                          *   '<S191>/If Warning//Error'
                                          *   '<S191>/Constant'
                                          */
  real_T NormalizeVector1_maxzero;     /* Mask Parameter: NormalizeVector1_maxzero
                                        * Referenced by: '<S175>/Switch'
                                        */
  real_T NormalizeVector_maxzero;      /* Mask Parameter: NormalizeVector_maxzero
                                        * Referenced by: '<S174>/Switch'
                                        */
  real_T DirectionCosineMatrixtoQuater_o;/* Mask Parameter: DirectionCosineMatrixtoQuater_o
                                          * Referenced by: '<S191>/If Warning//Error'
                                          */
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S157>/Delay Input1'
                                        */
  uint8_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S117>/Constant'
                                        */
  uint8_T CompareToConstant_const_b;   /* Mask Parameter: CompareToConstant_const_b
                                        * Referenced by: '<S156>/Constant'
                                        */
  uint8_T CompareToConstant_const_n;   /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S128>/Constant'
                                        */
  real_T Constant_Value[3];            /* Expression: [0;0;0]
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: 0.5
                                        * Referenced by: '<S145>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2
                                        * Referenced by: '<S145>/Gain2'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S145>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S145>/Gain1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 2
                                        * Referenced by: '<S146>/Gain'
                                        */
  real_T Constant_Value_b;             /* Expression: 0.5
                                        * Referenced by: '<S146>/Constant'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: 2
                                        * Referenced by: '<S146>/Gain2'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 2
                                        * Referenced by: '<S146>/Gain1'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 2
                                        * Referenced by: '<S147>/Gain'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 2
                                        * Referenced by: '<S147>/Gain1'
                                        */
  real_T Constant_Value_h;             /* Expression: 0.5
                                        * Referenced by: '<S147>/Constant'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: 2
                                        * Referenced by: '<S147>/Gain2'
                                        */
  real_T Constant_Value_bh;            /* Expression: 0.5
                                        * Referenced by: '<S151>/Constant'
                                        */
  real_T Gain2_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S151>/Gain2'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 2
                                        * Referenced by: '<S151>/Gain'
                                        */
  real_T Gain1_Gain_bj;                /* Expression: 2
                                        * Referenced by: '<S151>/Gain1'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 2
                                        * Referenced by: '<S152>/Gain'
                                        */
  real_T Constant_Value_cg;            /* Expression: 0.5
                                        * Referenced by: '<S152>/Constant'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 2
                                        * Referenced by: '<S152>/Gain2'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 2
                                        * Referenced by: '<S152>/Gain1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 2
                                        * Referenced by: '<S153>/Gain'
                                        */
  real_T Gain1_Gain_oh;                /* Expression: 2
                                        * Referenced by: '<S153>/Gain1'
                                        */
  real_T Constant_Value_m;             /* Expression: 0.5
                                        * Referenced by: '<S153>/Constant'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S153>/Gain2'
                                        */
  real_T Constant1_Value[9];           /* Expression: zeros(3,3)
                                        * Referenced by: '<S132>/Constant1'
                                        */
  real_T Constant2_Value[9];           /* Expression: zeros(3,3)
                                        * Referenced by: '<S132>/Constant2'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S137>/Gain'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: -1
                                        * Referenced by: '<S137>/Gain1'
                                        */
  real_T Gain2_Gain_ld;                /* Expression: -1
                                        * Referenced by: '<S137>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S137>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S137>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: -1
                                        * Referenced by: '<S137>/Gain5'
                                        */
  real_T Gain6_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S137>/Gain6'
                                        */
  real_T Merge_InitialOutput[4];       /* Expression: [1 0 0 0]
                                        * Referenced by: '<S188>/Merge'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S174>/Constant'
                                        */
  real_T Constant_Value_cb;            /* Expression: 1
                                        * Referenced by: '<S175>/Constant'
                                        */
  real_T Constant_Value_g[3];          /* Expression: zeros(3,1)
                                        * Referenced by: '<S171>/Constant'
                                        */
  real_T Constant_Value_hd;            /* Expression: 0.5
                                        * Referenced by: '<S170>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: 0.5
                                        * Referenced by: '<S165>/Constant'
                                        */
  real_T Gain_Gain_ne;                 /* Expression: -1
                                        * Referenced by: '<S165>/Gain'
                                        */
  real_T multiply_Gain;                /* Expression: 3
                                        * Referenced by: '<S123>/multiply'
                                        */
  real_T q_p_merge_InitialOutput;      /* Computed Parameter: q_p_merge_InitialOutput
                                        * Referenced by: '<S3>/q_p_merge'
                                        */
  real_T Switch_Threshold;             /* Expression: 2
                                        * Referenced by: '<S121>/Switch'
                                        */
  boolean_T Constant_Value_d;          /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S158>/Constant'
                                        */
  uint8_T Constant_Value_m0;           /* Computed Parameter: Constant_Value_m0
                                        * Referenced by: '<S129>/Constant'
                                        */
  uint8_T cnst_Value;                  /* Computed Parameter: cnst_Value
                                        * Referenced by: '<S131>/cnst'
                                        */
  P_quat_rectify_lib quat_rectify_lib_c;/* '<S124>/quat_rectify_lib' */
  P_CrossProdMatrix_lib_g CrossProdMatrix_lib1;/* '<S124>/CrossProdMatrix_lib1' */
  P_CrossProdMatrix_lib_g CrossProdMatrix_lib_mu;/* '<S124>/CrossProdMatrix_lib' */
  P_quat_rectify_lib quat_rectify_lib_m;/* '<S125>/quat_rectify_lib' */
  P_parallel_protection_lib parallel_protection_lib1;/* '<S125>/parallel_protection_lib1' */
  P_parallel_protection_lib parallel_protection_lib_c;/* '<S125>/parallel_protection_lib' */
  P_IfWarningError IfWarningError_o;   /* '<S191>/If Warning//Error' */
  P_NegativeTrace NegativeTrace_g;     /* '<S188>/Negative Trace' */
  P_PositiveTrace PositiveTrace_a;     /* '<S188>/Positive Trace' */
  P_TRIADActivation_lib TRIADActivation_lib_f;/* '<S3>/TRIADActivation_lib' */
  P_CrossProdMatrix_lib CrossProdMatrix_lib1_j;/* '<S132>/CrossProdMatrix_lib1' */
  P_CrossProdMatrix_lib CrossProdMatrix_lib_ma;/* '<S132>/CrossProdMatrix_lib' */
  P_parallel_protection_lib parallel_protection_lib_d;/* '<S115>/parallel_protection_lib' */
};

extern void MEKF_lib_Init(real_T rty_sc_quat[4], DW_MEKF_lib *localDW,
  P_MEKF_lib *localP);
extern void MEKF_lib_Start(DW_MEKF_lib *localDW);
extern void MEKF_lib(const real_T rtu_sc2sun_eci_unit[3], const real_T
                     rtu_mag_eci_T[3], const real_T rtu_sun_meas_body_unit[3],
                     const real_T rtu_mag_meas_body_T[3], const real_T
                     rtu_gyro_meas_body_radps[3], uint8_T rtu_sunsensor_valid,
                     boolean_T rtu_mag_meas_valid, boolean_T rtu_gryo_meas_valid,
                     boolean_T rtu_triad_activate, real_T rty_sc_quat[4], real_T
                     rty_body_rates_radps[3], real_T rty_threeSigma_rad[6],
                     real_T rty_bias_radps[3], uint8_T *rty_mekf_telem,
                     DW_MEKF_lib *localDW, P_MEKF_lib *localP);

#endif                                 /* RTW_HEADER_MEKF_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
