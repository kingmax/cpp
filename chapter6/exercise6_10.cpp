#include <iostream>
#include <string>
using namespace std;

//ptr version
void swap(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

//reference version
void swap2(int &pa, int &pb)
{
	int temp = pa;
	pa = pb;
	pb = temp;
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size(); //return first occur char
	occurs = 0;
	for(decltype(ret) i=0; i!=s.size(); ++i)
	{
		if(s[i] == c)
		{
			++occurs;
			if(ret == s.size())
				ret = i; //first occur
		}
	}
	return ret;
}

int main()
{
	int a=10, b=20;
	cout << a << ' ' << b << endl;
	swap(&a, &b);
	cout << a << ' ' << b << endl;
	swap2(a, b);
	cout << a << ' ' << b << endl;
	
	string s1 = "hi", s2 = "hello";
	cout << s1 << " < " << s2 << "?(shorter) " 
		 << (isShorter(s1, s2) ? "true" : "false")
		 << endl;
	
	cout << endl;
	string s = "welcome, jason";
	string::size_type x, y;
	x = find_char(s, 'e', y);
	cout << x << ' ' << y << endl;
	
	return 0;
}