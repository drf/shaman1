add_subdirectory(databases)
add_subdirectory(aqpm)
add_subdirectory(shamangeneral)

if (KDE4_INTEGRATION)

install( FILES settings-package-management.desktop  DESTINATION  ${SERVICES_INSTALL_DIR} )

endif (KDE4_INTEGRATION)
