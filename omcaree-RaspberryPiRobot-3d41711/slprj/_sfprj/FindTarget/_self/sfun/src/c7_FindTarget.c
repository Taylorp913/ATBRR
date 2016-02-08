/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FindTarget_sfun.h"
#include "c7_FindTarget.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FindTarget_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c7_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c7_IN_Running                  ((uint8_T)1U)
#define c7_IN_Start                    ((uint8_T)2U)
#define c7_IN_Waiting                  ((uint8_T)3U)
#define c7_IN_Drive                    ((uint8_T)1U)
#define c7_IN_Nod                      ((uint8_T)2U)
#define c7_IN_Search                   ((uint8_T)3U)
#define c7_IN_Stop                     ((uint8_T)4U)
#define c7_IN_Down                     ((uint8_T)1U)
#define c7_IN_Up                       ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c7_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void c7_durationReferenceTimeUpdater(SFc7_FindTargetInstanceStruct
  *chartInstance);
static void initialize_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance);
static void initialize_params_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance);
static void enable_c7_FindTarget(SFc7_FindTargetInstanceStruct *chartInstance);
static void disable_c7_FindTarget(SFc7_FindTargetInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance);
static void ext_mode_exec_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c7_FindTarget(SFc7_FindTargetInstanceStruct *
  chartInstance);
static void set_sim_state_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_st);
static void c7_set_sim_state_side_effects_c7_FindTarget
  (SFc7_FindTargetInstanceStruct *chartInstance);
static void finalize_c7_FindTarget(SFc7_FindTargetInstanceStruct *chartInstance);
static void sf_gateway_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance);
static void mdl_start_c7_FindTarget(SFc7_FindTargetInstanceStruct *chartInstance);
static void initSimStructsc7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance);
static void c7_enter_atomic_Start(SFc7_FindTargetInstanceStruct *chartInstance);
static void c7_Running(SFc7_FindTargetInstanceStruct *chartInstance);
static void c7_exit_internal_Running(SFc7_FindTargetInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_FindTargetInstanceStruct *chartInstance,
  const mxArray *c7_nargout, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn(SFc7_FindTargetInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static boolean_T c7_c_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_d_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static uint8_T c7_e_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_b_is_Running, const char_T *c7_identifier);
static uint8_T c7_f_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_g_emlrt_marshallIn(SFc7_FindTargetInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3]);
static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_h_emlrt_marshallIn(SFc7_FindTargetInstanceStruct *chartInstance,
  const mxArray *c7_b_dataWrittenToVector, const char_T *c7_identifier,
  boolean_T c7_y[9]);
static void c7_i_emlrt_marshallIn(SFc7_FindTargetInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, boolean_T c7_y[9]);
static const mxArray *c7_j_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_b_setSimStateSideEffectsInfo, const char_T
  *c7_identifier);
static const mxArray *c7_k_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc7_FindTargetInstanceStruct
  *chartInstance, int32_T c7_ssid);
static void c7_init_sf_message_store_memory(SFc7_FindTargetInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc7_FindTargetInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc7_FindTargetInstanceStruct
  *chartInstance);

/* Function Definitions */
static void c7_durationReferenceTimeUpdater(SFc7_FindTargetInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc7_FindTarget(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  *chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_doSetSimStateSideEffects = 0U;
  chartInstance->c7_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c7_is_Running = c7_IN_NO_ACTIVE_CHILD;
  *chartInstance->c7_is_Nod = c7_IN_NO_ACTIVE_CHILD;
  *chartInstance->c7_temporalCounter_i1 = 0U;
  *chartInstance->c7_temporalCounter_i1 = 0U;
  *chartInstance->c7_temporalCounter_i1 = 0U;
  *chartInstance->c7_is_active_c7_FindTarget = 0U;
  *chartInstance->c7_is_c7_FindTarget = c7_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c7_FindTarget(SFc7_FindTargetInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "DriveToTarget", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "SearchForTarget", 0);
}

static void disable_c7_FindTarget(SFc7_FindTargetInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "DriveToTarget", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "SearchForTarget", 0);
}

static void c7_update_debugger_state_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance)
{
  uint32_T c7_prevAniVal;
  c7_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c7_is_active_c7_FindTarget == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 5U, *chartInstance->c7_sfEvent);
  }

  if (*chartInstance->c7_is_c7_FindTarget == c7_IN_Start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, *chartInstance->c7_sfEvent);
  }

  if (*chartInstance->c7_is_c7_FindTarget == c7_IN_Waiting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, *chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *chartInstance->c7_sfEvent);
  }

  if (*chartInstance->c7_is_c7_FindTarget == c7_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
  }

  if (*chartInstance->c7_is_Running == c7_IN_Search) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c7_sfEvent);
  }

  if (*chartInstance->c7_is_Running == c7_IN_Drive) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c7_sfEvent);
  }

  if (*chartInstance->c7_is_Running == c7_IN_Nod) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c7_sfEvent);
  }

  if (*chartInstance->c7_is_Nod == c7_IN_Up) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c7_sfEvent);
  }

  if (*chartInstance->c7_is_Nod == c7_IN_Down) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c7_sfEvent);
  }

  if (*chartInstance->c7_is_Running == c7_IN_Stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c7_sfEvent);
  }

  _SFD_SET_ANIMATION(c7_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance)
{
  c7_update_debugger_state_c7_FindTarget(chartInstance);
}

