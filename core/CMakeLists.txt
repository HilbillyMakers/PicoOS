add_library(picoOS_lib
    picoOS.h
    picoOS.c
)

add_subdirectory(CanIf)
add_subdirectory(Hardware)

target_link_libraries(picoOS_lib
    canIf_Lib
)   