# Configure the setup.py file
configure_file(setup.py.in ${CMAKE_CURRENT_BINARY_DIR}/setup.py)

# Find program pybind11-stubgen needed to produce stubs for reaktplot's python interface
find_program(PYBIND11_STUBGEN pybind11-stubgen REQUIRED)

# Create pybind11-stubgen command string
set(PYBIND11_STUBGEN_COMMAND ${PYBIND11_STUBGEN} --ignore-invalid=all --no-setup-py --log-level=ERROR reaktplot)

# Create a custom target to build the python package during build stage
add_custom_target(reaktplot-setuptools ALL
    DEPENDS reaktplot4py
    COMMAND ${CMAKE_COMMAND} -E rm -rf build  # remove build dir created by previous `python setup.py install` commands (see next) to ensure fresh rebuild since changed python files are not overwritten even with --force option
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/reaktplot reaktplot
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:reaktplot4py> reaktplot
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:reaktplot> reaktplot
    COMMAND ${CMAKE_COMMAND} -E env
        "PYTHONPATH=${REAKTPLOT_PYTHONPATH}"
            ${PYBIND11_STUBGEN_COMMAND}
    COMMAND ${CMAKE_COMMAND} -E copy_directory stubs/reaktplot-stubs/ reaktplot
    COMMAND ${PYTHON_EXECUTABLE} setup.py --quiet build --force
    COMMAND ${CMAKE_COMMAND} -E rm reaktplot/$<TARGET_FILE_NAME:reaktplot4py>
    COMMAND ${CMAKE_COMMAND} -E rm reaktplot/$<TARGET_FILE_NAME:reaktplot>
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# Ensure the path where the python package is installed is not empty
if(NOT DEFINED REAKTPLOT_PYTHON_INSTALL_PREFIX)
    file(TO_NATIVE_PATH ${CMAKE_INSTALL_PREFIX} REAKTPLOT_PYTHON_INSTALL_PREFIX)
endif()

# Create an install target for the reaktplot python package
install(CODE "execute_process(COMMAND pip install . --no-deps --force-reinstall --no-compile --prefix=${REAKTPLOT_PYTHON_INSTALL_PREFIX} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})")
