#include <windows.h>
#include <wchar.h>

int wmain()
{
	wchar_t LogicalDrives[MAX_PATH] = {0};
	DWORD r = GetLogicalDriveStringsW(MAX_PATH, LogicalDrives);
	
	if(0==r)
	{
		wprintf(L"Failed to get drive names %ld", GetLastError());
		return 1;
	}
	
	if(r > 0 && r <= MAX_PATH)
	{
		wchar_t *SingleDrive = LogicalDrives;
		while(*SingleDrive)
		{
			wprintf(L"%ls\n", SingleDrive);
			SingleDrive += wcslen(SingleDrive) + 1;
		}
	}
	
	return 0;
}