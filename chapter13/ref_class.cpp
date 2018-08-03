#include <iostream>
#include <string>
using namespace std;

class RefClass
{
private:
	string *ps;
	int i;
	size_t *use;
	
public:
	RefClass(const string& s=string()) : ps(new string(s)), i(0), use(new size_t(1)) { cout << "constructor\n"; }
	
	RefClass(const RefClass& p) : ps(p.ps), i(p.i), use(p.use) { ++*use; cout << "copy constructor\n"; }
	
	RefClass& operator=(const RefClass&);
	
	~RefClass();
};

RefClass& RefClass::operator=(const RefClass& rhs)
{
	cout << "copy assignment operator\n";
	++*rhs.use;
	if(--*use == 0)
	{
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

RefClass::~RefClass()
{
	cout << "deconstructor\n";
	if(--*use == 0)
	{
		delete ps;
		delete use;
		cout << "release pointer resource" << endl;
	}
}



int main()
{
	RefClass r1, r2; //constructor 2 times
	
	r2 = r1;		 //copy assignment
	
	RefClass r3 = r1;//copy constructor
	RefClass r4(r2); //copy constructor
	
	//deconstructor 4 times, but not release pointer
	//release pointer resource!!!
	return 0;
}