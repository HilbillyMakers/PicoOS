add_library(ColdWhiteLED_lib
    src/coldWhiteLED.h
    src/coldWhiteLED.c
    src/coldWhiteLED_IPC.h
)

target_link_libraries(ColdWhiteLED_lib
    pico_stdlib
    hardware_pwm
)