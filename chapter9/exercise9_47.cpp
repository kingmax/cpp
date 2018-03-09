#include <iostream>
#include <string>
using namespace std;

void my_find(const string &s)
{
	const string numbers = "0123456789";
	string::size_type pos = 0;
	cout << "found numbers: ";
	while((pos = s.find_first_of(numbers, pos)) != string::npos)
	{
		cout << s[pos] << ' ';
		++pos;
	}
	cout << endl;
	
	pos = 0;
	cout << "found chars: ";
	while((pos = s.find_first_not_of(numbers, pos)) != string::npos)
	{
		cout << s[pos] << ' ';
		++pos;
	}
	cout << endl;
}

int main()
{
	const string s = "ab2c3d7R4E6";
	my_find(s);
	
	cout << "exercise 9.48 find result: string::npos" << endl;
	string name("r2d2"), numbers = "0123456789";
	cout << numbers.find(name) << endl; //string::npos
	
	
	return 0;
}