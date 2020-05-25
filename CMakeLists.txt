cmake_minimum_required(VERSION 3.15)
project(gcbitmap)

set(CMAKE_CXX_STANDARD 11)

set(GTEST_DIR "thirdparty/googletest")
include_directories(${GTEST_DIR}/include)

message("Project gcbitmap root path: " ${gcbitmap_SOURCE_DIR})
message("Project gcbitmap binary path: " ${gcbitmap_BINARY_DIR})

# CMake files in this project can refer to the root source directory
# as ${gcbitmap_SOURCE_DIR} and to the root binary directory as
# ${gcbitmap_BINARY_DIR}.

# Where gcbitmap's .h files can be found.
set(gcbitmap_build_include_dirs
        "${gcbitmap_SOURCE_DIR}/include")
set(gcbitmap_build_src_dirs
        "${gcbitmap_SOURCE_DIR}/src")

message("Project gcbitmap include path: " ${gcbitmap_build_include_dirs})
message("Project gcbitmap src path: " ${gcbitmap_build_src_dirs})

include_directories(${gcbitmap_build_include_dirs})
add_library(gcbitmap ${gcbitmap_build_src_dirs}/bitmap.cc)

add_subdirectory(tests)
add_subdirectory(thirdparty/googletest)