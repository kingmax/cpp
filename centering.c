#include <windows.h>

#pragma comment(lib, "user32.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CenterWindow(HWND);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
					PWSTR pCmdLine, int nCmdShow)
	{
		MSG msg;
		
		WNDCLASSW wc = {0};
		wc.lpszClassName = L"Center";
		wc.hInstance = hInstance;
		wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
		wc.lpfnWndProc = WndProc;
		wc.hCursor = LoadCursor(0, IDC_ARROW);
		
		RegisterClassW(&wc);
		CreateWindowW(wc.lpszClassName, L"Center",
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
		case WM_CREATE:
			CenterWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}	

void CenterWindow(HWND hwnd)
{
	RECT rc = {0};
	
	GetWindowRect(hwnd, &rc);
	int w = rc.right - rc.left;
	int h = rc.bottom - rc.top;
	
	int screen_w = GetSystemMetrics(SM_CXSCREEN);
	int screen_h = GetSystemMetrics(SM_CYSCREEN);
	
	SetWindowPos(hwnd, HWND_TOP, (screen_w - w)/2,
		(screen_h - h)/2, 0, 0, SWP_NOSIZE);
}