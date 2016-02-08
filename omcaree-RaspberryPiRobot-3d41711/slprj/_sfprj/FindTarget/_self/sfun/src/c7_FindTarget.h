#ifndef __c7_FindTarget_h__
#define __c7_FindTarget_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_FindTargetInstanceStruct
#define typedef_SFc7_FindTargetInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c7_dataWrittenToVector[9];
  uint8_T c7_doSetSimStateSideEffects;
  const mxArray *c7_setSimStateSideEffectsInfo;
  int32_T *c7_sfEvent;
  boolean_T *c7_isStable;
  uint8_T *c7_is_active_c7_FindTarget;
  uint8_T *c7_is_c7_FindTarget;
  uint8_T *c7_is_Running;
  uint8_T *c7_is_Nod;
  boolean_T *c7_TargetVisible;
  real_T (*c7_TargetPosition)[3];
  real_T *c7_MotorLeft;
  real_T *c7_MotorRight;
  boolean_T *c7_ButtonPressed;
  real_T *c7_i;
  real_T *c7_InitialElevation;
  real_T *c7_InitialAzimuth;
  real_T *c7_CameraElevation;
  real_T *c7_CameraAzimuth;
  real_T *c7_b_MotorLeft;
  real_T *c7_b_MotorRight;
  real_T (*c7_b_TargetPosition)[3];
  real_T *c7_c_MotorLeft;
  real_T *c7_c_MotorRight;
  uint8_T *c7_temporalCounter_i1;
} SFc7_FindTargetInstanceStruct;

#endif                                 /*typedef_SFc7_FindTargetInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_FindTarget_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_FindTarget_get_check_sum(mxArray *plhs[]);
extern void c7_FindTarget_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
