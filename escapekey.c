#include <windows.h>
#pragma comment(lib, "user32.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR pCmdLine, int nCmdShow)
{
	MSG msg;
	
	WNDCLASSW wc = {0};
	wc.lpszClassName = L"Escape";
	wc.hInstance = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpfnWndProc = WndProc;
	
	RegisterClassW(&wc);
	CreateWindowW(wc.lpszClassName, wc.lpszClassName,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 400, 300, 0, 0, hInstance, 0);
	
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_KEYDOWN:
			if(wParam == VK_ESCAPE)
			{
				int ret = MessageBoxW(hwnd, L"Are you sure to quit?", L"Message", MB_OKCANCEL);
				if(IDOK == ret)
					SendMessage(hwnd, WM_CLOSE, 0, 0);
			}
			break;
			
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}