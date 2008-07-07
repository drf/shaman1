PROJECT(shaman)

CMAKE_MINIMUM_REQUIRED(VERSION 2.4.0)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

include(FindQt4)
include(FindSharedMimeInfo)

configure_file(config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h )

qt4_add_dbus_adaptor(shaman_adaptor_SRCS dbus/org.archlinux.shaman.xml src/MainWindow.h MainWindow)

MACRO (MACRO_OPTIONAL_FIND_PACKAGE _name )
   OPTION(WITH_${_name} "Search for ${_name} package" ON)
   if (WITH_${_name})
      FIND_PACKAGE(${_name} ${ARGN})
   else (WITH_${_name})
      set(${_name}_FOUND)
      set(${_name}_INCLUDE_DIR)
      set(${_name}_INCLUDES)
      set(${_name}_LIBRARY)
      set(${_name}_LIBRARIES)
   endif (WITH_${_name})
ENDMACRO (MACRO_OPTIONAL_FIND_PACKAGE)

FIND_PACKAGE(KDE4)
FIND_PACKAGE(Plasma)

if(NOT NO_PLASMA)

	if (PLASMA_FOUND)
    		add_subdirectory(plasma)
	endif(PLASMA_FOUND)
	
endif(NOT NO_PLASMA)

SET(shaman_SRCS ${shaman_adaptor_SRCS}
    src/main.cpp
    src/MainWindow.cpp
    src/AlpmHandler.cpp
    src/BuildingDialog.cpp
    src/callbacks.cpp
    src/configDialog.cpp
    src/ConfigurationParser.cpp
    src/EditPBuild.cpp
    src/QueueDialog.cpp
    src/SysUpgradeDialog.cpp
    src/UpdateDbDialog.cpp
    src/ABSHandler.cpp
    src/BuildingHandler.cpp
    src/kanimatedsystemtrayicon.cpp
    src/ShamanTrayIcon.cpp
    src/ReviewQueueDialog.cpp
    src/ArchLinuxNewsReader.cpp
    src/NewsViewer.cpp
    src/LogViewer.cpp
    src/Authenticator.cpp
    src/ShamanDialog.cpp
    src/ShamanStatusBar.cpp
    src/PackageProperties.cpp
    src/ShamanTreeWidgetItem.cpp
)

SET(shaman_MOC_HDRS
    src/MainWindow.h
    src/AlpmHandler.h
    src/BuildingDialog.h
    src/callbacks.h
    src/configDialog.h
    src/EditPBuild.h
    src/QueueDialog.h
    src/SysUpgradeDialog.h
    src/UpdateDbDialog.h
    src/BuildingHandler.h
    src/kanimatedsystemtrayicon.h
    src/ShamanTrayIcon.h
    src/ReviewQueueDialog.h
    src/ArchLinuxNewsReader.h
    src/NewsViewer.h
    src/LogViewer.h
    src/Authenticator.h
    src/ShamanStatusBar.h
    src/PackageProperties.h
#    src/ShamanTreeWidgetItem.h
)

SET(shaman_UIS
    ui/MainWindow.ui
    ui/aboutDialog.ui
    ui/buildingDialog.ui
    ui/configDialog.ui
    ui/dbUpdateDialog.ui
    ui/editPBDialog.ui
    ui/reviewBuildingDialog.ui
    ui/reviewQueueDialog.ui
    ui/transactionDialog.ui
    ui/upgradeDialog.ui
    ui/newsDialog.ui
    ui/logViewer.ui
    ui/authDialog.ui
    ui/pkgProperties.ui
)

SET(shaman_RESOUCES
    ui/shaman.qrc
)

# verbose - on
# SET(CMAKE_VERBOSE_MAKEFILE ON)

# requires minimal Qt 4.3
SET(QT_MIN_VERSION "4.3.0")

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

# translation start
FIND_PROGRAM(QT_LRELEASE_EXECUTABLE
    NAMES lrelease
    PATHS ${QT_BINARY_DIR}
    NO_DEFAULT_PATH
)

# needed to create translation files
IF(NOT QT_LRELEASE_EXECUTABLE)
    MESSAGE(FATAL_ERROR "Qt4 lrelease not found. Make sure that it has been built and installed by the Qt4 package.")
ENDIF(NOT QT_LRELEASE_EXECUTABLE)

MACRO(ADD_TRANSLATION_FILES _sources)
    FOREACH(_current_FILE ${ARGN})
        GET_FILENAME_COMPONENT(_in ${_current_FILE} ABSOLUTE)
        GET_FILENAME_COMPONENT(_basename ${_current_FILE} NAME_WE)

        SET(_out ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.qm)#

        ADD_CUSTOM_COMMAND(
            OUTPUT ${_out}
            COMMAND ${QT_LRELEASE_EXECUTABLE}
            ARGS -verbose ${_in} -qm ${_out}
            DEPENDS ${_in}
        )

        SET(${_sources} ${${_sources}} ${_out})
   ENDFOREACH(_current_FILE)
