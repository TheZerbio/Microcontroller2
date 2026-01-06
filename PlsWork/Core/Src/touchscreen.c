/*
 * touchscreen.c
 *
 *  Created on: Jan 6, 2026
 *      Author: Admin
 */
#include "touchscreen.h"

void TOUCHSCREEN_INIT(){
  TS_Init_t hTS;
  hTS.Width = 480;
  hTS.Height = 272;
  hTS.Orientation = TS_ORIENTATION_LANDSCAPE;
  hTS.Accuracy = 0; // Use default accuracy

  // Initialize TouchScreen (Instance 0)
  if (BSP_TS_Init(0, &hTS) != BSP_ERROR_NONE)
  {
	  // If TS fails, Blink Red LED forever
	  while(1) { BSP_LED_Toggle(LED2); HAL_Delay(100); }
  }
}
void TOUCHSCREEN_CALIBRATION(uint32_t *maxX, uint32_t *maxY)
{
    TS_State_t TS_State;
    BSP_LCD_FillRect(0, 0, 0, 480, 272, CAL_COL1);

    *maxX = 0;
    *maxY = 0;

    HAL_Delay(500);

    BSP_LCD_FillRect(0, 0, 0, 480, 272, CAL_COL2);

    while(BSP_PB_GetState(BUTTON_USER) != 1)
    {
        BSP_TS_GetState(0, &TS_State);

        if(TS_State.TouchDetected)
        {
            *maxX = max(*maxX, TS_State.TouchY);
            *maxY = max(*maxY, TS_State.TouchX);

            BSP_LCD_FillRect(0, 0, 0, *maxX, *maxY, LCD_COLOR_ARGB8888_WHITE);
        }
        HAL_Delay(20);
    }

    BSP_LCD_FillRect(0, 0, 0, 480, 272, LCD_COLOR_ARGB8888_GREEN);
    HAL_Delay(500);

    do {
        BSP_TS_GetState(0, &TS_State);
        HAL_Delay(50);
    } while(TS_State.TouchDetected);

    BSP_LCD_FillRect(0, 0, 0, 480, 272, BACKGROUND_COLOR);
}

uint32_t max(uint32_t a, uint32_t b){
    if(a > b){
        return a;
    }
    return b;
}
