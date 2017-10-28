#include <mylibrary/mylibrary.h>

#include <iostream>

int main()
{
	print_funny("Hello World !");
	
	std::cout << "How many fibonacci numbers do you know ?\n";
	for(int i = 0; i < 10; ++i)
	{
		std::cout << fibonacci(i) << '\n';
	}
	
	std::cout << "And so much more !\n";

	return 0;
}
