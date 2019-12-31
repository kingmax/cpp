#include <windows.h>
#include <wchar.h>
#include <strsafe.h>

int wmain()
{
	wchar_t *sentence = L"Today is a rainy day";
	size_t size = wcslen(sentence) + 1;
	
	wchar_t *buf = new wchar_t[size];
	ZeroMemory(buf, size);
	
	HRESULT r = StringCchCopyW(buf, size, sentence);
	if(SUCCEEDED(r))
	{
		wprintf(L"%ls\n", buf);
	}
	else
	{
		wprintf(L"StringCchCopyW() failed\n");
		return 1;
	}
	delete[] buf;
	
	return 0;
}