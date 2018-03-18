#include <iostream>
#include "StrBlob.h"
//#include "StrBlobPtr.h"	//A.h always included B.h
using namespace std;

int main()
{
	StrBlob s = {"hi", "jason"};
	auto p = s.begin();
	cout << p.deref() << endl;
	
	return 0;
}