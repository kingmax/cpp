#pragma once

#ifdef MYDLL_EXPORTS
#define MYAPI __declspec(dllexport)
#define MYAPI2 extern "C" MYAPI
#else
#define MYAPI __declspec(dllimport)
#endif

MYAPI int add(int x, int y);

class MYAPI Box
{
public:
	Box() = default;
	~Box() = default;

	double Volumn();
	double GetLength();
	double GetWidth();
	double GetHeight();
	void SetLength(double);
	void SetWidth(double);
	void SetHeight(double);

private:
	double length = 2.0;
	double width = 2.0;
	double height = 2.0;
};

// dynamic load dll, extern "C" __declspec(dllexport)
MYAPI2 int mul(int a, int b);
