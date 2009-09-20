if (KDE4_INTEGRATION)
    ########### next target ###############

    set(kcm_shamangeneral_PART_SRCS
        ShamanGeneralConfig.cpp
        ../../ShamanDialog.cpp
        ../../ShamanIcon.cpp
    )

    kde4_add_ui_files(kcm_shamangeneral_PART_SRCS
        shamanGeneral.ui
    )

    qt4_add_resources (qtsourceview_RC_SRCS  ../../../ui/shaman.qrc)

    kde4_add_plugin(kcm_shamangeneral ${kcm_shamangeneral_PART_SRCS} ${qtsourceview_RC_SRCS})

    target_link_libraries(kcm_shamangeneral ${KDE4_KDEUI_LIBS} ${POLKITQT_LIBRARIES} ${AQPM_LIBRARY})

    install(TARGETS kcm_shamangeneral  DESTINATION ${PLUGIN_INSTALL_DIR} )

    ########### install files ###############

    install( FILES kcmshamangeneral.desktop  DESTINATION  ${SERVICES_INSTALL_DIR} )

endif (KDE4_INTEGRATION)
