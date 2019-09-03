#include <windows.h>

#pragma comment(lib, "user32.lib")

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR lpszCmdLine, int iCmdShow)
	{
		MessageBoxW(NULL, L"Hello, Windows", L"helloMsg", 0);
		
		return 0;
	}