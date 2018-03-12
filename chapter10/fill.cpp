#include <iostream>
#include <algorithm>
#include <vector>

#include <iterator>
#include <string>

using namespace std;

int main()
{
	vector<int> vi;
	for(int i=0; i != 10; ++i)
		vi.push_back(i);
	for(const auto &i:vi)
		cout << i << ' ';
	cout << endl;
	
	fill(vi.begin(), vi.begin() + vi.size()/2, 100);
	for(const auto &i : vi)
		cout << i << ' ';
	cout << endl;
	
	//fill_n
	fill_n(vi.begin(), 2, 888);
	for(const auto &i : vi)
		cout << i << ' ';
	cout << endl;
	
	//back_inserter
	vector<int> vec;
	cout << vec.size() << endl;
	auto it = back_inserter(vec);
	*it = 100;
	cout << vec.size() << endl;
	
	//copy
	int a1[] = {0,1,2,3,4,5,6,7,8,9};
	int a2[sizeof(a1)/sizeof(*a1)];
	auto ret = copy(begin(a1), end(a1), a2);
	cout << ret << endl;
	for(int i=0; i<sizeof(a2)/sizeof(int); ++i)
		cout << a2[i] << ' ';
	cout << endl;
	
	//replace
	string s = "hello, Jason";
	replace(s.begin(), s.end(), 'h', 'H');
	cout << s << endl; //Hello, Jason
	
	replace(vi.begin(), vi.end(), 100, 42);
	for(const auto &i : vi)
		cout << i << ' '; //888 888 42 42 42 5 6 7 8 9
	cout << endl;
	
	replace_copy(vi.begin(), vi.end(), back_inserter(vi), 42, 100);
	for(const auto &i : vi)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}