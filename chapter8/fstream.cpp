#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Sales_data
{
	friend istream &read(istream&, Sales_data&);
	friend ostream &print(ostream&, const Sales_data&);
	
	private:
		string bookNo;
		unsigned sold;
		double revenue;
		
	public:
		Sales_data() = default;
		Sales_data(string s, unsigned n, double price) : 
			bookNo(s), sold(n), revenue(n * price){}
		explicit Sales_data(string s) : Sales_data(s, 0, 0){}
		explicit Sales_data(istream &is) : Sales_data("", 0, 0){ read(is, *this); }
		
		string isbn() const {return bookNo;}
		Sales_data &combine(Sales_data &item);
		double avg_price() const;
};

istream &read(istream &is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.sold >> price;
	item.revenue = item.sold * price;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << ' ' << item.sold << ' '
	   << item.revenue << ' ' << item.avg_price();
	return os;
}

Sales_data &Sales_data::combine(Sales_data &item)
{
	this->sold += item.sold;
	this->revenue += item.revenue;
	return *this;
}

double Sales_data::avg_price() const
{
	if(sold)
		return revenue / sold;
	else
		return 0;
}

int main(int argc, char **argv)
{
	if(argc < 3)
	{
		cerr << "usage: fstream.exe in_file out_file" << endl;
		return -1;
	}
	
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	
	Sales_data total;
	if(read(input, total))
	{
		Sales_data trans;
		while(read(input, trans))
		{
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else
	{
		//cerr << "No data?!" << endl;
		output << "No data?!" << endl;
	}
	input.close();
	output.close();
	
	return 0;
}