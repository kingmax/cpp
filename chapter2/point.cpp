#include <iostream>

int main()
{
	int ival = 42;
	int *p = &ival;
	std::cout << "p.address = " << p << ", *p = " << *p <<std::endl;
	*p = 0;
	std::cout << "p.address=" << p << ", *p=" << *p << std::endl;
	
	int i = 100;
	int &r = i;
	int *pa;
	pa = &i;
	*pa = ++i; //i = ++i, 101
	int &r2 = *pa;//101
	std::cout << i << ' ' << r << ' ' << *pa << ' ' << r2 << std::endl;//101, 101, 101, 101 
	
	return 0;
}