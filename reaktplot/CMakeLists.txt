# Recursively collect all hpp files from the current directory
file(GLOB_RECURSE HPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)

# Recursively collect all cpp files from the current directory
file(GLOB_RECURSE CPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# Recursively collect all .py.cxx files from the current directory
file(GLOB_RECURSE CXX_FILES_PY RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.py.cxx)

# Enable automatic creation of a module definition (.def) file for a SHARED library on Windows.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

# Create a library target for reaktplot
add_library(reaktplot ${HPP_FILES} ${CPP_FILES})

# Add an alias reaktplot::reaktplot to the target library reaktplot
add_library(reaktplot::reaktplot ALIAS reaktplot)

# Add the include paths to reaktplot library target
target_include_directories(reaktplot
    PUBLIC $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>)

# Find pybind11, a required dependency of reaktplot
find_package(pybind11 REQUIRED)

# Link reaktplot library against pybind11
target_link_libraries(reaktplot PUBLIC pybind11::embed)

# Set PYBIND11_NAMESPACE to pybind11 to prevent it from becoming `pybind11 __attribute__((visibility("hidden")))` when __GNUG__ is defined.
target_compile_definitions(reaktplot PUBLIC PYBIND11_NAMESPACE=pybind11)

# Set compilation features to be propagated to dependent codes.
target_compile_features(reaktplot PUBLIC cxx_std_17)

# Set some target properties
set_target_properties(reaktplot PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    CXX_EXTENSIONS OFF)

#==============================================================================
#
# COMPILATION CONFIGURATION FOR PYTHON BINDINGS
#
#==============================================================================

if(REAKTPLOT_BUILD_PYTHON)

    # Compile reaktplot *.py.cxx files into a Python module
    pybind11_add_module(reaktplot4py ${CXX_FILES_PY})

    # Add the root directory of the project to the include list
    target_include_directories(reaktplot4py PRIVATE ${PROJECT_SOURCE_DIR})

    # Link reaktplot4py against reaktplot C++ library
    target_link_libraries(reaktplot4py LINK_PRIVATE reaktplot::reaktplot)

    # This is needed to avoid compilation issues when using clang-9 and c++17
    if(${CMAKE_CXX_COMPILER_ID} STREQUAL Clang AND ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 10.0.0)
        target_compile_options(reaktplot4py PRIVATE -fsized-deallocation)
    endif()

endif()

#==============================================================================
#
# INSTALL CONFIGURATION
#
#==============================================================================

# Install reaktplot C++ library
install(TARGETS reaktplot
    EXPORT reaktplotTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libraries
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libraries
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT libraries)

# Install reaktplot debug symbols for MSVC builds
if(MSVC)
    install(FILES $<TARGET_PDB_FILE:reaktplot>
        DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT libraries
        OPTIONAL)
endif()

# Install reaktplot header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/reaktplot
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    FILES_MATCHING
        PATTERN "*.hpp"
        PATTERN "__pycache__" EXCLUDE)
