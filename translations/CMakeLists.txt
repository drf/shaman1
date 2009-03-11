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


FILE(GLOB TS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/shaman_*.ts)

ADD_TRANSLATION_FILES(QM_FILES ${TS_FILES})

# creating a custom target is needed to make the files build
# "ALL" means that it will be run by default
ADD_CUSTOM_TARGET(translations ALL
                   DEPENDS ${QM_FILES})

INSTALL(CODE "MESSAGE(\"Installing Shaman i18n files...\")")
INSTALL (FILES ${QM_FILES}
         DESTINATION ${CMAKE_INSTALL_PREFIX}/share/shaman/translations)
# translation end