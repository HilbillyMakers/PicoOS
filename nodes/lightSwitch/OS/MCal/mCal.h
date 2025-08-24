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

#define CAN_SPI_CS_PIN      0u
#define CAN_SPI_CLK_PIN     0u
#define CAN_SPI_MISO_PIN    0u
#define CAN_SPI_MOSI_PIN    0u

#define CAN_SPI_FREQ_MHZ    0u
#define CAN_SPI_BAUDRATE    0u

/* GPIO config */
#define ENCODER_BUTTON_PIN  0u
#define ENCODER_POS_A_PIN   0u
#define ENCODER_POS_B_PIN   0u

/* PIO config */
#define WS2812_LED_PIN      0u

/* PWM config */
#define MOSFET_WARM_LED_PIN       0u
#define MOSFET_WARM_LED_PWM_FREQ  0u
#define MOSFET_WARM_LED_PWM_WRAP  0u

#define MOSFET_COLD_LED_PIN       0u
#define MOSFET_COLD_LED_PWM_FREQ  0u
#define MOSFET_COLD_LED_PWM_WRAP  0u