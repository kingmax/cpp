#include <iostream>

int main()
{
	//decltype(f()) sum = x; //data type is function f return type
	const int ci = 0, &cj = ci;
	decltype(ci) x = 0; //const int
	decltype(cj) y = x; //const int &
	//decltype(cj) z; //error, const int must be init!
	
	int i = 10, *p = &i, &r = i;
	//decltype(r) ref; //error, ref must be init
	decltype(r + 0) myInt; //int
	//decltype(*p) c; //error, int & (ptr) must be init
	
	//decltype((variable)) -> always get ref
	//decltype((i)) d; //error, d is int &, must be init
	decltype(i) e; //ok, e is int (un-init)
	
	//exercise 2.36~2.38
	int a=3, b=4;
	decltype(a) c=a;
	decltype((b)) d = a; //int& <=> ref: &d=a
	std::cout << "a:" << a << ", b:" << b;
	std::cout << "c:" << c << ", d:" << d << std::endl;
	++c;
	std::cout << "a:" << a << ", b:" << b;
	++d; //change a to 4!!!
	std::cout << "a:" << a << ", b:" << b;
	std::cout << "c:" << c << ", d:" << d << std::endl;
	
	std::cout << "a:" << a << ", b:" << b << std::endl;
	decltype(a=b) f = a; //int &
	std::cout << "a:" << a << ", b:" << b << ", f:" << f << std::endl;
	++f; // a changed to 5;
	std::cout << "a:" << a << ", b:" << b << ", f:" << f << std::endl;
	
	
	return 0;
}