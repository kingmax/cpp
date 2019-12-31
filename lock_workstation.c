#include <windows.h>
#include <wchar.h>

#pragma comment(lib, "user32.lib")

int wmain()
{
	int r = LockWorkStation();
	if(0 == r)
	{
		wprintf(L"LockWorkStation() failed %d\n", GetLastError());
		return 1;
	}
	return 0;
}