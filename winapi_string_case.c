#include <windows.h>
#include <wchar.h>

#pragma comment(lib, "user32.lib")

int wmain()
{
	wchar_t str[] = L"Europa";
	wprintf(L"%ls\n", str);
	
	CharLowerW(str);
	wprintf(L"%ls\n", str);
	
	CharUpperW(str);
	wprintf(L"%ls\n", str);
	
	return 0;
}