#include <iostream>
#include <string>
#include <vector>
using namespace std;

int f(int a, int b)
{
	return a + b;
}
//using pf = int (*)(int, int); //int (*)(int x, int y);
typedef int (*pf)(int, int);

//6.55
int add(int a, int b){ cout << __func__ << endl; return a+b; }
int sub(int a, int b){ cout << __func__ << endl; return a-b; }
int mul(int a, int b){ cout << __func__ << endl; return a*b; }
int _div(int a, int b)
{ 
	cout << __func__ << endl;
	if(b != 0) return a/b; 
	else return 0;
}
using op = int (*)(int, int);

int main()
{
	//6.54
	vector<pf> functions = {f, &f};
	cout << f << endl;
	for(auto func : functions)
		cout << func << endl;
	
	//6.55
	vector<op> ops = {add, sub, mul, _div};
	cout << "\nvector<op> ops = {add, sub, mul, _div} testing:" << endl;
	for(auto x : ops)
		cout << x << endl;
	cout << endl;
	
	//6.56
	int a = 10000, b = 100;
	for(auto fn : ops)
		cout << fn(a, b) << endl;
	cout << endl;
	
	return 0;
}