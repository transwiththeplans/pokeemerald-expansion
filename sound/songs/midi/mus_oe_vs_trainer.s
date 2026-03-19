	.include "MPlayDef.s"

	.equ	mus_oe_vs_trainer_grp, voicegroup_vs_frontier_brain
	.equ	mus_oe_vs_trainer_pri, 1
	.equ	mus_oe_vs_trainer_rev, reverb_set+50
	.equ	mus_oe_vs_trainer_mvl, 100
	.equ	mus_oe_vs_trainer_key, 0
	.equ	mus_oe_vs_trainer_tbs, 1
	.equ	mus_oe_vs_trainer_exg, 1
	.equ	mus_oe_vs_trainer_cmp, 1

	.section .rodata
	.global	mus_oe_vs_trainer
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_oe_vs_trainer_1:
	.byte	KEYSH , mus_oe_vs_trainer_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 144*mus_oe_vs_trainer_tbs/2
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		VOL   , 112*mus_oe_vs_trainer_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W84
	.byte		N12   , Gs3 , v112
	.byte	W12
mus_oe_vs_trainer_1_B1:
@ 002   ----------------------------------------
mus_oe_vs_trainer_1_002:
	.byte		N12   , As3 , v116
	.byte	W12
	.byte		N06   , As3 , v096
	.byte	W12
	.byte		N12   , Cs4 , v116
	.byte	W12
	.byte		N06   , Fs3 , v096
	.byte	W12
	.byte		N12   , Gs3 , v116
	.byte	W12
	.byte		N06   , Gs3 , v096
	.byte	W12
	.byte		N12   , As3 , v116
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte		N12   , Fs3 , v116
	.byte	W12
	.byte		N06   , Fs3 , v096
	.byte	W12
	.byte		N12   , Gs3 , v116
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W12
	.byte		N12   , Ds3 , v116
	.byte	W36
	.byte		        Gs3 , v112
	.byte	W12
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_1_002
@ 005   ----------------------------------------
	.byte		N12   , Fs3 , v116
	.byte	W12
	.byte		N06   , Fs3 , v096
	.byte	W12
	.byte		N12   , Gs3 , v116
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W12
	.byte		N12   , Ds3 , v116
	.byte	W12
	.byte		        Cs3 , v096
	.byte	W24
	.byte		        Gs3 , v112
	.byte	W12
@ 006   ----------------------------------------
	.byte		        As3 , v116
	.byte	W12
	.byte		N06   , Cs4 , v096
	.byte	W12
	.byte		N12   , Cs4 , v116
	.byte	W12
	.byte		N06   , As3 , v096
	.byte	W10
	.byte		N01   , Cs4 , v084
	.byte	W02
	.byte		N12   , Ds4 , v116
	.byte	W12
	.byte		N09   , Cs4 , v096
	.byte	W12
	.byte		N12   , As3 , v116
	.byte	W12
	.byte		N09   , Fs3 , v096
	.byte	W12
@ 007   ----------------------------------------
	.byte		N12   , Gs3 , v116
	.byte	W12
	.byte		        As3 , v096
	.byte	W12
	.byte		        Gs3 , v116
	.byte	W12
	.byte		        Fs3 , v096
	.byte	W12
	.byte		        Ds3 , v116
	.byte	W12
	.byte		        Cs3 , v096
	.byte	W12
	.byte		N18   , Ds3 , v116
	.byte	W24
@ 008   ----------------------------------------
	.byte		        Ds3 , v112
	.byte	W96
@ 009   ----------------------------------------
	.byte	W72
	.byte		VOICE , 48
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W12
@ 010   ----------------------------------------
mus_oe_vs_trainer_1_010:
	.byte		N12   , As3 , v116
	.byte	W12
	.byte		N09   , As3 , v096
	.byte	W12
	.byte		N12   , Cs4 , v116
	.byte	W12
	.byte		N09   , Fs3 , v096
	.byte	W12
	.byte		N12   , Gs3 , v116
	.byte	W12
	.byte		N09   , Gs3 , v096
	.byte	W12
	.byte		N12   , As3 , v116
	.byte	W12
	.byte		N09   , Ds3 , v096
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
	.byte		N12   , Fs3 , v116
	.byte	W12
	.byte		N09   , Fs3 , v096
	.byte	W12
	.byte		N12   , Gs3 , v116
	.byte	W12
	.byte		N09   , Ds3 , v096
	.byte	W12
	.byte		N12   , Ds3 , v116
	.byte	W36
	.byte		        Gs3 , v112
	.byte	W12
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_1_010
@ 013   ----------------------------------------
	.byte		N12   , Fs3 , v116
	.byte	W12
	.byte		N09   , Fs3 , v096
	.byte	W12
	.byte		N12   , Gs3 , v116
	.byte	W12
	.byte		N09   , Ds3 , v096
	.byte	W12
	.byte		N12   , Ds3 , v116
	.byte	W12
	.byte		        Cs3 , v096
	.byte	W24
	.byte		VOICE , 56
	.byte		VOL   , 127*mus_oe_vs_trainer_mvl/mxv
	.byte		N12   , Gs3 , v127
	.byte	W12
@ 014   ----------------------------------------
	.byte		        As3 
	.byte	W12
	.byte		N06   , Cs4 , v112
	.byte	W12
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		N06   , As3 , v112
	.byte	W10
	.byte		N01   , Cs4 , v096
	.byte	W02
	.byte		N12   , Ds4 , v127
	.byte	W12
	.byte		N09   , Cs4 , v112
	.byte	W12
	.byte		N12   , As3 , v127
	.byte	W12
	.byte		N09   , Fs3 , v112
	.byte	W12
@ 015   ----------------------------------------
	.byte		N12   , Gs3 , v127
	.byte	W12
	.byte		        As3 , v112
	.byte	W12
	.byte		        Gs3 , v127
	.byte	W12
	.byte		        Fs3 , v112
	.byte	W12
	.byte		        Ds3 , v127
	.byte	W12
	.byte		        Cs3 , v112
	.byte	W12
	.byte		N18   , Ds3 , v127
	.byte	W24
@ 016   ----------------------------------------
	.byte		N18   
	.byte	W48
	.byte		VOICE , 48
	.byte		VOL   , 112*mus_oe_vs_trainer_mvl/mxv
	.byte		N48   , Gs2 , v036
	.byte	W48
