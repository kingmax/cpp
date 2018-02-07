#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "hello", s2 = "world";
	string s3 = s1 + ", " + s2 + '\n';
	cout << s3 << endl;
	
	string s4 = s1 + ", ";
	//string s5 = "hello" + ", "; //error, literal is char[] (ptr point to char, same as C language, cant't +)
	string s6 = s1 + ", " + "world"; //ok, can string + literal OR literal + string
	cout << s6 << endl;
	
	string s7 = "hello" + ", " + s2; //error
	
	return 0;
}