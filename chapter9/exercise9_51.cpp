#include <iostream>
#include <string>
using namespace std;

class Date
{
	unsigned year, month, day;
	
	public:
		Date() = default;
		Date(const string &);
};

Date::Date(const string &s)
{
	// January 1, 1900
	// 1/1/1990
	// Jan 1 1900
	
}

ostream &print(ostream &os, const Date &d)
{
	os  << "Year: " << d.year
		<< "Month: " << d.month
		<< "Day: "	<< d.day << endl;
	return os;
}

int main()
{
	Date da("January 1, 1900");
	Date db("1/1/1990");
	Date dc("Jan 1 1900");
	
	
	
	return 0;
}