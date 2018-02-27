#include <iostream>
#include <string>
using namespace std;

istream &fn(istream &input)
{
	auto state = input.rdstate();
	input.clear();
	string s;
	while(!input.eof())
	{
		input >> s;
		cout << s << endl;
	}
	input.setstate(state);
	return input;
}

int main()
{
	cout << "input data" << endl;
	fn(cin);
	
	cout << unitbuf;
	cout << nounitbuf;
	
	cin.tie(&cout);
	ostream *old_tie = cin.tie(nullptr);
	cin.tie(&cerr);
	cin.tie(old_tie);
	
	return 0;
}