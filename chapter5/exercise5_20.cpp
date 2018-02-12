#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input, word="";
	while(cin >> input)
	{
		if(input == word && !word.empty())
		{
			cout << word << " occur 2 times" << endl;
			word = "";
		}
		else
			word = input;
	}
	
	return 0;
}