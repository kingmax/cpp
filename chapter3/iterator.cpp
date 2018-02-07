#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s("some string");
	cout << s << endl;
	if(s.begin() != s.end())
	{
		auto it = s.begin();
		*it = toupper(*it);
	}
	cout << s << endl;
	
	for(auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
		*it = toupper(*it);
	cout << s << endl;
	
	vector<string> text = {"hi", "jason", "welcom", "", "section2"};
	for(auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
		cout << *it << endl;
	
	return 0;
}