#include "canIf.h"
#include <stdint.h>
#include "hardware/spi.h"
#include "../Hardware/SPI/MCP2515/MCP2515_can.h"

typedef struct 
{
    uint8_t   csPin;
    uint8_t   clkPin;
    uint8_t   misoPin;
    uint8_t   mosiPin;
    uint8_t   frequencyMhz;
    uint32_t  baudrate;
} canController;

uint8_t setupCanController( uint8_t csPin,        uint8_t   clkPin, 
                            uint8_t misoPin,      uint8_t   mosiPin, 
                            uint8_t frequencyMhz, uint32_t  baudrate
                          )
{
    return 0u;
}