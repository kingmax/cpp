#include <iostream>
using namespace std;

#define DLLExport __declspec(dllexport)
#define DLLImport __declspec(dllimport)

//__declspec(dllimport) int add(int, int);
DLLImport int add(int, int);

//2 code & data section
DLLImport void SetX(int);
DLLImport int GetX();

//3 动态内存管理 https://blog.csdn.net/nullccc/article/details/80957423
DLLImport int* GetIntArray(int);
DLLImport void FreePtr(int*);

int main()
{
	int x = 100;
	int y = 200;
	int z = add(x, y);
	cout << x << "+" << y << "=" << z << endl;
	
	//2
	cout << "\n2. code & data section\n";
	cout << "static global variable int x=" << GetX() << endl;
	SetX(123);
	cout << "after SetX(123), x=" << GetX() << endl;
	
	//3
	cout << "\n//3 动态内存管理\n";
	const int size = 3;
	int *p = GetIntArray(size);
	for (size_t i = 0; i < size; i++)
	{
		cout << p[i] << ", ";
	}
	//free(p);	//Error!!! 必须在DLL里释放
	FreePtr(p);
	cout << endl;


	system("pause");
	return 0;
}