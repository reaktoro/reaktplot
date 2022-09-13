# The path where cmake config files are installed
set(REAKTPLOT_INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/reaktplot)

install(EXPORT reaktplotTargets
    FILE reaktplotTargets.cmake
    NAMESPACE reaktplot::
    DESTINATION ${REAKTPLOT_INSTALL_CONFIGDIR}
    COMPONENT cmake)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/reaktplotConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/reaktplotConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/reaktplotConfig.cmake
    INSTALL_DESTINATION ${REAKTPLOT_INSTALL_CONFIGDIR}
    PATH_VARS REAKTPLOT_INSTALL_CONFIGDIR)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/reaktplotConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/reaktplotConfigVersion.cmake
    DESTINATION ${REAKTPLOT_INSTALL_CONFIGDIR})
