#include "quadratureEncoder.h"
#include "../../../core/Hardware/PIO/quadrature_encoder/quadrature_encoder.pio.h"

#define ENCODER_SM      0
#define ENCODER_PIO     pio0
#define ENCODER_AB_PIN  10
#define MAX_STEP_RATE   0u

void init_quadratureEncoder(void)
{
    pio_add_program                 (ENCODER_PIO, &quadrature_encoder_program);
    quadrature_encoder_program_init (ENCODER_PIO, ENCODER_SM, ENCODER_AB_PIN, MAX_STEP_RATE);
}

void run_quadratureEncoder(void)
{
    encoderPosition_ipc = quadrature_encoder_get_count(ENCODER_PIO, ENCODER_SM);
}