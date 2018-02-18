#include <iostream>
#include <string>
using namespace std;

inline const string &shorterString(const string &s1, const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

int main()
{
	string s1 = "hi", s2 = "hello";
	const string &ss = shorterString(s1, s2);
	cout << ss << endl;
	cout << &s1 << ' ' << &s2 << ' ' << &ss << endl;
	
	return 0;
}