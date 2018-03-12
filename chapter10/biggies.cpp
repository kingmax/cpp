#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	sort(words.begin(), words.end());
	auto pend = unique(words.begin(), words.end());
	words.erase(pend, words.end());
	
	stable_sort(words.begin(), words.end(), 
				[](const string &a, const string &b){return a.size() < b.size();});
				
	auto wc = find_if(words.begin(), words.end(), 
				[sz](const string &s){return s.size() >= sz;});
	
	auto count = words.end() - wc;
	cout << count << " word(s) of length " << sz << " or longer" << endl;
	
	for_each(wc, words.end(), 
				 [](const string &w){cout << w << ' ';});
				 
	cout << endl;
}

int main()
{
	string txt = "the quick red fox jumps over the slow red turtle";
	vector<string> words;
	string word;
	stringstream ss(txt);
	while(ss >> word)
		words.push_back(word);
	
	//cout << words.size() << endl;
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	cout << endl;
	biggies(words, 5);
	
	//for_each
	cout << "using for_each to output" << endl;
	for_each(words.cbegin(), words.cend(), [](const string &word){cout << word << ' ';});
	cout << endl;
	
	return 0;
}
