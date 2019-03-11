#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

class MyPainter
{
public:
	MyPainter();
	~MyPainter() = default;

	void Paint(HDC hdc);

private:
	HPEN hPen[7];
	HBRUSH hBrush[7];
	int pens[7] = { PS_SOLID, PS_DASH, PS_DOT, PS_DASHDOT, PS_DASHDOTDOT, PS_NULL, PS_INSIDEFRAME };	//7 pen styles
	int brushes[6] = { HS_HORIZONTAL, HS_VERTICAL, HS_FDIAGONAL, HS_BDIAGONAL, HS_CROSS, HS_DIAGCROSS }; // 6 hatch styles
};

