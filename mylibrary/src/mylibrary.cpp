#include <mylibrary/mylibrary.h>

#include <iostream>
#include <vector>

void print_funny(char const *const message)
{
	std::cout << "Know what's funny ? " << message << std::endl;
}

static std::vector<uint64_t> data =
#include <fibonacci.txt>
;

uint64_t fibonacci(unsigned int index)
{
	if(index < data.size())
	{
		return data[index];
	}
	
	return 0;
}
