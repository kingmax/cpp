#include "std_lib_facilities.h"

int main()
{
	cout << "Hello, World!\n";
	
	string first_name = "???";
	int age = -1;
	cout << "enter your first name and age" << endl;
	cin >> first_name;
	cin >> age;
	cout << "Hello, " << first_name << " (age " << age << ")" << endl;
	
	keep_window_open();
	return 0;
}