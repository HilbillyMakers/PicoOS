add_executable(lightControllerBin
    lightController.h    
    lightController.c    
)

add_subdirectory(App)
add_subdirectory(OS)

target_link_libraries(lightControllerBin
    lightController_OsLib
    lightController_AppLib
)

# create map/bin/hex file etc.
pico_add_extra_outputs(lightControllerBin)