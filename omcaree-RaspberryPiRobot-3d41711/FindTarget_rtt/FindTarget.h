/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FindTarget.h
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

#ifndef RTW_HEADER_FindTarget_h_
#define RTW_HEADER_FindTarget_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef FindTarget_COMMON_INCLUDES_
# define FindTarget_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sdl_video_display.h"
#include "MW_gpio_lct.h"
#include "v4l2_capture.h"
#endif                                 /* FindTarget_COMMON_INCLUDES_ */

#include "FindTarget_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  uint8_T V4L2VideoCapture_o1[76800];  /* '<Root>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o2[76800];  /* '<Root>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o3[76800];  /* '<Root>/V4L2 Video Capture' */
  uint8_T greenIntensity[76800];       /* '<S17>/Calculate Green Intensity' */
  uint8_T DrawMarkers_o3[76800];       /* '<S18>/Draw Markers' */
  uint8_T DrawMarkers_o2[76800];       /* '<S18>/Draw Markers' */
  uint8_T Gain_e[76800];               /* '<S18>/Gain' */
  real_T RateTransition4;              /* '<S3>/Rate Transition4' */
  real_T RateTransition6[2];           /* '<S3>/Rate Transition6' */
  real_T TiltAngle;                    /* '<Root>/Tilt Angle' */
  real_T PanAngle;                     /* '<Root>/Pan  Angle' */
  real_T Bias1[2];                     /* '<S3>/Bias1' */
  real_T Xout[3];                      /* '<S5>/Measurement Update' */
  real_T Pout[9];                      /* '<S5>/Measurement Update' */
  real_T DiscreteTimeIntegrator;       /* '<S15>/Discrete-Time Integrator' */
  real_T Switch[2];                    /* '<S15>/Switch' */
  real_T MotorLeft;                    /* '<Root>/Finite State Machine' */
  real_T MotorRight;                   /* '<Root>/Finite State Machine' */
  real_T CameraElevation;              /* '<Root>/Finite State Machine' */
  real_T CameraAzimuth;                /* '<Root>/Finite State Machine' */
  real_T TargetPosition[3];            /* '<Root>/Finite State Machine' */
  real_T Gain1;                        /* '<S9>/Gain1' */
  real_T Gain4;                        /* '<S9>/Gain4' */
  real_T Saturation2;                  /* '<S13>/Saturation2' */
  real_T Saturation2_f;                /* '<S8>/Saturation2' */
  real_T Saturation1;                  /* '<S8>/Saturation1' */
  uint8_T RateTransition[76800];       /* '<S3>/Rate Transition' */
  uint8_T RateTransition1[76800];      /* '<S3>/Rate Transition1' */
  uint8_T RateTransition2[76800];      /* '<S3>/Rate Transition2' */
  uint8_T MatrixConcatenate2[153600];  /* '<S18>/Matrix Concatenate2' */
  uint8_T MatrixConcatenate1[153600];  /* '<S18>/Matrix Concatenate1' */
  uint8_T MatrixConcatenate[153600];   /* '<S18>/Matrix Concatenate' */
  boolean_T RateTransition5;           /* '<S3>/Rate Transition5' */
  boolean_T Compare;                   /* '<S6>/Compare' */
  boolean_T FixPtRelationalOperator;   /* '<S7>/FixPt Relational Operator' */
  boolean_T GPIORead;                  /* '<Root>/GPIO Read' */
  boolean_T status;                    /* '<S4>/Serial Write' */
  boolean_T Compare_i;                 /* '<S16>/Compare' */
  boolean_T Compare_d[76800];          /* '<S20>/Compare' */
} B_FindTarget_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T BlobAnalysis_STACK_DW[76800];/* '<S15>/Blob Analysis' */
  int16_T BlobAnalysis_M_PIXLIST_DW[76800];/* '<S15>/Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[76800];/* '<S15>/Blob Analysis' */
  uint8_T BlobAnalysis_PAD_DW[77924];  /* '<S15>/Blob Analysis' */
  real_T DelayInput1_DSTATE;           /* '<S24>/Delay Input1' */
  real_T UnitDelay1_DSTATE[3];         /* '<S5>/Unit Delay1' */
  real_T UnitDelay2_DSTATE[2];         /* '<S5>/Unit Delay2' */
  real_T UnitDelay_DSTATE[9];          /* '<S5>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S15>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S14>/UD' */
  real_T RateTransition4_Buffer0;      /* '<S3>/Rate Transition4' */
  real_T RateTransition6_Buffer0[2];   /* '<S3>/Rate Transition6' */
  real_T i;                            /* '<Root>/Finite State Machine' */
  struct {
    void *LoggedData;
  } State_PWORK;                       /* '<Root>/State' */

  struct {
    void *LoggedData;
  } MotorCommands_PWORK;               /* '<S8>/Motor Commands' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S13>/Scope' */

  int32_T spHandle;                    /* '<S4>/Serial Write' */
  int32_T sfEvent;                     /* '<Root>/Finite State Machine' */
  int32_T clockTickCounter;            /* '<S9>/Pulse Generator' */
  boolean_T TappedDelay_X[3];          /* '<S1>/Tapped Delay' */
  boolean_T DelayInput1_DSTATE_n;      /* '<S7>/Delay Input1' */
  int8_T Stateestimator_SubsysRanBC;   /* '<Root>/State estimator' */
  int8_T Imageprocessing_SubsysRanBC;  /* '<S3>/Image processing' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S15>/Discrete-Time Integrator' */
  int8_T DriveToTarget_SubsysRanBC;    /* '<S2>/DriveToTarget' */
  int8_T SearchForTarget_SubsysRanBC;  /* '<S2>/SearchForTarget' */
  uint8_T is_active_c7_FindTarget;     /* '<Root>/Finite State Machine' */
  uint8_T is_c7_FindTarget;            /* '<Root>/Finite State Machine' */
  uint8_T is_Running;                  /* '<Root>/Finite State Machine' */
  uint8_T is_Nod;                      /* '<Root>/Finite State Machine' */
  uint8_T temporalCounter_i1;          /* '<Root>/Finite State Machine' */
  boolean_T RateTransition5_Buffer0;   /* '<S3>/Rate Transition5' */
  boolean_T IC1_FirstOutputTime;       /* '<S3>/IC1' */
  boolean_T spHandle_not_empty;        /* '<S4>/Serial Write' */
  boolean_T isStable;                  /* '<Root>/Finite State Machine' */
  boolean_T Stateestimator_MODE;       /* '<Root>/State estimator' */
} DW_FindTarget_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: BlobAnalysis_WALKER_RTP
   * Referenced by: '<S15>/Blob Analysis'
   */
  int32_T BlobAnalysis_WALKER_RTP[8];

  /* Expression: devName
   * Referenced by: '<Root>/V4L2 Video Capture'
   */
  uint8_T V4L2VideoCapture_p1[12];
} ConstP_FindTarget_T;

