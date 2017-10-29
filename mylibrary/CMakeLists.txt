
set(headers
	include/mylibrary/mylibrary.h
)

set(sources
	src/mylibrary.cpp
)

message("Tutorial : Configuring ${CMAKE_CURRENT_BINARY_DIR}/mylibrary")
add_library(mylibrary ${sources} ${headers})
target_include_directories(mylibrary
	PUBLIC include
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
