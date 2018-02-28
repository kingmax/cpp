#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main()
{
	list<deque<int>> dlist;

	for(int i=0; i<10; ++i)
	{
		deque<int> d;
		for(int n=0; n<10; ++n)
			//d.push_front(i * n);
			d.push_back( i * n );
		//dlist.push_front(d);
		dlist.push_back(d);
	}
	
	cout << dlist.size() << endl;
	
	int n = 0;
	for(auto beg = dlist.cbegin(); beg != dlist.cend(); ++beg)
	{
		cout << "deque " << ++n << ":" << endl;
		for(auto b = (*beg).cbegin(); b != (*beg).cend(); ++b)
			cout << *b << ' ';
		cout << endl;
	}
	
	cout << "\nreverse output-------------------------" << endl;
	for(auto last = dlist.cend(); last != dlist.cbegin(); /* --last */)
	{
		cout << "deque " << n-- << ":\t" << &last << endl;
		//cout << (*last).size() << endl;
		--last;
		for(auto e = (*last).cend(); e != (*last).cbegin(); /* --e */)
		{
			--e;
			cout << *e << ' ';
		}
		cout << endl;
	}
	/* cout << &dlist.crend() << ' ' << &dlist.cend() << endl;
	cout << &dlist.crbegin() << ' ' << &dlist.cbegin() << endl; */
	
	cout << "\nReverse output 2 (using crbegin, crend [or rbegin, rend])" << endl;
	for(auto rbeg = dlist.crbegin(); rbeg != dlist.crend(); ++rbeg)
	{
		for(auto rb = (*rbeg).crbegin(); rb != (*rbeg).crend(); ++rb)
			cout << *rb << ' ';
		cout << endl;
	}
	
	return 0;
}