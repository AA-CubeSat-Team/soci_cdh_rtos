/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: maggyroProcessing_lib.h
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

#ifndef RTW_HEADER_maggyroProcessing_lib_h_
#define RTW_HEADER_maggyroProcessing_lib_h_
#ifndef FSW_Lib0_COMMON_INCLUDES_
# define FSW_Lib0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ecos.h"
#endif                                 /* FSW_Lib0_COMMON_INCLUDES_ */

#include "FSW_Lib0_types.h"

/* Child system includes */
#include "twonorm.h"
#include "rt_assert.h"

/* Block signals and states (default storage) for system '<S2>/maggyroProcessing_lib' */
typedef struct {
  real_T VectorConcatenate[9];         /* '<S22>/Vector Concatenate' */
  real_T VariableSelector1[3];         /* '<S22>/Variable Selector1' */
  real_T VariableSelector2[3];         /* '<S22>/Variable Selector2' */
  real_T VariableSelector6[3];         /* '<S25>/Variable Selector6' */
  real_T VariableSelector7[3];         /* '<S25>/Variable Selector7' */
  real_T VariableSelector8[3];         /* '<S25>/Variable Selector8' */
  real_T VariableSelector3[3];         /* '<S23>/Variable Selector3' */
  real_T VariableSelector4[3];         /* '<S23>/Variable Selector4' */
  real_T VariableSelector5[3];         /* '<S23>/Variable Selector5' */
  real_T Median[3];                    /* '<S26>/Median' */
  real_T Sqrt_l;                       /* '<S45>/Sqrt' */
  real_T Sqrt_gc;                      /* '<S50>/Sqrt' */
  real_T Sqrt_i;                       /* '<S51>/Sqrt' */
  real_T rtb_Merge_jh_idx_0;
  real_T rtb_Merge_jh_idx_1;
  uint32_T Median_Index[3];            /* '<S26>/Median' */
  void* Assertion_slioAccessor;        /* '<S36>/Assertion' */
  void* Assertion_slioAccessor_h;      /* '<S35>/Assertion' */
  void* Assertion_slioAccessor_d;      /* '<S34>/Assertion' */
} DW_maggyroProcessing_lib;

/* Parameters for system: '<S24>/If Action Subsystem14' */
struct P_IfActionSubsystem14_ {
  real_T Constant_Value[3];            /* Expression: [0;0;0]
                                        * Referenced by: '<S29>/Constant'
                                        */
};

/* Parameters for system: '<S25>/If Action Subsystem2' */
struct P_IfActionSubsystem2_ {
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S40>/Constant'
                                        */
};

