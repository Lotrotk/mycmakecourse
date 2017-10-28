
set(BUILD_FUNNY_COMPONENT CACHE BOOL ON "Add funny functionality to the library")
set(EXAMPLE_FUNNY_MESSAGE "well, not this example !")

message("Tutorial : Generating ${CMAKE_CURRENT_BINARY_DIR}/configuration.h")
set(configured_in "${CMAKE_CURRENT_SOURCE_DIR}/include/mylibrary/configuration.h.in")
set(configured_out "${CMAKE_CURRENT_BINARY_DIR}/configuration.h")
configure_file("${configured_in}" "${configured_out}")

set(headers
	include/mylibrary/mylibrary.h
	"${configured_out}"
)

set(sources
	src/mylibrary.cpp
)

message("Tutorial : Configuring ${CMAKE_CURRENT_BINARY_DIR}/mylibrary")
add_library(mylibrary ${sources} ${headers})
target_include_directories(mylibrary
	PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}"
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
install(FILES ${headers}
	DESTINATION "include/mylibrary"
	COMPONENT headers
)
