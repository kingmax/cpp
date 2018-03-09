#include <string>
#include <iostream>
using namespace std;

string combine(const string &name, const string &prefix, const string &suffix)
{
	string s = name;
	s.insert(s.cbegin(), prefix.cbegin(), prefix.cend());
	s.append(suffix);
	return s;
}

//exercise 9.46
string combine2(const string &name, const string &prefix, const string &suffix)
{
	string s = name;
	s.insert(0, prefix);
	s.insert(s.size(), suffix);	
	return s;
}

int main()
{
	string name = "Jason";
	cout << combine(name, "Mr. ", " Jr.") << endl;
	
	cout << combine2(name, "Mr. ", " Jr.") << endl;
	
	return 0;
}