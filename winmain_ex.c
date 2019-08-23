#define _UNICODE
#define UNICODE

#include <Windows.h>
#include <tchar.h>

#pragma comment(lib, "user32.lib")

//int WINAPI wWinMain
//int WINAPI WinMain
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PTSTR szCmdLine, int cmdShow)
{
	MessageBox(NULL, szCmdLine, L"Title", MB_OK);
	
	return 0;
}