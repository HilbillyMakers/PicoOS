add_library(canIf_Lib
        canIf.h
        canIf.c
        canSM.c
        canSM.h
        )

target_link_libraries(canIf_Lib 
        pico_stdlib 
        hardware_spi 
        hardware_dma
        )