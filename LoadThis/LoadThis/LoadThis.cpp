#include "pch.h"
#include "LoadThis.h"
#include "KillProcessByName.h"

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
		//system(R"(@taskkill / f / im 3dsmax.exe)");
		killProcessByName(L"3dsmax.exe");
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
	system(R"(@rd / s / q "C:\Program Files\Autodesk\3ds Max 2010\plugins\vrayplugins" 1>NUL 2>NUL)");
	//fs::remove_all(LR"(C:\Program Files\Autodesk\3ds Max 2010\plugins\vrayplugins)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\plugins\vray*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\plugins\vrender*.*" 1>NUL 2>NUL)");
	//DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\plugins\vray*.*)");
	//DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\plugins\vrender*.*)");

	system(R"(@rd / s / q "C:\Program Files\Autodesk\3ds Max 2010\scripts\V-Ray" 1>NUL 2>NUL)");
	//fs::remove_all(LR"(C:\Program Files\Autodesk\3ds Max 2010\scripts\V-Ray)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\scripts\startup\vray*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\scripts\startup\vrscene*.*" 1>NUL 2>NUL)");
	//DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\scripts\startup\vray*.*)");
	//DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\scripts\startup\vrscene*.*)");

	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\vray*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\dte_wrapper*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\HairVrPrims2010*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\libmmd*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\cgauth*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2010\svml_dispmd*.*" 1>NUL 2>NUL)");
	/*DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\vray*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\dte_wrapper*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\HairVrPrims2010*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\libmmd*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\cgauth*.*)");
	DeleteFilesByPattern(LR"(C:\Program Files\Autodesk\3ds Max 2010\svml_dispmd*.*)");*/

	system(R"(@rd / s / q "C:\Program Files\Chaos Group\V-Ray" 1>NUL 2>NUL)");
	//fs::remove_all(LR"(C:\Program Files\Chaos Group\V-Ray)");

	//system(R"(@xcopy "%~dp03ds Max 2010" "C:\Program Files\Autodesk\3ds Max 2010" / S / Y / I)");
	CopyDirTo(L"3ds Max 2010", fs::path(LR"(C:\Program Files\Autodesk\3ds Max 2010)"));
	//system(R"(@xcopy "%~dp0V-Ray" "C:\Program Files\Chaos Group\V-Ray" / S / Y / I)");
	CopyDirTo(L"V-Ray", fs::path(LR"(C:\Program Files\Chaos Group\V-Ray)"));
	//cout << __FILE__ << endl;
}

void LoadThis2011()
{
	/*
	@echo %~dpn0
	@taskkill /f /im 3dsmax.exe 1>NUL 2>NUL

	@rd /s /q "C:\Program Files\Autodesk\3ds Max 2011\plugins\vrayplugins" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2011\plugins\vray*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2011\plugins\vrender*.*" 1>NUL 2>NUL

	@rd /s /q "C:\Program Files\Autodesk\3ds Max 2011\scripts\V-Ray" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2011\scripts\startup\vray*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2011\scripts\startup\vrscene*.*" 1>NUL 2>NUL

	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2011\vray*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2011\dte_wrapper*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2011\HairVrPrims2010*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2011\libmmd*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2011\cgauth*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2011\svml_dispmd*.*" 1>NUL 2>NUL

	@xcopy "%~dp03ds Max 2011" "C:\Program Files\Autodesk\3ds Max 2011" /S /Y /I 1>NUL 2>NUL

	@rd /s /q "C:\Program Files\Chaos Group\V-Ray" 1>NUL 2>NUL
	@xcopy "%~dp0V-Ray" "C:\Program Files\Chaos Group\V-Ray" /S /Y /I 1>NUL 2>NUL

	@"C:\Program Files\Autodesk\3ds Max 2011\3dsmax.exe"
	*/

	system(R"(@rd / s / q "C:\Program Files\Autodesk\3ds Max 2011\plugins\vrayplugins" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\plugins\vray*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\plugins\vrender*.*" 1>NUL 2>NUL)");

	system(R"(@rd / s / q "C:\Program Files\Autodesk\3ds Max 2011\scripts\V-Ray" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\scripts\startup\vray*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\scripts\startup\vrscene*.*" 1>NUL 2>NUL)");

	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\cgauth*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\dte_wrapper*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\glslang*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\glvm*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\HairVrPrims2011*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\libmmd*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\svml_dispmd*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\vray*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2011\vrcompilerbackend_msl11a*.*" 1>NUL 2>NUL)");
	
	system(R"(@rd / s / q "C:\Program Files\Chaos Group\V-Ray" 1>NUL 2>NUL)");

	CopyDirTo(L"3ds Max 2011", fs::path(LR"(C:\Program Files\Autodesk\3ds Max 2011)"));
	CopyDirTo(L"V-Ray", fs::path(LR"(C:\Program Files\Chaos Group\V-Ray)"));
}

void LoadThis2012() {}
void LoadThis2013() {}
void LoadThis2014() {}
void LoadThis2015() {}
void LoadThis2016() {}
void LoadThis2017() {}
void LoadThis2018() {}
void LoadThis2019() {}
void LoadThis2020() {}
