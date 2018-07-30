#include <string>
#include <iostream>
using namespace std;

class Quote
{
private:
	string bookNo;

protected:
	double price = 0.0;

public:
	Quote() = default;
	Quote(const string& book, double sales_price) : bookNo(book), price(sales_price) {}
	string isbn() const { return bookNo; }

	virtual double net_price(size_t n) const
	{
		return n * price;
	}

	virtual void fn() const { cout << "virtual function in base class" << endl; }

	virtual void debug() const;

	virtual ~Quote() = default;
};

void Quote::debug() const
{
	cout << "Quote data member: bookNo=" << bookNo << " price=" << price << endl;
}


class Bulk_quote : public Quote
{
private:
	size_t min_qty = 0;
	double discount = 0.0;
public:
	Bulk_quote() = default;
	Bulk_quote(const string&, double, size_t, double);

	double net_price(size_t n) const override;

	void fn() const final { cout << "final method" << endl; }

	void debug() const override;
};

Bulk_quote::Bulk_quote(const string& book, double price, size_t qty, double disc) :
	Quote(book, price), min_qty(qty), discount(disc)
{

}

double Bulk_quote::net_price(size_t n) const
{
	if (n >= min_qty)
	{
		return n * (1 - discount) * price;
	}
	else
	{
		return n * price;
	}
}

void Bulk_quote::debug() const
{
	cout << "Bulk_quote data member: bookNo=" << isbn() << " price=" << price << " min_qty=" << min_qty << " discount=" << discount << endl;
}


//ex15.3
void print_total(const Quote& item, size_t n)
{
	double total = item.net_price(n);
	cout << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << total << endl;
}

//static member
class Base
{
public:
	static void statmem();
};

void Base::statmem()
{
	cout << "static member" << endl;
}

class Derived : public Base
{
public:
	void f(const Derived&) const;
};

void Derived::f(const Derived&) const
{
	Base::statmem();
	Derived::statmem();
	Derived dObj;
	dObj.statmem();
	statmem(); //this
	this->statmem();
}

//No derived
class NoDerived final
{
public:
protected:
private:
};

class Last final : Base
{};


//main
int main()
{
	Derived d;
	d.f(d);

	Quote q("isbn-123-456", 100.0);
	Bulk_quote bq("123-321-isbn", 100.0, 5, 0.2);
	q.debug();
	cout << q.net_price(8) << endl;

	bq.debug();
	cout << bq.net_price(8) << endl;

	getchar();
	return 0;
}

