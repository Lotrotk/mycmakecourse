
set(headers
)

set(sources
	src/main.cpp
)

message("Tutorial : Configuring ${CMAKE_CURRENT_BINARY_DIR}/myapp")
add_executable(myapp ${sources} ${headers})
target_link_libraries(myapp mylibrary)

message("Tutorial : Configuring ${CMAKE_INSTALL_PREFIX}/bin/myapp")
install(TARGETS myapp
	RUNTIME DESTINATION bin
	COMPONENT application
)
