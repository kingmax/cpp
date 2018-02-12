#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int main()
{
	string input;
	
	//throw
	/* start:
	cin >> input;
	if(input == "e")
		throw runtime_error("raise error exception!");
	
	cout << input << endl;
	goto start; */
	
	while(cin >> input)
	{
		try
		{
			cout << input << endl;
			throw runtime_error("raise runtime_error exception!");
		}
		catch(runtime_error err)
		{
			cout << err.what()
				 << "\nTry Again? Enter y or n"
				 << endl;
				 
			char c;
			cin >> c;
			if(!cin || c == 'n')
				break;
		}
	}
	
	
	return 0;
}