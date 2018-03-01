#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec(25,10);
	
	cout << vec.size() << endl;
	for(const auto &i : vec)
		cout << i << ' ';
	cout << endl;
	
	vec.resize(100);
	cout << vec.size() << endl;
	for(const auto &i : vec)
		cout << i << ' ';
	cout << endl;
	
	vec.resize(10);
	cout << vec.size() << endl;
	for(const auto &i : vec)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}