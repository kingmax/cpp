#include <Windows.h>
#include <windowsx.h>

#include "main.h"
#include <iostream>

#define WIN32_LEAN_AND_MEAN

// Global Vars
HINSTANCE hInst;
const LPCWSTR className = L"myWindow";
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
LRESULT CALLBACK About(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);


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
	//win.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	win.lpszClassName = className;
	//win.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	win.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	if (!RegisterClassEx(&win))
	{
		return 0;
	}

	hInst = hInstance;

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
		NULL, /*LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1))*/NULL, hInstance, NULL
	);

	if (!hwnd)
	{
		return FALSE;
	}

	HMENU hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1));
	SetMenu(hwnd, hMenu);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);


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
		case WM_ACTIVATE:
		{
			if (LOWORD(wparam) == WA_CLICKACTIVE)
			{
				HWND hPrev = (HWND)lparam;
				LPTSTR title = new TCHAR[32];
				GetWindowText(hPrev, title, 32);
				MessageBox(hwnd,/* L"Yes, I do!"*/title, L"你用鼠标激活了窗口", MB_OK);
				title = nullptr;
				//delete title;
			}
			if (HIWORD(wparam) == TRUE)
			{
				//std::cout << HIWORD(wparam) << std::endl;
			}
			break;
		}

		case WM_SIZE:
		{
			TCHAR txt[64];
			int w = LOWORD(lparam);
			int h = HIWORD(lparam);
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			sprintf(txt, "w = %d, h = %d \0", w, h);
			TextOut(hdc, 0, 0, txt, 64);
			EndPaint(hwnd, &ps);
			if (wparam == SIZE_MAXIMIZED)
			{
				MessageBox(hwnd, L"窗口最大化了", _T("提示"), MB_OK);
			}
			break;
		}

		case WM_CREATE:
		{
			break;
		}

		case WM_COMMAND:
		{
			//响应菜单命令
			int wmID = LOWORD(wparam);
			switch (wmID)
			{
			case ID_FILE_MESSAGE:
				MessageBox(hwnd, TEXT("This is a message"), TEXT("Caption"), MB_OK);
				break;

			case ID_FILE_EXIT:
				//DestroyWindow(hwnd);
				PostMessage(hwnd, WM_CLOSE, wparam, lparam);
				break;

			case ID_HELP_ABOUT:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, About);
				break;

			default:
				return DefWindowProc(hwnd, msg, wparam, lparam);
			}
		}

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
			break;
		}

		case WM_CLOSE:
		{
			int ok = MessageBox(hwnd, L"确定退出？", L"True?", MB_YESNO);
			if (ok == IDYES)
			{
				return DefWindowProc(hwnd, msg, wparam, lparam);
			}
			break;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}

		default:
			return DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return 0;
}

INT_PTR CALLBACK About(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	}
	return (INT_PTR)FALSE;
}