static const mxArray *get_sim_state_c7_FindTarget(SFc7_FindTargetInstanceStruct *
  chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_b_hoistedGlobal;
  real_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_c_hoistedGlobal;
  real_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  real_T c7_d_hoistedGlobal;
  real_T c7_d_u;
  const mxArray *c7_e_y = NULL;
  real_T c7_e_hoistedGlobal;
  real_T c7_e_u;
  const mxArray *c7_f_y = NULL;
  uint8_T c7_f_hoistedGlobal;
  uint8_T c7_f_u;
  const mxArray *c7_g_y = NULL;
  uint8_T c7_g_hoistedGlobal;
  uint8_T c7_g_u;
  const mxArray *c7_h_y = NULL;
  uint8_T c7_h_hoistedGlobal;
  uint8_T c7_h_u;
  const mxArray *c7_i_y = NULL;
  uint8_T c7_i_hoistedGlobal;
  uint8_T c7_i_u;
  const mxArray *c7_j_y = NULL;
  uint8_T c7_j_hoistedGlobal;
  uint8_T c7_j_u;
  const mxArray *c7_k_y = NULL;
  const mxArray *c7_l_y = NULL;
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(11, 1), false);
  c7_hoistedGlobal = *chartInstance->c7_CameraAzimuth;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = *chartInstance->c7_CameraElevation;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = *chartInstance->c7_MotorLeft;
  c7_c_u = c7_c_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = *chartInstance->c7_MotorRight;
  c7_d_u = c7_d_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  c7_e_hoistedGlobal = *chartInstance->c7_i;
  c7_e_u = c7_e_hoistedGlobal;
  c7_f_y = NULL;
  sf_mex_assign(&c7_f_y, sf_mex_create("y", &c7_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 4, c7_f_y);
  c7_f_hoistedGlobal = *chartInstance->c7_is_active_c7_FindTarget;
  c7_f_u = c7_f_hoistedGlobal;
  c7_g_y = NULL;
  sf_mex_assign(&c7_g_y, sf_mex_create("y", &c7_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 5, c7_g_y);
  c7_g_hoistedGlobal = *chartInstance->c7_is_c7_FindTarget;
  c7_g_u = c7_g_hoistedGlobal;
  c7_h_y = NULL;
  sf_mex_assign(&c7_h_y, sf_mex_create("y", &c7_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 6, c7_h_y);
  c7_h_hoistedGlobal = *chartInstance->c7_is_Running;
  c7_h_u = c7_h_hoistedGlobal;
  c7_i_y = NULL;
  sf_mex_assign(&c7_i_y, sf_mex_create("y", &c7_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 7, c7_i_y);
  c7_i_hoistedGlobal = *chartInstance->c7_is_Nod;
  c7_i_u = c7_i_hoistedGlobal;
  c7_j_y = NULL;
  sf_mex_assign(&c7_j_y, sf_mex_create("y", &c7_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 8, c7_j_y);
  c7_j_hoistedGlobal = *chartInstance->c7_temporalCounter_i1;
  c7_j_u = c7_j_hoistedGlobal;
  c7_k_y = NULL;
  sf_mex_assign(&c7_k_y, sf_mex_create("y", &c7_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 9, c7_k_y);
  c7_l_y = NULL;
  sf_mex_assign(&c7_l_y, sf_mex_create("y",
    chartInstance->c7_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 9), false);
  sf_mex_setcell(c7_y, 10, c7_l_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  boolean_T c7_bv0[9];
  int32_T c7_i0;
  c7_u = sf_mex_dup(c7_st);
  *chartInstance->c7_CameraAzimuth = c7_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("CameraAzimuth", c7_u, 0)), "CameraAzimuth");
  *chartInstance->c7_CameraElevation = c7_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("CameraElevation", c7_u, 1)), "CameraElevation");
  *chartInstance->c7_MotorLeft = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("MotorLeft", c7_u, 2)), "MotorLeft");
  *chartInstance->c7_MotorRight = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("MotorRight", c7_u, 3)), "MotorRight");
  *chartInstance->c7_i = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("i", c7_u, 4)), "i");
  *chartInstance->c7_is_active_c7_FindTarget = c7_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c7_FindTarget", c7_u, 5)),
     "is_active_c7_FindTarget");
  *chartInstance->c7_is_c7_FindTarget = c7_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c7_FindTarget", c7_u, 6)), "is_c7_FindTarget");
  *chartInstance->c7_is_Running = c7_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_Running", c7_u, 7)), "is_Running");
  *chartInstance->c7_is_Nod = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_Nod", c7_u, 8)), "is_Nod");
  *chartInstance->c7_temporalCounter_i1 = c7_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("temporalCounter_i1", c7_u, 9)),
    "temporalCounter_i1");
  c7_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c7_u, 10)), "dataWrittenToVector", c7_bv0);
  for (c7_i0 = 0; c7_i0 < 9; c7_i0++) {
    chartInstance->c7_dataWrittenToVector[c7_i0] = c7_bv0[c7_i0];
  }

  sf_mex_assign(&chartInstance->c7_setSimStateSideEffectsInfo,
                c7_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c7_u, 11)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c7_u);
  chartInstance->c7_doSetSimStateSideEffects = 1U;
  c7_update_debugger_state_c7_FindTarget(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void c7_set_sim_state_side_effects_c7_FindTarget
  (SFc7_FindTargetInstanceStruct *chartInstance)
{
  if (chartInstance->c7_doSetSimStateSideEffects != 0) {
    if (*chartInstance->c7_is_Nod == c7_IN_Down) {
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        *chartInstance->c7_temporalCounter_i1 = 0U;
      }
    }

    if (*chartInstance->c7_is_Nod == c7_IN_Up) {
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        *chartInstance->c7_temporalCounter_i1 = 0U;
      }
    }

    if (*chartInstance->c7_is_c7_FindTarget == c7_IN_Start) {
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        *chartInstance->c7_temporalCounter_i1 = 0U;
      }
    }

    chartInstance->c7_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c7_FindTarget(SFc7_FindTargetInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c7_setSimStateSideEffectsInfo);
}

