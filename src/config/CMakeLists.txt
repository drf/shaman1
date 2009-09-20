add_subdirectory(databases)
add_subdirectory(aqpm)

if (KDE4_INTEGRATION)

install( FILES settings-package-management.desktop  DESTINATION  ${SERVICES_INSTALL_DIR} )

endif (KDE4_INTEGRATION)
