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
	
	//seq container methods:
	s.insert(s.size(), 5, '!'); //hello world!!!!!
	cout << s << endl;
	s.erase(s.size()-5, 5); //hello world
	cout << s << endl;
	
	const char *cp2 = "Stately, plump Buck";
	s.assign(cp2, 7); //Stately
	cout << s << endl;
	s.insert(s.size(), cp2+7); //Stately, plump Buck
	cout << s << endl;
	
	string sa = "some string", sb = "some other string";
	sa.insert(0, sb);
	cout << sa << endl;
	sa.insert(0, sb, 0, sb.size());
	cout << sa << endl;
	
	//append, replace
	string _s = "C++ Primer", __s = _s;
	_s.insert(_s.size(), " 4th Ed.");
	cout << _s << endl;
	__s.append(" 4th Ed."); 
	cout << __s << endl; //C++ Primer 4th Ed.
	
	_s.erase(11, 3);
	_s.insert(11, "5th");
	cout << _s << endl;
	__s.replace(11, 3, "5th"); //C++ Primer 5th Ed.
	cout << __s << endl;
	_s.replace(11, 3, "Fifth"); //C++ Primer Fifth Ed.
	cout << _s << endl;
	
	return 0;
}