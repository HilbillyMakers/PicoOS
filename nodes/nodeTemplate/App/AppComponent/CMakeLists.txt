add_library(AppComponent_lib
    src/appComponent.h
    src/appComponent.c
)

target_link_libraries(
    pico_stdlib
)