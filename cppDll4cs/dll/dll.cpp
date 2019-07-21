// dll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"


extern "C"
{
	__declspec(dllexport) void e()
	{
		MessageBox(NULL, L"from cpp dll", L"win32", MB_OK);
	}
}