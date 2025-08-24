add_library(WarmWhiteLED_lib
    src/CDD_MosfetLed_WarmWhite.h
    src/CDD_MosfetLed_WarmWhite.c
)

target_link_libraries(WarmWhiteLED_lib
    pico_stdlib
    hardware_pwm
)