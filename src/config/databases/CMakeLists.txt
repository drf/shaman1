
if (KDE4_INTEGRATION)
    ########### next target ###############

    set(kcm_aqpmdatabases_PART_SRCS
        DatabaseConfig.cpp
        MirrorWidget.cpp
        ServerWidget.cpp
        ThirdPartyWidget.cpp
        ../../ShamanDialog.cpp
        ../../ShamanIcon.cpp
    )

    kde4_add_ui_files(kcm_aqpmdatabases_PART_SRCS
        databaseConfig.ui
        mirrorWidget.ui
        serverWidget.ui
        thirdPartyWidget.ui
    )

    qt4_add_resources (qtsourceview_RC_SRCS  ../../../ui/shaman.qrc)

    kde4_add_plugin(kcm_aqpmdatabases ${kcm_aqpmdatabases_PART_SRCS} ${qtsourceview_RC_SRCS})

    target_link_libraries(kcm_aqpmdatabases ${KDE4_KDEUI_LIBS} ${POLKITQT_LIBRARIES} ${AQPM_LIBRARY})

    install(TARGETS kcm_aqpmdatabases  DESTINATION ${PLUGIN_INSTALL_DIR} )

    ########### install files ###############

    install( FILES kcmaqpmdatabases.desktop  DESTINATION  ${SERVICES_INSTALL_DIR} )

endif (KDE4_INTEGRATION)