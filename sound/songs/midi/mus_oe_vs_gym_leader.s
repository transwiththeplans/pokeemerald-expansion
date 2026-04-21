	.include "MPlayDef.s"

	.equ	mus_oe_vs_gym_leader_grp, voicegroup_vs_gym_leader
	.equ	mus_oe_vs_gym_leader_pri, 1
	.equ	mus_oe_vs_gym_leader_rev, reverb_set+50
	.equ	mus_oe_vs_gym_leader_mvl, 100
	.equ	mus_oe_vs_gym_leader_key, 0
	.equ	mus_oe_vs_gym_leader_tbs, 1
	.equ	mus_oe_vs_gym_leader_exg, 1
	.equ	mus_oe_vs_gym_leader_cmp, 1

	.section .rodata
	.global	mus_oe_vs_gym_leader
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_oe_vs_gym_leader_1:
	.byte	KEYSH , mus_oe_vs_gym_leader_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 194*mus_oe_vs_gym_leader_tbs/2
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 99*mus_oe_vs_gym_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		N05   , Gn3 , v080
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
@ 001   ----------------------------------------
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
@ 002   ----------------------------------------
mus_oe_vs_gym_leader_1_002:
	.byte		VOICE , 45
	.byte		N11   , Cn4 , v127
	.byte	W36
	.byte		        Cs4 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte	PEND
@ 003   ----------------------------------------
mus_oe_vs_gym_leader_1_003:
	.byte		N11   , Gn3 , v127
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N23   , Cs3 
	.byte	W24
	.byte	PEND
@ 004   ----------------------------------------
mus_oe_vs_gym_leader_1_004:
	.byte		N11   , Cn4 , v127
	.byte	W36
	.byte		        Cs4 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
	.byte		        Gn3 
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N23   , Cs4 
	.byte	W24
mus_oe_vs_gym_leader_1_B1:
@ 006   ----------------------------------------
	.byte		N11   , Cn5 , v127
	.byte	W12
	.byte		        Cn5 , v068
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cs5 , v127
	.byte	W12
	.byte		        Cs5 , v068
	.byte	W12
	.byte		        Cs5 , v048
	.byte	W12
	.byte		        Cn4 , v127
	.byte	W12
	.byte		        Cn4 , v068
	.byte	W12
@ 007   ----------------------------------------
	.byte		        Gn4 , v127
	.byte	W12
	.byte		        Gn4 , v068
	.byte	W12
	.byte		        Gn4 , v048
	.byte	W12
	.byte		        Gs4 , v127
	.byte	W12
	.byte		        Gs4 , v068
	.byte	W12
	.byte		        Gs4 , v048
	.byte	W12
	.byte		N23   , Cs4 , v127
	.byte	W24
@ 008   ----------------------------------------
	.byte		N11   , Cn5 
	.byte	W12
	.byte		        Cn5 , v068
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cs5 , v127
	.byte	W12
	.byte		        Cs5 , v068
	.byte	W12
	.byte		        Cs5 , v048
	.byte	W12
	.byte		N23   , Gn4 , v127
	.byte	W24
@ 009   ----------------------------------------
	.byte		N11   , Cn5 
	.byte	W12
	.byte		        Cn5 , v068
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cs5 , v127
	.byte	W12
	.byte		        Cs5 , v068
	.byte	W12
	.byte		        Cs5 , v048
	.byte	W12
	.byte		N23   , Ds5 , v127
	.byte	W24
@ 010   ----------------------------------------
	.byte		VOICE , 48
	.byte		N44   , Cn4 , v076, gtp3
	.byte	W48
	.byte		        As3 , v076, gtp3
	.byte	W48
@ 011   ----------------------------------------
	.byte		N32   , Dn4 , v076, gtp3
	.byte	W36
	.byte		N11   , Gn3 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 012   ----------------------------------------
	.byte		N68   , En4 , v076, gtp3
	.byte	W72
	.byte		N11   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte		N52   , Gn3 , v076, gtp1
	.byte	W60
@ 014   ----------------------------------------
	.byte		N44   , Fn4 , v064, gtp3
	.byte	W48
	.byte		        En4 , v064, gtp3
	.byte	W48
@ 015   ----------------------------------------
	.byte		N23   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N32   , Cn4 , v064, gtp3
	.byte	W36
	.byte		N23   , Dn4 
	.byte	W24
	.byte		N44   , Cn4 , v064, gtp3
	.byte	W36
@ 017   ----------------------------------------
	.byte	W12
	.byte		N23   , En3 
	.byte	W24
	.byte		N11   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N32   , Cn4 , v064, gtp3
	.byte	W36
@ 018   ----------------------------------------
mus_oe_vs_gym_leader_1_018:
	.byte		N44   , As4 , v100, gtp3
	.byte	W48
	.byte		        An4 , v100, gtp3
	.byte	W48
	.byte	PEND
@ 019   ----------------------------------------
mus_oe_vs_gym_leader_1_019:
	.byte		N23   , As4 , v100
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte	PEND
@ 020   ----------------------------------------
	.byte		N68   , En5 , v100, gtp3
	.byte	W72
	.byte		N23   , Dn5 
	.byte	W24
@ 021   ----------------------------------------
	.byte		N88   , Cn5 , v100, gtp1
	.byte	W96
@ 022   ----------------------------------------
	.byte		N44   , Cn4 , v124, gtp3
	.byte	W48
	.byte		        As3 , v124, gtp3
	.byte	W48
@ 023   ----------------------------------------
	.byte		N32   , Dn4 , v124, gtp3
	.byte	W36
	.byte		N11   , Gn3 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N68   , En4 , v124, gtp3
	.byte	W72
	.byte		N11   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
@ 025   ----------------------------------------
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte		N52   , Cn4 , v124, gtp1
	.byte	W60
@ 026   ----------------------------------------
	.byte		N44   , Dn3 , v096, gtp3
	.byte	W48
	.byte		        Cn3 , v096, gtp3
	.byte	W48
@ 027   ----------------------------------------
	.byte		N23   , As2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        An2 
	.byte	W24
@ 028   ----------------------------------------
	.byte		N68   , Gn2 , v096, gtp3
	.byte	W72
	.byte		N23   , En2 
	.byte	W24
@ 029   ----------------------------------------
	.byte		N68   , Cn3 , v096, gtp3
	.byte	W72
	.byte		N11   
	.byte	W24
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_1_018
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_1_019
@ 032   ----------------------------------------
	.byte		N68   , En5 , v100, gtp3
	.byte	W72
	.byte		N23   , Cn5 
	.byte	W24
@ 033   ----------------------------------------
	.byte		N80   , En5 , v100, gtp3
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
	.byte		VOICE , 56
	.byte		VOL   , 127*mus_oe_vs_gym_leader_mvl/mxv
	.byte		N02   , Gs3 , v076
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N05   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N05   
	.byte	W12
	.byte		N02   , Cs4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N05   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N05   
	.byte	W12
@ 039   ----------------------------------------
	.byte		N02   , As3 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N05   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N05   
	.byte	W12
	.byte		N02   , Ds4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N05   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N05   
	.byte	W12
@ 040   ----------------------------------------
	.byte		N92   , Cn4 , v088, gtp3
	.byte	W96
@ 041   ----------------------------------------
	.byte		N68   , En4 , v080, gtp3
	.byte	W72
	.byte		N11   , Gn4 , v100
	.byte	W12
	.byte		        Fn4 
	.byte	W12
@ 042   ----------------------------------------
	.byte		N92   , Gs4 , v100, gtp3
	.byte	W96
@ 043   ----------------------------------------
	.byte		        As4 , v100, gtp3
	.byte	W96
@ 044   ----------------------------------------
	.byte		TIE   , Gn4 
	.byte	W96
@ 045   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		EOT   
	.byte	W01
	.byte		N11   , Gn4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
