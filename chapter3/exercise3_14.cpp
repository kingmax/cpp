#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int input;
	vector<int> vi;
	while(cin >> input && input != 0)
		vi.push_back(input);
	for(int i : vi)
		cout << i << ' ';
	cout << endl;
	
	string input2;
	vector<string> vs;
	while(cin >> input2 && input2 != "q")
		vs.push_back(input2);
	for(auto s : vs)
		cout << s << ' ';
	cout << endl;
	
	return 0;
}