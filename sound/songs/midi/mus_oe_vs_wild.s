	.include "MPlayDef.s"

	.equ	mus_oe_vs_wild_grp, voicegroup_vs_frontier_brain
	.equ	mus_oe_vs_wild_pri, 1
	.equ	mus_oe_vs_wild_rev, reverb_set+50
	.equ	mus_oe_vs_wild_mvl, 100
	.equ	mus_oe_vs_wild_key, 0
	.equ	mus_oe_vs_wild_tbs, 1
	.equ	mus_oe_vs_wild_exg, 1
	.equ	mus_oe_vs_wild_cmp, 1

	.section .rodata
	.global	mus_oe_vs_wild
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_oe_vs_wild_1:
	.byte	KEYSH , mus_oe_vs_wild_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 100*mus_oe_vs_wild_tbs/2
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		N03   , Fs2 , v044
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Gs2 , v048
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        As2 , v052
	.byte	W03
	.byte		        Bn2 , v056
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Cs3 , v060
	.byte	W03
	.byte		        Dn3 , v064
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Fs3 , v068
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        An3 , v072
	.byte	W03
	.byte		        Bn3 , v076
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        En4 , v080
	.byte	W03
	.byte		        Fs4 , v084
	.byte	W03
	.byte		        En4 , v080
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cs4 , v076
	.byte	W03
	.byte		        Bn3 , v072
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gn3 , v068
	.byte	W03
	.byte		        En3 , v064
	.byte	W03
	.byte		        Fs3 , v072
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Dn3 , v068
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Bn2 , v064
	.byte	W03
	.byte		        An2 , v060
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        En2 , v056
	.byte	W03
@ 001   ----------------------------------------
	.byte		N09   , Fs2 , v084
	.byte	W18
	.byte		        An2 
	.byte	W18
	.byte		        En2 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N09   , Dn3 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
@ 002   ----------------------------------------
	.byte		N18   
	.byte	W18
	.byte		        Dn3 
	.byte	W18
	.byte		        An4 , v092
	.byte	W18
	.byte		        Fs4 
	.byte	W18
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 003   ----------------------------------------
	.byte		N09   , Bn3 , v080
	.byte	W42
	.byte		N07   , Cs4 
	.byte	W54
mus_oe_vs_wild_1_B1:
@ 004   ----------------------------------------
	.byte		VOICE , 56
	.byte	W12
	.byte		N06   , Bn3 , v116
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N10   , Dn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W18
	.byte		N06   , Bn3 , v108
	.byte	W06
	.byte		        Bn3 , v116
	.byte	W06
@ 005   ----------------------------------------
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N10   , Fs4 
	.byte	W12
	.byte		N12   
	.byte	W24
@ 006   ----------------------------------------
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N10   , Bn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W30
@ 007   ----------------------------------------
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        En4 , v108
	.byte	W06
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 , v116
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 , v120
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N10   , An4 , v124
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N15   , Fs4 
	.byte	W30
@ 008   ----------------------------------------
	.byte	W42
	.byte		N06   , En4 , v116
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W24
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W42
	.byte		N06   , En3 , v108
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N12   
	.byte	W24
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte		VOICE , 48
	.byte		N18   , Bn3 , v056
	.byte	W18
	.byte		        Cs4 
	.byte	W18
	.byte		N12   , Fs4 , v060
	.byte	W12
	.byte		N06   , En4 , v064
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 , v068
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 , v072
	.byte	W06
@ 019   ----------------------------------------
	.byte		N24   , An3 , v080
	.byte	W24
	.byte		        Dn4 , v088
	.byte	W24
	.byte		N18   , En4 , v096
	.byte	W18
	.byte		        An4 , v104
	.byte	W30
@ 020   ----------------------------------------
	.byte		N96   , Bn4 , v056
	.byte	W96
@ 021   ----------------------------------------
	.byte		        Dn5 
	.byte	W96
@ 022   ----------------------------------------
	.byte		N18   , Bn4 , v064
	.byte	W18
	.byte		        Bn3 , v076
	.byte	W18
	.byte		        Fs4 
	.byte	W18
	.byte		        En4 
	.byte	W18
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 023   ----------------------------------------
	.byte		N30   , Dn4 
	.byte	W30
	.byte		N06   , En4 , v072
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N54   , Cs4 , v068
	.byte	W54
@ 024   ----------------------------------------
	.byte	W60
	.byte		N12   , Bn3 , v080
	.byte	W12
	.byte		N09   , Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
@ 025   ----------------------------------------
	.byte		N18   , Fs4 , v092
	.byte	W18
	.byte		N66   , Dn4 
	.byte	W78
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W48
	.byte		N06   , En3 , v056
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		        En3 , v068
	.byte	W06
	.byte		        Fs3 , v076
	.byte	W06
	.byte		        En3 , v084
	.byte	W06
	.byte		        Fs3 , v088
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		        Fs3 , v104
	.byte	W06
@ 028   ----------------------------------------
	.byte		N09   , Fs3 , v080
	.byte	W18
	.byte		        An3 
	.byte	W18
	.byte		        En3 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N09   , Dn4 
	.byte	W12
	.byte		N12   , Bn3 
	.byte	W12
@ 029   ----------------------------------------
	.byte		N18   , Fs4 , v092
	.byte	W18
	.byte		N66   , Dn4 
	.byte	W72
	.byte		N06   , Dn3 , v104
	.byte	W06
@ 030   ----------------------------------------
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N16   , En3 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N18   , Fs3 
	.byte	W18
	.byte		        En3 
	.byte	W18
	.byte		N12   , Dn3 
	.byte	W12
@ 031   ----------------------------------------
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N42   , An3 
	.byte	W42
	.byte		N12   , Dn4 
	.byte	W12
@ 032   ----------------------------------------
	.byte		        Bn3 
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte		N09   , En4 , v072
	.byte	W36
	.byte	W03
	.byte		N09   
	.byte	W09
	.byte		        Fs4 
	.byte	W48
	.byte	GOTO
	 .word	mus_oe_vs_wild_1_B1
