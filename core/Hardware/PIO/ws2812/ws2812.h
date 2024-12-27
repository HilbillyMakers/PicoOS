#ifndef WS2812_H
#define WS2812_T

#include <stdio.h>
#include "ws2812_rgbPatterns.h"

#define BUTTON_PRESSED  true
#define BUTTON_RELEASED false


typedef enum
{
    SM_WS2812_UNINIT,
    SM_WS2812_STATIC,
    SM_WS2812_DYNAMIC,
    SM_WS2812_STOPPED,
    SM_WS2812_FAULT
}ws2812_sm_state;

typedef enum
{
    SM_WS2812_E_OK,
    SM_WS2812_E_PIO_PROGRAM,        //The PIO program could not be loaded into memory at the requested offset
    SM_WS2812_E_UNINITIALIZED,
    SM_WS2812_E_UNKNOWN_STATE,
    SM_WS2812_E_UNKNOWN_REQUEST,
    SM_WS2812_E_REQUEST_SEQUENCE,
    SM_WS2812_E_STARTED_FROM_FAULT,
    SM_WS2812_E_FAULT_NOT_RESOLVED,

    SM_WS2812_E_NOK
}ws2812_sm_error;

typedef enum
{
    SM_WS2812_N_NONE,

    /* Errors are arranged in increasing order */
    SM_WS2812_N_LOW_PRIO_ERROR,
    SM_WS2812_N_MEDIUM_PRIO_ERROR,
    SM_WS2812_N_HIGH_PRIO_ERROR
}ws2812_sm_notificationType;

typedef enum
{
    SM_WS2812_R_NONE,
    SM_WS2812_R_START,
    SM_WS2812_R_STOP,
    SM_WS2812_R_RESET
}ws2812_sm_request;

typedef struct 
{
    uint8_t                     smID;
    uint8_t                     pin;

    uint16_t                    ledNumber;
    uint8_t                     currentPatternIndex;
    uint16_t*                   patternBuffer;

    ws2812_sm_notificationType  notificationType;
    ws2812_sm_state             sm_state;
    ws2812_sm_request           sm_request;
}ws2812_sm;

ws2812_sm_error init_ws2812         (ws2812_sm* sm_data);
ws2812_sm_error ws2812_loadPattern  (ws2812_sm* sm_data);

#endif