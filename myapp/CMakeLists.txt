
set(headers
)

set(sources
	src/main.cpp
)

message("Tutorial : Configuring ${CMAKE_CURRENT_BINARY_DIR}/myapp")
link_libraries(mylibrary)
add_executable(myapp ${sources} ${headers})
