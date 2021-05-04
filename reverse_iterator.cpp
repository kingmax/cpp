#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> v = {7, 5, 16, 8};
	v.push_back(25);
	
	for(int x : v)
		cout << x << ", ";
	cout << endl;
	
	vector<int>::reverse_iterator rit;
	for(rit = v.rbegin(); rit != v.rend(); ++rit)
		cout << *rit << ", ";
	cout << endl;
	
	return 0;
}