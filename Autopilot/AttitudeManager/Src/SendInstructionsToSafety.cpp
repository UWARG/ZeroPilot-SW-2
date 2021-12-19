#include "SendInstructionsToSafety.hpp"
#include "Interchip_A.h"
#include <cstdint>
#define PWM_CHANNELS 12

static int16_t pwmPercentages[PWM_CHANNELS] = {0};
static int16_t initialPWMPercentages[PWM_CHANNELS] = {0}; // Initially set to 0 since motors are at rest


void SendToSafety_Init(void)
{
    for(int i = 0; i < PWM_CHANNELS; i++)
    {
        pwmPercentages[i] = initialPWMPercentages[i];
    }
}

SendToSafety_error_t updatePWM(int channel, int percent)
{
    SendToSafety_error_t error;
    error.errorCode = 0;
    
    //TODO: Add in something that can update the error code if required
    //THIS IS TOP LEVEL PRIORITY ONCE INTERCHIP IS WRITTEN!!
    pwmPercentages[channel] = percent;
    Interchip_SetPWM(channel, percent);
    
    return error;
}
