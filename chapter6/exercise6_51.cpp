#include <iostream>
using namespace std;

void f()
{
	cout << "\nf()" << endl;
}

void f(int n)
{
	cout << "\nf(int n)\t";
	cout << n << endl;
}

void f(int a, int b)
{
	cout << "\nf(int a, int b)\t";
	cout << a << ' ' << b << endl;
}

void f(double d, double _default=3.14)
{
	cout << "\nf(double d, double _default=3.14)\t";
	cout << d << ' ' << _default << endl;
}

int main()
{
	//f(2.56, 42); 	//Error, cann't solve!
	f(42); 			//call f(int)
	f(42, 0);		//call f(int, int)
	f(2.56, 3.14);	//call f(double, double=3.14)
	
	return 0;
}