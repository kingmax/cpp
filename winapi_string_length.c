#include <windows.h>
#include <wchar.h>

int wmain()
{
	char *name = "Jane";
	wchar_t *chineseName = L"ë��ϯa";
	
	wprintf(L"The length of the name string is: %d\n", lstrlenA(name));
	wprintf(L"The chineseName string length is: %d\n", lstrlenW(chineseName));
	
	return 0;
}