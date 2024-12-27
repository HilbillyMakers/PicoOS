add_executable(lightSwitchBin
    lightSwitch.h    
    lightSwitch.c    
)

add_subdirectory(App)
add_subdirectory(OS)

target_link_libraries(lightSwitchBin
    lightSwitch_OsLib
    lightSwitch_AppLib
)