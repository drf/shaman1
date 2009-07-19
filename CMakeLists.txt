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

if (NOT ICON_INSTALL_DIR)
    set(ICON_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/share)
endif (NOT ICON_INSTALL_DIR)

macro (SHAMAN_UPDATE_ICONCACHE)
    # Update mtime of hicolor icon theme dir.
    # We don't always have touch command (e.g. on Windows), so instead create
    #  and delete a temporary file in the theme dir.
   install(CODE "
    set(DESTDIR_VALUE \"\$ENV{DESTDIR}\")
    if (NOT DESTDIR_VALUE)
        file(WRITE \"${ICON_INSTALL_DIR}/hicolor/temp.txt\" \"update\")
        file(REMOVE \"${ICON_INSTALL_DIR}/hicolor/temp.txt\")
    endif (NOT DESTDIR_VALUE)
    ")
endmacro (SHAMAN_UPDATE_ICONCACHE)

# a "map" of short type names to the directories
# unknown names should give empty results
# KDE 3 compatibility
set(_SHAMAN_ICON_GROUP_mime       "mimetypes")
set(_SHAMAN_ICON_GROUP_filesys    "places")
set(_SHAMAN_ICON_GROUP_device     "devices")
set(_SHAMAN_ICON_GROUP_app        "apps")
set(_SHAMAN_ICON_GROUP_action     "actions")
# KDE 4 / icon naming specification compatibility
set(_SHAMAN_ICON_GROUP_mimetypes  "mimetypes")
set(_SHAMAN_ICON_GROUP_places     "places")
set(_SHAMAN_ICON_GROUP_devices    "devices")
set(_SHAMAN_ICON_GROUP_apps       "apps")
set(_SHAMAN_ICON_GROUP_actions    "actions")
set(_SHAMAN_ICON_GROUP_categories "categories")
set(_SHAMAN_ICON_GROUP_status     "status")
set(_SHAMAN_ICON_GROUP_emblems    "emblems")
set(_SHAMAN_ICON_GROUP_emotes     "emotes")
set(_SHAMAN_ICON_GROUP_animations "animations")
set(_SHAMAN_ICON_GROUP_intl       "intl")

# a "map" of short theme names to the theme directory
set(_SHAMAN_ICON_THEME_ox "oxygen")
set(_SHAMAN_ICON_THEME_cr "crystalsvg")
set(_SHAMAN_ICON_THEME_lo "locolor")
set(_SHAMAN_ICON_THEME_hi "hicolor")

# only used internally by SHAMAN_INSTALL_ICONS
macro (_SHAMAN_ADD_ICON_INSTALL_RULE _install_SCRIPT _install_PATH _group _orig_NAME _install_NAME _l10n_SUBDIR)

   # if the string doesn't match the pattern, the result is the full string, so all three have the same content
   if (NOT ${_group} STREQUAL ${_install_NAME} )
      set(_icon_GROUP  ${_SHAMAN_ICON_GROUP_${_group}})
      if(NOT _icon_GROUP)
         set(_icon_GROUP "actions")
      endif(NOT _icon_GROUP)
#      message(STATUS "icon: ${_current_ICON} size: ${_size} group: ${_group} name: ${_name} l10n: ${_l10n_SUBDIR}")
      install(FILES ${_orig_NAME} DESTINATION ${_install_PATH}/${_icon_GROUP}/${_l10n_SUBDIR}/ RENAME ${_install_NAME} )
   endif (NOT ${_group} STREQUAL ${_install_NAME} )

endmacro (_SHAMAN_ADD_ICON_INSTALL_RULE)


macro (SHAMAN_INSTALL_ICONS _defaultpath )

   # the l10n-subdir if language given as second argument (localized icon)
   set(_lang ${ARGV1})
   if(_lang)
      set(_l10n_SUBDIR l10n/${_lang})
   else(_lang)
      set(_l10n_SUBDIR ".")
   endif(_lang)

   # first the png icons
   file(GLOB _icons *.png)
   foreach (_current_ICON ${_icons} )
      # since CMake 2.6 regex matches are stored in special variables CMAKE_MATCH_x, if it didn't match, they are empty
      string(REGEX MATCH "^.*/([a-zA-Z]+)([0-9]+)\\-([a-z]+)\\-(.+\\.png)$" _dummy  "${_current_ICON}")
      set(_type  "${CMAKE_MATCH_1}")
      set(_size  "${CMAKE_MATCH_2}")
      set(_group "${CMAKE_MATCH_3}")
      set(_name  "${CMAKE_MATCH_4}")

      set(_theme_GROUP ${_SHAMAN_ICON_THEME_${_type}})
      if( _theme_GROUP)
         _SHAMAN_ADD_ICON_INSTALL_RULE(${CMAKE_CURRENT_BINARY_DIR}/install_icons.cmake
                    ${_defaultpath}/${_theme_GROUP}/${_size}x${_size}
                    ${_group} ${_current_ICON} ${_name} ${_l10n_SUBDIR})
      endif( _theme_GROUP)
   endforeach (_current_ICON)

   # mng icons
   file(GLOB _icons *.mng)
   foreach (_current_ICON ${_icons} )
      # since CMake 2.6 regex matches are stored in special variables CMAKE_MATCH_x, if it didn't match, they are empty
      string(REGEX MATCH "^.*/([a-zA-Z]+)([0-9]+)\\-([a-z]+)\\-(.+\\.mng)$" _dummy  "${_current_ICON}")
      set(_type  "${CMAKE_MATCH_1}")
      set(_size  "${CMAKE_MATCH_2}")
      set(_group "${CMAKE_MATCH_3}")
      set(_name  "${CMAKE_MATCH_4}")

      set(_theme_GROUP ${_SHAMAN_ICON_THEME_${_type}})
      if( _theme_GROUP)
         _SHAMAN_ADD_ICON_INSTALL_RULE(${CMAKE_CURRENT_BINARY_DIR}/install_icons.cmake
                ${_defaultpath}/${_theme_GROUP}/${_size}x${_size}
                ${_group} ${_current_ICON} ${_name} ${_l10n_SUBDIR})
      endif( _theme_GROUP)
   endforeach (_current_ICON)

   # and now the svg icons
   file(GLOB _icons *.svgz)
   foreach (_current_ICON ${_icons} )
      # since CMake 2.6 regex matches are stored in special variables CMAKE_MATCH_x, if it didn't match, they are empty
      string(REGEX MATCH "^.*/([a-zA-Z]+)sc\\-([a-z]+)\\-(.+\\.svgz)$" _dummy "${_current_ICON}")
      set(_type  "${CMAKE_MATCH_1}")
      set(_group "${CMAKE_MATCH_2}")
      set(_name  "${CMAKE_MATCH_3}")

      set(_theme_GROUP ${_SHAMAN_ICON_THEME_${_type}})
      if( _theme_GROUP)
          _SHAMAN_ADD_ICON_INSTALL_RULE(${CMAKE_CURRENT_BINARY_DIR}/install_icons.cmake
                            ${_defaultpath}/${_theme_GROUP}/scalable
                            ${_group} ${_current_ICON} ${_name} ${_l10n_SUBDIR})
      endif( _theme_GROUP)
   endforeach (_current_ICON)

   shaman_update_iconcache()

endmacro (SHAMAN_INSTALL_ICONS)

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
 
