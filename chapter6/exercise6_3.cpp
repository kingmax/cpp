#include <iostream>
using namespace std;

int fact(int x)
{
	int ret = 1;
	while(x > 0)
		ret *= x--;
	return ret;
}

void out_fact()
{
	cout << "Enter a number(integer), return fact(number)" << endl;
	int x;
	cin >> x;
	cout << fact(x) << endl;
}

unsigned _abs(int x)
{
	return ( x >= 0 ? x : -x);
}

int main()
{
	int x = 6;
	cout << fact(x) << endl;
	
	//6.4
	try
	{
		while(cin)
			out_fact();
	}
	catch(exception ex)
	{
		cout << "exception occur, exit out_fact" << endl;
	}
	
	//6.5
	cout << "my abs function" << endl;
	cout << _abs(-10) << endl;
	cout << _abs(0) << endl;
	cout << _abs(199) << endl;
	
	return 0;
}