PROJECT(tribe)

CMAKE_MINIMUM_REQUIRED(VERSION 2.4.0)
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

include(FindQt4)

SET(tribe_SRCS
)

SET(tribe_MOC_HDRS
)

SET(tribe_UIS
  ui/tribeBase.ui
)

SET(tribe_RESOUCES
)

# verbose - on
# SET(CMAKE_VERBOSE_MAKEFILE ON)

# requires minimal Qt 4.3
SET(QT_MIN_VERSION "4.3.0")

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

# translation start
#FIND_PROGRAM(QT_LRELEASE_EXECUTABLE
#    NAMES lrelease
#    PATHS ${QT_BINARY_DIR}
#    NO_DEFAULT_PATH
#)

# needed to create translation files
#IF(NOT QT_LRELEASE_EXECUTABLE)
#    MESSAGE(FATAL_ERROR "Qt4 lrelease not found. Make sure that it has been built and installed by the Qt4 package.")
#ENDIF(NOT QT_LRELEASE_EXECUTABLE)

#MACRO(ADD_TRANSLATION_FILES _sources)
#    FOREACH(_current_FILE ${ARGN})
#        GET_FILENAME_COMPONENT(_in ${_current_FILE} ABSOLUTE)
#        GET_FILENAME_COMPONENT(_basename ${_current_FILE} NAME_WE)
#
#        SET(_out ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.qm)#
#
#        ADD_CUSTOM_COMMAND(
#            OUTPUT ${_out}
#            COMMAND ${QT_LRELEASE_EXECUTABLE}
#            ARGS -verbose ${_in} -qm ${_out}
#            DEPENDS ${_in}
#        )
#
#        SET(${_sources} ${${_sources}} ${_out})
#   ENDFOREACH(_current_FILE)
#ENDMACRO(ADD_TRANSLATION_FILES)


#FILE(GLOB TS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/translations/tribe_*.ts)

#ADD_TRANSLATION_FILES(QM_FILES ${TS_FILES})

# creating a custom target is needed to make the files build
# "ALL" means that it will be run by default
#ADD_CUSTOM_TARGET(translations ALL
#                   DEPENDS ${QM_FILES})

#INSTALL (FILES ${QM_FILES}
#         DESTINATION share/tribe/translations)
# translation end

SET(QT_USE_QTXML)

QT4_WRAP_CPP(tribe_MOC_SRCS ${tribe_MOC_HDRS})
QT4_ADD_RESOURCES (qtsourceview_RC_SRCS  ${tribe_RESOUCES})
QT4_WRAP_UI(tribe_UIS_H ${tribe_UIS})
QT4_AUTOMOC(${tribe_SRCS})

INCLUDE_DIRECTORIES(
    ${QT_INCLUDES}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
)

ADD_EXECUTABLE(tribe
    ${tribe_SRCS}
    ${tribe_UIS_H}
    ${tribe_MOC_SRCS}
    ${qtsourceview_RC_SRCS}
)

TARGET_LINK_LIBRARIES(tribe
    ${QT_QTCORE_LIBRARY}
    ${QT_QTGUI_LIBRARY}
    ${QT_QTDBUS_LIBRARY}
    -lalpm
    -larchive
)

CONFIGURE_FILE(
       "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/cmake_uninstall.cmake.in"
       "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
       IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

#FILE(GLOB helpfiles "${CMAKE_CURRENT_SOURCE_DIR}/help/*.png")
#INSTALL(FILES ${helpfiles} DESTINATION share/tribe/help)

#INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/help/main.htm DESTINATION share/tribe/help)

#FILE(GLOB helpfiles_de "${CMAKE_CURRENT_SOURCE_DIR}/help/de/*.png")
#INSTALL(FILES ${helpfiles_de} DESTINATION share/tribe/help/de)

#INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/help/de/main.htm DESTINATION share/tribe/help/de)

INSTALL(TARGETS tribe DESTINATION bin)

#IF(UNIX)
#    INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/misc/tribe.desktop DESTINATION share/applications)
#    INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/images/crystal/tribe.png DESTINATION share/icons/hicolor/32x32/apps)
#ENDIF(UNIX)
 
