#pragma once

#include "HiMax.h"

class HiMaxClassDesc : public ClassDesc2
{
public:
	virtual int IsPublic();
	virtual void* Create(BOOL loading = FALSE);
	virtual const TCHAR* ClassName();
	virtual SClass_ID SuperClassID();
	virtual Class_ID ClassID();
	virtual const TCHAR* Category();
	virtual const TCHAR* InternalName();
	virtual HINSTANCE HInstance();
};