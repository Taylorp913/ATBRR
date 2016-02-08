/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FindTarget_data.c
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

/* Block parameters (auto storage) */
P_FindTarget_T FindTarget_P = {
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S14>/UD'
                                        */
  1.0,                                 /* Mask Parameter: CoulombViscousFriction_gain
                                        * Referenced by: '<S21>/Gain'
                                        */
  5.0,                                 /* Mask Parameter: CoulombViscousFriction_offset
                                        * Referenced by: '<S21>/Gain1'
                                        */
  0.0,                                 /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S24>/Delay Input1'
                                        */
  100U,                                /* Mask Parameter: BlobAnalysis_minArea
                                        * Referenced by: '<S15>/Blob Analysis'
                                        */
  5U,                                  /* Mask Parameter: DrawMarkers_size
                                        * Referenced by: '<S18>/Draw Markers'
                                        */
  40U,                                 /* Mask Parameter: CompareToThreshold_const
                                        * Referenced by: '<S20>/Constant'
                                        */
  3U,                                  /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S6>/Constant'
                                        */
  0U,                                  /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S1>/Tapped Delay'
                                        */
  0,                                   /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S7>/Delay Input1'
                                        */
  45.0,                                /* Expression: 45
                                        * Referenced by: '<S12>/Speed Gain'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S12>/Saturation3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation3'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S13>/D'
                                        */
  30.0,                                /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S14>/TSamp'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S13>/P'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<S13>/Saturation2'
                                        */
  -20.0,                               /* Expression: -20
                                        * Referenced by: '<S13>/Saturation2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S13>/Gain3'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  -30.0,                               /* Expression: -30
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Gain4'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  -30.0,                               /* Expression: -30
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  -15.0,                               /* Expression: -15
                                        * Referenced by: '<S9>/Gain1'
                                        */
  15.0,                                /* Expression: 15
                                        * Referenced by: '<S9>/Gain4'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<S15>/Tilt1'
   */
  { 0.0, 0.0 },

  /*  Expression: -[240 320]/2
   * Referenced by: '<S15>/Subtract Image Centre'
   */
  { -120.0, -160.0 },
  0.166,                               /* Expression: 0.083*2
                                        * Referenced by: '<S15>/Convert pixels to degrees'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  1.0,                                 /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S15>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Discrete-Time Integrator'
                                        */

  /*  Expression: [-0.4 0 0]'
   * Referenced by: '<S5>/Unit Delay1'
   */
  { -0.4, 0.0, 0.0 },

  /*  Expression: [0 0]
   * Referenced by: '<S5>/Unit Delay2'
   */
  { 0.0, 0.0 },
  5.0E-5,                              /* Expression: 0.00005
                                        * Referenced by: '<S5>/Power2m'
                                        */

  /*  Expression: 0.1*eye(3)
   * Referenced by: '<S5>/Unit Delay'
   */
  { 0.1, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.1 },
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S5>/r2d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition6'
                                        */
  -20.0,                               /* Expression: -20
                                        * Referenced by: '<Root>/Tilt Angle'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pan  Angle'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S4>/Saturation3'
                                        */
  -100.0,                              /* Expression: -100
                                        * Referenced by: '<S4>/Saturation3'
                                        */
  1.28,                                /* Expression: 1.28
                                        * Referenced by: '<S4>/Gain'
                                        */
  128.0,                               /* Expression: 128
                                        * Referenced by: '<S4>/Bias'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S4>/Saturation'
                                        */
  -30.0,                               /* Expression: -30
                                        * Referenced by: '<S4>/Saturation'
                                        */
  80.0,                                /* Expression: 80
                                        * Referenced by: '<S4>/Bias2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  -30.0,                               /* Expression: -30
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S4>/Bias1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Gain1'
                                        */

  /*  Expression: [-20 0]
   * Referenced by: '<S3>/IC1'
   */
  { -20.0, 0.0 },

  /*  Expression: [-20 0]
   * Referenced by: '<S3>/Bias1'
   */
  { -20.0, 0.0 },
  0,                                   /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S16>/Constant'
                                        */
  0,                                   /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S15>/Switch'
                                        */

  /*  Computed Parameter: DrawMarkers_RTP_FILLCOLOR
   * Referenced by: '<S18>/Draw Markers'
   */
  { 255U, 0U, 0U },
  255U,                                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S18>/Gain'
                                        */
  0                                    /* Computed Parameter: RateTransition5_X0
                                        * Referenced by: '<S3>/Rate Transition5'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_FindTarget_T FindTarget_ConstP = {
  /* Computed Parameter: BlobAnalysis_WALKER_RTP
   * Referenced by: '<S15>/Blob Analysis'
   */
  { -1, 321, 322, 323, 1, -321, -322, -323 },

  /* Expression: devName
   * Referenced by: '<Root>/V4L2 Video Capture'
   */
  { 47U, 100U, 101U, 118U, 47U, 118U, 105U, 100U, 101U, 111U, 48U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
