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

add_subdirectory(icons)

