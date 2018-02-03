#include <iostream>
#include <string>

std::string global_str;
int global_int;

int main()
{
	//std::cin >> int input_value; //error
	//std::cout << input_value << std::endl; //error
	
	//int i = {3.14}; //c++ 11, but compile error, not int
	//std::cout << i << std::endl; //error
	
	//double salary = wage = 9999.99; //error
	double salary = 9999.99, wage; //warning wage uninit, cl /c /D "UNICODE" /EHsc /w exercise2_9.cpp
	std::cout << "salary=" << salary << ", wage=" << wage << std::endl;
	
	int j = 3.14;
	std::cout << "j=" << j << std::endl; //3
	
	int x(0), y=0, z{0}, n={0};
	std::cout << x << ' ' << y << ' ' << z << ' ' << n << std::endl;
	
	int local_int; //warning local_int uninit, cl /c /D "UNICODE" /EHsc /w exercise2_9.cpp
	std::string local_str;
	std::cout << "global_str:" << global_str
			<< ", global_int:" << global_int
			<< ", local_str:" << local_str
			<< ", local_int:" << local_int
			<< std::endl;
	
	return 0;
}