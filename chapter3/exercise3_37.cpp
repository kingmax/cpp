#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	const char cs[] = {'h', 'e', 'l', 'l', 'o'};
	const char *cp = cs;
	while(*cp)
	{
		cout << *cp << endl;
		++cp;
	}
	cout << endl;
	
	//3.39
	string s1 = "Hello";
	string s2 = "hello";
	if(s1 < s2)
		cout << "s1 < s2" << endl;
	else if(s1 > s2)
		cout << "s1 > s2" << endl;
	else
		cout << "s1 == s2" << endl;
	
	//3.39 b
	const char ca[] = "hello";
	const char cb[] = "Hello";
	int x = strcmp(ca, cb);
	if(x < 0)
		cout << "ca < cb" << endl;
	else if(x > 0)
		cout << "ca > cb" << endl;
	else
		cout << "ca == cb" << endl;
	
	//3.40
	char cc[11];
	strcpy(cc, ca);
	strcat(cc, cb);
	for(char c : cc)
		cout << c;
	cout << endl;
	
	const string s = "Hello, Jason!";
	const char *str = s.c_str();  //make string to char[]
	while(*str)
	{
		cout << *str << ' ';
		++str;
	}
	cout << endl;
	
	//3.41
	int iArr[] = {1,2,3,4,5};
	vector<int> iVec(begin(iArr), end(iArr));
	cout << iVec.size() << endl;
	for(int i : iVec)
		cout << i << ' ';
	cout << endl;
	vector<int> subVec(iArr+1, iArr+4);
	cout << subVec.size() << endl; //3
	for(int i : subVec)
		cout << i << ' ';
	cout << endl;
	
	//3.42
	cout << endl;
	const int n = 5;
	int arr2[n];
	for(int i = 0; i != n; ++i)
		arr2[i] = iVec[i];
	for(auto i : arr2)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}