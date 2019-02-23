#include <string>
#include <iostream>
using namespace std;

template<typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;
}

template<typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
	os << t << ", ";
	return print(os, rest...);
}

int main()
{
	print(cout, 100, "hi", 3.1415926);
	cout << endl;
	print(cout, "hi", 3.1415926);
	cout << endl;
	print(cout, 3.1415926) << endl;
	return 0;
}