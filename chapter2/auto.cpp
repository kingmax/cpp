#include <iostream>

int main()
{
	double v1=1, v2=2;
	auto item = v1 + v2;
	std::cout << item << std::endl;
	
	auto i=0, *p=&i;
	//auto sz=0, pi=3.14; //error, only one type
	
	int n = 0, &r = n;
	auto a = r; //int
	std::cout << a << std::endl;
	
	const int ci = n, &cr = ci;
	auto b = ci; //int
	auto c = cr; //int
	c = 10;
	std::cout << b << ' ' << cr << ' ' << c << std::endl;
	auto d = &i; //ptr point to int
	std::cout << d << ' ' << *d << ' ' << std::endl;
	d = &c;
	std::cout << d << ' ' << *d << ' ' << std::endl;
	auto e = &ci; //ptr point to const int
	
	const auto f = ci; //const int
	const auto g = &ci; //const ptr point to const int
	//g = &c; //error
	
	auto &g2 = ci; //ref binding to const int
	//auto &h = 42; //error, can't int & <- int
	const auto &j = 42; //ok, const int can assign literal
	
	auto k = ci, &l = i; //k is int, l is int &
	auto &m = ci, *p3 = &ci; //m is ref to const int, p3 is ptr point to const int
	std::cout << m << ' ' << *p3 << std::endl;
	
	//auto &n2 = i, *p4 = &ci; //error, i is int, ci is const int
	

	return 0;
}