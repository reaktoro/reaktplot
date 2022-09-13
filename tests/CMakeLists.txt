file(GLOB_RECURSE FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.test.cxx)

add_executable(reaktplot-cpptests ${FILES})
target_link_libraries(reaktplot-cpptests reaktplot)
target_include_directories(reaktplot-cpptests PUBLIC ${PROJECT_SOURCE_DIR})

# Test for linking errors (due to missing inline specifiers)
add_subdirectory(testing-project)

# Add target tests that performs all C++ and Python tests
add_custom_target(tests
    COMMENT "Running C++ tests..."
    COMMAND $<TARGET_FILE:reaktplot-cpptests>
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
