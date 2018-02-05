#include <iostream>

int main()
{
	constexpr int mf=20;
	constexpr int limit = mf+1;
	//constexpr int sz = size();
	std::cout << "constexpr must be get result at compile, not runtime!\n";
	std::cout << "constexpr: " << mf << ", " << limit << std::endl;
	
	return 0;
}