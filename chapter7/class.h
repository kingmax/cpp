#ifndef __CLASS_H__
#define __CLASS_H__

#include <string>
#include <iostream>

class Books_data
{
	friend std::istream &input(std::istream&, Books_data&);
	friend std::ostream &output(std::ostream&, const Books_data&);
	friend Books_data add(const Books_data&, const Books_data&);
	
	private:
		std::string bookNo;
		unsigned sold = 0;
		double revenue = 0.0;
		
	public:
		//constructor
		Books_data() = default;
		Books_data(std::string isbn, unsigned n, double price) :
			bookNo(isbn), sold(n), revenue(price*n){}
		Books_data(std::istream&);
		Books_data(std::string isbn) : bookNo(isbn){}
		
		//methods
		inline std::string isbn() const { return bookNo; }
		
		Books_data &combine(const Books_data &item)
		{
			this->sold += item.sold;
			this->revenue += item.revenue;
			return *this;
		}
		
		double avg_price() const
		{
			if(sold)
				return revenue / sold;
			else
				return 0;
		}
};

std::istream &input(std::istream &is, Books_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.sold >> price;
	item.revenue = price * item.sold;
	return is;
}

std::ostream &output(std::ostream &os, const Books_data &item)
{
	os << item.isbn() << ' ' << item.sold << ' '
	   << item.revenue << ' ' << item.avg_price();
	return os;
}

Books_data add(const Books_data &lhs, const Books_data &rhs)
{
	Books_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

//constructor
Books_data::Books_data(std::istream &is)
{
	input(is, *this);
}


#endif