#include <iostream>
#include <string>
#include <vector>
using namespace std;

int bigger(int n, const int *p)
{
	return n > *p ? n : *p;
}

//6.22
//void swap_ptr(const int *pa, const int *pb) //error!!
void swap_ptr(int* (&pa), int* (&pb))
{
	auto temp = pa;
	//int *temp = pa;
	pa = pb;
	pb = temp;
}


int main()
{
	int a=10, b=20;
	cout << bigger(a, &b) << endl;
	cout << endl;
	
	int *pa = &a, *pb = &b;
	cout << *pa << ' ' << *pb << endl;
	swap_ptr(pa, pb);
	cout << *pa << ' ' << *pb << endl;
	
	return 0;
}