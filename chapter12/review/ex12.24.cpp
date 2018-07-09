#include <iostream>
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
	
	return 0;
}