add_subdirectory(cpp)
add_subdirectory(python)

# Combine targets `tests-cpp` and `tests-py` created above into target `tests`
add_custom_target(tests DEPENDS tests-py tests-cpp)
