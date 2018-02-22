#include "Books_data.h"
using namespace std;

int main()
{
	cout << "Enter: isbn count price" << endl;
	Books_data total(cin);
	print(cout, total) << endl;
	
	if(!total.isbn().empty())
	{
		Books_data trans;
		while(read(cin, trans))
		{
			if(trans.isbn() == total.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	
	return 0;
}