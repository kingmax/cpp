#include <iostream>

int main()
{
	constexpr int mf=20;
	constexpr int limit = mf+1;
	//constexpr int sz = size();
	std::cout << "constexpr must be get result at compile, not runtime!\n";
	std::cout << "constexpr: " << mf << ", " << limit << std::endl;

	const int *p = nullptr;     //ptr point to const int
	constexpr int *q = nullptr; //const ptr point to int
	
	constexpr int *np = nullptr;
	int j = 0;
	constexpr int i = 42; //const int i=42;
	constexpr const int *p1 = &i; //const ptr point to const int
	constexpr int *p2 = &j; //const ptr point to int
	
	//int null=0, *px=null; //error
	int null=0, *px = &null;
	
	return 0;
}