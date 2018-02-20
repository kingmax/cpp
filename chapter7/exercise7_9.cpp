#include "Person.h"

int main()
{
	std::cout << "Enter Person: name addr" << std::endl;
	Person p;
	while(input(std::cin, p))
	{
		output(std::cout, p) << std::endl;
	}
	
	return 0;
}