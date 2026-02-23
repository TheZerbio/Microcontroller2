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
	uint32_t last_ui_update = 0;
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
				// 1. Setup Background and Text using parotconf colors
				UTIL_LCD_Clear(BACKGROUND_COLOR);
				UTIL_LCD_SetBackColor(BACKGROUND_COLOR);
				UTIL_LCD_SetTextColor(TEXT_COLOR);
				UTIL_LCD_SetFont(&Font24);
				UTIL_LCD_DisplayStringAt(10, 10, (uint8_t*)"RECORDING...", LEFT_MODE);

				// 2. Draw the Bar Container (Outline)
				// Using TEXT_COLOR or MAIN_COLOR for high contrast frame
				UTIL_LCD_DrawRect(50, 100, 380, 50, MAIN_COLOR);

				// Start Hardware
				Sound_StartRecording();
				ctx->timer_start = HAL_GetTick();
				ctx->needs_redraw = 0;
			}

			uint32_t elapsed = HAL_GetTick() - ctx->timer_start;

			// --- VISUALIZATION (Volume Meter) ---
			// Update UI every 30ms to prevent flickering
			if ((HAL_GetTick() - last_ui_update) > 30)
			{
				uint16_t volume = Sound_GetInputLevel(elapsed);

				// Scale volume (0-32000) to Bar Width (0-378px)
				uint32_t bar_width = volume / 64;
				if (bar_width > 378) bar_width = 378;

				// Draw Active Part: Use ACCENT_COLOR (DarkRed) for Recording
				if (bar_width > 0) {
					UTIL_LCD_FillRect(51, 101, bar_width, 48, ACCENT_COLOR);
				}

				// Draw Inactive Part: Use BACKGROUND_COLOR to "erase" old bar
				if (bar_width < 378) {
					UTIL_LCD_FillRect(51 + bar_width, 101, 378 - bar_width, 48, BACKGROUND_COLOR);
				}

				last_ui_update = HAL_GetTick();
			}

			// Stop Check
			if(elapsed >= RECORD_TIME_MS) {
				Sound_StopRecording();
				ChangeState(ctx, STATE_PLAYBACK);
			}
			break;

        // --- PLAYBACK ---
        case STATE_PLAYBACK:
        	if(ctx->needs_redraw) {
				// 1. Setup Background and Text
				UTIL_LCD_Clear(BACKGROUND_COLOR);
				UTIL_LCD_SetBackColor(BACKGROUND_COLOR);
				UTIL_LCD_SetTextColor(TEXT_COLOR);
				UTIL_LCD_SetFont(&Font24);
				UTIL_LCD_DisplayStringAt(10, 10, (uint8_t*)"PLAYBACK...", LEFT_MODE);

				// 2. Draw Container (Outline)
				UTIL_LCD_DrawRect(50, 100, 380, 50, MAIN_COLOR);

				// Start Hardware
				Sound_StartPlayback();
				ctx->timer_start = HAL_GetTick();
				ctx->needs_redraw = 0;
			}

			uint32_t play_elapsed = HAL_GetTick() - ctx->timer_start;

			// --- VISUALIZATION (Progress Bar) ---
			if ((HAL_GetTick() - last_ui_update) > 30)
			{
				// Calculate Progress Percentage based on Time
				// Max width is 378px (380px container - 2px border)
				uint32_t total_width = 378;

				// Avoid divide by zero
				if(RECORD_TIME_MS > 0) {
					uint32_t progress_width = (play_elapsed * total_width) / RECORD_TIME_MS;
					if (progress_width > total_width) progress_width = total_width;

					// Draw Active Part: Use CAL_COL2 (Purple) for Playback
					if (progress_width > 0) {
						UTIL_LCD_FillRect(51, 101, progress_width, 48, CAL_COL2);
					}

					// Draw Inactive Part: BACKGROUND_COLOR
					if (progress_width < total_width) {
						UTIL_LCD_FillRect(51 + progress_width, 101, total_width - progress_width, 48, BACKGROUND_COLOR);
					}
				}
				last_ui_update = HAL_GetTick();
			}

			// Stop Check
			if(play_elapsed >= RECORD_TIME_MS) {
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
