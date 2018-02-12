#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s = "hello, world!";
	for(decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
		s[index] = toupper(s[index]);
	for(char c : s)
		cout << c << ' ';
	cout << endl;
	
	vector<string> words = {"Hi", "Jason"};
	for(decltype(words.size()) i = 0, sz = words.size(); i != sz; ++i)
		words.push_back(words[i]);
	for(auto word : words)
		cout << word << ' ';
	words.push_back("0");
	cout << endl << words.size() << endl;
	cout << endl;
	
	cout << endl;
	auto beg = words.cbegin();
	for(; beg != words.cend() && *beg != "Jason"; ++beg) //only output 1 Hi!!! when condition false
	{
		cout << &beg << endl;
		cout << *beg << endl;
	}
	cout << "end" << endl;
	
	for(auto w : words)
		if(w != "Jason")
			cout << w << endl;
	cout << endl;
	
	vector<int> vi = {1,2,3,0,-1,-2,-3};
	//find first negative number
	auto start = vi.cbegin();
	for(; start != vi.cend() && *start >= 0; ++start)
		;
	cout << "search first negative number result: " << *start << endl; //-1
	cout << endl;
	
	for(auto x : {1,2,3,4,5,})
		cout << x << ' ';
	cout << endl;
	
	vector<int> vx = {1,2,3,4,5,};
	for(auto &x : vx)
	{
		x *= 2;
		cout << x << ' ';
	}
	cout << endl;
	
	for(auto begin = vx.cbegin(); begin != vx.cend(); ++begin)
		cout << *begin << ' ';
	cout << endl;
	
	return 0;
}