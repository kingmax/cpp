#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> vi = {"1", "3", "5", "7", "9"};
	int sum = 0;
	for(const string &s : vi)
	{
		sum += stoi(s);
	}
	cout << sum << endl; //25
	
	vector<string> vi2 = {"0.1", "2.2", "3.3"};
	double d = 0;
	for(const auto &s : vi2)
		d += stod(s);
	cout << d << endl; //5.6
	
	return 0;
}