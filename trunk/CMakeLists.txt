PROJECT(shaman)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.0)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

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

macro_optional_find_package(Plasma)

if (PLASMA_FOUND)
    add_subdirectory(plasma)
endif(PLASMA_FOUND)

SET(shaman_SRCS
    src/main.cpp
    src/MainWindow.cpp
    src/AlpmHandler.cpp
    src/BuildingDialog.cpp
    src/callbacks.cpp
    src/configDialog.cpp
    src/ConfigurationParser.cpp
    src/EditPBuild.cpp
    src/QueueDialog.cpp
    src/StringUtils.cpp
    src/SysUpgradeDialog.cpp
    src/UpdateDbDialog.cpp
    src/ABSHandler.cpp
)

SET(shaman_MOC_HDRS
    src/MainWindow.h
    src/AlpmHandler.h
    src/BuildingDialog.h
    src/callbacks.h
    src/configDialog.h
    src/ConfigurationParser.h
    src/EditPBuild.h
    src/QueueDialog.h
    src/StringUtils.h
    src/SysUpgradeDialog.h
    src/UpdateDbDialog.h
    src/ABSHandler.h
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
)

SET(shaman_RESOUCES
    ui/qtpacman.qrc
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

INSTALL (FILES ${QM_FILES}
         DESTINATION share/shaman/translations)
# translation end

SET(QT_USE_QTXML)

QT4_WRAP_CPP(shaman_MOC_SRCS ${shaman_MOC_HDRS})
QT4_ADD_RESOURCES (qtsourceview_RC_SRCS  ${shaman_RESOUCES})
QT4_WRAP_UI(shaman_UIS_H ${shaman_UIS})
QT4_AUTOMOC(${shaman_SRCS})

INCLUDE_DIRECTORIES(
    ${QT_INCLUDES}
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
    ${QT_QTXML_LIBRARY}
    -lalpm
    -larchive
)
#FILE(GLOB helpfiles "${CMAKE_CURRENT_SOURCE_DIR}/help/*.png")
#INSTALL(FILES ${helpfiles} DESTINATION share/shaman/help)

#INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/help/main.htm DESTINATION share/shaman/help)

#FILE(GLOB helpfiles_de "${CMAKE_CURRENT_SOURCE_DIR}/help/de/*.png")
#INSTALL(FILES ${helpfiles_de} DESTINATION share/shaman/help/de)

#INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/help/de/main.htm DESTINATION share/shaman/help/de)

INSTALL(TARGETS shaman DESTINATION bin)

#IF(UNIX)
#    INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/misc/shaman.desktop DESTINATION share/applications)
#    INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/images/crystal/shaman.png DESTINATION share/icons/hicolor/32x32/apps)
#ENDIF(UNIX)
 
