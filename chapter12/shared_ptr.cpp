#include <iostream>
#include <list>
#include <string>
#include <memory>
#include <vector>
using namespace std;

int main()
{
	shared_ptr<string> p1;
	shared_ptr<list<int>> p2;
	
	cout << (p1 == nullptr ? "yes, p1 is nullptr" : "no, p1 is not nullptr") << endl;
	p1 = make_shared<string>("hello");
	cout << "null" << *p1 << "null" << endl;
	if(p1 && !p1->empty())
		*p1 = "hi";
	
	cout << p1 << ' ' << *p1 << endl;
	
	shared_ptr<int> p3 = make_shared<int>(100);
	shared_ptr<string> p4 = make_shared<string>(10, '$');
	shared_ptr<int> p5 = make_shared<int>();
	
	cout << *p3 << ' ' << *p4 << ' ' << *p5 << endl;
	
	auto p6 = make_shared<vector<string>>( vector<string>({"jason", "li"}) );
	if(p6 && !p6->empty())
	{
		cout << p6->size() << endl;
		for(const auto &s : *p6)
			cout << s << ' ';
		cout << endl;
	}
	
	auto p7(p6);	//p7 and p6 point to same object!
	for(const auto &s : *p7)
		cout << s << ' ';
	cout << endl;
	
	return 0;
}