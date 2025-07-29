add_subdirectory(PushButton)
add_subdirectory(QuadratureEncoder)
add_subdirectory(RingRgbLED)

add_library(lightSwitch_AppLib
    lightSwitchSM.h
    lightSwitchSM.c
)

target_link_libraries(lightSwitch_AppLib
    PushButton_lib
    QuadratureEncoder_lib
    RingRgbLED_lib
)