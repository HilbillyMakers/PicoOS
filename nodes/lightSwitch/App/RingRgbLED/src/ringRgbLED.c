#include "ringRgbLED.h"
#include "../../../core/Hardware/PIO/ws2812/ws2812.h"

#define RGB_LED_RING_DATA_PIN     13u
#define RGB_LED_RING_PIXEL_NUMBER 16u
#define RGB_LED_RING_ENCODER_PIO  pio1
#define RGB_LED_RING_SM           1
#define RGB_LED_RING_SM_FREQ      8000000

ws2812_sm rgbConfig = 
{
    .smID                 = RGB_LED_RING_SM,
    .pin                  = RGB_LED_RING_DATA_PIN,
    .ledNumber            = RGB_LED_RING_PIXEL_NUMBER,
    .currentPatternIndex  = 0u,

    .notificationType     = SM_WS2812_N_NONE,
    .sm_state             = SM_WS2812_UNINIT,
    .sm_request           = SM_WS2812_R_NONE
};

void init_ringRgbLED(void)
{
    init_ws2812(&rgbConfig);
}

void run_ringRgbLED(void)
{
    ws2812_loadPattern(&rgbConfig);
}