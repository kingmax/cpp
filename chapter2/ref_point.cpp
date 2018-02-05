#include <iostream>

int main()
{
	int i = 100;
	int *p = nullptr;
	int *&r = p; //refers to point p: int* &r = p, (Error: int &r = p)
	r = &i;		// r is address (alias of p, so p now point to i)
	std::cout << i << ' ' << r << ' ' << *r << ' ' << *p << std::endl;
	
	//int &r2; //reference must be init
	
	return 0;
}