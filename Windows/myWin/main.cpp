#include <Windows.h>
#include <windowsx.h>

#include "main.h"

#define WIN32_LEAN_AND_MEAN

const LPCWSTR className = L"myWindow";
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*
	typedef struct tagWNDCLASSEXW {
    UINT        cbSize;
    // Win 3.x 
	UINT        style;
	WNDPROC     lpfnWndProc;
	int         cbClsExtra;
	int         cbWndExtra;
	HINSTANCE   hInstance;
	HICON       hIcon;
	HCURSOR     hCursor;
	HBRUSH      hbrBackground;
	LPCWSTR     lpszMenuName;
	LPCWSTR     lpszClassName;
	// Win 4.0 
	HICON       hIconSm;
} WNDCLASSEXW, *PWNDCLASSEXW, NEAR *NPWNDCLASSEXW, FAR *LPWNDCLASSEXW;
	*/

	WNDCLASSEX win;
	win.cbSize = sizeof(WNDCLASSEX);
	win.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC | CS_DBLCLKS;
	win.lpfnWndProc = WndProc;	// callback
	win.cbClsExtra = 0;
	win.cbWndExtra = 0;
	win.hInstance = hInstance;
	//win.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	win.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	win.hCursor = LoadCursor(NULL, IDC_CROSS);
	win.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
	win.lpszMenuName = NULL;
	win.lpszClassName = className;
	//win.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	win.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	if (!RegisterClassEx(&win))
	{
		return 0;
	}

	/*
	CreateWindowExW(
    _In_ DWORD dwExStyle,
    _In_opt_ LPCWSTR lpClassName,
    _In_opt_ LPCWSTR lpWindowName,
    _In_ DWORD dwStyle,
    _In_ int X,
    _In_ int Y,
    _In_ int nWidth,
    _In_ int nHeight,
    _In_opt_ HWND hWndParent,
    _In_opt_ HMENU hMenu,
    _In_opt_ HINSTANCE hInstance,
    _In_opt_ LPVOID lpParam);
#ifdef UNICODE
#define CreateWindowEx  CreateWindowExW
	*/
	
	HWND hwnd;
	hwnd = CreateWindowEx(
		NULL, className, className,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, /*0, 0,*/ 640, 480,
		NULL, NULL, hInstance, NULL
	);

	if (!hwnd)
	{
		return FALSE;
	}

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CREATE:
		{
			
		}
		break;
	case WM_COMMAND:
		{
			
		}
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
		}
		break;
	case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
		break;
	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
}