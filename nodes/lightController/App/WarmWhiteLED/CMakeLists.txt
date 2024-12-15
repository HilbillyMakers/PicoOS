add_library(WarmWhiteLED_lib
    src/warmWhiteLED.h
    src/warmWhiteLED.c
)

target_link_libraries(WarmWhiteLED_lib
    pico_stdlib
    hardware_pwm
)