static void sf_gateway_c7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance)
{
  int32_T c7_i1;
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 1.0;
  boolean_T c7_b_out;
  c7_set_sim_state_side_effects_c7_FindTarget(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  c7_durationReferenceTimeUpdater(chartInstance);
  if (*chartInstance->c7_temporalCounter_i1 < 31U) {
    (*chartInstance->c7_temporalCounter_i1)++;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, *chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_InitialAzimuth, 5U, 1U, 0U,
                        *chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_InitialElevation, 4U, 1U, 0U,
                        *chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c7_ButtonPressed, 3U, 1U, 0U,
                        *chartInstance->c7_sfEvent, false);
  for (c7_i1 = 0; c7_i1 < 3; c7_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c7_TargetPosition)[c7_i1], 2U, 1U, 0U,
                          *chartInstance->c7_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c7_TargetVisible, 1U, 1U, 0U,
                        *chartInstance->c7_sfEvent, false);
  *chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, *chartInstance->c7_sfEvent);
  if (*chartInstance->c7_is_active_c7_FindTarget == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 5U, *chartInstance->c7_sfEvent);
    *chartInstance->c7_is_active_c7_FindTarget = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c7_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c7_sfEvent);
    *chartInstance->c7_is_c7_FindTarget = c7_IN_Start;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *chartInstance->c7_sfEvent);
    *chartInstance->c7_temporalCounter_i1 = 0U;
    c7_enter_atomic_Start(chartInstance);
  } else {
    switch (*chartInstance->c7_is_c7_FindTarget) {
     case c7_IN_Running:
      CV_CHART_EVAL(5, 0, 1);
      c7_Running(chartInstance);
      break;

     case c7_IN_Start:
      CV_CHART_EVAL(5, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   *chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_u_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_out = CV_EML_IF(3, 0, 0, *chartInstance->c7_temporalCounter_i1 >= 30);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c7_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, *chartInstance->c7_sfEvent);
        *chartInstance->c7_is_c7_FindTarget = c7_IN_Waiting;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, *chartInstance->c7_sfEvent);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                     *chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, *chartInstance->c7_sfEvent);
      break;

     case c7_IN_Waiting:
      CV_CHART_EVAL(5, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   *chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_v_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_b_out = CV_EML_IF(5, 0, 0, *chartInstance->c7_ButtonPressed);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c7_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *chartInstance->c7_sfEvent);
        *chartInstance->c7_is_c7_FindTarget = c7_IN_Running;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
        *chartInstance->c7_is_Running = c7_IN_Search;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c7_sfEvent);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                     *chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, *chartInstance->c7_sfEvent);
      break;

     default:
      CV_CHART_EVAL(5, 0, 0);

      /* Unreachable state, for coverage only */
      *chartInstance->c7_is_c7_FindTarget = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FindTargetMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c7_FindTarget(SFc7_FindTargetInstanceStruct *chartInstance)
{
  c7_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc7_FindTarget(SFc7_FindTargetInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_enter_atomic_Start(SFc7_FindTargetInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 0.0;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  real_T c7_d_nargin = 0.0;
  real_T c7_d_nargout = 0.0;
  real_T c7_b_hoistedGlobal;
  real_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  *chartInstance->c7_MotorLeft = 0.0;
  chartInstance->c7_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_MotorLeft, 6U, 4U, 9U,
                        *chartInstance->c7_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_b_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  *chartInstance->c7_MotorRight = 0.0;
  chartInstance->c7_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_MotorRight, 7U, 4U, 9U,
                        *chartInstance->c7_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_c_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  *chartInstance->c7_CameraElevation = *chartInstance->c7_InitialElevation;
  chartInstance->c7_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_CameraElevation, 8U, 4U, 9U,
                        *chartInstance->c7_sfEvent, false);
  if (!chartInstance->c7_dataWrittenToVector[3U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 9U, *chartInstance->c7_sfEvent,
      false);
  }

  sf_mex_printf("%s =\\n", "CameraElevation");
  c7_hoistedGlobal = *chartInstance->c7_CameraElevation;
  c7_u = c7_hoistedGlobal;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_y);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_d_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargin, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargout, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  *chartInstance->c7_CameraAzimuth = *chartInstance->c7_InitialAzimuth;
  chartInstance->c7_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_CameraAzimuth, 9U, 4U, 9U,
                        *chartInstance->c7_sfEvent, false);
  if (!chartInstance->c7_dataWrittenToVector[4U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 9U, *chartInstance->c7_sfEvent,
      false);
  }

  sf_mex_printf("%s =\\n", "CameraAzimuth");
  c7_b_hoistedGlobal = *chartInstance->c7_CameraAzimuth;
  c7_b_u = c7_b_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_b_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_Running(SFc7_FindTargetInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 1.0;
  boolean_T c7_b_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 0.0;
  real_T c7_d_nargin = 0.0;
  real_T c7_d_nargout = 0.0;
  real_T c7_e_nargin = 0.0;
  real_T c7_e_nargout = 0.0;
  int32_T c7_i2;
  real_T c7_c_TargetPosition[3];
  int32_T c7_i3;
  real_T c7_d0;
  real_T c7_d1;
  int32_T c7_i4;
  int32_T c7_i5;
  real_T c7_d2;
  real_T c7_d3;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  real_T c7_b_hoistedGlobal;
  real_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_f_nargin = 0.0;
  real_T c7_f_nargout = 1.0;
  boolean_T c7_c_out;
  real_T c7_g_nargin = 0.0;
  real_T c7_g_nargout = 0.0;
  real_T c7_h_nargin = 0.0;
  real_T c7_h_nargout = 1.0;
  boolean_T c7_d_out;
  real_T c7_i_nargin = 0.0;
  real_T c7_i_nargout = 0.0;
  real_T c7_j_nargin = 0.0;
  real_T c7_j_nargout = 0.0;
  real_T c7_k_nargin = 0.0;
  real_T c7_k_nargout = 1.0;
  boolean_T c7_e_out;
  real_T c7_l_nargin = 0.0;
  real_T c7_l_nargout = 0.0;
  real_T c7_m_nargin = 0.0;
  real_T c7_m_nargout = 0.0;
  real_T c7_n_nargin = 0.0;
  real_T c7_n_nargout = 1.0;
  boolean_T c7_f_out;
  real_T c7_o_nargin = 0.0;
  real_T c7_o_nargout = 0.0;
  real_T c7_d4;
  real_T c7_d5;
  real_T c7_d6;
  real_T c7_d7;
  real_T c7_c_hoistedGlobal;
  real_T c7_c_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_d_hoistedGlobal;
  real_T c7_d_u;
  const mxArray *c7_d_y = NULL;
  real_T c7_p_nargin = 0.0;
  real_T c7_p_nargout = 0.0;
  real_T c7_q_nargin = 0.0;
  real_T c7_q_nargout = 0.0;
  real_T c7_r_nargin = 0.0;
  real_T c7_r_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, *chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_t_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  c7_out = CV_EML_IF(4, 0, 0, *chartInstance->c7_ButtonPressed);
  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c7_sfEvent);
    c7_exit_internal_Running(chartInstance);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
    *chartInstance->c7_is_c7_FindTarget = c7_IN_Start;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *chartInstance->c7_sfEvent);
    *chartInstance->c7_temporalCounter_i1 = 0U;
    c7_enter_atomic_Start(chartInstance);
    guard1 = true;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, *chartInstance->c7_sfEvent);
    switch (*chartInstance->c7_is_Running) {
     case c7_IN_Drive:
      CV_STATE_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   *chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_r_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_b_out = CV_EML_IF(2, 0, 0, CV_EML_MCDC(2, 0, 0, !CV_EML_COND(2, 0, 0,
        *chartInstance->c7_TargetVisible)));
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c7_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c7_sfEvent);
        *chartInstance->c7_is_Running = c7_IN_Stop;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c7_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_m_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_sf_marshallOut,
          c7_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U,
          c7_sf_marshallOut, c7_sf_marshallIn);
        *chartInstance->c7_MotorLeft = 0.0;
        chartInstance->c7_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c7_MotorLeft, 6U, 4U, 7U,
                              *chartInstance->c7_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_n_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargin, 0U, c7_sf_marshallOut,
          c7_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargout, 1U,
          c7_sf_marshallOut, c7_sf_marshallIn);
        *chartInstance->c7_MotorRight = 0.0;
        chartInstance->c7_dataWrittenToVector[1U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c7_MotorRight, 7U, 4U, 7U,
                              *chartInstance->c7_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     *chartInstance->c7_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_f_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargin, 0U, c7_sf_marshallOut,
          c7_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargout, 1U,
          c7_sf_marshallOut, c7_sf_marshallIn);
        for (c7_i2 = 0; c7_i2 < 3; c7_i2++) {
          c7_c_TargetPosition[c7_i2] = (*chartInstance->c7_TargetPosition)[c7_i2];
        }

        for (c7_i3 = 0; c7_i3 < 3; c7_i3++) {
          _SFD_DATA_RANGE_CHECK(c7_c_TargetPosition[c7_i3], 10U, 4U, 0U,
                                *chartInstance->c7_sfEvent, false);
        }

        _SFD_SET_DATA_VALUE_PTR(13U, &c7_d0);
        _SFD_SET_DATA_VALUE_PTR(11U, &c7_d1);
        _SFD_SET_DATA_VALUE_PTR(10U, c7_c_TargetPosition);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 0U, *chartInstance->c7_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(3U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("TargetPosition", c7_c_TargetPosition,
          c7_e_sf_marshallOut, c7_e_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("MotorLeft", &c7_d1, c7_sf_marshallOut,
          c7_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("MotorRight", &c7_d0, c7_sf_marshallOut,
          c7_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     *chartInstance->c7_sfEvent);
        for (c7_i4 = 0; c7_i4 < 3; c7_i4++) {
          (*chartInstance->c7_b_TargetPosition)[c7_i4] =
            c7_c_TargetPosition[c7_i4];
        }

        for (c7_i5 = 0; c7_i5 < 3; c7_i5++) {
          _SFD_DATA_RANGE_CHECK((*chartInstance->c7_b_TargetPosition)[c7_i5],
                                10U, 4U, 0U, *chartInstance->c7_sfEvent, false);
        }

        sf_call_output_fcn_call(chartInstance->S, 0, "DriveToTarget", 0);
        c7_d1 = *chartInstance->c7_b_MotorLeft;
        chartInstance->c7_dataWrittenToVector[5U] = true;
        _SFD_DATA_RANGE_CHECK(c7_d1, 11U, 4U, 0U, *chartInstance->c7_sfEvent,
                              false);
        c7_d0 = *chartInstance->c7_b_MotorRight;
        chartInstance->c7_dataWrittenToVector[6U] = true;
        _SFD_DATA_RANGE_CHECK(c7_d0, 13U, 4U, 0U, *chartInstance->c7_sfEvent,
                              false);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 0U, *chartInstance->c7_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(13U);
        _SFD_UNSET_DATA_VALUE_PTR(11U);
        _SFD_UNSET_DATA_VALUE_PTR(10U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c7_sfEvent);
        c7_d2 = c7_d1;
        c7_d3 = c7_d0;
        *chartInstance->c7_MotorLeft = c7_d2;
        chartInstance->c7_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c7_MotorLeft, 6U, 4U, 2U,
                              *chartInstance->c7_sfEvent, false);
        *chartInstance->c7_MotorRight = c7_d3;
        chartInstance->c7_dataWrittenToVector[1U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c7_MotorRight, 7U, 4U, 2U,
                              *chartInstance->c7_sfEvent, false);
        if (!chartInstance->c7_dataWrittenToVector[0U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 2U,
            *chartInstance->c7_sfEvent, false);
        }

        sf_mex_printf("%s =\\n", "MotorLeft");
        c7_hoistedGlobal = *chartInstance->c7_MotorLeft;
        c7_u = c7_hoistedGlobal;
        c7_y = NULL;
        sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_y);
        if (!chartInstance->c7_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U,
            *chartInstance->c7_sfEvent, false);
        }

        sf_mex_printf("%s =\\n", "MotorRight");
        c7_b_hoistedGlobal = *chartInstance->c7_MotorRight;
        c7_b_u = c7_b_hoistedGlobal;
        c7_b_y = NULL;
        sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c7_b_y);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c7_sfEvent);
      guard1 = true;
      break;

     case c7_IN_Nod:
      CV_STATE_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                   *chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_s_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      if (!chartInstance->c7_dataWrittenToVector[2U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 5U, 9U, *chartInstance->c7_sfEvent,
          false);
      }

      c7_c_out = CV_EML_IF(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0,
        *chartInstance->c7_i, 10.0, -1, 4U, *chartInstance->c7_i > 10.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, *chartInstance->c7_sfEvent);
        switch (*chartInstance->c7_is_Nod) {
         case c7_IN_Down:
          CV_STATE_EVAL(3, 1, 1);
          *chartInstance->c7_is_Nod = c7_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c7_sfEvent);
          break;

         case c7_IN_Up:
          CV_STATE_EVAL(3, 1, 2);
          *chartInstance->c7_is_Nod = c7_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c7_sfEvent);
          break;

         default:
          CV_STATE_EVAL(3, 1, 0);
          *chartInstance->c7_is_Nod = c7_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c7_sfEvent);
          break;
        }

        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 3U,
                     *chartInstance->c7_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_h_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_g_nargin, 0U, c7_sf_marshallOut,
          c7_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_g_nargout, 1U,
          c7_sf_marshallOut, c7_sf_marshallIn);
        *chartInstance->c7_CameraElevation = 0.0;
        chartInstance->c7_dataWrittenToVector[3U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c7_CameraElevation, 8U, 4U, 3U,
                              *chartInstance->c7_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c7_sfEvent);
        *chartInstance->c7_is_Running = c7_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c7_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
        *chartInstance->c7_is_c7_FindTarget = c7_IN_Start;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *chartInstance->c7_sfEvent);
        *chartInstance->c7_temporalCounter_i1 = 0U;
        c7_enter_atomic_Start(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     *chartInstance->c7_sfEvent);
        switch (*chartInstance->c7_is_Nod) {
         case c7_IN_Down:
          CV_STATE_EVAL(3, 0, 1);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                       *chartInstance->c7_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_p_debug_family_names,
            c7_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_h_nargin, 0U,
            c7_sf_marshallOut, c7_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_h_nargout, 1U,
            c7_sf_marshallOut, c7_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_out, 2U,
            c7_b_sf_marshallOut, c7_b_sf_marshallIn);
          c7_d_out = CV_EML_IF(6, 0, 0, *chartInstance->c7_temporalCounter_i1 >=
                               6);
          _SFD_SYMBOL_SCOPE_POP();
          if (c7_d_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c7_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c7_sfEvent);
            *chartInstance->c7_is_Nod = c7_IN_Up;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c7_sfEvent);
            *chartInstance->c7_temporalCounter_i1 = 0U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_i_debug_family_names,
              c7_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_i_nargin, 0U,
              c7_sf_marshallOut, c7_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_i_nargout, 1U,
              c7_sf_marshallOut, c7_sf_marshallIn);
            *chartInstance->c7_CameraElevation = 10.0;
            chartInstance->c7_dataWrittenToVector[3U] = true;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c7_CameraElevation, 8U, 4U, 5U,
                                  *chartInstance->c7_sfEvent, false);
            _SFD_SYMBOL_SCOPE_POP();
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_j_debug_family_names,
              c7_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_j_nargin, 0U,
              c7_sf_marshallOut, c7_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_j_nargout, 1U,
              c7_sf_marshallOut, c7_sf_marshallIn);
            if (!chartInstance->c7_dataWrittenToVector[2U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U,
                *chartInstance->c7_sfEvent, false);
            }

            (*chartInstance->c7_i)++;
            chartInstance->c7_dataWrittenToVector[2U] = true;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c7_i, 0U, 4U, 5U,
                                  *chartInstance->c7_sfEvent, false);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                         *chartInstance->c7_sfEvent);
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c7_sfEvent);
          break;

         case c7_IN_Up:
          CV_STATE_EVAL(3, 0, 2);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                       *chartInstance->c7_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_o_debug_family_names,
            c7_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_k_nargin, 0U,
            c7_sf_marshallOut, c7_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_k_nargout, 1U,
            c7_sf_marshallOut, c7_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_out, 2U,
            c7_b_sf_marshallOut, c7_b_sf_marshallIn);
          c7_e_out = CV_EML_IF(8, 0, 0, *chartInstance->c7_temporalCounter_i1 >=
                               6);
          _SFD_SYMBOL_SCOPE_POP();
          if (c7_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *chartInstance->c7_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c7_sfEvent);
            *chartInstance->c7_is_Nod = c7_IN_Down;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c7_sfEvent);
            *chartInstance->c7_temporalCounter_i1 = 0U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_k_debug_family_names,
              c7_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_l_nargin, 0U,
              c7_sf_marshallOut, c7_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_l_nargout, 1U,
              c7_sf_marshallOut, c7_sf_marshallIn);
            *chartInstance->c7_CameraElevation = -30.0;
            chartInstance->c7_dataWrittenToVector[3U] = true;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c7_CameraElevation, 8U, 4U, 4U,
                                  *chartInstance->c7_sfEvent, false);
            _SFD_SYMBOL_SCOPE_POP();
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_l_debug_family_names,
              c7_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_m_nargin, 0U,
              c7_sf_marshallOut, c7_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_m_nargout, 1U,
              c7_sf_marshallOut, c7_sf_marshallIn);
            if (!chartInstance->c7_dataWrittenToVector[2U]) {
              _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 4U,
                *chartInstance->c7_sfEvent, false);
            }

            (*chartInstance->c7_i)++;
            chartInstance->c7_dataWrittenToVector[2U] = true;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c7_i, 0U, 4U, 4U,
                                  *chartInstance->c7_sfEvent, false);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                         *chartInstance->c7_sfEvent);
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c7_sfEvent);
          break;

         default:
          CV_STATE_EVAL(3, 0, 0);

          /* Unreachable state, for coverage only */
          *chartInstance->c7_is_Nod = c7_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c7_sfEvent);
          break;
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c7_sfEvent);
      if (*chartInstance->c7_is_c7_FindTarget != c7_IN_Running) {
      } else {
        guard1 = true;
      }
      break;

     case c7_IN_Search:
      CV_STATE_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   *chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_q_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_n_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_n_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_f_out = CV_EML_IF(1, 0, 0, *chartInstance->c7_TargetVisible);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c7_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c7_sfEvent);
        *chartInstance->c7_is_Running = c7_IN_Drive;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c7_sfEvent);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     *chartInstance->c7_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_e_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_o_nargin, 0U, c7_sf_marshallOut,
          c7_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_o_nargout, 1U,
          c7_sf_marshallOut, c7_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(14U, &c7_d4);
        _SFD_SET_DATA_VALUE_PTR(12U, &c7_d5);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, *chartInstance->c7_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(2U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("MotorLeft", &c7_d5, c7_sf_marshallOut,
          c7_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("MotorRight", &c7_d4, c7_sf_marshallOut,
          c7_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     *chartInstance->c7_sfEvent);
        sf_call_output_fcn_call(chartInstance->S, 1, "SearchForTarget", 0);
        c7_d5 = *chartInstance->c7_c_MotorLeft;
        chartInstance->c7_dataWrittenToVector[7U] = true;
        _SFD_DATA_RANGE_CHECK(c7_d5, 12U, 4U, 8U, *chartInstance->c7_sfEvent,
                              false);
        c7_d4 = *chartInstance->c7_c_MotorRight;
        chartInstance->c7_dataWrittenToVector[8U] = true;
        _SFD_DATA_RANGE_CHECK(c7_d4, 14U, 4U, 8U, *chartInstance->c7_sfEvent,
                              false);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, *chartInstance->c7_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(14U);
        _SFD_UNSET_DATA_VALUE_PTR(12U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, *chartInstance->c7_sfEvent);
        c7_d6 = c7_d5;
        c7_d7 = c7_d4;
        *chartInstance->c7_MotorLeft = c7_d6;
        chartInstance->c7_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c7_MotorLeft, 6U, 4U, 6U,
                              *chartInstance->c7_sfEvent, false);
        *chartInstance->c7_MotorRight = c7_d7;
        chartInstance->c7_dataWrittenToVector[1U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c7_MotorRight, 7U, 4U, 6U,
                              *chartInstance->c7_sfEvent, false);
        if (!chartInstance->c7_dataWrittenToVector[0U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 6U,
            *chartInstance->c7_sfEvent, false);
        }

        sf_mex_printf("%s =\\n", "MotorLeft");
        c7_c_hoistedGlobal = *chartInstance->c7_MotorLeft;
        c7_c_u = c7_c_hoistedGlobal;
        c7_c_y = NULL;
        sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c7_c_y);
        if (!chartInstance->c7_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 6U,
            *chartInstance->c7_sfEvent, false);
        }

        sf_mex_printf("%s =\\n", "MotorRight");
        c7_d_hoistedGlobal = *chartInstance->c7_MotorRight;
        c7_d_u = c7_d_hoistedGlobal;
        c7_d_y = NULL;
        sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_d_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c7_d_y);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c7_sfEvent);
      guard1 = true;
      break;

     case c7_IN_Stop:
      CV_STATE_EVAL(1, 0, 4);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c7_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c7_sfEvent);
      *chartInstance->c7_is_Running = c7_IN_Nod;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_g_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_p_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_p_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      *chartInstance->c7_i = 0.0;
      chartInstance->c7_dataWrittenToVector[2U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c7_i, 0U, 4U, 3U,
                            *chartInstance->c7_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      *chartInstance->c7_is_Nod = c7_IN_Up;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c7_sfEvent);
      *chartInstance->c7_temporalCounter_i1 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_i_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_q_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_q_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      *chartInstance->c7_CameraElevation = 10.0;
      chartInstance->c7_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c7_CameraElevation, 8U, 4U, 5U,
                            *chartInstance->c7_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_j_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_r_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_r_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      if (!chartInstance->c7_dataWrittenToVector[2U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 5U, *chartInstance->c7_sfEvent,
          false);
      }

      (*chartInstance->c7_i)++;
      chartInstance->c7_dataWrittenToVector[2U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c7_i, 0U, 4U, 5U,
                            *chartInstance->c7_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *chartInstance->c7_sfEvent);
      guard1 = true;
      break;

     default:
      CV_STATE_EVAL(1, 0, 0);

      /* Unreachable state, for coverage only */
      *chartInstance->c7_is_Running = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c7_sfEvent);
      guard1 = true;
      break;
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c7_sfEvent);
  }
}

