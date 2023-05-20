#include <absacc.h> 

#pragma MOD167


#define B_brems 0x4

#define nmot_w (XVAR (unsigned short, 0xF410))
#define wped_w (XVAR (unsigned short, 0x30195C))
#define vfzg_w (XVAR (unsigned short, 0x3029AC))
#define zwgru (XVAR (signed char, 0xF337))
#define zwist (XVAR (signed char, 0xF338))
#define zwout (XVAR (signed char, 0xF33A))
#define word_FD64 (XVAR (unsigned short, 0xFD64))
#define redsol (XVAR (unsigned char, 0x3013F4))
#define redsol_my (XVAR (unsigned char, 0x30592C))
#define launch_active (XVAR (unsigned char, 0x30592E))
#define byte_301336 (XVAR (unsigned char, 0x30136))
#define launch_zwgru (XVAR (signed char, 0x2D000))
#define launch_wped_w (XVAR (unsigned short, 0x2D002))
#define launch_nmot_w (XVAR (unsigned short, 0x2D004))
#define launch_vfzg_w (XVAR (unsigned short, 0x2D006))

void huge launch()
{
	__asm {
		extp #0C1h, #1
		movb    rl4, 0x192E
		jmpr cc_Z, launch_disaled
		extp #0Bh, #1
		movb    rl4, 0x1000
		movb [r9], rl4
launch_disaled:
		movb 0xF33A, [r9]
	}
}

void huge kr_overload()
{
	__asm {
		movb    rl4, 0x192E
		jmpr cc_Z, launch_disabled
		bclr 0FD42H.2
launch_disabled:
		calls 7, 0xB41A
	}
}

void huge redsol_select()
{
	__asm {
		calls 5, 0x053A
	}
	if(wped_w > launch_wped_w && vfzg_w <= launch_vfzg_w) {
		launch_active = 1;
		if(nmot_w > launch_nmot_w + 1200)
			redsol_my = 5;
		if(nmot_w > launch_nmot_w + 800)
			redsol_my = 4;
		else if(nmot_w > launch_nmot_w + 400)
			redsol_my = 3;
		else if(nmot_w > launch_nmot_w)
			redsol_my = 2;
		else if(nmot_w > launch_nmot_w - 400)
			redsol_my = 1;
		else
			redsol_my = 0;
	}
	else {
		launch_active = 0;
		redsol_my = 0;
	}
	if(redsol_my > 0)
		redsol = redsol_my;
}