mus_oe_vs_wild_1_B2:
@ 039   ----------------------------------------
	.byte		VOICE , 48
	.byte		        48
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte	FINE

@**************** Track 2 (Midi-Chn.3) ****************@

mus_oe_vs_wild_2:
	.byte	KEYSH , mus_oe_vs_wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte	W84
	.byte		N12   , Dn3 , v096
	.byte	W12
@ 001   ----------------------------------------
	.byte		N09   , Bn2 , v116
	.byte	W18
	.byte		        Dn3 
	.byte	W18
	.byte		        An2 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		N09   , Fs3 
	.byte	W12
	.byte		N12   , Dn3 
	.byte	W12
@ 002   ----------------------------------------
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N54   , An3 
	.byte	W72
	.byte		N06   , Dn3 
	.byte	W06
@ 003   ----------------------------------------
	.byte		        En3 , v120
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 , v116
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N07   , Fs3 , v124
	.byte	W42
	.byte		N12   , Dn3 , v096
	.byte	W12
mus_oe_vs_wild_2_B1:
@ 004   ----------------------------------------
	.byte		N12   , Bn2 , v096
	.byte	W96
@ 005   ----------------------------------------
	.byte	W84
	.byte		        En3 
	.byte	W12
@ 006   ----------------------------------------
	.byte		        Bn2 
	.byte	W96
@ 007   ----------------------------------------
	.byte	W48
	.byte		N10   , Fs4 , v076
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N18   , Dn4 
	.byte	W24
	.byte		N06   , Dn4 , v104
	.byte	W06
@ 008   ----------------------------------------
	.byte		        En4 , v108
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N15   , En4 
	.byte	W60
	.byte		N12   , Dn3 , v096
	.byte	W12
@ 009   ----------------------------------------
	.byte		        Bn2 
	.byte	W90
	.byte		N06   , Dn3 , v104
	.byte	W06
@ 010   ----------------------------------------
	.byte		        En3 , v108
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N15   , En3 
	.byte	W60
	.byte		N12   , Dn3 , v096
	.byte	W12
@ 011   ----------------------------------------
	.byte		        Bn2 
	.byte	W96
@ 012   ----------------------------------------
	.byte	W84
	.byte		        En3 , v084
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Bn2 
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte		VOICE , 30
	.byte	W12
	.byte		N06   , Bn2 , v120
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N18   , Dn3 
	.byte	W18
	.byte		N09   , En3 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
@ 017   ----------------------------------------
	.byte		N04   , An3 , v124
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        En3 , v120
	.byte	W04
	.byte		        Dn3 , v116
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        An2 , v112
	.byte	W04
	.byte		N06   , Bn2 , v108
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        En3 , v116
	.byte	W06
	.byte		N42   , Fs3 
	.byte	W54
@ 018   ----------------------------------------
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
@ 019   ----------------------------------------
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N18   , Gn3 
	.byte	W18
	.byte		N30   , An3 
	.byte	W30
@ 020   ----------------------------------------
	.byte	W12
	.byte		N12   , Bn3 , v112
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N18   , Dn4 
	.byte	W18
	.byte		        Cs4 
	.byte	W18
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
@ 021   ----------------------------------------
	.byte		N30   , An3 
	.byte	W30
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N36   , En3 
	.byte	W36
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N24   , Bn2 
	.byte	W06
@ 022   ----------------------------------------
	.byte	W18
	.byte		N18   , Fs2 
	.byte	W18
	.byte		        Dn3 
	.byte	W18
	.byte		        Cs3 
	.byte	W18
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
@ 023   ----------------------------------------
	.byte		N06   , Fs3 , v108
	.byte	W06
	.byte		        En3 , v092
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 , v104
	.byte	W06
	.byte		N54   , An3 
	.byte	W54
@ 024   ----------------------------------------
	.byte		VOICE , 60
	.byte		N09   , Bn3 , v108
	.byte	W18
	.byte		        Dn4 
	.byte	W18
	.byte		        An3 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 025   ----------------------------------------
mus_oe_vs_wild_2_025:
	.byte		N18   , Bn4 , v108
	.byte	W18
	.byte		N66   , An4 
	.byte	W78
	.byte	PEND
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte		N09   , Bn3 
	.byte	W18
	.byte		        Dn4 
	.byte	W18
	.byte		        An3 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N09   , Fs4 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_2_025
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W84
	.byte		N12   , Dn3 , v096
	.byte	W12
@ 032   ----------------------------------------
	.byte		        Bn2 
	.byte	W96
@ 033   ----------------------------------------
	.byte		VOICE , 30
	.byte		N09   , Dn2 
	.byte	W12
	.byte		N09   
	.byte	W18
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W18
	.byte		N09   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte		VOICE , 60
	.byte		N12   , En3 , v068
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Fs3 
	.byte	W36
	.byte		        Dn3 , v096
	.byte	W12
	.byte	GOTO
	 .word	mus_oe_vs_wild_2_B1
mus_oe_vs_wild_2_B2:
@ 039   ----------------------------------------
	.byte		VOICE , 60
	.byte		        60
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte	FINE

@**************** Track 3 (Midi-Chn.4) ****************@

mus_oe_vs_wild_3:
	.byte	KEYSH , mus_oe_vs_wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 33
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		N12   , Bn1 , v048
	.byte	W12
	.byte		N06   , Bn1 , v052
	.byte	W06
	.byte		        An1 , v056
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Bn1 , v060
	.byte	W06
	.byte		        An1 , v064
	.byte	W06
	.byte		N12   , Bn1 , v068
	.byte	W12
	.byte		N06   , Bn1 , v072
	.byte	W06
	.byte		        An1 , v076
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        En2 , v080
	.byte	W06
	.byte		N12   , Dn2 , v100
	.byte	W12
