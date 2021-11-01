/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: L_inf_allocation_lib.c
 *
 * Code generated for Simulink model 'FSW_Lib'.
 *
 * Model version                  : 1.374
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Oct 26 16:29:45 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "L_inf_allocation_lib.h"

/* Include model header file for global data */
#include "FSW_Lib.h"
#include "FSW_Lib_private.h"

/*
 * Output and update for atomic system:
 *    '<S275>/L_inf_allocation_lib'
 *    '<S275>/L_inf_allocation_lib1'
 */
void L_inf_allocation_lib(const real_T rtu_input_body[3], real_T
  rty_output_wheel[4])
{
  real_T val;
  uint8_T id;
  real_T w_i_H;
  real_T w_j_H;
  real_T w_i_j;
  int32_T k;
  int32_T val_tmp;
  int32_T w_i_H_tmp;
  int32_T w_j_H_tmp;
  real_T w_j_H_tmp_0;
  real_T w_i_H_tmp_0;
  real_T w_j_H_tmp_1;
  real_T val_tmp_0;
  real_T val_tmp_1;

  /* MATLAB Function: '<S278>/MATLAB Function' incorporates:
   *  Constant: '<S278>/Constant'
   */
  val = 0.0;
  id = 1U;
  for (k = 1; k - 1 < 6; k++) {
    w_i_H_tmp = ((uint8_T)k - 1) * 3;
    w_i_H = fabs((rtConstP.Constant_Value.w_facet[w_i_H_tmp + 1] *
                  rtu_input_body[1] + rtConstP.Constant_Value.w_facet[w_i_H_tmp]
                  * rtu_input_body[0]) +
                 rtConstP.Constant_Value.w_facet[w_i_H_tmp + 2] *
                 rtu_input_body[2]);
    if (w_i_H > val) {
      val = w_i_H;
      id = (uint8_T)k;
    }
  }

  k = id - 1;
  val_tmp = k * 3;
  val_tmp_0 = rtConstP.Constant_Value.w_facet[val_tmp + 1];
  val_tmp_1 = rtConstP.Constant_Value.w_facet[val_tmp + 2];
  val = (val_tmp_0 * rtu_input_body[1] + rtConstP.Constant_Value.w_facet[val_tmp]
         * rtu_input_body[0]) + val_tmp_1 * rtu_input_body[2];
  val_tmp = rtConstP.Constant_Value.id_facet[k] - 1;
  w_i_H_tmp = val_tmp * 3;
  w_i_j = rtConstP.Constant_Value.A_wheel2body[w_i_H_tmp + 1];
  w_i_H_tmp_0 = rtConstP.Constant_Value.A_wheel2body[w_i_H_tmp + 2];
  w_i_H = (w_i_j * rtu_input_body[1] +
           rtConstP.Constant_Value.A_wheel2body[w_i_H_tmp] * rtu_input_body[0])
    + w_i_H_tmp_0 * rtu_input_body[2];
  w_i_H_tmp = rtConstP.Constant_Value.id_facet[id + 5] - 1;
  w_j_H_tmp = w_i_H_tmp * 3;
  w_j_H_tmp_0 = rtConstP.Constant_Value.A_wheel2body[w_j_H_tmp + 1];
  w_j_H_tmp_1 = rtConstP.Constant_Value.A_wheel2body[w_j_H_tmp + 2];
  w_j_H = (w_j_H_tmp_0 * rtu_input_body[1] +
           rtConstP.Constant_Value.A_wheel2body[w_j_H_tmp] * rtu_input_body[0])
    + w_j_H_tmp_1 * rtu_input_body[2];
  w_i_j = (w_i_j * w_j_H_tmp_0 + rtConstP.Constant_Value.A_wheel2body
           [(rtConstP.Constant_Value.id_facet[id - 1] - 1) * 3] *
           rtConstP.Constant_Value.A_wheel2body
           [(rtConstP.Constant_Value.id_facet[id + 5] - 1) * 3]) + w_i_H_tmp_0 *
    w_j_H_tmp_1;
  rty_output_wheel[0] = 0.0;
  rty_output_wheel[1] = 0.0;
  rty_output_wheel[2] = 0.0;
  rty_output_wheel[3] = 0.0;
  w_i_H_tmp_0 = rtConstP.Constant_Value.g_facet[k] * val;
  rty_output_wheel[val_tmp] = (w_i_H - w_i_j * w_j_H) *
    rtConstP.Constant_Value.inrm2[k] - w_i_H_tmp_0;
  rty_output_wheel[w_i_H_tmp] = (w_j_H - w_i_j * w_i_H) *
    rtConstP.Constant_Value.inrm2[id - 1] - w_i_H_tmp_0;
  for (k = 0; k < 2; k++) {
    w_i_H_tmp = (rtConstP.Constant_Value.id_facet_complement[(6 * k + id) - 1] -
                 1) * 3;
    w_i_H = (rtConstP.Constant_Value.A_wheel2body[w_i_H_tmp + 1] * val_tmp_0 +
             rtConstP.Constant_Value.A_wheel2body[w_i_H_tmp] *
             rtConstP.Constant_Value.w_facet[(id - 1) * 3]) +
      rtConstP.Constant_Value.A_wheel2body[w_i_H_tmp + 2] * val_tmp_1;
    if (w_i_H < 0.0) {
      w_i_H = -1.0;
    } else if (w_i_H > 0.0) {
      w_i_H = 1.0;
    } else if (w_i_H == 0.0) {
      w_i_H = 0.0;
    } else {
      w_i_H = (rtNaN);
    }

    rty_output_wheel[rtConstP.Constant_Value.id_facet_complement[(id + 6 * k) -
      1] - 1] = val * w_i_H;
  }

  /* End of MATLAB Function: '<S278>/MATLAB Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
