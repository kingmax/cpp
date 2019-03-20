#include <iostream>
#include <string>
using namespace std;

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