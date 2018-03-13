#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//exercise10.15
int add_10(int i)
{
	auto f = [i](int n){return i + n;};
	return f(10);
}

void make_unique(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

//exercise10.16
void biggies(vector<string> &words, unsigned len)
{
	make_unique(words);
	
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
	
	auto p = find_if(words.begin(), words.end(), [len](const string &w){return w.size() >= len;});
	cout << words.end() - p << " word(s) of length " << len << " or longer:" << endl;
	for_each(p, words.end(), [](const string &w){cout << w << ' ';});
}

//exercise10.18
void biggies2(vector<string> &words, unsigned len)
{
	make_unique(words);
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
	auto p = partition(words.begin(), words.end(), [len](const string &w){return w.size() < len;});
	cout << /* p - words.begin() */ words.end() - p << " word(s) which length equals or greater than " << len << endl;
	for_each(/* words.begin(), p, */ p, words.end(), [](const string &w){cout << w << ' ';});
}

//exercise10.19
void biggies3(vector<string> &words, unsigned len)
{
	make_unique(words);
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
	auto p = stable_partition(words.begin(), words.end(), [len](const string &w){return w.size() < len;});
	cout << words.end() - p << " word(s) which length equals or greater than " << len << endl;
	for_each(p, words.end(), [](const string &w){cout << w << ' ';});
}

void split(const string &txt, vector<string> &outVec, const string &keyword=" ")
{
	string::size_type pos = 0;
	string::size_type init= 0;
	while((pos = txt.find(keyword, init)) != string::npos)
	{
		outVec.push_back(txt.substr(init, pos - init));
		init = pos + 1;
	}
	outVec.push_back(txt.substr(init, -1));
	/* cout << (pos == string::npos ? "pos==string::npos" : "pos!=string::npos") 
		 << ", init pos:" << init << ", outVec size:" << outVec.size() << endl; */
}



int main()
{
	auto sum = [](int a, int b){return a+b;};
	int i = sum(10, 90);
	cout << i << endl;
	
	//exercise10.15
	int x = add_10(i);
	cout << x << endl;
	
	//exercise10.16
	string theStoryContent = "the quick red fox jumps over the slow red turtle";
	vector<string> words;
	cout << words.size() << endl;
	split(theStoryContent, words);
	cout << words.size() << endl;
	for_each(words.cbegin(), words.cend(), [](const string &word){cout << word << ' ';});
	
	cout << "\nafter unique" << endl;
	make_unique(words);
	for(const auto &w : words)
		cout << w << ' ';
	cout << endl;
	
	cout << "\nafter stable_sort" << endl;
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
	for_each(words.cbegin(), words.cend(), [](const string &w){cout << w << ' ';});
	
	//test biggies
	cout << endl;
	split(theStoryContent, words);
	biggies(words, 4);
	
	//test biggies2
	cout << endl;
	split(theStoryContent, words);
	biggies2(words, 4);
	cout << endl;
	
	//test biggies3
	split(theStoryContent, words);
	biggies3(words, 4);
	cout << endl;
	
	return 0;
}