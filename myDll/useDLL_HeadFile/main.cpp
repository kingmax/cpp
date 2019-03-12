#include "dll.h"
#include <iostream>

#pragma comment(lib, "DLL.lib")

int main()
{
	int m = Mul(10, 10);
	std::cout << m << std::endl;

	system("pause");

	return 0;
}
