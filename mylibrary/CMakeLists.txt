#(Optional) suggest a directory for installation
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/../install" CACHE PATH "Installation path")

cmake_minimum_required(VERSION 3.1)
project(MYLIBRARY)

set(CMAKE_CXX_STANDARD_11)

set(headers
	include/mylibrary/mylibrary.h
)

set(sources
	src/mylibrary.cpp
)

message("Tutorial : Configuring ${CMAKE_CURRENT_BINARY_DIR}/mylibrary")
add_library(mylibrary ${sources} ${headers})
target_include_directories(mylibrary
	PUBLIC
	#these 2 generator-expressions are evaluated by the generator (e.g. make), not cmake
	#depending on whether we are linking with the install or source directory the corresponding variable is substituted, the other removed
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:include>"
)

#install library
message("Tutorial : Configuring ${CMAKE_INSTALL_PREFIX}/lib/mylibrary")
install(TARGETS mylibrary
	EXPORT targets
	ARCHIVE DESTINATION lib
	COMPONENT library
)
#install headers (just make a copy)
message("Tutorial : Configuring ${CMAKE_INSTALL_PREFIX}/include")
install(DIRECTORY include
	DESTINATION "."
	COMPONENT headers
)

#declare package name
set(package_name mylibrary)

#install targets, so that other projects can link to the installed library using find_package()
message("Tutorial : Configuring ${CMAKE_INSTALL_PREFIX}/cmake/${package_name}Targets.cmake")
install(EXPORT targets
	FILE "${package_name}Targets.cmake"
	DESTINATION "cmake"
	COMPONENT targets
)
