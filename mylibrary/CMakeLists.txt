
set(headers
	include/mylibrary/mylibrary.h
)

set(sources
	src/mylibrary.cpp
)

message("Tutorial : Configuring ${CMAKE_CURRENT_BINARY_DIR}/mylibrary")
add_library(mylibrary ${sources} ${headers})
