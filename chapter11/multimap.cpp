#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	multimap<string, string> authors;
	authors.insert({"jason", "storyA"});
	authors.insert({"jason", "storyB"});
	authors.insert({"jason", "storyC"});
	
	authors.insert({"jason.lee", "storyA"});
	authors.insert({"jason.lee", "storyB"});
	authors.insert({"jason.lee", "storyC"});
	authors.insert({"jason.lee", "storyD"});
	
	for(const auto &m : authors)
		cout << m.first << ' ' << m.second << endl;
	
	cout << endl;
	string search_item("jason.lee");
	auto count = authors.count(search_item);
	auto it = authors.find(search_item);
	while(count)
	{
		cout << it->second << endl;
		++it;
		--count;
	}
	
	cout << endl;
	for(auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item); beg != end; ++beg)
	{
		cout << beg->second << endl;
	}
	
	cout << endl;
	for(auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
	{
		cout << pos.first->second << endl;
	}
	
	
	return 0;
}