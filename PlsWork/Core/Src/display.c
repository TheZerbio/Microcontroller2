#include "display.h"

void DISPLAY_INIT(void){
    BSP_LCD_Init(0, LCD_ORIENTATION_LANDSCAPE);
    BSP_LCD_DisplayOn(0);

    // Link the generic stm32_lcd library to the hardware driver
    // Without this line, all UTIL_LCD_ functions will fail!
    UTIL_LCD_SetFuncDriver(&LCD_Driver);

    UTIL_LCD_SetDevice(0);          // LCD Instance 0
    UTIL_LCD_SetLayer(0);           // Layer 0
    UTIL_LCD_SetFont(&Font24);      // Default Font
    UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
    UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_ST_GRAY_DARK);

    UTIL_LCD_Clear(UTIL_LCD_COLOR_ST_GRAY_DARK);
}

void DISPLAY_Clear(uint32_t color){
    UTIL_LCD_Clear(color);
}


//These are legacy functions i wrote before discovering the stm32_lcd.h file which basically implements these and more

/**
  * @brief  Draws a single character on the screen.
  */
void DISPLAY_DrawChar(uint16_t Xpos, uint16_t Ypos, const sFONT *pFont, uint32_t TextColor, char c)
{
  uint32_t i = 0, j = 0;
  uint16_t height, width;
  uint8_t offset;
  uint8_t *pchar;
  uint32_t line;
  uint32_t stride; // Bytes per row

  height = pFont->Height;
  width = pFont->Width;

  // Calculate bytes per row (e.g. Width 17 -> 3 bytes)
  stride = (width + 7) / 8;

  // 1. Calculate the offset for bit shifting
  offset = 8 * stride - width;

  // 2. Point to the start of the character's bitmap data
  pchar = (uint8_t *)&pFont->table[(c - ' ') * height * stride];

  // 3. Loop through every row (Height)
  for(i = 0; i < height; i++)
  {
    // FIX: Do NOT increment pchar here. We read directly from it below.

    // Read the bitmask for this line based on how many bytes wide the font is
    line = 0;
    switch(stride)
    {
      case 1:
        line = pchar[0];
        break;
      case 2:
        line = (pchar[0] << 8) | pchar[1];
        break;
      case 3:
      default:
        line = (pchar[0] << 16) | (pchar[1] << 8) | pchar[2];
        break;
    }

    // 4. Loop through every column (Width)
    for(j = 0; j < width; j++)
    {
      // Check if the specific bit is set
      // We check from the MSB (Left) to LSB (Right)
      if(line & (1 << (width - j + offset - 1)))
      {
        BSP_LCD_WritePixel(0, Xpos + j, Ypos + i, TextColor);
      }
    }

    // 5. Move pointer to the start of the NEXT row
    pchar += stride;
  }
}

/**
  * @brief  Draws a string on the screen.
  * @param  Xpos: Starting X position
  * @param  Ypos: Starting Y position
  * @param  pFont: Pointer to the font (e.g., &Font24)
  * @param  TextColor: Color of the text
  * @param  Text: Pointer to the string
  */
void DISPLAY_DrawString(uint16_t Xpos, uint16_t Ypos, const sFONT *pFont, uint32_t TextColor, char *Text)
{
  uint16_t refX = Xpos;

  // Loop until null terminator
  while (*Text != 0)
  {
    // Handle Newline character
    if (*Text == '\n')
    {
        Ypos += pFont->Height;
        Xpos = refX; // Reset X to start
        Text++;
        continue;
    }

    // Draw the current character
    DISPLAY_DrawChar(Xpos, Ypos, pFont, TextColor, *Text);

    // Move X position forward by the width of the font
    Xpos += pFont->Width;

    // Point to the next char
    Text++;
  }
}

//Wrapper functions for the display

void DISPLAY_DrawHeadline(uint16_t Xpos, uint16_t Ypos, char *Text){
	DISPLAY_DrawString(Xpos, Ypos, &Font12, TEXT_COLOR, Text);
}
void DISPLAY_DrawText(uint16_t Xpos, uint16_t Ypos, char *Text){
	DISPLAY_DrawString(Xpos, Ypos, &Font8, TEXT_COLOR, Text);
}
