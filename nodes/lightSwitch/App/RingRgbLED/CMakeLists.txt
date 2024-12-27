add_library(RingRgbLED_lib
    src/ringRgbLED.h
    src/ringRgbLED.c
)

target_link_libraries(RingRgbLED_lib
    pico_stdlib
    hardware_pwm
    pio_ws2812
)