/* Parameters for system: '<S2>/maggyroProcessing_lib' */
struct P_maggyroProcessing_lib_ {
  real_T CheckStaticRange1_min;        /* Mask Parameter: CheckStaticRange1_min
                                        * Referenced by: '<S34>/min_val'
                                        */
  real_T CheckStaticRange2_min;        /* Mask Parameter: CheckStaticRange2_min
                                        * Referenced by: '<S35>/min_val'
                                        */
  real_T CheckStaticRange4_min;        /* Mask Parameter: CheckStaticRange4_min
                                        * Referenced by: '<S36>/min_val'
                                        */
  real_T Constant_Value[3];            /* Expression: [0;0;0]
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Constant_Value_g[3];          /* Expression: [0;0;0]
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Constant_Value_c[3];          /* Expression: [0;0;0]
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S27>/Gain1'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 1
                                        * Referenced by: '<S24>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/3
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Constant_Value_j[9];          /* Expression: rotation_calibration_matrix(:,:,1)
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant2_Value[9];           /* Expression: rotation_calibration_matrix(:,:,3)
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T Constant1_Value[9];           /* Expression: rotation_calibration_matrix(:,:,2)
                                        * Referenced by: '<S22>/Constant1'
                                        */
  int32_T VariableSelector_Elements;   /* Computed Parameter: VariableSelector_Elements
                                        * Referenced by: '<S26>/Variable Selector'
                                        */
  int32_T VariableSelector1_Elements;  /* Computed Parameter: VariableSelector1_Elements
                                        * Referenced by: '<S26>/Variable Selector1'
                                        */
  int32_T VariableSelector2_Elements;  /* Computed Parameter: VariableSelector2_Elements
                                        * Referenced by: '<S26>/Variable Selector2'
                                        */
  int32_T VariableSelector6_Elements;  /* Computed Parameter: VariableSelector6_Elements
                                        * Referenced by: '<S27>/Variable Selector6'
                                        */
  int32_T VariableSelector7_Elements;  /* Computed Parameter: VariableSelector7_Elements
                                        * Referenced by: '<S27>/Variable Selector7'
                                        */
  int32_T VariableSelector8_Elements;  /* Computed Parameter: VariableSelector8_Elements
                                        * Referenced by: '<S27>/Variable Selector8'
                                        */
  int32_T VariableSelector6_Elements_m;/* Computed Parameter: VariableSelector6_Elements_m
                                        * Referenced by: '<S24>/Variable Selector6'
                                        */
  int32_T VariableSelector7_Elements_b;/* Computed Parameter: VariableSelector7_Elements_b
                                        * Referenced by: '<S24>/Variable Selector7'
                                        */
  int32_T VariableSelector8_Elements_g;/* Computed Parameter: VariableSelector8_Elements_g
                                        * Referenced by: '<S24>/Variable Selector8'
                                        */
  int32_T VariableSelector3_Elements;  /* Computed Parameter: VariableSelector3_Elements
                                        * Referenced by: '<S23>/Variable Selector3'
                                        */
  int32_T VariableSelector4_Elements;  /* Computed Parameter: VariableSelector4_Elements
                                        * Referenced by: '<S23>/Variable Selector4'
                                        */
  int32_T VariableSelector5_Elements;  /* Computed Parameter: VariableSelector5_Elements
                                        * Referenced by: '<S23>/Variable Selector5'
                                        */
  int32_T VariableSelector1_Elements_b;/* Computed Parameter: VariableSelector1_Elements_b
                                        * Referenced by: '<S22>/Variable Selector1'
                                        */
  int32_T VariableSelector2_Elements_g;/* Computed Parameter: VariableSelector2_Elements_g
                                        * Referenced by: '<S22>/Variable Selector2'
                                        */
  int32_T VariableSelector_Elements_e; /* Computed Parameter: VariableSelector_Elements_e
                                        * Referenced by: '<S22>/Variable Selector'
                                        */
  int32_T VariableSelector6_Elements_o;/* Computed Parameter: VariableSelector6_Elements_o
                                        * Referenced by: '<S25>/Variable Selector6'
                                        */
  int32_T VariableSelector7_Elements_c;/* Computed Parameter: VariableSelector7_Elements_c
                                        * Referenced by: '<S25>/Variable Selector7'
                                        */
  int32_T VariableSelector8_Elements_e;/* Computed Parameter: VariableSelector8_Elements_e
                                        * Referenced by: '<S25>/Variable Selector8'
                                        */
  boolean_T Constant_Value_js;         /* Expression: true
                                        * Referenced by: '<S24>/Constant'
                                        */
  boolean_T Constant_Value_f;          /* Expression: false
                                        * Referenced by: '<S23>/Constant'
                                        */
  P_IfActionSubsystem2 IfActionSubsystem14_d;/* '<S25>/If Action Subsystem14' */
  P_IfActionSubsystem2 IfActionSubsystem4;/* '<S25>/If Action Subsystem4' */
  P_IfActionSubsystem2 IfActionSubsystem2_p;/* '<S25>/If Action Subsystem2' */
  P_IfActionSubsystem14 IfActionSubsystem2_k;/* '<S24>/If Action Subsystem2' */
  P_IfActionSubsystem14 IfActionSubsystem1_o;/* '<S24>/If Action Subsystem1' */
  P_IfActionSubsystem14 IfActionSubsystem14_n;/* '<S24>/If Action Subsystem14' */
};

extern void IfActionSubsystem14(real_T rty_nullOut[3], P_IfActionSubsystem14
  *localP);
extern void IfActionSubsystem2(boolean_T *rty_Out1, P_IfActionSubsystem2 *localP);
extern void maggyroProcessing_lib_Init(DW_maggyroProcessing_lib *localDW);
extern void maggyroProcessing_lib(const real_T rtu_sensor_meas_data[9], const
  boolean_T rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T *
  rty_sensor_valid, DW_maggyroProcessing_lib *localDW, P_maggyroProcessing_lib
  *localP, real_T rtp_max_err, const real_T rtp_offset_calibration_matrix[9],
  real_T rtp_static_range_max_value, real_T rtp_Gain);

#endif                                 /* RTW_HEADER_maggyroProcessing_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