@ 017   ----------------------------------------
	.byte		        Cs3 , v052
	.byte	W48
	.byte		N24   , Fs3 , v072
	.byte	W24
	.byte		N03   , Bn3 , v064
	.byte	W03
	.byte		        Cs4 , v068
	.byte	W03
	.byte		        Ds4 , v072
	.byte	W03
	.byte		        Fn4 , v076
	.byte	W03
	.byte		        Fs4 , v084
	.byte	W03
	.byte		        Gs4 , v088
	.byte	W03
	.byte		        As4 , v092
	.byte	W03
	.byte		        Bn4 , v100
	.byte	W03
@ 018   ----------------------------------------
	.byte		N24   , Cs5 , v104
	.byte	W24
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N18   , Fs4 
	.byte	W12
@ 019   ----------------------------------------
mus_oe_vs_trainer_1_019:
	.byte	W12
	.byte		N18   , Fs4 , v104
	.byte	W24
	.byte		N24   
	.byte	W48
	.byte		N36   , Cs5 
	.byte	W12
	.byte	PEND
@ 020   ----------------------------------------
	.byte	W24
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N18   , Fs4 
	.byte	W12
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_1_019
@ 022   ----------------------------------------
	.byte	W24
	.byte		N12   , Bn4 , v104
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N18   
	.byte	W12
@ 023   ----------------------------------------
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N18   
	.byte	W48
	.byte		N10   , Cs4 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N10   
	.byte	W12
	.byte		N09   , Cs4 , v092
	.byte	W12
	.byte		N10   , Cs4 , v104
	.byte	W12
	.byte		N09   , Cs4 , v092
	.byte	W12
	.byte		N10   , Cs4 , v104
	.byte	W12
	.byte		N09   , Cs4 , v092
	.byte	W12
	.byte		N10   , Cs4 , v104
	.byte	W12
	.byte		N09   , Cs4 , v092
	.byte	W12
@ 025   ----------------------------------------
	.byte		N10   , Cn4 , v104
	.byte	W12
	.byte		N09   , Cn4 , v092
	.byte	W24
	.byte		N36   , Cs4 , v104
	.byte	W36
	.byte		VOICE , 56
	.byte		N24   , As3 , v127
	.byte	W24
@ 026   ----------------------------------------
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N15   , Ds3 , v124
	.byte	W84
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W72
	.byte		N24   , Ds4 
	.byte	W24
@ 030   ----------------------------------------
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N15   , Ds4 , v112
	.byte	W84
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W72
	.byte		VOICE , 48
	.byte	W24
@ 033   ----------------------------------------
	.byte		N06   , As3 , v100
	.byte	W06
	.byte		        Gs3 , v080
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 , v100
	.byte	W06
	.byte		        Gs3 , v080
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs3 , v100
	.byte	W06
	.byte		N15   , Ds3 
	.byte	W54
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W72
	.byte		VOICE , 17
	.byte	W12
	.byte		N11   , Gs3 , v112
	.byte	W12
	.byte	GOTO
	 .word	mus_oe_vs_trainer_1_B1
mus_oe_vs_trainer_1_B2:
@ 042   ----------------------------------------
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		VOL   , 112*mus_oe_vs_trainer_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_oe_vs_trainer_2:
	.byte	KEYSH , mus_oe_vs_trainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_trainer_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Ds2 , v052
	.byte	W96
@ 001   ----------------------------------------
	.byte		VOICE , 30
	.byte		N12   , As2 , v088
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
mus_oe_vs_trainer_2_B1:
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W72
	.byte		VOICE , 17
	.byte	W24
@ 008   ----------------------------------------
	.byte		N48   , Ds4 , v056
	.byte	W48
	.byte		        As4 
	.byte	W48
@ 009   ----------------------------------------
	.byte		        Gs4 
	.byte	W48
	.byte		        Cs5 
	.byte	W48
@ 010   ----------------------------------------
mus_oe_vs_trainer_2_010:
	.byte		N12   , Fs4 , v064
	.byte	W12
	.byte		        Fs4 , v056
	.byte	W24
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 , v064
	.byte	W12
	.byte		        Ds4 , v056
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
	.byte		        Cs4 , v064
	.byte	W12
	.byte		        Cs4 , v056
	.byte	W12
	.byte		        Gs4 , v064
	.byte	W12
	.byte		        Gs4 , v056
	.byte	W12
	.byte		        Fs4 , v064
	.byte	W48
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_2_010
@ 013   ----------------------------------------
	.byte		N12   , Cs4 , v064
	.byte	W12
	.byte		        Cs4 , v056
	.byte	W12
	.byte		        Gs4 , v064
	.byte	W12
	.byte		        Gs4 , v056
	.byte	W12
	.byte		        Fs4 , v064
	.byte	W12
	.byte		        As4 , v056
	.byte	W12
	.byte		N06   , Gs4 , v064
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
@ 014   ----------------------------------------
	.byte		VOICE , 60
	.byte		N12   , Cs3 , v060
	.byte	W12
	.byte		N06   , Ds3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N09   , Fn3 
	.byte	W12
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N09   , Cs3 
	.byte	W12
@ 015   ----------------------------------------
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N21   , Cs3 
	.byte	W24
@ 016   ----------------------------------------
	.byte		VOICE , 48
	.byte		N48   , As2 , v048
	.byte	W48
	.byte		        Cs3 , v056
	.byte	W48
@ 017   ----------------------------------------
	.byte		        Fs3 , v068
	.byte	W48
	.byte		        As3 , v072
	.byte	W48
@ 018   ----------------------------------------
	.byte		N24   , Fs3 , v084
	.byte	W24
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N18   , Cs3 
	.byte	W12
@ 019   ----------------------------------------
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N24   
	.byte	W48
	.byte		N32   , Fs3 , v084, gtp2
	.byte	W12
@ 020   ----------------------------------------
	.byte	W24
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N18   , Cs3 
	.byte	W12
@ 021   ----------------------------------------
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N24   
	.byte	W48
	.byte		N36   , En3 
	.byte	W12
@ 022   ----------------------------------------
	.byte	W24
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N18   , Bn2 
	.byte	W12
@ 023   ----------------------------------------
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N18   
	.byte	W48
	.byte	W01
	.byte		N10   , Cs3 
	.byte	W11
@ 024   ----------------------------------------
	.byte		        En3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N09   
	.byte	W12
@ 025   ----------------------------------------
	.byte		N10   , Ds3 
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N36   , Cs3 
	.byte	W60
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W24
	.byte		N09   , Ds4 , v096
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		N18   , Fs3 , v084
	.byte	W18
	.byte		N09   , Ds3 
	.byte	W12
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		N18   , Ds3 , v072
	.byte	W18
	.byte		N12   , Cs3 
	.byte	W12
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte		TIE   , Ds1 , v052
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 036   ----------------------------------------
	.byte		TIE   
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 038   ----------------------------------------
	.byte		N12   , As1 , v096
	.byte	W12
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N12   , As1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		N36   , Cs2 
	.byte	W36
