add_subdirectory(CDD_MosfetLed_WarmWhite)
add_subdirectory(CDD_MosfetLed_ColdWhite)

add_library(lightController_AppLib
    lightControllerApp.h
    lightControllerApp.c
)

target_link_libraries(lightController_AppLib
    WarmWhiteLED_lib
    ColdWhiteLED_lib
)