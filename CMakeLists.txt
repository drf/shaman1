PROJECT(shaman)

CMAKE_MINIMUM_REQUIRED(VERSION 2.4.0)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

include(FindQt4)
include(FindSharedMimeInfo)
include(FindPkgConfig)
include(FindPolkitQt)

if (KDE4_INTEGRATION)
find_package(KDE4)
endif (KDE4_INTEGRATION)

configure_file(config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h )

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

# requires minimal Qt 4.4
SET(QT_MIN_VERSION "4.4.0")

FIND_PACKAGE(Qt4 REQUIRED)
FIND_PACKAGE(Alpm REQUIRED)
pkg_check_modules(AQPM aqpm)
if(AQPM_FOUND)
	MESSAGE("Aqpm Found")
endif(AQPM_FOUND)
FIND_PACKAGE(LibArchive REQUIRED)
FIND_PACKAGE(PolkitQt REQUIRED)
FIND_PACKAGE(Automoc4 REQUIRED)
pkg_check_modules (POLKIT polkit>=0.8 REQUIRED)
pkg_check_modules (POLKITDBUS polkit-dbus>=0.8 REQUIRED)

#optional packages
FIND_PACKAGE(KDE4)
FIND_PACKAGE(Plasma)

INCLUDE(${QT_USE_FILE})

SET(QT_USE_QTXML)

INCLUDE_DIRECTORIES(
    ${QT_INCLUDES}
    ${ALPM_INCLUDE_DIR}
    ${LIBARCHIVE_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/src
    ${CMAKE_SOURCE_DIR}/src
    ${POLKITQT_INCLUDE_DIR}
    ${POLKIT_INCLUDE_DIRS}
)

CONFIGURE_FILE(
       "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/cmake_uninstall.cmake.in"
       "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
       IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

if(NOT PLASMA_ONLY)

	add_subdirectory(ui)
	add_subdirectory(dbus)
	add_subdirectory(src)
	add_subdirectory(translations)
	add_subdirectory(etc)

else(NOT PLASMA_ONLY)
	message("Building only plasma components, skipping shaman core")
endif(NOT PLASMA_ONLY)

if(NOT NO_PLASMA)

	if (PLASMA_FOUND)
#    		add_subdirectory(plasma)
	else (PLASMA_FOUND)
		message("Plasma not found, plasma components won't be built")
	endif(PLASMA_FOUND)

else(NOT NO_PLASMA)
	message("Plasma components disabled by the user, they won't be built")
endif(NOT NO_PLASMA)


# verbose - on
# SET(CMAKE_VERBOSE_MAKEFILE ON)

#FILE(GLOB helpfiles "${CMAKE_CURRENT_SOURCE_DIR}/help/*.png")
#INSTALL(FILES ${helpfiles} DESTINATION share/shaman/help)

#INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/help/main.htm DESTINATION share/shaman/help)

#FILE(GLOB helpfiles_de "${CMAKE_CURRENT_SOURCE_DIR}/help/de/*.png")
#INSTALL(FILES ${helpfiles_de} DESTINATION share/shaman/help/de)

#INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/help/de/main.htm DESTINATION share/shaman/help/de)
 
