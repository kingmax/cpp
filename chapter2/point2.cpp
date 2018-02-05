#include <iostream>
#include <cstdlib> //NULL

int main()
{
	int *p1 = nullptr; //c++11
	int *p2 = 0; //nullptr
	int *p3 = NULL;
	
	int zero = 0;
	//int *z = zero; //error
	
	int i = 100;
	int *pi = 0;
	int *pi2 = &i;
	int *pi3;
	
	pi3 = pi2;
	pi2 = 0; //now pi2 is nullptr
	
	int ival = 1024;
	int *ptr = 0;
	int *ptr2 = &ival;
	if(ptr)
		std::cout << "nullptr is false" << std::endl;
	if(ptr2)
		std::cout << "non nullptr is true" << std::endl;
	
	double obj = 3.14, *pd = &obj;
	void *pv = &obj;
	pv = pd;
	if(pv == pd)
		std::cout << "void *pv == double *pd, address:" << pv << std::endl;
	else
		std::cout << "void *pv != double *pd" << std::endl;
	
	double myDouble = 100.001, *pd2 = &myDouble;
	std::cout << "myDouble: " << myDouble << ", *pd2: " << *pd2 << std::endl;
	*pd2 = 200.002;
	pd2 = pd;
	std::cout << "Now myDouble: " << myDouble << ", *pd2: " << *pd2 << std::endl;
	
	return 0;
}