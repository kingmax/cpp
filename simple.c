#include <windows.h>

#pragma comment(lib, "user32.lib")

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR pCmdLine, int nCmdShow)
	{
		MessageBoxW(NULL, L"First Program", L"First", MB_OK);
		return 0;
	}