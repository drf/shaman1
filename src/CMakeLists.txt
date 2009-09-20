
qt4_add_dbus_adaptor(shaman_adaptor_SRCS ../dbus/org.archlinux.shaman.xml MainWindow.h MainWindow)

add_subdirectory(config)


SET(shaman_config_SRCS ${shaman_config_adaptor_SRCS}
    config/DatabaseConfig.cpp
    config/MirrorWidget.cpp
    config/ServerWidget.cpp
    config/ThirdPartyWidget.cpp
)

SET(shaman_config_UIS
    config/databaseConfig.ui
    config/mirrorWidget.ui
    config/serverWidget.ui
    config/thirdPartyWidget.ui
)

SET(shaman_SRCS ${shaman_adaptor_SRCS} ${shaman_config_SRCS}
    main.cpp
    MainWindow.cpp
    Shaman.cpp
    BuildingDialog.cpp
    EditPBuild.cpp
    QueueDialog.cpp
    SysUpgradeDialog.cpp
    UpdateDbDialog.cpp
    ABSHandler.cpp
    BuildingHandler.cpp
    kanimatedsystemtrayicon.cpp
    ShamanTrayIcon.cpp
    ReviewQueueDialog.cpp
    ArchLinuxNewsReader.cpp
    NewsViewer.cpp
    LogViewer.cpp
    ShamanDialog.cpp
    ShamanStatusBar.cpp
    PackageProperties.cpp
    ShamanTreeWidgetItem.cpp
    MaintenanceBar.cpp
    LocalPackageDialog.cpp
    ErrorHandler.cpp
)

SET(shaman_UIS ${shaman_config_UIS}
    ../ui/MainWindow.ui
    ../ui/aboutDialog.ui
    ../ui/buildingDialog.ui
    ../ui/dbUpdateDialog.ui
    ../ui/editPBDialog.ui
    ../ui/reviewBuildingDialog.ui
    ../ui/reviewQueueDialog.ui
    ../ui/transactionDialog.ui
    ../ui/upgradeDialog.ui
    ../ui/newsDialog.ui
    ../ui/logViewer.ui
    ../ui/pkgProperties.ui
    ../ui/fromFileDialog.ui
)

SET(shaman_RESOUCES
    ../ui/shaman.qrc
)

QT4_ADD_RESOURCES (qtsourceview_RC_SRCS  ${shaman_RESOUCES})
QT4_WRAP_UI(shaman_UIS_H ${shaman_UIS})
QT4_AUTOMOC(${shaman_SRCS})

AUTOMOC4_ADD_EXECUTABLE(shaman
    ${shaman_SRCS}
    ${shaman_UIS_H}
    ${qtsourceview_RC_SRCS}
)

TARGET_LINK_LIBRARIES(shaman
    ${QT_QTCORE_LIBRARY}
    ${QT_QTGUI_LIBRARY}
    ${QT_QTDBUS_LIBRARY}
    ${QT_QTNETWORK_LIBRARY}
    ${ALPM_LIBS}
    ${LIBARCHIVE_LIBS}
    ${POLKITQT_LIBRARIES}
    ${AQPM_LIBRARY}
)

if (KDE4_INTEGRATION)
target_link_libraries(shaman ${KDE4_KDECORE_LIBS} ${KDE4_KDEUI_LIBS})
endif (KDE4_INTEGRATION)

INSTALL(CODE "MESSAGE(\"Installing Shaman executable...\")")
INSTALL(TARGETS shaman DESTINATION bin)
