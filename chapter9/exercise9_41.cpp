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
	
	string s3("hello, world");
	cout << s3 << endl;
	auto b = s3.begin();
	s3.erase(b, b+6);
	cout << s3 << endl;
	//s3.insert(b, "hello"); //error, no memer function!!!
	s3.insert(b, vc.cbegin(), vc.cend());
	cout << s3 << endl;
	
	return 0;
}