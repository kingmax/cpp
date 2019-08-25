#include <windows.h>
#include <wchar.h>

int wmain()
{
	wchar_t *s1 = L"ZetCode, ";
	wchar_t *s2 = L"tutorials ";
	wchar_t *s3 = L"for ";
	wchar_t *s4 = L"programmers.\n";
	
	//ZetCode, tutorials for programmers.
	
	int len = lstrlenW(s1) + lstrlenW(s2)
		+ lstrlenW(s3) + lstrlenW(s4);
	wprintf(L"len = %d\n", len);
	
	//wchar_t buf[len+1]; //vs���鳤�ȷǳ���ʱ�޷�ͨ������
	//��C����û��new,���Ա���C++��(C������malloc?)
	wchar_t *buf = new wchar_t[len+1];
	lstrcpyW(buf, s1);
	lstrcatW(buf, s2);
	lstrcatW(buf, s3);
	lstrcatW(buf, s4);
	
	wprintf(L"%s\n%d\n", buf, lstrlenW(buf));
	delete[] buf;
	
	return 0;
}