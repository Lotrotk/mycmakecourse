#include <iostream>
#include <fstream>

/**
 * first argument : output_file
 * second argument : number of fibonacci numbers to write to file
 */
int main(int const argc, char const *argv[])
{
	if(argc != 3)
	{
		std::cerr << "Fibonacci : wrong number of arguments" << std::endl;
		return 1;
	}
	
	int const number = atoi(argv[2]);
	if(number < 0)
	{
		std::cerr << "Fibonacci : cannot write " << number << "fibonacci numbers" << std::endl;
		return 2;
	}
	
	std::ofstream ofs(argv[1]);
	if(!ofs.good())
	{
		std::cerr << "Fibonacci : failed to write " << argv[1] << std::endl;
		return 3;
	}
	
	uint64_t previous = 0;
	uint64_t current = 1;
	
	ofs << "{\n";
	for(int i = 0; i < number; ++i)
	{
		ofs << current << ",\n";
		uint64_t const p = previous;
		previous = current;
		current += p;
	}
	ofs << '}';
	
	return 0;
}
