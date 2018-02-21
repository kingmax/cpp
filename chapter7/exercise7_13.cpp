#include "Book_sales.h"
using namespace std;

int main()
{
	//0-201-78345-x 3 20.00
	cout << "Enter:isbn sold price" << endl;
	Book_sales total(cin);
	if(!total.isbn().empty())
	{
		//print(cout, total);
		Book_sales trans;
		while(read(cin, trans))
		{
			if(trans.isbn() == total.isbn())
				total.combine(trans);
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