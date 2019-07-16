#include "pch.h"
#include "KillProcessByName.h"

void killProcessByName(const WCHAR *filename)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(pEntry);
	BOOL hRes = Process32First(hSnapShot, &pEntry);
	while (hRes)
	{
		if (wcscmp(pEntry.szExeFile, filename) == 0)
		{
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
				(DWORD)pEntry.th32ProcessID);
			if (hProcess != NULL)
			{
				TerminateProcess(hProcess, 9);
				CloseHandle(hProcess);
			}
		}
		hRes = Process32Next(hSnapShot, &pEntry);
	}
	CloseHandle(hSnapShot);
}


//int main(int argc, char *argv[])
//{
//	std::string name = "";
//	if (argc > 1)
//	{
//		name = std::string(argv[1]);
//		std::cout << name << std::endl;
//
//		killProcessByName(name.c_str());
//	}
//	else
//	{
//		std::cout << "usage:: killProcess processName" << std::endl;
//	}
//
//	return 0;
//}