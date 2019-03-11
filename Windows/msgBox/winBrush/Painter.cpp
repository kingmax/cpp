#include "stdafx.h"
#include "Painter.h"

MyPainter::MyPainter()
{
	for (size_t i = 0; i < 7; i++)
	{
		hPen[i] = CreatePen(pens[i], 1, RGB(0, 255, 0));
		
		if (i != 6)
		{
			hBrush[i] = CreateHatchBrush(brushes[i], RGB(255, 0, 0));
		}
		else
		{
			hBrush[i] = CreateHatchBrush(brushes[i], RGB(0, 255, 0));
		}
	}
}

void MyPainter::Paint(HDC hdc)
{
	int y, x1, x2;
	for (size_t i = 0; i < 7; i++)
	{
		y = (i + 1) * 30;
		SelectObject(hdc, hPen[i]);
		MoveToEx(hdc, 30, y, NULL); 
		LineTo(hdc, 100, y); //draw line
	}

	x1 = 120;
	x2 = 180;

	for (size_t i = 0; i < 7; i++)
	{
		SelectObject(hdc, hBrush[i]);
		Rectangle(hdc, x1, 30, x2, y); 
		x1 += 70;
		x2 += 70;
	}
}
