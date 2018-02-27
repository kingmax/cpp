#ifndef __BOOKS_DATA_H__
#define __BOOKS_DATA_H__

#include <iostream>
#include <string>

class Books_data
{
	private:
		std::string bookNo;
		unsigned sold = 0;
		double revenue = 0.0;
		
	public:
		Books_data() = default;
		Books_data(std::string s, unsigned n, double p) : bookNo(s), sold(n), revenue(n*p){}
		explicit Books_data(std::string s) : Books_data("", 0, 0){}
		explicit Books_data(std::istream &is) : Books_data(""){ input(is, *this); }
		
		std::string isbn() const { return this->bookNo; }
		double avg_price() const { return sold ? revenue/sold : 0; }
		Books_data &combine(const Books_data&);
		
	friend Books_data add(const Books_data&, const Books_data&);
	friend std::istream &input(std::istream&, Books_data&);
	friend std::ostream &output(std::ostream&, const Books_data&);
};

Books_data &Books_data::combine(const Books_data &rhs)
{
	this->sold += rhs.sold;
	this->revenue += rhs.revenue;
	return *this;
}

Books_data add(const Books_data &lhs, const Books_data &rhs)
{
	Books_data sum = lhs;
	return sum.combine(rhs);
}

std::istream &input(std::istream &is, Books_data &item)
{
	double price;
	is >> item.bookNo >> item.sold >> price;
	item.revenue = item.sold * price;
	return is;
}

std::ostream &output(std::ostream &os, const Books_data &item)
{
	os << item.isbn() << ' ' << item.sold << ' ' << item.revenue << ' ' << item.avg_price();
	return os;
}


#endif