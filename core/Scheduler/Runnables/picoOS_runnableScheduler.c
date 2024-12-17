///TODO: create a temporary scheduler, before integration of freeRTOS

#include "picoOS_runnableScheduler.h"

/*  */

uint16_t addInitTask   (void* task, uint8_t taskPriority)
{

    return 0u;
}

uint16_t addCyclicTask (void* task, uint8_t taskPriority, uint8_t cycleTimeMs)
{
    return 0u;
}

uint16_t addEventTask  (void* task, uint8_t taskPriority, void*   taskTrigger)
{
    return 0u;
}

uint16_t removeInitTask   (void* task, uint8_t taskPriority)
{
    return 0u;
}

uint16_t removeCyclicTask (void* task, uint8_t taskPriority, uint8_t cycleTimeMs)
{
    return 0u;
}

uint16_t removeEventTask  (void* task, uint8_t taskPriority, void*   taskTrigger)
{
    return 0u;
}

void    runScheduler  (void)
{
    
}