@ 001   ----------------------------------------
mus_oe_vs_wild_3_001:
	.byte		VOICE , 30
	.byte		N12   , Bn1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
mus_oe_vs_wild_3_002:
	.byte		N12   , Dn2 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
	.byte		        En2 
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		        En2 , v100
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		        En2 , v100
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		        En2 , v100
	.byte	W06
	.byte		N09   , Fs2 
	.byte	W42
	.byte		N12   , Dn2 
	.byte	W12
mus_oe_vs_wild_3_B1:
@ 004   ----------------------------------------
mus_oe_vs_wild_3_004:
	.byte		N12   , Bn1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_002
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_004
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_002
@ 008   ----------------------------------------
mus_oe_vs_wild_3_008:
	.byte		N06   , En2 , v100
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		        En2 , v100
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		N15   , En2 , v100
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Fs2 , v088
	.byte	W06
	.byte		        Fs2 , v100
	.byte	W06
	.byte		        Fs2 , v088
	.byte	W06
	.byte		N15   , Fs2 , v100
	.byte	W18
	.byte		N12   , Dn2 
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
	.byte		        Bn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
@ 010   ----------------------------------------
	.byte		N09   , En2 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N09   , Fs2 
	.byte	W36
	.byte		N12   , Dn2 
	.byte	W12
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_004
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_002
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_004
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_002
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_008
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_004
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_002
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_004
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_002
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_004
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_002
@ 022   ----------------------------------------
	.byte		N12   , En2 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_002
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_004
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_002
@ 026   ----------------------------------------
	.byte		N12   , En2 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
@ 027   ----------------------------------------
	.byte		        Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn2 , v104
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        En2 , v100
	.byte	W06
	.byte		        Dn2 , v096
	.byte	W06
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_004
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_002
@ 030   ----------------------------------------
	.byte		N12   , En2 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 031   ----------------------------------------
	.byte		        Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N09   
	.byte	W24
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
@ 032   ----------------------------------------
	.byte		VOICE , 33
	.byte		N12   , Bn0 , v104
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W12
@ 033   ----------------------------------------
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_001
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_3_002
@ 036   ----------------------------------------
	.byte		N12   , En1 , v100
	.byte	W13
	.byte		N09   
	.byte	W32
	.byte	W03
	.byte		N12   , Fs1 
	.byte	W48
@ 037   ----------------------------------------
	.byte		N09   , Bn1 
	.byte	W12
	.byte		N09   
	.byte	W18
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W18
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
@ 038   ----------------------------------------
	.byte		N12   , En2 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Fs2 
	.byte	W36
	.byte		N11   , Dn2 
	.byte	W12
	.byte	GOTO
	 .word	mus_oe_vs_wild_3_B1
mus_oe_vs_wild_3_B2:
@ 039   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte	FINE

@**************** Track 4 (Midi-Chn.7) ****************@

mus_oe_vs_wild_4:
	.byte	KEYSH , mus_oe_vs_wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 85
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		N12   , An2 , v060
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N36   , Fs4 
	.byte	W48
@ 001   ----------------------------------------
	.byte		N06   , Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
@ 002   ----------------------------------------
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
@ 003   ----------------------------------------
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N03   , Cs4 , v056
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Fs3 , v060
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Fs3 , v064
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Fs3 , v068
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		        Dn3 , v072
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		        Dn2 , v076
	.byte	W03
mus_oe_vs_wild_4_B1:
@ 004   ----------------------------------------
	.byte		N15   , Bn2 , v080
	.byte	W96
@ 005   ----------------------------------------
	.byte	W84
	.byte		N12   , En3 
	.byte	W12
@ 006   ----------------------------------------
	.byte		N15   , Bn2 
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W84
	.byte		N12   , Dn3 
	.byte	W12
@ 009   ----------------------------------------
	.byte		        Bn2 
	.byte	W96
@ 010   ----------------------------------------
	.byte	W84
	.byte		        Dn3 
	.byte	W12
@ 011   ----------------------------------------
	.byte		        Bn2 
	.byte	W96
@ 012   ----------------------------------------
	.byte	W84
	.byte		        En3 
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Bn2 
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W84
	.byte		        Dn3 
	.byte	W12
@ 016   ----------------------------------------
mus_oe_vs_wild_4_016:
	.byte		N03   , Bn0 , v068
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte	PEND
@ 017   ----------------------------------------
mus_oe_vs_wild_4_017:
	.byte		N03   , Dn1 , v068
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte	PEND
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_016
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_017
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_016
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_017
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_016
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_017
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_016
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_017
@ 026   ----------------------------------------
mus_oe_vs_wild_4_026:
	.byte		N03   , En1 , v068
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte	PEND
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_017
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_016
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_017
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_026
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_4_017
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W48
	.byte		N48   , Dn3 , v084
	.byte	W24
	.byte		BEND  , c_v-1
	.byte		        c_v-1
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v-1
	.byte		        c_v-1
	.byte		        c_v-1
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-2
	.byte		        c_v-2
	.byte		        c_v-2
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-2
	.byte		        c_v-3
	.byte		        c_v-3
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-3
	.byte		        c_v-3
	.byte		        c_v-3
	.byte		        c_v-4
	.byte	W01
	.byte		        c_v-4
	.byte		        c_v-4
	.byte		        c_v-4
	.byte		        c_v-4
	.byte	W01
	.byte		        c_v-4
	.byte		        c_v-5
	.byte		        c_v-5
	.byte		        c_v-5
	.byte	W01
	.byte		        c_v-5
	.byte		        c_v-5
	.byte		        c_v-6
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v-6
	.byte		        c_v-6
	.byte		        c_v-6
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v-7
	.byte		        c_v-7
	.byte		        c_v-7
	.byte		        c_v-7
	.byte	W01
	.byte		        c_v-7
	.byte		        c_v-7
	.byte		        c_v-8
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-8
	.byte		        c_v-8
	.byte		        c_v-8
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-9
	.byte		        c_v-9
	.byte		        c_v-9
	.byte		        c_v-9
	.byte	W01
	.byte		        c_v-9
	.byte		        c_v-9
	.byte		        c_v-10
	.byte		        c_v-10
	.byte	W01
	.byte		        c_v-10
	.byte		        c_v-10
	.byte		        c_v-10
	.byte		        c_v-10
	.byte	W01
	.byte		        c_v-11
	.byte		        c_v-11
	.byte		        c_v-11
	.byte		        c_v-11
	.byte	W01
	.byte		        c_v-11
	.byte		        c_v-11
	.byte		        c_v-12
	.byte		        c_v-12
	.byte	W01
	.byte		        c_v-12
	.byte		        c_v-12
	.byte		        c_v-12
	.byte		        c_v-12
	.byte	W01
	.byte		        c_v-13
	.byte		        c_v-13
	.byte		        c_v-13
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v-13
	.byte		        c_v-13
	.byte		        c_v-14
	.byte		        c_v-14
	.byte	W01
	.byte		        c_v-14
	.byte		        c_v-14
	.byte		        c_v-14
	.byte		        c_v-14
	.byte	W01
	.byte		        c_v-15
	.byte		        c_v-15
	.byte		        c_v-15
	.byte		        c_v-15
	.byte	W01
	.byte		        c_v-15
	.byte		        c_v-15
	.byte		        c_v-16
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-16
	.byte		        c_v-16
	.byte		        c_v-16
	.byte		        c_v-16
	.byte	W01
