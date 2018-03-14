#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void delMM(multimap<string, string> &mm, const string &s)
{
	if(mm.count(s))
		mm.erase(s);
}

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
	
	cout << "\nAfter delete jason" << endl;
	delMM(authors, "jason");
	for(const auto &m : authors)
		cout << m.first << ' ' << m.second << endl;
	
	
	//exercise11.32
	authors.insert({"a jason", "storyA"});
	authors.insert({"a jason", "storyB"});
	authors.insert({"li jason", "storyC"});
	
	cout << "\n all author and books:" << endl;
	vector<string> names;
	for(const auto &m : authors)
	{
		if(find(names.cbegin(), names.cend(), m.first) == names.cend())
			names.push_back(m.first);
	}
	for(const auto &n : names)
		cout << n << ' ';
	cout << endl;
	sort(names.begin(), names.end());
	
	cout << endl;
	for(const auto &n : names)
	{
		cout << n << endl;
		for(auto p = authors.equal_range(n); p.first != p.second; ++p.first)
			cout << "\t" << p.first->second << endl;
	}
	
	
	return 0;
}