@ 039   ----------------------------------------
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
@ 040   ----------------------------------------
	.byte		        Fs1 
	.byte	W12
	.byte		N84   , Ds1 , v084
	.byte	W84
@ 041   ----------------------------------------
	.byte	W96
	.byte	GOTO
	 .word	mus_oe_vs_trainer_2_B1
mus_oe_vs_trainer_2_B2:
@ 042   ----------------------------------------
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_trainer_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

mus_oe_vs_trainer_3:
	.byte	KEYSH , mus_oe_vs_trainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_trainer_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Ds1 , v068
	.byte	W96
@ 001   ----------------------------------------
	.byte		VOICE , 33
	.byte		N12   , As0 , v108
	.byte	W24
	.byte		        As0 , v084
	.byte	W24
	.byte		N06   , As1 , v092
	.byte	W06
	.byte		        As1 , v076
	.byte	W06
	.byte		        As1 , v080
	.byte	W06
	.byte		        As1 , v084
	.byte	W06
	.byte		        As1 , v088
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        As1 , v092
	.byte	W06
	.byte		        As1 , v096
	.byte	W06
mus_oe_vs_trainer_3_B1:
@ 002   ----------------------------------------
mus_oe_vs_trainer_3_002:
	.byte		N12   , Ds1 , v100
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N12   , Fs0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N12   , Bn0 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
mus_oe_vs_trainer_3_003:
	.byte		N12   , Cs1 , v100
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N12   , Fs0 
	.byte	W12
	.byte		N09   
	.byte	W48
	.byte	PEND
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_002
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_003
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_003
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_002
@ 009   ----------------------------------------
	.byte		N12   , Cs1 , v100
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N12   , Fs0 
	.byte	W12
	.byte		N09   
	.byte	W36
	.byte		N12   , Cs1 
	.byte	W12
@ 010   ----------------------------------------
mus_oe_vs_trainer_3_010:
	.byte		N12   , Ds1 , v100
	.byte	W12
	.byte		N09   
	.byte	W18
	.byte		N06   , Fs1 , v072
	.byte	W06
	.byte		N12   , Fs0 , v100
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N03   , Gs0 , v084
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn0 , v100
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
	.byte		        Cs1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N03   , Fs1 , v084
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , Fs0 , v100
	.byte	W12
	.byte		N09   
	.byte	W48
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_010
@ 013   ----------------------------------------
	.byte		N12   , Cs1 , v100
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N03   , Fs1 , v084
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , Fs0 , v100
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   , Gs0 , v088
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		N12   , Gs0 , v100
	.byte	W12
	.byte		        Fs0 
	.byte	W12
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_010
@ 015   ----------------------------------------
	.byte		N12   , Cs1 , v100
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N03   , Fs1 , v084
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , Fs0 , v100
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N03   , As0 , v084
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_010
@ 017   ----------------------------------------
	.byte		N12   , Cs1 , v100
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N03   , Fs1 , v084
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , Fs0 , v100
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N12   , Fs0 , v088
	.byte	W12
	.byte		        Gs0 , v092
	.byte	W12
	.byte		        As0 , v096
	.byte	W12
@ 018   ----------------------------------------
mus_oe_vs_trainer_3_018:
	.byte		N12   , Bn0 , v100
	.byte	W12
	.byte		        Bn0 , v088
	.byte	W12
	.byte		        Bn0 , v100
	.byte	W12
	.byte		        Bn0 , v088
	.byte	W12
	.byte		        Bn0 , v100
	.byte	W12
	.byte		        Bn0 , v088
	.byte	W12
	.byte		        Bn0 , v100
	.byte	W12
	.byte		        Bn0 , v088
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_018
@ 020   ----------------------------------------
	.byte		N12   , Fs0 , v100
	.byte	W12
	.byte		        Fs0 , v088
	.byte	W12
	.byte		        Fs0 , v100
	.byte	W12
	.byte		        Fs0 , v088
	.byte	W12
	.byte		        Fs0 , v100
	.byte	W12
	.byte		        Fs0 , v088
	.byte	W12
	.byte		        Fs0 , v100
	.byte	W12
	.byte		        Fs0 , v088
	.byte	W12
@ 021   ----------------------------------------
	.byte		        Fs0 , v100
	.byte	W12
	.byte		        Fs0 , v088
	.byte	W12
	.byte		        Fs0 , v100
	.byte	W12
	.byte		        Fs0 , v088
	.byte	W12
	.byte		        Fs0 , v100
	.byte	W12
	.byte		        Fs0 , v088
	.byte	W12
	.byte		        Gs0 , v100
	.byte	W12
	.byte		        An0 , v088
	.byte	W12
@ 022   ----------------------------------------
mus_oe_vs_trainer_3_022:
	.byte		N12   , An0 , v100
	.byte	W12
	.byte		        An0 , v088
	.byte	W12
	.byte		        An0 , v100
	.byte	W12
	.byte		        An0 , v088
	.byte	W12
	.byte		        An0 , v100
	.byte	W12
	.byte		        An0 , v088
	.byte	W12
	.byte		        An0 , v100
	.byte	W12
	.byte		        An0 , v088
	.byte	W12
	.byte	PEND
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_022
@ 024   ----------------------------------------
	.byte		N12   , An0 , v100
	.byte	W12
	.byte		        En0 , v088
	.byte	W12
	.byte		        An0 , v100
	.byte	W12
	.byte		        En0 , v088
	.byte	W12
	.byte		        An0 , v100
	.byte	W12
	.byte		        En0 , v088
	.byte	W12
	.byte		        An0 , v100
	.byte	W12
	.byte		        En0 , v088
	.byte	W12
@ 025   ----------------------------------------
	.byte		        Gs0 , v100
	.byte	W12
	.byte		        Gs0 , v088
	.byte	W24
	.byte		        Cs0 , v100
	.byte	W60
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_002
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_003
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_002
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_003
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_002
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_003
@ 032   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_002
@ 033   ----------------------------------------
	.byte		N06   , As1 , v072
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N15   , Ds1 
	.byte	W42
	.byte		N12   , Cs1 , v100
	.byte	W12
