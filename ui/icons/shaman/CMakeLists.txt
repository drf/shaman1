install(CODE "MESSAGE(\"Installing Shaman Icons...\")")

shaman_install_icons (${ICON_INSTALL_DIR})

#And the package icon
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/application-x-shaman-package.png
        DESTINATION ${CMAKE_INSTALL_PREFIX}/share/pixmaps)
