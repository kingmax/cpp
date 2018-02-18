//assert
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//#define NDEBUG //close assert! OR cl /EHsc /D NDEBUG xxx.cpp

int main()
{
	string input;
	cin >> input;
	
	//complier with /D NDEBUG, close assert!
	//cl /EHsc /D NDEBUG assert.cpp
	
	//or using #define NDEBUG
	#ifndef NDEBUG
	assert(input.size() > 3); //if true do nothing!
	cerr << __func__ << endl;
	#endif
	
	cout << input << endl;

	return 0;
}