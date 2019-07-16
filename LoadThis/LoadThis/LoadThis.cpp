// LoadThis.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
//cpp 17
#include <filesystem>

#include <cstdlib>
#include <process.h>

#include <Windows.h>
#include <fileapi.h>
#include <PathCch.h>

using namespace std;
namespace fs = std::filesystem;

void DeleteFilesByPattern(const wchar_t *filenamePattern)
{
	fs::path path(filenamePattern);

	WIN32_FIND_DATA fd;
	HANDLE hFind = FindFirstFile(filenamePattern, &fd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			fs::remove(fs::path(path.parent_path().wstring() + L"\\" + fd.cFileName));
		} while (FindNextFile(hFind, &fd));

		FindClose(hFind);
	}
}

//复制相对目录，如果目标目录不存在则创建
void CopyDirTo(const wchar_t *relativeDirName, const fs::path &destDir)
{
	fs::path src = fs::current_path();
	src += L"\\";
	src += relativeDirName;
	//cout << src << endl;
	if (!fs::exists(destDir))
	{
		fs::create_directories(destDir);
	}
	if (fs::exists(src) && fs::exists(destDir))
	{
		//cout << src << endl << destDir << endl;
		fs::copy(src, destDir, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
	}
}

void Kill3dsMax()
{
	try
	{
		system(R"(@taskkill / f / im 3dsmax.exe)");
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

void LoadThis2010()
{
	//bat for Max2010 VRay
	/*
		@taskkill /f /im 3dsmax.exe

		@rd /s /q "C:\Program Files\Autodesk\3ds Max 2010\plugins\vrayplugins"
		@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2010\plugins\vray*.*"
		@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2010\plugins\vrender*.*"

		@rd /s /q "C:\Program Files\Autodesk\3ds Max 2010\scripts\V-Ray"
		@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2010\scripts\startup\vray*.*"
		@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2010\scripts\startup\vrscene*.*"

		@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2010\vray*.*"
		@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2010\dte_wrapper*.*"
		@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2010\HairVrPrims2010*.*"
		@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2010\libmmd*.*"
		@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2010\cgauth*.*"
		@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2010\svml_dispmd*.*"

		@xcopy "%~dp03ds Max 2010" "C:\Program Files\Autodesk\3ds Max 2010" /S /Y /I

		@rd /s /q "C:\Program Files\Chaos Group\V-Ray"
		@xcopy "%~dp0V-Ray" "C:\Program Files\Chaos Group\V-Ray" /S /Y /I
	*/

	//cout << __LINE__ << endl;
	//system(R"(@rd / s / q "C:\Program Files\Autodesk\3ds Max 2010\plugins\vrayplugins")");
	fs::remove_all(LR"(C:\Program Files\Autodesk\3ds Max 2010\plugins\vrayplugins)");
	//system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\plugins\vray*.*")");
	//system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\plugins\vrender*.*")");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\plugins\vray*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\plugins\vrender*.*)");

	//system(R"(@rd / s / q "C:\Program Files\Autodesk\3ds Max 2010\scripts\V-Ray")");
	fs::remove_all(LR"(C:\Program Files\Autodesk\3ds Max 2010\scripts\V-Ray)");
	//system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\scripts\startup\vray*.*")");
	//system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\scripts\startup\vrscene*.*")");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\scripts\startup\vray*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\scripts\startup\vrscene*.*)");

	/*system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\vray*.*")");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\dte_wrapper*.*")");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\HairVrPrims2010*.*")");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\libmmd*.*")");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\cgauth*.*")");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\svml_dispmd*.*")");*/
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\vray*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\dte_wrapper*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\HairVrPrims2010*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\libmmd*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\cgauth*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\svml_dispmd*.*)");

	//system(R"(@rd / s / q "C:\Program Files\Chaos Group\V-Ray")");
	fs::remove_all(LR"(C:\Program Files\Chaos Group\V-Ray)");

	//system(R"(@xcopy "%~dp03ds Max 2010" "C:\Program Files\Autodesk\3ds Max 2010" / S / Y / I)");
	CopyDirTo(L"3ds Max 2010", fs::path(LR"(C:\Program Files\Autodesk\3ds Max 2010)"));
	//system(R"(@xcopy "%~dp0V-Ray" "C:\Program Files\Chaos Group\V-Ray" / S / Y / I)");
	CopyDirTo(L"V-Ray", fs::path(LR"(C:\Program Files\Chaos Group\V-Ray)"));
	//cout << __FILE__ << endl;
}

void usage()
{
	cout << "LoadThis 3dsMaxVersion (2010..2020)" << endl;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		usage();
		return -1;
	}

	//Kill3dsMax();

	string ver(argv[1]);
	string msg = "LoadThis for 3dsMax " + ver;
	cout << msg << endl;

	if (ver == "2010")
	{
		try
		{
			LoadThis2010();
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}

	cout << "DONE!" << endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
