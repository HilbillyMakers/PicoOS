add_subdirectory(AppComponent)

add_library(nodeTemplate_AppLib
    nodeTemplateSM.h
    nodeTemplateSM.c
)

target_link_libraries(nodeTemplate_AppLib
    AppComponent
)