add_library(ColdWhiteLED_lib
    src/CDD_MosfetLed_ColdWhite.h
    src/CDD_MosfetLed_ColdWhite.c
)

target_link_libraries(ColdWhiteLED_lib
    pico_stdlib
    hardware_pwm
)