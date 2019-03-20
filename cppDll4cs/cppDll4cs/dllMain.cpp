#include <iostream>
#include <string>
using namespace std;

/*
	cpp dll for c# call:
	1. extern "C" (if for another cpp call, even using extern "C" when dllimport)
	2. x86 -> 32bit (x64 error!)
	通过extern "C"使用(函数名不会像C++那样被可能重载改变，同时按C语言方式写,如不使用string而是使用char*)
	使用x86(32位编译DLL)
*/

extern "C"
{
	__declspec(dllexport) int test(const char *s) // ok
	//__declspec(dllexport) int test(const string s) // error in c#, 输出了后面多余的乱码！
	{
		cout << "dll function test(const string) in cpp:\n\t";
		cout << s << endl;
		return 100;
	}

	__declspec(dllexport) int add(int a, int b) { return a + b; }	// ok
}

int main()
{
	cout << add(100, 100) << endl;
	test("你好");
	system("pause");
	return 0;
}