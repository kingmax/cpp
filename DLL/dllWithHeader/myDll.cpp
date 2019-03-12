#define MYDLL_EXPORTS
#include "myDll.h"

MYAPI int add(int x, int y)
{
	return x + y;
}

// Dynamic Load DLL Function -> extern "C" __declspec(dllexport)
MYAPI2 int mul(int a, int b)
{
	return a * b;
}

//class MYAPI Box
double Box::Volumn()
{
	return length * width * height;
}

double Box::GetLength()
{
	return length;
}

double Box::GetWidth()
{
	return width;
}

double Box::GetHeight()
{
	return height;
}

void Box::SetLength(double v)
{
	this->length = v;
}

void Box::SetWidth(double v)
{
	this->width = v;
}

void Box::SetHeight(double v)
{
	this->height = v;
}
