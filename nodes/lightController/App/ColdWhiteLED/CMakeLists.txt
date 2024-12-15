add_library(ColdWhiteLED_lib
    src/coldWhiteLED.h
    src/coldWhiteLED.c
)

target_link_libraries(ColdWhiteLED_lib
    pico_stdlib
    hardware_pwm
)