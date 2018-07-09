#include <iostream>
#include <algorithm>

#include "exercise12.19.h"
using namespace std;

int main()
{
	StrBlob s({"hi", "jason"});
	s.push_back("ok");
	if(!s.empty())
		cout << s.size() << endl;
	
	auto print = [](const string& str){ cout << " " << str; };
	//for_each(s.begin(), s.end(), print);
	for(auto beg = s.begin(), end = s.end(); beg != end; beg.incr())
	{
		cout << beg.deref() << endl;
	}
	
	return 0;
}