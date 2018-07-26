#include <iostream>
#include <string>
#include <memory>
using namespace std;

class HasPtr //simulate Pointer
{
private:
	string* ps;
	int i;
	size_t* use; //reference count
	
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)){}
	
	//copy constructor
	HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use;} //increment reference count
	
	HasPtr& operator=(const HasPtr&);
	
	~HasPtr();
	
	void output();
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
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

HasPtr::~HasPtr()
{
	if(--*use == 0)
	{
		delete ps;
		delete use;
	}
}

void HasPtr::output()
{
	cout << i << ' ' << *ps << ' ' << *use << endl;
}

//////////////////////
int main(int argc, char** argv)
{
	HasPtr pt("Hello");
	pt.output();
	
	HasPtr pt2(pt);
	pt2.output();
	
	HasPtr pt3("world");
	pt3.output();
	
	pt3 = pt;
	pt3.output();
	
	return 0;
}