#include <iostream>
#include <string>

extern "C"
{
	__declspec(dllexport) int fn(const std::string s)
	{
		std::cout << "The following string output in cpp:\n";
		std::cout << s << std::endl;
		return 43;
	}
}