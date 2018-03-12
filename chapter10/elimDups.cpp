#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	auto end_unique = unique(words.begin(), words.end());
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	words.erase(end_unique, words.end());
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
	
	elimDups(words);
	cout << words.size() << endl;
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	return 0;
}