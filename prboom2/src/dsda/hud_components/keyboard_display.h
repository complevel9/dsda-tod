#ifndef TOD_KEYBOARD_DISPLAY_H__
#define TOD_KEYBOARD_DISPLAY_H__

void tod_InitKDHC(int xoff, int yoff, int vpt_flags);
void tod_UpdateKDHC(void);
void tod_DrawKDHC(void);
void tod_EraseKDHC(void);

#endif