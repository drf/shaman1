INSTALL(CODE "MESSAGE(\"Installing Shaman DBus Configuration File...\")")
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/shaman.conf DESTINATION /etc/dbus-1/system.d)
INSTALL(CODE "MESSAGE(\"Installing Shaman Desktop File...\")")
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/shaman.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)

# for KDE 4.1 we require at least version 0.20
set(SHARED_MIME_INFO_MINIMUM_VERSION "0.20")
find_package(SharedMimeInfo)

if(KDE4_FOUND)
########### install files ###############
    INSTALL(CODE "MESSAGE(\"Installing Archlinux Package Mimetypes...\")")
    install(FILES shaman.xml DESTINATION ${XDG_MIME_INSTALL_DIR})
    update_xdg_mimetypes(${XDG_MIME_INSTALL_DIR})

endif(KDE4_FOUND)

INSTALL(CODE "MESSAGE(\"Installing Miscellaneous Shaman Files...\")")
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kdemodmirrorlist DESTINATION /etc/pacman.d)