#include "keyboard_display.h"

#include "d_ticcmd.h"
#include "base.h"
#include "d_player.h"
#include "doomdef.h"

#include <string.h>

static hu_textline_t w_keyboard_display_move;
static hu_textline_t w_keyboard_display_strafe;
//static hu_textline_t w_keyboard_display_misc;

static int unitspace = 5;

extern player_t players[MAX_MAXPLAYERS];
extern int displayplayer;
#define pcmd players[displayplayer].cmd
#define moveamt   pcmd.forwardmove
#define strafeamt pcmd.sidemove

#define CR_VHIGH CR_RED
#define CR_HIGH  CR_BLUE
#define CR_MID   CR_GREEN
#define CR_LOW   CR_WHITE

static crange_idx_e tod_Cr4Level(int v, int low, int mid, int high) {
	if (v >= high) return CR_VHIGH;
	if (v >= mid) return CR_HIGH;
	if (v >= low) return CR_MID;
	return CR_LOW;
}

void tod_InitKDHC(int xoff, int yoff, int vpt_flags)
{
	HUlib_initTextLine(&w_keyboard_display_move,   xoff, yoff, hu_font2, HU_FONTSTART, CR_WHITE, vpt_flags);
	HUlib_initTextLine(&w_keyboard_display_strafe, xoff, yoff, hu_font2, HU_FONTSTART, CR_WHITE, vpt_flags);
//	HUlib_initTextLine(&w_keyboard_display_misc,   xoff, yoff, hu_font2, HU_FONTSTART, CR_WHITE, vpt_flags);
}

void tod_UpdateKDHC(void)
{
	char *s;
	char move_str[8];
	char strafe_str[8];

	HUlib_clearTextLine(&w_keyboard_display_move);
	HUlib_clearTextLine(&w_keyboard_display_strafe);

	// transfer the init string to the widget
	if (moveamt) {
		snprintf(move_str, 5, "%+3d", moveamt);
		s = move_str;
		while (*s)
			HUlib_addCharToTextLine(&w_keyboard_display_move, *(s++));
	}
	if (strafeamt) {
		snprintf(strafe_str, 5, "%+3d", strafeamt);
		s = strafe_str;
		while (*s)
			HUlib_addCharToTextLine(&w_keyboard_display_strafe, *(s++));
	}
}

void tod_DrawKDHC(void)
{
	if (moveamt)
	{
		int movesign = -1 + (moveamt > 0)*2;
		int movemag = moveamt * movesign;
		int offy = unitspace * -4 * (moveamt > 0);
		w_keyboard_display_move.y += offy;
		w_keyboard_display_move.cm = tod_Cr4Level(movemag, 25, 50, 51);
		HUlib_drawTextLine(&w_keyboard_display_move, false);
		w_keyboard_display_move.y -= offy;
	}
	if (strafeamt)
	{
		int strafesign = -1 + (strafeamt > 0)*2;
		int strafemag = strafeamt * strafesign;
		int offx = unitspace * 4 * strafesign;
		w_keyboard_display_strafe.x += offx;
		w_keyboard_display_strafe.cm = tod_Cr4Level(strafemag, 24, 40, 50);
		HUlib_drawTextLine(&w_keyboard_display_strafe, false);
		w_keyboard_display_strafe.x -= offx;
	}
//	HUlib_drawTextLine(&w_keyboard_display_misc, false);
}

void tod_EraseKDHC(void)
{
	HUlib_eraseTextLine(&w_keyboard_display_move);
	HUlib_eraseTextLine(&w_keyboard_display_strafe);
//	HUlib_eraseTextLine(&w_keyboard_display_misc);
}
