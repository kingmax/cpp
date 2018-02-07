#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> vi;
	for(int i = 0; i != 100; ++i)
		vi.push_back(i);
	for(int i : vi)
		cout << i << ' ';
	cout << endl;
	
	string word;
	vector<string> text;
	while(cin >> word && word != "q")
		text.push_back(word);
	for(auto txt : text)
		cout << txt << ' ';
	cout << endl;
	
	return 0;
}