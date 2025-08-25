#ifndef CANIF_OS_H
#define CANIF_OS_H

#include "stdint.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"

typedef struct
{
    uint8_t   csPin;
    uint8_t   clkPin;
    uint8_t   misoPin;
    uint8_t   mosiPin;
    uint8_t   frequencyMhz;
    uint32_t  baudrate;
} canController;


#endif