#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto unique_end = unique(words.begin(), words.end());
	words.erase(unique_end, words.end());
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
	
	cout << "defalut sort:" << endl;
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	cout << "by length sort:" << endl;
	sort(words.begin(), words.end(), isShorter);
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	//stable_sort, by dict a b c...
	cout << "\nelimDups..." << endl;
	elimDups(words);
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	cout << "\nstable_sort, by dict a b c..." << endl;
	stable_sort(words.begin(), words.end(), isShorter);
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	return 0;
}