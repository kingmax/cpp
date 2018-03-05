#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
/* 	for(auto const &i : vi)
	{
		cout << i << ' ';
	}
	cout << endl; */
	
	auto it = vi.begin();
/* 	it = vi.insert(it, 100);
	cout << *it << endl; */
	
	while(it != vi.end())
	{
		if(*it % 2)
		{
			it = vi.insert(it, *it);
			++it;
		}
		++it;
	}
	//0 1 1 2 3 3 4 5 5 6 7 7 8 9 9
	for(auto const &i : vi)
	{
		cout << i << ' ';
	}
	cout << endl;
	
	it = vi.begin();
	while(it != vi.end())
	{
		if(!(*it % 2))
		{
			it = vi.insert(it, *it);
			it += 2;
		}
		else
			++it;
	}
	//0 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
	for(auto const &i : vi)
	{
		cout << i << ' ';
	}
	cout << endl;
	
	return 0;
}