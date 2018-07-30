#include <string>
#include <iostream>
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

	getchar();
	return 0;
}