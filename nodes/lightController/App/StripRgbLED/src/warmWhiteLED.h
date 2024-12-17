#ifndef WARM_WHITE_LED_H
#define WARM_WHITE_LED_H

#include <stdint.h>

extern void     init_appComponent (void);
extern void     run_appComponent  (void);
extern uint16_t requested_warmWhite_DutyCycle;
#endif