#include <iostream>
using namespace std;

int fact(int n)
{
	int ret = 1;
	while( n > 1)
		ret *= n--;
	return ret;
}

void fun(void){cout << "void function" << endl;}

int main()
{
	int j = fact(5);
	cout << j << endl;
	
	fun();
	
	return 0;
}