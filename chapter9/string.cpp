#include <iostream>
#include <string>
using namespace std;

int main()
{
	const char *cp = "Hello World!!!";
	char noNull[] = {'H', 'i'};
	
	//string constructor:
	string s1(cp);
	cout << s1 << endl;
	string s2(noNull, 2); //Hi
	cout << s2 << endl;
	/* string s3(noNull);	//error, undefined noNull end char*
	cout << s3 << endl; */
	
	string s4(cp + 6, 5); //World
	cout << s4 << endl;
	string s5(s1, 6, 5); //World
	cout << s5 << endl;	
	
	string s6(s1, 6); 	//World!!!
	cout << s6 << endl;
	
	string s7(s1, 6, 600); //World!!!
	cout << s7 << endl;
	
	/* string s8(s1, 16);	//error
	cout << s8 << endl; */
	
	cout << endl;
	//substr
	string s("hello world");
	s2 = s.substr(0, 5); //hello
	cout << s2 << endl;
	string s3 = s.substr(6);	 //world
	cout << s3 << endl;
	s4 = s.substr(6, 11);//world
	cout << s4 << endl;
	//s5 = s.substr(12);	 //error
	
	
	return 0;
}