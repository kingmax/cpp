#include <iostream>

int reused = 42;

int main()
{
	int unique = 0;
	std::cout << reused << " " << unique << std::endl; //42, 0
	int reused = 0;
	std::cout << reused << " " << unique << std::endl; //0, 0
	
	std::cout << ::reused << " " << unique << std::endl; //42, 0
	return 0;
}