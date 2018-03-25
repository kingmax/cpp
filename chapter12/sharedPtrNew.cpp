#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main()
{
	shared_ptr<double> p1;
	//shared_ptr<int> p2 = new int(100); //error, explicit ctor!
	shared_ptr<int> p2(new int(100));
	cout << p2.use_count() << endl;
	p2.reset();
	cout << p2.use_count() << endl;
	
	p2.reset(new int(1000));
	cout << p2.use_count() << endl;
	
	auto p3 = p2;
	cout << p2.use_count() << endl; //2
	cout << "p2 is unique? " << (p2.unique() ? "true" : "false") << endl;
	
	//if shared_ptr is not unique, 
	//make a copy first prevent auto free memory underhood
	if(!p2.unique())
		p2.reset(new int(*p2));
	(*p2)++;
	cout << p2.use_count() << endl;
	cout << p3.use_count() << endl;
	cout << *p2 << endl; //1001
	cout << *p3 << endl; //1000
	
	return 0;
}