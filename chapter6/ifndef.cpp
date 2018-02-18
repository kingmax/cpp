#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

void print(const int ia[], size_t size)
{
	//cl /EHsc /D NDEBUG
	#ifndef NDEBUG
		cerr << __func__ << ": array size is " << size << endl;
	#endif
	while(size > 0)
	{
		cout << ia[--size] << ' ';
	}
	cout << endl;
}

int main()
{
	int iarr[3] = {1,2,3};
	print(iarr, sizeof(iarr)/sizeof(int));
	
	string input;
	cin >> input;
	assert(input.size() > 2);
	
	if(input.size() > 5)
		cerr << "Error: " << __FILE__
			 << " : in function " << __func__
			 << " at line " << __LINE__ << endl
			 << "		 Compiled on " << __DATE__
			 << " at " << __TIME__ << endl
			 << "		 Input read was \"" << input
			 << "\": Length too long(>5)" << endl;
	
	
	return 0;
}