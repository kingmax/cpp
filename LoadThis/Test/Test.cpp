// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <Windows.h>

using namespace std;
namespace fs = std::filesystem;

const string path_env = R"(C:\ProgramData\Oracle\Java\javapath;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Python27;C:\Program Files\Common Files\Autodesk Shared\;C:\Program Files (x86)\Autodesk\Backburner\;)";

bool SetPermanentEnvironmentVariable(LPCTSTR envName, LPCTSTR envVal)
{
	HKEY hKey;
	LPCTSTR keyPath = TEXT("System\\CurrentControlSet\\Control\\Session Manager\\Environment");
	LSTATUS lOpenStatus = RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_ALL_ACCESS, &hKey);
	if (lOpenStatus == ERROR_SUCCESS)
	{
		LSTATUS lSetStatus = RegSetValueEx(hKey, envName, 0, REG_SZ, (LPBYTE)envVal, strlen(envVal) + 1);
		RegCloseKey(hKey);

		if (lSetStatus == ERROR_SUCCESS)
		{
			SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)"Environment", SMTO_BLOCK, 500, NULL);
			return true;
		}
	}

	return false;
}

bool IsVRay4()
{
	fs::path cd = fs::current_path();
	const string vr = cd.filename().string();
	if (vr.find("V_Ray_Next") == 0 || vr.find("V_Ray_Adv_4") == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	fs::path cd = fs::current_path();
	string path = (cd / "3ds Max 2013;").string();
	if (IsVRay4())
	{
		path += (cd / "V-Ray\\3ds Max 2013\\bin;").string();
	}
	else
	{
		path += (cd / "V-Ray\\RT for 3ds Max 2013 for x64\\bin;").string();
	}
	path = path_env + path;

	cout << path << endl;
	cout << "----------" << endl;
	cout << TEXT(path.c_str()) << endl;

	//return 0;

	if (SetPermanentEnvironmentVariable(TEXT("PATH"), TEXT(path.c_str())))
	{
		cout << "set env ok" << endl;
	}
	else
	{
		cout << "set env error" << endl;
	}

	/*wstring ws;
	ws.assign(path.begin(), path.end());

	bool isEnvDone = SetPermanentEnvironmentVariable(TEXT("PATH"), ws.c_str());

	wcout << ws << endl;
	if (isEnvDone)
	{
		cout << "env OK" << endl;
	}
	else
	{
		cout << "env Error" << endl;
	}*/

	string plugin = (cd / "3ds Max 2013\\en-US\\plugin.ini").string();
	string plDest = R"(C:\Program Files\Autodesk\3ds Max 2013\en-US\plugin.ini)";
	fs::copy(plugin, plDest, fs::copy_options::overwrite_existing);
}
