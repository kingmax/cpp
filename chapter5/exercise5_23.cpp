#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "enter 2 integer:" << endl;
	while(cin >> a >> b)
	{
		/* if(0 == b)
			throw runtime_error("a/b, b can't set to 0!"); */
		try
		{
			if(0 == b)
				throw runtime_error("a/b, b can't set to 0!");
			cout << "a / b = " << a / b << endl;
		}
		catch(runtime_error err)
		{
			cout << err.what() << endl;
			cout << "retry? enter y or n" << endl;
			
			char c;
			cin >> c;
			if(!cin || 'n' == c)
				break;
			cout << "enter 2 integer:" << endl;
		}
	}
	
	return 0;
}