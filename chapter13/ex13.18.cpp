#include <iostream>
#include <string>
using namespace std;

class Employee
{
	string name;
	int id;
	
	static int ID;
public:
	Employee() : name(""), id(++ID) {}
	Employee(const string& n) : name(n), id(++ID) {}
	
	Employee(const Employee& orig) : name(orig.name), id(++ID) {}
	
	void print() const
	{
		cout << "Name: " << name << ", ID: " << id << endl;
	}
};

int Employee::ID = 0;

int main()
{
	Employee a;
	Employee b("jason");
	Employee c = b;
	Employee d(c);
	
	a.print();
	b.print();
	c.print();
	d.print();
	
	Employee* pe = new Employee(d);
	pe->print();
	delete pe;
	
	return 0;
}