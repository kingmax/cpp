﻿#include "pch.h"
#include "LoadThis.h"
#include "KillProcessByName.h"

//如果当前目录下存在名为VR3的文件,直接返回true
bool IsVRay3()
{
	fs::path cd = fs::current_path();
	cd += L"\\VR3";
	if (fs::exists(cd))
	{
		cout << "exists VR3 file -> " << cd << endl;
		return true;
	}

	// C:\dps\2012\V_Ray_Adv_3_20_02
	//string p = fs::current_path().string();
	//string::size_type pos = p.rfind("V_Ray_Adv_");
	//if (pos != string::npos)
	//{
	//	string vray_version = p.substr(pos);
	//	cout << "vray_version is " << vray_version << endl;
	//	for (auto &c : vray_version)
	//	{
	//		// cout << c << ',';
	//		// first digit is 3
	//		if (isdigit(c) && c == '3')
	//		{
	//			return true;
	//		}
	//	}
	//}

	return false;
}

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

void CopyPluginIni(const WCHAR *relativeDirName_3dsMaxVersion)
{
	fs::path src = fs::current_path();
	src += L"\\";
	src += relativeDirName_3dsMaxVersion;
	src += L"\\plugin.ini";

	fs::path dst(R"(C:\Program Files\Autodesk\)");
	dst += relativeDirName_3dsMaxVersion;
	if (!fs::exists(dst))
	{
		fs::create_directories(dst);
	}
	dst += L"\\plugin.ini";

	if (fs::exists(src))
	{
		fs::copy(src, dst, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
	}
	cout << src << " -> " << dst << endl;
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

void ClearVray_15to24_2012()
{
	system(R"(@rd / s / q "C:\Program Files\Autodesk\3ds Max 2012\plugins\vrayplugins" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\plugins\vray*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\plugins\vrender*.*" 1>NUL 2>NUL)");

	system(R"(@rd / s / q "C:\Program Files\Autodesk\3ds Max 2012\scripts\V-Ray" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\scripts\startup\vray*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\scripts\startup\vrscene*.*" 1>NUL 2>NUL)");

	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\cgauth*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\dte_wrapper*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\glslang*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\glvm*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\HairVrPrims2012*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\libmmd*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\svml_dispmd*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\vray*.*" 1>NUL 2>NUL)");
	system(R"(@del / f / s / q "C:\Program Files\Autodesk\3ds Max 2012\vrcompilerbackend_msl12*.*" 1>NUL 2>NUL)");

	system(R"(@rd / s / q "C:\Program Files\Chaos Group\V-Ray" 1>NUL 2>NUL)");
}

void LoadThis2012_1_2()
{
	//VRay1.5~2.5 (<VRay3.x)
	/*
	@echo %~dpn0
	@taskkill /f /im 3dsmax.exe 1>NUL 2>NUL

	@rd /s /q "C:\Program Files\Autodesk\3ds Max 2012\plugins\vrayplugins" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\plugins\vray*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\plugins\vrender*.*" 1>NUL 2>NUL

	@rd /s /q "C:\Program Files\Autodesk\3ds Max 2012\scripts\V-Ray" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\scripts\startup\vray*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\scripts\startup\vrscene*.*" 1>NUL 2>NUL

	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\cgauth*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\dte_wrapper*.*" 1>NUL 2>NUL
	rem V_Ray_Adv_2_40_03
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\glslang*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\glvm*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\HairVrPrims2012*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\libmmd*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\svml_dispmd*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\vray*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\vrcompilerbackend_msl12*.*" 1>NUL 2>NUL

	@rd /s /q "C:\Program Files\Chaos Group\V-Ray" 1>NUL 2>NUL

	@xcopy "%~dp03ds Max 2012" "C:\Program Files\Autodesk\3ds Max 2012" /S /Y /I 1>NUL 2>NUL
	@xcopy "%~dp0V-Ray" "C:\Program Files\Chaos Group\V-Ray" /S /Y /I 1>NUL 2>NUL

	@"C:\Program Files\Autodesk\3ds Max 2012\3dsmax.exe"
	*/

	ClearVray_15to24_2012();

	CopyDirTo(L"3ds Max 2012", fs::path(LR"(C:\Program Files\Autodesk\3ds Max 2012)"));
	CopyDirTo(L"V-Ray", fs::path(LR"(C:\Program Files\Chaos Group\V-Ray)"));
}

// maxFolder = 3ds Max 2012
void SetEnv4VRay3_2012(string maxFolder, string vrFolder/*="V-Ray"*/)
{
	string _3dsMax = fs::path(fs::current_path() / maxFolder).string();
	string vray = fs::path(fs::current_path() / vrFolder).string();

	string cmd = "@SETX PATH \"" + _3dsMax + ";" + vray + "\\RT for " + maxFolder + " for x64\\bin;\"" + " 1>NUL 2>NUL";
	//cout << cmd << endl;
	system(cmd.c_str());
	cmd = "@SETX VRAY32_RT_FOR_3DSMAX2012_MAIN_x64 \"" + vray + "\\RT for " + maxFolder + " for x64\\bin;\"" + " 1>NUL 2>NUL";
	//cout << cmd << endl;
	system(cmd.c_str());
	cmd = "@SETX VRAY32_RT_FOR_3DSMAX2012_PLUGINS_x64 \"" + vray + "\\RT for " + maxFolder + " for x64\\bin\\plugins;\"" + " 1>NUL 2>NUL";
	//cout << cmd << endl;
	system(cmd.c_str());
	cmd = "@SETX VRAY_OSL_PATH_3DSMAX2012_x64 \"" + vray + "\\3dsmax 2012 for x64\\opensl\" 1> NUL 2> NUL";
	//cout << cmd << endl;
	system(cmd.c_str());

	/*system(R"(@SETX PATH "%~dp03ds Max 2012;%~dp0V-Ray\RT for 3ds Max 2012 for x64\bin;" 1>NUL 2>NUL)");
	system(R"(@SETX VRAY32_RT_FOR_3DSMAX2012_MAIN_x64 "%~dp0V-Ray\RT for 3ds Max 2012 for x64\bin" 1>NUL 2>NUL)");
	system(R"(@SETX VRAY32_RT_FOR_3DSMAX2012_PLUGINS_x64 "%~dp0V-Ray\RT for 3ds Max 2012 for x64\bin\plugins" 1>NUL 2>NUL)");
	system(R"(@SETX VRAY_OSL_PATH_3DSMAX2012_x64 "%~dp0V-Ray\3dsmax 2012 for x64\opensl" 1>NUL 2>NUL)");*/
}

void LoadThis2012_VR3()
{
	/*
	@echo SetEnv.bat for VRay3~4 %~dpn0
	@taskkill /f /im 3dsmax.exe 1>NUL 2>NUL

	@rd /s /q "C:\Program Files\Autodesk\3ds Max 2012\plugins\vrayplugins" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\plugins\vray*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\plugins\vrender*.*" 1>NUL 2>NUL

	@rd /s /q "C:\Program Files\Autodesk\3ds Max 2012\scripts\V-Ray" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\scripts\startup\vray*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\scripts\startup\vrscene*.*" 1>NUL 2>NUL

	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\cgauth*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\dte_wrapper*.*" 1>NUL 2>NUL
	rem V_Ray_Adv_2_40_03
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\glslang*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\glvm*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\HairVrPrims2010*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\libmmd*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\svml_dispmd*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\vray*.*" 1>NUL 2>NUL
	@del /f /s /q "C:\Program Files\Autodesk\3ds Max 2012\vrcompilerbackend_msl12*.*" 1>NUL 2>NUL

	@rd /s /q "C:\Program Files\Chaos Group\V-Ray" 1>NUL 2>NUL

	@SETX PATH "%~dp03ds Max 2012;%~dp0V-Ray\RT for 3ds Max 2012 for x64\bin;" 1>NUL 2>NUL
	@SETX VRAY32_RT_FOR_3DSMAX2012_MAIN_x64 "%~dp0V-Ray\RT for 3ds Max 2012 for x64\bin" 1>NUL 2>NUL
	@SETX VRAY32_RT_FOR_3DSMAX2012_PLUGINS_x64 "%~dp0V-Ray\RT for 3ds Max 2012 for x64\bin\plugins" 1>NUL 2>NUL
	@SETX VRAY_OSL_PATH_3DSMAX2012_x64 "%~dp0V-Ray\3dsmax 2012 for x64\opensl" 1>NUL 2>NUL


	@copy /Y "%~dp03ds Max 2012\plugin.ini" "C:\Program Files\Autodesk\3ds Max 2012\plugin.ini" 1>NUL 2>NUL

	@rem move to LoadThis.bat :: call SetEnv.bat first, then run 3dsmax.exe
	@rem "C:\Program Files\Autodesk\3ds Max 2012\3dsmax.exe"
	*/

	ClearVray_15to24_2012();

	/*system(R"(@SETX PATH "%~dp03ds Max 2012;%~dp0V-Ray\RT for 3ds Max 2012 for x64\bin;" 1>NUL 2>NUL)");
	system(R"(@SETX VRAY32_RT_FOR_3DSMAX2012_MAIN_x64 "%~dp0V-Ray\RT for 3ds Max 2012 for x64\bin" 1>NUL 2>NUL)");
	system(R"(@SETX VRAY32_RT_FOR_3DSMAX2012_PLUGINS_x64 "%~dp0V-Ray\RT for 3ds Max 2012 for x64\bin\plugins" 1>NUL 2>NUL)");
	system(R"(@SETX VRAY_OSL_PATH_3DSMAX2012_x64 "%~dp0V-Ray\3dsmax 2012 for x64\opensl" 1>NUL 2>NUL)");*/

	SetEnv4VRay3_2012("3ds Max 2012");

	//system(R"(@copy /Y "C:\dps\2012\V_Ray_Adv_3_20_02\3ds Max 2012\plugin.ini" "C:\Program Files\Autodesk\3ds Max 2012\plugin.ini" 1>NUL 2>NUL)");
	CopyPluginIni(L"3ds Max 2012");
}

void LoadThis2012()
{
	if (IsVRay3())
	{
		cout << "LoadThis2012 for VRay3.x" << endl;
		LoadThis2012_VR3();
	}
	else
	{
		LoadThis2012_1_2();
	}
}

void LoadThis2013() {}
void LoadThis2014() {}
void LoadThis2015() {}
void LoadThis2016() {}
void LoadThis2017() {}
void LoadThis2018() {}
void LoadThis2019() {}
void LoadThis2020() {}
