#ifndef CAN_IF_H
#define CAN_IF_H

#include <stdint.h>

uint8_t setupCanController( uint8_t csPin,        uint8_t   clkPin, 
                            uint8_t misoPin,      uint8_t   mosiPin, 
                            uint8_t frequencyMhz, uint32_t  baudrate
                          );

#endif