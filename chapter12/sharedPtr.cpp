#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

int main()
{
	shared_ptr<string> p1;		//null smart pointer
	shared_ptr<vector<int>> p2; //null smart pointer
	
	if(p1 && p1->empty())
		*p1 = "hi";
	
	cout << "p1 underhood pointer: " << p1.get() << ", p1.use_count() = " << p1.use_count() << endl;
	auto p3 = make_shared<string>("hi");
	cout << "p3 underhood pointer: " << p3.get() << ", p3.use_count() = " << p3.use_count() << endl;
	cout << "p3 is unique? " << (p3.unique() ? "true" : "false") << endl;
	p1 = p3;
	cout << "p1 underhood pointer: " << p1.get() << ", p1.use_count() = " << p1.use_count() << endl;
	cout << "p3 is unique? " << (p3.unique() ? "true" : "false") << endl;
	p1 = make_shared<string>("jason");
	cout << *p1 << ' ' << *p3 << endl;
	swap(p1, p3);
	cout << "p1:" << p1.get() << ", p3:" << p3.get() << endl;
	cout << *p1 << ' ' << *p3 << endl;
	
	shared_ptr<int> pi = make_shared<int>(42);
	shared_ptr<string> p4 = make_shared<string>(10, '$');
	shared_ptr<double> p5 = make_shared<double>(); //value initilizer
	auto p6(p5);
	cout << *p6 << endl;
	
	return 0;
}