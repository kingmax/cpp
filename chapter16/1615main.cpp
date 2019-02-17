#include "1614.h"
#include <iostream>

int main()
{
	Screen<640,480> s0("please input some words");
	std::cout << s0 << std::endl;
	s0.size_info();
	
	Screen<320,240> s;
	std::cin >> s;
	std::cout << s;
	
	s.size_info();
	
	return 0;
}