@ 034   ----------------------------------------
	.byte		        c_v+0
	.byte		N09   , Bn2 
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W24
	.byte		N01   , En2 , v072
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N06   , Fs3 , v056
	.byte	W21
	.byte		N01   , En3 , v052
	.byte	W01
	.byte		        Fn3 , v060
	.byte	W02
	.byte		N06   , Fs3 , v064
	.byte	W12
	.byte		N04   , Fs2 , v068
	.byte	W12
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte		N12   , En3 , v080
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Fs3 
	.byte	W36
	.byte		        Dn3 
	.byte	W11
	.byte		BEND  , c_v+0
	.byte	W01
	.byte	GOTO
	 .word	mus_oe_vs_wild_4_B1
mus_oe_vs_wild_4_B2:
@ 039   ----------------------------------------
	.byte		VOICE , 85
	.byte		        85
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte	FINE

@**************** Track 5 (Midi-Chn.8) ****************@

mus_oe_vs_wild_5:
	.byte	KEYSH , mus_oe_vs_wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 83
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		N06   , Bn1 , v052
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Bn1 , v056
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Bn1 , v060
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        An1 , v064
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , An2 , v080
	.byte	W12
@ 001   ----------------------------------------
mus_oe_vs_wild_5_001:
	.byte		N12   , Fs2 , v072
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
mus_oe_vs_wild_5_002:
	.byte		N12   , An2 , v072
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
	.byte		        Bn2 
	.byte	W06
	.byte		        Bn2 , v056
	.byte	W06
	.byte		        Bn2 , v060
	.byte	W06
	.byte		        Bn2 , v064
	.byte	W06
	.byte		        Gn2 , v068
	.byte	W06
	.byte		        An2 , v072
	.byte	W06
	.byte		        Bn2 , v076
	.byte	W06
	.byte		        Cs3 , v084
	.byte	W06
	.byte		N03   , Fs1 , v040
	.byte	W06
	.byte		        An1 , v044
	.byte	W06
	.byte		        Cs2 , v048
	.byte	W06
	.byte		        Fs2 , v052
	.byte	W06
	.byte		        An2 , v056
	.byte	W06
	.byte		        Cs3 , v060
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		        Cs3 , v068
	.byte	W06
mus_oe_vs_wild_5_B1:
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_001
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_002
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_001
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_002
@ 008   ----------------------------------------
mus_oe_vs_wild_5_008:
	.byte		N06   , Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v056
	.byte	W06
	.byte		        Bn2 , v060
	.byte	W06
	.byte		        Bn2 , v068
	.byte	W06
	.byte		N12   , Bn2 , v072
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs3 , v052
	.byte	W06
	.byte		        Cs3 , v060
	.byte	W06
	.byte		        Cs3 , v064
	.byte	W06
	.byte		N12   , Cs3 , v072
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
	.byte		        Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
@ 010   ----------------------------------------
	.byte		N09   , Bn2 
	.byte	W36
	.byte		N06   , Bn2 , v060
	.byte	W06
	.byte		        Bn2 , v064
	.byte	W06
	.byte		N09   , Cs3 , v072
	.byte	W36
	.byte		N12   , An2 
	.byte	W12
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_001
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_002
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_001
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_002
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_008
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_001
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_002
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_001
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_002
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_001
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_002
@ 022   ----------------------------------------
	.byte		N12   , Bn2 , v072
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_002
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_001
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_002
@ 026   ----------------------------------------
	.byte		N12   , Gs2 , v072
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
@ 027   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_001
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_002
@ 030   ----------------------------------------
	.byte		N12   , Gs2 , v072
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
@ 031   ----------------------------------------
	.byte		        An2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , An1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
@ 032   ----------------------------------------
	.byte		N72   , Fs3 , v056, gtp3
	.byte	W96
