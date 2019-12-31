#include <windows.h>
#include <wchar.h>

int wmain()
{
	FILETIME ft = {0};
	
	GetSystemTimeAsFileTime(&ft);
	
	LARGE_INTEGER li = {0};
	
	li.LowPart = ft.dwLowDateTime;
	li.HighPart = ft.dwHighDateTime;
	
	long long int hns = li.QuadPart;
	
	wprintf(L"%lli hundreds of nanoSeconds have elapsed "
		"since Windows API epoch\n", hns);
	
	return 0;
}
