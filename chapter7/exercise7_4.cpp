#include <iostream>
#include "Person.h"
using namespace std;

void printPersonInfo(const Person &p)
{
	cout << "Name: " << p.getName() << endl;
	cout << "Addr: " << p.getAddr() << endl;
}

int main()
{
	Person p;
	printPersonInfo(p);
	
	cout << "Enter person: Name Addr" << endl;
	while(cin >> p.name >> p.addr)
	{
		printPersonInfo(p);
	}
	
	return 0;
}