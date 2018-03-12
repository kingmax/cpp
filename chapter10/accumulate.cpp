#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

string strtolower(const string s)
{
	string s1(s);
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	return s1;
}

int main()
{
	int i;
	vector<int> vi;
	while(cin >> i)
		vi.push_back(i);
	
	for(const auto &i : vi)
		cout << i << ' ';
	cout << endl;
	
	int sum = accumulate(vi.cbegin(), vi.cend(), 0);
	cout << "sum vector is: " << sum << endl;
	
	string up("ABCDEFGHI");
	cout << up << endl;
	string low = strtolower(up);
	cout << low << endl;
	
	return 0;
}