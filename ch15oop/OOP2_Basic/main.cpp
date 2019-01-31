#include "Quote.h"
#include "Bulk_quote.h"
#include <iostream>
#include <string>
using namespace std;

ostream &print_total(ostream &os, const Quote &quote, size_t n)
{
	double total = quote.net_price(n);
	os << "ISBN: " << quote.isbn()
		<< " # sold: " << n
		<< " total due: " << total
		<< endl;
	return os;
}

int main()
{
	Quote base("0-201-82470-1", 50);
	print_total(cout, base, 10);
	base.debug();

	cout << endl;
	Bulk_Quote derived("0-201-82470-2", 50, 5, 0.19);
	print_total(cout, derived, 10);
	derived.debug();

	return 0;
}