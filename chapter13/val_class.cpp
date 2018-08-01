#include <iostream>
#include <string>
using namespace std;

class ValClass
{
private:
	string *ps;
	int i;
public:
	ValClass(const string &s = string()) : ps(new string(s)), i(0) { cout << "constructor\n"; }
	
	ValClass(const ValClass &p) : ps(new string(*p.ps)), i(p.i){ cout << "copy constructor\n"; }
	
	ValClass& operator=(const ValClass&);
	
	~ValClass() { delete ps; cout << "deconstructor\n"; }
	
	bool operator==(const ValClass& rhs)
	{
		return (*rhs.ps == *ps && rhs.i == i);
	}
};

ValClass& ValClass::operator=(const ValClass& rhs)
{
	cout << "operator=\n";
	if(*this == rhs)
		return *this;
	
	cout << "copy assigment\n";
	string *s = new string(*rhs.ps);
	delete ps;
	ps = s;
	i = rhs.i;
	return *this;
}

int main()
{
	ValClass v("hi");
	ValClass v2;
	v2 = v;
	
	ValClass v3(v2);
	v3 = v2; //not copy assigment
	cout << "v3 == v? " << (v3 == v ? "true" : "false") << endl;
	cout << "v3 == v2? " << (v3 == v2 ? "true" : "false") << endl;
	
	return 0;
}