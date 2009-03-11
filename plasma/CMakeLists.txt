FIND_PACKAGE(KDE4 REQUIRED)
FIND_PACKAGE(Plasma REQUIRED)

INCLUDE_DIRECTORIES(
    ${KDE4_INCLUDES}
    ${PLASMA_INCLUDE_DIR}
)

INSTALL(CODE "MESSAGE(\"Installing Shaman Plasma Components...\")")

add_subdirectory(engine)
add_subdirectory(applet) 
add_subdirectory(runner)