@ 034   ----------------------------------------
mus_oe_vs_trainer_3_034:
	.byte		N12   , Ds1 , v100
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	PEND
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_034
@ 037   ----------------------------------------
	.byte	W48
	.byte		N06   , Gs1 , v084
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N09   , Cs1 
	.byte	W12
	.byte		N12   , Cs1 , v100
	.byte	W12
	.byte		N12   
	.byte	W12
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_002
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_003
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_3_002
@ 041   ----------------------------------------
	.byte		N12   , As0 , v100
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   , As1 , v092
	.byte	W06
	.byte		        As1 , v076
	.byte	W06
	.byte		        As1 , v080
	.byte	W06
	.byte		        As1 , v084
	.byte	W06
	.byte		        As1 , v088
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        As1 , v092
	.byte	W06
	.byte		N05   , As1 , v096
	.byte	W06
	.byte	GOTO
	 .word	mus_oe_vs_trainer_3_B1
mus_oe_vs_trainer_3_B2:
@ 042   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_trainer_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

mus_oe_vs_trainer_4:
	.byte	KEYSH , mus_oe_vs_trainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 85
	.byte		VOL   , 100*mus_oe_vs_trainer_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Fs3 , v088
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds3 , v096
	.byte	W06
	.byte		        Fs3 , v088
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds3 , v096
	.byte	W06
	.byte		        Fs3 , v088
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn3 , v096
	.byte	W06
	.byte		        Fn3 , v084
	.byte	W06
	.byte		        An3 , v080
	.byte	W06
	.byte		        Cs3 , v092
	.byte	W06
	.byte		        Fn3 , v076
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn3 , v088
	.byte	W06
@ 001   ----------------------------------------
	.byte		        Ds3 , v072
	.byte	W06
	.byte		        Gn3 , v068
	.byte	W06
	.byte		        Bn2 , v084
	.byte	W06
	.byte		        Dn3 , v064
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As2 , v080
	.byte	W06
	.byte		        Cs3 , v060
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , As3 , v036
	.byte	W06
	.byte		        As3 , v048
	.byte	W06
	.byte		        As3 , v060
	.byte	W06
	.byte		        As3 , v072
	.byte	W06
	.byte		        As4 , v084
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W03
	.byte		        Dn4 , v076
	.byte	W03
	.byte		        As3 , v072
	.byte	W03
	.byte		        Fn3 , v068
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        As2 , v064
	.byte	W03
	.byte		        Fn2 , v060
	.byte	W03
mus_oe_vs_trainer_4_B1:
@ 002   ----------------------------------------
mus_oe_vs_trainer_4_002:
	.byte		N18   , Fs3 , v088
	.byte	W24
	.byte		N18   
	.byte	W72
	.byte	PEND
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_002
@ 005   ----------------------------------------
mus_oe_vs_trainer_4_005:
	.byte	W92
	.byte	W01
	.byte		N01   , Fs4 , v068
	.byte	W01
	.byte		        Gs4 , v076
	.byte	W02
	.byte	PEND
@ 006   ----------------------------------------
	.byte		N18   , As4 , v080
	.byte	W24
	.byte		N18   
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N15   , Fs3 , v052
	.byte	W18
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N10   , Cs3 
	.byte	W12
	.byte		N06   , Ds3 
	.byte	W12
@ 007   ----------------------------------------
	.byte		        Fs3 
	.byte	W12
	.byte		        Ds3 , v044
	.byte	W06
	.byte		        Gs3 , v052
	.byte	W12
	.byte		        Cs3 , v044
	.byte	W06
	.byte		N09   , Ds3 , v052
	.byte	W12
	.byte		N06   
	.byte	W44
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Fs4 , v060
	.byte	W01
	.byte		        Gs4 , v076
	.byte	W02
@ 008   ----------------------------------------
	.byte		N18   , As4 , v080
	.byte	W24
	.byte		N18   
	.byte	W48
	.byte		PAN   , c_v+63
	.byte		N18   , Ds2 , v068
	.byte	W24
@ 009   ----------------------------------------
	.byte		N18   
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N18   , Ds1 , v076
	.byte	W24
	.byte		N18   
	.byte	W24
	.byte		N12   , Cs3 , v064
	.byte	W12
	.byte		N09   , Ds3 , v068
	.byte	W12
@ 010   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		N10   , Ds1 , v072
	.byte	W12
	.byte		N09   , Ds1 , v056
	.byte	W12
	.byte		N10   , Ds1 , v072
	.byte	W12
	.byte		N09   , Fs1 , v056
	.byte	W12
	.byte		N10   , Gs1 , v072
	.byte	W12
	.byte		N09   , Gs1 , v056
	.byte	W12
	.byte		N10   , Gs1 , v072
	.byte	W12
	.byte		N09   , As1 , v056
	.byte	W12
@ 011   ----------------------------------------
mus_oe_vs_trainer_4_011:
	.byte		N10   , Cs2 , v072
	.byte	W12
	.byte		N09   , Cs2 , v056
	.byte	W12
	.byte		N10   , Cs2 , v072
	.byte	W12
	.byte		N09   , Fs1 , v056
	.byte	W12
	.byte		N12   , Fs1 , v072
	.byte	W48
	.byte	PEND
@ 012   ----------------------------------------
mus_oe_vs_trainer_4_012:
	.byte		N10   , Ds1 , v072
	.byte	W12
	.byte		N09   , Ds1 , v056
	.byte	W12
	.byte		N10   , Ds1 , v072
	.byte	W12
	.byte		N09   , Fs1 , v056
	.byte	W12
	.byte		N10   , Gs1 , v072
	.byte	W12
	.byte		N09   , Gs1 , v056
	.byte	W12
	.byte		N10   , Gs1 , v072
	.byte	W12
	.byte		N09   , As1 , v056
	.byte	W12
	.byte	PEND
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_011
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_012
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_011
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_012
@ 017   ----------------------------------------
	.byte		N10   , Cs2 , v072
	.byte	W12
	.byte		N09   , Cs2 , v056
	.byte	W12
	.byte		N10   , Cs2 , v072
	.byte	W12
	.byte		N09   , Fs1 , v056
	.byte	W12
	.byte		N12   , Fs1 , v072
	.byte	W12
	.byte		N09   , Gs1 , v056
	.byte	W12
	.byte		N12   , As1 , v072
	.byte	W12
	.byte		N09   , Bn1 , v056
	.byte	W12
@ 018   ----------------------------------------
	.byte		VOICE , 80
	.byte		N03   , Fs4 , v064
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
@ 019   ----------------------------------------
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
@ 020   ----------------------------------------
mus_oe_vs_trainer_4_020:
	.byte		N03   , As4 , v064
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte	PEND
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_020
@ 022   ----------------------------------------
mus_oe_vs_trainer_4_022:
	.byte		N03   , An4 , v064
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte	PEND
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_022
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_022
@ 025   ----------------------------------------
	.byte		N03   , Gs4 , v064
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs4 , v060
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cs4 , v048
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs3 , v044
	.byte	W06
	.byte		N03   
	.byte	W06
