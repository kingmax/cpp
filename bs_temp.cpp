#include "std_lib_facilities.h"

int main()
{
	double x;
	string s;
	while(cin >> x && (cin >> s) && s != "|")
		cout << x << " " << s << endl;
	
	return 0;
}