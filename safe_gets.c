#include <windows.h>
#include <wchar.h>
#include <strsafe.h>

#define BUF_LEN 8191

int wmain()
{
	wchar_t buf[BUF_LEN] = {0};
	HRESULT r = StringCchGetsW(buf, ARRAYSIZE(buf));
	if(SUCCEEDED(r))
	{
		wprintf(L"You have entered: %ls\n", buf);
	}
	else
	{
		wprintf(L"StringCchGetsW() failed\n");
		return 1;
	}
	
	return 0;
}