#include <stdlib.h>

#define DLLExport __declspec(dllexport)
#define DLLImport __declspec(dllimport)

//__declspec(dllexport) int add(int a, int b)
DLLExport int add(int a, int b)
{
	return a + b;
}

//2 code & data section
static int x = 0; //global

DLLExport void SetX(int var)
{
	x = var;
}

DLLExport int GetX()
{
	return x;
}

//3 ��̬�ڴ���� https://blog.csdn.net/nullccc/article/details/80957423
DLLExport int* GetIntArray(int size)
{
	int *p = (int*)malloc(sizeof(int) * size);

	for (size_t i = 0; i < size; i++)
	{
		p[i] = i;
	}

	return p;
}

//������DLL���ͷ�!

DLLExport void FreePtr(int *p)
{
	free(p);
}