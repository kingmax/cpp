#include "HiMaxClassDesc.h"

int HiMaxClassDesc::IsPublic()
{
	return TRUE;
}

void* HiMaxClassDesc::Create(BOOL loading)
{
	return HiMax::GetInstance();
}

const TCHAR* HiMaxClassDesc::ClassName()
{
	return GetString(IDS_CLASS_NAME);
}

SClass_ID HiMaxClassDesc::SuperClassID()
{
	return GUP_CLASS_ID;
}

Class_ID HiMaxClassDesc::ClassID()
{
	return HiMax_CLASS_ID;
}

const TCHAR* HiMaxClassDesc::Category()
{
	return GetString(IDS_CATEGORY);
}

const TCHAR* HiMaxClassDesc::InternalName()
{
	return _T("HiMax");	// returns fixed parsable name (scripter-visible name)
}

HINSTANCE HiMaxClassDesc::HInstance()
{
	return hInstance;	// returns owning module handle
}
