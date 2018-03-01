#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

forward_list<string> &append(forward_list<string> &flst, const string &wa, const string &wb)
{
	auto prev = flst.cbefore_begin();
	auto curr = flst.cbegin();
	auto last = flst.cend();
	while(curr != last)
	{
		if(*curr == wa)
		{
			prev = curr;
			curr = flst.insert_after(prev, wb);
			return flst;
		}
		else
		{
			prev = curr;
			++curr;
		}
	}
	
	flst.insert_after(prev, wb);

	return flst;
}

int main()
{
	forward_list<string> flst = {"hi", "jason", "welcom"};
	
	append(flst, "jason", "lee");
	for(const auto &s : flst)
		cout << s << ' ';
	cout << endl;
	
	append(flst, "here", "there");
	for(const auto &s : flst)
		cout << s << ' ';
	cout << endl;
	
	append(flst, "hi", "hey");
	for(const auto &s : flst)
		cout << s << ' ';
	cout << endl;
	
	return 0;
}