#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	string s2=s1;
	string s3(s2);
	string s4("hi");
	string s5{"hi"};
	string s6 = "hi";
	string s7(10, 'c');
	string s8 = "hello, "
				"world!";
	cout << s1 << ' ' << s2 << ' ' << s3 << ' '
		 << s4 << ' ' << s5 << ' ' << s6 << ' '
		 << s7 << ' ' << s8 << endl;
	
	cout << (s4 == s5) << ' ' << (s5 == s6) << endl; //1 1
	cout << (s7 > s8) << endl; //0
	cout << s1.empty() << endl; //1
	cout << s8.size() << endl; //13
	
	cin >> s1;
	cout << s1 << endl;
	
	cout << "cin word\n";
	string word;
	while(cin >> word)
		if("q" != word)
			cout << word << endl;
		else
		{
			cout << "quit cin word" << endl;
			break;
		}
	
	cout << "cin line\n";
	string line;
	while(getline(cin, line))
	{
		if(line == "q" || line == "Q")
			break;
		if(!line.empty())
		{	
			cout << line << endl;
			cout << "line.size: " << line.size() << endl;
		}
	}
	return 0;
}