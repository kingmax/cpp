#include <windows.h>

#pragma comment(lib, "user32.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);

#define IDM_FILE_NEW 1
#define IDM_FILE_OPEN 2
#define IDM_FILE_QUIT 3

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	
	WNDCLASSW wc = {0};
	wc.lpszClassName = L"Simple menu";
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	
	RegisterClassW(&wc);
	
	CreateWindowW(wc.lpszClassName, wc.lpszClassName,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 350, 250, 0, 0, hInstance, 0);
	
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
			AddMenus(hwnd);
			break;
			
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDM_FILE_NEW:
				case IDM_FILE_OPEN:
					MessageBeep(MB_ICONINFORMATION);
					break;
					
				case IDM_FILE_QUIT:
					SendMessage(hwnd, WM_CLOSE, 0, 0);
					break;
			}
			break;
			
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void AddMenus(HWND hwnd)
{
	HMENU hMenubar;
	HMENU hMenu;
	
	hMenubar = CreateMenu();
	hMenu = CreateMenu();
	
	AppendMenuW(hMenu, MF_STRING, IDM_FILE_NEW, L"&New");
	AppendMenuW(hMenu, MF_STRING, IDM_FILE_OPEN, L"&Open");
	AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
	AppendMenuW(hMenu, MF_STRING, IDM_FILE_QUIT, L"&Quit");
	
	AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR)hMenu, L"&File");
	SetMenu(hwnd, hMenubar);
}