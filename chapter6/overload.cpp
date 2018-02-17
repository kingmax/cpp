#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(const char *p);
void print(const int *beg, const int *end);
void print(const int ia[], size_t size);

void print(const char *p)
{
	while(*p)
		cout << *p++ << ' ';
	cout << endl;
}
void print(const int *beg, const int *end)
{
	while(beg != end) //move pointer
		cout << *beg++ << ' ';
	cout << endl;
}
void print(const int ia[], size_t size)
{
	for(size_t i = 0; i != size; ++i)
		cout << ia[i] << ' ';
	cout << endl;
}

const string &shorterString(const string &s1, const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2)
{
	/* const string &sa = s1;
	const string &sb = s2;
	auto &r = shorterString(sa, sb); */
	const string &r = shorterString(const_cast<const string&>(s1),
							const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

//default param
void log(int x = 0)
{
	cout << x << endl;
}

int main()
{
	cout << "call print(char *p) [c-style string]" << endl;
	print("Hello, World!");
	string str = "Hi, Jason!";
	print(str.c_str());
	
	cout << "\ncall print(const int *begin, const int *end)" << endl;
	int iArr[] = {0, 1, 2};
	cout << begin(iArr) << endl; //begin, end is ptr point to Array first, last+1 element!!!
	print(iArr, end(iArr));
	//cout << endl;
	print(begin(iArr), end(iArr));
	
	cout << "\ncall print(const int array[], size_t size)" << endl;
	print(iArr, end(iArr) - begin(iArr));
	
	cout << endl;
	string s1 = "string", s2 = "str";
	string &ss = shorterString(s1, s2);
	cout << ss << endl;
	
	cout << endl;
	const string cs1 = "stream", cs2 = "stringg";
	//string &_s = shorterString(cs1, cs2); //error, cann't cast const string to string
	cout << "\ncall string version(No const):" << endl;
	string &_s = shorterString(const_cast<string&>(cs1),
							   const_cast<string&>(cs2));
	cout << _s << endl;
	
	cout << "\ncall const version:" << endl;
	const string &cs = shorterString(cs1, cs2);
	cout << cs << endl;
	
	cout << "\ntest default param function:" << endl;
	log();
	log(100);
	
	return 0;
}