@ 046   ----------------------------------------
	.byte		N92   , Gs4 , v112, gtp3
	.byte	W96
@ 047   ----------------------------------------
	.byte		        As4 , v112, gtp3
	.byte	W96
@ 048   ----------------------------------------
	.byte		VOICE , 48
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		TIE   , Fn4 , v076
	.byte	W96
@ 049   ----------------------------------------
	.byte		VOL   , 98*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        96*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        94*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        92*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
@ 050   ----------------------------------------
	.byte		        90*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        88*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        85*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        83*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
@ 051   ----------------------------------------
	.byte		        80*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        78*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        75*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        73*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
@ 052   ----------------------------------------
	.byte		        71*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        69*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        67*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        65*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
@ 053   ----------------------------------------
	.byte		        61*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        58*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        52*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W24
	.byte		        49*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W23
	.byte		EOT   
	.byte	W01
@ 054   ----------------------------------------
	.byte		VOL   , 99*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte		N92   , En3 , v056, gtp3
	.byte	W96
@ 061   ----------------------------------------
	.byte		        As2 , v084, gtp3
	.byte	W96
@ 062   ----------------------------------------
	.byte		        Cn3 , v100, gtp3
	.byte	W96
@ 063   ----------------------------------------
	.byte		N40   , As2 , v100, gtp1
	.byte	W42
	.byte		N05   , Cn3 
	.byte	W06
	.byte		N44   , Dn3 , v100, gtp3
	.byte	W48
@ 064   ----------------------------------------
	.byte		N92   , Gn2 , v100, gtp3
	.byte	W96
@ 065   ----------------------------------------
	.byte		        Cn3 , v100, gtp3
	.byte	W96
@ 066   ----------------------------------------
	.byte		        Cs3 , v100, gtp3
	.byte	W96
@ 067   ----------------------------------------
	.byte		N44   , As2 , v100, gtp3
	.byte	W48
	.byte		N32   , Cs3 , v100, gtp3
	.byte	W36
	.byte		N11   , En3 
	.byte	W12
@ 068   ----------------------------------------
	.byte		N92   , Cn3 , v100, gtp3
	.byte	W96
@ 069   ----------------------------------------
	.byte		        En3 , v100, gtp3
	.byte	W96
@ 070   ----------------------------------------
	.byte		TIE   , Fn3 , v092
	.byte	W12
	.byte		VOL   , 98*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W12
	.byte		        94*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W12
	.byte		        91*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W12
	.byte		        87*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W12
	.byte		        85*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W12
	.byte		        82*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W12
	.byte		        79*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W12
@ 071   ----------------------------------------
	.byte		        74*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W12
	.byte		        72*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W12
	.byte		        68*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W12
	.byte		        67*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W12
	.byte		        65*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W44
	.byte	W03
	.byte		EOT   
	.byte	W01
@ 072   ----------------------------------------
	.byte		TIE   , Cn2 
	.byte	W96
@ 073   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		EOT   
	.byte	W01
@ 074   ----------------------------------------
	.byte	W48
	.byte		VOL   , 99*mus_oe_vs_gym_leader_mvl/mxv
	.byte		N44   , Gs2 , v100, gtp3
	.byte	W48
@ 075   ----------------------------------------
	.byte		        Cs3 , v100, gtp3
	.byte	W48
	.byte		        Fn3 , v100, gtp3
	.byte	W48
@ 076   ----------------------------------------
	.byte		N80   , Gn3 , v100, gtp3
	.byte	W96
@ 077   ----------------------------------------
	.byte		N92   , Gn1 , v060, gtp3
	.byte	W96
@ 078   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 112*mus_oe_vs_gym_leader_mvl/mxv
	.byte		N44   , Gn4 , v127, gtp3
	.byte	W48
	.byte		        Cn4 , v127, gtp3
	.byte	W48
@ 079   ----------------------------------------
	.byte		N23   , Fn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
@ 080   ----------------------------------------
	.byte		N64   , Cn4 , v127, gtp1
	.byte	W72
	.byte		N11   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
@ 081   ----------------------------------------
	.byte		N44   , Cn4 , v127, gtp3
	.byte	W48
	.byte		        Dn4 , v127, gtp3
	.byte	W48
@ 082   ----------------------------------------
	.byte		        En4 , v127, gtp3
	.byte	W48
	.byte		        Dn4 , v127, gtp3
	.byte	W48
@ 083   ----------------------------------------
	.byte		N23   , Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
@ 084   ----------------------------------------
	.byte		N05   , Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		TIE   , En4 
	.byte	W72
@ 085   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		EOT   
	.byte	W24
	.byte	W01
@ 086   ----------------------------------------
	.byte		VOICE , 48
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		N44   , En4 , v100, gtp3
	.byte	W48
	.byte		        Dn4 , v100, gtp3
	.byte	W48
@ 087   ----------------------------------------
	.byte		N23   , Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
@ 088   ----------------------------------------
	.byte		N05   , Ds4 
	.byte	W12
	.byte		N08   , Dn4 
	.byte	W12
	.byte		N44   , Cn4 
	.byte	W48
	.byte		N23   
	.byte	W24
@ 089   ----------------------------------------
	.byte		N92   , Dn4 , v100, gtp3
	.byte	W96
@ 090   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_1_002
@ 091   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_1_003
@ 092   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_1_004
@ 093   ----------------------------------------
	.byte		N11   , Gn3 , v127
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N23   , Cs4 
	.byte	W23
	.byte		VOL   , 99*mus_oe_vs_gym_leader_mvl/mxv
	.byte	W01
	.byte	GOTO
	 .word	mus_oe_vs_gym_leader_1_B1
mus_oe_vs_gym_leader_1_B2:
@ 094   ----------------------------------------
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 99*mus_oe_vs_gym_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_oe_vs_gym_leader_2:
	.byte	KEYSH , mus_oe_vs_gym_leader_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 33
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N23   , Cn2 , v108
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Cs1 
	.byte	W24
@ 001   ----------------------------------------
	.byte		        Gs1 
	.byte	W24
	.byte		N11   , As1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
@ 002   ----------------------------------------
mus_oe_vs_gym_leader_2_002:
	.byte		N11   , Cn1 , v108
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
mus_oe_vs_gym_leader_2_003:
	.byte		N11   , Cn1 , v108
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_002
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_003
mus_oe_vs_gym_leader_2_B1:
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_003
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_002
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_003
@ 010   ----------------------------------------
mus_oe_vs_gym_leader_2_010:
	.byte		N11   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
@ 012   ----------------------------------------
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
@ 014   ----------------------------------------
mus_oe_vs_gym_leader_2_014:
	.byte		N11   , As0 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
@ 015   ----------------------------------------
mus_oe_vs_gym_leader_2_015:
	.byte		N11   , As0 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PEND
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 017   ----------------------------------------
	.byte		N11   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 021   ----------------------------------------
mus_oe_vs_gym_leader_2_021:
	.byte		N11   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 025   ----------------------------------------
	.byte		N11   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_015
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 029   ----------------------------------------
	.byte		N11   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 032   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 033   ----------------------------------------
	.byte		N11   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 038   ----------------------------------------
mus_oe_vs_gym_leader_2_038:
	.byte		N11   , Cs1 , v108
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
@ 039   ----------------------------------------
mus_oe_vs_gym_leader_2_039:
	.byte		N11   , Ds1 , v108
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 041   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 042   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_038
@ 043   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_039
@ 044   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 045   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 046   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_038
@ 047   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_039
@ 048   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 049   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 050   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 051   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 052   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 053   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 054   ----------------------------------------
mus_oe_vs_gym_leader_2_054:
	.byte		N11   , An0 , v108
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	PEND
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_054
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_054
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_054
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_054
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 065   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 066   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 067   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_021
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_038
@ 071   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_038
@ 072   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 073   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 074   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_038
@ 075   ----------------------------------------
	.byte		N11   , Cs1 , v108
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
@ 076   ----------------------------------------
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
@ 077   ----------------------------------------
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
@ 078   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 079   ----------------------------------------
	.byte		N11   , Cn1 , v108
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
@ 080   ----------------------------------------
	.byte		        Cn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
