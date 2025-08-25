#ifndef DEM_SM_H
#define DEM_SM_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct 
{
    uint8_t occured                     : 1;
    uint8_t occured_this_cycle          : 1;
    uint8_t event_confirmation_pending  : 1;
    uint8_t event_confirmed             : 1;
    uint8_t not_tested_since_last_clear : 1;
    uint8_t test_failed_since_clear     : 1;
    uint8_t not_tested_this_cycle       : 1;
    uint8_t warning_indicator_requested : 1;
} DEM_Event_State;

typedef enum
{
    DEM_EVENT_PREPASSED,
    DEM_EVENT_PASSED,
    DEM_EVENT_PREFAILED,
    DEM_EVENT_FAILED
} DEM_Event_Update;

typedef struct
{
    uint8_t             ID;
    DEM_Event_State     state;
    DEM_Event_Update    updatedState;
    uint8_t             prefail_number;
    uint8_t             prefail_limit;
} DEM_Event;

void init_DEM_SM();
void run_DEM_SM ();

#endif