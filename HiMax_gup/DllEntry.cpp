#include "HiMax.h"
#include "HiMaxClassDesc.h"

HINSTANCE hInstance = 0;

////////////////////////////////////////// helper
static HiMaxClassDesc hiMaxDesc;

ClassDesc2* GetHiMaxDesc()
{
	return &hiMaxDesc;
}

TCHAR* GetString(int id)
{
	static TCHAR buf[256];
	if (hInstance)
	{
		return LoadString(hInstance, id, buf, sizeof(buf)) ? buf : NULL;
	}
	return NULL;
}


////////////////////////////////////////// dll entry point
BOOL WINAPI DllMain(HINSTANCE hinstDLL, ULONG fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		hInstance = hinstDLL;
		DisableThreadLibraryCalls(hInstance);
	}
	return TRUE;
}


////////////////////////////////////////// required functions
__declspec(dllexport) const TCHAR* LibDescription()		//1
{
	return GetString(IDS_LIBDESCRIPTION);
}

__declspec(dllexport) int LibNumberClasses()			//2
{
	return 1;
}

__declspec(dllexport) ClassDesc* LibClassDesc(int i)	//3
{
	switch (i)
	{
	case 0:
		return GetHiMaxDesc();
	default:
		return 0;
	}
}

__declspec(dllexport) ULONG LibVersion()				//4
{
	return VERSION_3DSMAX;
}

__declspec(dllexport) ULONG CanAutoDefer()				//5
{
	return 1;
}

__declspec(dllexport) int LibInitialize()				//6
{
	#pragma message(TODO("Perform initialization here."))
	return TRUE;
}

__declspec(dllexport) int LibShutdown()					//7
{
	#pragma message(TODO("Perform un-initialization here."))
	return TRUE;
}