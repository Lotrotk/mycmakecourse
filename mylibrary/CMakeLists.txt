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
add_library(mylibrary "${sources}" "${headers}")
target_include_directories(mylibrary
	PUBLIC
	#these 2 generator-expressions are evaluated by the generator (e.g. make), not cmake
	#depending on whether we are linking with the install or source directory the corresponding variable is substituted, the other removed
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:include>"
)

set(major_version 1)
set(minor_version 0)

#install library
message("Tutorial : Configuring ${CMAKE_INSTALL_PREFIX}/lib/mylibrary")
install(TARGETS mylibrary
	EXPORT targets
	ARCHIVE DESTINATION lib
	COMPONENT library
)
#install headers (just make a copy)
message("Tutorial : Configuring ${CMAKE_INSTALL_PREFIX}/include")
install(DIRECTORY
	include DESTINATION "."
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
#export build targets, so that other projects can link to the build instead of install
#for some reason the other projects do not include the build commands, so there is no real use for this case
#but other targets (e.g. generated files and such) may be of more interest
#message("Tutorial : Generating ${CMAKE_CURRENT_BINARY_DIR}/${package_name}Targets.cmake")
#export(EXPORT targets
#	FILE "${package_name}Targets.cmake"
#)

#useful cmake utility to generate config files
include(CMakePackageConfigHelpers)

#this variable will be visible to the config file
list(APPEND my_installed_components funny_print)
#this path variable will be passed to the config file with the correct prefix
#not actually used, just an example
set(example_of_a_configured_path include/)


#generate the config and configversion files in the binary dir, so that other projects can link to the built library
#complete the config file
message("Tutorial : Generating ${CMAKE_CURRENT_BINARY_DIR}/${package_name}Config.cmake")
configure_package_config_file("${package_name}Config.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/${package_name}Config.cmake"
                              INSTALL_DESTINATION "cmake"
                              PATH_VARS example_of_a_configured_path
)
#generate the config version file
message("Tutorial : Generating ${CMAKE_CURRENT_BINARY_DIR}/${package_name}ConfigVersion.cmake")
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/${package_name}ConfigVersion.cmake"
  VERSION "${major_version}.${minor_version}"
  COMPATIBILITY AnyNewerVersion
)
#install the config files
message("Tutorial : Configuring ${CMAKE_INSTALL_PREFIX}/${package_name}Config.cmake and ${CMAKE_INSTALL_PREFIX}/${package_name}ConfigVersion.cmake")
install(
	FILES "${CMAKE_CURRENT_BINARY_DIR}/${package_name}Config.cmake" "${CMAKE_CURRENT_BINARY_DIR}/${package_name}ConfigVersion.cmake"
	DESTINATION "cmake"
	COMPONENT config
)
