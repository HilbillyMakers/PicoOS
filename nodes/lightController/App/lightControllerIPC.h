#ifndef LIGHT_CONTROLLER_IPC_H
#define LIGHT_CONTROLLER_IPC_H

#include <stdint.h>

extern uint8_t CanRequest_whiteBalance;
extern uint8_t CanRequest_whiteIntensity;

extern float   requested_ColdWhite;
extern float   requested_WarmWhite;

#endif