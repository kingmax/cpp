#include <Windows.h>
#include <wchar.h>

#define BUFSIZE MAX_PATH

int wmain(int argc, wchar_t **argv)
{
	wchar_t buf[BUFSIZE];
	
	if(2 != argc)
	{
		wprintf(L"Usage: %ls <dir>\n", argv[0]);
		return 1;
	}
	
	DWORD r = SetCurrentDirectoryW(argv[1]);
	
	if(0 == r)
	{
		wprintf(L"SetCurrentDirectoryW() failed (%ld)\n", GetLastError());
		return 1;
	}
	
	r = GetCurrentDirectoryW(BUFSIZE, buf);
	if(0 == r)
	{
		wprintf(L"GetCurrentDirectory() failed (%ld)\n", GetLastError());
		return 1;
	}
	
	wprintf(L"Current directory is %ls\n", buf);
	
	return 0;
}