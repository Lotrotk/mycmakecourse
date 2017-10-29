#include <mylibrary/mylibrary.h>

#include <iostream>

int main(int const argc, char const *argv[])
{
	if(argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}
	
	print_funny(argv[1]);

	return 0;
}
