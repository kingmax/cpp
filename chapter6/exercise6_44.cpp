#include <iostream>
#include <string>
using namespace std;

inline bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

/* constexpr bool is_shorter(const string &s1, const string &s2) //error
{
	return s1.size() < s2.size();
} */

inline const string true_or_false(int n)
{
	return n != 0 ? "true" : "false";
}

/* constexpr string trueFalse(int n) //error
{
	return n != 0 ? "true" : "false";
} */

int main()
{
	string s1 = "hi", s2 = "hello";
	cout << true_or_false(isShorter(s1, s2)) << endl;
	
	return 0;
}