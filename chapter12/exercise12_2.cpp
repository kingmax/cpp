#include "exercise12_2.h"
#include <iostream>
using namespace std;

int main()
{
	BlobStr b1;
	{
		/* BlobStr b2 = {"a", "an"}; */ //Error, explicit ctor cann't do this "copy init"
		BlobStr b2{"a", "b"};
		
		b1 = b2;
		b2.push_back("the");
		
		cout << b1.size() << ' ' << b2.size() << endl;
	}
	cout << b1.size() << endl;
	
	
	
	return 0;
}