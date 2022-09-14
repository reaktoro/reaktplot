# Set cmake version requirement
cmake_minimum_required(VERSION 3.12)

# Set the cmake module path of the project
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Use ccache to speed up repeated compilations
include(CCache)

# Set the name of the project, its version and other information
project(reaktplot VERSION 0.1.0
    DESCRIPTION "A modern C++ scientific plotting library powered by plotly"
    HOMEPAGE_URL "https://github.com/reaktoro/reaktplot"
    LANGUAGES CXX)

# Generate compile_commands.json file in the binary directory
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include the cmake variables with values for installation directories
include(GNUInstallDirs)

# Define which components of reaktplot to build
option(REAKTPLOT_BUILD_EXAMPLES "Build the C++ examples"    ON)
option(REAKTPLOT_BUILD_TESTS    "Build the C++ tests"       ON)
option(REAKTPLOT_BUILD_PYTHON   "Build the Python package." ON)
option(REAKTPLOT_BUILD_DOCS     "Build the documentation"   ON)

# Define if shared library should be build instead of static.
option(BUILD_SHARED_LIBS "Build shared libraries." ON)

# Set compile options in case of MSVC
if(MSVC)
    add_compile_options(/MP)  # enable parallel build
    add_definitions("/wd4267 /wd4244")  # ignore silly warnings related to size_t/int and site_t/double conversions
endif()

# The directories where the built C++ library may be located
file(TO_NATIVE_PATH ${CMAKE_BINARY_DIR}/reaktplot REAKTPLOT_LIBRARY_DIR_1)
file(TO_NATIVE_PATH ${CMAKE_BINARY_DIR}/reaktplot/$<CONFIG> REAKTPLOT_LIBRARY_DIR_2)

# The directory where the python package reaktplot is built
# Note: This needs improvement. The complication below is due to the need of
# pybind11-stubgen in importing reaktplot, and this is done before running
# python setup.y install in reaktplot-setuptools target.
# Once the package is built with setuptools, the directory
# REAKTPLOT_PYTHON_PACKAGE_DIR_1 is created. But directory
# REAKTPLOT_PYTHON_PACKAGE_DIR_2 always exist and its used by pybind11-stubgen.
file(TO_NATIVE_PATH ${CMAKE_BINARY_DIR}/python/package/build/lib REAKTPLOT_PYTHON_PACKAGE_DIR_1)
file(TO_NATIVE_PATH ${CMAKE_BINARY_DIR}/python/package REAKTPLOT_PYTHON_PACKAGE_DIR_2)

# Define variables REAKTPLOT_PATH and REAKTPLOT_PYTHONPATH used to set environment variables PATH and PYTHONPATH.
if(WIN32)
    set(REAKTPLOT_PATH "${REAKTPLOT_LIBRARY_DIR_1}\;${REAKTPLOT_LIBRARY_DIR_2}\;$ENV{PATH}")
    set(REAKTPLOT_PYTHONPATH "${REAKTPLOT_PYTHON_PACKAGE_DIR_1}\;${REAKTPLOT_PYTHON_PACKAGE_DIR_2}\;$ENV{PYTHONPATH}")
else()
    # Surround path values with '' to avoid cmake errors when ( or ) exists such as in `Program Files (x86)` when compiling in WSL (Windows Subsystem for Linux).
    set(REAKTPLOT_PATH '$ENV{PATH}')
    set(REAKTPLOT_PYTHONPATH '${REAKTPLOT_PYTHON_PACKAGE_DIR_1}:${REAKTPLOT_PYTHON_PACKAGE_DIR_2}:$ENV{PYTHONPATH}')
endif()

# Start build of the library
add_subdirectory(reaktplot)

# Start build of the Python package
if(REAKTPLOT_BUILD_PYTHON)
    add_subdirectory(python)
endif()

# Start build of the examples
if(REAKTPLOT_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Start build of the tests
if(REAKTPLOT_BUILD_TESTS)
    add_subdirectory(tests)
endif()

# Start build of the docs
if(REAKTPLOT_BUILD_DOCS)
    add_subdirectory(docs)
endif()

# Collect targets under scripts
add_subdirectory(scripts)

# Install the cmake config files that permit users to use find_package(reaktplot)
include(reaktplotInstallConfigFiles)
