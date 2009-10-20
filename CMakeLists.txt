project(shaman)

cmake_minimum_required(VERSION 2.6.0)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

if(COMMAND cmake_policy)
   cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

# Versioning
set(MAJOR_SHAMAN_VERSION "1")
set(MINOR_SHAMAN_VERSION "2")
set(PATCH_SHAMAN_VERSION "71")
set(ADDENDUM_SHAMAN_VERSION "")
set(SHAMAN_VERSION_STRING "${MAJOR_SHAMAN_VERSION}.${MINOR_SHAMAN_VERSION}.${PATCH_SHAMAN_VERSION}${ADDENDUM_SHAMAN_VERSION}")
set(SHAMAN_VERSION_CODENAME "")
set(SHAMAN_VERSION_REVISION "")

# requires minimal Qt 4.4
set(QT_MIN_VERSION "4.4.0")
set(SHARED_MIME_INFO_MINIMUM_VERSION "0.20")

find_package(Automoc4 REQUIRED)
find_package(Qt4 REQUIRED)
find_package(SharedMimeInfo REQUIRED)
find_package(PolkitQt REQUIRED)
find_package(Aqpm REQUIRED)

if (KDE4_INTEGRATION)
    find_package(KDE4 REQUIRED)

    include (MacroLibrary)
    include (FindPackageHandleStandardArgs)
    include (KDE4Defaults)
endif (KDE4_INTEGRATION)

configure_file(config-shaman1.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-shaman1.h )

include (ShamanMacros)

include(${QT_USE_FILE})

set(QT_USE_QTXML)

include_directories(
    ${QT_INCLUDES}
    ${AQPM_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/src
    ${CMAKE_SOURCE_DIR}/src
    ${POLKITQT_INCLUDE_DIR}
    ${KDE4_INCLUDES}
)

add_definitions (${QT_DEFINITIONS} ${QT_QTDBUS_DEFINITIONS} ${KDE4_DEFINITIONS})

configure_file(
       "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/cmake_uninstall.cmake.in"
       "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
       IMMEDIATE @ONLY)
add_custom_target(uninstall "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

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

add_subdirectory(firstrun)

## Source tarball ##
set(ARCHIVE_NAME ${CMAKE_PROJECT_NAME}-${SHAMAN_VERSION_STRING})
add_custom_target(dist
    COMMAND git archive --prefix=${ARCHIVE_NAME}/ HEAD
        | bzip2 > ${CMAKE_BINARY_DIR}/${ARCHIVE_NAME}.tar.bz2
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
