/*
 * sound.c
 *
 *  Created on: Jan 6, 2026
 *      Author: Admin
 */
#include "sound.h"
#include "stm32h735g_discovery_audio.h"

// Define the buffer pointer pointing to the external HyperRAM
uint16_t *AudioBuffer = (uint16_t *)AUDIO_BUFFER_ADDR;
#define BUFFER_SIZE_WORDS (AUDIO_FREQ * AUDIO_CHANNELS * (RECORD_TIME_MS/1000))

int SOUND_INIT(void)
{
    BSP_AUDIO_Init_t AudioInit;

    // 1. Initialize Microphone (Input)
    AudioInit.Device        = AUDIO_IN_DEVICE_DIGITAL_MIC;
    AudioInit.ChannelsNbr   = AUDIO_CHANNELS;
    AudioInit.SampleRate    = AUDIO_FREQ;
    AudioInit.BitsPerSample = AUDIO_RESOLUTION_16B;
    AudioInit.Volume        = 100;

    if(BSP_AUDIO_IN_Init(0, &AudioInit) != BSP_ERROR_NONE)
    {
        return -1; // Error
    }

    // 2. Initialize Headphone/Speaker (Output)
    AudioInit.Device        = AUDIO_OUT_DEVICE_HEADPHONE;
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
    BSP_AUDIO_IN_Record(0, (uint8_t*)AudioBuffer, BUFFER_SIZE_WORDS * 2);
}

void Sound_StopRecording(void)
{
    BSP_AUDIO_IN_Stop(0);
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

