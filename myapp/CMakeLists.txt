#(Optional) suggest a directory for installation
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/../install" CACHE PATH "Installation path")

cmake_minimum_required(VERSION 3.1)
project(MYAPP)

set(CMAKE_CXX_STANDARD_11)

set(headers
)

set(sources
	src/main.cpp
)

if(NOT configured_from_root)
	message("Tutorial : Target mylibrary not defined. Commence search...")
	#This is so called 'module mode', where CMake will search for *Find.cmake files
	set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" CACHE PATH "Directory containing mylibraryFind.cmake")
	find_package(mylibrary REQUIRED MODULE)
endif()

message("Tutorial : Configuring ${CMAKE_CURRENT_BINARY_DIR}/myapp")
add_executable(myapp ${sources} ${headers})
target_link_libraries(myapp mylibrary)

message("Tutorial : Configuring ${CMAKE_INSTALL_PREFIX}/bin/myapp")
install(TARGETS myapp
	RUNTIME DESTINATION bin
	COMPONENT application
)
