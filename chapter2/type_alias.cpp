#include <iostream>
#include "../Sales_item.h"

int main()
{
	typedef double wages;
	typedef wages base, *p;
	
	using SI = Sales_item;
	SI si;
	std::cout << si <<std::endl;
	
	typedef char *pstring; //ptr point to char
	const pstring cstr=0;  //const ptr point to char
	const pstring *ps;	   //ptr point to const ptr2(point to char)
	
	return 0;
}