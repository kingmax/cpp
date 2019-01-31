#pragma once
#include <string>
#include <iostream>

class Quote
{
public:
	Quote() = default;

	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price)
	{

	}

	std::string isbn() const 
	{ 
		return bookNo; 
	}

	virtual double net_price(std::size_t n) const
	{
		return n * price;
	}

	// 通常基类都应该定义一个虚析构函数！
	virtual ~Quote() = default;

	// 15.11, page539(565/864)
	virtual void debug() const
	{
		std::cout << "private.bookNo: " << bookNo
			<< " protected.price: " << price
			<< std::endl;
	}

private:
	std::string bookNo;

protected:
	double price = 0.0;
};
