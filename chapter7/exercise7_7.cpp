#include "Book_sales.h"
using namespace std;

int main()
{
	Book_sales total;
	print(cout, total) << endl;
	
	cout << "Enter: isbn count price" << endl;
	//0-201-78345-x 3 20.00
	
	if(read(cin, total))
	{
		Book_sales trans;
		while(read(cin, trans))
		{
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	
	/* cout << "\ntest read(read(cin, bs1), bs2)" << endl;
	Book_sales bs1, bs2;
	if(read(read(cin, bs1), bs2))
	{
		print(print(cout, bs1), bs2) << endl;
	}
	cout << endl; */
	
	return 0;
}