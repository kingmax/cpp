#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int i = 10, j = 20;
	double slope = static_cast<double>(i) / j;
	cout << slope << endl;
	double d = i / j; //0
	cout << d << endl;
	
	void *p = &slope;
	double *dp = static_cast<double *>(p); //get valid ptr from void*
	cout << *dp << endl;
	
	//const_cast
	const char *pc = "hi";
	char *p2 = const_cast<char *>(pc); //ok, but cann't write by ptr
	cout << pc << endl;
	//*p2 = 'H'; //error!!!
	
	string s = static_cast<string>(pc);
	cout << s << endl;
	//s = const_cast<string>(pc); //error, const_cast only remove const atrribute!
	
	//reinterpret_cast
	int x = 97;
	int *px = &x;
	char *pchar = reinterpret_cast<char *>(px);
	cout << pchar << endl; //a
	char A = 'A';
	cout << static_cast<int>(A) << endl; //65
	
	char *pchar2 = (char *)px;
	cout << pchar2 << endl; //a
	char *pchar3 = (char *)(px);
	cout << pchar3 << endl; //a
	
	cout << endl;
	
	return 0;
}