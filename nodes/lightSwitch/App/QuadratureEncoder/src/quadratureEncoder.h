#ifndef QUADRATURE_ENCODER_H
#define QUADRATURE_ENCODER_H

#include <stdint.h>

extern uint32_t encoderPosition_ipc;

void init_quadratureEncoder (void);
void run_quadratureEncoder  (void);

#endif