@ 081   ----------------------------------------
	.byte		        Cn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
@ 082   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 083   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 084   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 085   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_010
@ 086   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 087   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 088   ----------------------------------------
	.byte		N11   , Gs0 , v108
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
@ 089   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_014
@ 090   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_002
@ 091   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_003
@ 092   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_002
@ 093   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_2_003
	.byte	GOTO
	 .word	mus_oe_vs_gym_leader_2_B1
mus_oe_vs_gym_leader_2_B2:
@ 094   ----------------------------------------
	.byte		VOICE , 33
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

mus_oe_vs_gym_leader_3:
	.byte	KEYSH , mus_oe_vs_gym_leader_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
mus_oe_vs_gym_leader_3_002:
	.byte		N44   , Cn4 , v080, gtp3
	.byte	W48
	.byte		        Cn3 , v080, gtp3
	.byte	W48
	.byte	PEND
@ 003   ----------------------------------------
mus_oe_vs_gym_leader_3_003:
	.byte		N44   , Gn3 , v080, gtp3
	.byte	W48
	.byte		        Cs3 , v080, gtp3
	.byte	W48
	.byte	PEND
@ 004   ----------------------------------------
mus_oe_vs_gym_leader_3_004:
	.byte		N44   , Cn4 , v080, gtp3
	.byte	W48
	.byte		        Gn4 , v080, gtp3
	.byte	W48
	.byte	PEND
@ 005   ----------------------------------------
mus_oe_vs_gym_leader_3_005:
	.byte		N44   , Cn5 , v080, gtp3
	.byte	W48
	.byte		        Cs4 
	.byte	W48
	.byte	PEND
mus_oe_vs_gym_leader_3_B1:
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_3_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_3_003
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_3_002
@ 009   ----------------------------------------
	.byte		N44   , Cs4 , v080, gtp3
	.byte	W48
	.byte		N23   , Ds3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
@ 010   ----------------------------------------
	.byte		N44   , Gn3 , v064, gtp3
	.byte	W48
	.byte		N40   , Fn3 , v064, gtp1
	.byte	W42
	.byte		N05   , Gs3 
	.byte	W06
@ 011   ----------------------------------------
	.byte		N32   , Gn3 , v064, gtp3
	.byte	W36
	.byte		N11   , Cn3 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 012   ----------------------------------------
	.byte		N32   , Gn3 , v064, gtp3
	.byte	W36
	.byte		        Cn4 , v064, gtp3
	.byte	W36
	.byte		N11   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
@ 013   ----------------------------------------
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W24
	.byte		N56   , Gn3 , v064, gtp3
	.byte	W60
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte		N44   , Dn4 , v088, gtp3
	.byte	W48
	.byte		        Cn4 , v088, gtp3
	.byte	W48
@ 019   ----------------------------------------
	.byte		        As3 , v088, gtp3
	.byte	W48
	.byte		        Dn4 , v088, gtp3
	.byte	W48
@ 020   ----------------------------------------
	.byte		N68   , En4 , v088, gtp3
	.byte	W72
	.byte		N23   , Dn4 
	.byte	W24
@ 021   ----------------------------------------
	.byte		N88   , Cn4 , v088, gtp1
	.byte	W96
@ 022   ----------------------------------------
	.byte		N32   , Cn3 , v088, gtp3
	.byte	W36
	.byte		        Fn3 , v088, gtp3
	.byte	W36
	.byte		N23   , En3 
	.byte	W24
@ 023   ----------------------------------------
	.byte		N32   , Fn3 , v088, gtp3
	.byte	W36
	.byte		N11   , Cn3 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N32   , Gn3 , v088, gtp3
	.byte	W36
	.byte		        Cn3 , v088, gtp3
	.byte	W36
	.byte		N11   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
@ 025   ----------------------------------------
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W24
	.byte		N56   , Gn3 , v088, gtp3
	.byte	W60
@ 026   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 127*mus_oe_vs_gym_leader_mvl/mxv
	.byte		N44   , As3 , v127, gtp3
	.byte	W48
	.byte		        An3 , v127, gtp3
	.byte	W48
@ 027   ----------------------------------------
	.byte		N23   , Gn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
@ 028   ----------------------------------------
	.byte		N68   , En3 , v127, gtp3
	.byte	W72
	.byte		N23   , Cn3 
	.byte	W24
@ 029   ----------------------------------------
	.byte		N68   , Gn3 , v127, gtp3
	.byte	W72
	.byte		N11   , En3 , v084
	.byte	W24
@ 030   ----------------------------------------
	.byte		VOICE , 60
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		N44   , Dn4 , v100, gtp3
	.byte	W48
	.byte		        Cn4 , v100, gtp3
	.byte	W48
@ 031   ----------------------------------------
	.byte		        As3 , v100, gtp3
	.byte	W48
	.byte		        Dn4 , v100, gtp3
	.byte	W48
@ 032   ----------------------------------------
	.byte		N68   , En4 , v100, gtp3
	.byte	W72
	.byte		N23   , Cn4 
	.byte	W24
@ 033   ----------------------------------------
	.byte		N88   , Gn4 , v100, gtp1
	.byte	W96
@ 034   ----------------------------------------
	.byte		N32   , Gn3 , v112, gtp3
	.byte	W36
	.byte		        Fn3 , v112, gtp3
	.byte	W36
	.byte		N23   , Gn3 
	.byte	W24
@ 035   ----------------------------------------
	.byte		N32   , An3 , v112, gtp3
	.byte	W36
	.byte		        Fn3 , v112, gtp3
	.byte	W36
	.byte		N23   , An3 
	.byte	W24
@ 036   ----------------------------------------
	.byte		TIE   , Gn3 
	.byte	W96
@ 037   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		EOT   
	.byte	W24
	.byte	W01
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte		TIE   , Cn3 , v127
	.byte	W96
@ 041   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		EOT   
	.byte	W01
	.byte		N11   
	.byte	W12
	.byte		        As2 
	.byte	W12
@ 042   ----------------------------------------
	.byte		N92   , Cs3 , v127, gtp3
	.byte	W96
@ 043   ----------------------------------------
	.byte		        Ds3 , v127, gtp3
	.byte	W96
@ 044   ----------------------------------------
	.byte		TIE   , Cn3 
	.byte	W96
@ 045   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		EOT   
	.byte	W01
	.byte		N11   , Cn3 , v100
	.byte	W12
	.byte		        As2 
	.byte	W12
@ 046   ----------------------------------------
	.byte		N92   , Cs3 , v100, gtp3
	.byte	W96
@ 047   ----------------------------------------
	.byte		        Ds3 , v100, gtp3
	.byte	W96
@ 048   ----------------------------------------
	.byte		TIE   , As2 
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		EOT   
	.byte	W01
@ 054   ----------------------------------------
	.byte		N92   , An2 , v104, gtp3
	.byte	W96
@ 055   ----------------------------------------
	.byte		N44   , Gn2 , v104, gtp3
	.byte	W48
	.byte		        Bn2 , v104, gtp3
	.byte	W48
@ 056   ----------------------------------------
	.byte		N92   , En2 , v104, gtp3
	.byte	W96
@ 057   ----------------------------------------
	.byte		        An2 , v104, gtp3
	.byte	W96
@ 058   ----------------------------------------
	.byte		        As2 , v104, gtp3
	.byte	W96
@ 059   ----------------------------------------
	.byte		N44   , Gn2 , v104, gtp3
	.byte	W48
	.byte		N32   , As2 , v104, gtp3
	.byte	W36
	.byte		N11   , Cs3 
	.byte	W12
@ 060   ----------------------------------------
	.byte		N92   , An2 , v104, gtp3
	.byte	W96
