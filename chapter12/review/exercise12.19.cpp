#include <iostream>
#include "exercise12.19.h"
using namespace std;

int main()
{
	StrBlob s({"hi", "jason"});
	s.push_back("ok");
	if(!s.empty())
		cout << s.size() << endl;
	
	return 0;
}