#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int *pi = new int;
	string *ps = new string;
	
	int *pi2 = new int(1024);
	string *ps2 = new string(10, '9');
	vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};
	
	int *pi3 = new int();
	string *ps3 = new string();
	vector<int> *pv2 = new vector<int>();
	
	const int *pci = new const int(1024);
	cout << *pci << endl;
	delete pci;
	const string *pcs = new const string;
	delete pcs;
	
	int *p2 = new (nothrow) int;
	delete p2;
	
	int *pp(new int(100));
	cout << *pp << ' ' << pp << endl;
	auto q = pp;
	delete pp;
	pp = nullptr;
	q = nullptr;
	
	return 0;
}