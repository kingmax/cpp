#include <iostream>
#include <string>
#include <vector>
using namespace std;

int *newInt(int x)
{
	return new int(x);
}

void use_newInt(int x, int y)
{
	int *p = newInt(x+y);
	cout << *p << endl;
	//NOTE, free memory!!!
	delete p;
}

int main()
{
	int *pi = new int;	//undefined value
	int *p2 = new int(1024);
	cout << *pi << ' ' << *p2 << endl;  //
	*pi = 100;
	cout << *pi << endl;
	
	string *ps = new string; //"", null string
	string *ps2 = new string(74, '$');
	cout << *ps << ' ' << *ps2 << endl;
	*ps = "hello";
	cout << *ps << ' ' << *ps2 << endl;
	
	vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};
	cout << pv->size() << endl;
	
	//using value init
	int *px = new int(); //0
	cout << *px << endl;
	
	string *psx = new string(); //""
	cout << *psx << psx->size() << endl;
	
	const int *pci = new const int(2048);
	const string *pcs = new const string();
	//*pcs = "hi"; //error
	cout << *pci << endl;
	delete pci;
	
	int *p3 = new (nothrow) int(); //if alloc memory failed, return nullptr!!! not bad_alloc exception!
	
	//delete
	int i, *pi1 = &i, *pi2 = nullptr;
	double *pd = new double(3.14), *pd2 = pd;
	//delete i; 	//error, not pointer
	//delete pi1;	//error, not dynamic pointer by new create
	delete pi2;	//ok, delete nullptr is okay.
	delete pd;	//ok
	//delete pd; 	//error, pointer was deleted!
	//delete pd2;	//error, the memory was deleted!!! (by delete pd)
	
	int *x = newInt(100);
	cout << *x << endl;
	delete x; //must free the function return pointer!
	
	use_newInt(100, 100);
	
	//
	auto *pp(new int(123));
	auto q = pp;
	delete pp; //pp and q are freed
	pp = nullptr; //but q point to invalid memory
	cout << q << ' ' << pp << endl;
	q = 0; //nullptr
	cout << q << ' ' << pp << endl;
	
	return 0;
}