@ 026   ----------------------------------------
	.byte		VOICE , 85
	.byte		N18   , Fs3 , v080
	.byte	W24
	.byte		N18   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N15   
	.byte	W18
	.byte		N09   
	.byte	W12
@ 027   ----------------------------------------
	.byte		N09   
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N09   , Fs3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N09   , Fs3 
	.byte	W12
	.byte		N21   
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		        Fs3 , v072
	.byte	W06
@ 028   ----------------------------------------
mus_oe_vs_trainer_4_028:
	.byte		N18   , Fs3 , v080
	.byte	W24
	.byte		N18   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N15   
	.byte	W18
	.byte		N09   
	.byte	W12
	.byte	PEND
@ 029   ----------------------------------------
	.byte		N09   
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N09   , Fs3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N09   , Fs3 
	.byte	W12
	.byte		N21   , Ds3 
	.byte	W36
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_028
@ 031   ----------------------------------------
	.byte		N09   , Fs3 , v080
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N09   , Fs3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N09   , Fs3 
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
@ 032   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_028
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_002
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_002
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_005
@ 038   ----------------------------------------
mus_oe_vs_trainer_4_038:
	.byte		N18   , As4 , v080
	.byte	W24
	.byte		N18   
	.byte	W72
	.byte	PEND
@ 039   ----------------------------------------
	.byte	W92
	.byte	W01
	.byte		N01   , Fs4 , v060
	.byte	W01
	.byte		        Gs4 , v076
	.byte	W02
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_4_038
@ 041   ----------------------------------------
	.byte	W48
	.byte		N03   , As3 , v036
	.byte	W06
	.byte		        As3 , v048
	.byte	W06
	.byte		        As3 , v060
	.byte	W06
	.byte		        As3 , v072
	.byte	W06
	.byte		        As4 , v084
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W03
	.byte		        Dn4 , v076
	.byte	W03
	.byte		        As3 , v072
	.byte	W03
	.byte		        Fn3 , v068
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        As2 , v064
	.byte	W03
	.byte		N02   , Fn2 , v060
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	GOTO
	 .word	mus_oe_vs_trainer_4_B1
mus_oe_vs_trainer_4_B2:
@ 042   ----------------------------------------
	.byte		VOICE , 85
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

mus_oe_vs_trainer_5:
	.byte	KEYSH , mus_oe_vs_trainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 82
	.byte		VOL   , 100*mus_oe_vs_trainer_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte		N09   , As2 , v080
	.byte	W24
	.byte		N09   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		        As2 , v064
	.byte	W06
	.byte		        As2 , v068
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        As2 , v072
	.byte	W06
	.byte		        As2 , v076
	.byte	W06
	.byte		        As2 , v080
	.byte	W06
	.byte		        As2 , v084
	.byte	W06
mus_oe_vs_trainer_5_B1:
@ 002   ----------------------------------------
	.byte		N18   , Ds3 , v088
	.byte	W24
	.byte		N16   
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N06   , Ds3 , v064
	.byte	W18
	.byte		        As2 
	.byte	W12
	.byte		N09   , Gs2 
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
@ 003   ----------------------------------------
mus_oe_vs_trainer_5_003:
	.byte		N06   , Cs3 , v064
	.byte	W12
	.byte		        Gs2 , v052
	.byte	W06
	.byte		        Ds3 , v064
	.byte	W12
	.byte		        Ds2 , v052
	.byte	W06
	.byte		N09   , Fs2 , v064
	.byte	W12
	.byte		N06   
	.byte	W48
	.byte	PEND
@ 004   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		N18   , Ds3 , v088
	.byte	W24
	.byte		N16   
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N06   , Ds3 , v064
	.byte	W18
	.byte		        As2 
	.byte	W12
	.byte		N09   , Gs2 
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_5_003
@ 006   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		N18   , Fs4 , v088
	.byte	W24
	.byte		N18   
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N06   , Ds3 , v064
	.byte	W18
	.byte		        As2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
@ 007   ----------------------------------------
	.byte		        Cs3 
	.byte	W12
	.byte		        Gs2 , v052
	.byte	W06
	.byte		        Ds3 , v064
	.byte	W12
	.byte		        Ds2 , v052
	.byte	W06
	.byte		N09   , Fs2 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn2 , v044
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
@ 008   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		N18   , Fs4 , v088
	.byte	W24
	.byte		N18   
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N06   , Ds3 , v064
	.byte	W18
	.byte		        As2 
	.byte	W12
	.byte		N09   , Gs2 
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
@ 009   ----------------------------------------
	.byte		        Cs3 
	.byte	W12
	.byte		        Gs2 , v052
	.byte	W06
	.byte		        Ds3 , v064
	.byte	W12
	.byte		        Ds2 , v052
	.byte	W06
	.byte		N09   , Fs2 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Ds2 , v048
	.byte	W06
	.byte		N04   , Gs2 , v064
	.byte	W06
	.byte		N12   , Gs2 , v076
	.byte	W12
	.byte		N09   , As2 
	.byte	W12
@ 010   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		N18   , Ds3 , v088
	.byte	W24
	.byte		N16   
	.byte	W18
	.byte		N06   , Ds3 , v064
	.byte	W18
	.byte		        As2 
	.byte	W12
	.byte		N09   , Gs2 
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_5_003
@ 012   ----------------------------------------
	.byte		N18   , Ds3 , v088
	.byte	W24
	.byte		N16   
	.byte	W18
	.byte		N06   , Ds3 , v064
	.byte	W18
	.byte		        As2 
	.byte	W12
	.byte		N09   , Gs2 
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Cs3 
	.byte	W12
	.byte		        Gs2 , v052
	.byte	W06
	.byte		        Ds3 , v064
	.byte	W12
	.byte		        Ds2 , v052
	.byte	W06
	.byte		N09   , Fs2 , v064
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		        As2 , v048
	.byte	W06
	.byte		        As2 , v056
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		        Cs3 , v056
	.byte	W06
	.byte		        As2 , v048
	.byte	W06
