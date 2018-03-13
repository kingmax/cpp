#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void absolute(vector<int> &vi)
{
	transform(vi.begin(), vi.end(), vi.begin(), [](int &x){return x < 0 ? -x : x;});
}

int main()
{
	vector<int> vi = {1, -1, -2, 3};
	for_each(vi.cbegin(), vi.cend(), [](const int &i){cout << i << ' ';});
	cout << endl;
	
	absolute(vi);
	for(const auto &i : vi)
		cout << i << ' ';
	cout << endl;
	
	transform(  vi.begin(), vi.end(), vi.begin(), 
				[](int &i) -> int 
				{ if(i < 0) return i; else return -i; }
			 );
			 
	for(const auto &i : vi)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}