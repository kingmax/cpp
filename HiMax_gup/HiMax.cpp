#include "HiMax.h"

#include <iostream>
#include <fstream>
using namespace std;

DWORD HiMax::Start()
{
	cout << "HiMax::Start()" << endl;
	return GUPRESULT_KEEP;
}

void HiMax::Stop()
{
	cout << "HiMax::Stop()" << endl;
}

void HiMax::DeleteThis()
{
	
}

HiMax* HiMax::GetInstance()
{
	static HiMax theHiMax;
	return &theHiMax;
}

