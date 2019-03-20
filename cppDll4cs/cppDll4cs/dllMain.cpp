#include <iostream>
#include <string>
using namespace std;

/*
	cpp dll for c# call:
	1. extern "C" (if for another cpp call, even using extern "C" when dllimport)
	2. x86 -> 32bit (x64 error!)
	ͨ��extern "C"ʹ��(������������C++�������������ظı䣬ͬʱ��C���Է�ʽд,�粻ʹ��string����ʹ��char*)
	ʹ��x86(32λ����DLL)
*/

extern "C"
{
	__declspec(dllexport) int test(const char *s) // ok
	//__declspec(dllexport) int test(const string s) // error in c#, ����˺����������룡
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
	test("���");
	system("pause");
	return 0;
}