@ 061   ----------------------------------------
	.byte		        Dn3 , v104, gtp3
	.byte	W96
@ 062   ----------------------------------------
	.byte		        Gn2 , v100, gtp3
	.byte	W96
@ 063   ----------------------------------------
	.byte		N44   , Fn2 , v100, gtp3
	.byte	W48
	.byte		        Gn2 , v100, gtp3
	.byte	W48
@ 064   ----------------------------------------
	.byte		N92   , Cn2 , v112, gtp3
	.byte	W96
@ 065   ----------------------------------------
	.byte		        Gn2 , v100, gtp3
	.byte	W96
@ 066   ----------------------------------------
	.byte		        Gs2 , v100, gtp3
	.byte	W96
@ 067   ----------------------------------------
	.byte		N44   , Fn2 , v100, gtp3
	.byte	W48
	.byte		        Gs2 , v100, gtp3
	.byte	W48
@ 068   ----------------------------------------
	.byte		N92   , Gn2 , v100, gtp3
	.byte	W96
@ 069   ----------------------------------------
	.byte		        Cn3 , v100, gtp3
	.byte	W96
@ 070   ----------------------------------------
	.byte		        Cs3 , v100, gtp3
	.byte	W96
@ 071   ----------------------------------------
	.byte		N44   , Gs2 , v100, gtp3
	.byte	W48
	.byte		        Cs3 , v100, gtp3
	.byte	W48
@ 072   ----------------------------------------
	.byte		        En3 , v100, gtp3
	.byte	W48
	.byte		        Dn3 , v100, gtp3
	.byte	W48
@ 073   ----------------------------------------
	.byte		        Cn3 , v100, gtp3
	.byte	W48
	.byte		        Gn2 , v100, gtp3
	.byte	W48
@ 074   ----------------------------------------
	.byte		TIE   , Gs2 , v072
	.byte	W96
@ 075   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		EOT   
	.byte	W01
@ 076   ----------------------------------------
	.byte	W96
@ 077   ----------------------------------------
	.byte	W48
	.byte		VOICE , 48
	.byte	W12
	.byte		N05   , An2 , v052
	.byte	W06
	.byte		        Bn2 , v056
	.byte	W06
	.byte		        Cn3 , v064
	.byte	W06
	.byte		        Dn3 , v068
	.byte	W06
	.byte		        En3 , v072
	.byte	W06
	.byte		        Fn3 , v076
	.byte	W06
@ 078   ----------------------------------------
	.byte		N92   , Gn3 , v088, gtp3
	.byte	W96
@ 079   ----------------------------------------
	.byte		        As3 , v088, gtp3
	.byte	W96
@ 080   ----------------------------------------
	.byte		VOICE , 60
	.byte		N44   , Cn4 , v088, gtp3
	.byte	W48
	.byte		        Cn3 , v088, gtp3
	.byte	W48
@ 081   ----------------------------------------
	.byte		        Gs3 , v088, gtp3
	.byte	W48
	.byte		        Fn3 , v088, gtp3
	.byte	W48
@ 082   ----------------------------------------
	.byte		N80   , Cn4 , v080, gtp3
	.byte	W84
	.byte		N05   
	.byte	W06
	.byte		        Dn4 
	.byte	W06
@ 083   ----------------------------------------
	.byte		N23   , En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
@ 084   ----------------------------------------
	.byte		N05   , Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N44   , Cn4 , v080, gtp3
	.byte	W48
	.byte		N23   , Cn3 
	.byte	W24
@ 085   ----------------------------------------
	.byte		        Cn4 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
@ 086   ----------------------------------------
	.byte		N92   , Cn3 , v080, gtp3
	.byte	W96
@ 087   ----------------------------------------
	.byte		        Dn3 , v080, gtp3
	.byte	W96
@ 088   ----------------------------------------
	.byte		N05   , Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N44   , Cn3 , v080, gtp3
	.byte	W48
	.byte		VOICE , 56
	.byte		VOL   , 127*mus_oe_vs_gym_leader_mvl/mxv
	.byte		N05   , Gs4 , v127
	.byte	W12
	.byte		        Gn4 
	.byte	W12
@ 089   ----------------------------------------
	.byte		N44   , Fn4 , v127, gtp3
	.byte	W48
	.byte		        As4 , v127, gtp3
	.byte	W48
@ 090   ----------------------------------------
	.byte		VOICE , 60
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		N44   , Cn4 , v080, gtp3
	.byte	W48
	.byte		        Cn3 , v080, gtp3
	.byte	W48
@ 091   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_3_003
@ 092   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_3_004
@ 093   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_3_005
	.byte	GOTO
	 .word	mus_oe_vs_gym_leader_3_B1
mus_oe_vs_gym_leader_3_B2:
@ 094   ----------------------------------------
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

mus_oe_vs_gym_leader_4:
	.byte	KEYSH , mus_oe_vs_gym_leader_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 5
	.byte		VOL   , 72*mus_oe_vs_gym_leader_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N05   , Gn2 , v096
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W12
@ 001   ----------------------------------------
	.byte		        Fn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		N05   
	.byte	W12
	.byte		        Fs3 
	.byte	W12
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
mus_oe_vs_gym_leader_4_B1:
@ 006   ----------------------------------------
	.byte		N05   , Fn5 , v068
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
@ 007   ----------------------------------------
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
@ 008   ----------------------------------------
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
@ 009   ----------------------------------------
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte		N44   , Dn4 , v064, gtp3
	.byte	W48
	.byte		        Cn4 , v064, gtp3
	.byte	W48
@ 015   ----------------------------------------
	.byte		N23   , As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        An3 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N68   , Gn3 , v064, gtp3
	.byte	W72
	.byte		N23   , En3 
	.byte	W24
@ 017   ----------------------------------------
	.byte		N80   , Cn4 , v064, gtp3
	.byte	W96
@ 018   ----------------------------------------
	.byte		N44   , As4 , v127, gtp3
	.byte	W48
	.byte		        An4 , v127, gtp3
	.byte	W48
@ 019   ----------------------------------------
	.byte		N23   , As4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
@ 020   ----------------------------------------
	.byte		N68   , En5 , v127, gtp3
	.byte	W72
	.byte		N23   , Dn5 
	.byte	W24
@ 021   ----------------------------------------
	.byte		N88   , Cn5 , v127, gtp1
	.byte	W96
@ 022   ----------------------------------------
	.byte		N44   , Cn6 , v088, gtp3
	.byte	W48
	.byte		        As5 , v088, gtp3
	.byte	W48
@ 023   ----------------------------------------
	.byte		N32   , Dn6 , v088, gtp3
	.byte	W36
	.byte		N11   , Gn5 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        Dn6 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N68   , En6 , v088, gtp3
	.byte	W72
	.byte		N11   , Dn6 
	.byte	W12
	.byte		        En6 
	.byte	W12
@ 025   ----------------------------------------
	.byte		N05   , Fn6 , v068
	.byte	W06
	.byte		        En6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte		N32   , Cn4 , v076, gtp3
	.byte	W36
	.byte		        As3 , v076, gtp3
	.byte	W36
	.byte		N23   , Cn4 
	.byte	W24
@ 035   ----------------------------------------
	.byte		N32   , Dn4 , v076, gtp3
	.byte	W36
	.byte		        As3 , v076, gtp3
	.byte	W36
	.byte		N23   , Dn4 
	.byte	W24
@ 036   ----------------------------------------
	.byte		N11   , Gn4 , v060
	.byte	W48
	.byte		        Dn4 
	.byte	W48
@ 037   ----------------------------------------
	.byte		        Cn4 
	.byte	W48
	.byte		N02   , Cn4 , v080
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 038   ----------------------------------------
	.byte		N02   , Cs4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   , Fn4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 039   ----------------------------------------
	.byte		N02   , Ds4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   , Gn4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 040   ----------------------------------------
	.byte		N02   , Cn5 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   , En5 
	.byte	W12
