#include <iostream>
#include <list>
#include <deque>
#include <string>
#include <vector>
using namespace std;

string &upper(string &str)
{
	for(auto &c : str)
		c = toupper(c);
	return str;
}

int main()
{
	list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	deque<int> di1, di2;
	for(const auto &i : li)
		if(i % 2)
			di1.push_back(i);
		else
			di2.push_back(i);
		
	cout << "li.size = " << li.size() << endl
		 << "di1.size= " << di1.size() << endl
		 << "di2.size= " << di2.size() << endl;
		 
	for(const auto &i : di1)
		cout << i << ' ';
	cout << endl;
	
	for(const auto &i : di2)
		cout << i << ' ';
	cout << endl;
	
	//exercise 9.21
	list<string> lst;
	auto iter = lst.begin();
	string word;
	while(cin >> word && word != "q")
		iter = lst.insert(iter, word); //same as push_front
	
	for(const auto &s : lst)
		cout << s << ' ';
	cout << endl;
	
	vector<string> vs;
	auto it = vs.begin();
	while(cin >> word && word != "q")
		it = vs.insert(it, upper(word));
	
	for(const auto &s : vs)
		cout << s << ' ';
	cout << endl;
	
	return 0;
}