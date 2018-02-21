#ifndef __BOOKS_DATA_H__
#define __BOOKS_DATA_H__

#include <string>
#include <iostream>

class Books_data
{
	friend Books_data add(const Books_data&, const Books_data&);
	friend std::istream &read(std::istream&, Books_data&);
	friend std::ostream &print(std::ostream&, const Books_data&);
	
	private:
		std::string bookNo;
		unsigned sold = 0;
		double revenue = 0.0;
		double avg_price() const
		{
			return sold ? revenue / sold : 0;
		}
		
	public:
		Books_data() = default;
		Books_data(const std::string &isbn) : bookNo(isbn){}
		Books_data(const std::string &isbn, unsigned count, double price) :
					bookNo(isbn), sold(count), revenue(price * count){}
		Books_data(std::istream&);
		std::string isbn() const { return bookNo; }
		Books_data &combine(const Books_data&);
};

//friend
Books_data add(const Books_data &lhs, const Books_data &rhs)
{
	Books_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::istream &read(std::istream &is, Books_data &item)
{
	double price(0);
	is >> item.bookNo >> item.sold >> price;
	item.revenue = item.sold * price;
	return is;
}

std::ostream &print(std::ostream &os, const Books_data &item)
{
	os << item.bookNo << ' ' << 
	return os;
}

Books_data::Books_data(std::istream &is)
{
	
}

Books_data& Books_data::combine(const Books_data &rhs)
{
	this->sold += rhs.sold;
	this->revenue += rhs.revenue;
	return *this;
}

#endif