@ 041   ----------------------------------------
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 042   ----------------------------------------
	.byte	W24
	.byte		N05   , Cn4 
	.byte	W12
	.byte		        Cn4 , v100
	.byte	W12
	.byte		        Cn4 , v080
	.byte	W12
	.byte		        Cn4 , v100
	.byte	W12
	.byte		        Cn4 , v080
	.byte	W12
	.byte		        Cn4 , v100
	.byte	W12
@ 043   ----------------------------------------
	.byte	W24
	.byte		        Ds4 , v080
	.byte	W12
	.byte		        Ds4 , v100
	.byte	W12
	.byte		        Ds4 , v080
	.byte	W12
	.byte		        Ds4 , v100
	.byte	W12
	.byte		        Ds4 , v080
	.byte	W12
	.byte		        Ds4 , v100
	.byte	W12
@ 044   ----------------------------------------
	.byte		PAN   , c_v+63
	.byte		N05   , Dn6 , v072
	.byte	W08
	.byte		        Cn6 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
@ 045   ----------------------------------------
	.byte		        Gn5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
@ 046   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte	W24
	.byte		N32   , Fn3 , v084, gtp3
	.byte	W36
	.byte		        Cs5 , v084, gtp3
	.byte	W36
@ 047   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		N23   , Ds5 
	.byte	W24
	.byte		N23   
	.byte	W24
	.byte		N11   , Gn5 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        As5 
	.byte	W12
@ 048   ----------------------------------------
	.byte		N32   , As5 , v084, gtp3
	.byte	W36
	.byte		N11   
	.byte	W12
	.byte		N05   , En5 , v072
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
@ 049   ----------------------------------------
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W84
@ 050   ----------------------------------------
	.byte		N08   , As3 , v100
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
@ 051   ----------------------------------------
	.byte		        Fn3 
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
@ 052   ----------------------------------------
	.byte		        Ds3 
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
@ 053   ----------------------------------------
	.byte		        Dn3 
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
@ 054   ----------------------------------------
mus_oe_vs_gym_leader_4_054:
	.byte		N08   , En3 , v072
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte	PEND
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_054
@ 056   ----------------------------------------
mus_oe_vs_gym_leader_4_056:
	.byte		N08   , An3 , v072
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte	PEND
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_056
@ 058   ----------------------------------------
mus_oe_vs_gym_leader_4_058:
	.byte		N08   , Fn3 , v072
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte	PEND
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_058
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_056
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_056
@ 062   ----------------------------------------
mus_oe_vs_gym_leader_4_062:
	.byte		N08   , Cn3 , v092
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte	PEND
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_062
@ 064   ----------------------------------------
mus_oe_vs_gym_leader_4_064:
	.byte		N08   , Cn4 , v092
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte	PEND
@ 065   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_064
@ 066   ----------------------------------------
mus_oe_vs_gym_leader_4_066:
	.byte		N08   , Cs3 , v092
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte	PEND
@ 067   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_066
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_064
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_064
@ 070   ----------------------------------------
mus_oe_vs_gym_leader_4_070:
	.byte		N11   , Cn4 , v104
	.byte	W36
	.byte		        Cs4 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte	PEND
@ 071   ----------------------------------------
mus_oe_vs_gym_leader_4_071:
	.byte		N11   , Gn3 , v104
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		        Cs3 
	.byte	W24
	.byte	PEND
@ 072   ----------------------------------------
	.byte		        Cn3 
	.byte	W36
	.byte		        Cs3 
	.byte	W36
	.byte		        Cn2 
	.byte	W24
@ 073   ----------------------------------------
	.byte		        Gn2 
	.byte	W36
	.byte		        Gs2 
	.byte	W36
	.byte		        Cs2 
	.byte	W24
@ 074   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_070
@ 075   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_4_071
@ 076   ----------------------------------------
	.byte	W12
	.byte		N08   , Cn4 , v092
	.byte	W12
	.byte		N17   
	.byte	W24
	.byte		N08   
	.byte	W12
	.byte		N17   
	.byte	W24
	.byte		N11   , Bn3 
	.byte	W12
@ 077   ----------------------------------------
	.byte	W12
	.byte		N02   , Bn2 , v080
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   , Dn3 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   , Gn3 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   , Bn3 
	.byte	W06
	.byte		N02   
	.byte	W06
@ 078   ----------------------------------------
	.byte		N44   , Gn4 , v064, gtp3
	.byte	W48
	.byte		        Cn4 , v064, gtp3
	.byte	W48
@ 079   ----------------------------------------
	.byte		N23   , Fn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N21   , Cn4 
	.byte	W24
@ 080   ----------------------------------------
	.byte		N23   
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N05   , An3 , v088
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N23   , Cn4 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
@ 081   ----------------------------------------
	.byte		PAN   , c_v+63
	.byte		N05   , Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N32   , Cn4 
	.byte	W36
	.byte		PAN   , c_v+0
	.byte		N05   
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
@ 082   ----------------------------------------
	.byte		N32   , Gn4 , v088, gtp3
	.byte	W36
	.byte		N02   , En4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N44   , Dn4 , v088, gtp3
	.byte	W48
@ 083   ----------------------------------------
	.byte		N23   , En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
@ 084   ----------------------------------------
	.byte		N05   , Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N68   , Cn4 , v088, gtp3
	.byte	W72
@ 085   ----------------------------------------
	.byte	W48
	.byte		N05   , Gn4 , v092
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
@ 086   ----------------------------------------
	.byte		N32   , As4 , v092, gtp3
	.byte	W36
	.byte		N05   , An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N32   , Fn4 , v092, gtp3
	.byte	W36
	.byte		N05   , En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
@ 087   ----------------------------------------
	.byte		N23   , Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
@ 088   ----------------------------------------
	.byte		N11   , Cn4 
	.byte	W12
	.byte		N08   , Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N11   , Gs4 
	.byte	W12
	.byte		N08   , Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
@ 089   ----------------------------------------
	.byte		N11   , As4 
	.byte	W12
	.byte		N08   , As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N11   , As4 
	.byte	W12
	.byte		N08   , Fn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
@ 090   ----------------------------------------
	.byte	W96
@ 091   ----------------------------------------
	.byte	W96
@ 092   ----------------------------------------
	.byte	W96
@ 093   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	GOTO
	 .word	mus_oe_vs_gym_leader_4_B1
mus_oe_vs_gym_leader_4_B2:
@ 094   ----------------------------------------
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

mus_oe_vs_gym_leader_5:
	.byte	KEYSH , mus_oe_vs_gym_leader_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 4
	.byte		VOL   , 72*mus_oe_vs_gym_leader_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N05   , Gn5 , v080
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn6 , v060
	.byte	W12
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn6 , v060
	.byte	W12
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn6 , v060
	.byte	W12
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn6 , v060
	.byte	W12
@ 001   ----------------------------------------
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn6 , v060
	.byte	W12
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn6 , v060
	.byte	W12
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn6 , v060
	.byte	W12
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn6 , v060
	.byte	W12
@ 002   ----------------------------------------
mus_oe_vs_gym_leader_5_002:
	.byte		N11   , Cn3 , v064
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
mus_oe_vs_gym_leader_5_003:
	.byte		N11   , Gn2 , v064
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
mus_oe_vs_gym_leader_5_004:
	.byte		N11   , Cn3 , v064
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
	.byte		        Cn4 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
mus_oe_vs_gym_leader_5_B1:
@ 006   ----------------------------------------
	.byte		N11   , Cn4 , v096
	.byte	W12
	.byte		        Cn4 , v068
	.byte	W12
	.byte		        Cn4 , v048
	.byte	W12
	.byte		        Cs4 , v096
	.byte	W12
	.byte		        Cs4 , v068
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W12
	.byte		        Cn3 , v096
	.byte	W12
	.byte		        Cn3 , v068
	.byte	W12
