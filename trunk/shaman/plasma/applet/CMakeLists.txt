
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

install(TARGETS plasma_applet_shaman DESTINATION ${KDE4_LIB_DIR}/kde4/)
install(FILES shaman-applet-default.desktop DESTINATION ${KDE4_LIB_DIR}/../share/kde4/services/)
