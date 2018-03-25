#include "Blob.h"
#include <iostream>
using namespace std;

int main()
{
	//cl /EHsc Blob_test.cpp Blob.cpp
	Blob b({"hi", "Jason"});
	cout << b.front() << ' ' << b.back() << endl;
	
	Blob c = b;
	cout << "c is empty? " << (c.empty() ? "true" : "false") << endl;
	cout << c.size() << endl;
	c.push_back("welcome");
	cout << b.size() << endl;
	cout << b.back() << endl;
	b.pop_back();
	cout << c.size() << endl;
	cout << c.back() << endl;
	
	Blob d{"hi", "initializer_list"};
	cout << d.size() << endl;
	
	Blob e = {"hi", "no explicit constructor"}; //not explicit, so can do this style
	cout << e.back() << endl;
	
	const Blob *p = new const Blob({"hi", "const"});
	cout << p->size() << endl;
	//p->push_back("ok"); //error
	cout << p->front() << ' ' << p->back() << endl; //call const member methods
	delete p;
	p = nullptr;
	
	//if alloc memory failed, don't throw std::bad_alloc exception
	const Blob *p2 = new (nothrow) const Blob();
	cout << p2 << endl; //memory address
	delete p2;
	p2 = nullptr;
	
	return 0;
}