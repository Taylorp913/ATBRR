  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (FindTarget_P)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% FindTarget_P.DiscreteDerivative_ICPrevScaled
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_P.CoulombViscousFriction_gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FindTarget_P.CoulombViscousFriction_offset
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FindTarget_P.DetectChange_vinit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% FindTarget_P.BlobAnalysis_minArea
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% FindTarget_P.DrawMarkers_size
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% FindTarget_P.CompareToThreshold_const
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_P.CompareToConstant_const
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FindTarget_P.TappedDelay_vinit
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% FindTarget_P.DetectIncrease_vinit
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 48;
      section.data(48)  = dumData; %prealloc
      
	  ;% FindTarget_P.SpeedGain_Gain
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_P.Saturation3_UpperSat
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FindTarget_P.Saturation3_LowerSat
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FindTarget_P.D_Gain
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FindTarget_P.TSamp_WtEt
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FindTarget_P.P_Gain
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 5;
	
	  ;% FindTarget_P.Saturation2_UpperSat
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 6;
	
	  ;% FindTarget_P.Saturation2_LowerSat
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 7;
	
	  ;% FindTarget_P.Gain3_Gain
	  section.data(9).logicalSrcIdx = 18;
	  section.data(9).dtTransOffset = 8;
	
	  ;% FindTarget_P.Saturation2_UpperSat_f
	  section.data(10).logicalSrcIdx = 19;
	  section.data(10).dtTransOffset = 9;
	
	  ;% FindTarget_P.Saturation2_LowerSat_e
	  section.data(11).logicalSrcIdx = 20;
	  section.data(11).dtTransOffset = 10;
	
	  ;% FindTarget_P.Gain4_Gain
	  section.data(12).logicalSrcIdx = 21;
	  section.data(12).dtTransOffset = 11;
	
	  ;% FindTarget_P.Saturation1_UpperSat
	  section.data(13).logicalSrcIdx = 22;
	  section.data(13).dtTransOffset = 12;
	
	  ;% FindTarget_P.Saturation1_LowerSat
	  section.data(14).logicalSrcIdx = 23;
	  section.data(14).dtTransOffset = 13;
	
	  ;% FindTarget_P.PulseGenerator_Amp
	  section.data(15).logicalSrcIdx = 24;
	  section.data(15).dtTransOffset = 14;
	
	  ;% FindTarget_P.PulseGenerator_Period
	  section.data(16).logicalSrcIdx = 25;
	  section.data(16).dtTransOffset = 15;
	
	  ;% FindTarget_P.PulseGenerator_Duty
	  section.data(17).logicalSrcIdx = 26;
	  section.data(17).dtTransOffset = 16;
	
	  ;% FindTarget_P.PulseGenerator_PhaseDelay
	  section.data(18).logicalSrcIdx = 27;
	  section.data(18).dtTransOffset = 17;
	
	  ;% FindTarget_P.Gain1_Gain
	  section.data(19).logicalSrcIdx = 28;
	  section.data(19).dtTransOffset = 18;
	
	  ;% FindTarget_P.Gain4_Gain_f
	  section.data(20).logicalSrcIdx = 29;
	  section.data(20).dtTransOffset = 19;
	
	  ;% FindTarget_P.Tilt1_Value
	  section.data(21).logicalSrcIdx = 30;
	  section.data(21).dtTransOffset = 20;
	
	  ;% FindTarget_P.SubtractImageCentre_Bias
	  section.data(22).logicalSrcIdx = 31;
	  section.data(22).dtTransOffset = 22;
	
	  ;% FindTarget_P.Convertpixelstodegrees_Gain
	  section.data(23).logicalSrcIdx = 32;
	  section.data(23).dtTransOffset = 24;
	
	  ;% FindTarget_P.Constant_Value
	  section.data(24).logicalSrcIdx = 33;
	  section.data(24).dtTransOffset = 25;
	
	  ;% FindTarget_P.DiscreteTimeIntegrator_gainval
	  section.data(25).logicalSrcIdx = 34;
	  section.data(25).dtTransOffset = 26;
	
	  ;% FindTarget_P.DiscreteTimeIntegrator_IC
	  section.data(26).logicalSrcIdx = 35;
	  section.data(26).dtTransOffset = 27;
	
	  ;% FindTarget_P.UnitDelay1_InitialCondition
	  section.data(27).logicalSrcIdx = 36;
	  section.data(27).dtTransOffset = 28;
	
	  ;% FindTarget_P.UnitDelay2_InitialCondition
	  section.data(28).logicalSrcIdx = 37;
	  section.data(28).dtTransOffset = 31;
	
	  ;% FindTarget_P.Power2m_Gain
	  section.data(29).logicalSrcIdx = 38;
	  section.data(29).dtTransOffset = 33;
	
	  ;% FindTarget_P.UnitDelay_InitialCondition
	  section.data(30).logicalSrcIdx = 39;
	  section.data(30).dtTransOffset = 34;
	
	  ;% FindTarget_P.r2d_Gain
	  section.data(31).logicalSrcIdx = 40;
	  section.data(31).dtTransOffset = 43;
	
	  ;% FindTarget_P.RateTransition4_X0
	  section.data(32).logicalSrcIdx = 41;
	  section.data(32).dtTransOffset = 44;
	
	  ;% FindTarget_P.RateTransition6_X0
	  section.data(33).logicalSrcIdx = 42;
	  section.data(33).dtTransOffset = 45;
	
	  ;% FindTarget_P.TiltAngle_Value
	  section.data(34).logicalSrcIdx = 43;
	  section.data(34).dtTransOffset = 46;
	
	  ;% FindTarget_P.PanAngle_Value
	  section.data(35).logicalSrcIdx = 44;
	  section.data(35).dtTransOffset = 47;
	
	  ;% FindTarget_P.Saturation3_UpperSat_o
	  section.data(36).logicalSrcIdx = 45;
	  section.data(36).dtTransOffset = 48;
	
	  ;% FindTarget_P.Saturation3_LowerSat_o
	  section.data(37).logicalSrcIdx = 46;
	  section.data(37).dtTransOffset = 49;
	
	  ;% FindTarget_P.Gain_Gain
	  section.data(38).logicalSrcIdx = 47;
	  section.data(38).dtTransOffset = 50;
	
	  ;% FindTarget_P.Bias_Bias
	  section.data(39).logicalSrcIdx = 48;
	  section.data(39).dtTransOffset = 51;
	
	  ;% FindTarget_P.Saturation_UpperSat
	  section.data(40).logicalSrcIdx = 49;
	  section.data(40).dtTransOffset = 52;
	
	  ;% FindTarget_P.Saturation_LowerSat
	  section.data(41).logicalSrcIdx = 50;
	  section.data(41).dtTransOffset = 53;
	
	  ;% FindTarget_P.Bias2_Bias
	  section.data(42).logicalSrcIdx = 51;
	  section.data(42).dtTransOffset = 54;
	
	  ;% FindTarget_P.Saturation1_UpperSat_f
	  section.data(43).logicalSrcIdx = 52;
	  section.data(43).dtTransOffset = 55;
	
	  ;% FindTarget_P.Saturation1_LowerSat_c
	  section.data(44).logicalSrcIdx = 53;
	  section.data(44).dtTransOffset = 56;
	
	  ;% FindTarget_P.Bias1_Bias
	  section.data(45).logicalSrcIdx = 54;
	  section.data(45).dtTransOffset = 57;
	
	  ;% FindTarget_P.Gain1_Gain_c
	  section.data(46).logicalSrcIdx = 55;
	  section.data(46).dtTransOffset = 58;
	
	  ;% FindTarget_P.IC1_Value
	  section.data(47).logicalSrcIdx = 56;
	  section.data(47).dtTransOffset = 59;
	
	  ;% FindTarget_P.Bias1_Bias_j
	  section.data(48).logicalSrcIdx = 57;
	  section.data(48).dtTransOffset = 61;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FindTarget_P.Constant_Value_f
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_P.Switch_Threshold
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FindTarget_P.DrawMarkers_RTP_FILLCOLOR
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_P.Gain_Gain_a
	  section.data(2).logicalSrcIdx = 61;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% FindTarget_P.RateTransition5_X0
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (FindTarget_B)
    ;%
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% FindTarget_B.RateTransition4
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_B.RateTransition6
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FindTarget_B.TiltAngle
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% FindTarget_B.PanAngle
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% FindTarget_B.Bias1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% FindTarget_B.Xout
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% FindTarget_B.Pout
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% FindTarget_B.DiscreteTimeIntegrator
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 19;
	
	  ;% FindTarget_B.Switch
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 20;
	
	  ;% FindTarget_B.MotorLeft
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 22;
	
	  ;% FindTarget_B.MotorRight
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 23;
	
	  ;% FindTarget_B.CameraElevation
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 24;
	
	  ;% FindTarget_B.CameraAzimuth
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 25;
	
	  ;% FindTarget_B.TargetPosition
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 26;
	
	  ;% FindTarget_B.Gain1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 29;
	
	  ;% FindTarget_B.Gain4
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 30;
	
	  ;% FindTarget_B.Saturation2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 31;
	
	  ;% FindTarget_B.Saturation2_f
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 32;
	
	  ;% FindTarget_B.Saturation1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 33;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% FindTarget_B.RateTransition
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_B.RateTransition1
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 76800;
	
	  ;% FindTarget_B.RateTransition2
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 153600;
	
	  ;% FindTarget_B.MatrixConcatenate2
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 230400;
	
	  ;% FindTarget_B.MatrixConcatenate1
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 384000;
	
	  ;% FindTarget_B.MatrixConcatenate
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 537600;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% FindTarget_B.RateTransition5
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_B.Compare
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FindTarget_B.FixPtRelationalOperator
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FindTarget_B.GPIORead
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FindTarget_B.status
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FindTarget_B.Compare_i
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 5;
	
	  ;% FindTarget_B.Compare_d
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (FindTarget_DW)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% FindTarget_DW.DelayInput1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_DW.UnitDelay1_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FindTarget_DW.UnitDelay2_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% FindTarget_DW.UnitDelay_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% FindTarget_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 15;
	
	  ;% FindTarget_DW.UD_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 16;
	
	  ;% FindTarget_DW.RateTransition4_Buffer0
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 17;
	
	  ;% FindTarget_DW.RateTransition6_Buffer0
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 18;
	
	  ;% FindTarget_DW.i
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% FindTarget_DW.State_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_DW.MotorCommands_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FindTarget_DW.Scope_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% FindTarget_DW.spHandle
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_DW.sfEvent
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FindTarget_DW.clockTickCounter
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FindTarget_DW.TappedDelay_X
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_DW.DelayInput1_DSTATE_n
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% FindTarget_DW.Stateestimator_SubsysRanBC
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_DW.Imageprocessing_SubsysRanBC
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FindTarget_DW.DiscreteTimeIntegrator_PrevRese
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FindTarget_DW.DriveToTarget_SubsysRanBC
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FindTarget_DW.SearchForTarget_SubsysRanBC
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% FindTarget_DW.is_active_c7_FindTarget
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_DW.is_c7_FindTarget
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FindTarget_DW.is_Running
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FindTarget_DW.is_Nod
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FindTarget_DW.temporalCounter_i1
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% FindTarget_DW.RateTransition5_Buffer0
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FindTarget_DW.IC1_FirstOutputTime
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FindTarget_DW.spHandle_not_empty
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FindTarget_DW.isStable
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FindTarget_DW.Stateestimator_MODE
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2115789970;
  targMap.checksum1 = 3551251627;
  targMap.checksum2 = 1570916689;
  targMap.checksum3 = 2970150352;

