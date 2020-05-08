cmake_minimum_required(VERSION 3.15)
project(gcbitmap)

set(CMAKE_CXX_STANDARD 11)

set(GTEST_DIR "thirdparty/googletest")
include_directories(${GTEST_DIR}/include)

add_subdirectory(utils)
add_subdirectory(tests)
add_subdirectory(thirdparty/googletest)