@ 033   ----------------------------------------
	.byte	W48
	.byte		N48   , An2 , v084
	.byte	W24
	.byte		BEND  , c_v-1
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v-1
	.byte		        c_v-1
	.byte		        c_v-1
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-2
	.byte		        c_v-2
	.byte		        c_v-2
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-2
	.byte		        c_v-3
	.byte		        c_v-3
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-3
	.byte		        c_v-3
	.byte		        c_v-3
	.byte		        c_v-4
	.byte	W01
	.byte		        c_v-4
	.byte		        c_v-4
	.byte		        c_v-4
	.byte		        c_v-4
	.byte	W01
	.byte		        c_v-4
	.byte		        c_v-5
	.byte		        c_v-5
	.byte		        c_v-5
	.byte	W01
	.byte		        c_v-5
	.byte		        c_v-5
	.byte		        c_v-5
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v-6
	.byte		        c_v-6
	.byte		        c_v-6
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v-6
	.byte		        c_v-7
	.byte		        c_v-7
	.byte		        c_v-7
	.byte	W01
	.byte		        c_v-7
	.byte		        c_v-7
	.byte		        c_v-8
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-8
	.byte		        c_v-8
	.byte		        c_v-8
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-9
	.byte		        c_v-9
	.byte		        c_v-9
	.byte		        c_v-9
	.byte	W01
	.byte		        c_v-9
	.byte		        c_v-9
	.byte		        c_v-10
	.byte		        c_v-10
	.byte	W01
	.byte		        c_v-10
	.byte		        c_v-10
	.byte		        c_v-10
	.byte		        c_v-10
	.byte	W01
	.byte		        c_v-11
	.byte		        c_v-11
	.byte		        c_v-11
	.byte		        c_v-11
	.byte	W01
	.byte		        c_v-11
	.byte		        c_v-11
	.byte		        c_v-12
	.byte		        c_v-12
	.byte	W01
	.byte		        c_v-12
	.byte		        c_v-12
	.byte		        c_v-12
	.byte		        c_v-12
	.byte	W01
	.byte		        c_v-13
	.byte		        c_v-13
	.byte		        c_v-13
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v-13
	.byte		        c_v-14
	.byte		        c_v-14
	.byte		        c_v-14
	.byte	W01
	.byte		        c_v-14
	.byte		        c_v-14
	.byte		        c_v-14
	.byte		        c_v-15
	.byte	W01
	.byte		        c_v-15
	.byte		        c_v-15
	.byte		        c_v-15
	.byte		        c_v-15
	.byte	W01
	.byte		        c_v-15
	.byte		        c_v-16
	.byte		        c_v-16
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-16
	.byte		        c_v-16
	.byte		        c_v-16
	.byte		        c_v-16
	.byte	W01
@ 034   ----------------------------------------
	.byte		        c_v+0
	.byte		N09   , Fs2 
	.byte	W12
	.byte		N06   , Fs2 , v072
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_5_002
@ 036   ----------------------------------------
	.byte		N09   , Bn1 , v072
	.byte	W12
	.byte		N09   
	.byte	W36
	.byte		N12   , Cs2 
	.byte	W48
@ 037   ----------------------------------------
	.byte		N09   , Fs2 
	.byte	W12
	.byte		N09   
	.byte	W18
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W18
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
@ 038   ----------------------------------------
	.byte		N12   , Bn2 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Cs3 
	.byte	W36
	.byte		        An2 
	.byte	W11
	.byte		BEND  , c_v+0
	.byte	W01
	.byte	GOTO
	 .word	mus_oe_vs_wild_5_B1
mus_oe_vs_wild_5_B2:
@ 039   ----------------------------------------
	.byte		VOICE , 83
	.byte		        83
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte	FINE

@**************** Track 6 (Midi-Chn.9) ****************@

mus_oe_vs_wild_6:
	.byte	KEYSH , mus_oe_vs_wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 88
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		MOD   , 0
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		MOD   , 0
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		N12   , An3 , v088
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		MOD   , 4
	.byte		N48   , Fs5 
	.byte	W48
@ 001   ----------------------------------------
	.byte		MOD   , 0
	.byte	W96
@ 002   ----------------------------------------
	.byte		N18   , Bn3 , v056
	.byte	W18
	.byte		N54   , Dn4 
	.byte	W78
@ 003   ----------------------------------------
	.byte	W96
mus_oe_vs_wild_6_B1:
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W12
	.byte		N12   , Bn4 , v092
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N36   , Bn4 , v092, gtp3
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte	W12
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N18   , Dn4 
	.byte	W18
	.byte		        Bn3 
	.byte	W18
	.byte		N24   , Fs3 
	.byte	W12
@ 012   ----------------------------------------
	.byte	W12
	.byte		N72   , An3 , v084
	.byte	W24
	.byte		MOD   , 5
	.byte	W48
	.byte		        0
	.byte	W12
@ 013   ----------------------------------------
	.byte	W12
	.byte		N06   , Bn3 , v080
	.byte	W06
	.byte		        An3 , v084
	.byte	W06
	.byte		        Bn3 , v088
	.byte	W06
	.byte		        An3 , v096
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		        An3 , v104
	.byte	W06
	.byte		N10   , Dn4 , v112
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W30
@ 014   ----------------------------------------
	.byte		N06   , Dn4 , v092
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		        Dn4 , v104
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 , v108
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		N10   , Fs4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N18   , Dn4 
	.byte	W24
	.byte		N06   , Dn4 , v104
	.byte	W06
@ 015   ----------------------------------------
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 , v108
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		N15   , En4 
	.byte	W18
	.byte		N06   , En4 , v100
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 , v104
	.byte	W06
	.byte		        Fs4 , v108
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fs4 , v112
	.byte	W24
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte		VOICE , 89
	.byte		N06   , Bn3 , v108
	.byte	W18
	.byte		        Dn4 
	.byte	W18
	.byte		        An3 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 021   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N18   , Gn4 
	.byte	W18
	.byte		N30   , Fs4 
	.byte	W30
@ 022   ----------------------------------------
	.byte		N06   , Bn3 
	.byte	W18
	.byte		        Dn4 
	.byte	W18
	.byte		        An3 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 023   ----------------------------------------
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , An4 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N18   , Bn4 
	.byte	W18
	.byte		N30   , An4 
	.byte	W30
@ 024   ----------------------------------------
	.byte		N06   , Bn3 
	.byte	W18
	.byte		        Dn4 
	.byte	W18
	.byte		        An3 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
