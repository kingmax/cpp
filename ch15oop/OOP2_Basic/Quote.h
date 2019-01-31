#pragma once
#include <string>


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

private:
	std::string bookNo;

protected:
	double price = 0.0;
};
