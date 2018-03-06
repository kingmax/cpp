#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<char> vc = {'H', 'e', 'l', 'l', 'o'};
	string s(&vc[0], 5);
	cout << s << endl;
	
	string s2;
	s2.assign(vc.cbegin(), vc.cend());
	cout << s2 << endl;
	
	return 0;
}