@ 007   ----------------------------------------
	.byte		        Gn3 , v096
	.byte	W12
	.byte		        Gn3 , v068
	.byte	W12
	.byte		        Gn3 , v048
	.byte	W12
	.byte		        Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v068
	.byte	W12
	.byte		        Gs3 , v048
	.byte	W12
	.byte		        Cs3 , v096
	.byte	W12
	.byte		        Cs3 , v068
	.byte	W12
@ 008   ----------------------------------------
	.byte		        Cn4 , v096
	.byte	W12
	.byte		        Cn4 , v068
	.byte	W12
	.byte		        Cn4 , v048
	.byte	W12
	.byte		        Cs4 , v096
	.byte	W12
	.byte		        Cs4 , v068
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W12
	.byte		        Gn3 , v096
	.byte	W12
	.byte		        Gn3 , v068
	.byte	W12
@ 009   ----------------------------------------
	.byte		        Cn4 , v096
	.byte	W12
	.byte		        Cn4 , v068
	.byte	W12
	.byte		        Cn4 , v048
	.byte	W12
	.byte		        Cs4 , v096
	.byte	W12
	.byte		        Cs4 , v068
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W12
	.byte		N23   , Ds4 , v080
	.byte	W24
@ 010   ----------------------------------------
	.byte		N11   , En4 
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		        Gn4 
	.byte	W24
@ 011   ----------------------------------------
	.byte	W60
	.byte		N11   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
@ 012   ----------------------------------------
mus_oe_vs_gym_leader_5_012:
	.byte		N32   , En5 , v080, gtp3
	.byte	W36
	.byte		        Cn5 , v080, gtp3
	.byte	W36
	.byte		N11   , Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte	PEND
@ 013   ----------------------------------------
mus_oe_vs_gym_leader_5_013:
	.byte		N11   , Fn5 , v080
	.byte	W12
	.byte		        En5 
	.byte	W24
	.byte		N56   , Cn5 , v080, gtp3
	.byte	W60
	.byte	PEND
@ 014   ----------------------------------------
	.byte		N44   , As3 , v080, gtp3
	.byte	W48
	.byte		        An3 , v080, gtp3
	.byte	W48
@ 015   ----------------------------------------
	.byte		N23   , Gn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N68   , En3 , v080, gtp3
	.byte	W72
	.byte		N23   , Cn3 
	.byte	W24
@ 017   ----------------------------------------
	.byte		N56   , Gn3 , v080, gtp3
	.byte	W60
	.byte		N11   , En3 , v064
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
@ 018   ----------------------------------------
	.byte		PAN   , c_v-64
	.byte		N11   , As2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
@ 019   ----------------------------------------
	.byte		PAN   , c_v+63
	.byte		N11   , As2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
@ 020   ----------------------------------------
	.byte		PAN   , c_v-64
	.byte		N11   , Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
@ 021   ----------------------------------------
	.byte		PAN   , c_v+63
	.byte		N11   , Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
@ 022   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		N11   , Cn5 , v080
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N23   , Fn5 
	.byte	W24
	.byte		N11   , En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
@ 023   ----------------------------------------
	.byte		        As4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N23   , Dn5 
	.byte	W24
	.byte		N11   , Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_012
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_013
@ 026   ----------------------------------------
	.byte		N44   , Fn4 , v080, gtp3
	.byte	W48
	.byte		        En4 , v080, gtp3
	.byte	W48
@ 027   ----------------------------------------
	.byte		N23   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
@ 028   ----------------------------------------
	.byte		N68   , Cn4 , v080, gtp3
	.byte	W72
	.byte		N23   , Gn3 
	.byte	W24
@ 029   ----------------------------------------
	.byte		N56   , En4 , v080, gtp3
	.byte	W60
	.byte		N11   , En3 , v064
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
@ 030   ----------------------------------------
	.byte		PAN   , c_v-64
	.byte		N11   , Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
@ 031   ----------------------------------------
	.byte		PAN   , c_v+63
	.byte		N11   , Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
@ 032   ----------------------------------------
	.byte		PAN   , c_v-64
	.byte		N11   , Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
@ 033   ----------------------------------------
	.byte		PAN   , c_v+63
	.byte		N11   , Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
@ 034   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte		N11   , En4 , v044
	.byte	W48
	.byte		        Cn4 
	.byte	W48
@ 037   ----------------------------------------
	.byte		        Gn3 
	.byte	W48
	.byte		N02   , Gn3 , v080
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 038   ----------------------------------------
	.byte		N02   , Gs3 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   , Cs4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 039   ----------------------------------------
	.byte		N02   , As3 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   , Ds4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 040   ----------------------------------------
	.byte		N02   , Gn4 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   , Cn5 
	.byte	W12
@ 041   ----------------------------------------
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
@ 042   ----------------------------------------
	.byte	W24
	.byte		N05   , Gs3 
	.byte	W12
	.byte		        Gs3 , v100
	.byte	W12
	.byte		        Gs3 , v080
	.byte	W12
	.byte		        Gs3 , v100
	.byte	W12
	.byte		        Gs3 , v080
	.byte	W12
	.byte		        Gs3 , v100
	.byte	W12
@ 043   ----------------------------------------
	.byte	W24
	.byte		        As3 , v080
	.byte	W12
	.byte		        As3 , v100
	.byte	W12
	.byte		        As3 , v080
	.byte	W12
	.byte		        As3 , v100
	.byte	W12
	.byte		        As3 , v080
	.byte	W12
	.byte		        As3 , v100
	.byte	W12
@ 044   ----------------------------------------
	.byte		PAN   , c_v-64
	.byte		N05   , Cn6 , v072
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
@ 045   ----------------------------------------
	.byte		        Dn5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
@ 046   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte	W24
	.byte		N32   , Cs3 , v084, gtp3
	.byte	W36
	.byte		        Gs4 , v084, gtp3
	.byte	W36
@ 047   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		N23   , As4 
	.byte	W24
	.byte		N23   
	.byte	W24
	.byte		N11   , Ds5 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Gn5 
	.byte	W12
@ 048   ----------------------------------------
	.byte		N32   , Fn5 , v084, gtp3
	.byte	W36
	.byte		N11   
	.byte	W15
	.byte		N05   , En4 , v060
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cn3 
	.byte	W03
@ 049   ----------------------------------------
	.byte	W03
	.byte		        Bn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Fs2 
	.byte	W80
	.byte	W01
@ 050   ----------------------------------------
	.byte		N08   , Ds5 , v080
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
@ 051   ----------------------------------------
	.byte		        Dn5 
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
@ 052   ----------------------------------------
	.byte		        Cn5 
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
@ 053   ----------------------------------------
	.byte		        As4 
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
@ 054   ----------------------------------------
mus_oe_vs_gym_leader_5_054:
	.byte		N08   , An2 , v072
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte	PEND
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_054
@ 056   ----------------------------------------
mus_oe_vs_gym_leader_5_056:
	.byte		N08   , En3 , v072
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte	PEND
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_056
@ 058   ----------------------------------------
mus_oe_vs_gym_leader_5_058:
	.byte		N08   , As2 , v072
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte	PEND
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_058
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_056
@ 061   ----------------------------------------
	.byte		N08   , En3 , v072
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N11   , Fn4 , v080
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
@ 062   ----------------------------------------
	.byte		PAN   , c_v-64
	.byte		N11   , Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
@ 063   ----------------------------------------
	.byte		PAN   , c_v+63
	.byte		N11   , Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
