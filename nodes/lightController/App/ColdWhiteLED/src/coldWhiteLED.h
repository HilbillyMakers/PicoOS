#ifndef COLD_WHITE_LED_H
#define COLD_WHITE_LED_H

#include <stdint.h>

extern void     init_appComponent (void);
extern void     run_appComponent  (void);
extern uint16_t requested_coldWhite_DutyCycle;

#endif