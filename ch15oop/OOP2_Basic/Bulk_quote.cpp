#include "Bulk_quote.h"

Bulk_Quote::Bulk_Quote(const std::string &book, double p,
	std::size_t qty, double disc) :
	Quote(book, p), min_qty(qty), discount(disc)
{

}

double Bulk_Quote::net_price(std::size_t n) const
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
