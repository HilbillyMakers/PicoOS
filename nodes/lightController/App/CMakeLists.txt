add_subdirectory(ColdWhiteLED)
add_subdirectory(WarmWhiteLED)

add_library(lightController_AppLib
    lightControllerSM.h
    lightControllerSM.c
)

target_link_libraries(lightController_AppLib
    WarmWhiteLED_lib
    ColdWhiteLED_lib
)