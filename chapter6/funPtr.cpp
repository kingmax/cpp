#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthCompare(const string &s1, const string &s2)
{
	return s1.size() == s2.size() ? 0 : (s1.size() > s2.size() ? 1 : -1);
}

int (*pf)(const string &s1, const string &s2); //ptr point to a function
int *pf2(const string &s1, const string &s2);  //a function return ptr!

//overload
void ff(int *)
{
	cout << "ff(int *)" << endl;
}
void ff(unsigned)
{
	cout << "ff(unsigned)" << endl;
}

//void (*pfx)(unsigned);
void fn(unsigned u)
{
	cout << "fn(unsigned u)\t" << u << endl;
}

//function ptr arguments
void useBigger(const string &s1, const string &s2,
			   int function(const string &, const string &)); //func param compiled to ptr!!!
void useBigger2(const string &s1, const string &s2, 
				int (*function)(const string &s1, const string &s2)); //same

//useBigger("hi", "jason", lengthCompare);
//useBigger2("hi","jason", lengthCompare); //function will convert to Pointer when compile!!!

//def function				
typedef int Func(const string &, const string &);
typedef decltype(lengthCompare) Func2; //same typedef int Func(const string&, const string&)
//def function pointer
typedef int (*FuncPtr)(const string &, const string &);
typedef decltype(lengthCompare) *FuncPtr2;//decltype result is function, so add *
//combine def
int myCompare1(const string &s1, const string &s2, Func fn){return fn(s1, s2);}
int myCompare2(const string &s1, const string &s2, FuncPtr ptr)
{
	return ptr(s1, s2);
}
int myCompare3(const string &s1, const string &s2, Func2 fn){return fn(s1, s2);}
int myCompare4(const string &s1, const string &s2, FuncPtr2 ptr)
{
	return ptr(s1, s2);
}

//return function pointer
using F = int(int*, int);	   //function
using PF = int (*)(int*, int); //pointer
int target(int *p, int x)
{
	return *p + x;
}
PF f1(int i)
{
	cout << __func__ << endl;
	return &target;
}

F *f2(int i)
{
	cout << __func__ << endl;
	return target;
}

//
int (*fun_x(int i))(int *p, int n);
auto f3(int i) -> int (*)(int *p, int n); //trailing return

//
string::size_type sumLength(const string &, const string &);
string::size_type largerLen(const string&, const string&);
decltype(sumLength) *getFun(const string &);

int main()
{
	pf = lengthCompare;
	cout << pf << endl;
	pf = &lengthCompare;
	cout << pf << endl; //same as pf
	
	//all 3 same as call pf(s1, s2)
	string s1 = "hello", s2 = "Jason";
	cout << pf(s1, s2) << endl;
	cout << (*pf)(s1, s2) << endl;
	cout << lengthCompare(s1, s2) << endl;
	
	cout << "overload:" << endl;
	void (*pfx)(unsigned) = ff;
	cout << pfx << endl;
	pfx(0); //call ff(unsigned)
	pfx = nullptr;
	pfx = fn;
	pfx(0); //call fn(unsigned)
	
	cout << endl;
	cout << "function pointer testing:" << endl;
	cout << myCompare1(s1, s2, lengthCompare) << endl;
	cout << myCompare2(s1, s2, &lengthCompare) << endl;
	cout << myCompare2(s1, s2, lengthCompare) << endl; //function will convert to Pointer!
	cout << myCompare3(s1, s2, lengthCompare) << endl;
	//cout << myCompare4(s1, s2, &lengthCompare) << end; //error
	cout << myCompare4(s1, s2, lengthCompare) << endl; //convert to pointer!
	
	cout << "\nreturn function pointer testing:" << endl;
	PF pf = f1(10);
	cout << pf << endl;
	cout << target << endl;
	int t = 10;
	cout << pf(&t, 2) << endl;
	
	cout << f1(5) << endl;
	
	cout << endl;
	F *pf2 = f2(8);
	cout << pf2 << endl;
	cout << pf2(&t, 10) << endl;
	
	return 0;
}