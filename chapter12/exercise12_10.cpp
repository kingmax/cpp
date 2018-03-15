#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
	shared_ptr<int> p(new int(1024));
	cout << *p << endl;
	
	cout << (p.unique() ? "p is unique shared_ptr" : "not unique ptr") << endl;
	cout << p << ' ' << &p << ' ' << p.get() << endl;
	
	auto q = p;
	cout << (p.unique() ? "p is unique shared_ptr" : "not unique ptr") << endl;
	
	if(!p.unique())
		p.reset(new int(2048));
	cout << *p << ' ' << *q << endl;
	
	auto ps1 = make_shared<string>("hi, jason"), ps2 = ps1;
	cout << ps1.use_count() << ' ' << ps2.use_count() << endl;
	
	if(!ps1.unique())
		ps1.reset(new string(*ps1));
	cout << ps1.use_count() << ' ' << ps2.use_count() << endl;
	*ps1 = "hello, jason";
	cout << *ps1 << ' ' << *ps2 << endl;
	
	return 0;
}