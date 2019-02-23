#include <iostream>
using namespace std;

template<typename T, typename... Args>
void foo(const T& t, const Args& ... rest);

int main()
{
	return 0;
}