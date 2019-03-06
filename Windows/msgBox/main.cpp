#include <Windows.h>
#include <windowsx.h>

#define WIN32_LEAN_AND_MEAN

int WINAPI WinMain
	(
		HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow
	)
{
	MessageBox(NULL, "这是第一个窗口", "我的第一个窗口", MB_OK | MB_ICONEXCLAMATION);

	return 0;
}