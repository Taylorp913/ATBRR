/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FindTarget.c
 *
 * Code generated for Simulink model 'FindTarget'.
 *
 * Model version                  : 1.92
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Mon Feb 01 21:55:27 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FindTarget.h"
#include "FindTarget_private.h"
#include "FindTarget_dt.h"

/* Named constants for Chart: '<Root>/Finite State Machine' */
#define FindTarget_CALL_EVENT          (-1)
#define FindTarget_IN_Down             ((uint8_T)1U)
#define FindTarget_IN_Drive            ((uint8_T)1U)
#define FindTarget_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define FindTarget_IN_Nod              ((uint8_T)2U)
#define FindTarget_IN_Running          ((uint8_T)1U)
#define FindTarget_IN_Search           ((uint8_T)3U)
#define FindTarget_IN_Start            ((uint8_T)2U)
#define FindTarget_IN_Stop             ((uint8_T)4U)
#define FindTarget_IN_Up               ((uint8_T)2U)
#define FindTarget_IN_Waiting          ((uint8_T)3U)

/* Block signals (auto storage) */
B_FindTarget_T FindTarget_B;

/* Block states (auto storage) */
DW_FindTarget_T FindTarget_DW;

/* Real-time model */
RT_MODEL_FindTarget_T FindTarget_M_;
RT_MODEL_FindTarget_T *const FindTarget_M = &FindTarget_M_;
static void rate_monotonic_scheduler(void);
int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = (uint32_T)(numerator >= 0 ? numerator : -numerator);
    absDenominator = (uint32_T)(denominator >= 0 ? denominator : -denominator);
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  FindTarget_M->Timing.RateInteraction.TID0_1 =
    (FindTarget_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (FindTarget_M->Timing.TaskCounters.TID[1])++;
  if ((FindTarget_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.33333333333333331s, 0.0s] */
    FindTarget_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model output function for TID0 */
void FindTarget_output0(void)          /* Sample time: [0.033333333333333333s, 0.0s] */
{
  uint32_T sum;
  boolean_T status;
  int32_T bytesTransmitted;
  static const char_T b[13] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'A', 'M',
    'A', '0', '\x00' };

  real_T delD;
  real_T A[9];
  real_T B[6];
  static const real_T Q[9] = { 0.001, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.001
  };

  static const int8_T b_0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T H[6];
  real_T b_a[4];
  real_T t;
  int8_T I[9];
  int8_T b_I[9];
  static const real_T b_1[4] = { 0.05, 0.0, 0.0, 0.05 };

  uint8_T rtb_SumofElements;
  uint8_T rtb_data[9];
  real_T rtb_Xout[3];
  real_T rtb_Pout[9];
  char_T b_2[13];
  int32_T i;
  real_T A_0[9];
  real_T B_0[9];
  real_T H_0[6];
  real_T b_I_0[9];
  real_T rtb_Power2m_idx_1;
  real_T rtb_Power2m_idx_0;
  real_T c_idx_0;
  real_T c_idx_1;
  real_T c_idx_2;
  uint32_T qY;

  {                                    /* Sample time: [0.033333333333333333s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(FindTarget_DW.DriveToTarget_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(FindTarget_DW.SearchForTarget_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(FindTarget_DW.Stateestimator_SubsysRanBC);

  /* RateTransition: '<S3>/Rate Transition4' */
  if (FindTarget_M->Timing.RateInteraction.TID0_1) {
    FindTarget_B.RateTransition4 = FindTarget_DW.RateTransition4_Buffer0;

    /* RateTransition: '<S3>/Rate Transition6' */
    FindTarget_B.RateTransition6[0] = FindTarget_DW.RateTransition6_Buffer0[0];
    FindTarget_B.RateTransition6[1] = FindTarget_DW.RateTransition6_Buffer0[1];

    /* RateTransition: '<S3>/Rate Transition5' */
    FindTarget_B.RateTransition5 = FindTarget_DW.RateTransition5_Buffer0;
  }

  /* End of RateTransition: '<S3>/Rate Transition4' */

  /* Outputs for Enabled SubSystem: '<Root>/State estimator' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (FindTarget_B.RateTransition5) {
    if (!FindTarget_DW.Stateestimator_MODE) {
      /* InitializeConditions for UnitDelay: '<S24>/Delay Input1' */
      FindTarget_DW.DelayInput1_DSTATE = FindTarget_P.DetectChange_vinit;

      /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
      FindTarget_DW.UnitDelay1_DSTATE[0] =
        FindTarget_P.UnitDelay1_InitialCondition[0];
      FindTarget_DW.UnitDelay1_DSTATE[1] =
        FindTarget_P.UnitDelay1_InitialCondition[1];
      FindTarget_DW.UnitDelay1_DSTATE[2] =
        FindTarget_P.UnitDelay1_InitialCondition[2];

      /* InitializeConditions for UnitDelay: '<S5>/Unit Delay2' */
      FindTarget_DW.UnitDelay2_DSTATE[0] =
        FindTarget_P.UnitDelay2_InitialCondition[0];
      FindTarget_DW.UnitDelay2_DSTATE[1] =
        FindTarget_P.UnitDelay2_InitialCondition[1];

      /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
      memcpy(&FindTarget_DW.UnitDelay_DSTATE[0],
             &FindTarget_P.UnitDelay_InitialCondition[0], 9U * sizeof(real_T));
      FindTarget_DW.Stateestimator_MODE = true;
    }

    /* Gain: '<S5>/Power2m' incorporates:
     *  UnitDelay: '<S5>/Unit Delay2'
     */
    rtb_Power2m_idx_0 = FindTarget_P.Power2m_Gain *
      FindTarget_DW.UnitDelay2_DSTATE[0];
    rtb_Power2m_idx_1 = FindTarget_P.Power2m_Gain *
      FindTarget_DW.UnitDelay2_DSTATE[1];

    /* MATLAB Function: '<S5>/Time Update' incorporates:
     *  SignalConversion: '<S26>/TmpSignal ConversionAt SFunction Inport2'
     *  UnitDelay: '<S5>/Unit Delay'
     *  UnitDelay: '<S5>/Unit Delay1'
     */
    /* MATLAB Function 'State estimator/Time Update': '<S26>:1' */
    /*  calculate some initial parameters */
    /* '<S26>:1:6' */
    delD = (rtb_Power2m_idx_1 + rtb_Power2m_idx_0) / 2.0;

    /* '<S26>:1:7' */
    rtb_Power2m_idx_0 = (rtb_Power2m_idx_1 - rtb_Power2m_idx_0) / 0.1;

    /* '<S26>:1:8' */
    /*  Update state */
    /* '<S26>:1:11' */
    rtb_Xout[0] = cos(rtb_Power2m_idx_0 / 2.0 + FindTarget_DW.UnitDelay1_DSTATE
                      [2]) * delD + FindTarget_DW.UnitDelay1_DSTATE[0];
    rtb_Xout[1] = sin(rtb_Power2m_idx_0 / 2.0 + FindTarget_DW.UnitDelay1_DSTATE
                      [2]) * delD + FindTarget_DW.UnitDelay1_DSTATE[1];
    rtb_Xout[2] = FindTarget_DW.UnitDelay1_DSTATE[2] + rtb_Power2m_idx_0;

    /*  Calculate A-matrix */
    /* '<S26>:1:14' */
    for (i = 0; i < 9; i++) {
      A[i] = b_0[i];
    }

    /* '<S26>:1:15' */
    A[6] = sin(rtb_Power2m_idx_0 / 2.0 + rtb_Xout[2]) * -delD;

    /* '<S26>:1:16' */
    A[7] = cos(rtb_Power2m_idx_0 / 2.0 + rtb_Xout[2]) * delD;

    /*  Calculate B-matrix */
    /* '<S26>:1:20' */
    B[0] = sin(rtb_Power2m_idx_0 / 2.0 + rtb_Xout[2]) * delD / 2.0 / 0.1 + cos
      (rtb_Power2m_idx_0 / 2.0 + rtb_Xout[2]) / 2.0;

    /* '<S26>:1:21' */
    B[3] = cos(rtb_Power2m_idx_0 / 2.0 + rtb_Xout[2]) / 2.0 - sin
      (rtb_Power2m_idx_0 / 2.0 + rtb_Xout[2]) * delD / 2.0 / 0.1;

    /* '<S26>:1:22' */
    B[1] = sin(rtb_Power2m_idx_0 / 2.0 + rtb_Xout[2]) / 2.0 - cos
      (rtb_Power2m_idx_0 / 2.0 + rtb_Xout[2]) * delD / 2.0 / 0.1;

    /* '<S26>:1:23' */
    B[4] = cos(rtb_Power2m_idx_0 / 2.0 + rtb_Xout[2]) * delD / 2.0 / 0.1 + sin
      (rtb_Power2m_idx_0 / 2.0 + rtb_Xout[2]) / 2.0;

    /* '<S26>:1:24' */
    B[2] = -10.0;

    /* '<S26>:1:25' */
    B[5] = 10.0;

    /*  Update covariance matrix */
    /* '<S26>:1:28' */
    for (i = 0; i < 3; i++) {
      for (bytesTransmitted = 0; bytesTransmitted < 3; bytesTransmitted++) {
        A_0[i + 3 * bytesTransmitted] = 0.0;
        A_0[i + 3 * bytesTransmitted] += FindTarget_DW.UnitDelay_DSTATE[3 *
          bytesTransmitted] * A[i];
        A_0[i + 3 * bytesTransmitted] += FindTarget_DW.UnitDelay_DSTATE[3 *
          bytesTransmitted + 1] * A[i + 3];
        A_0[i + 3 * bytesTransmitted] += FindTarget_DW.UnitDelay_DSTATE[3 *
          bytesTransmitted + 2] * A[i + 6];
        B_0[i + 3 * bytesTransmitted] = 0.0;
        B_0[i + 3 * bytesTransmitted] += B[i] * B[bytesTransmitted];
        B_0[i + 3 * bytesTransmitted] += B[i + 3] * B[bytesTransmitted + 3];
      }
    }

    for (i = 0; i < 3; i++) {
      for (bytesTransmitted = 0; bytesTransmitted < 3; bytesTransmitted++) {
        rtb_Pout[i + 3 * bytesTransmitted] = (((A_0[i + 3] * A[bytesTransmitted
          + 3] + A_0[i] * A[bytesTransmitted]) + A_0[i + 6] * A[bytesTransmitted
          + 6]) + B_0[3 * bytesTransmitted + i] * 0.0001) + Q[3 *
          bytesTransmitted + i];
      }
    }

    /* End of MATLAB Function: '<S5>/Time Update' */

    /* MATLAB Function: '<S5>/Measurement Update' incorporates:
     *  Gain: '<S5>/r2d'
     *  RelationalOperator: '<S24>/FixPt Relational Operator'
     *  UnitDelay: '<S24>/Delay Input1'
     */
    /* MATLAB Function 'State estimator/Measurement Update': '<S25>:1' */
    /*  Only perform measurement update if we have a new measurement */
    if (FindTarget_B.RateTransition4 != FindTarget_DW.DelayInput1_DSTATE) {
      /* '<S25>:1:5' */
      /*  Initialise some parameters */
      /* '<S25>:1:7' */
      /* '<S25>:1:8' */
      /* '<S25>:1:9' */
      delD = sqrt((0.0 - rtb_Xout[0]) * (0.0 - rtb_Xout[0]) + (0.0 - rtb_Xout[1])
                  * (0.0 - rtb_Xout[1]));

      /*  Calculate measurement matrix */
      /* '<S25>:1:13' */
      H[0] = (0.0 - rtb_Xout[1]) / (delD * delD);

      /* '<S25>:1:14' */
      H[2] = rtb_Xout[0] / (delD * delD);

      /* '<S25>:1:15' */
      H[4] = -1.0;

      /* '<S25>:1:16' */
      H[1] = (0.0 - rtb_Xout[0]) * -0.14 / ((delD * delD + 0.019600000000000003)
        * delD);

      /* '<S25>:1:17' */
      H[3] = (0.0 - rtb_Xout[1]) * -0.14 / ((delD * delD + 0.019600000000000003)
        * delD);

      /* '<S25>:1:18' */
      H[5] = 0.0;

      /*  Calculate Kalman gain */
      /* '<S25>:1:21' */
      /* '<S25>:1:22' */
      for (i = 0; i < 2; i++) {
        for (bytesTransmitted = 0; bytesTransmitted < 3; bytesTransmitted++) {
          H_0[i + (bytesTransmitted << 1)] = 0.0;
          H_0[i + (bytesTransmitted << 1)] += rtb_Pout[3 * bytesTransmitted] *
            H[i];
          H_0[i + (bytesTransmitted << 1)] += rtb_Pout[3 * bytesTransmitted + 1]
            * H[i + 2];
          H_0[i + (bytesTransmitted << 1)] += rtb_Pout[3 * bytesTransmitted + 2]
            * H[i + 4];
        }
      }

      for (i = 0; i < 2; i++) {
        for (bytesTransmitted = 0; bytesTransmitted < 2; bytesTransmitted++) {
          b_a[i + (bytesTransmitted << 1)] = ((H_0[i + 2] * H[bytesTransmitted +
            2] + H_0[i] * H[bytesTransmitted]) + H_0[i + 4] * H[bytesTransmitted
            + 4]) + b_1[(bytesTransmitted << 1) + i];
        }
      }

      if (fabs(b_a[1]) > fabs(b_a[0])) {
        rtb_Power2m_idx_0 = b_a[0] / b_a[1];
        t = 1.0 / (rtb_Power2m_idx_0 * b_a[3] - b_a[2]);
        c_idx_0 = b_a[3] / b_a[1] * t;
        c_idx_1 = -t;
        c_idx_2 = -b_a[2] / b_a[1] * t;
        t *= rtb_Power2m_idx_0;
      } else {
        rtb_Power2m_idx_0 = b_a[1] / b_a[0];
        t = 1.0 / (b_a[3] - rtb_Power2m_idx_0 * b_a[2]);
        c_idx_0 = b_a[3] / b_a[0] * t;
        c_idx_1 = -rtb_Power2m_idx_0 * t;
        c_idx_2 = -b_a[2] / b_a[0] * t;
      }

      for (i = 0; i < 3; i++) {
        for (bytesTransmitted = 0; bytesTransmitted < 2; bytesTransmitted++) {
          H_0[i + 3 * bytesTransmitted] = 0.0;
          H_0[i + 3 * bytesTransmitted] += rtb_Pout[i] * H[bytesTransmitted];
          H_0[i + 3 * bytesTransmitted] += rtb_Pout[i + 3] * H[bytesTransmitted
            + 2];
          H_0[i + 3 * bytesTransmitted] += rtb_Pout[i + 6] * H[bytesTransmitted
            + 4];
        }
      }

      /*  Calculate predicted measurements */
      /* '<S25>:1:25' */
      /* '<S25>:1:26' */
      /* '<S25>:1:27' */
      /*  Update state */
      /* '<S25>:1:30' */
      rtb_Power2m_idx_0 = FindTarget_P.r2d_Gain * FindTarget_B.RateTransition6[1]
        - (rt_atan2d_snf(0.0 - rtb_Xout[1], 0.0 - rtb_Xout[0]) - rtb_Xout[2]);
      rtb_Power2m_idx_1 = FindTarget_P.r2d_Gain * FindTarget_B.RateTransition6[0]
        - (-rt_atan2d_snf(0.14, delD));
      for (i = 0; i < 3; i++) {
        B[i] = 0.0;
        B[i] += H_0[i] * c_idx_0;
        B[i] += H_0[i + 3] * c_idx_1;
        B[i + 3] = 0.0;
        B[i + 3] += H_0[i] * c_idx_2;
        B[i + 3] += H_0[i + 3] * t;
        FindTarget_B.Xout[i] = (B[i + 3] * rtb_Power2m_idx_1 + B[i] *
          rtb_Power2m_idx_0) + rtb_Xout[i];
      }

      /*  Update covariance */
      /* '<S25>:1:33' */
      for (i = 0; i < 9; i++) {
        I[i] = 0;
        b_I[i] = 0;
      }

      I[0] = 1;
      I[4] = 1;
      I[8] = 1;
      for (bytesTransmitted = 0; bytesTransmitted < 3; bytesTransmitted++) {
        b_I[bytesTransmitted + 3 * bytesTransmitted] = 1;
        for (i = 0; i < 3; i++) {
          A[bytesTransmitted + 3 * i] = (real_T)I[3 * i + bytesTransmitted] -
            (H[(i << 1) + 1] * B[bytesTransmitted + 3] + H[i << 1] *
             B[bytesTransmitted]);
        }
      }

      for (i = 0; i < 3; i++) {
        for (bytesTransmitted = 0; bytesTransmitted < 3; bytesTransmitted++) {
          A_0[i + 3 * bytesTransmitted] = 0.0;
          A_0[i + 3 * bytesTransmitted] += rtb_Pout[3 * bytesTransmitted] * A[i];
          A_0[i + 3 * bytesTransmitted] += rtb_Pout[3 * bytesTransmitted + 1] *
            A[i + 3];
          A_0[i + 3 * bytesTransmitted] += rtb_Pout[3 * bytesTransmitted + 2] *
            A[i + 6];
          b_I_0[i + 3 * bytesTransmitted] = (real_T)b_I[3 * i + bytesTransmitted]
            - (H[(i << 1) + 1] * B[bytesTransmitted + 3] + H[i << 1] *
               B[bytesTransmitted]);
        }

        H_0[i] = 0.0;
        H_0[i] += B[i] * 0.05;
        H_0[i] += B[i + 3] * 0.0;
        H_0[i + 3] = 0.0;
        H_0[i + 3] += B[i] * 0.0;
        H_0[i + 3] += B[i + 3] * 0.05;
      }

      for (i = 0; i < 3; i++) {
        for (bytesTransmitted = 0; bytesTransmitted < 3; bytesTransmitted++) {
          A[i + 3 * bytesTransmitted] = 0.0;
          A[i + 3 * bytesTransmitted] += b_I_0[3 * bytesTransmitted] * A_0[i];
          A[i + 3 * bytesTransmitted] += b_I_0[3 * bytesTransmitted + 1] * A_0[i
            + 3];
          A[i + 3 * bytesTransmitted] += b_I_0[3 * bytesTransmitted + 2] * A_0[i
            + 6];
          B_0[i + 3 * bytesTransmitted] = 0.0;
          B_0[i + 3 * bytesTransmitted] += H_0[i] * B[bytesTransmitted];
          B_0[i + 3 * bytesTransmitted] += H_0[i + 3] * B[bytesTransmitted + 3];
        }
      }

      for (i = 0; i < 3; i++) {
        FindTarget_B.Pout[3 * i] = A[3 * i] + B_0[3 * i];
        FindTarget_B.Pout[1 + 3 * i] = A[3 * i + 1] + B_0[3 * i + 1];
        FindTarget_B.Pout[2 + 3 * i] = A[3 * i + 2] + B_0[3 * i + 2];
      }
    } else {
      /* '<S25>:1:35' */
      FindTarget_B.Xout[0] = rtb_Xout[0];
      FindTarget_B.Xout[1] = rtb_Xout[1];
      FindTarget_B.Xout[2] = rtb_Xout[2];

      /* '<S25>:1:36' */
      memcpy(&FindTarget_B.Pout[0], &rtb_Pout[0], 9U * sizeof(real_T));
    }

    /* End of MATLAB Function: '<S5>/Measurement Update' */
    srUpdateBC(FindTarget_DW.Stateestimator_SubsysRanBC);
  } else {
    if (FindTarget_DW.Stateestimator_MODE) {
      FindTarget_DW.Stateestimator_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/State estimator' */

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   *  S-Function (sfix_udelay): '<S1>/Tapped Delay'
   *  Sum: '<S1>/Sum of Elements'
   */
  FindTarget_B.Compare = ((uint8_T)(((uint32_T)FindTarget_DW.TappedDelay_X[0] +
    FindTarget_DW.TappedDelay_X[1]) + FindTarget_DW.TappedDelay_X[2]) >=
    FindTarget_P.CompareToConstant_const);

  /* RelationalOperator: '<S7>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S7>/Delay Input1'
   */
  FindTarget_B.FixPtRelationalOperator = ((int32_T)FindTarget_B.Compare >
    (int32_T)FindTarget_DW.DelayInput1_DSTATE_n);

  /* Constant: '<Root>/Tilt Angle' */
  FindTarget_B.TiltAngle = FindTarget_P.TiltAngle_Value;

  /* Constant: '<Root>/Pan  Angle' */
  FindTarget_B.PanAngle = FindTarget_P.PanAngle_Value;

  /* Chart: '<Root>/Finite State Machine' */
  if (FindTarget_DW.temporalCounter_i1 < 31U) {
    FindTarget_DW.temporalCounter_i1++;
  }

  /* Gateway: Finite State Machine */
  FindTarget_DW.sfEvent = FindTarget_CALL_EVENT;

  /* During: Finite State Machine */
  if (FindTarget_DW.is_active_c7_FindTarget == 0U) {
    /* Entry: Finite State Machine */
    FindTarget_DW.is_active_c7_FindTarget = 1U;

    /* Entry Internal: Finite State Machine */
    /* Transition: '<S2>:9' */
    FindTarget_DW.is_c7_FindTarget = FindTarget_IN_Start;
    FindTarget_DW.temporalCounter_i1 = 0U;

    /* Entry 'Start': '<S2>:33' */
    FindTarget_B.MotorLeft = 0.0;
    FindTarget_B.MotorRight = 0.0;
    FindTarget_B.CameraElevation = FindTarget_B.TiltAngle;
    FindTarget_B.CameraAzimuth = FindTarget_B.PanAngle;
  } else {
    switch (FindTarget_DW.is_c7_FindTarget) {
     case FindTarget_IN_Running:
      /* During 'Running': '<S2>:61' */
      if (FindTarget_B.FixPtRelationalOperator) {
        /* Transition: '<S2>:60' */
        /* Exit Internal 'Running': '<S2>:61' */
        if (FindTarget_DW.is_Running == FindTarget_IN_Nod) {
          /* Exit Internal 'Nod': '<S2>:101' */
          FindTarget_DW.is_Nod = FindTarget_IN_NO_ACTIVE_CHILD;

          /* Exit 'Nod': '<S2>:101' */
          FindTarget_B.CameraElevation = 0.0;
          FindTarget_DW.is_Running = FindTarget_IN_NO_ACTIVE_CHILD;
        } else {
          FindTarget_DW.is_Running = FindTarget_IN_NO_ACTIVE_CHILD;
        }

        FindTarget_DW.is_c7_FindTarget = FindTarget_IN_Start;
        FindTarget_DW.temporalCounter_i1 = 0U;

        /* Entry 'Start': '<S2>:33' */
        FindTarget_B.MotorLeft = 0.0;
        FindTarget_B.MotorRight = 0.0;
        FindTarget_B.CameraElevation = FindTarget_B.TiltAngle;
        FindTarget_B.CameraAzimuth = FindTarget_B.PanAngle;
      } else {
        switch (FindTarget_DW.is_Running) {
         case FindTarget_IN_Drive:
          /* During 'Drive': '<S2>:45' */
          if (!FindTarget_B.RateTransition5) {
            /* Transition: '<S2>:13' */
            FindTarget_DW.is_Running = FindTarget_IN_Stop;

            /* Entry 'Stop': '<S2>:62' */
            FindTarget_B.MotorLeft = 0.0;
            FindTarget_B.MotorRight = 0.0;
          } else {
            /* Simulink Function 'DriveToTarget': '<S2>:35' */
            FindTarget_B.TargetPosition[0] = FindTarget_B.Xout[0];
            FindTarget_B.TargetPosition[1] = FindTarget_B.Xout[1];
            FindTarget_B.TargetPosition[2] = FindTarget_B.Xout[2];

            /* Outputs for Function Call SubSystem: '<S2>/DriveToTarget' */
            /* Gain: '<S12>/Speed Gain' incorporates:
             *  Math: '<S10>/Math Function'
             *  Sqrt: '<S10>/Sqrt'
             *  Sum: '<S10>/Sum of Elements'
             */
            t = sqrt(FindTarget_B.TargetPosition[0] *
                     FindTarget_B.TargetPosition[0] +
                     FindTarget_B.TargetPosition[1] *
                     FindTarget_B.TargetPosition[1]) *
              FindTarget_P.SpeedGain_Gain;

            /* Saturate: '<S12>/Saturation3' */
            if (t > FindTarget_P.Saturation3_UpperSat) {
              t = FindTarget_P.Saturation3_UpperSat;
            } else {
              if (t < FindTarget_P.Saturation3_LowerSat) {
                t = FindTarget_P.Saturation3_LowerSat;
              }
            }

            /* End of Saturate: '<S12>/Saturation3' */

            /* Sum: '<S11>/Add2' incorporates:
             *  Trigonometry: '<S11>/Trigonometric Function'
             *  UnaryMinus: '<S11>/Unary Minus2'
             */
            delD = rt_atan2d_snf(-FindTarget_B.TargetPosition[1],
                                 -FindTarget_B.TargetPosition[0]) +
              -FindTarget_B.TargetPosition[2];

            /* SampleTimeMath: '<S14>/TSamp' incorporates:
             *  Gain: '<S13>/D'
             *
             * About '<S14>/TSamp':
             *  y = u * K where K = 1 / ( w * Ts )
             */
            rtb_Power2m_idx_0 = FindTarget_P.D_Gain * delD *
              FindTarget_P.TSamp_WtEt;

            /* Sum: '<S13>/Sum1' incorporates:
             *  Gain: '<S13>/P'
             *  Sum: '<S14>/Diff'
             *  UnitDelay: '<S14>/UD'
             */
            delD = (rtb_Power2m_idx_0 - FindTarget_DW.UD_DSTATE) +
              FindTarget_P.P_Gain * delD;

            /* Saturate: '<S13>/Saturation2' */
            if (delD > FindTarget_P.Saturation2_UpperSat) {
              FindTarget_B.Saturation2 = FindTarget_P.Saturation2_UpperSat;
            } else if (delD < FindTarget_P.Saturation2_LowerSat) {
              FindTarget_B.Saturation2 = FindTarget_P.Saturation2_LowerSat;
            } else {
              FindTarget_B.Saturation2 = delD;
            }

            /* End of Saturate: '<S13>/Saturation2' */

            /* Sum: '<S8>/Add' incorporates:
             *  Gain: '<S13>/Gain3'
             */
            delD = FindTarget_P.Gain3_Gain * FindTarget_B.Saturation2 + t;

            /* Saturate: '<S8>/Saturation2' */
            if (delD > FindTarget_P.Saturation2_UpperSat_f) {
              FindTarget_B.Saturation2_f = FindTarget_P.Saturation2_UpperSat_f;
            } else if (delD < FindTarget_P.Saturation2_LowerSat_e) {
              FindTarget_B.Saturation2_f = FindTarget_P.Saturation2_LowerSat_e;
            } else {
              FindTarget_B.Saturation2_f = delD;
            }

            /* End of Saturate: '<S8>/Saturation2' */

            /* Sum: '<S8>/Add1' incorporates:
             *  Gain: '<S13>/Gain4'
             */
            t += FindTarget_P.Gain4_Gain * FindTarget_B.Saturation2;

            /* Saturate: '<S8>/Saturation1' */
            if (t > FindTarget_P.Saturation1_UpperSat) {
              FindTarget_B.Saturation1 = FindTarget_P.Saturation1_UpperSat;
            } else if (t < FindTarget_P.Saturation1_LowerSat) {
              FindTarget_B.Saturation1 = FindTarget_P.Saturation1_LowerSat;
            } else {
              FindTarget_B.Saturation1 = t;
            }

            /* End of Saturate: '<S8>/Saturation1' */

            /* Update for UnitDelay: '<S14>/UD' */
            FindTarget_DW.UD_DSTATE = rtb_Power2m_idx_0;
            FindTarget_DW.DriveToTarget_SubsysRanBC = 4;

            /* End of Outputs for SubSystem: '<S2>/DriveToTarget' */
            FindTarget_B.MotorLeft = FindTarget_B.Saturation2_f;
            FindTarget_B.MotorRight = FindTarget_B.Saturation1;
          }
          break;

         case FindTarget_IN_Nod:
          /* During 'Nod': '<S2>:101' */
          if (FindTarget_DW.i > 10.0) {
            /* Transition: '<S2>:111' */
            /* Exit Internal 'Nod': '<S2>:101' */
            FindTarget_DW.is_Nod = FindTarget_IN_NO_ACTIVE_CHILD;

            /* Exit 'Nod': '<S2>:101' */
            FindTarget_DW.is_Running = FindTarget_IN_NO_ACTIVE_CHILD;
            FindTarget_DW.is_c7_FindTarget = FindTarget_IN_Start;
            FindTarget_DW.temporalCounter_i1 = 0U;

            /* Entry 'Start': '<S2>:33' */
            FindTarget_B.MotorLeft = 0.0;
            FindTarget_B.MotorRight = 0.0;
            FindTarget_B.CameraElevation = FindTarget_B.TiltAngle;
            FindTarget_B.CameraAzimuth = FindTarget_B.PanAngle;
          } else if (FindTarget_DW.is_Nod == FindTarget_IN_Down) {
            /* During 'Down': '<S2>:105' */
            if (FindTarget_DW.temporalCounter_i1 >= 6U) {
              /* Transition: '<S2>:103' */
              FindTarget_DW.is_Nod = FindTarget_IN_Up;
              FindTarget_DW.temporalCounter_i1 = 0U;

              /* Entry 'Up': '<S2>:102' */
              FindTarget_B.CameraElevation = 10.0;
              FindTarget_DW.i++;
            }
          } else {
            /* During 'Up': '<S2>:102' */
            if (FindTarget_DW.temporalCounter_i1 >= 6U) {
              /* Transition: '<S2>:106' */
              FindTarget_DW.is_Nod = FindTarget_IN_Down;
              FindTarget_DW.temporalCounter_i1 = 0U;

              /* Entry 'Down': '<S2>:105' */
              FindTarget_B.CameraElevation = -30.0;
              FindTarget_DW.i++;
            }
          }
          break;

         case FindTarget_IN_Search:
          /* During 'Search': '<S2>:2' */
          if (FindTarget_B.RateTransition5) {
            /* Transition: '<S2>:10' */
            FindTarget_DW.is_Running = FindTarget_IN_Drive;
          } else {
            /* Outputs for Function Call SubSystem: '<S2>/SearchForTarget' */
            /* DiscretePulseGenerator: '<S9>/Pulse Generator' */
            /* Simulink Function 'SearchForTarget': '<S2>:24' */
            t = (FindTarget_DW.clockTickCounter <
                 FindTarget_P.PulseGenerator_Duty) &&
              (FindTarget_DW.clockTickCounter >= 0) ?
              FindTarget_P.PulseGenerator_Amp : 0.0;
            if (FindTarget_DW.clockTickCounter >=
                FindTarget_P.PulseGenerator_Period - 1.0) {
              FindTarget_DW.clockTickCounter = 0;
            } else {
              FindTarget_DW.clockTickCounter++;
            }

            /* End of DiscretePulseGenerator: '<S9>/Pulse Generator' */

            /* Gain: '<S9>/Gain1' */
            FindTarget_B.Gain1 = FindTarget_P.Gain1_Gain * t;

            /* Gain: '<S9>/Gain4' */
            FindTarget_B.Gain4 = FindTarget_P.Gain4_Gain_f * t;
            FindTarget_DW.SearchForTarget_SubsysRanBC = 4;

            /* End of Outputs for SubSystem: '<S2>/SearchForTarget' */
            FindTarget_B.MotorLeft = FindTarget_B.Gain4;
            FindTarget_B.MotorRight = FindTarget_B.Gain1;
          }
          break;

         default:
          /* During 'Stop': '<S2>:62' */
          /* Transition: '<S2>:104' */
          FindTarget_DW.is_Running = FindTarget_IN_Nod;

          /* Entry 'Nod': '<S2>:101' */
          FindTarget_DW.i = 0.0;
          FindTarget_DW.is_Nod = FindTarget_IN_Up;
          FindTarget_DW.temporalCounter_i1 = 0U;

          /* Entry 'Up': '<S2>:102' */
          FindTarget_B.CameraElevation = 10.0;
          FindTarget_DW.i++;
          break;
        }
      }
      break;

     case FindTarget_IN_Start:
      /* During 'Start': '<S2>:33' */
      if (FindTarget_DW.temporalCounter_i1 >= 30U) {
        /* Transition: '<S2>:34' */
        FindTarget_DW.is_c7_FindTarget = FindTarget_IN_Waiting;
      }
      break;

     default:
      /* During 'Waiting': '<S2>:66' */
      if (FindTarget_B.FixPtRelationalOperator) {
        /* Transition: '<S2>:67' */
        FindTarget_DW.is_c7_FindTarget = FindTarget_IN_Running;
        FindTarget_DW.is_Running = FindTarget_IN_Search;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Finite State Machine' */

  /* Signum: '<S21>/Sign' */
  if (FindTarget_B.MotorLeft < 0.0) {
    rtb_Power2m_idx_0 = -1.0;
  } else if (FindTarget_B.MotorLeft > 0.0) {
    rtb_Power2m_idx_0 = 1.0;
  } else if (FindTarget_B.MotorLeft == 0.0) {
    rtb_Power2m_idx_0 = 0.0;
  } else {
    rtb_Power2m_idx_0 = FindTarget_B.MotorLeft;
  }

  /* Sum: '<S21>/Sum' incorporates:
   *  Gain: '<S21>/Gain'
   *  Gain: '<S21>/Gain1'
   *  Signum: '<S21>/Sign'
   */
  delD = FindTarget_P.CoulombViscousFriction_offset * rtb_Power2m_idx_0 +
    FindTarget_P.CoulombViscousFriction_gain * FindTarget_B.MotorLeft;

  /* Signum: '<S21>/Sign' */
  if (FindTarget_B.MotorRight < 0.0) {
    rtb_Power2m_idx_0 = -1.0;
  } else if (FindTarget_B.MotorRight > 0.0) {
    rtb_Power2m_idx_0 = 1.0;
  } else if (FindTarget_B.MotorRight == 0.0) {
    rtb_Power2m_idx_0 = 0.0;
  } else {
    rtb_Power2m_idx_0 = FindTarget_B.MotorRight;
  }

  /* Sum: '<S21>/Sum' incorporates:
   *  Gain: '<S21>/Gain'
   *  Gain: '<S21>/Gain1'
   *  Signum: '<S21>/Sign'
   */
  t = FindTarget_P.CoulombViscousFriction_offset * rtb_Power2m_idx_0 +
    FindTarget_P.CoulombViscousFriction_gain * FindTarget_B.MotorRight;

  /* MATLAB Function: '<S4>/Format Serial Message' */
  /* MATLAB Function 'Outputs/Format Serial Message': '<S22>:1' */
  /* '<S22>:1:4' */
  /*  Command */
  /* '<S22>:1:5' */
  /* '<S22>:1:7' */
  rtb_data[0] = MAX_uint8_T;
  rtb_data[1] = MAX_uint8_T;
  rtb_data[2] = 2U;
  rtb_data[3] = 9U;

  /* Saturate: '<S4>/Saturation3' */
  if (delD > FindTarget_P.Saturation3_UpperSat_o) {
    delD = FindTarget_P.Saturation3_UpperSat_o;
  } else {
    if (delD < FindTarget_P.Saturation3_LowerSat_o) {
      delD = FindTarget_P.Saturation3_LowerSat_o;
    }
  }

  /* MATLAB Function: '<S4>/Format Serial Message' incorporates:
   *  Bias: '<S4>/Bias'
   *  Gain: '<S4>/Gain'
   *  Saturate: '<S4>/Saturation3'
   */
  rtb_Power2m_idx_0 = rt_roundd_snf(FindTarget_P.Gain_Gain * delD +
    FindTarget_P.Bias_Bias);
  if (rtb_Power2m_idx_0 < 256.0) {
    if (rtb_Power2m_idx_0 >= 0.0) {
      rtb_data[4] = (uint8_T)rtb_Power2m_idx_0;
    } else {
      rtb_data[4] = 0U;
    }
  } else {
    rtb_data[4] = MAX_uint8_T;
  }

  /* Saturate: '<S4>/Saturation3' */
  if (t > FindTarget_P.Saturation3_UpperSat_o) {
    t = FindTarget_P.Saturation3_UpperSat_o;
  } else {
    if (t < FindTarget_P.Saturation3_LowerSat_o) {
      t = FindTarget_P.Saturation3_LowerSat_o;
    }
  }

  /* MATLAB Function: '<S4>/Format Serial Message' incorporates:
   *  Bias: '<S4>/Bias'
   *  Gain: '<S4>/Gain'
   *  Saturate: '<S4>/Saturation3'
   */
  rtb_Power2m_idx_0 = rt_roundd_snf(FindTarget_P.Gain_Gain * t +
    FindTarget_P.Bias_Bias);
  if (rtb_Power2m_idx_0 < 256.0) {
    if (rtb_Power2m_idx_0 >= 0.0) {
      rtb_data[5] = (uint8_T)rtb_Power2m_idx_0;
    } else {
      rtb_data[5] = 0U;
    }
  } else {
    rtb_data[5] = MAX_uint8_T;
  }

  /* Saturate: '<S4>/Saturation1' */
  if (FindTarget_B.CameraAzimuth > FindTarget_P.Saturation1_UpperSat_f) {
    rtb_Power2m_idx_0 = FindTarget_P.Saturation1_UpperSat_f;
  } else if (FindTarget_B.CameraAzimuth < FindTarget_P.Saturation1_LowerSat_c) {
    rtb_Power2m_idx_0 = FindTarget_P.Saturation1_LowerSat_c;
  } else {
    rtb_Power2m_idx_0 = FindTarget_B.CameraAzimuth;
  }

  /* MATLAB Function: '<S4>/Format Serial Message' incorporates:
   *  Bias: '<S4>/Bias1'
   *  Saturate: '<S4>/Saturation1'
   */
  rtb_Power2m_idx_0 = rt_roundd_snf(rtb_Power2m_idx_0 + FindTarget_P.Bias1_Bias);
  if (rtb_Power2m_idx_0 < 256.0) {
    if (rtb_Power2m_idx_0 >= 0.0) {
      rtb_data[6] = (uint8_T)rtb_Power2m_idx_0;
    } else {
      rtb_data[6] = 0U;
    }
  } else {
    rtb_data[6] = MAX_uint8_T;
  }

  /* Saturate: '<S4>/Saturation' */
  if (FindTarget_B.CameraElevation > FindTarget_P.Saturation_UpperSat) {
    rtb_Power2m_idx_0 = FindTarget_P.Saturation_UpperSat;
  } else if (FindTarget_B.CameraElevation < FindTarget_P.Saturation_LowerSat) {
    rtb_Power2m_idx_0 = FindTarget_P.Saturation_LowerSat;
  } else {
    rtb_Power2m_idx_0 = FindTarget_B.CameraElevation;
  }

  /* MATLAB Function: '<S4>/Format Serial Message' incorporates:
   *  Bias: '<S4>/Bias2'
   *  Saturate: '<S4>/Saturation'
   */
  rtb_Power2m_idx_0 = rt_roundd_snf(rtb_Power2m_idx_0 + FindTarget_P.Bias2_Bias);
  if (rtb_Power2m_idx_0 < 256.0) {
    if (rtb_Power2m_idx_0 >= 0.0) {
      rtb_data[7] = (uint8_T)rtb_Power2m_idx_0;
    } else {
      rtb_data[7] = 0U;
    }
  } else {
    rtb_data[7] = MAX_uint8_T;
  }

  rtb_data[8] = 0U;

  /*  Checksum is the complement of the sum of each byte */
  /*  Excluding start characters */
  /* '<S22>:1:11' */
  sum = 0U;

  /* '<S22>:1:12' */
  for (rtb_SumofElements = 0U; rtb_SumofElements < 6U; rtb_SumofElements++) {
    /* '<S22>:1:12' */
    /* '<S22>:1:13' */
    qY = rtb_data[rtb_SumofElements + 2] + sum;
    if (qY < sum) {
      qY = MAX_uint32_T;
    }

    sum = qY;
  }

  /* '<S22>:1:16' */
  sum = ~sum;
  if (sum > 255U) {
    sum = 255U;
  }

  rtb_data[8] = (uint8_T)sum;

  /* MATLAB Function: '<S4>/Serial Write' */
  /* MATLAB Function 'Outputs/Serial Write': '<S23>:1' */
  /* '<S23>:1:8' */
  /* '<S23>:1:4' */
  status = false;
  if (!FindTarget_DW.spHandle_not_empty) {
    /* '<S23>:1:6' */
    /* '<S23>:1:7' */
    FindTarget_DW.spHandle = 0;
    FindTarget_DW.spHandle_not_empty = true;

    /* '<S23>:1:8' */
    for (i = 0; i < 13; i++) {
      b_2[i] = b[i];
    }

    FindTarget_DW.spHandle = setupSerialPort(b_2, 57600U);
  }

  if (FindTarget_DW.spHandle > 0) {
    /* '<S23>:1:10' */
    /* '<S23>:1:12' */
    bytesTransmitted = write(FindTarget_DW.spHandle, rtb_data, 9U);
    if (bytesTransmitted == 9) {
      /* '<S23>:1:13' */
      /* '<S23>:1:14' */
      status = true;
    }
  }

  FindTarget_B.status = status;

  /* End of MATLAB Function: '<S4>/Serial Write' */

  /* S-Function (linuxGpioRead_sfcn): '<Root>/GPIO Read' */
  FindTarget_B.GPIORead = MW_gpioRead(18U);

  /* S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureOutput(FindTarget_ConstP.V4L2VideoCapture_p1,
                        FindTarget_B.V4L2VideoCapture_o1,
                        FindTarget_B.V4L2VideoCapture_o2,
                        FindTarget_B.V4L2VideoCapture_o3);

  /* RateTransition: '<S3>/Rate Transition' */
  if (FindTarget_M->Timing.RateInteraction.TID0_1) {
    memcpy(&FindTarget_B.RateTransition[0], &FindTarget_B.V4L2VideoCapture_o1[0],
           76800U * sizeof(uint8_T));

    /* RateTransition: '<S3>/Rate Transition1' */
    memcpy(&FindTarget_B.RateTransition1[0], &FindTarget_B.V4L2VideoCapture_o2[0],
           76800U * sizeof(uint8_T));

    /* RateTransition: '<S3>/Rate Transition2' */
    memcpy(&FindTarget_B.RateTransition2[0], &FindTarget_B.V4L2VideoCapture_o3[0],
           76800U * sizeof(uint8_T));
  }

  /* End of RateTransition: '<S3>/Rate Transition' */
}

/* Model update function for TID0 */
void FindTarget_update0(void)          /* Sample time: [0.033333333333333333s, 0.0s] */
{
  /* Update for Enabled SubSystem: '<Root>/State estimator' incorporates:
   *  Update for EnablePort: '<S5>/Enable'
   */
  if (FindTarget_DW.Stateestimator_MODE) {
    /* Update for UnitDelay: '<S24>/Delay Input1' */
    FindTarget_DW.DelayInput1_DSTATE = FindTarget_B.RateTransition4;

    /* Update for UnitDelay: '<S5>/Unit Delay1' */
    FindTarget_DW.UnitDelay1_DSTATE[0] = FindTarget_B.Xout[0];
    FindTarget_DW.UnitDelay1_DSTATE[1] = FindTarget_B.Xout[1];
    FindTarget_DW.UnitDelay1_DSTATE[2] = FindTarget_B.Xout[2];

    /* Update for UnitDelay: '<S5>/Unit Delay2' */
    FindTarget_DW.UnitDelay2_DSTATE[0] = FindTarget_B.MotorLeft;
    FindTarget_DW.UnitDelay2_DSTATE[1] = FindTarget_B.MotorRight;

    /* Update for UnitDelay: '<S5>/Unit Delay' */
    memcpy(&FindTarget_DW.UnitDelay_DSTATE[0], &FindTarget_B.Pout[0], 9U *
           sizeof(real_T));
  }

  /* End of Update for SubSystem: '<Root>/State estimator' */

  /* Update for S-Function (sfix_udelay): '<S1>/Tapped Delay' */
  FindTarget_DW.TappedDelay_X[0] = FindTarget_DW.TappedDelay_X[1];
  FindTarget_DW.TappedDelay_X[1] = FindTarget_DW.TappedDelay_X[2];
  FindTarget_DW.TappedDelay_X[2] = FindTarget_B.GPIORead;

  /* Update for UnitDelay: '<S7>/Delay Input1' */
  FindTarget_DW.DelayInput1_DSTATE_n = FindTarget_B.Compare;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.033333333333333333s, 0.0s] */
    if ((rtmGetTFinal(FindTarget_M)!=-1) &&
        !((rtmGetTFinal(FindTarget_M)-FindTarget_M->Timing.taskTime0) >
          FindTarget_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(FindTarget_M, "Simulation finished");
    }

    if (rtmGetStopRequested(FindTarget_M)) {
      rtmSetErrorStatus(FindTarget_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  FindTarget_M->Timing.taskTime0 =
    (++FindTarget_M->Timing.clockTick0) * FindTarget_M->Timing.stepSize0;
}

/* Model output function for TID1 */
void FindTarget_output1(void)          /* Sample time: [0.33333333333333331s, 0.0s] */
{
  boolean_T visited1;
  boolean_T visited2;
  boolean_T done;
  int32_T idxFillColorCur;
  real_T rtb_BlobAnalysis_o2[2];
  int32_T rtb_BlobAnalysis_o1;
  int32_T pixListNinc;
  uint32_T BlobAnalysis_NUM_PIX_DW;
  int32_T ms;
  int32_T j;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T stackIdx;
  uint32_T walkerIdx;
  uint32_T padIdx;
  int32_T idx;
  int32_T n;
  int32_T loop;
  int32_T line_idx_3;
  int32_T line_idx_2;
  int32_T line_idx_3_0;
  int32_T line_idx_2_0;
  int32_T line_idx_1;
  int32_T line_idx_0;
  real_T tmp;
  real_T tmp_0;

  /* Reset subsysRan breadcrumbs */
  srClearBC(FindTarget_DW.Imageprocessing_SubsysRanBC);

  /* S-Function (fcncallgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/Image processing'
   */
  /* MATLAB Function 'Image Processing/Image processing/Detect Target/Calculate Green Intensity': '<S19>:1' */
  /* '<S19>:1:3' */
  for (loop = 0; loop < 76800; loop++) {
    /* MATLAB Function: '<S17>/Calculate Green Intensity' */
    pixIdx = (uint32_T)FindTarget_B.RateTransition1[loop] - (uint8_T)(int32_T)
      rt_roundd_snf((real_T)FindTarget_B.RateTransition[loop] / 2.0);
    if (pixIdx > FindTarget_B.RateTransition1[loop]) {
      pixIdx = 0U;
    }

    stackIdx = pixIdx - (uint8_T)(int32_T)rt_roundd_snf((real_T)
      FindTarget_B.RateTransition2[loop] / 2.0);
    if (stackIdx > pixIdx) {
      stackIdx = 0U;
    }

    /* RelationalOperator: '<S20>/Compare' incorporates:
     *  Constant: '<S20>/Constant'
     *  MATLAB Function: '<S17>/Calculate Green Intensity'
     */
    FindTarget_B.Compare_d[loop] = ((uint8_T)stackIdx >
      FindTarget_P.CompareToThreshold_const);
  }

  /* S-Function (svipblob): '<S15>/Blob Analysis' */
  maxNumBlobsReached = false;
  memset(&FindTarget_DW.BlobAnalysis_PAD_DW[0], 0, 323U * sizeof(uint8_T));
  currentLabel = 1U;
  loop = 0;
  idx = 323;
  for (n = 0; n < 240; n++) {
    for (pixListNinc = 0; pixListNinc < 320; pixListNinc++) {
      FindTarget_DW.BlobAnalysis_PAD_DW[idx] = (uint8_T)
        (FindTarget_B.Compare_d[loop] ? 255 : 0);
      loop++;
      idx++;
    }

    FindTarget_DW.BlobAnalysis_PAD_DW[idx] = 0U;
    FindTarget_DW.BlobAnalysis_PAD_DW[idx + 1] = 0U;
    idx += 2;
  }

  memset(&FindTarget_DW.BlobAnalysis_PAD_DW[idx], 0, 321U * sizeof(uint8_T));
  idx = 0;
  pixIdx = 0U;
  n = 0;
  while (n < 240) {
    ms = 0;
    j = (idx + 1) * 322;
    pixListNinc = 0;
    while (pixListNinc < 320) {
      padIdx = (uint32_T)((j + ms) + 1);
      start_pixIdx = pixIdx;
      if (FindTarget_DW.BlobAnalysis_PAD_DW[padIdx] == 255) {
        FindTarget_DW.BlobAnalysis_PAD_DW[padIdx] = currentLabel;
        FindTarget_DW.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)idx;
        FindTarget_DW.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)ms;
        pixIdx++;
        BlobAnalysis_NUM_PIX_DW = 1U;
        FindTarget_DW.BlobAnalysis_STACK_DW[0U] = padIdx;
        stackIdx = 1U;
        while (stackIdx != 0U) {
          stackIdx--;
          padIdx = FindTarget_DW.BlobAnalysis_STACK_DW[stackIdx];
          for (loop = 0; loop < 8; loop++) {
            walkerIdx = padIdx + FindTarget_ConstP.BlobAnalysis_WALKER_RTP[loop];
            if (FindTarget_DW.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
              FindTarget_DW.BlobAnalysis_PAD_DW[walkerIdx] = currentLabel;
              FindTarget_DW.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                ((int16_T)(walkerIdx / 322U) - 1);
              FindTarget_DW.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)
                (walkerIdx % 322U - 1U);
              pixIdx++;
              BlobAnalysis_NUM_PIX_DW++;
              FindTarget_DW.BlobAnalysis_STACK_DW[stackIdx] = walkerIdx;
              stackIdx++;
            }
          }
        }

        if (BlobAnalysis_NUM_PIX_DW < FindTarget_P.BlobAnalysis_minArea) {
          currentLabel--;
          pixIdx = start_pixIdx;
        }

        if (currentLabel == 1) {
          maxNumBlobsReached = true;
          n = 240;
          pixListNinc = 320;
        }

        if (pixListNinc < 320) {
          currentLabel++;
        }
      }

      ms++;
      pixListNinc++;
    }

    idx++;
    n++;
  }

  stackIdx = (uint32_T)(maxNumBlobsReached ? (int32_T)currentLabel : (int32_T)
                        (uint8_T)(currentLabel - 1U));
  n = 0;
  pixListNinc = 0;
  for (loop = 0; loop < (int32_T)stackIdx; loop++) {
    rtb_BlobAnalysis_o1 = (int32_T)BlobAnalysis_NUM_PIX_DW;
    idx = 0;
    ms = 0;
    for (j = 0; j < (int32_T)BlobAnalysis_NUM_PIX_DW; j++) {
      idx += FindTarget_DW.BlobAnalysis_N_PIXLIST_DW[j + pixListNinc];
      ms += FindTarget_DW.BlobAnalysis_M_PIXLIST_DW[j + n];
    }

    rtb_BlobAnalysis_o2[loop] = (real_T)idx / (real_T)BlobAnalysis_NUM_PIX_DW +
      1.0;
    rtb_BlobAnalysis_o2[1U + loop] = (real_T)ms / (real_T)
      BlobAnalysis_NUM_PIX_DW + 1.0;
    n += (int32_T)BlobAnalysis_NUM_PIX_DW;
    pixListNinc += (int32_T)BlobAnalysis_NUM_PIX_DW;
  }

  loop = (int32_T)stackIdx;
  while (loop < 1) {
    rtb_BlobAnalysis_o1 = -1;
    loop = 1;
  }

  loop = (int32_T)stackIdx;
  while (loop < 1) {
    rtb_BlobAnalysis_o2[0] = -1.0;
    loop = 1;
  }

  loop = 1 + (int32_T)stackIdx;
  while (loop < 2) {
    rtb_BlobAnalysis_o2[1] = -1.0;
    loop = 2;
  }

  /* End of S-Function (svipblob): '<S15>/Blob Analysis' */

  /* DataTypeConversion: '<S18>/Data Type Conversion1' */
  tmp_0 = floor(rtb_BlobAnalysis_o2[0]);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  tmp = floor(rtb_BlobAnalysis_o2[1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* S-Function (svipdrawmarkers): '<S18>/Draw Markers' incorporates:
   *  DataTypeConversion: '<S18>/Data Type Conversion1'
   */
  /* Copy the image from input to output. */
  memcpy(&FindTarget_B.greenIntensity[0], &FindTarget_B.RateTransition[0],
         76800U * sizeof(uint8_T));
  memcpy(&FindTarget_B.DrawMarkers_o2[0], &FindTarget_B.RateTransition1[0],
         76800U * sizeof(uint8_T));
  memcpy(&FindTarget_B.DrawMarkers_o3[0], &FindTarget_B.RateTransition2[0],
         76800U * sizeof(uint8_T));

  /* Update view port. */
  /* Draw all X marks. */
  idx = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-tmp :
                   (int32_T)(uint16_T)tmp) - 1;
  ms = (uint16_T)(tmp_0 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-tmp_0 :
                  (int32_T)(uint16_T)tmp_0) - 1;
  n = idx - FindTarget_P.DrawMarkers_size;
  pixListNinc = ms - FindTarget_P.DrawMarkers_size;
  line_idx_2 = idx + FindTarget_P.DrawMarkers_size;
  line_idx_3 = ms + FindTarget_P.DrawMarkers_size;
  maxNumBlobsReached = false;

  /* Find the visible portion of a line. */
  visited1 = false;
  visited2 = false;
  done = false;
  line_idx_0 = n;
  line_idx_1 = pixListNinc;
  line_idx_2_0 = line_idx_2;
  line_idx_3_0 = line_idx_3;
  while (!done) {
    BlobAnalysis_NUM_PIX_DW = 0U;
    stackIdx = 0U;

    /* Determine viewport violations. */
    if (line_idx_0 < 0) {
      BlobAnalysis_NUM_PIX_DW = 4U;
    } else {
      if (line_idx_0 > 319) {
        BlobAnalysis_NUM_PIX_DW = 8U;
      }
    }

    if (line_idx_2_0 < 0) {
      stackIdx = 4U;
    } else {
      if (line_idx_2_0 > 319) {
        stackIdx = 8U;
      }
    }

    if (line_idx_1 < 0) {
      BlobAnalysis_NUM_PIX_DW |= 1U;
    } else {
      if (line_idx_1 > 239) {
        BlobAnalysis_NUM_PIX_DW |= 2U;
      }
    }

    if (line_idx_3_0 < 0) {
      stackIdx |= 1U;
    } else {
      if (line_idx_3_0 > 239) {
        stackIdx |= 2U;
      }
    }

    if (!((BlobAnalysis_NUM_PIX_DW | stackIdx) != 0U)) {
      /* Line falls completely within bounds. */
      done = true;
      maxNumBlobsReached = true;
    } else if ((BlobAnalysis_NUM_PIX_DW & stackIdx) != 0U) {
      /* Line falls completely out of bounds. */
      done = true;
      maxNumBlobsReached = false;
    } else if (BlobAnalysis_NUM_PIX_DW != 0U) {
      /* Clip 1st point; if it's in-bounds, clip 2nd point. */
      if (visited1) {
        line_idx_0 = n;
        line_idx_1 = pixListNinc;
      }

      loop = line_idx_2_0 - line_idx_0;
      j = line_idx_3_0 - line_idx_1;
      if ((loop > 1073741824) || (loop < -1073741824) || ((j > 1073741824) || (j
            < -1073741824))) {
        /* Possible Inf or Nan. */
        done = true;
        maxNumBlobsReached = false;
        visited1 = true;
      } else if ((BlobAnalysis_NUM_PIX_DW & 4U) != 0U) {
        /* Violated RMin. */
        idxFillColorCur = -line_idx_0 * j;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (loop >= 0)) || ((idxFillColorCur <
          0) && (loop < 0))) {
          line_idx_1 += (div_s32_floor(idxFillColorCur << 1, loop) + 1) >> 1;
        } else {
          line_idx_1 -= (div_s32_floor(-idxFillColorCur << 1, loop) + 1) >> 1;
        }

        line_idx_0 = 0;
        visited1 = true;
      } else if ((BlobAnalysis_NUM_PIX_DW & 8U) != 0U) {
        /* Violated RMax. */
        idxFillColorCur = (319 - line_idx_0) * j;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (loop >= 0)) || ((idxFillColorCur <
          0) && (loop < 0))) {
          line_idx_1 += (div_s32_floor(idxFillColorCur << 1, loop) + 1) >> 1;
        } else {
          line_idx_1 -= (div_s32_floor(-idxFillColorCur << 1, loop) + 1) >> 1;
        }

        line_idx_0 = 319;
        visited1 = true;
      } else if ((BlobAnalysis_NUM_PIX_DW & 1U) != 0U) {
        /* Violated CMin. */
        idxFillColorCur = -line_idx_1 * loop;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (j >= 0)) || ((idxFillColorCur < 0)
                    && (j < 0))) {
          line_idx_0 += (div_s32_floor(idxFillColorCur << 1, j) + 1) >> 1;
        } else {
          line_idx_0 -= (div_s32_floor(-idxFillColorCur << 1, j) + 1) >> 1;
        }

        line_idx_1 = 0;
        visited1 = true;
      } else {
        /* Violated CMax. */
        idxFillColorCur = (239 - line_idx_1) * loop;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (j >= 0)) || ((idxFillColorCur < 0)
                    && (j < 0))) {
          line_idx_0 += (div_s32_floor(idxFillColorCur << 1, j) + 1) >> 1;
        } else {
          line_idx_0 -= (div_s32_floor(-idxFillColorCur << 1, j) + 1) >> 1;
        }

        line_idx_1 = 239;
        visited1 = true;
      }
    } else {
      /* Clip the 2nd point. */
      if (visited2) {
        line_idx_2_0 = line_idx_2;
        line_idx_3_0 = line_idx_3;
      }

      loop = line_idx_2_0 - line_idx_0;
      j = line_idx_3_0 - line_idx_1;
      if ((loop > 1073741824) || (loop < -1073741824) || ((j > 1073741824) || (j
            < -1073741824))) {
        /* Possible Inf or Nan. */
        done = true;
        maxNumBlobsReached = false;
        visited2 = true;
      } else if ((stackIdx & 4U) != 0U) {
        /* Violated RMin. */
        idxFillColorCur = -line_idx_2_0 * j;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (loop >= 0)) || ((idxFillColorCur <
          0) && (loop < 0))) {
          line_idx_3_0 += (div_s32_floor(idxFillColorCur << 1, loop) + 1) >> 1;
        } else {
          line_idx_3_0 -= (div_s32_floor(-idxFillColorCur << 1, loop) + 1) >> 1;
        }

        line_idx_2_0 = 0;
        visited2 = true;
      } else if ((stackIdx & 8U) != 0U) {
        /* Violated RMax. */
        idxFillColorCur = (319 - line_idx_2_0) * j;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (loop >= 0)) || ((idxFillColorCur <
          0) && (loop < 0))) {
          line_idx_3_0 += (div_s32_floor(idxFillColorCur << 1, loop) + 1) >> 1;
        } else {
          line_idx_3_0 -= (div_s32_floor(-idxFillColorCur << 1, loop) + 1) >> 1;
        }

        line_idx_2_0 = 319;
        visited2 = true;
      } else if ((stackIdx & 1U) != 0U) {
        /* Violated CMin. */
        idxFillColorCur = -line_idx_3_0 * loop;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (j >= 0)) || ((idxFillColorCur < 0)
                    && (j < 0))) {
          line_idx_2_0 += (div_s32_floor(idxFillColorCur << 1, j) + 1) >> 1;
        } else {
          line_idx_2_0 -= (div_s32_floor(-idxFillColorCur << 1, j) + 1) >> 1;
        }

        line_idx_3_0 = 0;
        visited2 = true;
      } else {
        /* Violated CMax. */
        idxFillColorCur = (239 - line_idx_3_0) * loop;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (j >= 0)) || ((idxFillColorCur < 0)
                    && (j < 0))) {
          line_idx_2_0 += (div_s32_floor(idxFillColorCur << 1, j) + 1) >> 1;
        } else {
          line_idx_2_0 -= (div_s32_floor(-idxFillColorCur << 1, j) + 1) >> 1;
        }

        line_idx_3_0 = 239;
        visited2 = true;
      }
    }
  }

  if (maxNumBlobsReached) {
    loop = line_idx_1 * 320 + line_idx_0;
    for (j = line_idx_0; j <= line_idx_2_0; j++) {
      FindTarget_B.greenIntensity[loop] =
        FindTarget_P.DrawMarkers_RTP_FILLCOLOR[0];
      FindTarget_B.DrawMarkers_o2[loop] =
        FindTarget_P.DrawMarkers_RTP_FILLCOLOR[1];
      FindTarget_B.DrawMarkers_o3[loop] =
        FindTarget_P.DrawMarkers_RTP_FILLCOLOR[2];
      loop += 321;
    }
  }

  n = idx - FindTarget_P.DrawMarkers_size;
  pixListNinc = ms + FindTarget_P.DrawMarkers_size;
  line_idx_2 = idx + FindTarget_P.DrawMarkers_size;
  line_idx_3 = ms - FindTarget_P.DrawMarkers_size;
  maxNumBlobsReached = false;

  /* Find the visible portion of a line. */
  visited1 = false;
  visited2 = false;
  done = false;
  line_idx_0 = n;
  line_idx_1 = pixListNinc;
  line_idx_2_0 = line_idx_2;
  line_idx_3_0 = line_idx_3;
  while (!done) {
    BlobAnalysis_NUM_PIX_DW = 0U;
    stackIdx = 0U;

    /* Determine viewport violations. */
    if (line_idx_0 < 0) {
      BlobAnalysis_NUM_PIX_DW = 4U;
    } else {
      if (line_idx_0 > 319) {
        BlobAnalysis_NUM_PIX_DW = 8U;
      }
    }

    if (line_idx_2_0 < 0) {
      stackIdx = 4U;
    } else {
      if (line_idx_2_0 > 319) {
        stackIdx = 8U;
      }
    }

    if (line_idx_1 < 0) {
      BlobAnalysis_NUM_PIX_DW |= 1U;
    } else {
      if (line_idx_1 > 239) {
        BlobAnalysis_NUM_PIX_DW |= 2U;
      }
    }

    if (line_idx_3_0 < 0) {
      stackIdx |= 1U;
    } else {
      if (line_idx_3_0 > 239) {
        stackIdx |= 2U;
      }
    }

    if (!((BlobAnalysis_NUM_PIX_DW | stackIdx) != 0U)) {
      /* Line falls completely within bounds. */
      done = true;
      maxNumBlobsReached = true;
    } else if ((BlobAnalysis_NUM_PIX_DW & stackIdx) != 0U) {
      /* Line falls completely out of bounds. */
      done = true;
      maxNumBlobsReached = false;
    } else if (BlobAnalysis_NUM_PIX_DW != 0U) {
      /* Clip 1st point; if it's in-bounds, clip 2nd point. */
      if (visited1) {
        line_idx_0 = n;
        line_idx_1 = pixListNinc;
      }

      loop = line_idx_2_0 - line_idx_0;
      j = line_idx_3_0 - line_idx_1;
      if ((loop > 1073741824) || (loop < -1073741824) || ((j > 1073741824) || (j
            < -1073741824))) {
        /* Possible Inf or Nan. */
        done = true;
        maxNumBlobsReached = false;
        visited1 = true;
      } else if ((BlobAnalysis_NUM_PIX_DW & 4U) != 0U) {
        /* Violated RMin. */
        idxFillColorCur = -line_idx_0 * j;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (loop >= 0)) || ((idxFillColorCur <
          0) && (loop < 0))) {
          line_idx_1 += (div_s32_floor(idxFillColorCur << 1, loop) + 1) >> 1;
        } else {
          line_idx_1 -= (div_s32_floor(-idxFillColorCur << 1, loop) + 1) >> 1;
        }

        line_idx_0 = 0;
        visited1 = true;
      } else if ((BlobAnalysis_NUM_PIX_DW & 8U) != 0U) {
        /* Violated RMax. */
        idxFillColorCur = (319 - line_idx_0) * j;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (loop >= 0)) || ((idxFillColorCur <
          0) && (loop < 0))) {
          line_idx_1 += (div_s32_floor(idxFillColorCur << 1, loop) + 1) >> 1;
        } else {
          line_idx_1 -= (div_s32_floor(-idxFillColorCur << 1, loop) + 1) >> 1;
        }

        line_idx_0 = 319;
        visited1 = true;
      } else if ((BlobAnalysis_NUM_PIX_DW & 1U) != 0U) {
        /* Violated CMin. */
        idxFillColorCur = -line_idx_1 * loop;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (j >= 0)) || ((idxFillColorCur < 0)
                    && (j < 0))) {
          line_idx_0 += (div_s32_floor(idxFillColorCur << 1, j) + 1) >> 1;
        } else {
          line_idx_0 -= (div_s32_floor(-idxFillColorCur << 1, j) + 1) >> 1;
        }

        line_idx_1 = 0;
        visited1 = true;
      } else {
        /* Violated CMax. */
        idxFillColorCur = (239 - line_idx_1) * loop;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (j >= 0)) || ((idxFillColorCur < 0)
                    && (j < 0))) {
          line_idx_0 += (div_s32_floor(idxFillColorCur << 1, j) + 1) >> 1;
        } else {
          line_idx_0 -= (div_s32_floor(-idxFillColorCur << 1, j) + 1) >> 1;
        }

        line_idx_1 = 239;
        visited1 = true;
      }
    } else {
      /* Clip the 2nd point. */
      if (visited2) {
        line_idx_2_0 = line_idx_2;
        line_idx_3_0 = line_idx_3;
      }

      loop = line_idx_2_0 - line_idx_0;
      j = line_idx_3_0 - line_idx_1;
      if ((loop > 1073741824) || (loop < -1073741824) || ((j > 1073741824) || (j
            < -1073741824))) {
        /* Possible Inf or Nan. */
        done = true;
        maxNumBlobsReached = false;
        visited2 = true;
      } else if ((stackIdx & 4U) != 0U) {
        /* Violated RMin. */
        idxFillColorCur = -line_idx_2_0 * j;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (loop >= 0)) || ((idxFillColorCur <
          0) && (loop < 0))) {
          line_idx_3_0 += (div_s32_floor(idxFillColorCur << 1, loop) + 1) >> 1;
        } else {
          line_idx_3_0 -= (div_s32_floor(-idxFillColorCur << 1, loop) + 1) >> 1;
        }

        line_idx_2_0 = 0;
        visited2 = true;
      } else if ((stackIdx & 8U) != 0U) {
        /* Violated RMax. */
        idxFillColorCur = (319 - line_idx_2_0) * j;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (loop >= 0)) || ((idxFillColorCur <
          0) && (loop < 0))) {
          line_idx_3_0 += (div_s32_floor(idxFillColorCur << 1, loop) + 1) >> 1;
        } else {
          line_idx_3_0 -= (div_s32_floor(-idxFillColorCur << 1, loop) + 1) >> 1;
        }

        line_idx_2_0 = 319;
        visited2 = true;
      } else if ((stackIdx & 1U) != 0U) {
        /* Violated CMin. */
        idxFillColorCur = -line_idx_3_0 * loop;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (j >= 0)) || ((idxFillColorCur < 0)
                    && (j < 0))) {
          line_idx_2_0 += (div_s32_floor(idxFillColorCur << 1, j) + 1) >> 1;
        } else {
          line_idx_2_0 -= (div_s32_floor(-idxFillColorCur << 1, j) + 1) >> 1;
        }

        line_idx_3_0 = 0;
        visited2 = true;
      } else {
        /* Violated CMax. */
        idxFillColorCur = (239 - line_idx_3_0) * loop;
        if ((idxFillColorCur > 1073741824) || (idxFillColorCur < -1073741824)) {
          /* Check for Inf or Nan. */
          done = true;
          maxNumBlobsReached = false;
        } else if (((idxFillColorCur >= 0) && (j >= 0)) || ((idxFillColorCur < 0)
                    && (j < 0))) {
          line_idx_2_0 += (div_s32_floor(idxFillColorCur << 1, j) + 1) >> 1;
        } else {
          line_idx_2_0 -= (div_s32_floor(-idxFillColorCur << 1, j) + 1) >> 1;
        }

        line_idx_3_0 = 239;
        visited2 = true;
      }
    }
  }

  if (maxNumBlobsReached) {
    loop = line_idx_1 * 320 + line_idx_0;
    for (j = line_idx_0; j <= line_idx_2_0; j++) {
      FindTarget_B.greenIntensity[loop] =
        FindTarget_P.DrawMarkers_RTP_FILLCOLOR[0];
      FindTarget_B.DrawMarkers_o2[loop] =
        FindTarget_P.DrawMarkers_RTP_FILLCOLOR[1];
      FindTarget_B.DrawMarkers_o3[loop] =
        FindTarget_P.DrawMarkers_RTP_FILLCOLOR[2];
      loop -= 319;
    }
  }

  /* End of S-Function (svipdrawmarkers): '<S18>/Draw Markers' */

  /* Gain: '<S18>/Gain' */
  for (loop = 0; loop < 76800; loop++) {
    FindTarget_B.Gain_e[loop] = (uint8_T)(FindTarget_B.Compare_d[loop] ?
      (int32_T)FindTarget_P.Gain_Gain_a : 0);
  }

  /* End of Gain: '<S18>/Gain' */

  /* Concatenate: '<S18>/Matrix Concatenate2' incorporates:
   *  Concatenate: '<S18>/Matrix Concatenate1'
   */
  for (loop = 0; loop < 240; loop++) {
    memcpy(&FindTarget_B.MatrixConcatenate2[loop * 640],
           &FindTarget_B.greenIntensity[loop * 320], 320U * sizeof(uint8_T));
  }

  for (loop = 0; loop < 240; loop++) {
    memcpy(&FindTarget_B.MatrixConcatenate2[loop * 640 + 320],
           &FindTarget_B.Gain_e[loop * 320], 320U * sizeof(uint8_T));

    /* Concatenate: '<S18>/Matrix Concatenate1' */
    memcpy(&FindTarget_B.MatrixConcatenate1[loop * 640],
           &FindTarget_B.DrawMarkers_o2[loop * 320], 320U * sizeof(uint8_T));
  }

  /* End of Concatenate: '<S18>/Matrix Concatenate2' */
  for (loop = 0; loop < 240; loop++) {
    /* Concatenate: '<S18>/Matrix Concatenate1' incorporates:
     *  Concatenate: '<S18>/Matrix Concatenate'
     */
    memcpy(&FindTarget_B.MatrixConcatenate1[loop * 640 + 320],
           &FindTarget_B.Gain_e[loop * 320], 320U * sizeof(uint8_T));

    /* Concatenate: '<S18>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S18>/Matrix Concatenate1'
     */
    memcpy(&FindTarget_B.MatrixConcatenate[loop * 640],
           &FindTarget_B.DrawMarkers_o3[loop * 320], 320U * sizeof(uint8_T));
  }

  /* Concatenate: '<S18>/Matrix Concatenate' */
  for (loop = 0; loop < 240; loop++) {
    memcpy(&FindTarget_B.MatrixConcatenate[loop * 640 + 320],
           &FindTarget_B.Gain_e[loop * 320], 320U * sizeof(uint8_T));
  }

  /* S-Function (sdl_video_display_sfcn): '<S15>/SDL Video Display' */
  MW_SDL_videoDisplayOutput(FindTarget_B.MatrixConcatenate2,
    FindTarget_B.MatrixConcatenate1, FindTarget_B.MatrixConcatenate);

  /* RelationalOperator: '<S16>/Compare' incorporates:
   *  Constant: '<S16>/Constant'
   */
  FindTarget_B.Compare_i = (rtb_BlobAnalysis_o1 > FindTarget_P.Constant_Value_f);

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  if (FindTarget_B.Compare_i && (FindTarget_DW.DiscreteTimeIntegrator_PrevRese <=
       0)) {
    FindTarget_DW.DiscreteTimeIntegrator_DSTATE =
      FindTarget_P.DiscreteTimeIntegrator_IC;
  }

  FindTarget_B.DiscreteTimeIntegrator =
    FindTarget_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */

  /* Switch: '<S15>/Switch' incorporates:
   *  Bias: '<S15>/Subtract Image Centre'
   *  Constant: '<S15>/Tilt1'
   *  Gain: '<S15>/Convert pixels to degrees'
   */
  if (rtb_BlobAnalysis_o1 > FindTarget_P.Switch_Threshold) {
    FindTarget_B.Switch[0] = (rtb_BlobAnalysis_o2[0] +
      FindTarget_P.SubtractImageCentre_Bias[0]) *
      FindTarget_P.Convertpixelstodegrees_Gain;
    FindTarget_B.Switch[1] = (rtb_BlobAnalysis_o2[1] +
      FindTarget_P.SubtractImageCentre_Bias[1]) *
      FindTarget_P.Convertpixelstodegrees_Gain;
  } else {
    FindTarget_B.Switch[0] = FindTarget_P.Tilt1_Value[0];
    FindTarget_B.Switch[1] = FindTarget_P.Tilt1_Value[1];
  }

  /* End of Switch: '<S15>/Switch' */

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S15>/Constant'
   */
  FindTarget_DW.DiscreteTimeIntegrator_DSTATE +=
    FindTarget_P.DiscreteTimeIntegrator_gainval * FindTarget_P.Constant_Value;
  FindTarget_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)FindTarget_B.Compare_i;
  FindTarget_DW.Imageprocessing_SubsysRanBC = 4;

  /* End of Outputs for S-Function (fcncallgen): '<S3>/Function-Call Generator' */

  /* Gain: '<S3>/Gain1' */
  rtb_BlobAnalysis_o2[0] = FindTarget_P.Gain1_Gain_c * FindTarget_B.Switch[0];
  rtb_BlobAnalysis_o2[1] = FindTarget_P.Gain1_Gain_c * FindTarget_B.Switch[1];

  /* InitialCondition: '<S3>/IC1' */
  if (FindTarget_DW.IC1_FirstOutputTime) {
    FindTarget_DW.IC1_FirstOutputTime = false;
    rtb_BlobAnalysis_o2[0] = FindTarget_P.IC1_Value[0];
    rtb_BlobAnalysis_o2[1] = FindTarget_P.IC1_Value[1];
  }

  /* End of InitialCondition: '<S3>/IC1' */

  /* Bias: '<S3>/Bias1' */
  FindTarget_B.Bias1[0] = rtb_BlobAnalysis_o2[0] + FindTarget_P.Bias1_Bias_j[0];
  FindTarget_B.Bias1[1] = rtb_BlobAnalysis_o2[1] + FindTarget_P.Bias1_Bias_j[1];
}

