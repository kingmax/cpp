#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//exercise10.15
int add_10(int i)
{
	auto f = [i](int n){return i + n;};
	return f(10);
}

int main()
{
	auto sum = [](int a, int b){return a+b;};
	int i = sum(10, 90);
	cout << i << endl;
	
	//exercise10.15
	int x = add_10(i);
	cout << x << endl;
	
	
	
	
	return 0;
}