/* Parameters (auto storage) */
struct P_FindTarget_T_ {
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S14>/UD'
                                          */
  real_T CoulombViscousFriction_gain;  /* Mask Parameter: CoulombViscousFriction_gain
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T CoulombViscousFriction_offset;/* Mask Parameter: CoulombViscousFriction_offset
                                        * Referenced by: '<S21>/Gain1'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S24>/Delay Input1'
                                        */
  uint32_T BlobAnalysis_minArea;       /* Mask Parameter: BlobAnalysis_minArea
                                        * Referenced by: '<S15>/Blob Analysis'
                                        */
  uint16_T DrawMarkers_size;           /* Mask Parameter: DrawMarkers_size
                                        * Referenced by: '<S18>/Draw Markers'
                                        */
  uint8_T CompareToThreshold_const;    /* Mask Parameter: CompareToThreshold_const
                                        * Referenced by: '<S20>/Constant'
                                        */
  uint8_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S6>/Constant'
                                        */
  uint8_T TappedDelay_vinit;           /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S1>/Tapped Delay'
                                        */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S7>/Delay Input1'
                                        */
  real_T SpeedGain_Gain;               /* Expression: 45
                                        * Referenced by: '<S12>/Speed Gain'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 10
                                        * Referenced by: '<S12>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S12>/Saturation3'
                                        */
  real_T D_Gain;                       /* Expression: 10
                                        * Referenced by: '<S13>/D'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S14>/TSamp'
                                        */
  real_T P_Gain;                       /* Expression: 10
                                        * Referenced by: '<S13>/P'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 20
                                        * Referenced by: '<S13>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -20
                                        * Referenced by: '<S13>/Saturation2'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S13>/Gain3'
                                        */
  real_T Saturation2_UpperSat_f;       /* Expression: 30
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_e;       /* Expression: -30
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S13>/Gain4'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 30
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -30
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 10
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 5
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T Gain1_Gain;                   /* Expression: -15
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Gain4_Gain_f;                 /* Expression: 15
                                        * Referenced by: '<S9>/Gain4'
                                        */
  real_T Tilt1_Value[2];               /* Expression: [0 0]
                                        * Referenced by: '<S15>/Tilt1'
                                        */
  real_T SubtractImageCentre_Bias[2];  /* Expression: -[240 320]/2
                                        * Referenced by: '<S15>/Subtract Image Centre'
                                        */
  real_T Convertpixelstodegrees_Gain;  /* Expression: 0.083*2
                                        * Referenced by: '<S15>/Convert pixels to degrees'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S15>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S15>/Discrete-Time Integrator'
                                        */
  real_T UnitDelay1_InitialCondition[3];/* Expression: [-0.4 0 0]'
                                         * Referenced by: '<S5>/Unit Delay1'
                                         */
  real_T UnitDelay2_InitialCondition[2];/* Expression: [0 0]
                                         * Referenced by: '<S5>/Unit Delay2'
                                         */
  real_T Power2m_Gain;                 /* Expression: 0.00005
                                        * Referenced by: '<S5>/Power2m'
                                        */
  real_T UnitDelay_InitialCondition[9];/* Expression: 0.1*eye(3)
                                        * Referenced by: '<S5>/Unit Delay'
                                        */
  real_T r2d_Gain;                     /* Expression: pi/180
                                        * Referenced by: '<S5>/r2d'
                                        */
  real_T RateTransition4_X0;           /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition4'
                                        */
  real_T RateTransition6_X0;           /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition6'
                                        */
  real_T TiltAngle_Value;              /* Expression: -20
                                        * Referenced by: '<Root>/Tilt Angle'
                                        */
  real_T PanAngle_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Pan  Angle'
                                        */
  real_T Saturation3_UpperSat_o;       /* Expression: 100
                                        * Referenced by: '<S4>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_o;       /* Expression: -100
                                        * Referenced by: '<S4>/Saturation3'
                                        */
  real_T Gain_Gain;                    /* Expression: 1.28
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Bias_Bias;                    /* Expression: 128
                                        * Referenced by: '<S4>/Bias'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 10
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -30
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Bias2_Bias;                   /* Expression: 80
                                        * Referenced by: '<S4>/Bias2'
                                        */
  real_T Saturation1_UpperSat_f;       /* Expression: 10
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_c;       /* Expression: -30
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T Bias1_Bias;                   /* Expression: 90
                                        * Referenced by: '<S4>/Bias1'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: -1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T IC1_Value[2];                 /* Expression: [-20 0]
                                        * Referenced by: '<S3>/IC1'
                                        */
  real_T Bias1_Bias_j[2];              /* Expression: [-20 0]
                                        * Referenced by: '<S3>/Bias1'
                                        */
  int32_T Constant_Value_f;            /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S16>/Constant'
                                        */
  int32_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S15>/Switch'
                                        */
  uint8_T DrawMarkers_RTP_FILLCOLOR[3];/* Computed Parameter: DrawMarkers_RTP_FILLCOLOR
                                        * Referenced by: '<S18>/Draw Markers'
                                        */
  uint8_T Gain_Gain_a;                 /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S18>/Gain'
                                        */
  boolean_T RateTransition5_X0;        /* Computed Parameter: RateTransition5_X0
                                        * Referenced by: '<S3>/Rate Transition5'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_FindTarget_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_FindTarget_T FindTarget_P;

/* Block signals (auto storage) */
extern B_FindTarget_T FindTarget_B;

/* Block states (auto storage) */
extern DW_FindTarget_T FindTarget_DW;

/* Constant parameters (auto storage) */
extern const ConstP_FindTarget_T FindTarget_ConstP;

/* Model entry point functions */
extern void FindTarget_initialize(void);
extern void FindTarget_output0(void);
extern void FindTarget_update0(void);
extern void FindTarget_output1(void);
extern void FindTarget_update1(void);
extern void FindTarget_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FindTarget_T *const FindTarget_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FindTarget'
 * '<S1>'   : 'FindTarget/Debounce Switch'
 * '<S2>'   : 'FindTarget/Finite State Machine'
 * '<S3>'   : 'FindTarget/Image Processing'
 * '<S4>'   : 'FindTarget/Outputs'
 * '<S5>'   : 'FindTarget/State estimator'
 * '<S6>'   : 'FindTarget/Debounce Switch/Compare To Constant'
 * '<S7>'   : 'FindTarget/Debounce Switch/Detect Increase'
 * '<S8>'   : 'FindTarget/Finite State Machine/DriveToTarget'
 * '<S9>'   : 'FindTarget/Finite State Machine/SearchForTarget'
 * '<S10>'  : 'FindTarget/Finite State Machine/DriveToTarget/Calculate Distance Error'
 * '<S11>'  : 'FindTarget/Finite State Machine/DriveToTarget/Calculate Heading Error'
 * '<S12>'  : 'FindTarget/Finite State Machine/DriveToTarget/Speed Control'
 * '<S13>'  : 'FindTarget/Finite State Machine/DriveToTarget/Steering Control'
 * '<S14>'  : 'FindTarget/Finite State Machine/DriveToTarget/Steering Control/Discrete Derivative'
 * '<S15>'  : 'FindTarget/Image Processing/Image processing'
 * '<S16>'  : 'FindTarget/Image Processing/Image processing/Compare To Zero'
 * '<S17>'  : 'FindTarget/Image Processing/Image processing/Detect Target'
 * '<S18>'  : 'FindTarget/Image Processing/Image processing/Overlay Points'
 * '<S19>'  : 'FindTarget/Image Processing/Image processing/Detect Target/Calculate Green Intensity'
 * '<S20>'  : 'FindTarget/Image Processing/Image processing/Detect Target/Compare To Threshold'
 * '<S21>'  : 'FindTarget/Outputs/Coulomb & Viscous Friction'
 * '<S22>'  : 'FindTarget/Outputs/Format Serial Message'
 * '<S23>'  : 'FindTarget/Outputs/Serial Write'
 * '<S24>'  : 'FindTarget/State estimator/Detect Change'
 * '<S25>'  : 'FindTarget/State estimator/Measurement Update'
 * '<S26>'  : 'FindTarget/State estimator/Time Update'
 */
#endif                                 /* RTW_HEADER_FindTarget_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
