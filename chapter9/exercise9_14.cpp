#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main()
{
	list<const char*> cstr = {"hi", "Jason"};
	for(const auto &c : cstr)
		cout << c << endl;
	cout << endl;
	
	vector<string> svec;
	
	svec.assign(cstr.cbegin(), cstr.cend());
	for(const auto &s : svec)
		cout << s << endl;
	cout << endl;
	
	cout << cstr.empty() << ' ' << cstr.size() << ' ' << cstr.max_size() << endl;
	
	return 0;
}