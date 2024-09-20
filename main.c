#include <absacc.h> 

#pragma MOD167


#define B_brems 0x4

#define nmot_w (XVAR (unsigned short, 0xF410))
#define wped_w (XVAR (unsigned short, 0x30195C))
#define vfzg_w (XVAR (unsigned short, 0x3029AC))
#define zwgru (XVAR (signed char, 0xF337))
#define zwist (XVAR (signed char, 0xF338))
#define zwout (XVAR (signed char, 0xF33A))
#define word_FD26 (XVAR (unsigned short, 0xFD26))
#define word_FD64 (XVAR (unsigned short, 0xFD64))
#define redsol (XVAR (unsigned char, 0x3013F4))
#define redsol_my (XVAR (unsigned char, 0x30592C))
#define kfnwse_offset (XVAR (unsigned short, 0x303F7E))
#define kfnwse_page (XVAR (unsigned short, 0x303F80))
#define kfnwsa_offset (XVAR (unsigned short, 0x303F82))
#define kfnwsa_page (XVAR (unsigned short, 0x303F84))
#define kfldrx_offset (XVAR (unsigned short, 0x303F86))
#define kfldrx_page (XVAR (unsigned short, 0x303F88))
#define launch_status (XVAR (unsigned short, 0xFDE2))
#define vin_begin (XVAR (unsigned char, 0x303198))
#define ldtvm (XVAR (unsigned char, 0x3018C3))
#define vin_accepted (XVAR (unsigned short, 0xFDE4))
#define launch_zwgru (XVAR (signed char, 0x2D000))
#define launch_wped_w (XVAR (unsigned short, 0x2D002))
#define launch_nmot_w (XVAR (unsigned short, 0x2D004))
#define launch_vfzg_w (XVAR (unsigned short, 0x2D006))
#define launch_start_nmot_w (XVAR (unsigned short, 0x2D008))
#define launch_lamsons_w (XVAR (unsigned short, 0x2D00A))
#define launch_ldtv_w (XVAR (unsigned short, 0x2D00C))
#define launch_ldtv_w (XVAR (unsigned short, 0x2D00C))
#define vin_expected (XVAR (unsigned short, 0x2D00E))

void huge launch()
{
	__asm {
		jnb 0xFDE2.0, launch_disabled
		extp #0Bh, #1
		movb    rl4, 0x1000
		movb [r9], rl4
launch_disabled:
		movb 0xF33A, [r9]
	}
}

void huge kr_overload()
{
	__asm {
		jnb 0xFDE2.0, launch_disabled
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
	if(wped_w > launch_wped_w && vfzg_w <= launch_vfzg_w && nmot_w >= launch_start_nmot_w) {
		launch_status |= 1;
		kfnwse_offset = 0x120E;
		kfnwse_page = 0xB;
		kfnwsa_offset = 0x110E;
		kfnwsa_page = 0xB;
		if(nmot_w > launch_nmot_w + 2000)
			redsol_my = 5;
		else if(nmot_w > launch_nmot_w + 1200)
			redsol_my = 2;
		else if(nmot_w > launch_nmot_w)
			redsol_my = 2;
		else if(nmot_w > launch_nmot_w - 400)
			redsol_my = 1;
		else
			redsol_my = 0;
	}
	else {
		launch_status = 0;
		kfnwse_offset = 0x19BA;
		kfnwse_page = 0x7;
		kfnwsa_offset = 0x21C0;
		kfnwsa_page = 0x7;
		redsol_my = 0;
	}
	if(redsol_my > 0)
		redsol = redsol_my;
}

void huge lamsons_select()
{
	__asm {
		jnb 0xFDE2.0, launch_disabled
		extp #0Bh, #1
		mov r4, 0x100A
		mov 0xA93C, r4
launch_disabled:
		mov 0xA93E, r4
	}
}

void huge ldtvm_overload()
{
	__asm {
		calls 0xE, 0x0474
		jnb 0xFDE2.0, launch_disabled
		extp #0Bh, #1
		mov r4, 0x100C
		extp #0C1h, #1
		mov 0x18F0, r4
launch_disabled:
	}
}

void huge zw_map_switch()
{
	
}

void huge boost_map_switch()
{
}

void check_vin_impl()
{
	unsigned short result = 0;
	int i = 0;
	for(i = 0; i < 17; ++i)
		result += (&vin_begin)[i];
	
	vin_accepted = (result == vin_expected);
}

void huge check_vin()
{
	__asm {
		movb    0xB19A, rl4
	}
	check_vin_impl();
}
	
void huge apply_ldtvm()
{
	__asm {
		jb 0xFDE4.0, vin_checked
		movb    rl6, #0
	vin_checked:
		movb    0x98C3, rl6
	}
}

void huge kfldrx_select()
{
	if(word_FD26 & 0x800) {
		kfldrx_offset = 0x130E;
		kfldrx_page = 0x0B;
	}
	else {
		kfldrx_offset = 0x13FE;
		kfldrx_page = 0x0B;
	}
	__asm {
		calls 0xE, 0x0080
	}
}
