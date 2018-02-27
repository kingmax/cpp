#include <iostream>
#include <string>
using namespace std;

istream &func(istream &is)
{
	auto state = is.rdstate();
	is.clear();
	string s;
	while(!is.eof())
	{
		is >> s;
		cout << s << endl << endl;
	}
	is.setstate(state);
	return is;
}

int main()
{
	cout << "enter some data:" << flush;
	func(cin);
	
	return 0;
}