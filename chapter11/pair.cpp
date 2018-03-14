#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>
using namespace std;

pair<string, size_t> fn(const vector<string> &vec)
{
	if(!vec.empty())
		return {vec.back(), vec.back().size()};
	else
		return pair<string, int>();
}

int main()
{
	pair<string, string> author{"James", "Joyce"};
	
	cout << author.first << ' ' << author.second << endl;
	
	vector<string> vec = {"hello", "jason"};
	auto p2 = make_pair(vec.front(), vec.front().size());
	auto p = fn(vec);
	cout << p.first << ' ' << p.second << endl;
	cout << p2.first << ' ' << p2.second << endl;
	
	set<int> iset = {1,2,3,4,5,6,7,8,8};
	cout << iset.size() << endl; //8!!!
	set<int>::iterator set_it = iset.begin();
	if(set_it != iset.end())
		//*set_it = 42; //error, const
		cout << *set_it << endl;
	
	cout << endl;
	vector<int> vi = {2,4,6,8,2,4,6,8};
	set<int> set2;
	set2.insert(vi.cbegin(), vi.cend());
	set2.insert({1,3,5,7,1,3,5,7});
	for(const auto &i : set2)
		cout << i << ' ';
	cout << endl;
	
	cout << endl;
	map<string, size_t> map2;
	map2.insert({"word", 1});
	map2.insert(make_pair("word2", 2));
	map2.insert(pair<string, size_t>("word3", 3));
	map2.insert(map<string, size_t>::value_type("word4", 4));
	for(const auto &m : map2)
		cout << m.first << ' ' << m.second << endl;
	cout << endl;
	
	auto ret = map2.insert({"word", 1});
	cout << (ret.second ? "insert okay" : "element exist") << endl;
	
	auto f = map2.find("word");
	cout << (f == map2.end() ? "not found " : "found ") << f->first << ' ' << f->second << endl;
	
	return 0;
}