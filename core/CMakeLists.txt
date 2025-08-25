add_library(picoOS_lib
    picoOS.h
    picoOS.c
)

add_subdirectory(Hardware)
add_subdirectory(CanIf)

target_link_libraries(picoOS_lib
    canIf_Lib

)