#include <iostream>

int main()
{
	int i=0, &r1 = i;
	double d=0, &r2 = d;
	
	r2 = 3.14159;
	r2 = r1; //0
	i = r2;  //0
	r1 = d;  //0
	
	std::cout << i << ' ' << r1 << ' ' << d << ' ' << r2 << std::endl; //0 0 0 0
	
	int x, &rx = x;
	x = 5;
	rx = 10;
	std::cout << x << " " << rx << std::endl; //10, 10
	
	return 0;
}