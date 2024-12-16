add_library(lightSwitch_OsLib
    os.c
)

# add_subdirectory(CanIf)
# add_subdirectory(MCal)
# add_subdirectory(Faults)

target_link_libraries(lightSwitch_OsLib
    picoOS_lib
)