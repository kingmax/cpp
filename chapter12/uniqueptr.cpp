#include <iostream>
#include <string>
#include <memory>
using namespace std;

unique_ptr<int> clone(int p)
{
	return unique_ptr<int>(new int(p));
}

unique_ptr<int> clone2(int p)
{
	/* auto ret = unique_ptr<int>(new int(p)); */
	unique_ptr<int> ret(new int(p));
	return ret;
}

int main()
{
	unique_ptr<int> p1(new int(100));
	unique_ptr<double> p2(new double());
	
	cout << *p1 << ' ' << *p2 << endl;
	
	//unique_ptr<int> p3(p1); //error, can not copy
	unique_ptr<double> p4;
	//p4 = p2; //error
	unique_ptr<double> p5(p2.release());
	cout << *p5 << ' ' << (p2 ? "p2 exist" : "p2 is nullptr") << endl;
	
	unique_ptr<int> p6(new int());
	cout << *p1 << ' ' << *p6 << endl; //100, 0
	p1.reset(p6.release()); //now p1 hold 0, p6 is nullptr
	//cout << *p1 << ' ' << *p6 << endl; //100 error
	cout << *p1 << endl; //0
	
	
	return 0;
}