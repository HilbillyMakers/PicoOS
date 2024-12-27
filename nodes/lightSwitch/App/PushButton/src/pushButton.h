#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

#include <stdint.h>
#include <stdbool.h>


extern bool     pushButtonState_ipc;
extern uint32_t pushButtonTimePressed_ipc;

void init_pushButton(void);
void run_pushButton (void);

#endif