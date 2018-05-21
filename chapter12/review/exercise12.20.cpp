#include <iostream>
#include <fstream>
#include <string>
#include "exercise12.19.h"
using namespace std;

int main()
{
	ifstream ifs("exercise12.19.h");
	StrBlob blob;
	for(string txt; getline(ifs, txt);)
		blob.push_back(txt);
	
	for(StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
		cout << pbeg.deref() << endl;
	
	return 0;
}