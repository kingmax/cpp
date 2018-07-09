#include <iostream>
#include <string>
using namespace std;

char* concate(string& a, string& b);

int main()
{
	string s1 = "Hello ", s2 = "world";
	char* dynamicCharArray = concate(s1, s2);
	cout << dynamicCharArray << endl;
	delete[] dynamicCharArray;
	
	cout << "s1 + s2 = " << s1 + s2 << endl;
	
	return 0;
}

char* concate(string& a, string& b)
{
	char* arr = new char[a.length() + b.length()]();
	strcat(arr, a.c_str());
	strcat(arr, b.c_str());
	return arr;
}