#include <iostream>
#include <string>
#include <vector>
using namespace std;

string (*retArrPtr(string (*p)[10]))[10]
{
	return p;
}

typedef string tenStrs[10];
const tenStrs *fun(const tenStrs *ptr)
{
	return ptr;
}

using tenStrArr = string[10];
tenStrArr *fun2(tenStrArr *ptr)
{
	return ptr;
}

auto fun3(string (*arr)[10]) -> string (*)[10]
{
	return arr;
}

int iArr[10]={};
decltype(iArr) *fun4(int (*p)[10])
{
	return p;
}

int main()
{
	tenStrs ts;
	for(int i = 0; i != 10; ++i)
		ts[i] = to_string(i);
	for(auto s : ts)
		cout << s << ' ';
	cout << endl;
	
	cout << endl;
	const tenStrs ts2 = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
	const tenStrs *ptr = fun(&ts2);
	cout << ptr << ' ' << *ptr << endl; //ptr point to array, point to array[0] actually!
	for(auto x : *ptr)
		cout << x << ' ';
	cout << endl;
	for(int i = 0; i != 10; ++i)
		cout << (*ptr)[i] << ' ';
	cout << endl;
	
	cout << endl << ts2 << ' ' << &ts2[0] << endl;
	const tenStrs *p = &ts2;
	for(int i=0; i<10; ++i)
		//cout << *((*p)+i) << ' '; //ok
		cout << (*p)[i] << ' ';
	cout << endl;
	
	cout << "\n*fun2(&tenStrArr):" << endl;
	tenStrArr *p2 = fun2(&ts);
	for(auto &x : *p2)
		cout << x << ' ';
	cout << endl;
	
	cout << "\nauto *fun3(string(*arr)[10]) -> string (*)[10]" << endl;
	auto *p3 = fun3(&ts);
	for(auto &s : *p3)
		cout << s << ' ';
	cout << endl;
	
	cout << "\ndecltype(iArr) *fun4(int (*p)[10])" << endl;
	int (*p4)[10] = fun4(&iArr);
	for(auto &i : *p4)
		i *= ++i;
		//cout << i << ' ';
	int (*p5)[10] = fun4(&iArr);
	for(auto &i : *p5)
		cout << i << ' ';
	cout << endl;
	
	cout << "\nstring (*retArrPtr(string (*p)[10]))[10]" << endl;
	string (*p6)[10] = retArrPtr(&ts);
	for(int i = 0; i != 10; ++i)
		cout << (*p6)[i] << ' ';
	cout << endl;
	
	return 0;
}