#include <iostream>

int main()
{
	//int i=-1, &r=0; //error, ref type must be init
	int i2 = 2;
	int *const p2 = &i2; //ok, const ptr point to int
	std::cout << p2 << ' ' << *p2 << std::endl;
	*p2 = 3;
	std::cout << p2 << ' ' << *p2 << std::endl;
	
	const int i = -1, &r=0;
	const int &r1 = 0;
	std::cout << i << ' ' << r << ' ' << r1 << std::endl;
	//r = 1; //error
	//r1 = 1; //error
	
	const int *const p3 = &i2; //ok, const ptr point to const int
	std::cout << p3 << ' ' << *p3 << std::endl;
	if(p2 == p3)
		std::cout << "p2 == p3" << std::endl;
	
	const int *p1 = &i2; //ok, ptr point to const int
	std::cout << p1 << ' ' << *p1 << std::endl;
	std::cout << (p1 == p2) << std::endl; //1
	
	//const int &const r2 = -2; //error
	//std::cout << r2 << std::endl; 
	
	int j = 1;
	const int k = j, &r3 = j;
	std::cout << j << ' ' << k << ' ' << r3 << std::endl;
	
	//int *const cp; //error, const ptr must be init
	//const int ic, &ric = ic; //error, const must be init
	const int ic=100, &ric = ic;
	//const int *const p4; //error const ptr must be init
	const int *p; //ok, but ptr not point to anything!
	//std::cout << p << ' ' << *p << std::endl; //error, using un-init ptr!
	
	j = ic; //ok, int j be changed
	p1 = p3; //ok, p1 point to p3
	p1 = &ic; //ok, p1 point to ic
	p3 = &ic; //error, can't change const ptr
	p2 = p1; //error, can't change const ptr
	ic = *p3; //error, const can't change
	
	return 0;
}