@ 014   ----------------------------------------
	.byte		N18   , Fs4 , v088
	.byte	W24
	.byte		N18   
	.byte	W18
	.byte		N06   , Ds3 , v064
	.byte	W18
	.byte		        As2 
	.byte	W12
	.byte		N09   , Gs2 
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_5_003
@ 016   ----------------------------------------
	.byte		N18   , Fs4 , v088
	.byte	W24
	.byte		N18   
	.byte	W36
	.byte		N06   , Ds2 , v068
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W18
@ 017   ----------------------------------------
	.byte		        Fs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Bn2 
	.byte	W18
	.byte		        Gs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cs3 
	.byte	W18
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
@ 018   ----------------------------------------
	.byte		N24   , Cs4 , v084
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N18   , Bn2 
	.byte	W12
@ 019   ----------------------------------------
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N18   
	.byte	W48
	.byte		N36   , Cs4 
	.byte	W12
@ 020   ----------------------------------------
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N18   , As3 
	.byte	W12
@ 021   ----------------------------------------
	.byte	W12
	.byte		        Bn3 
	.byte	W24
	.byte		        As3 
	.byte	W48
	.byte		N32   , An3 , v084, gtp2
	.byte	W12
@ 022   ----------------------------------------
	.byte	W24
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N18   
	.byte	W12
@ 023   ----------------------------------------
	.byte	W12
	.byte		N18   
	.byte	W24
	.byte		N18   
	.byte	W48
	.byte		N10   , An2 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N10   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N09   
	.byte	W12
@ 025   ----------------------------------------
	.byte		N10   , Gs2 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N19   , Cs3 
	.byte	W60
@ 026   ----------------------------------------
mus_oe_vs_trainer_5_026:
	.byte	W24
	.byte		N06   , Cs3 , v088
	.byte	W12
	.byte		        Gs2 , v072
	.byte	W06
	.byte		        Ds3 , v088
	.byte	W18
	.byte		        As2 
	.byte	W12
	.byte		N09   , Gs2 
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
	.byte	PEND
@ 027   ----------------------------------------
mus_oe_vs_trainer_5_027:
	.byte		N06   , Cs3 , v088
	.byte	W12
	.byte		        Gs2 , v072
	.byte	W06
	.byte		        Ds3 , v088
	.byte	W12
	.byte		        Ds2 , v072
	.byte	W06
	.byte		N09   , Fs2 , v088
	.byte	W12
	.byte		N06   
	.byte	W48
	.byte	PEND
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_5_026
@ 029   ----------------------------------------
	.byte		N06   , Cs3 , v088
	.byte	W12
	.byte		        Gs2 , v072
	.byte	W06
	.byte		        Ds3 , v088
	.byte	W12
	.byte		        Ds2 , v072
	.byte	W06
	.byte		N09   , Fs2 , v088
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N02   , Fs2 , v072
	.byte	W04
	.byte		        Fs2 , v076
	.byte	W04
	.byte		        Fs2 , v084
	.byte	W04
	.byte		N12   , Fs2 , v088
	.byte	W12
	.byte		N06   , Ds2 , v060
	.byte	W12
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_5_026
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_5_027
@ 032   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_5_026
@ 033   ----------------------------------------
	.byte		N03   , As4 , v088
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W54
@ 034   ----------------------------------------
mus_oe_vs_trainer_5_034:
	.byte		N18   , Ds3 , v088
	.byte	W24
	.byte		N16   
	.byte	W72
	.byte	PEND
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_5_034
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
mus_oe_vs_trainer_5_038:
	.byte		N18   , Fs4 , v088
	.byte	W24
	.byte		N18   
	.byte	W72
	.byte	PEND
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_5_038
@ 041   ----------------------------------------
	.byte		N09   , As2 , v080
	.byte	W24
	.byte		N09   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		        As2 , v064
	.byte	W06
	.byte		        As2 , v068
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        As2 , v072
	.byte	W06
	.byte		        As2 , v076
	.byte	W06
	.byte		        As2 , v080
	.byte	W06
	.byte		        As2 , v084
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	GOTO
	 .word	mus_oe_vs_trainer_5_B1
mus_oe_vs_trainer_5_B2:
@ 042   ----------------------------------------
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 6 (Midi-Chn.6) ****************@

mus_oe_vs_trainer_6:
	.byte	KEYSH , mus_oe_vs_trainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 88
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_trainer_mvl/mxv
	.byte		BENDR , 3
	.byte		BEND  , c_v+0
	.byte		N24   , Ds5 , v084
	.byte	W24
	.byte		        As5 
	.byte	W24
	.byte		N36   , An5 
	.byte	W36
	.byte		N12   , Fn5 
	.byte	W12
@ 001   ----------------------------------------
	.byte		N96   , Fs5 
	.byte	W36
	.byte		BEND  , c_v-1
	.byte		        c_v-2
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-4
	.byte		        c_v-5
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v-7
	.byte		        c_v-8
	.byte		        c_v-9
	.byte	W01
	.byte		        c_v-10
	.byte		        c_v-11
	.byte		        c_v-12
	.byte	W01
	.byte		        c_v-13
	.byte		        c_v-14
	.byte		        c_v-15
	.byte	W01
	.byte		        c_v-16
	.byte		        c_v-17
	.byte		        c_v-18
	.byte	W01
	.byte		        c_v-19
	.byte		        c_v-20
	.byte		        c_v-21
	.byte	W01
	.byte		        c_v-22
	.byte		        c_v-23
	.byte		        c_v-24
	.byte	W01
	.byte		        c_v-25
	.byte		        c_v-26
	.byte		        c_v-27
	.byte	W01
	.byte		        c_v-28
	.byte		        c_v-29
	.byte		        c_v-30
	.byte	W01
	.byte		        c_v-31
	.byte		        c_v-32
	.byte		        c_v-33
	.byte	W01
	.byte		        c_v-34
	.byte		        c_v-35
	.byte		        c_v-36
	.byte	W01
	.byte		        c_v-37
	.byte		        c_v-38
	.byte		        c_v-39
	.byte	W01
	.byte		        c_v-40
	.byte		        c_v-41
	.byte		        c_v-42
	.byte	W01
	.byte		        c_v-43
	.byte		        c_v-44
	.byte		        c_v-45
	.byte	W01
	.byte		        c_v-46
	.byte		        c_v-47
	.byte		        c_v-48
	.byte	W01
	.byte		        c_v-49
	.byte		        c_v-50
	.byte		        c_v-51
	.byte	W01
	.byte		        c_v-52
	.byte		        c_v-53
	.byte		        c_v-54
	.byte	W01
	.byte		        c_v-55
	.byte		        c_v-56
	.byte		        c_v-57
	.byte	W01
	.byte		        c_v-58
	.byte		        c_v-59
	.byte		        c_v-60
	.byte	W01
	.byte		        c_v-61
	.byte		        c_v-62
	.byte		        c_v-63
	.byte	W01
	.byte		        c_v-64
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W36
mus_oe_vs_trainer_6_B1:
@ 002   ----------------------------------------
	.byte		VOICE , 87
	.byte		BEND  , c_v+0
	.byte		N12   , Ds2 , v076
	.byte	W12
	.byte		N09   , Ds2 , v056
	.byte	W12
	.byte		N12   , Ds2 , v076
	.byte	W12
	.byte		N09   , Fs2 , v056
	.byte	W12
	.byte		N12   , Gs2 , v076
	.byte	W12
	.byte		N09   , Gs2 , v056
	.byte	W12
	.byte		N12   , Gs2 , v076
	.byte	W12
	.byte		N09   , As2 , v056
	.byte	W12
