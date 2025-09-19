add_library(mcp2518_spi_lib
        defines.h
        registers.h
        MCP2518_spi.c
        MCP2518_spi.h
        MCP2518_can.c
        MCP2518_can.h

)

target_link_libraries(mcp2518_spi_lib PUBLIC
        pico_stdlib
        hardware_spi
        hardware_dma
)