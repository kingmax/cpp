#include "Person.h"
using namespace std;

int main()
{
	Person p;
	output(cout, p);
	cout << endl;
	
	Person p2("Jason");
	output(cout, p2);
	cout << endl;
	
	Person p3("Jason", "Suzhou");
	output(cout, p3);
	cout << endl;
	
	cout << "constructor from input, Enter: Name Addr" << endl;
	Person p4(cin);
	output(cout, p4);
	cout << endl;
	
	return 0;
}