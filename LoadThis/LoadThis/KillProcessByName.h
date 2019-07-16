#pragma once
#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string>
#include <iostream>

void killProcessByName(const WCHAR*);