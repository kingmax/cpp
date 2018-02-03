#include <iostream>

int main()
{
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl; //32
	std::cout << u - u2 << std::endl; //unsigned(-32)
	std::cout << "unsigned(-32) = " << unsigned(-32) << std::endl;
	
	int i3 = -42;
	unsigned u3 = 0;
	u3 = i3;
	std::cout << i3 << ", int convert to unsigned: " << u3
			<< ", unsigned(-42) + int(10) = " << unsigned(-42) + int(10)
			<< std::endl;
	
	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl; //32
	std::cout << i - i2 << std::endl; //-32
	std::cout << i - u << std::endl;  //0
	std::cout << u - i << std::endl;  //0
	return 0;
}