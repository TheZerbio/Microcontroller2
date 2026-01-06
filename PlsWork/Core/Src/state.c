/*
 * state.c
 *
 *  Created on: Jan 6, 2026
 *      Author: Admin
 */
#include "state.h"

static void ChangeState(SystemContext_t *ctx, AppState_t newState) {
    ctx->previousState = ctx->currentState;
    ctx->currentState = newState;
    ctx->needs_redraw = 1; // Force UI update on entry to new state
}

/**
 * @brief Switches to the newState if User Button is pressed during the call
 */
void State_Button_Switch(SystemContext_t *ctx, AppState_t newState){
	if(BSP_PB_GetState(BUTTON_USER)){
		ChangeState(ctx,newState);
	}
}

void State_Init(SystemContext_t *ctx) {
    ctx->currentState = STATE_INIT;
    ctx->previousState = STATE_INIT;

    ctx->ts_max_x = 272;
    ctx->ts_max_y = 480;

    ctx->touch_x = -1;
    ctx->touch_y = -1;
    ctx->needs_redraw = 1;
}

void State_Machine_Run(SystemContext_t *ctx) {

    switch (ctx->currentState) {
        // --- INITIALIZATION ---
        case STATE_INIT:
            if(ctx->needs_redraw) {
            	DISPLAY_INIT();
				TOUCHSCREEN_INIT();
				if (SOUND_INIT() != 0) {
					ctx->currentState = STATE_ERROR;
					return;
				}
				BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);
                DISPLAY_Clear(BACKGROUND_COLOR);
                DISPLAY_DrawString(100, 120, &Font24, TEXT_COLOR, "SYSTEM INIT");

                HAL_Delay(500);
                ChangeState(ctx, STATE_CALIBRATION);
            }
            break;

        // --- IDLE (WAITING) ---
        case STATE_IDLE:
            if(ctx->needs_redraw) {
                DISPLAY_Clear(BACKGROUND_COLOR);
                DISPLAY_DrawHeadline(10,10,"STATE_IDLE");

                // Draw a hint for calibration (hidden feature)
                BSP_LCD_FillRect(0, 0, 0, 10, 10, ACCENT_COLOR); // Top left dot
                ctx->needs_redraw = 0;
            }

            // INPUT: User Button -> Record
            if(BSP_PB_GetState(BUTTON_USER) == 1) {
                ChangeState(ctx, STATE_RECORDING);
                HAL_Delay(300); // Simple Debounce
            }

            break;

        // --- RECORDING ---
        case STATE_RECORDING:
            if(ctx->needs_redraw) {
                // UI Update
                DISPLAY_Clear(ACCENT_COLOR); // Dark Red background
                DISPLAY_DrawHeadline(10,10,"STATE_RECORDING");

                // Hardware Trigger
                //Sound_StartRecording();
                ctx->timer_start = HAL_GetTick(); // Mark start time
                ctx->needs_redraw = 0;
            }

            // Non-blocking Timer Check
            if((HAL_GetTick() - ctx->timer_start) >= RECORD_TIME_MS) {
                Sound_StopRecording();
                ChangeState(ctx, STATE_PLAYBACK);
            }
            break;

        // --- PLAYBACK ---
        case STATE_PLAYBACK:
            if(ctx->needs_redraw) {
                // UI Update (Purple/Gray theme from your config)
                DISPLAY_Clear(LCD_COLOR_ARGB8888_YELLOW);
                DISPLAY_DrawHeadline(10,10,"STATE_PLAYBACK");

                // Hardware Trigger
                Sound_StartPlayback();
                ctx->timer_start = HAL_GetTick();
                ctx->needs_redraw = 0;
            }

            // Non-blocking Timer Check
            if((HAL_GetTick() - ctx->timer_start) >= RECORD_TIME_MS) {
                Sound_StopPlayback();
                ChangeState(ctx, STATE_IDLE);
            }
            break;

        // --- CALIBRATION ---
        case STATE_CALIBRATION:
            // Assuming your TOUCHSCREEN_CALIBRATION function is blocking.
            // If it is blocking, we just call it once and exit state.
            TOUCHSCREEN_CALIBRATION(&ctx->ts_max_x, &ctx->ts_max_y);
            ChangeState(ctx, STATE_IDLE);
            break;

        // --- ERROR ---
        case STATE_ERROR:
            DISPLAY_Clear(ACCENT_COLOR);
            DISPLAY_DrawHeadline(10,10,"STATE_ERROR");
            HAL_Delay(1000); // Stuck here
            break;
    }
}
