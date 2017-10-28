cmake_minimum_required(VERSION 3.1)
project(TUTORIAL)

set(CMAKE_CXX_STANDARD 11)

include_directories(mylibrary/include)

add_subdirectory(myapp)
add_subdirectory(mylibrary)
