# - Try to find Aqpm
# Once done this will define
#
#  AQPM_FOUND - system has Polkit-qt
#  AQPM_INCLUDE_DIR - the Polkit-qt include directory
#  AQPM_LIBRARIES - Link these to use all Polkit-qt libs
#  AQPM_CORE_LIBRARY - Link this to use the polkit-qt-core library only
#  AQPM_GUI_LIBRARY - Link this to use GUI elements in polkit-qt (polkit-qt-gui)
#  AQPM_DEFINITIONS - Compiler switches required for using Polkit-qt

# Copyright (c) 2009, Dario Freddi, <drf@chakra-project.org>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

if (AQPM_INCLUDE_DIR AND AQPM_LIB)
    set(AQPM_FIND_QUIETLY TRUE)
endif (AQPM_INCLUDE_DIR AND AQPM_LIB)

if (NOT AQPM_MIN_VERSION)
  set(AQPM_MIN_VERSION "1.3.3")
endif (NOT AQPM_MIN_VERSION)

if (NOT WIN32)
   # use pkg-config to get the directories and then use these values
   # in the FIND_PATH() and FIND_LIBRARY() calls
   find_package(PkgConfig)
   pkg_check_modules(PC_AQPM aqpm)
   set(AQPM_DEFINITIONS ${PC_AQPM_CFLAGS_OTHER})
endif (NOT WIN32)

find_path( AQPM_INCLUDE_DIR
     NAMES aqpm/Backend.h
     HINTS ${PC_AQPM_INCLUDEDIR}
)
find_library( AQPM_LIBRARY
    NAMES aqpm
    HINTS ${PC_AQPM_LIBDIR}
)

include(FindPackageHandleStandardArgs)

# handle the QUIETLY and REQUIRED arguments and set AQPM_FOUND to TRUE if
# all listed variables are TRUE
find_package_handle_standard_args(aqpm DEFAULT_MSG AQPM_LIBRARY AQPM_INCLUDE_DIR)

mark_as_advanced(AQPM_INCLUDE_DIR AQPM_LIBRARY)

if (AQPM_FOUND)
    if (PC_AQPM_VERSION VERSION_LESS AQPM_MIN_VERSION)
        message(STATUS "Found Aqpm release < ${AQPM_MIN_VERSION}")
        message(STATUS "You need Aqpm version ${AQPM_MIN_VERSION} or newer to compile this component")
        set(AQPM_FOUND FALSE)
        return()
    endif (PC_AQPM_VERSION VERSION_LESS AQPM_MIN_VERSION)
endif (AQPM_FOUND)
