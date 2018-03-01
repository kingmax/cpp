#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	vector<int> va = {begin(ia), end(ia)};
	list<int> la = {begin(ia), end(ia)};
	
	for(const auto &i : va)
		cout << i << ' ';
	cout << endl;
	for(const auto &i : la)
		cout << i << ' ';
	cout << endl;
	
	auto beg = va.cbegin();
	while(beg != va.cend())
		if(*beg % 2)
			beg = va.erase(beg);
		else
			++beg;
		
	for(const auto &i : va)
		cout << i << ' ';
	cout << endl;
	
	auto beg2 = la.cbegin();
	while(beg2 != la.cend())
		if(*beg2 % 2)
			++beg2;
		else
			beg2 = la.erase(beg2);
	
	for(const auto &i : la)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}