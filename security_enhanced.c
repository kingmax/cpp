#include <windows.h>
#include <wchar.h>
#include <locale.h>

#define BUF_LEN 25

int wmain()
{
	//��������������⣬���˳�����Ҫsetlocale��
	//Դ����ҲҪע���������,utf-8���������,תΪANSI������
	
	//https://blog.csdn.net/testcs_dn/article/details/26164025
	setlocale(LC_ALL, "chs");
	//_wsetlocale(LC_ALL, L"chs");
	//https://bbs.csdn.net/topics/390274293?page=1
	//setlocale(LC_CTYPE, ".936");
	
	wchar_t str1[] = L"There are 15 pines";
	
	const int MAX_CHARS = 50;
	size_t count = wcsnlen_s(str1, MAX_CHARS);
	
	wprintf(L"The length of the string is %zd characters\n", count);
	
	wchar_t buf[BUF_LEN] = {0};
	
	int r = wcscpy_s(buf, BUF_LEN, L"Wuthering");
	if(0 != r)
	{
		wprintf(L"wcscpy_s() failed %ld", r);
	}
	
	r = wcscat_s(buf, BUF_LEN, L" heights��ѽ\n");
	if(0 != r)
	{
		wprintf(L"wcscat_s() failed %ld", r);
	}
	
	wprintf(L"%s\n%lld", buf, wcslen(buf));
	
	wprintf(L"%s\n", L"�����ַ�");
	return 0;
}