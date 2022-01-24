/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: L_inf_allocation_lib.c
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

#include "L_inf_allocation_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for atomic system:
 *    '<S275>/L_inf_allocation_lib'
 *    '<S275>/L_inf_allocation_lib1'
 */
void L_inf_allocation_lib(const real_T rtu_input_body[3], real_T
  rty_output_wheel[4], DW_L_inf_allocation_lib *localDW)
{
  uint8_T id;
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
  localDW->val = 0.0;
  id = 1U;
  for (k = 1; k - 1 < rtP.fswParams.allocator.num_facet; k++) {
    w_i_H_tmp = ((uint8_T)k - 1) * 3;
    localDW->w_i_H = fabs((rtP.fswParams.allocator.w_facet[w_i_H_tmp + 1] *
      rtu_input_body[1] + rtP.fswParams.allocator.w_facet[w_i_H_tmp] *
      rtu_input_body[0]) + rtP.fswParams.allocator.w_facet[w_i_H_tmp + 2] *
                          rtu_input_body[2]);
    if (localDW->w_i_H > localDW->val) {
      localDW->val = localDW->w_i_H;
      id = (uint8_T)k;
    }
  }

  k = id - 1;
  val_tmp = k * 3;
  val_tmp_0 = rtP.fswParams.allocator.w_facet[val_tmp + 1];
  val_tmp_1 = rtP.fswParams.allocator.w_facet[val_tmp + 2];
  localDW->val = (val_tmp_0 * rtu_input_body[1] +
                  rtP.fswParams.allocator.w_facet[val_tmp] * rtu_input_body[0])
    + val_tmp_1 * rtu_input_body[2];
  val_tmp = rtP.fswParams.allocator.id_facet[k] - 1;
  w_i_H_tmp = val_tmp * 3;
  localDW->w_i_j = rtP.fswParams.allocator.A_wheel2body[w_i_H_tmp + 1];
  w_i_H_tmp_0 = rtP.fswParams.allocator.A_wheel2body[w_i_H_tmp + 2];
  localDW->w_i_H = (localDW->w_i_j * rtu_input_body[1] +
                    rtP.fswParams.allocator.A_wheel2body[w_i_H_tmp] *
                    rtu_input_body[0]) + w_i_H_tmp_0 * rtu_input_body[2];
  w_i_H_tmp = rtP.fswParams.allocator.id_facet[id + 5] - 1;
  w_j_H_tmp = w_i_H_tmp * 3;
  w_j_H_tmp_0 = rtP.fswParams.allocator.A_wheel2body[w_j_H_tmp + 1];
  w_j_H_tmp_1 = rtP.fswParams.allocator.A_wheel2body[w_j_H_tmp + 2];
  localDW->w_j_H = (w_j_H_tmp_0 * rtu_input_body[1] +
                    rtP.fswParams.allocator.A_wheel2body[w_j_H_tmp] *
                    rtu_input_body[0]) + w_j_H_tmp_1 * rtu_input_body[2];
  localDW->w_i_j = (localDW->w_i_j * w_j_H_tmp_0 +
                    rtP.fswParams.allocator.A_wheel2body
                    [(rtP.fswParams.allocator.id_facet[id - 1] - 1) * 3] *
                    rtP.fswParams.allocator.A_wheel2body
                    [(rtP.fswParams.allocator.id_facet[id + 5] - 1) * 3]) +
    w_i_H_tmp_0 * w_j_H_tmp_1;
  rty_output_wheel[0] = 0.0;
  rty_output_wheel[1] = 0.0;
  rty_output_wheel[2] = 0.0;
  rty_output_wheel[3] = 0.0;
  w_i_H_tmp_0 = rtP.fswParams.allocator.g_facet[k] * localDW->val;
  rty_output_wheel[val_tmp] = (localDW->w_i_H - localDW->w_i_j * localDW->w_j_H)
    * rtP.fswParams.allocator.inrm2[k] - w_i_H_tmp_0;
  rty_output_wheel[w_i_H_tmp] = (localDW->w_j_H - localDW->w_i_j *
    localDW->w_i_H) * rtP.fswParams.allocator.inrm2[id - 1] - w_i_H_tmp_0;
  for (k = 0; k < 2; k++) {
    w_i_H_tmp = (rtP.fswParams.allocator.id_facet_complement[(6 * k + id) - 1] -
                 1) * 3;
    localDW->w_i_H = (rtP.fswParams.allocator.A_wheel2body[w_i_H_tmp + 1] *
                      val_tmp_0 + rtP.fswParams.allocator.A_wheel2body[w_i_H_tmp]
                      * rtP.fswParams.allocator.w_facet[(id - 1) * 3]) +
      rtP.fswParams.allocator.A_wheel2body[w_i_H_tmp + 2] * val_tmp_1;
    if (localDW->w_i_H < 0.0) {
      localDW->w_i_H = -1.0;
    } else if (localDW->w_i_H > 0.0) {
      localDW->w_i_H = 1.0;
    } else if (localDW->w_i_H == 0.0) {
      localDW->w_i_H = 0.0;
    } else {
      localDW->w_i_H = (rtNaN);
    }

    rty_output_wheel[rtP.fswParams.allocator.id_facet_complement[(id + 6 * k) -
      1] - 1] = localDW->val * localDW->w_i_H;
  }

  /* End of MATLAB Function: '<S278>/MATLAB Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
