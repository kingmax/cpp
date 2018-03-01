#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto it = lst.cbegin();
	while(it != lst.cend())
		if(*it % 2)
			it = lst.erase(it);
		else
			++it;
		
	for(const auto &i : lst)
		cout << i << ' ';
	cout << endl;
	
	lst.clear();
	cout << lst.size() << endl;
	lst.emplace_front(100);
	cout << lst.size() << endl;
	auto beg = lst.cbegin();
	auto end = beg; //lst.cend();
	//--end;
	cout << &beg << ' ' << &end << endl;
	lst.erase(beg, end); //if beg == end erase do nothing!
	cout << lst.size() << endl;
	
	beg = lst.cend();
	end = beg;
	cout << &beg << ' ' << &end << endl;
	lst.erase(beg, end); //if beg and end all are cend erase do nothing!
	cout << lst.size() << endl;
	
	return 0;
}