ENDMACRO(ADD_TRANSLATION_FILES)


FILE(GLOB TS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/translations/shaman_*.ts)

ADD_TRANSLATION_FILES(QM_FILES ${TS_FILES})

# creating a custom target is needed to make the files build
# "ALL" means that it will be run by default
ADD_CUSTOM_TARGET(translations ALL
                   DEPENDS ${QM_FILES})

INSTALL(CODE "MESSAGE(\"Installing Shaman i18n files...\")")
INSTALL (FILES ${QM_FILES}
         DESTINATION ${CMAKE_INSTALL_PREFIX}/share/shaman/translations)
# translation end

SET(QT_USE_QTXML)

QT4_WRAP_CPP(shaman_MOC_SRCS ${shaman_MOC_HDRS})
QT4_ADD_RESOURCES (qtsourceview_RC_SRCS  ${shaman_RESOUCES})
QT4_WRAP_UI(shaman_UIS_H ${shaman_UIS})
QT4_AUTOMOC(${shaman_SRCS})

INCLUDE_DIRECTORIES(
    ${QT_INCLUDES}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
)

ADD_EXECUTABLE(shaman
    ${shaman_SRCS}
    ${shaman_UIS_H}
    ${shaman_MOC_SRCS}
    ${qtsourceview_RC_SRCS}
)

TARGET_LINK_LIBRARIES(shaman
    ${QT_QTCORE_LIBRARY}
    ${QT_QTGUI_LIBRARY}
    ${QT_QTDBUS_LIBRARY}
    ${QT_QTNETWORK_LIBRARY}
    #${QTPLUGIN_QTMNG_LIBRARY}
    -lalpm
    -larchive
    -lpam
)

CONFIGURE_FILE(
       "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/cmake_uninstall.cmake.in"
       "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
       IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

#FILE(GLOB helpfiles "${CMAKE_CURRENT_SOURCE_DIR}/help/*.png")
#INSTALL(FILES ${helpfiles} DESTINATION share/shaman/help)

#INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/help/main.htm DESTINATION share/shaman/help)

#FILE(GLOB helpfiles_de "${CMAKE_CURRENT_SOURCE_DIR}/help/de/*.png")
#INSTALL(FILES ${helpfiles_de} DESTINATION share/shaman/help/de)

#INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/help/de/main.htm DESTINATION share/shaman/help/de)

INSTALL(CODE "MESSAGE(\"Installing Shaman executable...\")")
INSTALL(TARGETS shaman DESTINATION bin)
INSTALL(CODE "MESSAGE(\"Installing Shaman DBus Configuration File...\")")
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/etc/shaman.conf DESTINATION /etc/dbus-1/system.d)
INSTALL(CODE "MESSAGE(\"Installing Shaman Icons...\")")
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/ui/icons/shaman/shaman-32.png
		${CMAKE_CURRENT_SOURCE_DIR}/ui/icons/shaman/shaman-64.png
		${CMAKE_CURRENT_SOURCE_DIR}/ui/icons/shaman/shaman-128.png ${CMAKE_CURRENT_SOURCE_DIR}/ui/icons/shaman/shaman-48.png
		DESTINATION ${CMAKE_INSTALL_PREFIX}/share/pixmaps)
INSTALL(CODE "MESSAGE(\"Installing Shaman Desktop File...\")")
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/etc/shaman.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)

# for KDE 4.1 we require at least version 0.20
set(SHARED_MIME_INFO_MINIMUM_VERSION "0.20")
find_package(SharedMimeInfo)

#if(SHAREDMIMEINFO_FOUND)
########### install files ###############
    INSTALL(CODE "MESSAGE(\"Installing Archlinux Package Mimetypes...\")")
    install(FILES etc/shaman.xml DESTINATION ${XDG_MIME_INSTALL_DIR})
    update_xdg_mimetypes(${XDG_MIME_INSTALL_DIR})

#endif(SHAREDMIMEINFO_FOUND)

INSTALL(CODE "MESSAGE(\"Installing Miscellaneous Shaman Files...\")")
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/etc/kdemodmirrorlist DESTINATION /etc/pacman.d)

#IF(UNIX)
#    INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/misc/shaman.desktop DESTINATION share/applications)
#    INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/images/crystal/shaman.png DESTINATION share/icons/hicolor/32x32/apps)
#ENDIF(UNIX)
 
