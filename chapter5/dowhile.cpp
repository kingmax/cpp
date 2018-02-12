#include <iostream>
#include <string>
using namespace std;

int main()
{
	string rsp;
	do
	{
		cout << "please enter two values: ";
		int v1 = 0, v2 = 0;
		cin >> v1 >> v2;
		cout << "The sum of " << v1 << " and " << v2
			 << " = " << v1 + v2 << "\n\n"
			 << "More? Enter yes or no: ";
		cin >> rsp;
	}
	while(!rsp.empty() && rsp[0] != 'n');
	cout << endl;
	
	string a, b;
	do
	{
		cout << "enter 2 strings:";
		cin >> a >> b;
		cout << (a.size() < b.size() ? a : b) << endl;
	}
	while(a != "q");
	
	return 0;
}