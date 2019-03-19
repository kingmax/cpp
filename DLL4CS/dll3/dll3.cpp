// dll3.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;

extern "C"
{
	__declspec(dllexport) int Test(const string s)
	{
		cout << "cout from cpp Test [dll3, win32 dll, any cpu or x86]" << endl;
		return 100;
	}
}
