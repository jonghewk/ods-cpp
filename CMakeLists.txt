cmake_minimum_required(VERSION 3.16.3)


project(ods-cpp)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "v")
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ch2 array_lists/main.cc)
target_include_directories(ch2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
