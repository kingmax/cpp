#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string s("Hello, World!!!");
	decltype(s.size()) punctuation_cnt = 0;
	for(auto c : s)
	{
		if(ispunct(c))
			++punctuation_cnt;
	}
	cout << punctuation_cnt << " punctuation characters in "
		 << s << endl;
	
	//toupper
	for(auto &c : s)
		c = toupper(c);
	cout << s << endl;
	
	//tolower
	if(!s.empty())
		s[0] = tolower(s[0]);
	cout << s << endl;
	
	auto len = s.size();
	for(int i=0; i<len; ++i)
		s[i] = tolower(s[i]);
	cout << s << endl;
	
	for(decltype(s.size()) index=0; index != s.size() && !isspace(s[index]); ++index)
		s[index] = toupper(s[index]);
	cout << s << endl;
	
	return 0;
}