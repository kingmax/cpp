#pragma once
#include <iostream>
#include <string>
//cpp 17
#include <filesystem>

#include <cstdlib>
#include <process.h>

#include <Windows.h>
#include <fileapi.h>
#include <PathCch.h>
#include <shellapi.h>

using namespace std;
namespace fs = std::filesystem;

bool IsVRay3();

void DeleteFilesByPattern(const wchar_t *filenamePattern);
void CopyDirTo(const wchar_t *relativeDirName, const fs::path &destDir);

void Kill3dsMax();

void LoadThis2010();
void LoadThis2011();
void ClearVray_15to24_2012();
void LoadThis2012();
// maxFolder = 3ds Max 2012
void SetEnv4VRay3_2012(string maxFolder, string vrFolder = "V-Ray");
void LoadThis2012_VR3();

void LoadThis2013();
void LoadThis2014();
void LoadThis2015();
void LoadThis2016();
void LoadThis2017();
void LoadThis2018();
void LoadThis2019();
void LoadThis2020();

