#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

forward_list<string> &append(forward_list<string> &flst, const string &sa, const string &sb)
{
	auto prev = flst.cbefore_begin();
	auto curr = flst.cbegin();
	while(curr != flst.cend())
	{
		if(*curr == sa)
		{
			prev = curr;
			curr = flst.insert_after(prev, sb);
			return flst;
		}
		else
		{
			++prev;
			++curr;
		}
	}
	
	flst.insert_after(prev, sb);
	
	return flst;
}

int main()
{
	forward_list<string> flst = {"hi", "jason"};
	
	append(flst, "hi", "here,");
	for(const auto &s : flst)
		cout << s << ' ';
	cout << endl;
	
	append(flst, "haha", "welcome!");
	for(const auto &s : flst)
		cout << s << ' ';
	cout << endl;
	
	return 0;
}