#include <iostream>
using namespace std;

int (*func(int i))[10]; //return ptr point to int[10]

auto func2(int i) -> int (*)[10]; //return ptr point to int[10]

int odd[] = {1,3,5,7,9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) *arrPtr(int i) //decltype return array, not ptr
{
	return (i % 2) ? &odd : &even; //return ptr point to int[]
}


int main()
{
	cout << odd << endl;
	cout << &odd << endl;
	cout << arrPtr(1) << endl;
	cout << endl;
	
	decltype(odd) *ptr = arrPtr(2);
	for(auto &i : *ptr)
		cout << i << ' ' << &i << endl;
	cout << endl;
	for(auto beg = begin(*ptr); beg != end(*ptr); ++beg)
		//cout << *beg << endl;
		*beg *= 10;
	cout << endl;
	for(const auto i : *ptr)
		cout << i << endl;
	cout << endl;
	
	return 0;
}