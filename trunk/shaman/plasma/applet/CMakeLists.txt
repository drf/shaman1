
INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_BINARY_DIR}
)

set(plasma_applet_shaman_SRCS
  shamanApplet.cpp
  AbstractView.cpp
  ErrorView.cpp
  IdleView.cpp
  TransactionView.cpp
)

kde4_add_plugin(plasma_applet_shaman 
	${plasma_applet_shaman_SRCS}
)

target_link_libraries(plasma_applet_shaman 
	${PLASMA_LIBS} 
	${KDE4_KDEUI_LIBS}
	${KDE4_KIO_LIBS}
)

install(TARGETS plasma_applet_shaman DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES shaman-applet-default.desktop DESTINATION ${SERVICES_INSTALL_DIR})
