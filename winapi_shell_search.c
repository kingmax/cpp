#include <windows.h>
#include <wchar.h>
#include "shlwapi.h"

#pragma comment(lib, "Shlwapi.lib")

int wmain()
{
	wchar_t buf[] = L"Today is a rainy day";
	wchar_t *search_word = L"rainy";
	
	int len = wcslen(search_word);
	
	LPWSTR pr = StrStrW(buf, search_word);
	if(NULL == pr)
	{
		wprintf(L"No match\n", buf);
	}
	else
	{
		wprintf(L"%.*ls is found\n", len, pr);
	}
	
	return 0;
}