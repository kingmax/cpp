#include <iostream>
#include <vector>
using namespace std;

int main()
{
	const int n = 10;
	int arr[n];
	for(int i = 0; i != n; ++i)
		arr[i] = i;
	for(int i : arr)
		cout << i << ' ';
	cout << endl;
	
	//copy to another array
	int a2[n] = {};
	for(int i=0; i!=n; ++i)
		a2[i] = arr[i];
	for(auto i : a2)
		cout << i << ' ';
	cout << endl;
	
	//vector
	vector<int> vi;
	for(int i=0; i<n; ++i)
		vi.push_back(i);
	for(auto i:vi)
		cout << i << ' ';
	cout << endl;
	
	vector<int> v2 = vi;
	for(int i : v2)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}