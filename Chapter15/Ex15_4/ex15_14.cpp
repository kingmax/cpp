#include <string>
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string& _isbn, double _price) : __isbn(_isbn), price(_price) {}
	virtual ~Quote() = default;

	string isbn() const { return __isbn; }

protected:
	double price;

private:
	string __isbn;
};

class Disc_quote : public Quote
{
protected:
	size_t quantity = 0;
	double discount = 0.0;

public:
	Disc_quote() = default;
	Disc_quote(const string& book, double price, size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc) {}

	virtual double net_price(size_t) const = 0; //pure virtual
};

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double price, size_t qty, double disc) :
		Disc_quote(book, price, qty, disc) {}

	double net_price(size_t) const override;
};

double Bulk_quote::net_price(size_t n) const
{
	if (n > quantity)
	{
		return price * n * (1 - discount);
	}
	else
	{
		return price * n;
	}
}

class A
{
private:
	string bookNo;
protected:
	double price;
	size_t quantity;
	double discount;

public:
	A() = default;
	A(const string& book, double price, size_t quantity, double discount) :
		bookNo(book), price(price), quantity(quantity), discount(discount) {}
	virtual ~A() = default;

	string isbn() const { return bookNo; }
	void debug() const
	{
		cout << "data member: bookNo=" << bookNo << " price=" << price << " quantity=" << quantity << " discount=" << discount << endl;
	}

	virtual double net_price(size_t) const = 0; //pure virtual
};

//double A::net_price(size_t n) const
//{
//	return price * n;
//}

class D : public A
{
public:
	D() = default;
	D(const string& book, double price, size_t quantity, double discount) :
		A(book, price, quantity, discount) {}

	double net_price(size_t) const override;
};

double D::net_price(size_t n) const
{
	if (n > quantity)
	{
		return n * price * (1 - discount);
	}
	else
	{
		return n * price;
	}
}

//Default Constructor, Copy Constructor, Assigment, Move, Deconstructor::
class Quote2
{
public:
	Quote2() = default;
	Quote2(const Quote2&) = default;
	Quote2(Quote2&&) = default;

	Quote2& operator=(const Quote2&) = default;
	Quote2& operator=(Quote2&&) = default;

	virtual ~Quote2() = default;

	Quote2(const string&, double, size_t, double);

private:
	string bookNo;
	
protected:
	double price;
	size_t quantity;
	double discount;
};

Quote2::Quote2(const string& book, double price, size_t quantity, double discount) :
	bookNo(book), price(price), quantity(quantity), discount(discount)
{}

class Disc_quote2 : public Quote2
{
public:
	//using 用于声明继承构造函数时，不会改变访问级别(即原来是private的仍然是private)
	//如果被继承构造函数带有默认参数的，继承将得到多个构造函数，没有默认参数
	using Quote2::Quote2; //gen Constructor for Derived Class (all base constructor function)
	
public:
	Disc_quote2(const string& book) : Quote2(book, 0, 0, 0) { }
};


//main
int main()
{
	Quote q;
	//Disc_quote dq;
	Bulk_quote bq("fun book", 10, 6, 0.2);
	cout << bq.net_price(10) << endl;

	cout << "class D : public A" << endl;
	//A a("a", 10, 10, 0.2);
	D d("book-d1-isbn", 20.5, 10, 0.25);
	d.debug();
	cout << d.net_price(20) << endl;

	Disc_quote2 d2("d2", 100, 10, 0.3);
	Disc_quote2 d3_ex("d3-extent");

	vector<shared_ptr<Quote>> basket;
	basket.push_back(make_shared<Quote>("0-201-82470-1", 50));
	basket.push_back(make_shared<Bulk_quote>("0-201-54848-8", 50, 10, 0.25));
	cout << basket.back()->isbn() << endl;

	getchar();
	return 0;
}