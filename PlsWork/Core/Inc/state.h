/*
 * state.h
 *
 *  Created on: Jan 6, 2026
 *      Author: Admin
 */

#ifndef INC_STATE_H_
#define INC_STATE_H_

#include "parotconf.h"
#include "display.h"
#include "touchscreen.h"
#include "sound.h"
#include "stm32h735g_discovery.h"

typedef enum {
    STATE_INIT,
    STATE_IDLE,
	STATE_CALIBRATION,
	STATE_RECORDING,
	STATE_PLAYBACK,
	STATE_ERROR
} AppState_t;


// This struct holds EVERYTHING the app needs to remember between loops.
// This effectively replaces global variables in main.c
typedef struct {
    // State Control
    AppState_t currentState;
    AppState_t previousState;
    uint8_t    needs_redraw; // Flag to optimize screen drawing (only draw on change)

    // Touch Data
    uint32_t ts_max_x;
    uint32_t ts_max_y;
    int touch_x;
    int touch_y;

    // Timer / Logic
    uint32_t timer_start;

} SystemContext_t;

void SystemContext_init(SystemContext_t* context);

// Call this once before the while(1) loop to set defaults
void State_Init(SystemContext_t *ctx);

// Call this repeatedly inside the while(1) loop
void State_Machine_Run(SystemContext_t *ctx);

void State_Button_Switch(SystemContext_t *ctx, AppState_t newState);

#endif /* INC_STATE_H_ */
