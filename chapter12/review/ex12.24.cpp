#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "How long do you want the string?" << endl;
	int size(0);
	cin >> size;
	char* input = new char[size+1]();
	cin.ignore();
	cout << "input the string:" << endl;
	cin >> input;
	//cin.get(input, size+1);
	
	cout << input << endl;
	
	delete[] input;
	
	cout << "input some string" << endl;
	//prepare allocator
	string *const p = new string[10];
	string s;
	string *q = p;
	while(cin >> s && q != p+10)
		*q++ = s;
	const size_t x = q - p;
	delete [] p;
	cout << x << endl;
	
	return 0;
}