#include <iostream>
using namespace std;

class Base
{
public:
	virtual double f1(double) noexcept;
	virtual int f2() noexcept(false);
	virtual void f3();
};

class Derived : public Base
{
public:
	double f1(double);	// error C2694
	int f2() noexcept(false);
	void f3() noexcept;
};

int main()
{
	Base b;
	Derived d;
	cout << "noexcept" << endl;

	return 0;
}