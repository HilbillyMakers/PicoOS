add_library(libDEM
    DiagnosticEventManager.h
    DiagnosticEventManager.c
    DEM_SM.h
    DEM_SM.c
    DEM_If.h
    DEM_If.c
    DEM_Event_List.h
)

target_link_libraries(libDEM
    pico_stdlib
)