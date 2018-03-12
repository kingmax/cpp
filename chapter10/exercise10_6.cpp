#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main()
{
	vector<int> vi(10, 100);
	for(const auto &i : vi)
		cout << i << ' ';
	cout << endl;
	
	fill_n(vi.begin(), vi.size(), 0);
	for(const auto &i : vi)
		cout << i << ' ';
	cout << endl;
	
	//exercise10.7
	vector<int> vec;
	list<int> lst;
	int i;
	while(cin >> i)
		lst.push_back(i);
	//copy(lst.cbegin(), lst.cend(), vec.begin()); //error vec.size==0!
	vec.resize(lst.size());
	copy(lst.cbegin(), lst.cend(), vec.begin());
	for(const auto &i : vec)
		cout << i << ' ';
	cout << endl;
	
	//vec.reserve(10); //warn
	vec.resize(10);
	fill_n(vec.begin(), 10, 0);
	for(const auto &i : vec)
		cout << i << ' ';
	cout << endl;
	
	auto it = back_inserter(vec);
	*it = 8888;
	cout << vec.size() << endl;
	for(const auto &i : vec)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}