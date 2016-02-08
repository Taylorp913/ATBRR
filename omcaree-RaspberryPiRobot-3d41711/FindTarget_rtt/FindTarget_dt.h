/*
 * FindTarget_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "FindTarget".
 *
 * Model version              : 1.92
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Mon Feb 01 21:55:27 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int16_T),
  sizeof(int32_T),
  sizeof(int16_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "int16_T",
  "int32_T",
  "int16_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&FindTarget_B.RateTransition4), 0, 0, 34 },

  { (char_T *)(&FindTarget_B.RateTransition[0]), 3, 0, 691200 },

  { (char_T *)(&FindTarget_B.RateTransition5), 8, 0, 76806 }
  ,

  { (char_T *)(&FindTarget_DW.DelayInput1_DSTATE), 0, 0, 21 },

  { (char_T *)(&FindTarget_DW.State_PWORK.LoggedData), 11, 0, 3 },

  { (char_T *)(&FindTarget_DW.spHandle), 6, 0, 3 },

  { (char_T *)(&FindTarget_DW.TappedDelay_X[0]), 8, 0, 4 },

  { (char_T *)(&FindTarget_DW.Stateestimator_SubsysRanBC), 2, 0, 5 },

  { (char_T *)(&FindTarget_DW.is_active_c7_FindTarget), 3, 0, 5 },

  { (char_T *)(&FindTarget_DW.RateTransition5_Buffer0), 8, 0, 5 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&FindTarget_P.DiscreteDerivative_ICPrevScaled), 0, 0, 4 },

  { (char_T *)(&FindTarget_P.BlobAnalysis_minArea), 7, 0, 1 },

  { (char_T *)(&FindTarget_P.DrawMarkers_size), 5, 0, 1 },

  { (char_T *)(&FindTarget_P.CompareToThreshold_const), 3, 0, 3 },

  { (char_T *)(&FindTarget_P.DetectIncrease_vinit), 8, 0, 1 },

  { (char_T *)(&FindTarget_P.SpeedGain_Gain), 0, 0, 63 },

  { (char_T *)(&FindTarget_P.Constant_Value_f), 6, 0, 2 },

  { (char_T *)(&FindTarget_P.DrawMarkers_RTP_FILLCOLOR[0]), 3, 0, 4 },

  { (char_T *)(&FindTarget_P.RateTransition5_X0), 8, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  9U,
  rtPTransitions
};

/* [EOF] FindTarget_dt.h */
