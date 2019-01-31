#pragma once
#include "Quote.h"
#include <string>

class Bulk_Quote : public Quote
{
public:
	Bulk_Quote() = default;

	Bulk_Quote(const std::string&, double, std::size_t, double);

	double net_price(std::size_t) const override;

	// 15.11, page539(565/864)
	virtual void debug() const override final;

private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};
