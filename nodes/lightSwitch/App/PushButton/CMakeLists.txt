add_library(PushButton_lib
    src/pushButton.h
    src/pushButton.c
)

target_link_libraries(PushButton_lib PUBLIC
    pico_stdlib
    hardware_pwm
    pio_quadrature_encoder
)