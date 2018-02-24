#include <iostream>
using namespace std;

class X; //forward declaration
class Y; //forward declaration

class X
{
	public:
	X() = default;
	X(Y *p){ ptr = p; }
	
	void print()
	{
		if(ptr)
		{
			cout << ptr << endl;
			//ptr->print(); //error cann't call undefined class method
		}
		else
			cout << "ptr == nullptr" << endl;
	}
	
	//private:
	Y *ptr = nullptr;
};

class Y
{
	public:
	Y(){ cout << "Y default constructor" << endl; }
	Y(X _x){ x = _x; }
	
	void print()
	{
		cout << &x << endl;
	}
	
	//private:
	X x;
};

int main()
{
	X a;
	a.print();
	Y b;
	cout << &b << endl;
	
	cout << endl;
	X x(&b);
	cout << &x << endl;
	x.print();
	
	//remove private
	x.ptr->print();
	
	return 0;
}