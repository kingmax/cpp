#include <iostream>
#include <memory>
#include <set>
#include <string>
using namespace std;

//Page 560 (586/864)

class Quote
{
public:
	Quote() = default;
	Quote(const string& book, double price) : bookNo(book), price(price) {}
	
	Quote(const Quote&) = default;
	Quote(Quote&&) = default;

	Quote& operator=(const Quote&) = default;
	Quote& operator=(Quote&&) = default;

	string isbn() const
	{
		return bookNo;
	}

protected:
	double price;

private:
	string bookNo;
};