# Recursively collect all hpp files from the current directory
file(GLOB_RECURSE HPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)

# Recursively collect all cpp files from the current directory
file(GLOB_RECURSE CPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# Enable automatic creation of a module definition (.def) file for a SHARED library on Windows.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

# Find pybind11, a required dependency of reaktplot
find_package(pybind11 REQUIRED)

# Create a library target for reaktplot
add_library(reaktplot SHARED ${HPP_FILES} ${CPP_FILES})

# Add an alias reaktplot::reaktplot to the target library reaktplot
add_library(reaktplot::reaktplot ALIAS reaktplot)

# Add the include paths to reaktplot library target
target_include_directories(reaktplot
    PUBLIC $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>)

# Link reaktplot library against pybind11
target_link_libraries(reaktplot PUBLIC pybind11::embed)  # propagate dependency on pybind11::embed target to new targets depending on reaktplot

# Set compilation features to be propagated to dependent codes.
target_compile_features(reaktplot PUBLIC cxx_std_17)

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
