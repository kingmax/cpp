#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
	friend istream &read(istream&, Sales_data&);
	friend ostream &print(ostream&, const Sales_data&);
	
	public:
		Sales_data() = default;
		Sales_data(string s, unsigned n, double price) :
			bookNo(s), sold(n), revenue(n*price){}
		//Sales_data() : Sales_data("", 0, 0){}
		explicit Sales_data(string s) : Sales_data(s, 0, 0){}
		explicit Sales_data(istream &is) : Sales_data() { read(is, *this); }
		
	private:
		string bookNo;
		unsigned sold = 0;
		double revenue = 0.0;
};

istream &read(istream& is, Sales_data& item)
{
	double price;
	is >> item.bookNo >> item.sold >> price;
	item.revenue = item.sold * price;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.bookNo << ' ' << item.sold << ' ' << item.revenue;
	return os;
}

//7.5.3 Error
/* class NoDefault
{
	public:
		NoDefault(const string&);
};

struct A
{
	NoDefault my_mem;
};

A a;

struct B
{
	B(){}
	NoDefault b_member;
}; */

int main()
{
	Sales_data sd(cin);
	cout << &sd << endl;
	print(cout, sd) << endl;
	
	cout << "Non-explicit constructor testing:(implicit)" << endl;
	string null_isbn("9-999-9999-9");
	Sales_data item1(null_isbn);
	Sales_data item2("9-999-9999-9");
	
	return 0;
}