#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

//read, isbn, combine, print, add
/*
Sales_data total;
if(read(cin, total))
{
	Sales_data trans;
	while(read(cin, trans))
	{
		if(total.isbn() == trans.isbn())
			total.combine(trans);
		else
		{
			print(cout, total) << endl;
			total = trans; //reset and start next record
		}
	}
	print(cout, total) << end; //last record
}
else
{
	cerr << "No data?!" << endl;
}
*/

struct Sales_data
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	
	std::string isbn() const //const modifier make this to const => std::string isbn(const Sales_data *const this)
	{
		//return bookNo;	//also ok
		return this->bookNo;
	}
	
	double avg_price() const;
	Sales_data &combine(const Sales_data &);
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

//method implementation
double Sales_data::avg_price() const
{
	if(this->units_sold)
		return this->revenue / this->units_sold;
	else
		return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
	this->units_sold += rhs.units_sold;
	this->revenue += rhs.revenue;
	return *this;
}

#endif