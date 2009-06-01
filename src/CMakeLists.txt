
qt4_add_dbus_adaptor(shaman_adaptor_SRCS ../dbus/org.archlinux.shaman.xml MainWindow.h MainWindow)

SET(shaman_SRCS ${shaman_adaptor_SRCS}
    main.cpp
    MainWindow.cpp
    Shaman.cpp
    BuildingDialog.cpp
    configDialog.cpp
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

SET(shaman_UIS
    ../ui/MainWindow.ui
    ../ui/aboutDialog.ui
    ../ui/buildingDialog.ui
    ../ui/configDialog.ui
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
    -laqpm
)

INSTALL(CODE "MESSAGE(\"Installing Shaman executable...\")")
INSTALL(TARGETS shaman DESTINATION bin)
