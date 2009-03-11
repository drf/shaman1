
SET(shaman_UIS
    MainWindow.ui
    aboutDialog.ui
    buildingDialog.ui
    configDialog.ui
    dbUpdateDialog.ui
    editPBDialog.ui
    reviewBuildingDialog.ui
    reviewQueueDialog.ui
    transactionDialog.ui
    upgradeDialog.ui
    newsDialog.ui
    logViewer.ui
    authDialog.ui
    pkgProperties.ui
    fromFileDialog.ui
)

SET(shaman_RESOUCES
    shaman.qrc
)

QT4_WRAP_UI(shaman_UIS_H ${shaman_UIS})

INSTALL(CODE "MESSAGE(\"Installing Shaman Icons...\")")
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/icons/shaman/shaman-32.png
		${CMAKE_CURRENT_SOURCE_DIR}/icons/shaman/shaman-64.png
		${CMAKE_CURRENT_SOURCE_DIR}/icons/shaman/shaman-128.png ${CMAKE_CURRENT_SOURCE_DIR}/icons/shaman/shaman-48.png
		${CMAKE_CURRENT_SOURCE_DIR}/icons/shaman/application-x-shaman-package.png
		DESTINATION ${CMAKE_INSTALL_PREFIX}/share/pixmaps)
