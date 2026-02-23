/*
 * sound.c
 *
 *  Created on: Jan 6, 2026
 *      Author: Admin
 */
#include "sound.h"
#include "stm32h735g_discovery_audio.h"
#define InputInstance 2

// Define the buffer pointer pointing to the external HyperRAM
uint16_t *AudioBuffer = (uint16_t *)AUDIO_BUFFER_ADDR;
#define BUFFER_SIZE_WORDS (AUDIO_FREQ * AUDIO_CHANNELS * (RECORD_TIME_MS/1000))

int SOUND_INIT(void)
{
    BSP_AUDIO_Init_t AudioInit;

    // 1. Initialize Microphone (Input)
    AudioInit.Device        = AUDIO_IN_DEVICE_DIGITAL_MIC1;
    AudioInit.ChannelsNbr   = 1;
    AudioInit.SampleRate    = AUDIO_FREQ;
    AudioInit.BitsPerSample = AUDIO_RESOLUTION_16B;
    AudioInit.Volume        = 100;

    // Instace 0 = analog input, Instance 2 = DFSDM
    if(BSP_AUDIO_IN_Init(InputInstance, &AudioInit) != BSP_ERROR_NONE)
    {
        return -1; // Error
    }

    // 2. Initialize Headphone/Speaker (Output)
    AudioInit.Device        = AUDIO_OUT_DEVICE_HEADPHONE;
    AudioInit.ChannelsNbr   = AUDIO_CHANNELS;
    AudioInit.Volume        = 70;

    if(BSP_AUDIO_OUT_Init(0, &AudioInit) != BSP_ERROR_NONE)
    {
        return -1; // Error
    }

    return 0; // Success
}

void Sound_StartRecording(void)
{
    // Multiply by 2 because the function expects size in Bytes, not Words
    BSP_AUDIO_IN_Record(InputInstance, (uint8_t*)AudioBuffer, BUFFER_SIZE_WORDS * 2);
}

void Sound_StopRecording(void)
{
    BSP_AUDIO_IN_Stop(InputInstance);
}

void Sound_StartPlayback(void)
{
    // Multiply by 2 for Bytes
    BSP_AUDIO_OUT_Play(0, (uint8_t*)AudioBuffer, BUFFER_SIZE_WORDS * 2);
}

void Sound_StopPlayback(void)
{
    BSP_AUDIO_OUT_Stop(0);
}

// Helper to get current volume (Amplitude 0-32767)
uint16_t Sound_GetInputLevel(uint32_t elapsed_time_ms)
{
    // 1. Calculate roughly where the DMA is currently writing
    uint32_t current_index = (AUDIO_FREQ * AUDIO_CHANNELS * elapsed_time_ms)/ 1000;

    //Safety
    if (current_index >= BUFFER_SIZE_WORDS) {
        current_index = BUFFER_SIZE_WORDS - 1;
    }

    // 2. Look at the last 100 samples for avg audio.
    uint32_t lookback = 100;
    if (current_index < lookback) lookback = current_index;

    uint32_t sum = 0;
    for (uint32_t i = 0; i < lookback; i++)
    {
        int16_t sample = (int16_t)AudioBuffer[current_index - i];
        sum += abs(sample);
    }

    if (lookback == 0) return 0;
    return (uint16_t)(sum / lookback);
}
