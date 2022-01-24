/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: maggyroProcessing_lib.c
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

#include "maggyroProcessing_lib.h"

/* Include model header file for global data */
#include "FSW_Lib0.h"
#include "FSW_Lib0_private.h"

/*
 * Output and update for action system:
 *    '<S24>/If Action Subsystem14'
 *    '<S24>/If Action Subsystem1'
 *    '<S24>/If Action Subsystem2'
 *    '<S66>/If Action Subsystem14'
 *    '<S66>/If Action Subsystem1'
 *    '<S66>/If Action Subsystem2'
 */
void IfActionSubsystem14(real_T rty_nullOut[3], P_IfActionSubsystem14 *localP)
{
  /* SignalConversion: '<S29>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
   *  Constant: '<S29>/Constant'
   */
  rty_nullOut[0] = localP->Constant_Value[0];
  rty_nullOut[1] = localP->Constant_Value[1];
  rty_nullOut[2] = localP->Constant_Value[2];
}

/*
 * Output and update for action system:
 *    '<S25>/If Action Subsystem2'
 *    '<S25>/If Action Subsystem4'
 *    '<S25>/If Action Subsystem14'
 *    '<S67>/If Action Subsystem2'
 *    '<S67>/If Action Subsystem4'
 *    '<S67>/If Action Subsystem14'
 */
