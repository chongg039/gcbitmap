add_executable(test test.cc)
target_link_libraries(test bitmap)
target_link_libraries(test gtest)