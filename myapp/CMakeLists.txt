
set(headers
)

set(sources
	src/main.cpp
)

message("Tutorial : Configuring ${CMAKE_CURRENT_BINARY_DIR}/myapp")
add_executable(myapp ${sources} ${headers})
target_link_libraries(myapp mylibrary)
