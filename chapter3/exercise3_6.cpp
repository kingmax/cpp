#include <iostream>
#include <string>
using namespace std;

int main()
{
	//3.6
	string s = "Hello, World!";
	for(auto &c : s)
		c = 'X';
	cout << s << endl;
	
	//3.7
	for(char &c : s)
		c = '*';
	cout << s << endl;
	
	//3.8
	for(decltype(s.size()) i = 0; i != s.size(); ++i)
		s[i] = 'x';
	cout << s << endl;
	
	decltype(s.size()) n = 0;
	while(n != s.size())
	{
		s[n] = '$';
		++n;
	}
	cout << s << endl;
	
	//3.10
	string input, output="";
	getline(cin, input);
	if(!input.empty())
		for(const auto &c : input)
			if(!ispunct(c))
				output += c;
		cout << output << endl;
		
	//3.11
	const string s1 = "Keep out!";
	for(auto &c : s1)
	{
		cout << c << endl;
		//c = 'e'; //const char can't changed
	}
	
	return 0;
}