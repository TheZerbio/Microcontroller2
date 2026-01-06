/*
 * touchscreen.h
 *
 *  Created on: Jan 6, 2026
 *      Author: Admin
 */

#ifndef INC_TOUCHSCREEN_H_
#define INC_TOUCHSCREEN_H_

#define TS_ORIENTATION_LANDSCAPE        1

#include "parotconf.h"
#include "stm32h735g_discovery.h"
#include "stm32h735g_discovery_ts.h"
#include "stm32h735g_discovery_lcd.h"

void TOUCHSCREEN_INIT(void);
void TOUCHSCREEN_CALIBRATION(uint32_t *maxX, uint32_t *maxY);
uint32_t max(uint32_t a, uint32_t b);

#endif /* INC_TOUCHSCREEN_H_ */
