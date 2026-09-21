cmake_minimum_required(VERSION 3.21)


project(file_navigation_project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

include_directories(./include)

add_executable(tests main.cpp)

target_link_libraries(tests file_navigation)

