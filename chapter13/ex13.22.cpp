#include <iostream>
#include <string>

using namespace std;

class HasPtr //simulate Value Type
{
private:
	int i;
	string* ps;
	
public:
	//constructor, option parameter s has default value
	HasPtr(const string& s = string()) : ps(new string(s)), i(0){}
	
	//copy constructor
	HasPtr(const HasPtr& p) : ps(new string(*p.ps)), i(p.i){}
	
	//copy assignment operator
	HasPtr& operator=(const HasPtr&);
	
	~HasPtr(){ delete ps; }
	
	void output();
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	auto newp = new string(*rhs.ps); //copy string
	delete ps;
	ps = newp;
	
	i = rhs.i;
	
	return *this;
}

void HasPtr::output()
{
	cout << i << ' ' << *ps << endl;
}

int main(int argc, char** argv)
{
	HasPtr val("hello");
	//cout << val.i << *val.ps << endl;
	val.output();
	
	HasPtr val2;
	//cout << val2.i << *val2.ps << endl;
	val2.output();
	
	val2 = val;
	//cout << val2.i << *val2.ps << endl;
	val2.output();
	
	return 0;
}