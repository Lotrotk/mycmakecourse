
set(headers
)

set(sources
	src/main.cpp
)

message("Tutorial : Configuring ${CMAKE_CURRENT_BINARY_DIR}/myapp")
add_executable(myapp ${sources} ${headers})
target_link_libraries(myapp mylibrary)

add_test(simpletest myapp "I am !")
add_test(argumentstest myapp "I am !" "I'm the funniest !")

#verify that argumentstest does not exit with 0
set_tests_properties(argumentstest PROPERTIES WILL_FAIL TRUE)
