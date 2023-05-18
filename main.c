#include <absacc.h> 

#pragma MOD167


#define B_brems 0x20

#define nmot_w (XVAR (unsigned short, 0xF410))
#define wped_w (XVAR (unsigned short, 0x30195C))
#define vfzg_w (XVAR (unsigned short, 0x3029AC))
#define zwgru (XVAR (signed char, 0xF337))
#define zwist (XVAR (signed char, 0xF338))
#define zwout (XVAR (signed char, 0xF33A))
#define redsol (XVAR (unsigned char, 0x3013F4))
#define redsol_my (XVAR (unsigned char, 0x30592C))
#define byte_301336 (XVAR (unsigned char, 0x30136))
#define launch_zwgru (XVAR (signed char, 0x2D000))
#define launch_wped_w (XVAR (unsigned short, 0x2D002))
#define launch_nmot_w (XVAR (unsigned short, 0x2D004))
#define launch_vfzg_w (XVAR (unsigned short, 0x2D006))

void huge launch()
{
	__asm {
		calls 5, 0x50D24
	}

	if(wped_w > launch_wped_w && vfzg_w <= launch_vfzg_w) {
		zwgru = launch_zwgru;
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
		redsol_my = 0;
	}
}

void huge redsol_select()
{
	__asm {
		calls 5, 0x053A
	}
	if(redsol_my > 0)
		redsol = redsol_my;
}