static void c7_exit_internal_Running(SFc7_FindTargetInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  switch (*chartInstance->c7_is_Running) {
   case c7_IN_Drive:
    CV_STATE_EVAL(1, 1, 1);
    *chartInstance->c7_is_Running = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c7_sfEvent);
    break;

   case c7_IN_Nod:
    CV_STATE_EVAL(1, 1, 2);
    switch (*chartInstance->c7_is_Nod) {
     case c7_IN_Down:
      CV_STATE_EVAL(3, 1, 1);
      *chartInstance->c7_is_Nod = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c7_sfEvent);
      break;

     case c7_IN_Up:
      CV_STATE_EVAL(3, 1, 2);
      *chartInstance->c7_is_Nod = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c7_sfEvent);
      break;

     default:
      CV_STATE_EVAL(3, 1, 0);
      *chartInstance->c7_is_Nod = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c7_sfEvent);
      break;
    }

    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 3U, *chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_h_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    *chartInstance->c7_CameraElevation = 0.0;
    chartInstance->c7_dataWrittenToVector[3U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c7_CameraElevation, 8U, 4U, 3U,
                          *chartInstance->c7_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c7_sfEvent);
    *chartInstance->c7_is_Running = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c7_sfEvent);
    break;

   case c7_IN_Search:
    CV_STATE_EVAL(1, 1, 3);
    *chartInstance->c7_is_Running = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c7_sfEvent);
    break;

   case c7_IN_Stop:
    CV_STATE_EVAL(1, 1, 4);
    *chartInstance->c7_is_Running = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c7_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    *chartInstance->c7_is_Running = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c7_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  (void)c7_chartNumber;
  (void)c7_instanceNumber;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_FindTargetInstanceStruct *chartInstance;
  chartInstance = (SFc7_FindTargetInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_FindTargetInstanceStruct *chartInstance,
  const mxArray *c7_nargout, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn(SFc7_FindTargetInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d8;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d8, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d8;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_FindTargetInstanceStruct *chartInstance;
  chartInstance = (SFc7_FindTargetInstanceStruct *)chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  boolean_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_FindTargetInstanceStruct *chartInstance;
  chartInstance = (SFc7_FindTargetInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(boolean_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static boolean_T c7_c_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  boolean_T c7_y;
  boolean_T c7_b0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_b0, 1, 11, 0U, 0, 0U, 0);
  c7_y = c7_b0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_sf_internal_predicateOutput;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  boolean_T c7_y;
  SFc7_FindTargetInstanceStruct *chartInstance;
  chartInstance = (SFc7_FindTargetInstanceStruct *)chartInstanceVoid;
  c7_sf_internal_predicateOutput = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_sf_internal_predicateOutput), &c7_thisId);
  sf_mex_destroy(&c7_sf_internal_predicateOutput);
  *(boolean_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_FindTarget_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c7_nameCaptureInfo;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_FindTargetInstanceStruct *chartInstance;
  chartInstance = (SFc7_FindTargetInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_d_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i6;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i6, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i6;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_FindTargetInstanceStruct *chartInstance;
  chartInstance = (SFc7_FindTargetInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  uint8_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_FindTargetInstanceStruct *chartInstance;
  chartInstance = (SFc7_FindTargetInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(uint8_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_b_is_Running, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_is_Running),
    &c7_thisId);
  sf_mex_destroy(&c7_b_is_Running);
  return c7_y;
}

static uint8_T c7_f_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_is_Running;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  uint8_T c7_y;
  SFc7_FindTargetInstanceStruct *chartInstance;
  chartInstance = (SFc7_FindTargetInstanceStruct *)chartInstanceVoid;
  c7_b_is_Running = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_is_Running),
    &c7_thisId);
  sf_mex_destroy(&c7_b_is_Running);
  *(uint8_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i7;
  real_T c7_u[3];
  const mxArray *c7_y = NULL;
  SFc7_FindTargetInstanceStruct *chartInstance;
  chartInstance = (SFc7_FindTargetInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i7 = 0; c7_i7 < 3; c7_i7++) {
    c7_u[c7_i7] = (*(real_T (*)[3])c7_inData)[c7_i7];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static void c7_g_emlrt_marshallIn(SFc7_FindTargetInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3])
{
  real_T c7_dv0[3];
  int32_T c7_i8;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c7_i8 = 0; c7_i8 < 3; c7_i8++) {
    c7_y[c7_i8] = c7_dv0[c7_i8];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_c_TargetPosition;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[3];
  int32_T c7_i9;
  SFc7_FindTargetInstanceStruct *chartInstance;
  chartInstance = (SFc7_FindTargetInstanceStruct *)chartInstanceVoid;
  c7_c_TargetPosition = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_c_TargetPosition),
                        &c7_thisId, c7_y);
  sf_mex_destroy(&c7_c_TargetPosition);
  for (c7_i9 = 0; c7_i9 < 3; c7_i9++) {
    (*(real_T (*)[3])c7_outData)[c7_i9] = c7_y[c7_i9];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static void c7_h_emlrt_marshallIn(SFc7_FindTargetInstanceStruct *chartInstance,
  const mxArray *c7_b_dataWrittenToVector, const char_T *c7_identifier,
  boolean_T c7_y[9])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_dataWrittenToVector),
                        &c7_thisId, c7_y);
  sf_mex_destroy(&c7_b_dataWrittenToVector);
}

