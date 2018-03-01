#include <iostream>
#include <string>
#include <deque>
#include <list>
using namespace std;

int main()
{
	string s;
	deque<string> ds;
	list<string> ls;
	while(cin >> s && s != "q")
	{
		//ds.push_back(s);
		ds.push_front(s);
		ls.push_back(s);
	}
	
	cout << "\nYour input in deque:" << endl;
	for(auto beg = ds.cbegin(); beg != ds.cend(); ++beg)
		cout << *beg << ' ';
	cout << endl;
	
	/* list<string> ls;
	while(cin >> s && s != "q")
		ls.push_back(s); */
	cout << "\nYour input in list:" << endl;
	for(auto beg = ls.cbegin(); beg != ls.cend(); ++beg)
		cout << *beg << ' ';
	cout << endl;
	
	return 0;
}