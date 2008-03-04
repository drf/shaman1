FIND_PACKAGE(KDE4 REQUIRED)
FIND_PACKAGE(Plasma REQUIRED)
INCLUDE_DIRECTORIES( 
    ${KDE4_INCLUDES} 
    ${PLASMA_INCLUDE_DIR}
)

set(shaman_engine_SRCS
    shamanEngine.cpp
)
message(STATUS ""  ${PLASMA_INCLUDE_DIR})

kde4_add_plugin(plasma_engine_shaman ${shaman_engine_SRCS})
target_link_libraries(plasma_engine_shaman ${KDE4_KDECORE_LIBS} ${PLASMA_LIBS})

install(TARGETS plasma_engine_shaman DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES plasma-engine-shaman.desktop DESTINATION ${SERVICES_INSTALL_DIR})
