#include <windows.h>

#pragma comment(lib, "user32.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CenterWindow(HWND);

#define ID_HOTKEY 1

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	
	WNDCLASSW wc = {0};
	wc.lpszClassName = L"Application";
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	
	RegisterClassW(&wc);
	hwnd = CreateWindowW(wc.lpszClassName, L"Hot Key",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 400, 300, 0, 0, 0, 0);
		
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_CREATE:
			RegisterHotKey(hwnd, ID_HOTKEY, MOD_CONTROL, 0x43);
			break;
			
		case WM_HOTKEY:
			if((wParam) == ID_HOTKEY)
				CenterWindow(hwnd);
			break;
			
		case WM_DESTROY:
			UnregisterHotKey(hwnd, ID_HOTKEY);
			PostQuitMessage(0);
			break;
	}
	
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void CenterWindow(HWND hwnd) {

    RECT rc = {0};
    
    GetWindowRect(hwnd, &rc);
    int win_w = rc.right - rc.left;
    int win_h = rc.bottom - rc.top;

    int screen_w = GetSystemMetrics(SM_CXSCREEN);
    int screen_h = GetSystemMetrics(SM_CYSCREEN);
    
    SetWindowPos(hwnd, HWND_TOP, (screen_w - win_w)/2, 
        (screen_h - win_h)/2, 0, 0, SWP_NOSIZE);
}