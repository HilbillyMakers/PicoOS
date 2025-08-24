add_library(libDEM
    DiagnosticEventManager.h
    DiagnosticEventManager.c
    DEM_SM.h
    DEM_SM.c
)

target_link_libraries(libDEM
    pico_stdlib
)