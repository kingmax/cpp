#include <Windows.h>
#include <windowsx.h>

#define WIN32_LEAN_AND_MEAN

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
	win.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	win.hCursor = LoadCursor(NULL, IDC_CROSS);
	win.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
	win.lpszMenuName = NULL;
	win.lpszClassName = L"myWindow";

	return 0;
}