@ 025   ----------------------------------------
	.byte		N18   , Bn4 
	.byte	W18
	.byte		        An4 , v112
	.byte	W18
	.byte		        En4 , v120
	.byte	W18
	.byte		        Dn4 
	.byte	W18
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 026   ----------------------------------------
	.byte		        En4 
	.byte	W18
	.byte		        Fs4 
	.byte	W18
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 027   ----------------------------------------
	.byte		        En4 
	.byte	W18
	.byte		        Fs4 
	.byte	W18
	.byte		N18   , Bn4 
	.byte	W18
	.byte		        An4 
	.byte	W18
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
@ 028   ----------------------------------------
	.byte		N48   , Fs4 , v104
	.byte	W48
	.byte		N18   , Dn4 
	.byte	W18
	.byte		        Bn3 
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
@ 029   ----------------------------------------
	.byte		N36   , An3 
	.byte	W54
	.byte		N06   , Gn3 , v076
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 , v080
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
@ 030   ----------------------------------------
	.byte	W06
	.byte		        An3 , v084
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 , v088
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 , v092
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        Dn4 
	.byte	W06
@ 031   ----------------------------------------
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 , v100
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 , v104
	.byte	W06
	.byte		N12   , An2 , v120
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 032   ----------------------------------------
	.byte		N78   , Fs4 , v084
	.byte	W24
	.byte		MOD   , 6
	.byte	W54
	.byte		        0
	.byte	W18
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte		N12   , Bn0 , v124
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W12
@ 035   ----------------------------------------
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
@ 036   ----------------------------------------
	.byte		N12   , En0 
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N01   , Dn4 , v056
	.byte	W01
	.byte		N10   , En4 , v088
	.byte	W56
	.byte	W03
@ 037   ----------------------------------------
	.byte		VOICE , 88
	.byte	W12
	.byte		N09   , Bn4 , v104
	.byte	W12
	.byte		N01   , Fn5 , v060
	.byte	W01
	.byte		N07   , Fs5 , v104
	.byte	W11
	.byte		N09   , Dn5 
	.byte	W12
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N10   
	.byte	W12
	.byte		BEND  , c_v-1
	.byte		        c_v-2
	.byte		        c_v-3
	.byte		N24   
	.byte	W01
	.byte		BEND  , c_v-3
	.byte		        c_v-4
	.byte		        c_v-5
	.byte		        c_v-5
	.byte	W01
	.byte		        c_v-6
	.byte		        c_v-7
	.byte		        c_v-7
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-9
	.byte		        c_v-9
	.byte		        c_v-10
	.byte		        c_v-11
	.byte	W01
	.byte		        c_v-11
	.byte		        c_v-12
	.byte		        c_v-13
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v-14
	.byte		        c_v-15
	.byte		        c_v-15
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-17
	.byte		        c_v-18
	.byte		        c_v-18
	.byte		        c_v-19
	.byte	W01
	.byte		        c_v-20
	.byte		        c_v-20
	.byte		        c_v-21
	.byte		        c_v-22
	.byte	W01
	.byte		        c_v-22
	.byte		        c_v-23
	.byte		        c_v-24
	.byte		        c_v-24
	.byte	W01
	.byte		        c_v-25
	.byte		        c_v-26
	.byte		        c_v-26
	.byte		        c_v-27
	.byte	W01
	.byte		        c_v-28
	.byte		        c_v-28
	.byte		        c_v-29
	.byte		        c_v-30
	.byte	W01
	.byte		        c_v-30
	.byte		        c_v-31
	.byte		        c_v-32
	.byte		        c_v-32
	.byte	W01
	.byte		        c_v-33
	.byte		        c_v-34
	.byte		        c_v-35
	.byte		        c_v-35
	.byte	W01
	.byte		        c_v-36
	.byte		        c_v-37
	.byte		        c_v-37
	.byte		        c_v-38
	.byte	W01
	.byte		        c_v-39
	.byte		        c_v-39
	.byte		        c_v-40
	.byte		        c_v-41
	.byte	W01
	.byte		        c_v-41
	.byte		        c_v-42
	.byte		        c_v-43
	.byte		        c_v-43
	.byte	W01
	.byte		        c_v-44
	.byte		        c_v-45
	.byte		        c_v-45
	.byte		        c_v-46
	.byte	W01
	.byte		        c_v-47
	.byte		        c_v-47
	.byte		        c_v-48
	.byte		        c_v-49
	.byte	W01
	.byte		        c_v-50
	.byte		        c_v-50
	.byte		        c_v-51
	.byte		        c_v-52
	.byte	W01
	.byte		        c_v-52
	.byte		        c_v-53
	.byte		        c_v-54
	.byte		        c_v-54
	.byte	W01
	.byte		        c_v-55
	.byte		        c_v-56
	.byte		        c_v-56
	.byte		        c_v-57
	.byte	W01
	.byte		        c_v-58
	.byte		        c_v-58
	.byte		        c_v-59
	.byte		        c_v-60
	.byte	W01
	.byte		        c_v-60
	.byte		        c_v-61
	.byte		        c_v-62
	.byte		        c_v-62
	.byte	W01
	.byte		        c_v-63
	.byte		        c_v-64
	.byte		        c_v-64
	.byte		        c_v-64
	.byte	W01
@ 038   ----------------------------------------
	.byte		        c_v+0
	.byte		N10   , En1 , v088
	.byte	W36
	.byte	W01
	.byte		N10   
	.byte	W11
	.byte		MOD   , 5
	.byte		N48   , Fs5 , v100
	.byte	W44
	.byte	W03
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W01
	.byte	GOTO
	 .word	mus_oe_vs_wild_6_B1
mus_oe_vs_wild_6_B2:
@ 039   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		MOD   , 5
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		MOD   , 5
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte	FINE

@**************** Track 7 (Midi-Chn.10) ****************@

