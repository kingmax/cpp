#include <windows.h>

#pragma comment(lib, "user32.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	
	WNDCLASSW wc = {0};
	wc.lpszClassName = L"Flashing";
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	
	RegisterClassW(&wc);
	CreateWindowW(wc.lpszClassName, wc.lpszClassName,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 500, 400, 0, 0, hInstance, 0);
		
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	FLASHWINFO fwi;
	switch(msg)
	{
		case WM_CREATE:
			CreateWindowW(L"Button", L"Flash",
				WS_CHILD | WS_VISIBLE,
				10, 10, 80, 25,
				hwnd, (HMENU)1, NULL, NULL);
			break;
		
		case WM_COMMAND:
			fwi.cbSize = sizeof(fwi);
			fwi.dwFlags = FLASHW_ALL;
			fwi.dwTimeout = 0;
			fwi.hwnd = hwnd;
			fwi.uCount = 4;
			
			FlashWindowEx(&fwi);
			break;
			
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}