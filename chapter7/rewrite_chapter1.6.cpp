#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

int main()
{
	//test const
	const int ci = 0;
	const int *const ptr = &ci;
	
	Sales_data total;
	double price;
	cout << "input sold book(s): isbn count price" << endl;
	//0-201-78345-x 3 20.00
	
	if(cin >> total.bookNo >> total.units_sold >> price)
	{
		total.revenue = total.units_sold * price;
		
		Sales_data trans;
		while(cin >> trans.bookNo >> trans.units_sold >> price)
		{
			if(trans.bookNo == total.bookNo)
			{
				total.units_sold += trans.units_sold;
				total.revenue += trans.units_sold * price;
			}
			else
			{
				cout << total.bookNo << ' ' << total.units_sold << ' '
					 << total.revenue << endl;
				//reset
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.units_sold * price;
			}
		}
		//last record
		cout << total.bookNo << ' ' << total.units_sold << ' '
			 << total.revenue << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	
	return 0;
}