mus_oe_vs_wild_7:
	.byte	KEYSH , mus_oe_vs_wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte	W48
	.byte		N06   , Dn1 , v088
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte		N12   , En2 
	.byte	W12
@ 001   ----------------------------------------
mus_oe_vs_wild_7_001:
	.byte		N12   , Cn1 , v088
	.byte		N48   , An2 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 , v080
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
mus_oe_vs_wild_7_002:
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Cn1 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 , v088
	.byte	W06
	.byte		        Dn1 , v068
	.byte	W06
	.byte		        Dn1 , v084
	.byte		N12   , En2 , v088
	.byte	W06
	.byte		N06   , Dn1 , v076
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
	.byte		N12   , Cn1 , v088
	.byte		N42   , An2 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 , v080
	.byte	W06
	.byte		        En2 , v088
	.byte	W30
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v068
	.byte	W06
	.byte		N03   , Dn1 , v084
	.byte	W03
	.byte		        Dn1 , v076
	.byte	W03
	.byte		        Dn1 , v084
	.byte	W03
	.byte		        Dn1 , v080
	.byte	W03
mus_oe_vs_wild_7_B1:
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_001
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_002
@ 006   ----------------------------------------
mus_oe_vs_wild_7_006:
	.byte		N12   , Cn1 , v088
	.byte		N48   , An2 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 , v080
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
mus_oe_vs_wild_7_007:
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Cn1 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 , v088
	.byte	W06
	.byte		        Dn1 , v068
	.byte	W06
	.byte		N03   , Dn1 , v084
	.byte	W03
	.byte		        Dn1 , v076
	.byte	W03
	.byte		        Dn1 , v084
	.byte	W03
	.byte		        Dn1 , v080
	.byte	W03
	.byte	PEND
@ 008   ----------------------------------------
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		        Dn1 
	.byte		N12   , En2 
	.byte	W12
@ 009   ----------------------------------------
	.byte		        Cn1 
	.byte		N48   , An2 
	.byte	W12
	.byte		N06   , Ds1 , v072
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Ds1 , v072
	.byte	W06
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        Fn1 , v076
	.byte	W03
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Ds1 , v072
	.byte	W06
	.byte		        Cn1 , v080
	.byte		N06   , Ds1 , v072
	.byte	W06
	.byte		        Dn1 , v088
	.byte	W06
	.byte		        Dn1 , v068
	.byte	W06
	.byte		N03   , Dn1 , v084
	.byte		N06   , Ds1 , v072
	.byte	W03
	.byte		N03   , Dn1 , v076
	.byte	W03
	.byte		        Dn1 , v084
	.byte	W03
	.byte		        Dn1 , v080
	.byte	W03
@ 010   ----------------------------------------
	.byte		N12   , Cn1 , v088
	.byte		N06   , An2 
	.byte	W36
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte		N06   , En2 
	.byte	W36
	.byte		N03   , Dn1 , v084
	.byte	W03
	.byte		        Dn1 , v076
	.byte	W03
	.byte		        Dn1 , v084
	.byte	W03
	.byte		        Dn1 , v080
	.byte	W03
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_001
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_002
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_006
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_007
@ 015   ----------------------------------------
	.byte		N12   , Cn1 , v088
	.byte		N48   , An2 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte		N36   , An2 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W06
	.byte		N03   , Gn1 , v076
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Dn1 , v088
	.byte		N12   , En2 
	.byte	W06
	.byte		N06   , Cn1 , v080
	.byte	W06
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_001
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_002
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_006
@ 019   ----------------------------------------
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Cn1 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 , v088
	.byte	W06
	.byte		        Dn1 , v068
	.byte	W06
	.byte		N03   , Dn1 , v084
	.byte		N12   , En2 , v088
	.byte	W03
	.byte		N03   , Dn1 , v076
	.byte	W03
	.byte		        Dn1 , v084
	.byte	W03
	.byte		        Dn1 , v080
	.byte	W03
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_001
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_002
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_006
@ 023   ----------------------------------------
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N12   , Cn1 , v088
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Dn1 , v088
	.byte		N18   , En2 
	.byte	W06
	.byte		N06   , Cn1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 , v088
	.byte		N18   , Gn2 
	.byte	W12
	.byte		N03   , Dn1 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 , v088
	.byte		N12   , En2 
	.byte	W06
	.byte		N06   , Cn1 , v080
	.byte	W06
@ 024   ----------------------------------------
mus_oe_vs_wild_7_024:
	.byte		N12   , Dn1 , v080
	.byte		N48   , An2 , v088
	.byte	W12
	.byte		N06   , Cn1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 025   ----------------------------------------
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W03
	.byte		        Cn1 , v068
	.byte	W03
	.byte		N06   , Dn1 , v080
	.byte		N12   , En2 , v088
	.byte	W06
	.byte		N06   , Cn1 , v080
	.byte	W06
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_7_024
@ 027   ----------------------------------------
	.byte		N12   , Dn1 , v080
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Dn1 , v076
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 , v080
	.byte		N12   , En2 , v088
	.byte	W06
	.byte		N06   , Cn1 , v080
	.byte	W06
@ 028   ----------------------------------------
	.byte		N12   , Dn1 
	.byte		N48   , An2 , v088
	.byte	W12
	.byte		N06   , Cn1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
@ 029   ----------------------------------------
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W03
	.byte		        Cn1 , v068
	.byte	W03
	.byte		N06   , Dn1 , v080
	.byte	W06
	.byte		        Cn1 
	.byte	W06
@ 030   ----------------------------------------
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N03   , Dn1 
	.byte	W03
	.byte		N03   
	.byte	W03
@ 031   ----------------------------------------
	.byte		N12   
	.byte	W48
	.byte		N06   , Dn1 , v088
	.byte	W06
	.byte		N03   , Gn1 , v076
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Dn1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 , v088
	.byte	W06
	.byte		N03   , Dn1 , v076
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 , v088
	.byte		N12   , En2 
	.byte	W06
	.byte		N06   , Dn1 , v080
	.byte	W06
