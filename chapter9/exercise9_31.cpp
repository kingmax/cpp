#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
using namespace std;

int main()
{
	vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto it = vi.begin();
	while(it != vi.end())
	{
		if(*it % 2)
		{
			it = vi.insert(it, *it);
			it += 2;
		}
		else
			it = vi.erase(it);
	}
	
	for(const auto &i : vi)
		cout << i << ' ';
	cout << endl;
	
	list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto it2 = li.begin();
	while(it2 != li.end())
	{
		if(*it2 % 2)
		{
			it2 = li.insert(it2, *it2);
			//it2 += 2; // no += op
			++it2;
			++it2;
		}
		else
			it2 = li.erase(it2);
	}
	
	for(auto const &i : li)
		cout << i << ' ';
	cout << endl;
	
	forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while(curr != flst.end())
	{
		if(*curr % 2)
		{
			prev = curr;
			curr = flst.insert_after(prev, *curr);
			++prev;
			++prev;
			++curr;
			++curr;
		}
		else
		{
			curr = flst.erase_after(prev);
		}
	}
	
	for(const auto &i : flst)
		cout << i << ' ';
	cout << endl;
	
	
	return 0;
}