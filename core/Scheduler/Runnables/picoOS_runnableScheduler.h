///TODO: create a temporary scheduler, before integration of freeRTOS

#include <stdint.h>

typedef enum
{
    INIT_TASK,
    CYCLIC_TASK,
    EVENT_TASK,
} RunnableType;

/* Functions return the ID of the task in the queues */

uint16_t addInitTask   (void* task, uint8_t taskPriority);
uint16_t addCyclicTask (void* task, uint8_t taskPriority, uint8_t cycleTimeMs);
uint16_t addEventTask  (void* task, uint8_t taskPriority, void*   taskTrigger);

uint16_t addInitTask   (void* task, uint8_t taskPriority);
uint16_t addCyclicTask (void* task, uint8_t taskPriority, uint8_t cycleTimeMs);
uint16_t addEventTask  (void* task, uint8_t taskPriority, void*   taskTrigger);

void    runScheduler  (void);