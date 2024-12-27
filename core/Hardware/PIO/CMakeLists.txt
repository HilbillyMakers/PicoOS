add_subdirectory(pio_allocator)
add_subdirectory(quadrature_encoder)
add_subdirectory(ws2812)


add_library(pioLib)

target_link_libraries(pioLib PUBLIC
    pio_quadrature_encoder) 