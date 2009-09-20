
install(CODE "MESSAGE(\"Installing Shaman Desktop File...\")")
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/shaman.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)

if(KDE4_FOUND)
########### install files ###############
    install(CODE "MESSAGE(\"Installing Archlinux Package Mimetypes...\")")
    install(FILES shaman.xml DESTINATION ${XDG_MIME_INSTALL_DIR})
    update_xdg_mimetypes(${XDG_MIME_INSTALL_DIR})

endif(KDE4_FOUND)

if (KDE4_INTEGRATION)
    install( FILES shaman.notifyrc DESTINATION ${DATA_INSTALL_DIR}/shaman )
endif (KDE4_INTEGRATION)

if (NOT NO_ROOT_INSTALL)
    install(CODE "MESSAGE(\"Installing Shaman DBus Configuration File...\")")
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/shaman.conf DESTINATION /etc/dbus-1/system.d)
    install(CODE "MESSAGE(\"Installing Miscellaneous Shaman Files...\")")
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kdemodmirrorlist DESTINATION /etc/pacman.d)
endif (NOT NO_ROOT_INSTALL)