static void c7_i_emlrt_marshallIn(SFc7_FindTargetInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, boolean_T c7_y[9])
{
  boolean_T c7_bv1[9];
  int32_T c7_i10;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_bv1, 1, 11, 0U, 1, 0U, 1, 9);
  for (c7_i10 = 0; c7_i10 < 9; c7_i10++) {
    c7_y[c7_i10] = c7_bv1[c7_i10];
  }

  sf_mex_destroy(&c7_u);
}

static const mxArray *c7_j_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_b_setSimStateSideEffectsInfo, const char_T
  *c7_identifier)
{
  const mxArray *c7_y = NULL;
  emlrtMsgIdentifier c7_thisId;
  c7_y = NULL;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  sf_mex_assign(&c7_y, c7_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_setSimStateSideEffectsInfo), &c7_thisId), false);
  sf_mex_destroy(&c7_b_setSimStateSideEffectsInfo);
  return c7_y;
}

static const mxArray *c7_k_emlrt_marshallIn(SFc7_FindTargetInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  const mxArray *c7_y = NULL;
  (void)chartInstance;
  (void)c7_parentId;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_duplicatearraysafe(&c7_u), false);
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc7_FindTargetInstanceStruct
  *chartInstance, int32_T c7_ssid)
{
  (void)chartInstance;
  (void)c7_ssid;
  return NULL;
}