void IfActionSubsystem2(boolean_T *rty_Out1, P_IfActionSubsystem2 *localP)
{
  /* SignalConversion: '<S40>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
   *  Constant: '<S40>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * System initialize for atomic system:
 *    '<S2>/maggyroProcessing_lib'
 *    '<S2>/maggyroProcessing_lib1'
 */
void maggyroProcessing_lib_Init(DW_maggyroProcessing_lib *localDW)
{
  /* SystemInitialize for IfAction SubSystem: '<S12>/ThreeValid_MVS' */
  /* InitializeConditions for S-Function (sdspmdn2): '<S26>/Median' */
  localDW->Median_Index[0] = 0U;
  localDW->Median_Index[1] = 3U;
  localDW->Median_Index[2] = 6U;

  /* End of SystemInitialize for SubSystem: '<S12>/ThreeValid_MVS' */
}

/*
 * Output and update for atomic system:
 *    '<S2>/maggyroProcessing_lib'
 *    '<S2>/maggyroProcessing_lib1'
 */
void maggyroProcessing_lib(const real_T rtu_sensor_meas_data[9], const boolean_T
  rtu_sensor_meas_valid[3], real_T rty_sensor_meas_body[3], boolean_T
  *rty_sensor_valid, DW_maggyroProcessing_lib *localDW, P_maggyroProcessing_lib *
  localP, real_T rtp_max_err, const real_T rtp_offset_calibration_matrix[9],
  real_T rtp_static_range_max_value, real_T rtp_Gain)
{
  int32_T c;
  uint32_T i0;
  uint32_T i1;
  int32_T j1;
  int32_T r;
  int32_T idx;
  boolean_T rtb_conjunction;
  boolean_T rtb_conjunction_l;
  boolean_T rtb_conjunction_h;
  boolean_T rtb_Merge_c;
  boolean_T rtb_Merge1_c;
  boolean_T rtb_Merge2_b;
  real_T rtb_Merge_jh_idx_2;
  boolean_T tmp;
  real_T rtb_VariableSelector4_tmp;
  real_T rtb_VariableSelector4_tmp_0;
  real_T rtb_VariableSelector4_tmp_1;

  /* S-Function (sdspperm2): '<S22>/Variable Selector1' */
  idx = localP->VariableSelector1_Elements_b;
  if (localP->VariableSelector1_Elements_b < 0) {
    idx = 0;
  } else {
    if (localP->VariableSelector1_Elements_b >= 3) {
      idx = 2;
    }
  }

  localDW->VariableSelector1[0] = rtu_sensor_meas_data[3 * idx];
  localDW->VariableSelector1[1] = rtu_sensor_meas_data[3 * idx + 1];
  localDW->VariableSelector1[2] = rtu_sensor_meas_data[3 * idx + 2];

  /* End of S-Function (sdspperm2): '<S22>/Variable Selector1' */

  /* S-Function (sdspperm2): '<S22>/Variable Selector2' */
  idx = localP->VariableSelector2_Elements_g;
  if (localP->VariableSelector2_Elements_g < 0) {
    idx = 0;
  } else {
    if (localP->VariableSelector2_Elements_g >= 3) {
      idx = 2;
    }
  }

  localDW->VariableSelector2[0] = rtu_sensor_meas_data[3 * idx];
  localDW->VariableSelector2[1] = rtu_sensor_meas_data[3 * idx + 1];
  localDW->VariableSelector2[2] = rtu_sensor_meas_data[3 * idx + 2];

  /* End of S-Function (sdspperm2): '<S22>/Variable Selector2' */

  /* S-Function (sdspperm2): '<S22>/Variable Selector' */
  idx = localP->VariableSelector_Elements_e;
  if (localP->VariableSelector_Elements_e < 0) {
    idx = 0;
  } else {
    if (localP->VariableSelector_Elements_e >= 3) {
      idx = 2;
    }
  }

  localDW->rtb_Merge_jh_idx_0 = rtu_sensor_meas_data[3 * idx];
  localDW->rtb_Merge_jh_idx_1 = rtu_sensor_meas_data[3 * idx + 1];
  rtb_Merge_jh_idx_2 = rtu_sensor_meas_data[3 * idx + 2];

  /* End of S-Function (sdspperm2): '<S22>/Variable Selector' */
  for (idx = 0; idx < 3; idx++) {
    /* Product: '<S22>/Matrix Multiply3' incorporates:
     *  Constant: '<S22>/Constant'
     */
    localDW->VectorConcatenate[idx] = 0.0;
    localDW->VectorConcatenate[idx] += localP->Constant_Value_j[idx] *
      localDW->rtb_Merge_jh_idx_0;
    localDW->VectorConcatenate[idx] += localP->Constant_Value_j[idx + 3] *
      localDW->rtb_Merge_jh_idx_1;
    localDW->VectorConcatenate[idx] += localP->Constant_Value_j[idx + 6] *
      rtb_Merge_jh_idx_2;

    /* Product: '<S22>/Matrix Multiply2' incorporates:
     *  Constant: '<S22>/Constant2'
     */
    localDW->VectorConcatenate[6 + idx] = 0.0;
    localDW->VectorConcatenate[6 + idx] += localP->Constant2_Value[idx] *
      localDW->VariableSelector2[0];
    localDW->VectorConcatenate[6 + idx] += localP->Constant2_Value[idx + 3] *
      localDW->VariableSelector2[1];
    localDW->VectorConcatenate[6 + idx] += localP->Constant2_Value[idx + 6] *
      localDW->VariableSelector2[2];

    /* Product: '<S22>/Matrix Multiply1' incorporates:
     *  Constant: '<S22>/Constant1'
     */
    localDW->VectorConcatenate[3 + idx] = 0.0;
    localDW->VectorConcatenate[3 + idx] += localP->Constant1_Value[idx] *
      localDW->VariableSelector1[0];
    localDW->VectorConcatenate[3 + idx] += localP->Constant1_Value[idx + 3] *
      localDW->VariableSelector1[1];
    localDW->VectorConcatenate[3 + idx] += localP->Constant1_Value[idx + 6] *
      localDW->VariableSelector1[2];
  }

  /* Sum: '<S22>/Sum' incorporates:
   *  Constant: '<S22>/mag_offset'
   */
  for (idx = 0; idx < 9; idx++) {
    localDW->VectorConcatenate[idx] += rtp_offset_calibration_matrix[idx];
  }

  /* End of Sum: '<S22>/Sum' */

  /* S-Function (sdspperm2): '<S25>/Variable Selector6' */
  idx = localP->VariableSelector6_Elements_o;
  if (localP->VariableSelector6_Elements_o < 0) {
    idx = 0;
  } else {
    if (localP->VariableSelector6_Elements_o >= 3) {
      idx = 2;
    }
  }

  localDW->VariableSelector6[0] = localDW->VectorConcatenate[3 * idx];
  localDW->VariableSelector6[1] = localDW->VectorConcatenate[3 * idx + 1];
  localDW->VariableSelector6[2] = localDW->VectorConcatenate[3 * idx + 2];

  /* End of S-Function (sdspperm2): '<S25>/Variable Selector6' */

  /* S-Function (sdspperm2): '<S25>/Variable Selector7' */
  idx = localP->VariableSelector7_Elements_c;
  if (localP->VariableSelector7_Elements_c < 0) {
    idx = 0;
  } else {
    if (localP->VariableSelector7_Elements_c >= 3) {
      idx = 2;
    }
  }

  localDW->VariableSelector7[0] = localDW->VectorConcatenate[3 * idx];
  localDW->VariableSelector7[1] = localDW->VectorConcatenate[3 * idx + 1];
  localDW->VariableSelector7[2] = localDW->VectorConcatenate[3 * idx + 2];

  /* End of S-Function (sdspperm2): '<S25>/Variable Selector7' */

  /* S-Function (sdspperm2): '<S25>/Variable Selector8' */
  idx = localP->VariableSelector8_Elements_e;
  if (localP->VariableSelector8_Elements_e < 0) {
    idx = 0;
  } else {
    if (localP->VariableSelector8_Elements_e >= 3) {
      idx = 2;
    }
  }

  localDW->VariableSelector8[0] = localDW->VectorConcatenate[3 * idx];
  localDW->VariableSelector8[1] = localDW->VectorConcatenate[3 * idx + 1];
  localDW->VariableSelector8[2] = localDW->VectorConcatenate[3 * idx + 2];

  /* End of S-Function (sdspperm2): '<S25>/Variable Selector8' */

  /* Outputs for Atomic SubSystem: '<S25>/twonorm1' */
  localDW->Sqrt_l = twonorm(localDW->VariableSelector6);

  /* End of Outputs for SubSystem: '<S25>/twonorm1' */

  /* Logic: '<S34>/conjunction' incorporates:
   *  Constant: '<S34>/max_val'
   *  Constant: '<S34>/min_val'
   *  RelationalOperator: '<S34>/max_relop'
   *  RelationalOperator: '<S34>/min_relop'
   */
  rtb_conjunction = ((localP->CheckStaticRange1_min <= localDW->Sqrt_l) &&
                     (localDW->Sqrt_l <= rtp_static_range_max_value));

  /* If: '<S25>/If4' incorporates:
   *  Inport: '<S37>/In1'
   */
  if (rtb_conjunction) {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    rtb_Merge_c = rtu_sensor_meas_valid[0];

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem14' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge_c, &localP->IfActionSubsystem14_d);

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem14' */
  }

  /* End of If: '<S25>/If4' */

  /* Outputs for Atomic SubSystem: '<S25>/twonorm2' */
  localDW->Sqrt_l = twonorm(localDW->VariableSelector7);

  /* End of Outputs for SubSystem: '<S25>/twonorm2' */

  /* Logic: '<S35>/conjunction' incorporates:
   *  Constant: '<S35>/max_val'
   *  Constant: '<S35>/min_val'
   *  RelationalOperator: '<S35>/max_relop'
   *  RelationalOperator: '<S35>/min_relop'
   */
  rtb_conjunction_l = ((localP->CheckStaticRange2_min <= localDW->Sqrt_l) &&
                       (localDW->Sqrt_l <= rtp_static_range_max_value));

  /* If: '<S25>/If1' incorporates:
   *  Inport: '<S38>/In1'
   */
  if (rtb_conjunction_l) {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    rtb_Merge1_c = rtu_sensor_meas_valid[1];

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge1_c, &localP->IfActionSubsystem2_p);

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem2' */
  }

  /* End of If: '<S25>/If1' */

  /* Outputs for Atomic SubSystem: '<S25>/twonorm3' */
  localDW->Sqrt_l = twonorm(localDW->VariableSelector8);

  /* End of Outputs for SubSystem: '<S25>/twonorm3' */

  /* Logic: '<S36>/conjunction' incorporates:
   *  Constant: '<S36>/max_val'
   *  Constant: '<S36>/min_val'
   *  RelationalOperator: '<S36>/max_relop'
   *  RelationalOperator: '<S36>/min_relop'
   */
  rtb_conjunction_h = ((localP->CheckStaticRange4_min <= localDW->Sqrt_l) &&
                       (localDW->Sqrt_l <= rtp_static_range_max_value));

  /* If: '<S25>/If2' incorporates:
   *  Inport: '<S41>/In1'
   */
  if (rtb_conjunction_h) {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    rtb_Merge2_b = rtu_sensor_meas_valid[2];

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    IfActionSubsystem2(&rtb_Merge2_b, &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S25>/If Action Subsystem4' */
  }

  /* End of If: '<S25>/If2' */

  /* If: '<S12>/If' incorporates:
   *  Gain: '<S27>/Gain1'
   *  Sum: '<S26>/Subtract'
   *  Sum: '<S26>/Subtract1'
   *  Sum: '<S26>/Subtract2'
   *  Sum: '<S27>/Sum1'
   */
  tmp = (rtb_Merge_c && rtb_Merge1_c);
  if (tmp && rtb_Merge2_b) {
    /* Outputs for IfAction SubSystem: '<S12>/ThreeValid_MVS' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* S-Function (sdspperm2): '<S26>/Variable Selector' */
    idx = localP->VariableSelector_Elements;
    if (localP->VariableSelector_Elements < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector_Elements >= 3) {
        idx = 2;
      }
    }

    localDW->VariableSelector3[0] = localDW->VectorConcatenate[3 * idx];
    localDW->VariableSelector3[1] = localDW->VectorConcatenate[3 * idx + 1];
    localDW->VariableSelector3[2] = localDW->VectorConcatenate[3 * idx + 2];

    /* End of S-Function (sdspperm2): '<S26>/Variable Selector' */

    /* S-Function (sdspperm2): '<S26>/Variable Selector1' */
    idx = localP->VariableSelector1_Elements;
    if (localP->VariableSelector1_Elements < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector1_Elements >= 3) {
        idx = 2;
      }
    }

    localDW->VariableSelector5[0] = localDW->VectorConcatenate[3 * idx];
    localDW->VariableSelector5[1] = localDW->VectorConcatenate[3 * idx + 1];
    localDW->VariableSelector5[2] = localDW->VectorConcatenate[3 * idx + 2];

    /* End of S-Function (sdspperm2): '<S26>/Variable Selector1' */

    /* S-Function (sdspperm2): '<S26>/Variable Selector2' */
    idx = localP->VariableSelector2_Elements;
    if (localP->VariableSelector2_Elements < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector2_Elements >= 3) {
        idx = 2;
      }
    }

    /* S-Function (sdspmdn2): '<S26>/Median' */
    c = 0;
    for (r = 0; r < 3; r++) {
      i0 = localDW->Median_Index[0];
      localDW->Sqrt_l = localDW->VectorConcatenate[localDW->Median_Index[0] + r];
      i1 = localDW->Median_Index[1U];
      localDW->Sqrt_gc = localDW->VectorConcatenate[localDW->Median_Index[1U] +
        r];
      if (localDW->Sqrt_l > localDW->Sqrt_gc) {
        localDW->Median_Index[1U] = localDW->Median_Index[0];
        localDW->Median_Index[0U] = i1;
      } else {
        localDW->Sqrt_l = localDW->Sqrt_gc;
        i0 = localDW->Median_Index[1U];
      }

      i1 = localDW->Median_Index[2U];
      localDW->Sqrt_gc = localDW->VectorConcatenate[localDW->Median_Index[2U] +
        r];
      if (localDW->Sqrt_l > localDW->Sqrt_gc) {
        localDW->Median_Index[2U] = i0;
        if (localDW->VectorConcatenate[localDW->Median_Index[0U] + r] >
            localDW->Sqrt_gc) {
          localDW->Median_Index[1U] = localDW->Median_Index[0U];
          j1 = 1;
        } else {
          j1 = 2;

          /* set loop index to break loop */
        }

        localDW->Median_Index[j1 - 1U] = i1;
      } else {
        localDW->Sqrt_l = localDW->Sqrt_gc;
      }

      localDW->Median[c] = localDW->VectorConcatenate[localDW->Median_Index[1] +
        r];
      c++;
    }

    /* End of S-Function (sdspmdn2): '<S26>/Median' */

    /* SignalConversion: '<S26>/OutportBufferForsensor_meas_body' */
    localDW->rtb_Merge_jh_idx_0 = localDW->Median[0];

    /* S-Function (sdspperm2): '<S26>/Variable Selector2' */
    rtb_VariableSelector4_tmp = localDW->VectorConcatenate[3 * idx];

    /* Sum: '<S26>/Subtract1' incorporates:
     *  S-Function (sdspperm2): '<S26>/Variable Selector2'
     */
    localDW->VariableSelector2[0] = localDW->VariableSelector3[0] -
      rtb_VariableSelector4_tmp;
    localDW->VariableSelector3[0] -= localDW->VariableSelector5[0];
    localDW->VariableSelector4[0] = localDW->VariableSelector5[0] -
      rtb_VariableSelector4_tmp;

    /* SignalConversion: '<S26>/OutportBufferForsensor_meas_body' incorporates:
     *  Sum: '<S26>/Subtract'
     *  Sum: '<S26>/Subtract1'
     *  Sum: '<S26>/Subtract2'
     */
    localDW->rtb_Merge_jh_idx_1 = localDW->Median[1];

    /* S-Function (sdspperm2): '<S26>/Variable Selector2' */
    rtb_VariableSelector4_tmp = localDW->VectorConcatenate[3 * idx + 1];

    /* Sum: '<S26>/Subtract1' incorporates:
     *  S-Function (sdspperm2): '<S26>/Variable Selector2'
     */
    localDW->VariableSelector2[1] = localDW->VariableSelector3[1] -
      rtb_VariableSelector4_tmp;
    localDW->VariableSelector3[1] -= localDW->VariableSelector5[1];
    localDW->VariableSelector4[1] = localDW->VariableSelector5[1] -
      rtb_VariableSelector4_tmp;

    /* SignalConversion: '<S26>/OutportBufferForsensor_meas_body' incorporates:
     *  Sum: '<S26>/Subtract'
     *  Sum: '<S26>/Subtract1'
     *  Sum: '<S26>/Subtract2'
     */
    rtb_Merge_jh_idx_2 = localDW->Median[2];

    /* S-Function (sdspperm2): '<S26>/Variable Selector2' */
    rtb_VariableSelector4_tmp = localDW->VectorConcatenate[3 * idx + 2];

    /* Sum: '<S26>/Subtract1' incorporates:
     *  S-Function (sdspperm2): '<S26>/Variable Selector2'
     */
    localDW->VariableSelector2[2] = localDW->VariableSelector3[2] -
      rtb_VariableSelector4_tmp;
    localDW->VariableSelector3[2] -= localDW->VariableSelector5[2];
    localDW->VariableSelector4[2] = localDW->VariableSelector5[2] -
      rtb_VariableSelector4_tmp;

    /* Outputs for Atomic SubSystem: '<S26>/twonorm' */
    localDW->Sqrt_l = twonorm(localDW->VariableSelector3);

    /* End of Outputs for SubSystem: '<S26>/twonorm' */

    /* Outputs for Atomic SubSystem: '<S26>/twonorm1' */
    localDW->Sqrt_gc = twonorm(localDW->VariableSelector2);

    /* End of Outputs for SubSystem: '<S26>/twonorm1' */

    /* Outputs for Atomic SubSystem: '<S26>/twonorm2' */
    localDW->Sqrt_i = twonorm(localDW->VariableSelector4);

    /* End of Outputs for SubSystem: '<S26>/twonorm2' */

    /* Logic: '<S26>/OR' incorporates:
     *  Constant: '<S46>/Constant'
     *  Constant: '<S47>/Constant'
     *  Constant: '<S48>/Constant'
     *  RelationalOperator: '<S46>/Compare'
     *  RelationalOperator: '<S47>/Compare'
     *  RelationalOperator: '<S48>/Compare'
     *  Sum: '<S26>/Subtract'
     *  Sum: '<S26>/Subtract1'
     *  Sum: '<S26>/Subtract2'
     */
    *rty_sensor_valid = ((localDW->Sqrt_l <= rtp_max_err) || (localDW->Sqrt_gc <=
      rtp_max_err) || (localDW->Sqrt_i <= rtp_max_err));

    /* End of Outputs for SubSystem: '<S12>/ThreeValid_MVS' */
  } else if (tmp || (rtb_Merge1_c && rtb_Merge2_b) || (rtb_Merge2_b &&
              rtb_Merge_c)) {
    /* Outputs for IfAction SubSystem: '<S12>/TwoValid' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* S-Function (sdspperm2): '<S27>/Variable Selector6' */
    idx = localP->VariableSelector6_Elements;
    if (localP->VariableSelector6_Elements < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector6_Elements >= 3) {
        idx = 2;
      }
    }

    localDW->VariableSelector5[0] = localDW->VectorConcatenate[3 * idx];
    localDW->VariableSelector5[1] = localDW->VectorConcatenate[3 * idx + 1];
    localDW->VariableSelector5[2] = localDW->VectorConcatenate[3 * idx + 2];

    /* End of S-Function (sdspperm2): '<S27>/Variable Selector6' */

    /* S-Function (sdspperm2): '<S27>/Variable Selector7' */
    idx = localP->VariableSelector7_Elements;
    if (localP->VariableSelector7_Elements < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector7_Elements >= 3) {
        idx = 2;
      }
    }

    localDW->VariableSelector3[0] = localDW->VectorConcatenate[3 * idx];
    localDW->VariableSelector3[1] = localDW->VectorConcatenate[3 * idx + 1];
    localDW->VariableSelector3[2] = localDW->VectorConcatenate[3 * idx + 2];

    /* End of S-Function (sdspperm2): '<S27>/Variable Selector7' */

    /* S-Function (sdspperm2): '<S27>/Variable Selector8' */
    idx = localP->VariableSelector8_Elements;
    if (localP->VariableSelector8_Elements < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector8_Elements >= 3) {
        idx = 2;
      }
    }

    rtb_VariableSelector4_tmp = localDW->VectorConcatenate[3 * idx];
    localDW->VariableSelector4[0] = rtb_VariableSelector4_tmp;
    rtb_VariableSelector4_tmp_0 = localDW->VectorConcatenate[3 * idx + 1];
    localDW->VariableSelector4[1] = rtb_VariableSelector4_tmp_0;
    rtb_VariableSelector4_tmp_1 = localDW->VectorConcatenate[3 * idx + 2];
    localDW->VariableSelector4[2] = rtb_VariableSelector4_tmp_1;

    /* End of S-Function (sdspperm2): '<S27>/Variable Selector8' */

    /* If: '<S27>/If4' incorporates:
     *  Inport: '<S55>/In1'
     */
    if (rtb_Merge_c) {
      /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S55>/Action Port'
       */
      localDW->rtb_Merge_jh_idx_0 = localDW->VariableSelector5[0];
      localDW->rtb_Merge_jh_idx_1 = localDW->VariableSelector5[1];
      rtb_Merge_jh_idx_2 = localDW->VariableSelector5[2];

      /* End of Outputs for SubSystem: '<S27>/If Action Subsystem6' */
    } else {
      /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem14' incorporates:
       *  ActionPort: '<S53>/Action Port'
       */
      /* SignalConversion: '<S53>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
       *  Constant: '<S53>/Constant'
       */
      localDW->rtb_Merge_jh_idx_0 = localP->Constant_Value[0];

      /* Sum: '<S53>/Subtract' */
      localDW->VariableSelector2[0] = localDW->VariableSelector3[0] -
        rtb_VariableSelector4_tmp;

      /* SignalConversion: '<S53>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
       *  Constant: '<S53>/Constant'
       */
      localDW->rtb_Merge_jh_idx_1 = localP->Constant_Value[1];

      /* Sum: '<S53>/Subtract' */
      localDW->VariableSelector2[1] = localDW->VariableSelector3[1] -
        rtb_VariableSelector4_tmp_0;

      /* SignalConversion: '<S53>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
       *  Constant: '<S53>/Constant'
       */
      rtb_Merge_jh_idx_2 = localP->Constant_Value[2];

      /* Sum: '<S53>/Subtract' */
      localDW->VariableSelector2[2] = localDW->VariableSelector3[2] -
        rtb_VariableSelector4_tmp_1;

      /* Outputs for Atomic SubSystem: '<S53>/twonorm' */
      localDW->Sqrt_l = twonorm(localDW->VariableSelector2);

      /* End of Outputs for SubSystem: '<S53>/twonorm' */

      /* RelationalOperator: '<S60>/Compare' incorporates:
       *  Constant: '<S60>/Constant'
       */
      *rty_sensor_valid = (localDW->Sqrt_l <= rtp_max_err);

      /* End of Outputs for SubSystem: '<S27>/If Action Subsystem14' */
    }

    /* End of If: '<S27>/If4' */

    /* If: '<S27>/If5' incorporates:
     *  Inport: '<S56>/In1'
     */
    if (rtb_Merge1_c) {
      /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S56>/Action Port'
       */
      localDW->VariableSelector2[0] = localDW->VariableSelector3[0];
      localDW->VariableSelector2[1] = localDW->VariableSelector3[1];
      localDW->VariableSelector2[2] = localDW->VariableSelector3[2];

      /* End of Outputs for SubSystem: '<S27>/If Action Subsystem8' */
    } else {
      /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S52>/Action Port'
       */
      /* SignalConversion: '<S52>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
       *  Constant: '<S52>/Constant'
       */
      localDW->VariableSelector2[0] = localP->Constant_Value_g[0];

      /* Sum: '<S52>/Subtract' */
      localDW->VariableSelector1[0] = localDW->VariableSelector5[0] -
        rtb_VariableSelector4_tmp;

      /* SignalConversion: '<S52>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
       *  Constant: '<S52>/Constant'
       */
      localDW->VariableSelector2[1] = localP->Constant_Value_g[1];

      /* Sum: '<S52>/Subtract' */
      localDW->VariableSelector1[1] = localDW->VariableSelector5[1] -
        rtb_VariableSelector4_tmp_0;

      /* SignalConversion: '<S52>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
       *  Constant: '<S52>/Constant'
       */
      localDW->VariableSelector2[2] = localP->Constant_Value_g[2];

      /* Sum: '<S52>/Subtract' */
      localDW->VariableSelector1[2] = localDW->VariableSelector5[2] -
        rtb_VariableSelector4_tmp_1;

      /* Outputs for Atomic SubSystem: '<S52>/twonorm' */
      localDW->Sqrt_l = twonorm(localDW->VariableSelector1);

      /* End of Outputs for SubSystem: '<S52>/twonorm' */

      /* RelationalOperator: '<S58>/Compare' incorporates:
       *  Constant: '<S58>/Constant'
       */
      *rty_sensor_valid = (localDW->Sqrt_l <= rtp_max_err);

      /* End of Outputs for SubSystem: '<S27>/If Action Subsystem1' */
    }

    /* End of If: '<S27>/If5' */

    /* If: '<S27>/If6' incorporates:
     *  Sum: '<S54>/Subtract'
     */
    if (!rtb_Merge2_b) {
      /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S54>/Action Port'
       */
      /* SignalConversion: '<S54>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
       *  Constant: '<S54>/Constant'
       */
      localDW->VariableSelector4[0] = localP->Constant_Value_c[0];
      localDW->VariableSelector5[0] -= localDW->VariableSelector3[0];

      /* SignalConversion: '<S54>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
       *  Constant: '<S54>/Constant'
       *  Sum: '<S54>/Subtract'
       */
      localDW->VariableSelector4[1] = localP->Constant_Value_c[1];
      localDW->VariableSelector5[1] -= localDW->VariableSelector3[1];

      /* SignalConversion: '<S54>/OutportBuffer_InsertedFor_nullOut_at_inport_0' incorporates:
       *  Constant: '<S54>/Constant'
       *  Sum: '<S54>/Subtract'
       */
      localDW->VariableSelector4[2] = localP->Constant_Value_c[2];
      localDW->VariableSelector5[2] -= localDW->VariableSelector3[2];

      /* Outputs for Atomic SubSystem: '<S54>/twonorm' */
      localDW->Sqrt_l = twonorm(localDW->VariableSelector5);

      /* End of Outputs for SubSystem: '<S54>/twonorm' */

      /* RelationalOperator: '<S62>/Compare' incorporates:
       *  Constant: '<S62>/Constant'
       *  Sum: '<S54>/Subtract'
       */
      *rty_sensor_valid = (localDW->Sqrt_l <= rtp_max_err);

      /* End of Outputs for SubSystem: '<S27>/If Action Subsystem2' */
    }

    /* End of If: '<S27>/If6' */
    localDW->rtb_Merge_jh_idx_0 = ((localDW->rtb_Merge_jh_idx_0 +
      localDW->VariableSelector2[0]) + localDW->VariableSelector4[0]) *
      localP->Gain1_Gain;
    localDW->rtb_Merge_jh_idx_1 = ((localDW->rtb_Merge_jh_idx_1 +
      localDW->VariableSelector2[1]) + localDW->VariableSelector4[1]) *
      localP->Gain1_Gain;
    rtb_Merge_jh_idx_2 = ((rtb_Merge_jh_idx_2 + localDW->VariableSelector2[2]) +
                          localDW->VariableSelector4[2]) * localP->Gain1_Gain;

    /* End of Outputs for SubSystem: '<S12>/TwoValid' */
  } else if (rtb_Merge_c || rtb_Merge1_c || rtb_Merge2_b) {
    /* Outputs for IfAction SubSystem: '<S12>/OneValid' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* S-Function (sdspperm2): '<S24>/Variable Selector6' */
    idx = localP->VariableSelector6_Elements_m;
    if (localP->VariableSelector6_Elements_m < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector6_Elements_m >= 3) {
        idx = 2;
      }
    }

    localDW->VariableSelector3[0] = localDW->VectorConcatenate[3 * idx];
    localDW->VariableSelector3[1] = localDW->VectorConcatenate[3 * idx + 1];
    localDW->VariableSelector3[2] = localDW->VectorConcatenate[3 * idx + 2];

    /* End of S-Function (sdspperm2): '<S24>/Variable Selector6' */

    /* If: '<S24>/If4' */
    if (!rtb_Merge_c) {
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem14' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      IfActionSubsystem14(localDW->VariableSelector3,
                          &localP->IfActionSubsystem14_n);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem14' */
    }

    /* End of If: '<S24>/If4' */

    /* S-Function (sdspperm2): '<S24>/Variable Selector7' */
    idx = localP->VariableSelector7_Elements_b;
    if (localP->VariableSelector7_Elements_b < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector7_Elements_b >= 3) {
        idx = 2;
      }
    }

    localDW->VariableSelector4[0] = localDW->VectorConcatenate[3 * idx];
    localDW->VariableSelector4[1] = localDW->VectorConcatenate[3 * idx + 1];
    localDW->VariableSelector4[2] = localDW->VectorConcatenate[3 * idx + 2];

    /* End of S-Function (sdspperm2): '<S24>/Variable Selector7' */

    /* If: '<S24>/If5' */
    if (!rtb_Merge1_c) {
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      IfActionSubsystem14(localDW->VariableSelector4,
                          &localP->IfActionSubsystem1_o);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem1' */
    }

    /* End of If: '<S24>/If5' */

    /* S-Function (sdspperm2): '<S24>/Variable Selector8' */
    idx = localP->VariableSelector8_Elements_g;
    if (localP->VariableSelector8_Elements_g < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector8_Elements_g >= 3) {
        idx = 2;
      }
    }

    localDW->VariableSelector5[0] = localDW->VectorConcatenate[3 * idx];
    localDW->VariableSelector5[1] = localDW->VectorConcatenate[3 * idx + 1];
    localDW->VariableSelector5[2] = localDW->VectorConcatenate[3 * idx + 2];

    /* End of S-Function (sdspperm2): '<S24>/Variable Selector8' */

    /* If: '<S24>/If6' */
    if (!rtb_Merge2_b) {
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      IfActionSubsystem14(localDW->VariableSelector5,
                          &localP->IfActionSubsystem2_k);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem2' */
    }

    /* End of If: '<S24>/If6' */

    /* Gain: '<S24>/Gain1' incorporates:
     *  Sum: '<S24>/Sum1'
     */
    localDW->rtb_Merge_jh_idx_0 = ((localDW->VariableSelector3[0] +
      localDW->VariableSelector4[0]) + localDW->VariableSelector5[0]) *
      localP->Gain1_Gain_j;
    localDW->rtb_Merge_jh_idx_1 = ((localDW->VariableSelector3[1] +
      localDW->VariableSelector4[1]) + localDW->VariableSelector5[1]) *
      localP->Gain1_Gain_j;
    rtb_Merge_jh_idx_2 = ((localDW->VariableSelector3[2] +
      localDW->VariableSelector4[2]) + localDW->VariableSelector5[2]) *
      localP->Gain1_Gain_j;

    /* SignalConversion: '<S24>/OutportBuffer_InsertedFor_sensor_valid_at_inport_0' incorporates:
     *  Constant: '<S24>/Constant'
     */
    *rty_sensor_valid = localP->Constant_Value_js;

    /* End of Outputs for SubSystem: '<S12>/OneValid' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/NoneValid' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* S-Function (sdspperm2): '<S23>/Variable Selector3' */
    idx = localP->VariableSelector3_Elements;
    if (localP->VariableSelector3_Elements < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector3_Elements >= 3) {
        idx = 2;
      }
    }

    localDW->VariableSelector3[0] = localDW->VectorConcatenate[3 * idx];
    localDW->VariableSelector3[1] = localDW->VectorConcatenate[3 * idx + 1];
    localDW->VariableSelector3[2] = localDW->VectorConcatenate[3 * idx + 2];

    /* End of S-Function (sdspperm2): '<S23>/Variable Selector3' */

    /* S-Function (sdspperm2): '<S23>/Variable Selector4' */
    idx = localP->VariableSelector4_Elements;
    if (localP->VariableSelector4_Elements < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector4_Elements >= 3) {
        idx = 2;
      }
    }

    localDW->VariableSelector4[0] = localDW->VectorConcatenate[3 * idx];
    localDW->VariableSelector4[1] = localDW->VectorConcatenate[3 * idx + 1];
    localDW->VariableSelector4[2] = localDW->VectorConcatenate[3 * idx + 2];

    /* End of S-Function (sdspperm2): '<S23>/Variable Selector4' */

    /* S-Function (sdspperm2): '<S23>/Variable Selector5' */
    idx = localP->VariableSelector5_Elements;
    if (localP->VariableSelector5_Elements < 0) {
      idx = 0;
    } else {
      if (localP->VariableSelector5_Elements >= 3) {
        idx = 2;
      }
    }

    /* Gain: '<S23>/Gain' incorporates:
     *  S-Function (sdspperm2): '<S23>/Variable Selector5'
     *  Sum: '<S23>/Sum'
     */
    localDW->rtb_Merge_jh_idx_0 = ((localDW->VariableSelector3[0] +
      localDW->VariableSelector4[0]) + localDW->VectorConcatenate[3 * idx]) *
      localP->Gain_Gain;
    localDW->rtb_Merge_jh_idx_1 = (localDW->VectorConcatenate[3 * idx + 1] +
      (localDW->VariableSelector3[1] + localDW->VariableSelector4[1])) *
      localP->Gain_Gain;
    rtb_Merge_jh_idx_2 = (localDW->VectorConcatenate[3 * idx + 2] +
                          (localDW->VariableSelector3[2] +
      localDW->VariableSelector4[2])) * localP->Gain_Gain;

    /* SignalConversion: '<S23>/OutportBuffer_InsertedFor_sensor_valid_at_inport_0' incorporates:
     *  Constant: '<S23>/Constant'
     */
    *rty_sensor_valid = localP->Constant_Value_f;

    /* End of Outputs for SubSystem: '<S12>/NoneValid' */
  }

  /* End of If: '<S12>/If' */

  /* Gain: '<S12>/UnitConversion' */
  rty_sensor_meas_body[0] = rtp_Gain * localDW->rtb_Merge_jh_idx_0;
  rty_sensor_meas_body[1] = rtp_Gain * localDW->rtb_Merge_jh_idx_1;
  rty_sensor_meas_body[2] = rtp_Gain * rtb_Merge_jh_idx_2;

  /* Assertion: '<S36>/Assertion' */
  utAssert(rtb_conjunction_h);

  /* Assertion: '<S35>/Assertion' */
  utAssert(rtb_conjunction_l);

  /* Assertion: '<S34>/Assertion' */
  utAssert(rtb_conjunction);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
