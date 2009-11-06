set(shaman_firstrun_SRCS ${shaman_firstrun_adaptor_SRCS} ${shaman_firstrun_config_SRCS}
    firstrunwizard.cpp
    intropage.cpp
    securitypage.cpp
    firstrun_main.cpp
    configurationpage.cpp
    kdepage.cpp
    finishpage.cpp
)

# set(shaman_firstrun_UIS ${shaman_firstrun_config_UIS}
# ../ui/MainWindow.ui
# ../ui/aboutDialog.ui
# ../ui/buildingDialog.ui
# ../ui/dbUpdateDialog.ui
# ../ui/editPBDialog.ui
# ../ui/reviewBuildingDialog.ui
# ../ui/reviewQueueDialog.ui
# ../ui/transactionDialog.ui
# ../ui/upgradeDialog.ui
# ../ui/newsDialog.ui
# ../ui/logViewer.ui
# ../ui/pkgProperties.ui
# ../ui/fromFileDialog.ui
# )

#set(shaman_firstrun_RESOUCES
#../ui/shaman_firstrun.qrc
#)

#qt4_add_resources (qtsourceview_RC_SRCS  ${shaman_firstrun_RESOUCES})
#qt4_wrap_ui (shaman_firstrun_UIS_H ${shaman_firstrun_UIS})

automoc4_add_executable(shaman_firstrun
${shaman_firstrun_SRCS}
# ${shaman_firstrun_UIS_H}
# ${qtsourceview_RC_SRCS}
)

target_link_libraries(shaman_firstrun
${QT_QTCORE_LIBRARY}
${QT_QTGUI_LIBRARY}
)

if (KDE4_INTEGRATION)
    target_link_libraries(shaman_firstrun ${KDE4_KDEUI_LIBRARY})
endif (KDE4_INTEGRATION)
