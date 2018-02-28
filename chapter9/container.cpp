#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include <forward_list>
using namespace std;

int main()
{
	list<string> authors = {"Milton", "Shakespeare", "Austen"};
	vector<const char*> articles = {"a", "an", "the"};
	
	list<string> list2(authors);
	//deque<string> authList(authors); //error
	//vector<string> words(articles);  //error
	
	forward_list<string> words(articles.begin(), articles.end());
	for(auto w : words)
		cout << w << ' ';
	cout << endl;
	
	vector<int> ivec(10, -1);
	list<string> slist(10, "hi!");
	forward_list<int> ilist(10);
	deque<string> sque(10);
	
	
	return 0;
}