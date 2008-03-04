FIND_PACKAGE(KDE4 REQUIRED)
FIND_PACKAGE(Plasma REQUIRED)
INCLUDE_DIRECTORIES( ${KDE4_INCLUDES} )

set(plasma_applet_shaman_SRCS
  shamanApplet.cpp
)

kde4_add_plugin(plasma_applet_shaman ${plasma_applet_shaman_SRCS})
target_link_libraries(plasma_applet_shaman ${PLASMA_LIBS} ${KDE4_KDEUI_LIBS})

install(TARGETS plasma_applet_shaman DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/kde4/)
install(FILES shaman-applet-default.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/kde4/services/)
