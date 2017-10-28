
add_executable(fibonacci src/fibonacci.cpp)

set(FIBONACCI_NUMBERS 25 CACHE STRING "Number of fibonacci numbers supported")
set(output_file "${CMAKE_CURRENT_BINARY_DIR}/fibonacci.txt")
message("Tutorial : Configuring ${output_file}")
add_custom_command(
	OUTPUT "${output_file}"
	COMMAND fibonacci
	#arguments to fibonacci : (string outputfile, int numbers)
	ARGS "${output_file}" "${FIBONACCI_NUMBERS}"
)
add_custom_target(GenerateNumbers
	DEPENDS "${output_file}"
)

set(headers
	include/mylibrary/mylibrary.h
)

set(sources
	src/mylibrary.cpp
)

set(resources
	${output_file}
)

add_library(mylibrary ${sources} ${headers} ${resources})
target_include_directories(mylibrary
	PUBLIC include
	PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
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
