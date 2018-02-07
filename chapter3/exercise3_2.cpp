#include <iostream>
#include <string>
using namespace std;

int main()
{
	//3.2
	string input;
	while(getline(cin, input) && input != "q")
	{
		cout << input << endl;
	}
	//3.3 b
	while(cin >> input && input != "q")
	{
		cout << input << endl;
	}
	//3.4
	string a, b;
	cout << "please input 2 word" << endl;
	cin >> a >> b;
	if(a > b)
		cout << a << endl;
	else if(b > a)
		cout << b << endl;
	else
		cout << "a == b" << endl;
	//3.4 b
	auto len_a = a.size();
	auto len_b = b.size();
	if(len_a > len_b)
		cout << "a.size > b.size" << endl;
	else if(len_b > len_a)
		cout << "b.size > a.size" << endl;
	else
		cout << "a.size == b.size" << endl;
	//3.5
	string result{""}, result2="";
	while(cin >> input && input != "q")
	{
		result += input;
		result2 += " " + input;
	}
	cout << result << endl;
	cout << result2 << endl;
	
	return 0;
}