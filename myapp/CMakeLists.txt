cmake_minimum_required(VERSION 3.1)
project(MYAPP)

set(CMAKE_CXX_STANDARD_11)

set(headers
)

set(sources
	src/main.cpp
)

if(NOT TARGET mylibrary)
	message("Tutorial : Target mylibrary not defined. Commence search...")
	#mylibrary_DIR is used by find_package()
	set(mylibrary_DIR "" CACHE PATH "Directory containing mylibraryConfig.cmake")
	find_package(mylibrary REQUIRED
		COMPONENTS funny_print
	)
endif()

message("Tutorial : Configuring ${CMAKE_CURRENT_BINARY_DIR}/myapp")
add_executable(myapp "${sources}" "${headers}")
target_link_libraries(myapp mylibrary)

message("Tutorial : Configuring ${CMAKE_INSTALL_PREFIX}/bin/myapp")
install(TARGETS myapp
	RUNTIME DESTINATION bin
)
