#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i = 10;
	double d = 100.1;
	i *= static_cast<int>(d);
	cout << i << endl; //1000
	
	//4.37
	const string s = "Hi";
	const string *ps = &s;
	char c = 'c', *pc = &c;
	void *pv;
	
	//pv = (void *)ps;
	cout << ps << endl;
	pv = static_cast<void *>(const_cast<string *>(ps));
	cout << pv << endl;
	pv = reinterpret_cast<void *>(const_cast<string *>(ps));
	cout << pv << endl;
	pv = const_cast<string *>(ps);
	cout << pv << endl;
	
	//i = int(*pc);
	i = static_cast<int>(*pc);
	cout << *pc << ' ' << pc << endl;
	cout << i << ' ' << char(99) << endl;
	
	//pv = &d;
	cout << endl;
	cout << "d = " << d << endl; //100.1
	pv = reinterpret_cast<void *>(&d);
	cout << *static_cast<double *>(pv) << endl; //100.1
	
	//pc = (char *)pv;
	cout << endl;
	pc = static_cast<char *>(pv);//100.1 -> 102 ?
	cout << *pc << endl; 		//f
	cout << (char)100 << endl;  //d
	cout << int('f') << endl; 	//102
	
	return 0;
}