#include <iostream>
#include <string>
using namespace std;

string &myReplace(string &s, const string &oldVal, const string &newVal)
{
	auto sz = oldVal.size();
	for(auto beg = oldVal.cbegin(); beg != oldVal.cend(); ++beg)
	{
		auto b = s.begin();
		while(s.end() - b >= sz)
		{
			auto sub = b + sz;
			if(*b == *beg && string(b, sub) == oldVal)
			{
				s.erase(b, sub);
				b = s.insert(b, newVal.cbegin(), newVal.cend());
				//break;
			}
			++b;
		}
	}
	
	return s;
}

//exercise 9.44
string &myReplace2(string &s, const string &oldVal, const string &newVal)
{
	string::size_type sz = oldVal.size();
	for(string::size_type i = 0; s.size() - i >= sz; ++i)
	{
		if(s.substr(i, sz) == oldVal)
		{
			s.replace(i, sz, newVal);
			i += sz;
		}
	}
	
	return s;
}

int main()
{
	string s1 = "tho string";
	cout << s1 << endl;
	cout << myReplace(s1, "tho", "though") << endl << endl;

	string s2 = "thru other string";
	cout << s2 << endl;
	cout << myReplace(s2, "thru", "through") << endl << endl;
	
	string s3 = "tho string tho ";
	cout << myReplace(s3, "tho", "though") << endl << endl;
	
	string s4 = "thru other string, thru end.";
	cout << myReplace(s4, "thru", "through") << endl << endl;
	
	
	//[] and replace
	cout << "myReplace2 using [] & replace" << endl;
	string s5 = "tho string tho ";
	cout << myReplace2(s5, "tho", "though") << endl;
	
	string s6 = "thru other string, thru end.";
	cout << myReplace2(s6, "thru", "through") << endl;
	
	return 0;
}