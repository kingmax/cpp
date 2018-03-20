#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main()
{
	int *pia = new int[10]; //not initialized!
	typedef int iArr[10];
	int *pi = new iArr();
	delete [] pi;
	
	int *pia2 = new int[10](); //default initialized to 0
	string *psa = new string[10];   //10 null string
	string *psb = new string[10](); //10 null string
	
	int *pia3 = new int[3]{0, 1, 2};
	string *psc = new string[10]{"a", "an", "the", string(3, 'x')};
	
	std::size_t n = 10;
	int *p = new int[n]();
	for(size_t i = 0; i != n; ++i)
	{
		p[i] = i * 2;
	}
	
	for(int *q = p; q != p+n; ++q)
		cout << *q << ' ';
	cout << endl;
	
	delete [] p; //delete array, free memory!
	
	//unique_ptr
	unique_ptr<int[]> up(new int[10]);
	for(size_t i = 0; i != 10; ++i)
		up[i] = i;
	up.release(); // call delete []
	
	//shared_ptr, must assign deleter, (eg. lambda expression)
	shared_ptr<int> sp(new int[10], [](int *p){delete[] p;});
	for(size_t i = 0; i != 10; ++i)
		*(sp.get() + i) = i; //must be using get got internal pointer!
	sp.reset(); //call lambda expression delete[]
	
	
	return 0;
}