@ 003   ----------------------------------------
mus_oe_vs_trainer_6_003:
	.byte		N12   , Cs3 , v076
	.byte	W12
	.byte		N09   , Cs3 , v056
	.byte	W12
	.byte		N12   , Cs3 , v076
	.byte	W12
	.byte		N09   , Fs2 , v056
	.byte	W12
	.byte		N12   , Fs2 , v076
	.byte	W48
	.byte	PEND
@ 004   ----------------------------------------
mus_oe_vs_trainer_6_004:
	.byte		N12   , Ds2 , v076
	.byte	W12
	.byte		N09   , Ds2 , v056
	.byte	W12
	.byte		N12   , Ds2 , v076
	.byte	W12
	.byte		N09   , Fs2 , v056
	.byte	W12
	.byte		N12   , Gs2 , v076
	.byte	W12
	.byte		N09   , Gs2 , v056
	.byte	W12
	.byte		N12   , Gs2 , v076
	.byte	W12
	.byte		N09   , As2 , v056
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
	.byte		N12   , Cs3 , v076
	.byte	W12
	.byte		N09   , Cs3 , v056
	.byte	W12
	.byte		N12   , Cs3 , v076
	.byte	W12
	.byte		N09   , Fs2 , v056
	.byte	W12
	.byte		N12   , Fs2 , v076
	.byte	W12
	.byte		N06   , Gs3 , v096
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_6_004
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_6_003
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_6_004
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_6_003
@ 010   ----------------------------------------
mus_oe_vs_trainer_6_010:
	.byte		N18   , Fs3 , v104
	.byte	W24
	.byte		N18   
	.byte	W72
	.byte	PEND
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_6_010
@ 013   ----------------------------------------
mus_oe_vs_trainer_6_013:
	.byte	W92
	.byte	W01
	.byte		N01   , Fs4 , v080
	.byte	W01
	.byte		        Gs4 , v088
	.byte	W02
	.byte	PEND
@ 014   ----------------------------------------
	.byte		N18   , As4 , v096
	.byte	W24
	.byte		N18   
	.byte	W72
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_6_013
@ 016   ----------------------------------------
	.byte		N18   , As4 , v096
	.byte	W24
	.byte		N18   
	.byte	W24
	.byte		VOICE , 88
	.byte		N48   , Ds5 , v060
	.byte	W48
@ 017   ----------------------------------------
	.byte		        Fs5 , v068
	.byte	W48
	.byte		        Cs6 , v076
	.byte	W48
@ 018   ----------------------------------------
	.byte		TIE   , Bn5 , v076
	.byte	W96
@ 019   ----------------------------------------
	.byte	W48
	.byte		EOT   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		TIE   , Fs6 
	.byte	W12
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N06   , Bn5 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		N12   , Fs5 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		        Fs6 
	.byte	W12
@ 022   ----------------------------------------
	.byte		N96   , En6 
	.byte	W96
@ 023   ----------------------------------------
	.byte		N12   , As3 , v064
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
@ 024   ----------------------------------------
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N03   , An4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N03   
	.byte	W06
@ 025   ----------------------------------------
	.byte		        Dn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		N03   
	.byte	W06
@ 026   ----------------------------------------
	.byte		VOICE , 87
	.byte		N18   , Ds4 , v080
	.byte	W24
	.byte		N18   
	.byte	W48
	.byte		        Fs3 , v064
	.byte	W24
@ 027   ----------------------------------------
	.byte		N18   
	.byte	W48
	.byte		N21   , Fs4 
	.byte	W24
	.byte		N21   
	.byte	W24
@ 028   ----------------------------------------
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N21   
	.byte	W24
	.byte		N18   , Ds2 , v096
	.byte	W24
@ 029   ----------------------------------------
	.byte		N18   
	.byte	W96
@ 030   ----------------------------------------
	.byte		VOICE , 88
	.byte		N48   , Ds4 , v076
	.byte	W48
	.byte		        As4 
	.byte	W48
@ 031   ----------------------------------------
	.byte		        Gs4 
	.byte	W48
	.byte		        Cs5 
	.byte	W48
@ 032   ----------------------------------------
	.byte		N06   , Ds5 , v088
	.byte	W06
	.byte		        As4 , v056
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fs5 , v088
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fs4 , v056
	.byte	W06
	.byte		        Ds5 , v088
	.byte	W06
	.byte		        As4 , v056
	.byte	W06
	.byte		        Ds5 , v088
	.byte	W06
	.byte		        As4 , v056
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 , v088
	.byte	W06
	.byte		        Gs4 , v056
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
@ 033   ----------------------------------------
	.byte	W48
	.byte		N06   , As3 , v076
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
@ 034   ----------------------------------------
	.byte	W24
	.byte		VOICE , 87
	.byte	W12
	.byte		N09   , Fs3 , v072
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		TIE   , As3 
	.byte	W24
@ 035   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 036   ----------------------------------------
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 037   ----------------------------------------
	.byte		N72   , Gs3 
	.byte	W96
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_6_004
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_6_003
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_6_004
@ 041   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W01
	.byte	GOTO
	 .word	mus_oe_vs_trainer_6_B1
mus_oe_vs_trainer_6_B2:
@ 042   ----------------------------------------
	.byte		VOICE , 88
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_trainer_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 7 (Midi-Chn.7) ****************@

mus_oe_vs_trainer_7:
	.byte	KEYSH , mus_oe_vs_trainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 38*mus_oe_vs_trainer_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
