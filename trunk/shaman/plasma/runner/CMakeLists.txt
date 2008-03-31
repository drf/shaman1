FIND_PACKAGE(KDE4 REQUIRED)
FIND_PACKAGE(Plasma REQUIRED)
INCLUDE_DIRECTORIES( ${KDE4_INCLUDES} )

set(krunner_shaman_SRCS
    shamanRunner.cpp
)

kde4_add_plugin(krunner_shaman ${krunner_shaman_SRCS})
target_link_libraries(krunner_shaman ${PLASMA_LIBS} ${KDE4_KDEUI_LIBS})

install(TARGETS krunner_shaman DESTINATION ${KDE4_LIB_DIR}/kde4/)

install(FILES plasma-runner-shaman.desktop DESTINATION ${KDE4_LIB_DIR}/../share/kde4/services/)

