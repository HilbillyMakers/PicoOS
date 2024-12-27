#include "ws2812_rgbPatterns.h"


#define NEUTRAL_WHITE ((uint32_t) (127) << 16) | ((uint32_t) (127) << 8 ) | ((uint32_t) (127) << 0 )

/* Local helper functions */
static uint32_t pixelFade(uint32_t pixel, float fadeFactor)
{
    uint8_t green = ((pixel >> 24) & 0xff) * fadeFactor;
    uint8_t red   = ((pixel >> 16) & 0xff) * fadeFactor;
    uint8_t blue  = ((pixel >> 8 ) & 0xff) * fadeFactor;

    return  ((uint32_t) (green) << 24) |
            ((uint32_t) (red  ) << 16) |
            ((uint32_t) (blue ) << 8 ) ;
}

/* Pattern functions */
void travellingDot(uint16_t patternFrameIndex, uint32_t *outputBuffer, uint16_t ledNumber)
{
    uint16_t index = 0u;
    
    for(index; index < ledNumber; ++index)
    {
        outputBuffer[index] = (patternFrameIndex == index) * NEUTRAL_WHITE;
    }
}

void travellingDotTrail_volatile(uint16_t patternFrameIndex, uint32_t *outputBuffer, uint16_t ledNumber)
{
    const float fadeFactor = 0.5f;

    uint16_t index = 0u;
    
    for(index; index < ledNumber; ++index)
    {
        outputBuffer[index] = \
        /* If index matches frame, color the pixel white */
        (patternFrameIndex == index) * NEUTRAL_WHITE + \
        /* If index doesn't match the frame  */
        (patternFrameIndex != index) * pixelFade(outputBuffer[index], fadeFactor);
    }
}

