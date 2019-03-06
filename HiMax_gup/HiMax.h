#pragma once

#include "resource.h"
#include <istdplug.h>
#include <iparamb2.h>
#include <iparamm2.h>
#include <maxtypes.h>	// HINSTANCE (windows.h?)
#include <plugin.h>		// ClassDesc
#include <plugapi.h>	// VERSION_3DSMAX

#include <gup.h>

// from 3dsmaxsdk_preinclude.h
// useful for #pragma message
#define STRING2(x) #x
#define STRING(x) STRING2(x)
#define TODO(x) __FILE__ "(" STRING(__LINE__) "): TODO: "x

extern TCHAR* GetString(int id); // Define in DllEntry.cpp
extern HINSTANCE hInstance;		 // Define in DllEntry.cpp, HiMaxClassDesc::HInstance used
#define HiMax_CLASS_ID Class_ID(0x47004666, 0x6773197d); // HiMaxClassDesc::ClassID used

class HiMax : public GUP
{
public:
	HiMax() = default;
	~HiMax() = default;

	virtual DWORD Start();
	virtual void Stop();
	virtual void DeleteThis();

	// Singleton access
	static HiMax* GetInstance();
};