@ 032   ----------------------------------------
	.byte		        Cn1 
	.byte		N48   , An2 , v088
	.byte	W78
	.byte		N06   , Cn1 , v080
	.byte	W06
	.byte		        Dn1 , v088
	.byte	W12
@ 033   ----------------------------------------
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte		N12   
	.byte	W18
	.byte		N06   , Cn1 , v080
	.byte	W06
	.byte		N12   , Dn1 , v088
	.byte	W24
	.byte		N12   
	.byte		N12   , En2 
	.byte	W12
@ 034   ----------------------------------------
	.byte		        Cn1 
	.byte		N48   , An2 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W18
	.byte		N06   , Cn1 , v080
	.byte	W06
	.byte		N12   , Dn1 , v088
	.byte	W18
	.byte		N06   , Cn1 , v080
	.byte	W06
	.byte		N12   , Dn1 , v088
	.byte	W18
	.byte		N03   , Cn1 , v080
	.byte	W03
	.byte		        Cn1 , v068
	.byte	W03
	.byte		N12   , Dn1 , v088
	.byte	W12
@ 035   ----------------------------------------
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W18
	.byte		N06   , Cn1 , v080
	.byte	W06
	.byte		N12   , Dn1 , v088
	.byte	W18
	.byte		N06   , Cn1 , v080
	.byte	W06
	.byte		N12   , Dn1 , v088
	.byte	W18
	.byte		N03   , Cn1 , v080
	.byte	W03
	.byte		        Cn1 , v068
	.byte	W03
	.byte		N12   , Dn1 , v088
	.byte	W12
@ 036   ----------------------------------------
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Dn1 
	.byte		N24   , En2 
	.byte	W24
	.byte		N12   , Cn1 
	.byte	W24
	.byte		        Dn1 , v080
	.byte	W12
	.byte		        Cn1 , v088
	.byte		N12   , En2 
	.byte	W12
@ 037   ----------------------------------------
	.byte		        Cn1 
	.byte		N48   , An2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Dn1 , v088
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
@ 038   ----------------------------------------
	.byte		N12   
	.byte		N12   , An2 
	.byte	W36
	.byte		N03   , Dn1 
	.byte		N12   , En2 
	.byte	W03
	.byte		N03   , Dn1 , v076
	.byte	W03
	.byte		        Dn1 , v084
	.byte	W03
	.byte		        Dn1 , v080
	.byte	W03
	.byte		N12   , Cn1 , v088
	.byte		N12   , An2 
	.byte	W18
	.byte		N03   , Dn1 
	.byte	W03
	.byte		        Dn1 , v076
	.byte	W03
	.byte		N06   , Dn1 , v088
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , Dn1 
	.byte		N11   , En2 
	.byte	W03
	.byte		N03   , Dn1 , v076
	.byte	W03
	.byte		        Dn1 , v084
	.byte	W03
	.byte		N02   , Dn1 , v080
	.byte	W03
	.byte	GOTO
	 .word	mus_oe_vs_wild_7_B1
mus_oe_vs_wild_7_B2:
@ 039   ----------------------------------------
	.byte		VOICE , 0
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte	FINE

@**************** Track 8 (Midi-Chn.12) ****************@

mus_oe_vs_wild_8:
	.byte	KEYSH , mus_oe_vs_wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
mus_oe_vs_wild_8_B1:
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
mus_oe_vs_wild_8_006:
	.byte	W12
	.byte		N12   , An4 , v064
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_8_006
@ 012   ----------------------------------------
mus_oe_vs_wild_8_012:
	.byte		N12   , An4 , v064
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte	PEND
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_8_006
@ 014   ----------------------------------------
	.byte		N12   , An4 , v064
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
@ 015   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_8_006
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_8_012
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_8_006
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_8_012
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_8_006
@ 021   ----------------------------------------
	.byte		N12   , An4 , v064
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_8_006
@ 023   ----------------------------------------
	.byte		N12   , An4 , v064
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W48
	.byte	W03
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
mus_oe_vs_wild_8_028:
	.byte		N03   , An4 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PEND
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_8_028
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_8_028
@ 031   ----------------------------------------
	.byte		N03   , An4 , v064
	.byte	W48
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
@ 032   ----------------------------------------
	.byte	W72
	.byte		        An4 , v060
	.byte	W03
	.byte		N03   
	.byte	W21
@ 033   ----------------------------------------
	.byte	W30
	.byte		N04   
	.byte	W42
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W18
@ 034   ----------------------------------------
mus_oe_vs_wild_8_034:
	.byte		N03   , An4 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_wild_8_034
@ 036   ----------------------------------------
	.byte	W66
	.byte		N03   , An4 , v064
	.byte	W03
	.byte		N03   
	.byte	W24
	.byte	W03
@ 037   ----------------------------------------
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
@ 038   ----------------------------------------
	.byte	W96
	.byte	GOTO
	 .word	mus_oe_vs_wild_8_B1
mus_oe_vs_wild_8_B2:
@ 039   ----------------------------------------
	.byte		VOICE , 127
	.byte		        127
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*mus_oe_vs_wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*mus_oe_vs_wild_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		        c_v+0
	.byte	FINE

@******************************************************@
	.align	2

mus_oe_vs_wild:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_oe_vs_wild_pri	@ Priority
	.byte	mus_oe_vs_wild_rev	@ Reverb.

	.word	mus_oe_vs_wild_grp

	.word	mus_oe_vs_wild_1
	.word	mus_oe_vs_wild_2
	.word	mus_oe_vs_wild_3
	.word	mus_oe_vs_wild_4
	.word	mus_oe_vs_wild_5
	.word	mus_oe_vs_wild_6
	.word	mus_oe_vs_wild_7
	.word	mus_oe_vs_wild_8

	.end
