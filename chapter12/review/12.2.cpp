#include <iostream>
#include <memory>
using namespace std;

int main()
{
	const unsigned int size = 10;
	int* p = new int[size]();
	cout << "-->" << *p << endl;
	
	int x = 0;
	for(int* q = p; q != p + size; ++q)
	{
		*q = ++x;
	}
	cout << "\n-->" << *p << endl;
	
	for(int i=0; i < size; ++i)
		cout << *(p+i) << endl;
	
	delete[] p;
	
	unique_ptr<int[]> up(new int[10]);
	for(size_t i = 0; i != 10; ++i)
		up[i] = i;
	
	for(size_t i = 10; i > 0; )
		cout << up[--i] << ' ';
	cout << endl;
	
	up.release();
	
	shared_ptr<int[]> sp(new int[10], [](int *p){delete[] p;});
	for(size_t i = 0; i != 10; ++i)
		//sp[i] = i;
		*(sp.get() + i) = i;
	for(size_t i = 10; i > 0; )
		cout << sp[--i] << ' ';
	cout << endl;
	sp.reset();
	
	return 0;
}