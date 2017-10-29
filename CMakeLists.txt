#(Optional) suggest a directory for installation
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/../install" CACHE PATH "Installation path")

cmake_minimum_required(VERSION 3.1)
project(TUTORIAL)

set(configured_from_root True)

add_subdirectory(myapp)
add_subdirectory(mylibrary)
