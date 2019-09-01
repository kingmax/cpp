#include <windows.h>
#include <wchar.h>

int wmain()
{
	SYSTEMTIME st1;
	SYSTEMTIME st2;
	FILETIME ft1;
	FILETIME ft2;
	
	st1.wYear = 2019;
	st1.wMonth = 9;
	st1.wDay = 1;
	
	st2.wYear = 2020;
	st2.wMonth = 1;
	st2.wDay = 1;
	
	int r1 = SystemTimeToFileTime(&st1, &ft1);
	if(0 == r1)
	{
		wprintf(L"Failed to convert system time to file time\n (%d)", GetLastError());
		return 1;
	}
	
	int r2 = SystemTimeToFileTime(&st2, &ft2);
	if(0 == r2)
	{
		wprintf(L"Failed to convert system time to file time\n (%d)", GetLastError());
		return 1;
	}
	
	short ct = CompareFileTime(&ft1, &ft2);
	if(ct == -1)
	{
		wprintf(L"%02d/%02d/%02d comes before %02d/%02d/%02d", st1.wDay, st1.wMonth, st1.wYear, st2.wDay, st2.wMonth, st2.wYear);
	}
	else if(ct == 0)
	{
		wprintf(L"%02d/%02d/%02d is equal to %02d/%02d/%02d", st1.wDay, st1.wMonth, st1.wYear, st2.wDay, st2.wMonth, st2.wYear);
	}
	else
	{
		wprintf(L"%02d/%02d/%02d comes after %02d/%02d/%02d", st1.wDay, st1.wMonth, st1.wYear, st2.wDay, st2.wMonth, st2.wYear);
	}
	
	return 0;
}