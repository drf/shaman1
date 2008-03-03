FIND_PACKAGE(KDE4 REQUIRED)
FIND_PACKAGE(Plasma REQUIRED)
INCLUDE_DIRECTORIES( ${KDE4_INCLUDES} )

set(plasma_applet_shaman_SRCS
  shamanApplet.cpp
)

#kde4_add_ui_files(shaman_SRCS shamanConfig.ui)
message(STATUS "PlasmaLibs: " ${PLASMA_LIBS})
kde4_add_plugin(plasma_applet_shaman ${plasma_applet_shaman_SRCS})
target_link_libraries(plasma_applet_shaman ${PLASMA_LIBS} ${KDE4_KDEUI_LIBS})

install(TARGETS plasma_applet_shaman DESTINATION ${PLASMA_INCLUDE_DIR}/../lib/kde4)#Dirty hack for the correct dir, look for sth like PLASMA_PLUGIN_INSTALL_DIR
install(FILES shaman-applet-default.desktop DESTINATION ${PLASMA_INCLUDE_DIR}/../../share/kde4/services/)#Haha the same
