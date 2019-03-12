#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	HMODULE hModule = LoadLibrary(L"dllWithHeader.dll");
	if (hModule)
	{
		typedef int(*DLL_MUL)(int, int);
		DLL_MUL mul = (DLL_MUL)GetProcAddress(hModule, "mul");
		if (mul)
		{
			int z = mul(100, 10000);
			cout << "Dynamic Load DLL Function mul(100, 10000)=" << z << endl;
		}
		else
		{
			cout << "GetProcAddress(hModule,\"mul\") -> NULL\n";
		}
		FreeLibrary(hModule);
	}
	else
	{
		cout << "LoadLibrary result is NULL!\n";
	}

	getchar();
	return 0;
}