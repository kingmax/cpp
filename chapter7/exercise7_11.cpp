#include "Book_sales.h"
using namespace std;

int main()
{
	Book_sales bs1; // = Book_sales(); call default constructor
	print(cout, bs1);
	cout << endl;
	
	//Book_sales bs2("0-201-78345-x"); //ok
	Book_sales bs2 = Book_sales("0-201-78345-x");
	print(cout, bs2);
	cout << endl;
	
	Book_sales bs3("0-201-78345-x", 3, 20.00);
	print(cout, bs3);
	cout << endl;
	
	Book_sales bs4(cin); //call constructor Book_sales(istream &is)
	print(cout, bs4);
	cout << endl;
	
	return 0;
}