@ 064   ----------------------------------------
mus_oe_vs_gym_leader_5_064:
	.byte		PAN   , c_v-64
	.byte		N11   , Gn3 , v080
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
@ 065   ----------------------------------------
mus_oe_vs_gym_leader_5_065:
	.byte		PAN   , c_v+63
	.byte		N11   , Gn3 , v080
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
@ 066   ----------------------------------------
	.byte		PAN   , c_v-64
	.byte		N11   , Gs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 067   ----------------------------------------
	.byte		PAN   , c_v+63
	.byte		N11   , Gs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_064
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_065
@ 070   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		N08   , Cn3 , v092
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N20   , Cs3 
	.byte	W24
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
@ 071   ----------------------------------------
mus_oe_vs_gym_leader_5_071:
	.byte		N08   , Gn2 , v092
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N20   , Gs2 
	.byte	W24
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte	PEND
@ 072   ----------------------------------------
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N08   
	.byte	W24
	.byte		        Dn4 
	.byte	W12
	.byte		N08   
	.byte	W24
	.byte		        Cn4 
	.byte	W12
@ 073   ----------------------------------------
	.byte		N08   
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		N08   
	.byte	W24
	.byte		        En3 
	.byte	W12
	.byte		N08   
	.byte	W24
@ 074   ----------------------------------------
	.byte		        Cn3 
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N20   , Cs3 
	.byte	W24
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
@ 075   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_071
@ 076   ----------------------------------------
	.byte	W12
	.byte		N08   , Gn3 , v092
	.byte	W12
	.byte		N17   
	.byte	W24
	.byte		N08   
	.byte	W12
	.byte		N17   
	.byte	W24
	.byte		N11   
	.byte	W12
@ 077   ----------------------------------------
	.byte	W12
	.byte		N02   , Gn2 , v080
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   , Bn2 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   , Dn3 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		N02   , Gn3 
	.byte	W06
	.byte		N02   
	.byte	W06
@ 078   ----------------------------------------
	.byte		N44   , Cn4 , v064, gtp3
	.byte	W96
@ 079   ----------------------------------------
	.byte	W96
@ 080   ----------------------------------------
	.byte	W48
	.byte		PAN   , c_v-64
	.byte		N23   , An3 , v088
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
@ 081   ----------------------------------------
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N32   , Gs3 
	.byte	W36
	.byte		PAN   , c_v+0
	.byte		N05   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
@ 082   ----------------------------------------
	.byte		N32   , Cn4 , v088, gtp3
	.byte	W36
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N44   , Cn4 , v088, gtp3
	.byte	W48
@ 083   ----------------------------------------
	.byte		N23   , Gn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
@ 084   ----------------------------------------
	.byte		N05   , En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N48   , Gn3 
	.byte	W48
	.byte		N08   , En3 , v092
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 085   ----------------------------------------
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
@ 086   ----------------------------------------
	.byte		N44   , En4 , v092, gtp3
	.byte	W96
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte		N08   , Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
@ 089   ----------------------------------------
	.byte		        As3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
@ 090   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_002
@ 091   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_003
@ 092   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_5_004
@ 093   ----------------------------------------
	.byte		N11   , Cn4 , v064
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	GOTO
	 .word	mus_oe_vs_gym_leader_5_B1
mus_oe_vs_gym_leader_5_B2:
@ 094   ----------------------------------------
	.byte		VOICE , 4
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 6 (Midi-Chn.6) ****************@

mus_oe_vs_gym_leader_6:
	.byte	KEYSH , mus_oe_vs_gym_leader_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N05   , Cn6 , v072
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
@ 001   ----------------------------------------
	.byte		        En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
mus_oe_vs_gym_leader_6_B1:
@ 006   ----------------------------------------
	.byte		VOICE , 81
	.byte		N44   , Cn3 , v068, gtp3
	.byte	W48
	.byte		        Cn2 , v068, gtp3
	.byte	W48
@ 007   ----------------------------------------
	.byte		        Gn2 , v068, gtp3
	.byte	W48
	.byte		        Cs2 , v068, gtp3
	.byte	W48
@ 008   ----------------------------------------
	.byte		        Cn3 , v068, gtp3
	.byte	W48
	.byte		        Cn2 , v068, gtp3
	.byte	W48
@ 009   ----------------------------------------
	.byte		        Cs3 , v068, gtp3
	.byte	W48
	.byte		        Ds2 , v068, gtp3
	.byte	W48
@ 010   ----------------------------------------
	.byte		        Cn4 , v092, gtp3
	.byte	W48
	.byte		        As3 , v092, gtp3
	.byte	W48
@ 011   ----------------------------------------
	.byte		N32   , Dn4 , v092, gtp3
	.byte	W36
	.byte		N11   , Gn3 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 012   ----------------------------------------
	.byte		N68   , En4 , v092, gtp3
	.byte	W72
	.byte		N11   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte		N52   , Cn4 , v092, gtp1
	.byte	W60
@ 014   ----------------------------------------
	.byte		VOICE , 90
	.byte		N44   , As4 , v120, gtp3
	.byte	W48
	.byte		        An4 , v120, gtp3
	.byte	W48
@ 015   ----------------------------------------
	.byte		N23   , Gn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N68   , En4 , v120, gtp3
	.byte	W72
	.byte		N23   , Cn4 
	.byte	W24
@ 017   ----------------------------------------
	.byte		N80   , Gn4 , v120, gtp3
	.byte	W96
@ 018   ----------------------------------------
	.byte		N44   , Fn4 , v080, gtp3
	.byte	W48
	.byte		        En4 , v080, gtp3
	.byte	W48
@ 019   ----------------------------------------
	.byte		N23   , Fn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
@ 020   ----------------------------------------
	.byte		N68   , Cn5 , v080, gtp3
	.byte	W72
	.byte		N23   , An4 
	.byte	W24
@ 021   ----------------------------------------
	.byte		N88   , Gn4 , v080, gtp1
	.byte	W96
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
	.byte	W96
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte		N32   , Cn3 , v092, gtp3
	.byte	W36
	.byte		        As2 , v092, gtp3
	.byte	W36
	.byte		N23   , Cn3 
	.byte	W24
@ 035   ----------------------------------------
	.byte		N32   , Dn3 , v092, gtp3
	.byte	W36
	.byte		        As2 , v092, gtp3
	.byte	W36
	.byte		N23   , Dn3 
	.byte	W24
@ 036   ----------------------------------------
	.byte		N92   , Cn3 , v092, gtp3
	.byte	W96
@ 037   ----------------------------------------
	.byte		VOICE , 81
	.byte		N68   , Cn3 , v080, gtp3
	.byte	W72
	.byte		N11   
	.byte	W12
	.byte		        As2 
	.byte	W12
@ 038   ----------------------------------------
	.byte		N92   , Cs3 , v080, gtp3
	.byte	W96
@ 039   ----------------------------------------
	.byte		        Ds3 , v080, gtp3
	.byte	W96
@ 040   ----------------------------------------
	.byte		TIE   , Cn3 
	.byte	W96
@ 041   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		EOT   
	.byte	W01
	.byte		N11   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
@ 042   ----------------------------------------
	.byte		N92   , Cs4 , v080, gtp3
	.byte	W96
@ 043   ----------------------------------------
	.byte		        Ds4 , v080, gtp3
	.byte	W96
@ 044   ----------------------------------------
	.byte		TIE   , Cn4 
	.byte	W96
@ 045   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		EOT   
	.byte	W01
	.byte		N11   , Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
@ 046   ----------------------------------------
	.byte		N92   , Gs2 , v080, gtp3
	.byte	W96
@ 047   ----------------------------------------
	.byte		        As2 , v080, gtp3
	.byte	W96
@ 048   ----------------------------------------
	.byte		TIE   , Dn3 , v048
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		EOT   
	.byte	W01
@ 054   ----------------------------------------
	.byte		VOICE , 90
	.byte		N92   , En3 , v072, gtp3
	.byte	W96
@ 055   ----------------------------------------
	.byte		N44   , Dn3 , v072, gtp3
	.byte	W48
	.byte		        En3 , v072, gtp3
	.byte	W48
@ 056   ----------------------------------------
	.byte		N92   , An2 , v072, gtp3
	.byte	W96
