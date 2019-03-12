#include "myDll.h"
#include <iostream>
using namespace std;

int main()
{
	int x = 100;
	int y = 900;
	int z = add(x, y);
	std::cout << x << "+" << y << "=" << z << std::endl;

	//class Box
	Box box;
	cout << "\nw=" << box.GetWidth() << ", h=" << box.GetHeight() << ", l=" << box.GetLength()
		<< "\t Volumn=" << box.Volumn() << endl;

	box.SetWidth(10);
	box.SetHeight(10);
	box.SetLength(10);
	cout << "\nw=" << box.GetWidth() << ", h=" << box.GetHeight() << ", l=" << box.GetLength()
		<< "\t Volumn=" << box.Volumn() << endl;

	system("pause");
	return 0;
}