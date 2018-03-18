#include <iostream>
#include "strblob.h"	//only include A.h
//#include "strblobptr.h" 
using namespace std;

//cl /EHsc strblob_ptr_test.cpp strblob.cpp strblobptr.cpp

int main()
{
	StrBlob s = {"hi", "jason"};
	auto beg = s.begin();
	//cout << beg.deref() << endl;
	
	//cout << (s.end()).deref() << endl; //error, past end of
	
	while(beg != s.end()) //need operator !=
	{
		cout << beg.deref() << endl;
		beg.incr();
	}
	
	
	return 0;
}