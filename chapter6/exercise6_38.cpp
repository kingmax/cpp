#include <iostream>
#include <string>
#include <vector>
using namespace std;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

int (&arrRef(int i))[5]
{
	return (i % 2) ? odd : even;
}

int main()
{
	int (&ref)[5] = arrRef(0);
	for(auto i : ref)
		cout << i << ' ';
	cout << endl;
	
	for(auto i : arrRef(1))
		cout << i << ' ';
	cout << endl;
	
	return 0;
}