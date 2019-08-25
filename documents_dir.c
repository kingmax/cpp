#include <windows.h>
#include <wchar.h>
#include <initguid.h>
#include <KnownFolders.h>
#include <Shlobj.h>

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "ole32.lib")

int wmain()
{
	PWSTR path = NULL;
	HRESULT hr = SHGetKnownFolderPath(&FOLDERID_Documents, 0, NULL, &path);
	if(SUCCEEDED(hr))
	{
		wprintf(L"My Documents dir is: %ls\n", path);
	}
	CoTaskMemFree(path);
	
	return 0;
}