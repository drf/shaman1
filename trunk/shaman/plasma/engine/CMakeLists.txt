
INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_BINARY_DIR}
)

set(shaman_engine_SRCS
    shamanEngine.cpp
)

kde4_add_plugin(plasma_engine_shaman ${shaman_engine_SRCS})
target_link_libraries(plasma_engine_shaman ${KDE4_KDECORE_LIBS} ${PLASMA_LIBS})

install(TARGETS plasma_engine_shaman DESTINATION ${KDE4_LIB_DIR}/kde4)
install(FILES plasma-engine-shaman.desktop DESTINATION ${KDE4_LIB_DIR}/../share/kde4/services/)
