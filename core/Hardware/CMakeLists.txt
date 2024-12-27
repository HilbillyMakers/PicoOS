add_subdirectory(PIO)
add_subdirectory(SPI)

add_library(osHardwareLib)

target_link_libraries(osHardwareLib PUBLIC
    pioLib
)