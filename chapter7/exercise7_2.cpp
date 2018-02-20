#include <iostream>
#include <string>
#include "Book_sales.h"
using namespace std;

int main()
{
	Book_sales total;
	double price;
	
	cout << "Enter: isbn count price" << endl;
	//0-201-78345-x 3 20.00
	
	if(cin >> total.bookNo >> total.sold >> price)
	{
		total.revenue = total.sold * price;
		Book_sales trans;
		while(cin >> trans.bookNo >> trans.sold >> price)
		{
			trans.revenue = trans.sold * price;
			if(total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				cout << total.bookNo << ' ' << total.sold
					 << ' ' << total.revenue << endl;
				total.bookNo = trans.bookNo;
				total.sold = trans.sold;
				total.revenue = trans.revenue;
			}
		}
		cout << total.bookNo << ' ' << total.sold
			 << ' ' << total.revenue << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	
	return 0;
}