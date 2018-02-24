#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NoDefault
{
	public:
		NoDefault(int a){cout << a << " in NoDefault(int a)" << endl;}
		void print() const {cout << "NoDefault.print()" << endl;}
};

class C
{
	public:
		NoDefault nd;
		//C() = default; //error
		C() : nd(NULL){}
};

int main()
{
	C c;
	cout << &c << endl;
	cout << &c.nd << endl;
	c.nd = NoDefault(100);
	cout << &c.nd << endl;
	c.nd.print();
	
	cout << endl;
	
	//exercise7.44
	//vector<NoDefault> vec(10); //error, no default constructor
	
	//exercise7.45
	vector<C> vec(10);
	cout << vec.size() << endl;
	
	return 0;
}