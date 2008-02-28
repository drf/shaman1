macro (KDE4_ADD_PLUGIN _target_NAME _with_PREFIX)
#is the first argument is "WITH_PREFIX" then keep the standard "lib" prefix, otherwise set the prefix empty
   if (${_with_PREFIX} STREQUAL "WITH_PREFIX")
      set(_first_SRC)
   else (${_with_PREFIX} STREQUAL "WITH_PREFIX")
      set(_first_SRC ${_with_PREFIX})
   endif (${_with_PREFIX} STREQUAL "WITH_PREFIX")

   set(_SRCS ${_first_SRC} ${ARGN})
   kde4_handle_automoc(${_target_NAME} _SRCS)
   if (KDE4_ENABLE_FINAL)
      kde4_create_final_files(${CMAKE_CURRENT_BINARY_DIR}/${_target_NAME}_final_cpp.cpp _separate_files ${_SRCS})
      add_library(${_target_NAME} MODULE  ${CMAKE_CURRENT_BINARY_DIR}/${_target_NAME}_final_cpp.cpp ${_separate_files})
   else (KDE4_ENABLE_FINAL)
      add_library(${_target_NAME} MODULE ${_SRCS})
   endif (KDE4_ENABLE_FINAL)

   if (_first_SRC)
      set_target_properties(${_target_NAME} PROPERTIES PREFIX "")
   endif (_first_SRC)

   kde4_handle_rpath_for_library(${_target_NAME})

   if (WIN32)
      # for shared libraries/plugins a -DMAKE_target_LIB is required
      string(TOUPPER ${_target_NAME} _symbol)
      string(REGEX REPLACE "[^_A-Za-z0-9]" "_" _symbol ${_symbol})
      set(_symbol "MAKE_${_symbol}_LIB")
      set_target_properties(${_target_NAME} PROPERTIES DEFINE_SYMBOL ${_symbol})
   endif (WIN32)

endmacro (KDE4_ADD_PLUGIN _target_NAME _with_PREFIX)



set(shaman_SRCS
    plasma-kget.cpp
)

#kde4_add_ui_files(shaman_SRCS shamanConfig.ui)
kde4_add_plugin(plasma_applet_shaman ${shaman_SRCS})
target_link_libraries(plasma_applet_shaman ${PLASMA_LIBS} ${KDE4_KDEUI_LIBS})

install(TARGETS plasma_applet_shaman DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES plasma-shaman-default.desktop DESTINATION ${SERVICES_INSTALL_DIR})
