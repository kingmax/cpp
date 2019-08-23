#include <Windows.h>
#include <cstdlib>
#include <iostream>
using namespace std;

//错误	C4996	'getenv': This function or variable may be unsafe.Consider using _dupenv_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.get_set_env	d : \git\cpp\get_set_env\get_set_env\main.cpp	8
#pragma warning(disable:4996)

// https://stackoverflow.com/questions/17258029/c-setenv-undefined-identifier-in-visual-studio
int setenv(const char *name, const char *value, int overwrite)
{
	int errcode = 0;
	if (!overwrite) {
		size_t envsize = 0;
		errcode = getenv_s(&envsize, NULL, 0, name);
		if (errcode || envsize) return errcode;
	}
	return _putenv_s(name, value);
}

// https://stackoverflow.com/questions/5246046/how-to-add-environment-variable-in-c
bool SetPermanentEnvironmentVariable(LPCTSTR value, LPCTSTR data)
{
	HKEY hKey;
	LPCTSTR keyPath = TEXT("System\\CurrentControlSet\\Control\\Session Manager\\Environment");
	LSTATUS lOpenStatus = RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_ALL_ACCESS, &hKey);
	if (lOpenStatus == ERROR_SUCCESS)
	{
		LSTATUS lSetStatus = RegSetValueEx(hKey, value, 0, REG_SZ, (LPBYTE)data, strlen(data) + 1);
		RegCloseKey(hKey);

		if (lSetStatus == ERROR_SUCCESS)
		{
			SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)"Environment", SMTO_BLOCK, 100, NULL);
			return true;
		}
	}

	return false;
}

int main()
{
	const char* env = "PYTHONPATH";
	char* val = getenv(env);

	if (val != NULL)
	{
		cout << env << " = " << val << endl;
	}

	//cout << setenv("mytest", "TST", 0) << endl;
	LPCTSTR envVar = TEXT("MY_ENV");
	LPCTSTR envVal = TEXT("MY_VAL");

	//HKEY hKey;
	//LPCTSTR envKey = TEXT("SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment");
	//if (ERROR_SUCCESS != RegOpenKeyEx(HKEY_LOCAL_MACHINE, envKey, 0, KEY_ALL_ACCESS, &hKey));
	//{
	//	cerr << "访问注册表出错！\n请使用管理员帐户执行本程序！" << endl;
	//	return -1;
	//}


	//LSTATUS lSetStatus = RegSetValueEx(hKey, envVar, 0, REG_SZ, (LPBYTE)envVal, strlen(envVal) + 1);
	//RegCloseKey(hKey);

	//if (lSetStatus == ERROR_SUCCESS)
	//{
	//	SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)"Environment", SMTO_BLOCK, 100, NULL);
	//}

	if (SetPermanentEnvironmentVariable(envVar, envVal))
	{
		cout << "set env MY_ENV=MY_VAL ok" << endl;
	}
	else
	{
		cout << "set env MY_ENV=MY_VAL failed" << endl;
	}

	
	

	system("pause");
	return 0;
}