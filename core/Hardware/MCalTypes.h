#ifndef MCAL_TYPES.H
#define MCAL_TYPES.H


#include "stdint.h"

/* SPI config */
typedef struct
{
    uint8_t   cs_pin;
    uint8_t   clk_pin;
    uint8_t   miso_pin;
    uint8_t   mosi_pin;
    uint8_t   freq_mhz;
} spi_config;

#endif