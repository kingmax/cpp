#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
	//[capture list] (parameter list) -> return type {function body}
	auto f = []{ return 100; };
	
	cout << f() << endl; 					//100
	cout << ([]{return 888;})() << endl; 	//888
	
	auto f2 = [](const string &s1, const string &s2){return s1.size() < s2.size();};
	
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
	
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	return 0;
}