#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i = 42;
	string s = to_string(i);
	cout << s << endl;
	double d = stod(s);
	cout << ++d << endl;
	
	string s2 = "pi = 3.1415926";
	cout << s2 << endl;
	long double ld = stold(s2.substr(s2.find_first_of("+-.0123456789")));
	cout << ld << endl; //3.14159	!!!
	cout << to_string(ld) << endl; //3.141593	!!!
	return 0;
}