#include <windows.h>
#include <wchar.h>

int wmain()
{
	SYSTEMTIME lt = {0};
	GetLocalTime(&lt);
	wprintf(L"The local time is: %04d/%02d/%02d %02d:%02d:%02d %ld\n", lt.wYear, lt.wMonth, lt.wDay, 
	lt.wHour, lt.wMinute, lt.wSecond,
	lt.wMilliseconds);
	
	return 0;
}