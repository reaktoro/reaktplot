# Configure the setup.py file
configure_file(setup.py.in ${CMAKE_CURRENT_BINARY_DIR}/setup.py)

# Create a custom target to build the python package during build stage
add_custom_target(reaktplot-setuptools ALL
    COMMAND ${CMAKE_COMMAND} -E rm -rf build  # remove build dir created by previous `python setup.py install` commands (see next) to ensure fresh rebuild since changed python files are not overwritten even with --force option
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_BINARY_DIR}/src
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/README.md ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/LICENSE ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${PYTHON_EXECUTABLE} setup.py --quiet build --force
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# Ensure the path where the python package is installed is not empty
if(NOT DEFINED REAKTPLOT_PYTHON_INSTALL_PREFIX)
    file(TO_NATIVE_PATH ${CMAKE_INSTALL_PREFIX} REAKTPLOT_PYTHON_INSTALL_PREFIX)
endif()

# Create an install target for the reaktplot python package
install(CODE "execute_process(COMMAND pip install . --no-deps --force-reinstall --no-compile --prefix=${REAKTPLOT_PYTHON_INSTALL_PREFIX} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})")
