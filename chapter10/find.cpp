#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int val = 42;
	vector<int> vec = {1,2,3,4,5};
	auto result = find(vec.cbegin(), vec.cend(), val);
	cout << "find the value " << val
		 << (result == vec.cend() ? " is not present" : " is present") << endl;
	
	list<string> lst = {"hello", "hi", "world", "jason"};
	string s = "a value";
	auto result2 = find(lst.cbegin(), lst.cend(), s);
	cout << ( result2 == lst.cend() ? "not found" : "found" ) << endl;
	
	int ia[] = {27, 210, 12, 47, 109, 83};
	int val2 = 83;
	int *p = find(begin(ia), end(ia), val2);
	cout << p << ' ' << *p << endl;
	cout << (val2 == *p ? "found " : "not found ") << val2 << endl;
	
	auto result3 = find(ia + 1, ia + 4, val);
	cout << (result3 == end(ia)) << endl;
	
	return 0;
}