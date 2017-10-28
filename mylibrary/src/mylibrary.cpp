#include <mylibrary/mylibrary.h>

#include <iostream>

#ifdef BUILD_FUNNY_COMPONENT

void print_funny(char const *const message)
{
	std::cout << "Know what's funny ? " << message << std::endl;
}

#endif
