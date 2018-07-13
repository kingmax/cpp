#include <string>
#include <iostream>
using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) { cout << "default constructor" << endl; }
	
	//Copy constructor
	HasPtr(const HasPtr &orig) : ps(new string(*orig.ps)), i(orig.i)
	{
		*ps += "_added";
		++i;
		cout << "copy constructor" << endl;
	}
	
	void print()
	{
		cout << ps << ' ' << *ps << endl;
		cout << &i << ' ' << i << endl;
	}
	
	//Assigmentor
	HasPtr& operator=(const HasPtr &rhs)
	{
		cout << "assigment operator" << endl;
		ps = new string(*rhs.ps);
		i = rhs.i;
		return *this;
	}
	
	HasPtr f(HasPtr hp)
	{
		HasPtr ret = hp;
		return ret;
	}
	
	~HasPtr()
	{
		delete ps;
		cout << "deconstructor" << endl;
	}
	
private:
	string *ps;
	int i;
};

int main()
{
	HasPtr a("a"); //call default constructor
	cout << "a finished" << endl;
	
	HasPtr b = a;	//call copy constructor
	cout << "b finished\n" << endl;
	
	a.print();
	cout << endl;
	b.print();
	
	cout << endl << endl;
	HasPtr c(b); //call copy constructor
	c.print();
	
	cout << endl << endl;
	b.print();
	
	cout << endl << endl;
	HasPtr d;	//call default constructor
	d.print();
	
	cout << endl << endl;
	d = b;	//call assigment operator
	d.print();
	
	cout << endl << endl;
	HasPtr *p = new HasPtr; //call default constructor
	p->print();
	cout << "will delete p" << endl;
	delete p;				//call deconstructor
	cout << endl;
	
	p->f(d);
	HasPtr x(d);
	
	return 0;
}