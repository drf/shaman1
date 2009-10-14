
qt4_add_dbus_adaptor(shaman_adaptor_SRCS ../dbus/org.archlinux.shaman.xml MainWindow.h MainWindow)

add_subdirectory(config)

if (NOT KDE4_INTEGRATION)
    SET(shaman_config_SRCS
        config/databases/DatabaseConfig.cpp
        config/aqpm/AqpmConfig.cpp
        config/databases/MirrorWidget.cpp
        config/databases/ServerWidget.cpp
        config/databases/ThirdPartyWidget.cpp
        config/shamangeneral/ShamanGeneralConfig.cpp
        config/ConfigDialog.cpp
    )

    SET(shaman_config_UIS
        config/databases/databaseConfig.ui
        config/aqpm/aqpmConfig.ui
        config/databases/mirrorWidget.ui
        config/databases/serverWidget.ui
        config/databases/thirdPartyWidget.ui
        config/shamangeneral/shamanGeneral.ui
        config/configDialog.ui
    )
endif (NOT KDE4_INTEGRATION)

set(shaman_SRCS ${shaman_adaptor_SRCS} ${shaman_config_SRCS}
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
    ShamanIcon.cpp
)

set(shaman_UIS ${shaman_config_UIS}
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

set(shaman_RESOUCES
    ../ui/shaman.qrc
)

qt4_add_resources (qtsourceview_RC_SRCS  ${shaman_RESOUCES})
qt4_wrap_ui (shaman_UIS_H ${shaman_UIS})

automoc4_add_executable(shaman
    ${shaman_SRCS}
    ${shaman_UIS_H}
    ${qtsourceview_RC_SRCS}
)

target_link_libraries(shaman
    ${QT_QTCORE_LIBRARY}
    ${QT_QTGUI_LIBRARY}
    ${QT_QTDBUS_LIBRARY}
    ${QT_QTNETWORK_LIBRARY}
    ${POLKITQT_LIBRARIES}
    ${AQPM_LIBRARY}
)

if (KDE4_INTEGRATION)
    target_link_libraries(shaman ${KDE4_KDECORE_LIBS} ${KDE4_KDEUI_LIBS} ${KDE4_KUTILS_LIBS})
endif (KDE4_INTEGRATION)

install(CODE "message(\"Installing Shaman executable...\")")
install(TARGETS shaman DESTINATION bin)
