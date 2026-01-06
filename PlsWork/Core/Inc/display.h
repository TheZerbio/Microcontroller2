/*
 * display.h
 *
 *  Created on: Jan 6, 2026
 *      Author: Admin
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_
//Includes
#include "parotconf.h"
#include "fonts.h"
#include "stm32h735g_discovery.h"
#include "stm32h735g_discovery_lcd.h"
#include "stm32h735g_discovery_ospi.h"

//Functions
void DISPLAY_INIT(void);
void DISPLAY_Clear(uint32_t color);
void DISPLAY_DrawChar(uint16_t Xpos, uint16_t Ypos, const sFONT *pFont, uint32_t TextColor, char c);
void DISPLAY_DrawString(uint16_t Xpos, uint16_t Ypos, const sFONT *pFont, uint32_t TextColor, char *Text);
void DISPLAY_DrawHeadline(uint16_t Xpos, uint16_t Ypos, char *Text);
void DISPLAY_DrawText(uint16_t Xpos, uint16_t Ypos, char *Text);

#endif /* INC_DISPLAY_H_ */
