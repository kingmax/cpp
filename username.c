#include <Windows.h>
#include <Lmcons.h>
#include <wchar.h>

// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getusernamea
#pragma comment(lib, "Advapi32.lib")

int wmain()
{
	wchar_t username[UNLEN + 1];
	DWORD len = sizeof(username) / sizeof(wchar_t);
	
	int r = GetUserNameW(username, &len);
	if(0 == r)
	{
		wprintf(L"Failed to get username %ld", GetLastError());
		return 1;
	}
	
	wprintf(L"User name: %ls\n", username);
	
	return 0;
}