mus_oe_vs_trainer_7_B1:
@ 002   ----------------------------------------
mus_oe_vs_trainer_7_002:
	.byte		N05   , Cs4 , v088
	.byte	W12
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs4 , v088
	.byte	W12
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs4 , v088
	.byte	W12
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs4 , v088
	.byte	W12
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
mus_oe_vs_trainer_7_003:
	.byte		N05   , Cs4 , v088
	.byte	W12
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs4 , v088
	.byte	W12
	.byte		N11   , Ds4 , v084
	.byte	W12
	.byte		N05   , Cs4 , v088
	.byte	W12
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs4 , v088
	.byte	W12
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte	PEND
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_002
@ 005   ----------------------------------------
mus_oe_vs_trainer_7_005:
	.byte		N05   , Cs4 , v088
	.byte	W12
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs4 , v088
	.byte	W12
	.byte		N11   , Ds4 , v084
	.byte	W12
	.byte		N05   , Cs4 , v088
	.byte	W12
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs4 , v088
	.byte	W06
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_003
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_002
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_003
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_002
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_003
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_002
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_005
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_002
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_003
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_002
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_005
@ 018   ----------------------------------------
	.byte		N05   , Cs4 , v076
	.byte	W12
	.byte		N16   , Ds4 
	.byte	W24
	.byte		N16   
	.byte	W24
	.byte		N16   
	.byte	W24
	.byte		N16   
	.byte	W12
@ 019   ----------------------------------------
mus_oe_vs_trainer_7_019:
	.byte	W12
	.byte		N16   , Ds4 , v076
	.byte	W24
	.byte		N16   
	.byte	W24
	.byte		N16   
	.byte	W24
	.byte		N16   
	.byte	W12
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 032   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_019
@ 033   ----------------------------------------
	.byte	W12
	.byte		N16   , Ds4 , v076
	.byte	W18
	.byte		N13   
	.byte	W30
	.byte		N05   , Cs4 
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		        Cs4 , v088
	.byte	W12
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N05   
	.byte	W06
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_002
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_003
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_002
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_005
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_002
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_003
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_7_002
@ 041   ----------------------------------------
	.byte		N05   , Cs4 , v088
	.byte	W96
	.byte	GOTO
	 .word	mus_oe_vs_trainer_7_B1
mus_oe_vs_trainer_7_B2:
@ 042   ----------------------------------------
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 38*mus_oe_vs_trainer_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 8 (Midi-Chn.10) ****************@

mus_oe_vs_trainer_8:
	.byte	KEYSH , mus_oe_vs_trainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_trainer_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W84
	.byte		N06   , En1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
@ 001   ----------------------------------------
	.byte		N12   
	.byte	W36
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte		N48   , Cn3 , v064
	.byte	W24
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
mus_oe_vs_trainer_8_B1:
@ 002   ----------------------------------------
mus_oe_vs_trainer_8_002:
	.byte		N12   , Cn1 , v100
	.byte		N48   , An2 , v108
	.byte	W12
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		        En1 , v100
	.byte	W24
	.byte		        Cn1 
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W24
	.byte	PEND
@ 003   ----------------------------------------
mus_oe_vs_trainer_8_003:
	.byte		N12   , Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte	PEND
@ 004   ----------------------------------------
mus_oe_vs_trainer_8_004:
	.byte		N12   , Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        En1 , v100
	.byte	W24
	.byte		        Cn1 
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
mus_oe_vs_trainer_8_005:
	.byte		N12   , Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W12
	.byte		N06   , An1 , v076
	.byte	W06
	.byte		        Gn1 , v064
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v092
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_004
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_003
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_004
@ 009   ----------------------------------------
	.byte		N12   , Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W12
	.byte		N06   , An1 , v076
	.byte	W06
	.byte		        Gn1 , v064
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v092
	.byte	W06
	.byte		        En1 , v100
	.byte		N12   , Cs2 , v072
	.byte	W06
	.byte		N06   , En1 , v096
	.byte	W06
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_002
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_003
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_004
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_005
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_004
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_003
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_004
@ 017   ----------------------------------------
	.byte	W12
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , En1 
	.byte		N36   , En2 , v096
	.byte	W06
	.byte		N06   , Cn1 , v100
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        En1 , v092
	.byte	W06
	.byte		N03   , En1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v100
	.byte	W06
@ 018   ----------------------------------------
	.byte		N12   , Cn1 
	.byte		N48   , An2 , v108
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W18
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
@ 019   ----------------------------------------
mus_oe_vs_trainer_8_019:
	.byte		N12   , Cn1 , v100
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 , v092
	.byte	W06
	.byte	PEND
@ 020   ----------------------------------------
mus_oe_vs_trainer_8_020:
	.byte		N12   , Cn1 , v100
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W18
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte	PEND
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_019
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_020
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_019
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_020
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_019
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_002
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_003
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_004
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_005
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_004
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_003
@ 032   ----------------------------------------
	.byte		N12   , Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        En1 , v100
	.byte	W24
	.byte		        Cn1 
	.byte	W18
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   , En1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
@ 033   ----------------------------------------
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		N54   , An2 , v108
	.byte	W12
	.byte		N06   , Cn1 , v084
	.byte	W06
	.byte		        An1 , v076
	.byte	W06
	.byte		        Gn1 , v064
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v092
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
@ 034   ----------------------------------------
mus_oe_vs_trainer_8_034:
	.byte		N12   , Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        En1 , v100
	.byte	W36
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte	PEND
@ 035   ----------------------------------------
mus_oe_vs_trainer_8_035:
	.byte		N12   , Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        En1 , v100
	.byte	W36
	.byte		N06   , Cn1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte	PEND
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_034
@ 037   ----------------------------------------
	.byte		N12   , Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   , An1 , v076
	.byte	W06
	.byte		        Gn1 , v064
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v092
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_034
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_trainer_8_035
@ 040   ----------------------------------------
	.byte		N12   , Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        En1 , v100
	.byte	W36
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 041   ----------------------------------------
	.byte		N12   
	.byte	W36
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte		N44   , Cn3 , v064, gtp3
	.byte	W24
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte	GOTO
	 .word	mus_oe_vs_trainer_8_B1
mus_oe_vs_trainer_8_B2:
@ 042   ----------------------------------------
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_trainer_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	FINE

@******************************************************@
	.align	2

mus_oe_vs_trainer:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_oe_vs_trainer_pri	@ Priority
	.byte	mus_oe_vs_trainer_rev	@ Reverb.

	.word	mus_oe_vs_trainer_grp

	.word	mus_oe_vs_trainer_1
	.word	mus_oe_vs_trainer_2
	.word	mus_oe_vs_trainer_3
	.word	mus_oe_vs_trainer_4
	.word	mus_oe_vs_trainer_5
	.word	mus_oe_vs_trainer_6
	.word	mus_oe_vs_trainer_7
	.word	mus_oe_vs_trainer_8

	.end
