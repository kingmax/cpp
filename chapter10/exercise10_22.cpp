#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

int main()
{
	const vector<string> vs = {"hi", "jason", "hello", "world", "here"};
	
	auto check_size_4 = bind(check_size, _1, 4);
	unsigned cnt = 0;
	
	auto wc = find_if(vs.cbegin(), vs.cend(), check_size_4);
	cout << *wc << endl;
	
	return 0;
}