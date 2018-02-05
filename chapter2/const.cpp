#include <iostream>

int get_i(){return 100;}

int main()
{
	const int bufSize = 512;
	const int i = get_i();
	//const int j; //error, must be init
	extern const int j;
	
	int x = 1000;
	const int k = x;
	int y = k;
	std::cout << k << ' ' << x << ' ' << y << std::endl; //1000 1000 1000
	x = 2000;
	std::cout << k << ' ' << x << ' ' << y << std::endl; //1000 2000 1000
	
	const int &r = k;
	//int &r2 = k; //error, const not allow change but int &r2 can
	
	const int &r1 = x; //ok <=> const int &r1 = 1000;
	const int &r2 = 100;
	const int &r3 = r1 * 2; //ok <=> const int &r3 = 2000;
	//int &r4 = r1 * 2; 	//error, 
	//int &r5 = 2000;		//error, 
	
	const double &rd = x;	//error, convert int to double make a temp variable
	std::cout << rd << ", &x address:" << &x << std::endl;
	double d = 1.23;
	const int &ri = d; //error, ri.address != d.address, is a temp variable
	std::cout << d << ", &d address:" << &d << ", ri:" << ri 
	<< ", ri.address:" << &ri << std::endl;
	
	//const ref may refers to non-const object
	int n = 10;
	int &rn = n;
	const int &crn = n; //ok
	std::cout << "n=" << n << ", rn=" << rn << ", crn=" << crn << std::endl;
	rn = 100; //crn now also is 100!
	std::cout << "const refer changed!\n";
	std::cout << "n=" << n << ", rn=" << rn << ", crn=" << crn << std::endl;
	
	return 0;
}