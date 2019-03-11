#include <iostream>
using namespace std;

//#pragma comment(lib, "Dll1.lib")

//_declspec(dllexport) int add(int, int);
_declspec(dllimport) int add(int, int);

int main()
{
	cout << 1 << "+" << 2 << "=" << add(1, 2) << endl;
	system("pause");

	return 0;
}