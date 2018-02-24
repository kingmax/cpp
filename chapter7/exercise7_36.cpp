#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct X
{
	//X(int i, int j) : base(i), rem(base % j){} //error
	//X(int i, int j) : rem(base%j), base(i){}   //error
	int rem, base;
	
	X(int i, int j) : base(i){rem = base % j;}
};

//exercise7.37
class Sales_data
{
	public:
		Sales_data(string s="") : bookNo(s){ cout << "default constructor, " << bookNo; }
		Sales_data(string s, unsigned cnt, double rev) :
			bookNo(s), sold(cnt), revenue(rev*cnt){}
		Sales_data(istream &is){ read(is, *this); }
		
	private:
		string bookNo;
		unsigned sold = 0;
		double revenue = 0.0;
		
	friend istream &read(istream &is, Sales_data &item)
	{
		double price;
		is >> item.bookNo >> item.sold >> price;
		item.revenue = item.sold * price;
		return is;
	}
};

class Book
{
	friend istream &input(istream&, Book&);
	private:
		string name;
		string isbn;
		string category;
		double price;
		//date dt;
		
	public:
		Book() = default;
		Book(string n="") : name(n){}
		Book(string n, string _isbn, string cate, double _price) : 
			name(n), isbn(_isbn), category(cate), price(_price){}
		Book(istream &is){ input(is, *this); }
};

istream &input(istream &is, Book &item)
{
	is >> item.name;
	return is;
}

int main()
{
	X x(10, 3);
	
	cout << x.base << ' ' << x.rem << endl;
	cout << endl;
	
	cout << "Enter: bookNo sold price" << endl;
	Sales_data first_item(cin);
	Sales_data next;
	cout << endl;
	Sales_data last("9-999-9999-9");
	
	cout << endl;
	Book book(cin);
	cout << &book << ' ' << sizeof(Book) << endl;

	return 0;
}