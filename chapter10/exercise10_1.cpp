#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main()
{
	vector<int> vi;
	int x;
	while(cin >> x)
	{
		vi.push_back(x);
	}
	for(const auto &i : vi)
		cout << i << ' ';
	cout << endl;
	
	int n = 8;
	int cnt = count(vi.cbegin(), vi.cend(), n);
	cout << n << " in vector's count: " << cnt << endl;
	
	
	/* cout << "enter some word now" << endl;
	list<string> lst;
	string w;
	while(cin >> w && w != "q")
		lst.push_front(w);
	
	for(const auto &w : lst)
		cout << w << ' ';
	cout << endl;
	
	string word = "jason";
	cout << word << " in list's count: " << count(lst.cbegin(), lst.cend(), word) << endl; */
	
	return 0;
}