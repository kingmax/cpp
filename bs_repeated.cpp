#include "std_lib_facilities.h"

int main()
{
	string previous = "";
	string current;
	while(cin >> current)
	{
		if(current == previous)
			cout << "repeated word: " << current << endl;
		previous = current;
	}
	return 0;
}