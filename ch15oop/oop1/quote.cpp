#include <iostream>
#include <string>
using namespace std;

class Quote
{
public:
	string isbn() const;
	virtual double net_price(size_t n) const;
};

string Quote::isbn() const { return "isbn-123456"; }
double Quote::net_price(size_t n) const
{
	return 10.0 * n;
}

class Bulk_quote : public Quote
{
public:
	virtual double net_price(size_t) const override;
};

double Bulk_quote::net_price(size_t n) const
{
	return 5.0 * n;
}

double print_total(ostream &os,
	const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
		<< ret << endl;
	return ret;
}

int main(int argc, char **argv)
{
	Quote basic;
	Bulk_quote bulk;
	print_total(cout, basic, 20);
	print_total(cout, bulk, 20);

	return 0;
}