/* Model update function for TID1 */
void FindTarget_update1(void)          /* Sample time: [0.33333333333333331s, 0.0s] */
{
  /* Update for RateTransition: '<S3>/Rate Transition4' */
  FindTarget_DW.RateTransition4_Buffer0 = FindTarget_B.DiscreteTimeIntegrator;

  /* Update for RateTransition: '<S3>/Rate Transition6' */
  FindTarget_DW.RateTransition6_Buffer0[0] = FindTarget_B.Bias1[0];
  FindTarget_DW.RateTransition6_Buffer0[1] = FindTarget_B.Bias1[1];

  /* Update for RateTransition: '<S3>/Rate Transition5' */
  FindTarget_DW.RateTransition5_Buffer0 = FindTarget_B.Compare_i;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.33333333333333331, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  FindTarget_M->Timing.clockTick1++;
}

/* Model initialize function */
void FindTarget_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)FindTarget_M, 0,
                sizeof(RT_MODEL_FindTarget_T));
  rtmSetTFinal(FindTarget_M, -1);
  FindTarget_M->Timing.stepSize0 = 0.033333333333333333;

  /* External mode info */
  FindTarget_M->Sizes.checksums[0] = (2115789970U);
  FindTarget_M->Sizes.checksums[1] = (3551251627U);
  FindTarget_M->Sizes.checksums[2] = (1570916689U);
  FindTarget_M->Sizes.checksums[3] = (2970150352U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    FindTarget_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&FindTarget_DW.DriveToTarget_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&FindTarget_DW.SearchForTarget_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&FindTarget_DW.Imageprocessing_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&FindTarget_DW.Imageprocessing_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&FindTarget_DW.Imageprocessing_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&FindTarget_DW.Imageprocessing_SubsysRanBC;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)&FindTarget_DW.Stateestimator_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&FindTarget_DW.Stateestimator_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&FindTarget_DW.Stateestimator_SubsysRanBC;
    rteiSetModelMappingInfoPtr(FindTarget_M->extModeInfo,
      &FindTarget_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(FindTarget_M->extModeInfo, FindTarget_M->Sizes.checksums);
    rteiSetTPtr(FindTarget_M->extModeInfo, rtmGetTPtr(FindTarget_M));
  }

  /* block I/O */
  (void) memset(((void *) &FindTarget_B), 0,
                sizeof(B_FindTarget_T));

  /* states (dwork) */
  (void) memset((void *)&FindTarget_DW, 0,
                sizeof(DW_FindTarget_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    FindTarget_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  {
    uint8_T tmp;

    /* Start for RateTransition: '<S3>/Rate Transition4' */
    FindTarget_B.RateTransition4 = FindTarget_P.RateTransition4_X0;

    /* Start for RateTransition: '<S3>/Rate Transition6' */
    FindTarget_B.RateTransition6[0] = FindTarget_P.RateTransition6_X0;
    FindTarget_B.RateTransition6[1] = FindTarget_P.RateTransition6_X0;

    /* Start for RateTransition: '<S3>/Rate Transition5' */
    FindTarget_B.RateTransition5 = FindTarget_P.RateTransition5_X0;

    /* InitializeConditions for Enabled SubSystem: '<Root>/State estimator' */
    /* InitializeConditions for UnitDelay: '<S24>/Delay Input1' */
    FindTarget_DW.DelayInput1_DSTATE = FindTarget_P.DetectChange_vinit;

    /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
    FindTarget_DW.UnitDelay1_DSTATE[0] =
      FindTarget_P.UnitDelay1_InitialCondition[0];
    FindTarget_DW.UnitDelay1_DSTATE[1] =
      FindTarget_P.UnitDelay1_InitialCondition[1];
    FindTarget_DW.UnitDelay1_DSTATE[2] =
      FindTarget_P.UnitDelay1_InitialCondition[2];

    /* InitializeConditions for UnitDelay: '<S5>/Unit Delay2' */
    FindTarget_DW.UnitDelay2_DSTATE[0] =
      FindTarget_P.UnitDelay2_InitialCondition[0];
    FindTarget_DW.UnitDelay2_DSTATE[1] =
      FindTarget_P.UnitDelay2_InitialCondition[1];

    /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
    memcpy(&FindTarget_DW.UnitDelay_DSTATE[0],
           &FindTarget_P.UnitDelay_InitialCondition[0], 9U * sizeof(real_T));

    /* End of InitializeConditions for SubSystem: '<Root>/State estimator' */

    /* Start for Constant: '<Root>/Tilt Angle' */
    FindTarget_B.TiltAngle = FindTarget_P.TiltAngle_Value;

    /* Start for Constant: '<Root>/Pan  Angle' */
    FindTarget_B.PanAngle = FindTarget_P.PanAngle_Value;

    /* Start for S-Function (linuxGpioRead_sfcn): '<Root>/GPIO Read' */
    tmp = 0U;
    MW_gpioInit(18U, 1U, 1U, &tmp);

    /* Start for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
    MW_videoCaptureInit(FindTarget_ConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 320U,
                        240U, 2U, 2U, 1U, 0.033333333333333333);

    /* Start for S-Function (fcncallgen): '<S3>/Function-Call Generator' incorporates:
     *  Start for SubSystem: '<S3>/Image processing'
     */
    /* Start for S-Function (sdl_video_display_sfcn): '<S15>/SDL Video Display' */
    MW_SDL_videoDisplayInit(1, 1, 1, 640, 240);

    /* End of Start for S-Function (fcncallgen): '<S3>/Function-Call Generator' */

    /* Start for InitialCondition: '<S3>/IC1' */
    FindTarget_DW.IC1_FirstOutputTime = true;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition4' */
    FindTarget_DW.RateTransition4_Buffer0 = FindTarget_P.RateTransition4_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition6' */
    FindTarget_DW.RateTransition6_Buffer0[0] = FindTarget_P.RateTransition6_X0;
    FindTarget_DW.RateTransition6_Buffer0[1] = FindTarget_P.RateTransition6_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition5' */
    FindTarget_DW.RateTransition5_Buffer0 = FindTarget_P.RateTransition5_X0;

    /* InitializeConditions for S-Function (sfix_udelay): '<S1>/Tapped Delay' */
    FindTarget_DW.TappedDelay_X[0] = (FindTarget_P.TappedDelay_vinit != 0);
    FindTarget_DW.TappedDelay_X[1] = (FindTarget_P.TappedDelay_vinit != 0);
    FindTarget_DW.TappedDelay_X[2] = (FindTarget_P.TappedDelay_vinit != 0);

    /* InitializeConditions for UnitDelay: '<S7>/Delay Input1' */
    FindTarget_DW.DelayInput1_DSTATE_n = FindTarget_P.DetectIncrease_vinit;

    /* InitializeConditions for Chart: '<Root>/Finite State Machine' */
    FindTarget_DW.sfEvent = FindTarget_CALL_EVENT;
    FindTarget_DW.is_Running = FindTarget_IN_NO_ACTIVE_CHILD;
    FindTarget_DW.is_Nod = FindTarget_IN_NO_ACTIVE_CHILD;
    FindTarget_DW.temporalCounter_i1 = 0U;
    FindTarget_DW.is_active_c7_FindTarget = 0U;
    FindTarget_DW.is_c7_FindTarget = FindTarget_IN_NO_ACTIVE_CHILD;

    /* InitializeConditions for MATLAB Function: '<S4>/Serial Write' */
    FindTarget_DW.spHandle_not_empty = false;

    /* InitializeConditions for Function Call SubSystem: '<S2>/DriveToTarget' */
    /* InitializeConditions for UnitDelay: '<S14>/UD' incorporates:
     *  Enable for Chart: '<Root>/Finite State Machine'
     */
    FindTarget_DW.UD_DSTATE = FindTarget_P.DiscreteDerivative_ICPrevScaled;

    /* End of InitializeConditions for SubSystem: '<S2>/DriveToTarget' */

    /* InitializeConditions for Function Call SubSystem: '<S2>/SearchForTarget' */
    /* InitializeConditions for DiscretePulseGenerator: '<S9>/Pulse Generator' incorporates:
     *  Enable for Chart: '<Root>/Finite State Machine'
     */
    FindTarget_DW.clockTickCounter = 0;

    /* End of InitializeConditions for SubSystem: '<S2>/SearchForTarget' */

    /* InitializeConditions for S-Function (fcncallgen): '<S3>/Function-Call Generator' incorporates:
     *  InitializeConditions for SubSystem: '<S3>/Image processing'
     */
    /* Enable for S-Function (fcncallgen): '<S3>/Function-Call Generator' */
    /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
    FindTarget_DW.DiscreteTimeIntegrator_DSTATE =
      FindTarget_P.DiscreteTimeIntegrator_IC;
    FindTarget_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* End of Enable for S-Function (fcncallgen): '<S3>/Function-Call Generator' */
    /* End of InitializeConditions for S-Function (fcncallgen): '<S3>/Function-Call Generator' */
  }
}

/* Model terminate function */
void FindTarget_terminate(void)
{
  /* Terminate for S-Function (linuxGpioRead_sfcn): '<Root>/GPIO Read' */
  MW_gpioTerminate(18U);

  /* Terminate for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureTerminate(FindTarget_ConstP.V4L2VideoCapture_p1);

  /* Terminate for S-Function (fcncallgen): '<S3>/Function-Call Generator' incorporates:
   *  Terminate for SubSystem: '<S3>/Image processing'
   */
  /* Terminate for S-Function (sdl_video_display_sfcn): '<S15>/SDL Video Display' */
  MW_SDL_videoDisplayTerminate(640, 240);

  /* End of Terminate for S-Function (fcncallgen): '<S3>/Function-Call Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