static void c7_init_sf_message_store_memory(SFc7_FindTargetInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc7_FindTargetInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc7_FindTargetInstanceStruct
  *chartInstance)
{
  chartInstance->c7_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c7_isStable = (boolean_T *)ssGetDWork_wrapper(chartInstance->S,
    1);
  chartInstance->c7_is_active_c7_FindTarget = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 2);
  chartInstance->c7_is_c7_FindTarget = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c7_is_Running = (uint8_T *)ssGetDWork_wrapper(chartInstance->S,
    4);
  chartInstance->c7_is_Nod = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c7_TargetVisible = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c7_TargetPosition = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_MotorLeft = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_MotorRight = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c7_ButtonPressed = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c7_i = (real_T *)ssGetDWork_wrapper(chartInstance->S, 6);
  chartInstance->c7_InitialElevation = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c7_InitialAzimuth = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c7_CameraElevation = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c7_CameraAzimuth = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c7_b_MotorLeft = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c7_b_MotorRight = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c7_b_TargetPosition = (real_T (*)[3])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 5);
  chartInstance->c7_c_MotorLeft = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c7_c_MotorRight = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c7_temporalCounter_i1 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 7);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static uint32_T* sf_get_sfun_dwork_checksum(void);
void sf_c7_FindTarget_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1479382363U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1319445898U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4018715019U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(610685683U);
}

