# Recursively collect all .test.cxx files from the current directory
file(GLOB_RECURSE CXX_FILES_TEST RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.test.cxx)

# Check the testing project compiles fine (e.g., to check linking errors)
add_subdirectory(testing-project)

# Find catch2, which is used as the testing framework for reaktplot
find_package(Catch2 REQUIRED)

# Create a test executable target for reaktplot
add_executable(reaktplot-cpptests ${CXX_FILES_TEST})
target_link_libraries(reaktplot-cpptests reaktplot Catch2::Catch2)
target_include_directories(reaktplot-cpptests PUBLIC ${PROJECT_SOURCE_DIR})

# Create target `tests-cpp` to execute C++ tests
add_custom_target(tests-cpp
    DEPENDS reaktplot-cpptests
    COMMENT "Running C++ tests..."
    COMMAND ${CMAKE_COMMAND} -E env
        "PATH=${REAKTPLOT_PATH}"
            $<TARGET_FILE:reaktplot-cpptests>
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
