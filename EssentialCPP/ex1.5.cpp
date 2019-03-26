#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	
	do
	{
		cout << "input your name please: (q for exit)\n";
		
		cin >> name;
		if(name == "q")
			break;
		
		if(name.length() > 2)
		{
			cout << "welcome, " << name << endl;
			break;
		}
	}
	while(name.length() <= 2);
	
	char n[100];
	do
	{
		cout << "enter your name again: (q for exit)" << endl;
		
		//cin.getline(n, 20);
		cin >> n;
		//int len = sizeof(n) / sizeof(n[0]);	// 20
		//int len = size(n);					// 20
		int len = strlen(n);
		cout << len << endl;
		if(len == 1 && n[0] == 'q')
			break;
		else if (len > 2)
		{
			cout << "hello, " << n << endl;
			break;
		}
	}
	while(strlen(n) <= 2);
	
	return 0;
}
