add_subdirectory(cpp)
add_subdirectory(python)

# Combine targets `tests-cpp` and `tests-py` created above into target `tests`
add_custom_target(tests
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR} --target tests-cpp
    COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR} --target tests-py
)
