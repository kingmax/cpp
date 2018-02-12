#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	
	begin:
		cin >> input;
		if(input != "q")
		{
			cout << input << endl;
			goto begin;
		}
	
	cout << "end" << endl;
		
	return 0;
}