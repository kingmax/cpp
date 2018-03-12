#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool gt5(const string &s)
{
	return s.size() >= 5;
}

int main()
{
	string txt = "the quick red fox jumps over the slow red turtle";
	vector<string> words;
	string word;
	stringstream ss(txt);
	while(ss >> word)
		words.push_back(word);
	
	cout << words.size() << endl;
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	auto it_end = partition(words.begin(), words.end(), gt5);
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl << endl;
	
	for(auto beg = words.begin(); beg != it_end; ++beg)
		cout << *beg << endl;
	
	return 0;
}