@ 057   ----------------------------------------
	.byte		        En3 , v072, gtp3
	.byte	W96
@ 058   ----------------------------------------
	.byte		        Fn3 , v072, gtp3
	.byte	W96
@ 059   ----------------------------------------
	.byte		N44   , Dn3 , v072, gtp3
	.byte	W48
	.byte		        Fn3 , v072, gtp3
	.byte	W48
@ 060   ----------------------------------------
	.byte		N05   , An3 , v056
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W18
	.byte		N05   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W18
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Dn6 
	.byte	W06
@ 061   ----------------------------------------
	.byte		        Ds6 
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        Fn5 , v060
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        As4 , v064
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        As4 , v068
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 , v072
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
@ 062   ----------------------------------------
mus_oe_vs_gym_leader_6_062:
	.byte		N05   , Fn6 , v076
	.byte	W06
	.byte		        En6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte	PEND
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_062
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_062
@ 065   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_062
@ 066   ----------------------------------------
mus_oe_vs_gym_leader_6_066:
	.byte		N05   , Gs6 , v076
	.byte	W06
	.byte		        Fn6 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte	PEND
@ 067   ----------------------------------------
	.byte		        Gs6 
	.byte	W06
	.byte		        Fn6 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W12
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_062
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_062
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_066
@ 071   ----------------------------------------
	.byte		N05   , Cs2 , v076
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
@ 072   ----------------------------------------
	.byte		N68   , Gn5 , v076, gtp3
	.byte	W72
	.byte		N05   , Cn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        As5 
	.byte	W06
@ 073   ----------------------------------------
	.byte		N92   , Cn6 , v076, gtp3
	.byte	W96
@ 074   ----------------------------------------
	.byte	W24
	.byte		N05   , Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N23   , Fn4 
	.byte	W24
	.byte		N05   , Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
@ 075   ----------------------------------------
	.byte		N23   , Gs4 
	.byte	W24
	.byte		N11   , Fn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 076   ----------------------------------------
	.byte		N36   , Cn4 , v076, gtp2
	.byte	W42
	.byte		N05   , As3 
	.byte	W06
	.byte		N11   , Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_062
@ 079   ----------------------------------------
	.byte		N05   , Fn6 , v076
	.byte	W06
	.byte		        En6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
@ 080   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_062
@ 081   ----------------------------------------
	.byte		N05   , Gs6 , v076
	.byte	W06
	.byte		        Fn6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
@ 082   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_062
@ 083   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_062
@ 084   ----------------------------------------
	.byte		N05   , Cn4 , v076
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		TIE   , En4 
	.byte	W72
@ 085   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		EOT   
	.byte	W24
	.byte	W01
@ 086   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_062
@ 087   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_6_062
@ 088   ----------------------------------------
	.byte		N32   , Cn4 , v076, gtp3
	.byte	W36
	.byte		N05   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N23   , Gs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
@ 089   ----------------------------------------
	.byte		        Fn4 
	.byte	W24
	.byte		N05   , As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N23   , As4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
@ 090   ----------------------------------------
	.byte		TIE   , Cn5 , v060
	.byte	W96
@ 091   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		EOT   
	.byte	W01
@ 092   ----------------------------------------
	.byte	W96
@ 093   ----------------------------------------
	.byte	W96
	.byte	GOTO
	 .word	mus_oe_vs_gym_leader_6_B1
mus_oe_vs_gym_leader_6_B2:
@ 094   ----------------------------------------
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 7 (Midi-Chn.10) ****************@

mus_oe_vs_gym_leader_7:
	.byte	KEYSH , mus_oe_vs_gym_leader_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N76   , Gn2 , v127, gtp1
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte		        Gn2 , v127, gtp1
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W60
	.byte		N32   , Gn2 , v127, gtp3
	.byte	W36
mus_oe_vs_gym_leader_7_B1:
@ 006   ----------------------------------------
	.byte		N76   , Gn2 , v127, gtp1
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte		N06   , Cn1 , v104
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte		N23   , Gn2 , v127
	.byte	W06
	.byte		N06   , Cn1 , v104
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 010   ----------------------------------------
mus_oe_vs_gym_leader_7_010:
	.byte		N06   , Cn1 , v104
	.byte		N76   , Gn2 , v127, gtp1
	.byte	W12
	.byte		N06   , Dn1 , v104
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
mus_oe_vs_gym_leader_7_011:
	.byte		N06   , Cn1 , v104
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
@ 012   ----------------------------------------
mus_oe_vs_gym_leader_7_012:
	.byte		N06   , Cn1 , v104
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_012
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 032   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 033   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_012
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 041   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 042   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 043   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 044   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 045   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 046   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 047   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 048   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 049   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 050   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 051   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 052   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 053   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_012
@ 054   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_010
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 065   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 066   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 067   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 070   ----------------------------------------
mus_oe_vs_gym_leader_7_070:
	.byte	W12
	.byte		N06   , Cn1 , v104
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N23   , Gn2 , v096
	.byte	W24
	.byte		N06   , Dn1 , v104
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 071   ----------------------------------------
mus_oe_vs_gym_leader_7_071:
	.byte	W12
	.byte		N06   , Cn1 , v104
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N23   , Gn2 , v096
	.byte	W24
	.byte		N06   , Dn1 , v104
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 072   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 073   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_011
@ 074   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_070
@ 075   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_071
@ 076   ----------------------------------------
	.byte		N06   , Dn1 , v104
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 077   ----------------------------------------
	.byte		N06   
	.byte		N44   , Gn2 , v096, gtp3
	.byte	W60
	.byte		N06   , Cn1 , v104
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N68   , Gn2 , v112, gtp3
	.byte	W12
	.byte		N06   , Dn1 , v104
	.byte	W12
@ 078   ----------------------------------------
mus_oe_vs_gym_leader_7_078:
	.byte		N06   , Cn1 , v104
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
@ 079   ----------------------------------------
mus_oe_vs_gym_leader_7_079:
	.byte		N06   , Cn1 , v104
	.byte	W24
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
@ 080   ----------------------------------------
mus_oe_vs_gym_leader_7_080:
	.byte		N06   , Cn1 , v104
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
@ 081   ----------------------------------------
mus_oe_vs_gym_leader_7_081:
	.byte	W12
	.byte		N06   , Cn1 , v104
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cn1 , v104
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 082   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_078
@ 083   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_079
@ 084   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_080
@ 085   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_081
@ 086   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_078
@ 087   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_079
@ 088   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_080
@ 089   ----------------------------------------
	.byte	PATT
	 .word	mus_oe_vs_gym_leader_7_081
@ 090   ----------------------------------------
	.byte		VOICE , 56
	.byte		TIE   , Gn4 , v127
	.byte	W96
@ 091   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		EOT   
	.byte	W01
@ 092   ----------------------------------------
	.byte	W96
@ 093   ----------------------------------------
	.byte	W48
	.byte		VOICE , 0
	.byte	W12
	.byte		N32   , Gn2 , v127, gtp3
	.byte	W36
	.byte	GOTO
	 .word	mus_oe_vs_gym_leader_7_B1
mus_oe_vs_gym_leader_7_B2:
@ 094   ----------------------------------------
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_oe_vs_gym_leader_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	FINE

@******************************************************@
	.align	2

mus_oe_vs_gym_leader:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_oe_vs_gym_leader_pri	@ Priority
	.byte	mus_oe_vs_gym_leader_rev	@ Reverb.

	.word	mus_oe_vs_gym_leader_grp

	.word	mus_oe_vs_gym_leader_1
	.word	mus_oe_vs_gym_leader_2
	.word	mus_oe_vs_gym_leader_3
	.word	mus_oe_vs_gym_leader_4
	.word	mus_oe_vs_gym_leader_5
	.word	mus_oe_vs_gym_leader_6
	.word	mus_oe_vs_gym_leader_7

	.end
