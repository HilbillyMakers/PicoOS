#ifndef PICO_OS_H
#define PICO_OS_H

#include <stdint.h>

typedef enum
{
    NODE_UNDEFINED,
    NODE_LIGHT_SWITCH,
    NODE_LIGHT_CONTROLLER,

    NODE_UNKNOWN
} NodeType;

/* 
 * picoOS node configuration structure
 */
typedef struct
{
    NodeType nodeType;
    uint8_t  nodeID;



} picoOS_config;

uint8_t init_picoOS (picoOS_config* config);
uint8_t run_picoOS  (void);

#endif