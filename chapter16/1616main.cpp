#include "vec.h"
#include <iostream>

using namespace std;

int main()
{
	Vec<int> v = {1,2,3};
	Vec<int> v2;
	
	v2 = v;
	cout << v2.capacity() << endl;
	
	v2.push_back(99);
	v2.resize(2, 2);
	
	for(auto t : v2)
		cout << t << ',';
	
	cout << endl << v2.capacity() << endl;
	
	return 0;
}