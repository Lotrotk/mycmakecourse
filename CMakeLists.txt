#(Optional) suggest a directory for installation
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/../install" CACHE PATH "Installation path")

cmake_minimum_required(VERSION 3.1)
project(TUTORIAL)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(myapp)
add_subdirectory(mylibrary)

message("Tutorial : Configuring package installer")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
include(CPack)