mxArray* sf_c7_FindTarget_get_post_codegen_info(void);
mxArray *sf_c7_FindTarget_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("klm6SbjBz7W5uUt8TpnViC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c7_FindTarget_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_FindTarget_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_FindTarget_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("ext_mode");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c7_FindTarget_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c7_FindTarget_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c7_FindTarget(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[110],T\"CameraAzimuth\",},{M[1],M[109],T\"CameraElevation\",},{M[1],M[29],T\"MotorLeft\",},{M[1],M[30],T\"MotorRight\",},{M[3],M[91],T\"i\",},{M[8],M[0],T\"is_active_c7_FindTarget\",},{M[9],M[0],T\"is_c7_FindTarget\",},{M[9],M[61],T\"is_Running\",},{M[9],M[101],T\"is_Nod\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x3[102 105 33],M[1]}}}}",
    "100 S'type','srcId','name','auxInfo'{{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_FindTarget_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc7_FindTargetInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_FindTargetInstanceStruct *chartInstance =
      (SFc7_FindTargetInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FindTargetMachineNumber_,
           7,
           11,
           10,
           0,
           15,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_FindTargetMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_FindTargetMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _FindTargetMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"i");
          _SFD_SET_DATA_PROPS(1,1,1,0,"TargetVisible");
          _SFD_SET_DATA_PROPS(2,1,1,0,"TargetPosition");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ButtonPressed");
          _SFD_SET_DATA_PROPS(4,1,1,0,"InitialElevation");
          _SFD_SET_DATA_PROPS(5,1,1,0,"InitialAzimuth");
          _SFD_SET_DATA_PROPS(6,2,0,1,"MotorLeft");
          _SFD_SET_DATA_PROPS(7,2,0,1,"MotorRight");
          _SFD_SET_DATA_PROPS(8,2,0,1,"CameraElevation");
          _SFD_SET_DATA_PROPS(9,2,0,1,"CameraAzimuth");
          _SFD_SET_DATA_PROPS(10,8,0,0,"");
          _SFD_SET_DATA_PROPS(11,9,0,0,"");
          _SFD_SET_DATA_PROPS(12,9,0,0,"");
          _SFD_SET_DATA_PROPS(13,9,0,0,"");
          _SFD_SET_DATA_PROPS(14,9,0,0,"");
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,1);
          _SFD_CH_SUBSTATE_INDEX(1,9);
          _SFD_CH_SUBSTATE_INDEX(2,10);
          _SFD_ST_SUBSTATE_COUNT(1,4);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_INDEX(1,2,6);
          _SFD_ST_SUBSTATE_INDEX(1,3,7);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,2);
          _SFD_ST_SUBSTATE_INDEX(3,0,4);
          _SFD_ST_SUBSTATE_INDEX(3,1,5);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(1,4,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,15,0,15);
        _SFD_CV_INIT_EML(6,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,0,15,0,15);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,1,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,15,1,15);

        {
          static int condStart[] = { 2 };

          static int condEnd[] = { 15 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,15,1,0,&(condStart[0]),&(condEnd[0]),2,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(9,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,5,1,5);
        _SFD_CV_INIT_EML_RELATIONAL(9,0,0,1,5,-1,4);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(5,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,14,1,14);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_e_sf_marshallOut,(MexInFcnForType)
            c7_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(11,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(12,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(13,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(14,(void *)(NULL));
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _FindTargetMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_FindTargetInstanceStruct *chartInstance =
      (SFc7_FindTargetInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c7_TargetVisible);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c7_TargetPosition);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c7_MotorLeft);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c7_MotorRight);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c7_ButtonPressed);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c7_i);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c7_InitialElevation);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c7_InitialAzimuth);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c7_CameraElevation);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c7_CameraAzimuth);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "suBL1NjZPth1tl9hTarCHtE";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_FindTarget_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 7, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c7_FindTarget(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc7_FindTargetInstanceStruct*) chartInstanceVar
    )->S);
  chart_debug_initialization(((SFc7_FindTargetInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c7_FindTarget((SFc7_FindTargetInstanceStruct*)
    chartInstanceVar);
  initialize_c7_FindTarget((SFc7_FindTargetInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_FindTarget(void *chartInstanceVar)
{
  enable_c7_FindTarget((SFc7_FindTargetInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_FindTarget(void *chartInstanceVar)
{
  disable_c7_FindTarget((SFc7_FindTargetInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_FindTarget(void *chartInstanceVar)
{
  sf_gateway_c7_FindTarget((SFc7_FindTargetInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c7_FindTarget(void *chartInstanceVar)
{
  ext_mode_exec_c7_FindTarget((SFc7_FindTargetInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c7_FindTarget(SimStruct* S)
{
  return get_sim_state_c7_FindTarget((SFc7_FindTargetInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_FindTarget(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c7_FindTarget((SFc7_FindTargetInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c7_FindTarget(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_FindTargetInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FindTarget_optimization_info();
    }

    finalize_c7_FindTarget((SFc7_FindTargetInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_FindTarget((SFc7_FindTargetInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_FindTarget(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_FindTarget((SFc7_FindTargetInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

mxArray *sf_c7_FindTarget_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S1x4'varName','path'{{T\"is_active_c7_FindTarget\",T\"is_active_c7_FindTarget\"},{T\"is_c7_FindTarget\",T\"is_c7_FindTarget\"},{T\"is_Running\",T\"Running.is_Running\"},{T\"is_Nod\",T\"Running.Nod.is_Nod\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x8'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id'{{T\"int32\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"boolean\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 8, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 4238265890U, 286370175U, 2977145005U,
    2887494898U };

  return checksum;
}

static void mdlSetWorkWidths_c7_FindTarget(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FindTarget_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 7);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,7);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,7,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 9; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(370871287U));
  ssSetChecksum1(S,(2021139373U));
  ssSetChecksum2(S,(3871736130U));
  ssSetChecksum3(S,(3120229978U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_FindTarget(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c7_FindTarget(SimStruct *S)
{
  SFc7_FindTargetInstanceStruct *chartInstance;
  chartInstance = (SFc7_FindTargetInstanceStruct *)utMalloc(sizeof
    (SFc7_FindTargetInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc7_FindTargetInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_FindTarget;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_FindTarget;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_FindTarget;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_FindTarget;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_FindTarget;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_FindTarget;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_FindTarget;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c7_FindTarget;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_FindTarget;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_FindTarget;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_FindTarget;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c7_FindTarget;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c7_FindTarget(chartInstance);
}

void c7_FindTarget_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_FindTarget(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_FindTarget(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_FindTarget(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_FindTarget_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
