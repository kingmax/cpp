#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;

template<typename T> void print(const T &container)
{
	typedef typename T::size_type size_type;
	for(size_type i = 0; i != container.size(); ++i)
		cout << container[i] << ',';
	cout << endl;
}

// 16.20
template<typename T> void print2(const T &c)
{
	for(auto b = c.begin(); b != c.end(); ++b)
		cout << *b << ',';
	cout << endl;
}

int main()
{
	vector<string> s = {"a", "b", "c"};
	print(s);
	
	list<int> l{1,2,3,4,5};
	print2(l);
	
	return 0;
}