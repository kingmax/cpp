#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

class HasPtr //simulate Pointer
{
	friend void swap(HasPtr&, HasPtr&);
	
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
	
	bool operator<(const HasPtr&);
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	cout << "swap(&, &)" << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

bool HasPtr::operator<(const HasPtr& rhs)
{
	return *ps < *rhs.ps;
}

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
	cout << endl;
	
	//ex13.31
	vector<HasPtr> vs = {HasPtr{"a"}, HasPtr{"b"}, HasPtr{"c"}, HasPtr{"ab"}, HasPtr{"abc"}};
	for(auto &v : vs)
		v.output();
	
	cout << "\nafter sorted" << endl;
	std::sort(vs.begin(), vs.end());
	for(auto &v : vs)
		v.output();
	
	return 0;
}