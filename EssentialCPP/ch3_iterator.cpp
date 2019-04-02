#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

template<typename T>
void display(const vector<T> &vec, ostream &os)
{
	for(auto cbeg = vec.cbegin(),
			 cend = vec.cend();
		cbeg != cend; ++cbeg)
		os << *cbeg << " ";
	os << endl;
}

template<typename Iter, typename T>
Iter find(Iter first, Iter last, const T &value)
{
	for(; first != last; ++first)
		if(value == *first)
			return first;
	return last;
}


int main()
{
	vector<string> vs = {"a", "bc", "def"};
	for(auto it = vs.cbegin(); it != vs.cend(); ++it)
	{
		cout << *it << " ";
		cout << it->size() << endl;
	}
	cout << endl;
	
	display(vs, cout);
	
	cout << "find demo:" << endl;
	const int SIZE = 8;
	int ia[SIZE] = {1,1,2,3,5,8,13,21};
	vector<int> ivec(ia, ia+SIZE);
	list<int> ilist(ia, ia+SIZE);
	int *pia = find(ia, ia+SIZE, 1024);
	
	if(pia != ia+SIZE)
		cout << "found in array" << endl;
	else
		cout << "not found in array" << endl;
	
	vector<int>::iterator it;
	it = find(ivec.begin(), ivec.end(), 21);
	if(it != ivec.end())
		cout << "found in vector\n";
	else
		cout << "not found in vector\n";
	
	list<int>::iterator iter;
	iter = find(ilist.begin(), ilist.end(), 13);
	if(iter != ilist.end())
		cout << "found in list\n";
	else
		cout << "not found in list\n";
	
	return 0;
}