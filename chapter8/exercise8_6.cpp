#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Books_data
{
	friend istream &read(istream&, Books_data&);
	friend ostream &print(ostream&, const Books_data&);
	friend Books_data add(const Books_data &lhs, const Books_data &rhs);
	
	private:
		string bookNo;
		unsigned sold = 0;
		double revenue = 0.0;
		
	public:
		Books_data() = default;
		Books_data(string s, unsigned n, double price) : bookNo(s), sold(n), revenue(n*price){}
		explicit Books_data(string s) : Books_data(s, 0, 0){}
		explicit Books_data(istream &is) : Books_data("", 0, 0){ read(is, *this); }
		
		string isbn() const {return this->bookNo;}
		double avg_price() const { return this->sold ? revenue / sold : 0; }
		Books_data &combine(const Books_data&);
};

istream &read(istream &is, Books_data &item)
{
	double price;
	is >> item.bookNo >> item.sold >> price;
	item.revenue = item.sold * price;
	return is;
}

ostream &print(ostream &os, const Books_data &item)
{
	os << item.bookNo << ' ' << item.sold << ' '
	   << item.revenue <<' ' << item.avg_price();
    return os;
}

Books_data add(const Books_data &lhs, const Books_data &rhs)
{
	Books_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Books_data &Books_data::combine(const Books_data &rhs)
{
	this->sold += rhs.sold;
	this->revenue += rhs.revenue;
	return *this;
}


int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cerr << "usage:books_prog.exe in_file" << endl;
		return -1;
	}
	
	ifstream input(argv[1]); //read file
	
	Books_data total;
	if(read(input, total))
	{
		Books_data trans;
		while(read(input, trans))
		{
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
		
		input.close();
	}
	else
	{
		cerr << "No data?!" << endl;
		return -2;
	}
	
	return 0;
}