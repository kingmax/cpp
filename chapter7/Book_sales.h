//exercise7.2
#ifndef BOOK_SALES_H
#define BOOK_SALES_H

#include <string>
#include <iostream>


struct Book_sales
{
	//data
	std::string bookNo = "";
	unsigned sold = 0;
	double revenue= 0.0;
	
	//constructor
	//Book_sales() = default;
	Book_sales(const std::string &isbn) : bookNo(isbn) {}
	Book_sales(const std::string &isbn, unsigned count, double price) :
				bookNo(isbn), sold(count), revenue(price * count) {}
	//Book_sales(std::istream &is) //implemetation outside
	//exercise7.12
	Book_sales(std::istream &is)
	{
		//read(is, *this);
		double price;
		is >> bookNo >> sold >> price;
		this->revenue = sold * price;
	}
	//exercise7.14
	Book_sales() : bookNo(""), sold(0), revenue(0.0) { std::cout << "call another default constructor" << std::endl; }
	
	//methods
	std::string isbn() const
	{
		return bookNo;
	}
	
	Book_sales &combine(const Book_sales &rhs)
	{
		sold += rhs.sold;
		revenue += rhs.revenue;
		return *this;
	}
	
	double avg_price() const;
};

//implementation outside class, struct
double Book_sales::avg_price() const
{
	if(this->sold)
		return revenue / sold;
	else
		return 0;
}

std::istream &read(std::istream &is, Book_sales &item)
{
	double price(0);
	is >> item.bookNo >> item.sold >> price;
	item.revenue = item.sold * price;
	return is;
}

std::ostream &print(std::ostream &os, const Book_sales &item)
{
	os << item.isbn() << ' ' << item.sold << ' ' 
	   << item.revenue << ' ' << item.avg_price();
	return os;
}

Book_sales add(const Book_sales &lhs, const Book_sales &rhs)
{
	Book_sales sum = lhs; //copy constructor
	sum.combine(rhs);
	return sum;
}

//constructor implementation
/* Book_sales::Book_sales(std::istream &is)
{
	read(is, *this); //call read function
} */

#endif