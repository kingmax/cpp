#include <iostream>
#include <string>
using namespace std;

int main()
{
	string _name("AnnaBelle");
	auto pos = _name.find("Anna");
	cout << pos << endl;
	
	string lowercase("annabelle");
	pos = lowercase.find("Anna");
	cout << pos << endl; //18446744073709551615 static std::string::npos
	
	string numbers("0123456789"), name("r2d2");
	pos = name.find_first_of(numbers);
	cout << pos << endl; //1
	
	pos = numbers.rfind("6");
	cout << pos << endl; //6
	
	string dept("03714p3");
	pos = dept.find_first_not_of(numbers);
	cout << pos << endl; //5
	
	cout << name.find_last_of("2") << endl; //3
	
	
	//
	cout << endl;
	string::size_type p = 0;
	while((p = name.find_first_of(numbers, p)) != string::npos)
	{
		cout << "found number at index: " << p
			 << " element is " << name[p] << endl;
		++p;
	}
	cout << endl;
	
	string river("Mississippi");
	cout << river.find("is") << endl; //1
	cout << river.rfind("is")<< endl; //4
	
	
	return 0;
}