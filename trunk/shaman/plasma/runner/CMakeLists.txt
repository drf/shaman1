INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_BINARY_DIR}
)

set(krunner_shaman_SRCS
    shamanRunner.cpp
)

SET(shamanRunner_RESOUCES
    ../../ui/shamanRunner.qrc
)

QT4_ADD_RESOURCES (qtsourceview_RC_SRCS  ${shamanRunner_RESOUCES})

kde4_add_plugin(krunner_shaman ${krunner_shaman_SRCS} ${qtsourceview_RC_SRCS})
target_link_libraries(krunner_shaman ${PLASMA_LIBS} ${KDE4_KDEUI_LIBS} ${KDE4_KIO_LIBS})

install(TARGETS krunner_shaman DESTINATION ${PLUGIN_INSTALL_DIR})

install(FILES plasma-runner-shaman.desktop DESTINATION ${SERVICES_INSTALL_DIR})

