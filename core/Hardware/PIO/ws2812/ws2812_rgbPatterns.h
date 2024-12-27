#ifndef WS2812_RGB_PATTERNS_H
#define WS2812_RGB_PATTERNS_H
#include "pico/stdlib.h"

/* 
Logic: 
    Each pattern has a generator function of the form 
    
    void patternName(uint16_t patternFrameIndex, uint32 *outputBuffer, uint16_t ledNumber)

        outputBuffer - the buffer containing the values for each rgb pixel that will be sent to the SM
        stepNumber   - allows the caller to specify the "frame" of a dynamic pattern. Static patterns are considered to have a single frame
        ledNumber    - number of physical ws2812 modules on the target LED strip

    For patterns requiring the update of the existing buffer, the _volatile suffix should be added
    
    As long as the interface remains consistent across all the patterns, the patternFrameIndex as well as the outputBuffer can be used as
    in any way required, with the assumption that [outputBuffer] will be directly written to the ws2812 modules on function exit
 */

/**
 * @brief A travelling pixel with a hardcoded color (used for basic testing)
 */
void travellingDot              (uint16_t patternFrameIndex, uint32_t *outputBuffer, uint16_t ledNumber);

/**
 * @brief A travelling pixel leaving a trail (used for testing led color and refresh rates)
 */
void travellingDotTrail_volatile(uint16_t patternFrameIndex, uint32_t *outputBuffer, uint16_t ledNumber);


#endif