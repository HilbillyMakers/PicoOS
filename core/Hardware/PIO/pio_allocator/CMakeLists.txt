add_library(pioAllocatorLib
    pio_allocator.h
    pio_allocator.c
)

target_link_libraries(pioAllocatorLib PUBLIC
        pico_stdlib
        hardware_pio
)