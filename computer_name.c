#include <windows.h>
#include <wchar.h>

int wmain()
{
	wchar_t computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	
	int r = GetComputerNameW(computerName, &size);
	if(0==r)
	{
		wprintf(L"Failed to get computer name %ld\n", GetLastError());
		return 1;
	}
	
	wprintf(L"Computer name: %ls\n", computerName);
	
	return 0;
}