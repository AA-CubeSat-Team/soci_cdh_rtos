/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSW_Lib0_private.h
 *
 * Code generated for Simulink model 'FSW_Lib0'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr 17 16:27:21 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FSW_Lib0_private_h_
#define RTW_HEADER_FSW_Lib0_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "FSW_Lib0.h"

extern const real_T rtCP_pooled_IugXtwH1hUEH[9];
extern const real_T rtCP_pooled_DECzJ8kbJsmr[9];
extern const real_T rtCP_pooled_1flyXRJuZEb5[9];
extern const real_T rtCP_pooled_8C7XRlVrxmwu[9];
extern const real_T rtCP_pooled_ZfDBypHgOeGj[9];
extern const real_T rtCP_pooled_h9xDo34tXKiL[36];
extern const real_T rtCP_pooled_FEWufo6vVHrj[9];
extern const real_T rtCP_pooled_Da55ZxuBKuX2[36];
extern const real_T rtCP_pooled_t5FveOUIZnGM[36];
extern const real_T rtCP_pooled_gvk5RxEQBycj[9];
extern const real_T rtCP_pooled_pT9epSenClvy[9];
extern const real_T rtCP_pooled_nw91sARCHMv7[9];
extern const real_T rtCP_pooled_0RsXyt3gOemN[12];
extern const real_T rtCP_pooled_OaIvzZJq11xx[9];
extern const real_T rtCP_pooled_JgFDSFSbPMVr[3];

#define rtCP_pooled1                   rtCP_pooled_IugXtwH1hUEH  /* Pooled Parameter (Mixed Expressions)
                                                                  * Referenced by:
                                                                  *   '<S2>/maggyroProcessing_lib'
                                                                  *   '<S2>/maggyroProcessing_lib1'
                                                                  */
#define rtCP_Constant_Value_ps         rtCP_pooled_DECzJ8kbJsmr  /* Expression: rotation_calibration_matrix(:,:,1)
                                                                  * Referenced by: '<S15>/Constant'
                                                                  */
#define rtCP_Constant2_Value           rtCP_pooled_1flyXRJuZEb5  /* Expression: rotation_calibration_matrix(:,:,3)
                                                                  * Referenced by: '<S15>/Constant2'
                                                                  */
#define rtCP_Constant1_Value           rtCP_pooled_8C7XRlVrxmwu  /* Expression: rotation_calibration_matrix(:,:,2)
                                                                  * Referenced by: '<S15>/Constant1'
                                                                  */
#define rtCP_Constant_Value_a          rtCP_pooled_ZfDBypHgOeGj  /* Expression: rotation_calibration_matrix(:,:,1)
                                                                  * Referenced by: '<S59>/Constant'
                                                                  */
#define rtCP_Constant2_Value_b         rtCP_pooled_ZfDBypHgOeGj  /* Expression: rotation_calibration_matrix(:,:,3)
                                                                  * Referenced by: '<S59>/Constant2'
                                                                  */
#define rtCP_Constant1_Value_e         rtCP_pooled_ZfDBypHgOeGj  /* Expression: rotation_calibration_matrix(:,:,2)
                                                                  * Referenced by: '<S59>/Constant1'
                                                                  */
#define rtCP_Constant_Value_gu         rtCP_pooled_h9xDo34tXKiL  /* Expression: fswParams.estimation.Rchol
                                                                  * Referenced by: '<S109>/Constant'
                                                                  */
#define rtCP_Bias1_Bias                rtCP_pooled_FEWufo6vVHrj  /* Expression: -eye(3)
                                                                  * Referenced by: '<S203>/Bias1'
                                                                  */
#define rtCP_UnitDelay_InitialConditi_e rtCP_pooled_Da55ZxuBKuX2 /* Expression: fswParams.estimation.ic.Pchol_init
                                                                  * Referenced by: '<S3>/Unit Delay'
                                                                  */
#define rtCP_Constant13_Value          rtCP_pooled_t5FveOUIZnGM  /* Expression: fswParams.estimation.Qchol
                                                                  * Referenced by: '<S112>/Constant13'
                                                                  */
#define rtCP_Constant_Value_c          rtCP_pooled_gvk5RxEQBycj  /* Expression: fswParams.controllers.asmc.C
                                                                  * Referenced by: '<S223>/Constant'
                                                                  */
#define rtCP_Kp_Gain                   rtCP_pooled_pT9epSenClvy  /* Expression: fswParams.controllers.sunseek.Kp
                                                                  * Referenced by: '<S239>/Kp'
                                                                  */
#define rtCP_Kd_Gain                   rtCP_pooled_nw91sARCHMv7  /* Expression: fswParams.controllers.sunseek.Kd
                                                                  * Referenced by: '<S239>/Kd'
                                                                  */
#define rtCP_Constant_Value_dp         rtCP_pooled_0RsXyt3gOemN  /* Expression: fswParams.allocator.A_wheel2body
                                                                  * Referenced by: '<S251>/Constant'
                                                                  */
#define rtCP_A_wheel2body_Value        rtCP_pooled_0RsXyt3gOemN  /* Expression: fswParams.allocator.A_wheel2body
                                                                  * Referenced by: '<S365>/A_wheel2body'
                                                                  */
#define rtCP_Constant1_Value_h         rtCP_pooled_OaIvzZJq11xx  /* Expression: simParams.sensors.sun_sensor.ss2body
                                                                  * Referenced by: '<S14>/Constant1'
                                                                  */
#define rtCP_Constant_Value_jp         rtCP_pooled_JgFDSFSbPMVr  /* Expression: fswParams.ground_targs(1).ecef_m
                                                                  * Referenced by: '<S261>/Constant'
                                                                  */

extern void run_ecos(int32_T rtu_n, int32_T rtu_m, int32_T rtu_p, int32_T rtu_l,
                     int32_T rtu_ncones, const real_T rtu_c[332], const int32_T
                     rtu_Gjc[333], const int32_T rtu_Gir[834], const real_T
                     rtu_Gpr[834], const real_T rtu_h[474], const int32_T rtu_q
                     [21], const int32_T rtu_Ajc[333], const int32_T rtu_Air
                     [1278], const real_T rtu_Apr[1278], const real_T rtu_b[117],
                     real_T rty_y[334]);

#endif                                 /* RTW_HEADER_FSW_Lib0_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
