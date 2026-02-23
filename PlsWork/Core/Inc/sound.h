/*
 * sound.h
 *
 *  Created on: Jan 6, 2026
 *      Author: Admin
 */

#ifndef INC_SOUND_H_
#define INC_SOUND_H_

#include "parotconf.h"
#include <stdlib.h>

#define AUDIO_FREQ           16000  // 16kHz Sample Rate
#define AUDIO_CHANNELS       2      // Stereo
#define AUDIO_BITS_PER_SAMP  16     // 16-bit audio
#define RECORD_TIME_MS       5000

// Memory Location (OSPI RAM Offset from Image Data to prevent access conflicts)
#define AUDIO_BUFFER_ADDR    0x70100000

// Functions
int SOUND_INIT(void);
void Sound_StartRecording(void);
void Sound_StopRecording(void);
void Sound_StartPlayback(void);
void Sound_StopPlayback(void);
uint16_t Sound_GetInputLevel(uint32_t elapsed_time_ms);
void Sound_GenerateTestTone(void);

#endif /* INC_SOUND_H_ */
