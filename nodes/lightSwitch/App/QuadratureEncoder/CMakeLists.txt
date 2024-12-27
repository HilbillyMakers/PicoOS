add_library(QuadratureEncoder_lib
    src/quadratureEncoder.h
    src/quadratureEncoder.c
)

target_link_libraries(QuadratureEncoder_lib
    pico_stdlib
    hardware_pwm
    # hardware_pio
    pio_quadrature_encoder
)