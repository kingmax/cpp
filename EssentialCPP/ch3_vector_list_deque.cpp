#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
using namespace std;

int main()
{
	//1.empty container
	list<string> slist;
	vector<int> ivec;
	
	//2.init all element to default value
	list<int> ilist(1024); 
	vector<string> svec(32);
	for(const auto &s : svec)
		cout << s << endl;
	
	//3.init value and size
	vector<int> vi(10, -1);
	list<string> ls(16, "unassigned");
	
	//4.a pair iterator, range(beg, end)
	int ia[3] = {1,2,3};
	vector<int> fib(ia, ia+3);
	
	//5.from another container
	list<string> sl{"a", "b"};
	list<string> sl2(sl);
	
	deque<int> a_line;
	int ival;
	while(cin >> ival)
	{
		a_line.push_back(ival);
		int curr_value = a_line.front();
		a_line.pop_front();
	}
	
	return 0;
}